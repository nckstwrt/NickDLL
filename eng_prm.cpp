#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "CMHeader.h"
#include "Helper.h"
#include "vtable.h"
#include "generic_functions.h"

/*
eng_prm.cpp VTable at 00969D1C:
0. 00 = 005735B0
1. 08 = 00574C10
2. 28 = 005A8F60
3. 30 = 00684640
4. 3C = 00573660
5. 44 = 00686940
6. 48 = 0048C6D0
7. 50 = 0048E180
8. 68 = 0048E380
9. 7C = 0048F2D0
10. 8C = 00574B70
11. B0 = 005752E0
12. B4 = 005756C0
13. B8 = 00685D30
*/

static int(*sub_4AFBD0)() = (int(*)())(0x4AFBD0);
static int(*sub_5E8290)() = (int(*)())(0x5E8290);
static int(*sub_6826D0)() = (int(*)())(0x6826D0);
static int(*sub_6830B0)() = (int(*)())(0x6830B0);
static int(*sub_6831A0)() = (int(*)())(0x6831A0);
static int(*sub_90D130)() = (int(*)())(0x90D130);
static int(*sub_944C9F)() = (int(*)())(0x944C9F);
static int(*sub_944CFF)() = (int(*)())(0x944CFF);
static int(*sub_944E46)() = (int(*)())(0x944E46);
static int(*sub_9452CA)() = (int(*)())(0x9452CA);
static int(*sub_48ECE0)() = (int(*)())(0x48ECE0);
static int(*sub_599E00)() = (int(*)())(0x599E00);
static int(*sub_5A0590)() = (int(*)())(0x5A0590);
static int(*sub_689C80)() = (int(*)())(0x689C80);
static int(*sub_5750A0)() = (int(*)())(0x5750A0);
static int(*sub_574A20)() = (int(*)())(0x574A20);
static int(*sub_574E60)() = (int(*)())(0x574E60);
static int(*sub_68A980)() = (int(*)())(0x68A980);
static int(*sub_687970)() = (int(*)())(0x687970);
static int(*sub_4A1C50)() = (int(*)())(0x4A1C50);
static int(*sub_6835C0)() = (int(*)())(0x6835C0);
static int(*sub_6827D0)() = (int(*)())(0x6827D0);
static int(*sub_68AA80)() = (int(*)())(0x68AA80);
static int(*sub_79CEE0)() = (int(*)())(0x79CEE0);

void __fastcall sub_5750A0_promote_teams_to_bottom_league_c(BYTE *_this)
{
	dprintf("sub_5750A0_promote_teams_to_bottom_league_c called - _this: %08X (eng_prm)\n", _this);

	std::vector<cm3_clubs*> northern_relegated_clubs = get_relegated_teams(NorthernConferenceDivisionCompID);
	std::vector<cm3_clubs*> southern_relegated_clubs = get_relegated_teams(SouthernConferenceDivisionCompID);
	std::vector<cm3_clubs*> available_clubs;
	
	for (int i = 0; i < get_club_count(); i++)
	{
		cm3_clubs *club = get_club(i);
		if (club)
		{
			if (club->ClubDivision && club->ClubNation)
			{
				DWORD compID = club->ClubDivision->ClubCompID;
				DWORD nationID = club->ClubNation->NationID;
				if (nationID == Get9CF(0x9cf2e4) &&		// England
					compID != Get9CF(0x9cf5bc) &&		// Premier Division
					compID != Get9CF(0x9cf5c0) &&		// First Division
					compID != Get9CF(0x9cf5c4) &&		// Second Division
					compID != Get9CF(0x9cf5c8) &&		// Third Division
					compID != Get9CF(0x9cf69c) &&		// Conference
					compID != Get9CF(0x9cf764) &&		// A Lower Division
					compID != NorthernConferenceDivisionCompID &&
					compID != SouthernConferenceDivisionCompID)	// Nothern Premier
				{
					dprintf("Available Club: %s (%s)\n", club->ClubName, club->ClubDivision->ClubCompName);
					available_clubs.push_back(club);
				}
			}
		}
	}

	for (unsigned int i = 0; i < northern_relegated_clubs.size(); i++)
	{
		int availableIdx = rand() % available_clubs.size();
		cm3_clubs *clubToRelegate = northern_relegated_clubs[i];
		cm3_clubs *available = available_clubs[availableIdx];

		dprintf("Swapping Teams: %s (%s) <-> %s (%s)\n", clubToRelegate->ClubName, clubToRelegate->ClubDivision->ClubCompName, available->ClubName, available->ClubDivision->ClubCompName);

		cm3_club_comps *tempDivision = available->ClubDivision;
		available->ClubDivision = clubToRelegate->ClubDivision;
		clubToRelegate->ClubDivision = tempDivision;

		available_clubs.erase(available_clubs.begin() + availableIdx);
	}
		
	for (unsigned int i = 0; i < southern_relegated_clubs.size(); i++)
	{
		int availableIdx = rand() % available_clubs.size();
		cm3_clubs* clubToRelegate = southern_relegated_clubs[i];
		cm3_clubs* available = available_clubs[availableIdx];

		dprintf("Swapping Teams: %s (%s) <-> %s (%s)\n", clubToRelegate->ClubName, clubToRelegate->ClubDivision->ClubCompName, available->ClubName, available->ClubDivision->ClubCompName);

		cm3_club_comps* tempDivision = available->ClubDivision;
		available->ClubDivision = clubToRelegate->ClubDivision;
		clubToRelegate->ClubDivision = tempDivision;

		available_clubs.erase(available_clubs.begin() + availableIdx);
	}
}

void __declspec(naked) sub_eng_prm_574C10()  // eng_prm +8 Func
{
	__asm
	{
	/*00574C10*/	sub esp,0x200
	/*00574C16*/	push esi
	/*00574C17*/	mov esi,ecx
	/*00574C19*/	push edi
	/*00574C1A*/	xor edi,edi
	/*00574C1C*/	mov eax,dword ptr ds:[esi]
	/*00574C1E*/	push 0x1
	/*00574C20*/	mov dword ptr ds:[esi+0x4C],edi
	/*00574C23*/	call dword ptr ds:[eax+0xB0]						// <--- calling 0xB0
	/*00574C29*/	mov ecx,dword ptr ds:[0xADADFC]
	/*00574C2F*/	mov edx,dword ptr ds:[0x9CF69C]						// [9cf69c] = English Conference
	/*00574C35*/	mov eax,dword ptr ds:[ecx+edx*0x4]
	/*00574C38*/	mov ecx,esi
	/*00574C3A*/	cmp eax,edi
	/*00574C3C*/	je _00574C45
	/*00574C3E*/	call sub_5750A0		/*call <cm0102.sub_5750A0>*/	// <---- do the conference relegation
	/*00574C43*/	jmp _00574C4A
_00574C45:
	/*00574C45*/	call sub_574E60		/*call <cm0102.sub_574E60>*/
_00574C4A:
	/*00574C4A*/	push edi
	/*00574C4B*/	mov ecx,esi
	/*00574C4D*/	call sub_687970		/*call <cm0102.sub_687970>*/
	/*00574C52*/	mov eax,dword ptr ds:[esi+0xBA]
	/*00574C58*/	cmp eax,edi
	/*00574C5A*/	je _00574C6B
	/*00574C5C*/	push eax
	/*00574C5D*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*00574C62*/	add esp,0x4
	/*00574C65*/	mov dword ptr ds:[esi+0xBA],edi
_00574C6B:
	/*00574C6B*/	mov ecx,dword ptr ds:[esi+0x8]
	/*00574C6E*/	cmp ecx,edi
	/*00574C70*/	je _00574C79
	/*00574C72*/	push 0x1
	/*00574C74*/	call sub_4A1C50		/*call cm0102.4A1C50*/
_00574C79:
	/*00574C79*/	mov eax,dword ptr ds:[esi]
	/*00574C7B*/	inc word ptr ds:[esi+0x40]
	/*00574C7F*/	mov ecx,esi
	/*00574C81*/	call dword ptr ds:[eax+0x8C]
	/*00574C87*/	test eax,eax
	/*00574C89*/	jne _00574CBD
	/*00574C8B*/	lea ecx,dword ptr ss:[esp+0x8]
	/*00574C8F*/	lea edx,dword ptr ss:[esp+0x108]
	/*00574C96*/	push ecx
	/*00574C97*/	push edx
	/*00574C98*/	push edi
	/*00574C99*/	push edi
	/*00574C9A*/	push 0x9C43B0		/*push cm0102.9C43B0*/
	/*00574C9F*/	call sub_944CFF		/*call <cm0102.sub_944CFF>*/
	/*00574CA4*/	add esp,0x14
	/*00574CA7*/	lea eax,dword ptr ss:[esp+0x8]
	/*00574CAB*/	lea ecx,dword ptr ss:[esp+0x108]
	/*00574CB2*/	push 0x267
	/*00574CB7*/	push eax
	/*00574CB8*/	jmp _00574D6C
_00574CBD:
	/*00574CBD*/	mov ecx,esi
	/*00574CBF*/	call sub_574A20		/*call <cm0102.sub_574A20>*/
	/*00574CC4*/	test eax,eax
	/*00574CC6*/	jne _00574CF8
	/*00574CC8*/	lea edx,dword ptr ss:[esp+0x108]
	/*00574CCF*/	lea eax,dword ptr ss:[esp+0x8]
	/*00574CD3*/	push edx
	/*00574CD4*/	push eax
	/*00574CD5*/	push edi
	/*00574CD6*/	push edi
	/*00574CD7*/	push 0x9C43B0		/*push cm0102.9C43B0*/
	/*00574CDC*/	call sub_944CFF		/*call <cm0102.sub_944CFF>*/
	/*00574CE1*/	add esp,0x14
	/*00574CE4*/	lea ecx,dword ptr ss:[esp+0x108]
	/*00574CEB*/	lea edx,dword ptr ss:[esp+0x8]
	/*00574CEF*/	push 0x26E
	/*00574CF4*/	push ecx
	/*00574CF5*/	push edx
	/*00574CF6*/	jmp _00574D6D
_00574CF8:
	/*00574CF8*/	mov ecx,esi
	/*00574CFA*/	call sub_6835C0		/*call cm0102.6835C0*/
	/*00574CFF*/	test eax,eax
	/*00574D01*/	jne _00574D33
	/*00574D03*/	lea eax,dword ptr ss:[esp+0x108]
	/*00574D0A*/	lea ecx,dword ptr ss:[esp+0x8]
	/*00574D0E*/	push eax
	/*00574D0F*/	push ecx
	/*00574D10*/	push edi
	/*00574D11*/	push edi
	/*00574D12*/	push 0x9C43B0		/*push cm0102.9C43B0*/
	/*00574D17*/	call sub_944CFF		/*call <cm0102.sub_944CFF>*/
	/*00574D1C*/	add esp,0x14
	/*00574D1F*/	lea edx,dword ptr ss:[esp+0x108]
	/*00574D26*/	lea eax,dword ptr ss:[esp+0x8]
	/*00574D2A*/	push 0x274
	/*00574D2F*/	push edx
	/*00574D30*/	push eax
	/*00574D31*/	jmp _00574D6D
_00574D33:
	/*00574D33*/	push edi
	/*00574D34*/	mov ecx,esi
	/*00574D36*/	call sub_6827D0		/*call <cm0102.sub_6827D0>*/
	/*00574D3B*/	test eax,eax
	/*00574D3D*/	jne _00574DA4
	/*00574D3F*/	lea ecx,dword ptr ss:[esp+0x108]
	/*00574D46*/	lea edx,dword ptr ss:[esp+0x8]
	/*00574D4A*/	push ecx
	/*00574D4B*/	push edx
	/*00574D4C*/	push edi
	/*00574D4D*/	push edi
	/*00574D4E*/	push 0x9C43B0		/*push cm0102.9C43B0*/
	/*00574D53*/	call sub_944CFF		/*call <cm0102.sub_944CFF>*/
	/*00574D58*/	add esp,0x14
	/*00574D5B*/	lea eax,dword ptr ss:[esp+0x108]
	/*00574D62*/	lea ecx,dword ptr ss:[esp+0x8]
	/*00574D66*/	push 0x27B
	/*00574D6B*/	push eax
_00574D6C:
	/*00574D6C*/	push ecx
_00574D6D:
	/*00574D6D*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*00574D72*/	push eax
	/*00574D73*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00574D78*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00574D7D*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*00574D82*/	push edi
	/*00574D83*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00574D88*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00574D8D*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*00574D92*/	add esp,0x24
	/*00574D95*/	mov dword ptr ds:[0xB67A34],edi
	/*00574D9B*/	pop edi
	/*00574D9C*/	pop esi
	/*00574D9D*/	add esp,0x200
	/*00574DA3*/	ret
_00574DA4:
	/*00574DA4*/	mov edx,dword ptr ds:[esi]
	/*00574DA6*/	mov ecx,esi
	/*00574DA8*/	call dword ptr ds:[edx+0x5C]
	/*00574DAB*/	mov eax,dword ptr ds:[0xADADFC]
	/*00574DB0*/	mov ecx,dword ptr ds:[0x9CF5C8]							// [9cf5c8] = English Third Division		
	/*00574DB6*/	push 0x1
	/*00574DB8*/	push 0xFFFFFFFD
	/*00574DBA*/	mov ecx,dword ptr ds:[eax+ecx*0x4]
	/*00574DBD*/	push 0x3
	/*00574DBF*/	push 0x1
	/*00574DC1*/	call sub_68A980		/*call <cm0102.sub_68A980>*/
	/*00574DC6*/	mov edx,dword ptr ds:[0x9CF69C]							// [9cf69c] = English Conference
	/*00574DCC*/	mov eax,dword ptr ds:[0xADADFC]
	/*00574DD1*/	mov ecx,dword ptr ds:[eax+edx*0x4]
	/*00574DD4*/	cmp ecx,edi
	/*00574DD6*/	je _00574DE4
	/*00574DD8*/	push 0x1
	/*00574DDA*/	push 0xFFFFFFFD
	/*00574DDC*/	push edi
	/*00574DDD*/	push 0x2
	/*00574DDF*/	call sub_68A980		/*call <cm0102.sub_68A980>*/
_00574DE4:
	/*00574DE4*/	mov ecx,dword ptr ds:[0x9CF5C0]
	/*00574DEA*/	mov edx,dword ptr ds:[0xADADFC]
	/*00574DF0*/	mov ecx,dword ptr ds:[edx+ecx*0x4]
	/*00574DF3*/	mov eax,dword ptr ds:[ecx]
	/*00574DF5*/	call dword ptr ds:[eax+0x8]
	/*00574DF8*/	mov ecx,dword ptr ds:[0xADADFC]
	/*00574DFE*/	mov edx,dword ptr ds:[0x9CF5C4]
	/*00574E04*/	mov ecx,dword ptr ds:[ecx+edx*0x4]
	/*00574E07*/	mov eax,dword ptr ds:[ecx]
	/*00574E09*/	call dword ptr ds:[eax+0x8]
	/*00574E0C*/	mov ecx,dword ptr ds:[0xADADFC]
	/*00574E12*/	mov edx,dword ptr ds:[0x9CF5C8]
	/*00574E18*/	mov ecx,dword ptr ds:[ecx+edx*0x4]
	/*00574E1B*/	mov eax,dword ptr ds:[ecx]
	/*00574E1D*/	call dword ptr ds:[eax+0x8]
	/*00574E20*/	mov ecx,dword ptr ds:[0xADADFC]
	/*00574E26*/	mov edx,dword ptr ds:[0x9CF69C]
	/*00574E2C*/	mov ecx,dword ptr ds:[ecx+edx*0x4]
	/*00574E2F*/	cmp ecx,edi
	/*00574E31*/	je _00574E38
	/*00574E33*/	mov eax,dword ptr ds:[ecx]
	/*00574E35*/	call dword ptr ds:[eax+0x8]

					// Without the the northern conference's +0x8 function does not get called (if the rele/prom is added)
					mov ecx, dword ptr ds:[0xADADFC]						
					mov edx, dword ptr ds:[NorthernConferenceDivisionCompID]
					mov ecx, dword ptr ds:[ecx + edx * 0x4]
					mov eax, dword ptr ds:[ecx]
					call dword ptr ds:[eax+0x8]

		
					mov ecx, dword ptr ds:[0xADADFC]						
					mov edx, dword ptr ds:[SouthernConferenceDivisionCompID]
					mov ecx, dword ptr ds:[ecx + edx * 0x4]
					mov eax, dword ptr ds:[ecx]
					call dword ptr ds:[eax+0x8]
					
_00574E38:
	/*00574E38*/	mov ecx,esi
	/*00574E3A*/	call sub_68AA80		/*call <cm0102.sub_68AA80>*/
	/*00574E3F*/	mov ecx,dword ptr ds:[esi+0x4]
	/*00574E42*/	push ecx
	/*00574E43*/	mov ecx,dword ptr ds:[0xB74340]
	/*00574E49*/	call sub_79CEE0		/*call <cm0102.sub_79CEE0>*/
	/*00574E4E*/	pop edi
	/*00574E4F*/	pop esi
	/*00574E50*/	add esp,0x200
	/*00574E56*/	ret
	}
}

void eng_prm_prom_rel_update(BYTE* _this, int a2) 
{
	DWORD v1 = *(DWORD*)_this;
	(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(_this);

	BYTE* eng_first = get_loaded_league(Get9CF(0x9CF5C0));
	v1 = *(DWORD*)eng_first;
	(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(eng_first);

	BYTE* eng_second = get_loaded_league(Get9CF(0x9CF5C4));
	v1 = *(DWORD*)eng_second;
	(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(eng_second);

	BYTE* eng_third = get_loaded_league(Get9CF(0x9CF5C8));
	v1 = *(DWORD*)eng_third;
	(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(eng_third);

	sub_689C80_promote(_this, _this, eng_first, 1, a2, -1, -1);
	sub_689C80_promote(_this, eng_first, eng_second, 1, a2, -1, -1);
	sub_689C80_promote(_this, eng_second, eng_third, 1, a2, -1, -1);

	BYTE* eng_conf = get_loaded_league(Get9CF(0x9CF69C));
	if (eng_conf) {
		v1 = *(DWORD*)eng_conf;
		(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(eng_conf);
		BYTE* eng_conf_n = get_loaded_league(0x168);
		v1 = *(DWORD*)eng_conf_n;
		(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(eng_conf_n);
		BYTE* eng_conf_s = get_loaded_league(0x167);
		v1 = *(DWORD*)eng_conf_s;
		(*(int(__thiscall**)(BYTE*))(v1 + 0xA4))(eng_conf_s);

		// To do: stadium capacity validations
		sub_689C80_promote(_this, eng_third, eng_conf, 1, a2, -1, -1);
		sub_689C80_promote(_this, eng_conf, eng_conf_n, 1, a2, -1, -1);
		sub_689C80_promote(_this, eng_conf, eng_conf_s, 1, a2, -1, -1);
	}
}

void __declspec(naked) sub_5752E0_eng_prm_promo()			// +B0 Func
{
	__asm
	{
		//ret 0x4;

	/*005752E0*/	mov eax,dword ptr ds:[0xADADFC]
	/*005752E5*/	mov edx,dword ptr ds:[0x9CF69C]					// [9cf69c] = English Conference
	/*005752EB*/	push ebx
	/*005752EC*/	push ebp
	/*005752ED*/	mov ebp,dword ptr ds:[eax+edx*0x4]
	/*005752F0*/	push esi
	/*005752F1*/	mov esi,ecx
	/*005752F3*/	push edi
	/*005752F4*/	mov ecx,dword ptr ds:[0x9CF5C8]					// [9cf5c8] = English Third Division
	/*005752FA*/	mov edi,dword ptr ds:[eax+ecx*0x4]
	/*005752FD*/	mov eax,dword ptr ds:[esi]
	/*005752FF*/	mov ecx,esi
	/*00575301*/	call dword ptr ds:[eax+0xA4]
	
	/*00575307*/	mov ecx,dword ptr ds:[0xADADFC]
	/*0057530D*/	mov edx,dword ptr ds:[0x9CF5C0]					// [9cf5c0] = English First Division
	/*00575313*/	mov ecx,dword ptr ds:[ecx+edx*0x4]
	/*00575316*/	mov eax,dword ptr ds:[ecx]
	/*00575318*/	call dword ptr ds:[eax+0xA4]
	
	/*0057531E*/	mov ecx,dword ptr ds:[0xADADFC]
	/*00575324*/	mov edx,dword ptr ds:[0x9CF5C4]					// [9cf5c4] = English Second Division
	/*0057532A*/	mov ecx,dword ptr ds:[ecx+edx*0x4]
	/*0057532D*/	mov eax,dword ptr ds:[ecx]
	/*0057532F*/	call dword ptr ds:[eax+0xA4]
	
	/*00575335*/	mov ecx,dword ptr ds:[0xADADFC]
	/*0057533B*/	mov edx,dword ptr ds:[0x9CF5C8]					// [9cf5c8] = English Third Division
	/*00575341*/	mov ecx,dword ptr ds:[ecx+edx*0x4]
	/*00575344*/	mov eax,dword ptr ds:[ecx]
	/*00575346*/	call dword ptr ds:[eax+0xA4]

	/*0057534C*/	mov eax,dword ptr ds:[0xADADFC]
	/*00575351*/	mov ecx,dword ptr ds:[0x9CF5C0]					// [9cf5c0] = English First Division
	/*00575357*/	mov ebx,dword ptr ss:[esp+0x14]
	/*0057535B*/	push 0xFFFFFFFF
	/*0057535D*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*00575360*/	mov ecx,dword ptr ds:[0x9CF5BC]					// [9cf5bc] = English Premier League
	/*00575366*/	push 0xFFFFFFFF
	/*00575368*/	push ebx
	/*00575369*/	push 0x1
	/*0057536B*/	push edx
	/*0057536C*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*0057536F*/	mov ecx,esi
	/*00575371*/	push edx
	/*00575372*/	call sub_689C80		/*call <cm0102.sub_689C80>*/

	/*00575377*/	mov eax,dword ptr ds:[0xADADFC]
	/*0057537C*/	mov ecx,dword ptr ds:[0x9CF5C4]					// [9cf5c4] = English Second Division
	/*00575382*/	push 0xFFFFFFFF
	/*00575384*/	push 0xFFFFFFFF
	/*00575386*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*00575389*/	mov ecx,dword ptr ds:[0x9CF5C0]					// [9cf5c0] = English First Division
	/*0057538F*/	push ebx
	/*00575390*/	push 0x1
	/*00575392*/	push edx
	/*00575393*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*00575396*/	push edx
	/*00575397*/	mov ecx,esi
	/*00575399*/	call sub_689C80		/*call <cm0102.sub_689C80>*/

	/*0057539E*/	mov eax,dword ptr ds:[0xADADFC]
	/*005753A3*/	mov ecx,dword ptr ds:[0x9CF5C8]					// [9cf5c8] = English Third Division
	/*005753A9*/	push 0xFFFFFFFF
	/*005753AB*/	push 0xFFFFFFFF
	/*005753AD*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*005753B0*/	mov ecx,dword ptr ds:[0x9CF5C4]					// [9cf5c4] = English Second Division
	/*005753B6*/	push ebx
	/*005753B7*/	push 0x1
	/*005753B9*/	push edx
	/*005753BA*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*005753BD*/	push edx
	/*005753BE*/	mov ecx,esi
	/*005753C0*/	call sub_689C80		/*call <cm0102.sub_689C80>*/

	/*005753C5*/	test ebp,ebp									// Test if English Conference exists
	/*005753C7*/	je _00575492

	/*005753CD*/	mov eax,dword ptr ds:[0xADADFC]
	/*005753D2*/	mov ecx,dword ptr ds:[0x9CF69C]					// [9cf69c] = English Conference
	/*005753D8*/	mov ecx,dword ptr ds:[eax+ecx*0x4]
	/*005753DB*/	mov edx,dword ptr ds:[ecx]
	/*005753DD*/	call dword ptr ds:[edx+0xA4]

					mov ecx, dword ptr ds:[0xADADFC]
					mov edx, dword ptr ds:[NorthernConferenceDivisionCompID]		// NorthernConferenceDivisionCompID
					mov ecx, dword ptr ds:[ecx+edx*0x4]
					mov eax, dword ptr ds:[ecx]
					call dword ptr ds:[eax+0xA4]

					mov ecx, dword ptr ds:[0xADADFC]
					mov edx, dword ptr ds:[SouthernConferenceDivisionCompID]		// SouthernConferenceDivisionCompID
					mov ecx, dword ptr ds:[ecx + edx * 0x4]
					mov eax, dword ptr ds:[ecx]
					call dword ptr ds:[eax + 0xA4]
					
	/*005753E3*/	mov ax,word ptr ds:[edi+0xE2]									// edi is 3rd Division ??
	/*005753EA*/	mov edx,dword ptr ds:[edi+0x4]
	/*005753ED*/	mov cx,word ptr ds:[edi+0xE4]
	/*005753F4*/	push 0x1
	/*005753F6*/	mov edx,dword ptr ds:[edx]
	/*005753F8*/	movsx eax,ax
	/*005753FB*/	movsx ecx,cx
	/*005753FE*/	push edx
	/*005753FF*/	push eax
	/*00575400*/	push ecx
	/*00575401*/	push 0x0
	/*00575403*/	mov ecx,ebp
	/*00575405*/	call sub_6826D0		/*call <cm0102.sub_6826D0>*/

	/*0057540A*/	mov edx,dword ptr ds:[eax]
	/*0057540C*/	mov ecx,dword ptr ds:[0xAE2A38]
	/*00575412*/	push edx
	/*00575413*/	call sub_5A0590		/*call <cm0102.sub_5A0590>*/
	/*00575418*/	mov ecx,eax
	/*0057541A*/	call sub_599E00		/*call <cm0102.sub_599E00>*/
	/*0057541F*/	test al,al
	/*00575421*/	jne _0057546B

	/*00575423*/	movsx eax,word ptr ds:[edi+0x3E]
	/*00575427*/	dec eax
	/*00575428*/	mov ecx,edi
	/*0057542A*/	push eax
	/*0057542B*/	call sub_6826D0		/*call <cm0102.sub_6826D0>*/
	/*00575430*/	push 0x2
	/*00575432*/	push 0x0
	/*00575434*/	push 0x0
	/*00575436*/	mov ecx,ebp
	/*00575438*/	mov byte ptr ds:[eax+0x37],0xFE
	/*0057543C*/	call sub_6826D0		/*call <cm0102.sub_6826D0>*/


	/*00575441*/	mov ecx,dword ptr ds:[eax]
	/*00575443*/	mov eax,dword ptr ds:[0x9CF69C]			// [0x9CF69C]							// [9cf69c] = English Conference
	/*00575448*/	push ecx
	/*00575449*/	lea ecx,dword ptr ds:[eax+eax*0x2]
	/*0057544C*/	lea edx,dword ptr ds:[ecx+ecx*0x8]
	/*0057544F*/	mov ecx,dword ptr ds:[0xAE23D0]
	/*00575455*/	shl edx,0x2
	/*00575458*/	sub edx,eax
	/*0057545A*/	add edx,ecx
	/*0057545C*/	mov ecx,edi
	/*0057545E*/	push edx
	/*0057545F*/	call sub_48ECE0		/*call <cm0102.sub_48ECE0>*/

	/*00575464*/	pop edi
	/*00575465*/	pop esi
	/*00575466*/	pop ebp
	/*00575467*/	pop ebx
	/*00575468*/	ret 0x4
_0057546B:
	/*0057546B*/	mov eax,dword ptr ds:[0xADADFC]
	/*00575470*/	mov ecx,dword ptr ds:[0x9CF69C]							// [9cf69c] = English Conference
	/*00575476*/	push 0xFFFFFFFF
	/*00575478*/	push 0xFFFFFFFF
	/*0057547A*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*0057547D*/	mov ecx,dword ptr ds:[0x9CF5C8]							// [9cf5c8] = English Third Division
	/*00575483*/	push ebx
	/*00575484*/	push 0x1
	/*00575486*/	push edx
	/*00575487*/	mov edx,dword ptr ds:[eax+ecx*0x4]
	/*0057548A*/	push edx
	/*0057548B*/	mov ecx,esi
	/*0057548D*/	call sub_689C80		/*call <cm0102.sub_689C80>*/

		
					// Do the promotion and relegation between the two leagues
					mov eax, dword ptr ds:[0xADADFC]
					mov ecx, dword ptr ds:[NorthernConferenceDivisionCompID]				// NorthernConferenceDivisionCompID
					push 0xFFFFFFFF
					push 0xFFFFFFFF
					mov edx, dword ptr ds:[eax+ecx*0x4]
					mov ecx, dword ptr ds:[0x9CF69C]							// [9cf69c] = English Conference
					push ebx
					push 0x1
					push edx
					mov edx, dword ptr ds:[eax+ecx*0x4]
					push edx
					mov ecx, esi
					call sub_689C80		//call <cm0102.sub_689C80>
		
					// Do the promotion and relegation between the two leagues
					mov eax, dword ptr ds:[0xADADFC]
					mov ecx, dword ptr ds:[SouthernConferenceDivisionCompID]				// SouthernConferenceDivisionCompID
					push 0xFFFFFFFF
					push 0xFFFFFFFF
					mov edx, dword ptr ds:[eax+ecx*0x4]
					mov ecx, dword ptr ds:[0x9CF69C]							// [9cf69c] = English Conference
					push ebx
					push 0x1
					push edx
					mov edx, dword ptr ds:[eax+ecx*0x4]
					push edx
					mov ecx, esi
					call sub_689C80		//call <cm0102.sub_689C80>
					
_00575492:
	/*00575492*/	pop edi
	/*00575493*/	pop esi
	/*00575494*/	pop ebp
	/*00575495*/	pop ebx
	/*00575496*/	ret 0x4
	}
}

void patch_eng_prm()
{
	vtable::PrintVTable(0x969D1C, "eng_prm.cpp");

	PatchFunction(0x5750A0, (DWORD)&sub_5750A0_promote_teams_to_bottom_league_c);
	PatchFunction(0x5752E0, (DWORD)&sub_5752E0_eng_prm_promo);
	PatchFunction(0x574C10, (DWORD)&sub_eng_prm_574C10);
}
