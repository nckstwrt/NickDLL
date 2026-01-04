#include <windows.h>
#include "CMHeader.h"
#include "Helper.h"
#include <algorithm>

using namespace std;

// https://champman0102.net/viewtopic.php?f=35&t=2756
// https://champman0102.net/viewtopic.php?p=87269#p87269
/*
This function in NickDLL then selects randomly from the 20 best teams (based on reputation) from the countries in the following order. 
4 each from Brazil and Argentina, 2 from Uruguay, Colombia, Chile and Paraguay. 1 from Bolivia, Peru, Ecuador and Venezuela. 
(If it can not get the needed teams from any of the countries it just gets more from Brazil and Argentina)
*/
// conmebol_merc == Copa Sudamericana (old Mercosur)
/*
Argentina teams with last position from 6 to 9 and no last division
Brazil teams with last position from 6 to 9 and no last division
Uruguay teams with last position from 5 to 6 and no last division
Colombia teams with last position from 5 to 6 and no last division
Chile teams with last position from 3 to 4 and no last division
Paraguay teams with last position from 3 to 4 and no last division
One Bolivia team with last position 3 and no last division
One Peru team with last position 3 and no last division
One Ecuador team with last position 3 and no last division
One Venezuela team with last position 3 and no last division
*/

DWORD replacement_004C5906_ret;
int replacement_004C5906_counter = 0;
vector<cm3_clubs*> sudamericana_20_clubs;

void AddGoodClubs(vector<cm3_clubs*> &vec, const char *szNation, int numberOfClubs)
{
	vector<cm3_clubs*> nation_clubs = find_clubs_of_country(find_country(szNation)->NationID);
	sort(nation_clubs.begin(), nation_clubs.end(), compareClubRep);

	int TeamsToSelectFrom = (nation_clubs.size() < 10) ? nation_clubs.size() : 10;

	if (TeamsToSelectFrom < numberOfClubs)
	{
		// If we can't get this countries clubs - then just get some more Argentina or Brazil ones
		AddGoodClubs(vec, ((rand() % 2) == 0) ? "Brazil" : "Argentina", numberOfClubs);
		return;
	}

	for (int i = 0; i < numberOfClubs; i++)
	{
		cm3_clubs* club = nation_clubs[rand() % TeamsToSelectFrom];
		if (!vector_contains_club(vec, club))
			vec.push_back(club);
		else
			i--;	// Else do again as the club selected was already picked
	}
}

DWORD replacement_004C5906_full()
{
	if (replacement_004C5906_counter == 0)
	{
		sudamericana_20_clubs.clear();

		AddGoodClubs(sudamericana_20_clubs, "Argentina", 4);
		AddGoodClubs(sudamericana_20_clubs, "Brazil", 4);
		AddGoodClubs(sudamericana_20_clubs, "Uruguay", 2);
		AddGoodClubs(sudamericana_20_clubs, "Colombia", 2);
		AddGoodClubs(sudamericana_20_clubs, "Chile", 2);
		AddGoodClubs(sudamericana_20_clubs, "Paraguay", 2);
		AddGoodClubs(sudamericana_20_clubs, "Bolivia", 1);
		AddGoodClubs(sudamericana_20_clubs, "Peru", 1);
		AddGoodClubs(sudamericana_20_clubs, "Ecuador", 1);
		AddGoodClubs(sudamericana_20_clubs, "Venezuela", 1);
	}

	if (replacement_004C5906_counter == 20)
	{
		replacement_004C5906_counter = 0;
		return 0;
	}
	return (DWORD)sudamericana_20_clubs[replacement_004C5906_counter++];
}


extern "C" _declspec(naked) int replacement_004C5906()
{
	_asm
	{
		pushad
	}
	replacement_004C5906_ret = replacement_004C5906_full();
	_asm
	{
		popad
		mov eax, [replacement_004C5906_ret]
		ret 4
	}
}

void setup_sudamericana()
{
	// 004C5906  |.  E8 850F0000              |CALL 004C6890                           ; \cm0102.004C6890
	// Remap function to our function
	DWORD func_addr = (DWORD)replacement_004C5906;
	WriteDWORD(0x004C5906 + 1, func_addr - (0x004C5906 + 5));

	// Change calling function to use our return value
	//004C5919      89348A                    MOV DWORD PTR DS:[ECX*4+EDX],ESI   <--- ESI to EAX
	WriteBytes(0x004C5919+1, 1, 4);
	
	// 004C590D     /74 28                     JZ SHORT 004C5937  <--- This jump changed so if 0 is returned, finish the loop
	WriteBytes(0x004C590D+1, 1, 0x28);
}
