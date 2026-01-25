#include <Windows.h>
#include "generic_functions.h"
#include "CMHeader.h"
#include "Helper.h"
#include "Date.h"
#include "LeagueInfo.h"

DWORD SecondDivisionCompID;
DWORD ThirdDivisionCompID;
DWORD ConferenceDivisionCompID;
DWORD NorthernConferenceDivisionCompID;
DWORD SouthernConferenceDivisionCompID;
DWORD ALowerDivisionCompID;

void GetCompIDs()
{
	SecondDivisionCompID = find_club_comp_id("English Second Division");
	ThirdDivisionCompID = find_club_comp_id("English Third Division");
	ConferenceDivisionCompID = find_club_comp_id("English Conference");
	NorthernConferenceDivisionCompID = find_club_comp_id("English Northern Premier League Premier Division");
	SouthernConferenceDivisionCompID = find_club_comp_id("English Southern League Premier Division");
	ALowerDivisionCompID = find_club_comp_id("A Lower Division");

	dprintf("GetCompIDs: SecondDivisionCompID = %02X\nThirdDivisionCompID = %02X\nConferenceDivisionCompID = %02X\nNorthernConferenceDivisionCompID = %02X\nSouthernConferenceDivisionCompID = %02X\nALowerDivisionCompID = %02X\n", SecondDivisionCompID, ThirdDivisionCompID, ConferenceDivisionCompID, NorthernConferenceDivisionCompID, SouthernConferenceDivisionCompID, ALowerDivisionCompID);
}

int AddTeams(BYTE* _this)
{
	DWORD CompID = *(DWORD*)(*(DWORD*)(_this + 0x4));

	// Count the number of teams first, as the code really expects us to know up front
	BYTE numberOfLeagueTeams = (BYTE)CountNumberOfTeamsInComp(CompID);

	// Now let's add the teams
	*((WORD*)(_this + 0x3E)) = numberOfLeagueTeams; // number of teams
	*((DWORD*)(_this + 0xB1)) = (DWORD)sub_944E46_malloc(numberOfLeagueTeams * 59); // number of teams * 59 (0x3B) - was 0x2FF
	BYTE teamsAdded = 0;
	for (DWORD i = 0; i < *clubs_count; i++)
	{
		cm3_clubs* club = &(*clubs)[i];
		if (club->ClubDivision && club->ClubDivision->ClubCompID == CompID)
			sub_687430_add_team_call(_this, teamsAdded++, club, 0, 0);
	}
	return 1;
}


typedef BYTE*(__thiscall*league_init_typedef)(BYTE* _this, __int16 a2, cm3_club_comps* a3);
void AddLeague(BYTE* _this, DWORD compID, int leagueNo, int year, DWORD league_init_addr)
{
	dprintf("Adding (This: %08X) league %X at slot %d for year %d (calling init addr: %08X).\n", (DWORD)_this, compID, leagueNo, (short)year, league_init_addr);
	cm3_club_comps* comp = get_comp(compID);
	if (comp)
	{
		dprintf("comp name: %s\n", comp->ClubCompName);
		BYTE* ee_bytes = (BYTE*)sub_944CF1_operator_new(0xEE);
		league_init_typedef init_call = (league_init_typedef)(league_init_addr);
		BYTE* leagueSetupPtr = init_call(ee_bytes, (short)*current_year, comp);
		DWORD* compPtrTable = *(DWORD**)(_this + 0x10);
		compPtrTable[leagueNo] = (DWORD)leagueSetupPtr;
	}
	else
		dprintf("Could not find comp ID %X!", compID);
}

void AddFixture(BYTE *pMem, int fixture, Date date, int startYear, Day dayOfWeek /* Mon = 0 */, int timeOfDay = 1)
{
	sub_68A160_add_fixture_call(pMem, fixture, date.getDay(), date.getMonth() - 1, date.getYear() - startYear, dayOfWeek, timeOfDay, startYear, 0);
	sub_68A1C0_add_fixture_call(pMem, fixture, 0, -1, -1, -1, 0);
}

DWORD GenericAddTeamFixtures(BYTE* _this, BYTE a2, WORD* a3, WORD* a4, DWORD* a5)
{
	dprintf("Using GenericAddTeamFixtures\n");
	cm3_club_comps *comp = (cm3_club_comps *)*((DWORD*)(_this + 4));
	int team_count = CountNumberOfTeamsInComp(comp->ClubCompID);

	if (a2 == 0xFF)	// -1
	{
		if (a5)
			*a5 = 1;
		*a3 = (team_count - 1) * 2;
		*a4 = 0;
		BYTE* pMem = (BYTE*)sub_944E46_malloc((*a3) * 65);	// Allocate memory for fixtures
		WORD year = *(WORD*)(_this + 0x40);

		Date date(year, August, 12);
		for (WORD i = 0; i < *a3; i++)
		{
			AddFixture(pMem, i, date, year, Saturday);
			date.addDays(7);
		}
		return (DWORD)pMem;
	}
	else
	{
		BYTE playOffPlaces = _this[0xBF];
		dprintf("Playoff Places: %d\n", playOffPlaces);

		if (a2 != 0)
			return 0;
		if (a5)
			*a5 = 0;

		BYTE* pMem = NULL;
		WORD year = *(WORD*)(_this + 0x40);

		if (playOffPlaces == 4)
		{
			*a3 = 2;
			*a4 = 160;

			pMem = (BYTE*)sub_944E46_malloc(104 * (*a3));

			sub_521E60_add_playoff_fixture_call(pMem, 0, 7, 4, 1, 0, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 0, 12, 4, 1, 5, 1, year, 0);
			*(WORD*)(pMem + 0x7) = 0x82;		// 130 *10
			*(WORD*)(pMem + 0x9) = 0x0;
			*(WORD*)(pMem + 0xB) = 0x0;
			*(WORD*)(pMem + 0xD) = 0x204;		// 516
			*(BYTE*)(pMem + 0x17) = 0x5;
			*((WORD*)pMem + 0xC) = 0x4;
			*(WORD*)(pMem + 0x1A) = 0x2;
			*(WORD*)(pMem + 0x1C) = 0x4;
			*(WORD*)(pMem + 0xF) = 0x3;
			*(WORD*)(pMem + 0x1E) = 0x0;
			*(BYTE*)(pMem + 0x20) = 0x0;
			*(BYTE*)(pMem + 0x21) = 0x2;
			*(BYTE*)(pMem + 0x22) = 0x4;
			*((DWORD*)pMem + 0x17) = 0x0;
			*((DWORD*)pMem + 0x18) = 0x0;
			*((DWORD*)pMem + 0x19) = 0x0;

			sub_521E60_add_playoff_fixture_call(pMem, 1, 17, 4, 1, 3, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 1, 26, 4, 1, 5, 1, year, 4);
			*(WORD*)(pMem + 113) = 1;
			*(WORD*)(pMem + 130) = 1;
			*(WORD*)(pMem + 104 + 0x7) = 0x96;	// 150
			*(WORD*)(pMem + 115) = 0;
			*(WORD*)(pMem + 117) = 3;
			*(BYTE*)(pMem + 127) = 5;
			*(WORD*)(pMem + 128) = 2;
			*(WORD*)(pMem + 132) = 0;
			*(WORD*)(pMem + 119) = 0;
			*(WORD*)(pMem + 134) = 0;
			*(BYTE*)(pMem + 136) = 0;
			*(BYTE*)(pMem + 137) = 1;
			*(BYTE*)(pMem + 138) = 0;
			*((DWORD*)pMem + 49) = 0;
			*((DWORD*)pMem + 50) = 0;
			*((DWORD*)pMem + 51) = 0;
		}

		if (playOffPlaces == 6)
		{
			*a3 = 3;
			*a4 = 160;
			pMem = (BYTE*)sub_944E46_malloc(104 * (*a3));

			sub_521E60_add_playoff_fixture_call(pMem, 0, 3, 4, 1, 0, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 0, 5, 4, 1, 2, 2, year, 0);

			*(WORD*)(pMem + 7) = 120;
			*(WORD*)(pMem + 9) = 0;
			*(WORD*)(pMem + 11) = 0;
			*(WORD*)(pMem + 13) = 515;
			pMem[23] = 5;
			*((WORD*)pMem + 12) = 4;
			*((WORD*)pMem + 13) = 2;
			*((WORD*)pMem + 14) = 4;
			*(WORD*)(pMem + 15) = 3;
			*((WORD*)pMem + 15) = 0;
			pMem[32] = 0;
			pMem[33] = 1;
			pMem[34] = 4;
			*((DWORD*)pMem + 23) = 0;
			*((DWORD*)pMem + 24) = 0;
			*((DWORD*)pMem + 25) = 0;
		
			sub_521E60_add_playoff_fixture_call(pMem, 1, 6, 4, 1, 3, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 1, 8, 4, 1, 5, 1, year, 0);

			*(WORD*)(pMem + 111) = 130;
			*(WORD*)(pMem + 113) = 1;
			*(WORD*)(pMem + 115) = 0;
			*(WORD*)(pMem + 117) = 1027;
			pMem[127] = 5;
			*((WORD*)pMem + 64) = 4;
			*((WORD*)pMem + 65) = 2;
			*((WORD*)pMem + 66) = 2;
			*(WORD*)(pMem + 119) = 3;
			*((WORD*)pMem + 67) = 4;
			*(DWORD*)(pMem + 135) = 16842752;
			*((DWORD*)pMem + 49) = 0;
			*((DWORD*)pMem + 50) = 0;
			*((DWORD*)pMem + 51) = 0;

			sub_521E60_add_playoff_fixture_call(pMem, 2, 9, 4, 1, 6, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 2, 15, 4, 1, 5, 1, year, 4);

			*(WORD*)(pMem + 217) = 2;
			*((WORD*)pMem + 116) = 2;
			*((WORD*)pMem + 117) = 1;
			*((WORD*)pMem + 118) = 0;
			*(WORD*)(pMem + 215) = 150;
			*(WORD*)(pMem + 219) = 0;
			*(WORD*)(pMem + 221) = 3;
			pMem[231] = 5;
			*(WORD*)(pMem + 223) = 0;
			*((WORD*)pMem + 119) = 6;
			pMem[240] = 0;
			pMem[241] = 1;
			pMem[242] = 0;
			*((DWORD*)pMem + 75) = 0;
			*((DWORD*)pMem + 76) = 0;
			*((DWORD*)pMem + 77) = 0;
		}

		return (DWORD)pMem;
	}
	return 0;
}

DWORD AddEng24TeamFixturesWithPlayoffs(BYTE* _this, BYTE a2, WORD* a3, WORD* a4, DWORD* a5)
{
	dprintf("add_eng_24team_fixtures_with_playoffs called with this=%08X a2=%02X, a3=%08X, a4=%08X, a5=%08X\n", _this, a2, a3, a4, a5);

	DWORD CompID = *(DWORD*)*((DWORD*)(_this + 4));
	const char *szCompName = (const char *)(*((DWORD*)(_this + 4))+4);
	int team_count = CountNumberOfTeamsInComp(CompID);
	dprintf("CompID: %08X Name: %s Team Count: %d\n", CompID, szCompName, team_count);

	// HACK: if less than 20 teams just use the generic fixture adder
	if (team_count < 20)
		return GenericAddTeamFixtures(_this, a2, a3, a4, a5);

	if (a2 == 0xFF)	// -1
	{
		if (a5)
			*a5 = 1;
		*a3 = (team_count - 1) * 2;		// Number of Fixtures = 0x22 (34 i.e. (number of teams - 1) * 2) 18 in ser c1/a (23 in nothern prem) (eng third: 24)
		*a4 = 0;
		BYTE* pMem = (BYTE*)sub_944E46_malloc((*a3) * 65);	// Allocate memory for fixtures
		WORD year = *(WORD*)(_this + 0x40);

		int fixture = 0;

		AddFixture(pMem, fixture++, Date(year, 8, 12), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 8, 19), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 8, 26), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 8, 28), year, Monday, 2);
		AddFixture(pMem, fixture++, Date(year, 9, 2), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 9, 9), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 9, 13), year, Wednesday, 2);
		AddFixture(pMem, fixture++, Date(year, 9, 16), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 9, 23), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 9, 30), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 10, 7), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 10, 14), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 10, 17), year, Tuesday, 2);
		AddFixture(pMem, fixture++, Date(year, 10, 21), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 10, 24), year, Tuesday, 2);
		AddFixture(pMem, fixture++, Date(year, 10, 28), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 11, 4), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 11, 11), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 11, 18), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 11, 25), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 12, 2), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 12, 9), year, Saturday);
		AddFixture(pMem, fixture++, Date(year, 12, 16), year, Saturday);

		Date FirstDec(year, 12, 1);
		Date Dec16(year, 12, 16);
		int dayDiff = Dec16.DayOfYear() - FirstDec.DayOfYear();

		dprintf("dayDiff: %d\n", dayDiff);
		switch (dayDiff)
		{
		case 12:
			AddFixture(pMem, fixture++, Date(year, 12, 20), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 27), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 30), year, DontCare, 2);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 3), year, DontCare);
			break;
		case 13:
			AddFixture(pMem, fixture++, Date(year, 12, 21), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 26), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 28), year, DontCare, 2);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 1), year, DontCare);
			break;
		case 14:
			AddFixture(pMem, fixture++, Date(year, 12, 22), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 26), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 29), year, DontCare);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 1), year, DontCare);
			break;
		case 15:
			AddFixture(pMem, fixture++, Date(year, 12, 23), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 26), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 30), year, DontCare);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 1), year, DontCare);
			break;
		case 16:
			AddFixture(pMem, fixture++, Date(year, 12, 21), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 26), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 31), year, DontCare);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 4), year, DontCare);
			break;
		case 17:
			AddFixture(pMem, fixture++, Date(year, 12, 22), year, DontCare, 2);
			AddFixture(pMem, fixture++, Date(year, 12, 26), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 28), year, DontCare, 2);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 4), year, DontCare);
			break;
		default:
		case 18:
			if (dayDiff != 18)
				dprintf("SOMETHING WENT WRONG WITH DAY DIFF!!!\n");
			AddFixture(pMem, fixture++, Date(year, 12, 26), year, DontCare);
			AddFixture(pMem, fixture++, Date(year, 12, 28), year, DontCare, 2);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 2), year, DontCare);
			AddFixture(pMem, fixture++, Date(year + 1, 1, 5), year, DontCare);
			break;
		}

		AddFixture(pMem, fixture++, Date(year + 1, 1, 12), year, Saturday);
		AddFixture(pMem, fixture++, Date(year + 1, 1, 20), year, Saturday);

		AddFixture(pMem, fixture++, Date(year + 1, 2, 3), year, Saturday);
		AddFixture(pMem, fixture++, Date(year + 1, 2, 10), year, Saturday);
		AddFixture(pMem, fixture++, Date(year + 1, 2, 17), year, Saturday);
		AddFixture(pMem, fixture++, Date(year + 1, 2, 20), year, Tuesday, 2);
		AddFixture(pMem, fixture++, Date(year + 1, 2, 24), year, Saturday);

		AddFixture(pMem, fixture++, Date(year + 1, 3, 3), year, Saturday);
		AddFixture(pMem, fixture++, Date(year + 1, 3, 7), year, Tuesday, 2);

		if (team_count >= 20)
		{
			AddFixture(pMem, fixture++, Date(year + 1, 3, 10), year, Saturday);
			AddFixture(pMem, fixture++, Date(year + 1, 3, 17), year, Monday, 2);
		}
		
		if (team_count >= 21)
		{
			AddFixture(pMem, fixture++, Date(year + 1, 3, 24), year, Saturday);
			AddFixture(pMem, fixture++, Date(year + 1, 3, 31), year, Saturday);
		}

		if (team_count >= 22)
		{
			AddFixture(pMem, fixture++, Date(year + 1, 4, 7), year, Saturday);
			AddFixture(pMem, fixture++, Date(year + 1, 4, 14), year, Saturday);
		}
		
		if (team_count >= 23)
		{
			AddFixture(pMem, fixture++, Date(year + 1, 4, 16), year, Monday, 2);
			AddFixture(pMem, fixture++, Date(year + 1, 4, 21), year, Saturday);
		}

		if (team_count >= 24)
		{
			AddFixture(pMem, fixture++, Date(year + 1, 4, 28), year, Saturday);
			AddFixture(pMem, fixture++, Date(year + 1, 5, 4), year, Sunday);
		}

		dprintf("fixtures added: %d\n", fixture - 1);

		return (DWORD)pMem;
	}
	else
	{
		BYTE playOffPlaces = _this[0xBF];
		dprintf("Playoff Places: %d\n", playOffPlaces);

		if (a2 != 0)
			return 0;
		if (a5)
			*a5 = 0;

		BYTE* pMem = NULL;
		WORD year = *(WORD*)(_this + 0x40);

		if (playOffPlaces == 4)
		{
			*a3 = 2;
			*a4 = 160;

			pMem = (BYTE*)sub_944E46_malloc(104 * (*a3));

			sub_521E60_add_playoff_fixture_call(pMem, 0, 7, 4, 1, 0, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 0, 12, 4, 1, 5, 1, year, 0);
			*(WORD*)(pMem + 0x7) = 0x82;		// 130 *10
			*(WORD*)(pMem + 0x9) = 0x0;
			*(WORD*)(pMem + 0xB) = 0x0;
			*(WORD*)(pMem + 0xD) = 0x204;		// 516
			*(BYTE*)(pMem + 0x17) = 0x5;
			*((WORD*)pMem + 0xC) = 0x4;
			*(WORD*)(pMem + 0x1A) = 0x2;
			*(WORD*)(pMem + 0x1C) = 0x4;
			*(WORD*)(pMem + 0xF) = 0x3;
			*(WORD*)(pMem + 0x1E) = 0x0;
			*(BYTE*)(pMem + 0x20) = 0x0;
			*(BYTE*)(pMem + 0x21) = 0x2;		
			*(BYTE*)(pMem + 0x22) = 0x4;
			*((DWORD*)pMem + 0x17) = 0x0;
			*((DWORD*)pMem + 0x18) = 0x0;
			*((DWORD*)pMem + 0x19) = 0x0;

			sub_521E60_add_playoff_fixture_call(pMem, 1, 17, 4, 1, 3, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 1, 26, 4, 1, 5, 1, year, 4);
			*(WORD*)(pMem + 113) = 1;
			*(WORD*)(pMem + 130) = 1;
			*(WORD*)(pMem + 104 + 0x7) = 0x96;	// 150
			*(WORD*)(pMem + 115) = 0;
			*(WORD*)(pMem + 117) = 3;
			*(BYTE*)(pMem + 127) = 5;
			*(WORD*)(pMem + 128) = 2;
			*(WORD*)(pMem + 132) = 0;
			*(WORD*)(pMem + 119) = 0;
			*(WORD*)(pMem + 134) = 0;
			*(BYTE*)(pMem + 136) = 0;
			*(BYTE*)(pMem + 137) = 1;
			*(BYTE*)(pMem + 138) = 0;
			*((DWORD*)pMem + 49) = 0;
			*((DWORD*)pMem + 50) = 0;
			*((DWORD*)pMem + 51) = 0;
		}

		if (playOffPlaces == 6)
		{
			*a3 = 3;
			*a4 = 160;
			pMem = (BYTE*)sub_944E46_malloc(104 * (*a3));

			sub_521E60_add_playoff_fixture_call(pMem, 0, 3, 4, 1, 0, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 0, 5, 4, 1, 2, 2, year, 0);
			
			*(WORD*)(pMem + 7) = 120;
			*(WORD*)(pMem + 9) = 0;
			*(WORD*)(pMem + 11) = 0;
			*(WORD*)(pMem + 13) = 515;
			pMem[23] = 5;
			*((WORD*)pMem + 12) = 4;
			*((WORD*)pMem + 13) = 2;
			*((WORD*)pMem + 14) = 4;
			*(WORD*)(pMem + 15) = 3;
			*((WORD*)pMem + 15) = 0;
			pMem[32] = 0;
			pMem[33] = 1;
			pMem[34] = 4;
			*((DWORD*)pMem + 23) = 0;
			*((DWORD*)pMem + 24) = 0;
			*((DWORD*)pMem + 25) = 0;
			/*
			*(WORD*)(pMem + 7) = 0x78;
			*(WORD*)(pMem + 9) = 0;
			*(WORD*)(pMem + 11) = 0;
			*(WORD*)(pMem + 13) = 0x203;
			pMem[23] = 5;
			*((WORD*)pMem + 12) = 4;
			*((WORD*)pMem + 13) = 2;
			*((WORD*)pMem + 14) = 4;
			*(WORD*)(pMem + 15) = 3;
			*((WORD*)pMem + 15) = 0;
			pMem[32] = 0;
			pMem[33] = 1;
			pMem[34] = 4;
			*((DWORD*)pMem + 23) = 0;
			*((DWORD*)pMem + 24) = 0;
			*((DWORD*)pMem + 25) = 0;*/

			sub_521E60_add_playoff_fixture_call(pMem, 1, 6, 4, 1, 3, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 1, 8, 4, 1, 5, 1, year, 0);

			*(WORD*)(pMem + 111) = 130;
			*(WORD*)(pMem + 113) = 1;
			*(WORD*)(pMem + 115) = 0;
			*(WORD*)(pMem + 117) = 1027;
			pMem[127] = 5;
			*((WORD*)pMem + 64) = 4;
			*((WORD*)pMem + 65) = 2;
			*((WORD*)pMem + 66) = 2;
			*(WORD*)(pMem + 119) = 3;
			*((WORD*)pMem + 67) = 4;
			*(DWORD*)(pMem + 135) = 16842752;
			*((DWORD*)pMem + 49) = 0;
			*((DWORD*)pMem + 50) = 0;
			*((DWORD*)pMem + 51) = 0;

			/*
			*(WORD*)(pMem + 104 + 7) = 0x82;
			*(WORD*)(pMem + 104 + 9) = 1;
			*(WORD*)(pMem + 104 + 11) = 0;
			*(WORD*)(pMem + 104 + 13) = 0x403;
			pMem[127] = 5;
			*((WORD*)pMem + (104/2) + 12) = 4;
			*((WORD*)pMem + (104/2) + 13) = 2;
			*((WORD*)pMem + (104/2) + 14) = 2;
			*(WORD*)(pMem + 104 + 15) = 3;
			*((WORD*)pMem + (104/2) + 15) = 4;
			*(DWORD*)(pMem + 135) = 0x1010000;
			*((DWORD*)pMem + 49) = 0;
			*((DWORD*)pMem + 50) = 0;
			*((DWORD*)pMem + 51) = 0;*/

			sub_521E60_add_playoff_fixture_call(pMem, 2, 9, 4, 1, 6, year);
			sub_521EB0_add_playoff_fixture_call(pMem, 2, 15, 4, 1, 5, 1, year, 4);

			*(WORD*)(pMem + 217) = 2;
			*((WORD*)pMem + 116) = 2;
			*((WORD*)pMem + 117) = 1;
			*((WORD*)pMem + 118) = 0;
			*(WORD*)(pMem + 215) = 150;
			*(WORD*)(pMem + 219) = 0;
			*(WORD*)(pMem + 221) = 3;
			pMem[231] = 5;
			*(WORD*)(pMem + 223) = 0;
			*((WORD*)pMem + 119) = 6;
			pMem[240] = 0;
			pMem[241] = 1;
			pMem[242] = 0;
			*((DWORD*)pMem + 75) = 0;
			*((DWORD*)pMem + 76) = 0;
			*((DWORD*)pMem + 77) = 0;

			/*
			*(WORD*)(pMem + 217) = 2;
			*((WORD*)pMem + 116) = 2;
			*((WORD*)pMem + 117) = 1;
			*((WORD*)pMem + 118) = 0;
			*(WORD*)(pMem + 215) = 0x96;
			*(WORD*)(pMem + 219) = 0;
			*(WORD*)(pMem + 221) = 3;
			pMem[231] = 5;
			*(WORD*)(pMem + 223) = 0;
			*((WORD*)pMem + 119) = 6;
			pMem[240] = 0;
			pMem[241] = 1;
			pMem[242] = 0;
			*((DWORD*)pMem + 75) = 0;
			*((DWORD*)pMem + 76) = 0;
			*((DWORD*)pMem + 77) = 0;*/
		}

		return (DWORD)pMem;
	}
	return 0;
}

// Not part of the Tapani patches but one of the hooks needed to call our relegation code. Standard B0 in vtable for relegation/promotion
static int(*sub_689C80)() = (int(*)())(0x689C80);
void sub_601FF0();
void __declspec(naked) sub_689C20_relegation_hook()
{
	__asm
	{
	/*00689C20*/	push ebx
	/*00689C21*/	mov ebx,ecx
	/*00689C23*/	push edi
	/*00689C24*/	mov eax,dword ptr ds:[ebx+0x1C]
	/*00689C27*/	test eax,eax
	/*00689C29*/	jge _00689C73
	/*00689C2B*/	mov eax,dword ptr ds:[ebx]
	/*00689C2D*/	mov edi,ebx
	/*00689C2F*/	call dword ptr ds:[eax+0xA4]
	/*00689C35*/	mov eax,dword ptr ds:[ebx+0x20]
	/*00689C38*/	test eax,eax
	/*00689C3A*/	jl _00689C73
	/*00689C3C*/	push ebp
	/*00689C3D*/	mov ebp,dword ptr ss:[esp+0x10]
	/*00689C41*/	push esi
_00689C42:
	/*00689C42*/	mov ecx,dword ptr ds:[0xADADFC]
	/*00689C48*/	mov esi,dword ptr ds:[ecx+eax*0x4]
	/*00689C4B*/	mov ecx,esi
	/*00689C4D*/	mov edx,dword ptr ds:[esi]
	/*00689C4F*/	call dword ptr ds:[edx+0xA4]
	/*00689C55*/	push 0xFFFFFFFF
	/*00689C57*/	push 0xFFFFFFFF
	/*00689C59*/	push ebp
	/*00689C5A*/	push 0x1
	/*00689C5C*/	push esi
	/*00689C5D*/	push edi
	/*00689C5E*/	mov ecx,ebx
	/*00689C60*/	call sub_689C80		/*call <cm0102.sub_689C80>*/
	/*00689C65*/	mov eax,dword ptr ds:[esi+0x20]
	/*00689C68*/	mov edi,esi
	/*00689C6A*/	test eax,eax
	/*00689C6C*/	jge _00689C42
	/*00689C6E*/	call sub_601FF0		/*call <cm0102.sub_601FF0>*/		// <---- additional call added by Tapani
_00689C73:
	/*00689C73*/	pop esi
	/*00689C74*/	pop ebp
	/*00689C75*/	pop edi
	/*00689C76*/	pop ebx
	/*00689C77*/	ret 0x4
	}
}

static void (*sub_9452CA_free)(LPVOID lpMem) = (void(*)(LPVOID))(0x9452CA);
static int(__thiscall* sub_51C800_call)(BYTE* _this, DWORD val) = (int(__thiscall*)(BYTE * _this, DWORD val))(0x51C800);
static int(*sub_522E00)() = (int(*)())(0x522E00);

int __fastcall HandlePlayoffSelection(BYTE *_this)
{
  void *v5; // ebx
  DWORD v6; // eax
  DWORD *v7; // ecx
  WORD v12 = 0; // [esp+10h] [ebp-418h] BYREF
  WORD v13 = 0; // [esp+14h] [ebp-414h] BYREF
  int v19; // [esp+424h] [ebp-4h]

  BYTE promotionPlaces = _this[0xBE];
  BYTE playoffPlaces = _this[0xBF];
  BYTE *pMem = (BYTE*)sub_944E46_malloc(4 * playoffPlaces);

  DWORD promotionPlacesOffset = promotionPlaces * 59;
  *(DWORD*)(pMem) = *(DWORD *)(*(DWORD *)(_this + 0xB1) + promotionPlacesOffset + (6 * 59));
  *(DWORD*)(pMem + 4) = *(DWORD *)(*(DWORD *)(_this + 0xB1) + promotionPlacesOffset + (3 * 59));
  *(DWORD*)(pMem + 8) = *(DWORD *)(*(DWORD *)(_this + 0xB1) + promotionPlacesOffset + (5 * 59));
  *(DWORD*)(pMem + 12) = *(DWORD *)(*(DWORD *)(_this + 0xB1) + promotionPlacesOffset + (4 * 59));
  if (playoffPlaces >=6)
  {
	  *(DWORD*)(pMem + 16) = *(DWORD*)(*(DWORD*)(_this + 0xB1) + (1 * 59));
	  *(DWORD*)(pMem + 20) = *(DWORD*)(*(DWORD*)(_this + 0xB1) + (2 * 59));
  }
  
  v5 = (void *)(*(int (__thiscall **)(BYTE *, BYTE, WORD *, WORD *, DWORD))(*(DWORD *)_this + 0x3C))(			// 0x3C is fixtures
                 _this,
                 0,
                 &v12,
                 &v13,
                 0);

  BYTE *v14 = (BYTE *)sub_944CF1_operator_new(0xB2);
  v19 = 0;
  if ( v14 )
  {
	  v6 = ((DWORD(__thiscall*)(BYTE*, BYTE*, WORD, BYTE*, WORD, DWORD, void*, WORD, BYTE, BYTE, WORD, BYTE, DWORD, DWORD, DWORD, DWORD))sub_522E00)(
			 v14,
			 _this,
			 playoffPlaces,
			 pMem,
			 v12,
			 *((DWORD*)_this + 1),
			 v5,
			 *((WORD*)_this + 0x20),
			 0,
			 1,
			 v13,
			 20,
			 0,
			 0,
			 0,
			 0);
  }
  else
    v6 = 0;
  v7 = (DWORD*)*(DWORD*)(_this + 0xC);
  v19 = -1;
  *v7 = (DWORD)v6;
  sub_9452CA_free(pMem);	// Mem Free
  sub_9452CA_free(v5);	// Mem Free
  return sub_51C800_call((BYTE*)v6, 0);
}

void __declspec(naked) PromotionRelegateCaller()		// used as a __thiscall -> __cdecl converter (by +B0)
{
	__asm
	{
		mov eax, esp
		push dword ptr[eax + 0x4]
		push ecx
		call GenericPromotionRelegation
		add esp, 0x8
		ret 4
	}
}

void GenericPromotionRelegation(BYTE* _this, int a2)
{
	comp_stats *comp = (comp_stats*)_this;
	dprintf("GenericPromotionRelegation called with this=%08X a2=%d CompID=%X\n", _this, a2, comp->competition_db->ClubCompID);
	LeagueInfo *leagueInfo = get_league_info(comp->competition_db->ClubCompID);
	if (leagueInfo)
	{
		if (leagueInfo->PromotionComp == NULL && leagueInfo->RelegationComp != NULL)		// If it's the top most league in the country, no promotion function
		{
			// Call this league's +A4
			cm3_club_comps *compPtr = comp->competition_db;

			// Call +A4 on all subsequent leagues
			while (true)
			{
				BYTE* loaded_league = get_loaded_league(compPtr->ClubCompID);
				if (loaded_league)
				{
					DWORD v1 = *(DWORD*)loaded_league;

					dprintf("Calling +A4 of league %s (CompID=%X v1=%08X loaded_league=%08X)\n", leagueInfo->Name, compPtr->ClubCompID, v1, loaded_league);
					(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(loaded_league);

					compPtr = leagueInfo->RelegationComp;
					leagueInfo = compPtr ? get_league_info(compPtr->ClubCompID) : NULL;

					dprintf("Next league to call +A4 of: %s (compPtr: %08X)\n", leagueInfo ? leagueInfo->Name : "NULL", (DWORD)compPtr);
					if (compPtr == NULL || leagueInfo == NULL || leagueInfo->SetupFunction == 0)
						break;
				}
				else
					break;
			}

			// Now loop through and call the relegation function on the leagues
			compPtr = comp->competition_db;
			leagueInfo = get_league_info(comp->competition_db->ClubCompID);
			if (leagueInfo->RelegationComp)
			{
				while (true)
				{
					LeagueInfo* relegatedLeagueInfo = get_league_info(leagueInfo->RelegationComp->ClubCompID);
					if (relegatedLeagueInfo->SetupFunction == NULL)
					{
						dprintf("Relegation league %s is not playable (SetupFunction == NULL). Skipping promotion call.\n", relegatedLeagueInfo->Name);
						leagueInfo = relegatedLeagueInfo;
						break;
					}
					dprintf("Calling sub_689C80_promote between %s <-> %s\n", leagueInfo->Name, leagueInfo->RelegationComp ? get_league_info(leagueInfo->RelegationComp->ClubCompID)->Name : "NULL");
					sub_689C80_promote(_this, get_loaded_league(compPtr->ClubCompID), get_loaded_league(leagueInfo->RelegationComp->ClubCompID), 1, a2, -1, -1);
					compPtr = leagueInfo->RelegationComp;
					leagueInfo = compPtr ? get_league_info(compPtr->ClubCompID) : NULL;
					if (compPtr == NULL || leagueInfo == NULL || leagueInfo->RelegationComp == NULL)
						break;
				}
			}

			// LeagueInfo should be the bottom league now and sould not be playable (i.e. SetupFunction == NULL)
			if (leagueInfo->PromotionComp && leagueInfo->RelegationComp == NULL)
			{
				LeagueInfo* promotionLeagueInfo = get_league_info(leagueInfo->PromotionComp->ClubCompID);

				// Need to do the relegation for the bottom league with the lower divisions
				dprintf("Getting relegated teams for bottom real league %s\n", promotionLeagueInfo->Name);
				std::vector<cm3_clubs*> relegated_clubs = get_relegated_teams(promotionLeagueInfo->Comp->ClubCompID);
				std::vector<cm3_clubs*> available_clubs;
				
				for (int i = 0; i < get_club_count(); i++)
				{
					cm3_clubs* club = get_club(i);
					if (club)
					{
						if (club->ClubDivision && club->ClubNation)
						{
							DWORD compID = club->ClubDivision->ClubCompID;
							DWORD nationID = club->ClubNation->NationID;
							if (compID == leagueInfo->Comp->ClubCompID && nationID == leagueInfo->Comp->ClubCompNation->NationID)
							{
								available_clubs.push_back(club);
							}
						}
					}
				}

				dprintf("Bottom league relegation: Relegated Clubs: %d Available Clubs: %d\n", relegated_clubs.size(), available_clubs.size());

				for (unsigned int i = 0; i < relegated_clubs.size(); i++)
				{
					int availableIdx = rand() % available_clubs.size();
					cm3_clubs* clubToRelegate = relegated_clubs[i];
					cm3_clubs* available = available_clubs[availableIdx];

					dprintf("Swapping Teams: %s (%s) <-> %s (%s)\n", clubToRelegate->ClubName, clubToRelegate->ClubDivision->ClubCompName, available->ClubName, available->ClubDivision->ClubCompName);

					cm3_club_comps* tempDivision = available->ClubDivision;
					available->ClubDivision = clubToRelegate->ClubDivision;
					clubToRelegate->ClubDivision = tempDivision;

					available_clubs.erase(available_clubs.begin() + availableIdx);
				}
			}

			// The lower teams won't have had their +8 function called. So we have to call them manually here.
			compPtr = comp->competition_db;
			leagueInfo = get_league_info(comp->competition_db->ClubCompID);
			if (leagueInfo->RelegationComp)
			{
				while (true)
				{
					compPtr = leagueInfo->RelegationComp;
					leagueInfo = compPtr ? get_league_info(compPtr->ClubCompID) : leagueInfo;
					if (compPtr == NULL)
						break;

					if (leagueInfo->SetupFunction == NULL)
					{
						dprintf("Relegation league %s is not playable (SetupFunction == NULL). Skipping +8 call.\n", leagueInfo->Name);
						break;
					}

					BYTE* loaded_league = get_loaded_league(compPtr->ClubCompID);
					DWORD v1 = *(DWORD*)loaded_league;

					dprintf("Calling +8 of league %s (CompID=%X v1=%08X loaded_league=%08X)\n", leagueInfo->Name, compPtr->ClubCompID, v1, loaded_league);
					(*(int(__thiscall**)(BYTE*))(v1 + 0x8))(loaded_league);
				}
			}
		}
		else
		{
			dprintf("No relegation function defined for league %s\n", leagueInfo->Name);
		}
	}
}
