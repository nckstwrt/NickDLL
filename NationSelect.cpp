#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "CMHeader.h"
#include "Helper.h"
#include "generic_functions.h"
#include "Date.h"
#include "LeagueInfo.h"
#include <deque>

static int(*sub_7A1710)() = (int(*)())(0x7A1710);
static int(*sub_41BFB0)() = (int(*)())(0x41BFB0);
static int(*sub_66F4E0)() = (int(*)())(0x66F4E0);
static int(*sub_803F30)() = (int(*)())(0x803F30);
static int(*sub_75DB00)() = (int(*)())(0x75DB00);
static int(*sub_803F80)() = (int(*)())(0x803F80);
static int(*sub_55FBA0)() = (int(*)())(0x55FBA0);
static int(*sub_8040A0)() = (int(*)())(0x8040A0);
static int(*sub_804100)() = (int(*)())(0x804100);
static int(*sub_944C9F)() = (int(*)())(0x944C9F);
static int(*sub_669F50)() = (int(*)())(0x669F50);
static int(*sub_7FEBB0)() = (int(*)())(0x7FEBB0);
static int(*sub_7FEC60)() = (int(*)())(0x7FEC60);
static int(*sub_5EDCC0)() = (int(*)())(0x5EDCC0);
static int(*sub_7FF010)() = (int(*)())(0x7FF010);
static int(*sub_403320)() = (int(*)())(0x403320);
static int(*sub_7FF270)() = (int(*)())(0x7FF270);
static int(*sub_90D130)() = (int(*)())(0x90D130);
static int(*sub_945501)() = (int(*)())(0x945501);
static int(*sub_944CF1)() = (int(*)())(0x944CF1);
static int(*sub_404250)() = (int(*)())(0x404250);
static int(*sub_406BF0)() = (int(*)())(0x406BF0);
static int(*sub_549F70)() = (int(*)())(0x549F70);
static int(*sub_945333)() = (int(*)())(0x945333);
static int(*sub_90C1D0)() = (int(*)())(0x90C1D0);
static int(*sub_524D50)() = (int(*)())(0x524D50);
static int(*sub_5D8480)() = (int(*)())(0x5D8480);
static int(*sub_5E8290)() = (int(*)())(0x5E8290);
static int(*sub_667150)() = (int(*)())(0x667150);
static int(*sub_827D50)() = (int(*)())(0x827D50);
static int(*sub_90BDE0)() = (int(*)())(0x90BDE0);
static int(*sub_5E8290_message_box)() = (int(*)())(0x5E8290);

void sub_66A0C0();
void sub_66A100();

void sub_576DD0_eng_third_init();

DWORD GenericSetup(BYTE* nation_data) 
{
	BYTE compNo = 0;
	cm3_nations *nation = (cm3_nations*)*(DWORD*)(nation_data);
	DWORD *numberOfComps = (DWORD*)(nation_data + 0xc);

	*(WORD*)(nation_data + 0x37) = 5;
	*(WORD*)(nation_data + 0x32) = 10;
	*(BYTE*)(nation_data + 0x34) = 7;
	*(WORD*)(nation_data + 0x35) = (WORD)*current_year;
	*(WORD*)(nation_data + 0x46) = 5;
	*(WORD*)(nation_data + 0x41) = 24;
	*(BYTE*)(nation_data + 0x43) = 4;
	*(WORD*)(nation_data + 0x44) = *current_year + 1;
	*(DWORD*)(nation_data + 0x26) = 0;		// Cup Comp

	NationLeagueInfo *nation_league_info = get_nation_league_info(nation->NationName);

	*numberOfComps = nation_league_info->GetPlayableLeagues();
	*(DWORD*)(nation_data + 0x10) = (DWORD)sub_944E46_malloc(*numberOfComps * 4);		// Allocate memory for comps
	for (size_t i = 0; i < *numberOfComps; i++)
	{
		LeagueInfo league = nation_league_info->leagues[i];
		AddLeague(nation_data, league.Comp->ClubCompID, compNo++, *current_year, league.SetupFunction);
	}

	Date startDate(*current_year, 6, 20);
	
	*(WORD*)(nation_data + 0x15) = (WORD)startDate.DayOfYear();
	*(WORD*)(nation_data + 0x1B) = *current_year;
	*(BYTE*)(nation_data + 0x1D) = 1;
	return 1;
}

/*
0. 00B63D60 00000000  (Setup Func: 00830620)
1. 00B63DA8 00000000  (Setup Func: 00830AC0)
2. 00B63DF0 00000000  (Setup Func: 00830FE0)
3. 00B63E38 00000000  (Setup Func: 008312E0)
4. 00B63E80 00000000  (Setup Func: 00831650)
5. 00B63EC8 00000000  (Setup Func: 008318F0)
6. 00B63F10 00000000  (Setup Func: 00831BA0)
7. 00B63F58 00000000  (Setup Func: 00831EB0)
8. 00B63FA0 170E8F84 Argentina (Setup Func: 00832100)
9. 00B63FE8 170E92EA Australia (Setup Func: 00832380)
10. 00B64030 170E9BFA Belgium (Setup Func: 008325D0)
11. 00B64078 170EA50A Brazil (Setup Func: 00832980)
12. 00B640C0 170EBCD4 Croatia (Setup Func: 008330B0)
13. 00B64108 170EC27E Denmark (Setup Func: 00833400)
14. 00B64150 170ECB8E England (Setup Func: 00833750)
15. 00B64198 170ED49E Finland (Setup Func: 00833CF0)
16. 00B641E0 170ED5C0 France (Setup Func: 00833FF0)
17. 00B64228 170EDA48 Germany (Setup Func: 008343F0)
18. 00B64270 170EDC8C Greece (Setup Func: 008347C0)
19. 00B642B8 170EE59C Holland (Setup Func: 00834B10)
20. 00B64300 170EEFCE Republic of Ireland (Setup Func: 00834E60)
21. 00B64348 170EF212 Italy (Setup Func: 00835320)
22. 00B64390 170EF578 Japan (Setup Func: 00835900)
23. 00B643D8 170F1896 Northern Ireland (Setup Func: 00835C90)
24. 00B64420 170F23EA Norway (Setup Func: 00836050)
25. 00B64468 170F2F3E Poland (Setup Func: 00836350)
26. 00B644B0 170F3060 Portugal (Setup Func: 008366E0)
27. 00B644F8 170F360A Russia (Setup Func: 00836AC0)
28. 00B64540 170F3CD6 Scotland (Setup Func: 00836DC0)
29. 00B64588 170F482A South Korea (Setup Func: 00837200)
30. 00B645D0 170F494C Spain (Setup Func: 00837560)
31. 00B64618 170F525C Sweden (Setup Func: 008379F0)
32. 00B64660 170F5FF4 Turkey (Setup Func: 00837D70)
33. 00B646A8 170F647C United States (Setup Func: 008380C0)
34. 00B646F0 170F70F2 Wales (Setup Func: 008383B0)
*/

DWORD OriginalNumberOfNations = 0x23;
DWORD TotalNumberOfConsideredNations = 0x23;
BYTE* original_table_ptr = (BYTE*)0xB63D60;
BYTE* nation_table_ptr = (BYTE*)0xB63D60;  // Playable Leagues - 72 byte blocks. First 8 are reserved. 0 = World Cup
BYTE* our_nation_table_ptr;
BYTE* our_sorted_idx_B63D38;
DWORD our_B63D5C = 0;

void AddNation(const char *szNation, DWORD NationSetupFunction)
{
	cm3_nations *country = find_country(szNation);

	// Copy a country as a template
	DWORD country_to_copy = 8; // 29; // South Korea

	memcpy(nation_table_ptr + (TotalNumberOfConsideredNations * 72), nation_table_ptr + (country_to_copy * 72), 72);
	*(DWORD*)(nation_table_ptr + (TotalNumberOfConsideredNations * 72)) = (DWORD)country;
	*(DWORD*)(nation_table_ptr + (TotalNumberOfConsideredNations * 72) + 8) = (DWORD)NationSetupFunction;

	// 0x1E is a cup
	*(DWORD*)(nation_table_ptr + (TotalNumberOfConsideredNations * 72) + 0x1E) = 0; // No Cup Competition

	dprintf("Copied nation as a template: %08X to %08X (%s)\n", original_table_ptr + (country_to_copy * 72), nation_table_ptr + (TotalNumberOfConsideredNations * 72), szNation);

	TotalNumberOfConsideredNations++;
}

void ModifyLeagues()
{
	our_nation_table_ptr = new BYTE[100 * 72];		// Max Nations = 100
	our_sorted_idx_B63D38 = new BYTE[500];
	
	memcpy(our_nation_table_ptr, nation_table_ptr, OriginalNumberOfNations * 72);

	// Switch to using our own larger nation table
	nation_table_ptr = our_nation_table_ptr;

	dprintf("our_nation_table_ptr: %08X\n", our_nation_table_ptr);
	
	for (DWORD i = 0; i < TotalNumberOfConsideredNations; i++)
	{
		BYTE* league = nation_table_ptr + (i*72);
		if (league)
		{
			dprintf("%d. %08X %08X %s (Setup Func: %08X)\n", i, league, *(DWORD*)league, (*(DWORD*)league == 0) ? "" : (char*)((*(DWORD*)league)+4), *(DWORD*)(league+8));
		}
	}

	SetupNationLeagueInfo();

	AddNation("Austria", (DWORD)&GenericSetup);
	AddNation("Czech Republic", (DWORD)&GenericSetup);
	AddNation("Hong Kong", (DWORD)&GenericSetup);
	AddNation("China PR", (DWORD)&GenericSetup);
	AddNation("Luxembourg", (DWORD)&GenericSetup);
	AddNation("Malaysia", (DWORD)&GenericSetup);
	AddNation("Mexico", (DWORD)&GenericSetup);
	AddNation("South Africa", (DWORD)&GenericSetup);
	AddNation("Yugoslavia", (DWORD)&GenericSetup);

	// Hack to get around replacing aus, a key nation, with a euro nation that does not have a cup and can't feed the uefa_seeding (?)
	WriteBytes(0x904819, 11, 0xE9, 0x0A, 0x03, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90);
}

bool NationSelectSetupRun = false;
void NationSelectSetup()
{
	if (!NationSelectSetupRun)
	{
		GetCompIDs();
		ModifyLeagues();
		NationSelectSetupRun = true;
	}
}

int PreCreateLeagues()
{
	int ret = TRUE;
	DWORD nations_selected = *(DWORD*)0xAE2D04;
	dprintf("nations_selected = %d\n", nations_selected);

	if (nations_selected > 27)
	{
		sub_5E8290_message_box_call("Too many nations selected", "Please select a maximum of 27 nations.\r\nIt is recommended, for stability, to select less.", 0);
		ret = FALSE;
	}
	else
	{
		// Original nation table 0xB63D60 needs to be recreated from what we've selected in our fake one
		std::deque<DWORD> free_locations;
		for (DWORD i = 0; i < TotalNumberOfConsideredNations; i++)
		{
			DWORD *nation_ptr = (DWORD*)(nation_table_ptr + (i * 72));
			if (nation_ptr)
			{
				cm3_nations *nation = (cm3_nations *)*nation_ptr;
				if (nation) 
				{
					if (nation->NationLeagueSelected)
					{
						dprintf("Selected Nation: %d. %s\n", i, nation->NationName);
						if (i >= OriginalNumberOfNations)
						{
							DWORD free_location = free_locations.front();
							
							dprintf("free_location = %08X nation_table_ptr = %08X\n", free_location, (DWORD)nation_table_ptr);
							DWORD offset = free_location - (DWORD)nation_table_ptr;
							DWORD copyTo = (0xB63D60 + offset);
							dprintf("Copying To %08X\n", copyTo);
							memcpy((void*)copyTo, nation_ptr, 72);

							free_locations.pop_front();
						}
					}
					else
						free_locations.push_back((DWORD)nation_ptr);
				}
			}
		}
	}

	return ret;
}

void __declspec(naked) NationSelect_81D010()
{
	__asm pushad;
	NationSelectSetup();
	__asm popad;

	__asm
	{
	/*0081D010*/	sub esp,0x2C
	/*0081D013*/	push ebx
	/*0081D014*/	push esi
	/*0081D015*/	mov al,0x2A
	/*0081D017*/	xor ebx,ebx
	/*0081D019*/	push edi
	/*0081D01A*/	mov byte ptr ss:[esp+0x18],0x19
	/*0081D01F*/	mov byte ptr ss:[esp+0x19],0x1
	/*0081D024*/	mov byte ptr ss:[esp+0x1A],0xD
	/*0081D029*/	mov byte ptr ss:[esp+0x1B],0x1
	/*0081D02E*/	mov byte ptr ss:[esp+0x1C],0xF
	/*0081D033*/	mov byte ptr ss:[esp+0x1D],0x1
	/*0081D038*/	mov byte ptr ss:[esp+0x1E],0x13
	/*0081D03D*/	mov byte ptr ss:[esp+0x20],al
	/*0081D041*/	mov byte ptr ss:[esp+0x21],0xD
	/*0081D046*/	mov byte ptr ss:[esp+0x22],0x1
	/*0081D04B*/	mov byte ptr ss:[esp+0x23],0xD
	/*0081D050*/	mov byte ptr ss:[esp+0x24],0xA
	/*0081D055*/	mov byte ptr ss:[esp+0x25],al
	/*0081D059*/	mov byte ptr ss:[esp+0x26],0xD
	/*0081D05E*/	mov byte ptr ss:[esp+0x27],0x1
	/*0081D063*/	mov byte ptr ss:[esp+0x28],0xD
	/*0081D068*/	mov byte ptr ss:[esp+0x2C],bl
	/*0081D06C*/	mov byte ptr ss:[esp+0x2D],bl
	/*0081D070*/	mov byte ptr ss:[esp+0x2E],bl
	/*0081D074*/	mov byte ptr ss:[esp+0x2F],bl
	/*0081D078*/	mov byte ptr ss:[esp+0x30],bl
	/*0081D07C*/	mov byte ptr ss:[esp+0x31],al
	/*0081D080*/	mov byte ptr ss:[esp+0x32],0xD
	/*0081D085*/	mov byte ptr ss:[esp+0x33],0x1
	/*0081D08A*/	mov byte ptr ss:[esp+0x34],0xD
	/*0081D08F*/	call sub_7A1710		/*call <cm0102.sub_7A1710>*/
	/*0081D094*/	mov ecx,eax
	/*0081D096*/	mov eax,0x92492493
	/*0081D09B*/	imul ecx
	/*0081D09D*/	add edx,ecx
	/*0081D09F*/	sar edx,0x2
	/*0081D0A2*/	mov eax,edx
	/*0081D0A4*/	shr eax,0x1F
	/*0081D0A7*/	add edx,eax
	/*0081D0A9*/	mov edi,edx
	/*0081D0AB*/	jne _0081D0B2
	/*0081D0AD*/	mov edi,0x1
_0081D0B2:
	/*0081D0B2*/	mov dword ptr ds:[0xDD7124],ebx
	/*0081D0B8*/	call sub_41BFB0		/*call <cm0102.sub_41BFB0>*/
	/*0081D0BD*/	push 0xA80288		/*push cm0102.A80288*/
	/*0081D0C2*/	push 0xDD70A8		/*push cm0102.DD70A8*/
	/*0081D0C7*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D0CC*/	mov cx,word ptr ds:[0xAE3184]
	/*0081D0D3*/	mov dx,word ptr ds:[0xAE31A8]
	/*0081D0DA*/	add esp,0x8
	/*0081D0DD*/	push 0xDD70A8		/*push cm0102.DD70A8*/
	/*0081D0E2*/	push ecx
	/*0081D0E3*/	push edx
	/*0081D0E4*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D0E9*/	call sub_803F30		/*call <cm0102.sub_803F30>*/
	/*0081D0EE*/	push ebx
	/*0081D0EF*/	push 0x4
	/*0081D0F1*/	call sub_75DB00		/*call <cm0102.sub_75DB00>*/
	/*0081D0F6*/	mov eax,dword ptr ds:[0xDD7118]
	/*0081D0FB*/	add esp,0x8
	/*0081D0FE*/	cmp eax,ebx
	/*0081D100*/	je _0081D109
	/*0081D102*/	push 0xA8042C		/*push cm0102.A8042C*/
	/*0081D107*/	jmp _0081D10E
_0081D109:
	/*0081D109*/	push 0xA80418		/*push cm0102.A80418*/
_0081D10E:
	/*0081D10E*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D113*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D118*/	add esp,0x8
	/*0081D11B*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D120*/	push ebx
	/*0081D121*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D126*/	call sub_803F80		/*call <cm0102.sub_803F80>*/
	/*0081D12B*/	cmp byte ptr ds:[0xB74348],bl
	/*0081D131*/	jne _0081D343
	/*0081D137*/	push 0xFFFFFFFF
	/*0081D139*/	push ebx
	/*0081D13A*/	push 0x2
	/*0081D13C*/	push ebx
	/*0081D13D*/	lea eax,dword ptr ss:[esp+0x30]
	/*0081D141*/	push 0x1
	/*0081D143*/	push eax
	/*0081D144*/	push 0x9
	/*0081D146*/	movsx eax,word ptr ds:[0xB77C7A]
	/*0081D14D*/	push 0xA5
	/*0081D152*/	push 0x20D
	/*0081D157*/	lea ecx,dword ptr ds:[eax+eax*0x2]
	/*0081D15A*/	push 0x91
	/*0081D15F*/	shl ecx,0x8
	/*0081D162*/	push 0x6E
	/*0081D164*/	mov ecx,dword ptr ds:[ecx+0xB74C4C]
	/*0081D16A*/	call sub_55FBA0		/*call <cm0102.sub_55FBA0>*/
	/*0081D16F*/	push 0xA80404		/*push cm0102.A80404*/
	/*0081D174*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D179*/	mov esi,eax
	/*0081D17B*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D180*/	mov dx,word ptr ds:[0xAE3184]
	/*0081D187*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D18D*/	add esp,0x8
	/*0081D190*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D195*/	push ebx
	/*0081D196*/	push ebx
	/*0081D197*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D19C*/	push edx
	/*0081D19D*/	push 0x1
	/*0081D19F*/	push 0x1
	/*0081D1A1*/	push eax
	/*0081D1A2*/	push 0x1
	/*0081D1A4*/	push ebx
	/*0081D1A5*/	push ebx
	/*0081D1A6*/	push esi
	/*0081D1A7*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D1AC*/	mov eax,dword ptr ds:[0xDD7118]
	/*0081D1B1*/	cmp eax,ebx
	/*0081D1B3*/	mov al,byte ptr ds:[0x9B5981]
	/*0081D1B8*/	je _0081D26B
	/*0081D1BE*/	cmp al,bl
	/*0081D1C0*/	push 0x98E8D0		/*push cm0102.98E8D0*/
	/*0081D1C5*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D1CA*/	je _0081D1F6
	/*0081D1CC*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D1D1*/	mov cx,word ptr ds:[0xAEBDD4]
	/*0081D1D8*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D1DF*/	add esp,0x8
	/*0081D1E2*/	push ebx
	/*0081D1E3*/	push ebx
	/*0081D1E4*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D1E9*/	push ecx
	/*0081D1EA*/	push 0x1
	/*0081D1EC*/	push 0xC
	/*0081D1EE*/	push edx
	/*0081D1EF*/	push 0x801
	/*0081D1F4*/	jmp _0081D216
_0081D1F6:
	/*0081D1F6*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D1FB*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D201*/	add esp,0x8
	/*0081D204*/	mov cx,ax
	/*0081D207*/	push ebx
	/*0081D208*/	push ebx
	/*0081D209*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D20E*/	push ecx
	/*0081D20F*/	push 0x1
	/*0081D211*/	push 0xC
	/*0081D213*/	push eax
	/*0081D214*/	push 0x1
_0081D216:
	/*0081D216*/	push ebx
	/*0081D217*/	push 0x1
	/*0081D219*/	push esi
	/*0081D21A*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D21F*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D224*/	mov al,byte ptr ds:[0x9B5981]
	/*0081D229*/	push 0x98E8CC		/*push cm0102.98E8CC*/
	/*0081D22E*/	cmp al,bl
	/*0081D230*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D235*/	je _0081D25C
	/*0081D237*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D23C*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D242*/	add esp,0x8
	/*0081D245*/	mov dx,ax
	/*0081D248*/	push ebx
	/*0081D249*/	push ebx
	/*0081D24A*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D24F*/	push edx
	/*0081D250*/	push 0x1
	/*0081D252*/	push 0xC
	/*0081D254*/	push eax
	/*0081D255*/	push 0x1
	/*0081D257*/	jmp _0081D330
_0081D25C:
	/*0081D25C*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D261*/	add esp,0x8
	/*0081D264*/	push ebx
	/*0081D265*/	push ebx
	/*0081D266*/	jmp _0081D313
_0081D26B:
	/*0081D26B*/	cmp al,bl
	/*0081D26D*/	push 0x98E8D0		/*push cm0102.98E8D0*/
	/*0081D272*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D277*/	je _0081D2A3
	/*0081D279*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D27E*/	mov dx,word ptr ds:[0xAEBDD4]
	/*0081D285*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D28B*/	add esp,0x8
	/*0081D28E*/	push ebx
	/*0081D28F*/	push 0x39
	/*0081D291*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D296*/	push edx
	/*0081D297*/	push 0x1
	/*0081D299*/	push 0xC
	/*0081D29B*/	push eax
	/*0081D29C*/	push 0x801
	/*0081D2A1*/	jmp _0081D2C4
_0081D2A3:
	/*0081D2A3*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D2A8*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D2AE*/	add esp,0x8
	/*0081D2B1*/	mov cx,ax
	/*0081D2B4*/	push ebx
	/*0081D2B5*/	push 0x39
	/*0081D2B7*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D2BC*/	push ecx
	/*0081D2BD*/	push 0x1
	/*0081D2BF*/	push 0xC
	/*0081D2C1*/	push eax
	/*0081D2C2*/	push 0x1
_0081D2C4:
	/*0081D2C4*/	push ebx
	/*0081D2C5*/	push 0x1
	/*0081D2C7*/	push esi
	/*0081D2C8*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D2CD*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D2D2*/	mov al,byte ptr ds:[0x9B5981]
	/*0081D2D7*/	push 0x98E8CC		/*push cm0102.98E8CC*/
	/*0081D2DC*/	cmp al,bl
	/*0081D2DE*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D2E3*/	je _0081D308
	/*0081D2E5*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D2EA*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D2F0*/	add esp,0x8
	/*0081D2F3*/	mov dx,ax
	/*0081D2F6*/	push ebx
	/*0081D2F7*/	push 0x3A
	/*0081D2F9*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D2FE*/	push edx
	/*0081D2FF*/	push 0x1
	/*0081D301*/	push 0xC
	/*0081D303*/	push eax
	/*0081D304*/	push 0x1
	/*0081D306*/	jmp _0081D330
_0081D308:
	/*0081D308*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D30D*/	add esp,0x8
	/*0081D310*/	push ebx
	/*0081D311*/	push 0x3A
_0081D313:
	/*0081D313*/	mov ax,word ptr ds:[0xAEBDD4]
	/*0081D319*/	mov cx,word ptr ds:[0xAE317E]
	/*0081D320*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D325*/	push eax
	/*0081D326*/	push 0x1
	/*0081D328*/	push 0xC
	/*0081D32A*/	push ecx
	/*0081D32B*/	push 0x801
_0081D330:
	/*0081D330*/	push ebx
	/*0081D331*/	push 0x3
	/*0081D333*/	push esi
	/*0081D334*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D339*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D33E*/	cmp si,bx
	/*0081D341*/	jne _0081D37D
_0081D343:
	/*0081D343*/	movsx eax,word ptr ds:[0xB77C7A]
	/*0081D34A*/	push 0xFFFFFFFF
	/*0081D34C*/	push ebx
	/*0081D34D*/	push 0x2
	/*0081D34F*/	push ebx
	/*0081D350*/	lea edx,dword ptr ss:[esp+0x3C]
	/*0081D354*/	push 0x1
	/*0081D356*/	push edx
	/*0081D357*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081D35A*/	push 0x9
	/*0081D35C*/	push 0xA5
	/*0081D361*/	shl eax,0x8
	/*0081D364*/	push 0x20D
	/*0081D369*/	push 0x91
	/*0081D36E*/	mov ecx,dword ptr ds:[eax+0xB74C4C]
	/*0081D374*/	push 0x6E
	/*0081D376*/	call sub_55FBA0		/*call <cm0102.sub_55FBA0>*/
	/*0081D37B*/	mov esi,eax
_0081D37D:
	/*0081D37D*/	push 0xA803EC		/*push cm0102.A803EC*/
	/*0081D382*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D387*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D38C*/	mov cx,word ptr ds:[0xAE3184]
	/*0081D393*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D39A*/	add esp,0x8
	/*0081D39D*/	push ebx
	/*0081D39E*/	push ebx
	/*0081D39F*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D3A4*/	push ecx
	/*0081D3A5*/	push 0x1
	/*0081D3A7*/	push 0x1
	/*0081D3A9*/	push edx
	/*0081D3AA*/	push 0x1
	/*0081D3AC*/	push ebx
	/*0081D3AD*/	push 0x5
	/*0081D3AF*/	push esi
	/*0081D3B0*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D3B5*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D3BA*/	mov eax,dword ptr ds:[0xDD7118]
	/*0081D3BF*/	cmp eax,ebx
	/*0081D3C1*/	mov al,byte ptr ds:[0x9CC270]
	/*0081D3C6*/	je _0081D49B
	/*0081D3CC*/	cmp al,bl
	/*0081D3CE*/	push 0x98E8D0		/*push cm0102.98E8D0*/
	/*0081D3D3*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D3D8*/	je _0081D403
	/*0081D3DA*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D3DF*/	mov ax,word ptr ds:[0xAEBDD4]
	/*0081D3E5*/	mov cx,word ptr ds:[0xAE317E]
	/*0081D3EC*/	add esp,0x8
	/*0081D3EF*/	push ebx
	/*0081D3F0*/	push ebx
	/*0081D3F1*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D3F6*/	push eax
	/*0081D3F7*/	push 0x1
	/*0081D3F9*/	push 0xC
	/*0081D3FB*/	push ecx
	/*0081D3FC*/	push 0x801
	/*0081D401*/	jmp _0081D423
_0081D403:
	/*0081D403*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D408*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D40E*/	add esp,0x8
	/*0081D411*/	mov dx,ax
	/*0081D414*/	push ebx
	/*0081D415*/	push ebx
	/*0081D416*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D41B*/	push edx
	/*0081D41C*/	push 0x1
	/*0081D41E*/	push 0xC
	/*0081D420*/	push eax
	/*0081D421*/	push 0x1
_0081D423:
	/*0081D423*/	push ebx
	/*0081D424*/	push 0x6
	/*0081D426*/	push esi
	/*0081D427*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D42C*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D431*/	mov al,byte ptr ds:[0x9CC270]
	/*0081D436*/	push 0x98E8CC		/*push cm0102.98E8CC*/
	/*0081D43B*/	cmp al,bl
	/*0081D43D*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D442*/	je _0081D46C
	/*0081D444*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D449*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D44F*/	add esp,0x8
	/*0081D452*/	mov cx,ax
	/*0081D455*/	push ebx
	/*0081D456*/	push ebx
	/*0081D457*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D45C*/	push ecx
	/*0081D45D*/	push 0x1
	/*0081D45F*/	push 0xC
	/*0081D461*/	push eax
	/*0081D462*/	push 0x1
	/*0081D464*/	push ebx
	/*0081D465*/	push 0x7
	/*0081D467*/	jmp _0081D564
_0081D46C:
	/*0081D46C*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D471*/	mov dx,word ptr ds:[0xAEBDD4]
	/*0081D478*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D47E*/	add esp,0x8
	/*0081D481*/	push ebx
	/*0081D482*/	push ebx
	/*0081D483*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D488*/	push edx
	/*0081D489*/	push 0x1
	/*0081D48B*/	push 0xC
	/*0081D48D*/	push eax
	/*0081D48E*/	push 0x801
	/*0081D493*/	push ebx
	/*0081D494*/	push 0x7
	/*0081D496*/	jmp _0081D564
_0081D49B:
	/*0081D49B*/	cmp al,bl
	/*0081D49D*/	push 0x98E8D0		/*push cm0102.98E8D0*/
	/*0081D4A2*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D4A7*/	je _0081D4D4
	/*0081D4A9*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D4AE*/	mov cx,word ptr ds:[0xAEBDD4]
	/*0081D4B5*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D4BC*/	add esp,0x8
	/*0081D4BF*/	push ebx
	/*0081D4C0*/	push 0x3B
	/*0081D4C2*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D4C7*/	push ecx
	/*0081D4C8*/	push 0x1
	/*0081D4CA*/	push 0xC
	/*0081D4CC*/	push edx
	/*0081D4CD*/	push 0x801
	/*0081D4D2*/	jmp _0081D4F5
_0081D4D4:
	/*0081D4D4*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D4D9*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D4DF*/	add esp,0x8
	/*0081D4E2*/	mov cx,ax
	/*0081D4E5*/	push ebx
	/*0081D4E6*/	push 0x3B
	/*0081D4E8*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D4ED*/	push ecx
	/*0081D4EE*/	push 0x1
	/*0081D4F0*/	push 0xC
	/*0081D4F2*/	push eax
	/*0081D4F3*/	push 0x1
_0081D4F5:
	/*0081D4F5*/	push ebx
	/*0081D4F6*/	push 0x6
	/*0081D4F8*/	push esi
	/*0081D4F9*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D4FE*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D503*/	mov al,byte ptr ds:[0x9CC270]
	/*0081D508*/	push 0x98E8CC		/*push cm0102.98E8CC*/
	/*0081D50D*/	cmp al,bl
	/*0081D50F*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D514*/	je _0081D539
	/*0081D516*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D51B*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D521*/	add esp,0x8
	/*0081D524*/	mov dx,ax
	/*0081D527*/	push ebx
	/*0081D528*/	push 0x3C
	/*0081D52A*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D52F*/	push edx
	/*0081D530*/	push 0x1
	/*0081D532*/	push 0xC
	/*0081D534*/	push eax
	/*0081D535*/	push 0x1
	/*0081D537*/	jmp _0081D561
_0081D539:
	/*0081D539*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D53E*/	mov ax,word ptr ds:[0xAEBDD4]
	/*0081D544*/	mov cx,word ptr ds:[0xAE317E]
	/*0081D54B*/	add esp,0x8
	/*0081D54E*/	push ebx
	/*0081D54F*/	push 0x3C
	/*0081D551*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D556*/	push eax
	/*0081D557*/	push 0x1
	/*0081D559*/	push 0xC
	/*0081D55B*/	push ecx
	/*0081D55C*/	push 0x801
_0081D561:
	/*0081D561*/	push ebx
	/*0081D562*/	push 0x8
_0081D564:
	/*0081D564*/	push esi
	/*0081D565*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D56A*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D56F*/	movsx eax,word ptr ds:[0xB77C7A]
	/*0081D576*/	push 0xFFFFFFFF
	/*0081D578*/	push ebx
	/*0081D579*/	push 0x1
	/*0081D57B*/	push ebx
	/*0081D57C*/	push 0x1
	/*0081D57E*/	push ebx
	/*0081D57F*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081D582*/	push 0x2
	/*0081D584*/	push 0xA5
	/*0081D589*/	push 0x30C
	/*0081D58E*/	shl edx,0x8
	/*0081D591*/	push 0x91
	/*0081D596*/	push 0x212
	/*0081D59B*/	mov ecx,dword ptr ds:[edx+0xB74C4C]
	/*0081D5A1*/	call sub_55FBA0		/*call <cm0102.sub_55FBA0>*/
	/*0081D5A6*/	push 0x99B4C8		/*push cm0102.99B4C8*/
	/*0081D5AB*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D5B0*/	mov esi,eax
	/*0081D5B2*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D5B7*/	mov eax,dword ptr ds:[0xDD7118]
	/*0081D5BC*/	add esp,0x8
	/*0081D5BF*/	cmp eax,ebx
	/*0081D5C1*/	je _0081D5DD
	/*0081D5C3*/	mov ax,word ptr ds:[0xAE3184]
	/*0081D5C9*/	mov cx,word ptr ds:[0xAE317E]
	/*0081D5D0*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D5D5*/	push eax
	/*0081D5D6*/	push 0x1
	/*0081D5D8*/	push 0x2C
	/*0081D5DA*/	push ecx
	/*0081D5DB*/	jmp _0081D630
_0081D5DD:
	/*0081D5DD*/	cmp dword ptr ds:[0xAE2D04],0xF
	/*0081D5E4*/	jge _0081D617
	/*0081D5E6*/	cmp edi,0x10
	/*0081D5E9*/	jl _0081D617
	/*0081D5EB*/	mov dx,word ptr ds:[0xAE3184]
	/*0081D5F2*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D5F8*/	push ebx
	/*0081D5F9*/	push 0xA
	/*0081D5FB*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D600*/	push edx
	/*0081D601*/	push 0x1
	/*0081D603*/	push 0xC
	/*0081D605*/	push eax
	/*0081D606*/	push 0x30
	/*0081D608*/	push ebx
	/*0081D609*/	push ebx
	/*0081D60A*/	push esi
	/*0081D60B*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D610*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D615*/	jmp _0081D63F
_0081D617:
	/*0081D617*/	mov cx,word ptr ds:[0xAE3184]
	/*0081D61E*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D625*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D62A*/	push ecx
	/*0081D62B*/	push 0x1
	/*0081D62D*/	push 0x2C
	/*0081D62F*/	push edx
_0081D630:
	/*0081D630*/	push 0x30
	/*0081D632*/	push ebx
	/*0081D633*/	push ebx
	/*0081D634*/	push esi
	/*0081D635*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D63A*/	call sub_804100		/*call <cm0102.sub_804100>*/
_0081D63F:
	/*0081D63F*/	push 0xA803DC		/*push cm0102.A803DC*/
	/*0081D644*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D649*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D64E*/	mov eax,dword ptr ds:[0xDD7118]
	/*0081D653*/	add esp,0x8
	/*0081D656*/	cmp eax,ebx
	/*0081D658*/	je _0081D674
	/*0081D65A*/	mov ax,word ptr ds:[0xAE3184]
	/*0081D660*/	mov cx,word ptr ds:[0xAE317E]
	/*0081D667*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D66C*/	push eax
	/*0081D66D*/	push 0x1
	/*0081D66F*/	push 0x2C
	/*0081D671*/	push ecx
	/*0081D672*/	jmp _0081D6C2
_0081D674:
	/*0081D674*/	cmp dword ptr ds:[0xAE2D00],ebx
	/*0081D67A*/	jle _0081D6A9
	/*0081D67C*/	mov dx,word ptr ds:[0xAE3184]
	/*0081D683*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D689*/	push ebx
	/*0081D68A*/	push 0xB
	/*0081D68C*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D691*/	push edx
	/*0081D692*/	push 0x1
	/*0081D694*/	push 0xC
	/*0081D696*/	push eax
	/*0081D697*/	push 0x30
	/*0081D699*/	push ebx
	/*0081D69A*/	push 0x1
	/*0081D69C*/	push esi
	/*0081D69D*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D6A2*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D6A7*/	jmp _0081D6D2
_0081D6A9:
	/*0081D6A9*/	mov cx,word ptr ds:[0xAE3184]
	/*0081D6B0*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D6B7*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D6BC*/	push ecx
	/*0081D6BD*/	push 0x1
	/*0081D6BF*/	push 0x2C
	/*0081D6C1*/	push edx
_0081D6C2:
	/*0081D6C2*/	push 0x30
	/*0081D6C4*/	push ebx
	/*0081D6C5*/	push 0x1
	/*0081D6C7*/	push esi
	/*0081D6C8*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D6CD*/	call sub_804100		/*call <cm0102.sub_804100>*/
_0081D6D2:
	/*0081D6D2*/	push 0xFFFFFFFF
	/*0081D6D4*/	push ebx
	/*0081D6D5*/	push 0x2
	/*0081D6D7*/	push ebx
	/*0081D6D8*/	lea eax,dword ptr ss:[esp+0x28]
	/*0081D6DC*/	push 0x10
	/*0081D6DE*/	push eax
	/*0081D6DF*/	push 0x7
	/*0081D6E1*/	movsx eax,word ptr ds:[0xB77C7A]
	/*0081D6E8*/	push 0x217
	/*0081D6ED*/	push 0x30C
	/*0081D6F2*/	lea ecx,dword ptr ds:[eax+eax*0x2]
	/*0081D6F5*/	push 0xAA
	/*0081D6FA*/	shl ecx,0x8
	/*0081D6FD*/	push 0x6E
	/*0081D6FF*/	mov ecx,dword ptr ds:[ecx+0xB74C4C]
	/*0081D705*/	call sub_55FBA0		/*call <cm0102.sub_55FBA0>*/
	/*0081D70A*/	push ebx
	/*0081D70B*/	mov esi,eax
	/*0081D70D*/	xor edi,edi
	/*0081D70F*/	call sub_66A0C0		/*call <cm0102.sub_66A0C0>*/						// <--- returns a small table of sorted numbers - (it's the countries in alphabetical order)
	/*0081D714*/	mov edx,eax
	/*0081D716*/	add esp,0x4
	/*0081D719*/	mov dword ptr ss:[esp+0x14],edx
	/*0081D71D*/	xor ecx,ecx
	/*0081D71F*/	mov dword ptr ds:[0xAE2D04],ebx

_0081D725:																					// Loop counts the number of leagues selected and stores in 0xAE2D04
	/*0081D725*/	movsx eax,byte ptr ds:[ecx+edx]
	/*0081D729*/	lea eax,dword ptr ds:[eax+eax*0x8]										// eax *= 9
		
					push ebx
					mov ebx, [nation_table_ptr]
	/*0081D72C*/	mov eax,dword ptr ds:[eax*0x8+ebx]									// B63D60 is your fixed table of playable leagues in 72 byte blocks?
					pop ebx

	/*0081D733*/	cmp eax,ebx
	/*0081D735*/	je _0081D746
	/*0081D737*/	test byte ptr ds:[eax+0x11C],0x2
	/*0081D73E*/	je _0081D746
	/*0081D740*/	inc dword ptr ds:[0xAE2D04]
_0081D746:
	/*0081D746*/	inc ecx
	/*0081D747*/	cmp ecx,dword ptr [TotalNumberOfConsideredNations]										// <----- Number of leagues (normally 0x23 (35))
	/*0081D74A*/	jl _0081D725															// Loop round

	/*0081D74C*/	push ebp																// B74450
	/*0081D74D*/	mov dword ptr ss:[esp+0x14],ebx											// ebx == 0
	/*0081D751*/	mov ecx,ebx

_0081D753:																					// Top of Loop
	/*0081D753*/	mov edx,dword ptr ss:[esp+0x18]											// pointer to table of sorted numbers from sub_66A0C0
	/*0081D757*/	movsx eax,byte ptr ds:[ecx+edx]											// ecx is loop counter
	/*0081D75B*/	lea eax,dword ptr ds:[eax+eax*0x8]										// Multiply eax by 9

					push ebx
					mov ebx, [nation_table_ptr]
	/*0081D75E*/	mov ebp,dword ptr ds:[eax*0x8+ebx]
					pop ebx

	/*0081D765*/	cmp ebp,ebx
	/*0081D767*/	je _0081DB7E															// Always jmps until we had 8 (*9). Nation 8 == Argentina
	/*0081D76D*/	cmp dword ptr ds:[0xDD7118],ebx
	/*0081D773*/	je _0081D9AB
	/*0081D779*/	lea ecx,dword ptr ss:[ebp+0x4]
	/*0081D77C*/	push ecx
	/*0081D77D*/	push 0x987FF0		/*push cm0102.987FF0*/
	/*0081D782*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D787*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*0081D78C*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081D792*/	add esp,0xC
	/*0081D795*/	cmp al,bl
	/*0081D797*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D79C*/	jne _0081D7A8
	/*0081D79E*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D7A5*/	push edx
	/*0081D7A6*/	jmp _0081D7AF
_0081D7A8:
	/*0081D7A8*/	mov ax,word ptr ds:[0xAEBDEC]
	/*0081D7AE*/	push eax
_0081D7AF:
	/*0081D7AF*/	push 0x3
	/*0081D7B1*/	push 0x1
	/*0081D7B3*/	push ebx
	/*0081D7B4*/	push 0x1
	/*0081D7B6*/	push edi
	/*0081D7B7*/	push ebx
	/*0081D7B8*/	push esi
	/*0081D7B9*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D7BE*/	call sub_804100		/*call <cm0102.sub_804100>*/
	/*0081D7C3*/	push 0xA803D0		/*push cm0102.A803D0*/
	/*0081D7C8*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D7CD*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D7D2*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081D7D8*/	add esp,0x8
	/*0081D7DB*/	test al,0x2
	/*0081D7DD*/	je _0081D7F8
	/*0081D7DF*/	mov cx,word ptr ds:[0xAEBDD4]
	/*0081D7E6*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D7EB*/	push ecx
	/*0081D7EC*/	push 0x2
	/*0081D7EE*/	push 0xC
	/*0081D7F0*/	push ebx
	/*0081D7F1*/	push 0x801
	/*0081D7F6*/	jmp _0081D836
_0081D7F8:
	/*0081D7F8*/	test al,0x1
	/*0081D7FA*/	je _0081D823
	/*0081D7FC*/	mov dx,word ptr ds:[0xAE3184]
	/*0081D803*/	push ebp
	/*0081D804*/	push 0xD
	/*0081D806*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D80B*/	push edx
	/*0081D80C*/	push 0x2
	/*0081D80E*/	push 0xC
	/*0081D810*/	push ebx
	/*0081D811*/	push 0x1
	/*0081D813*/	push edi
	/*0081D814*/	push 0x2
	/*0081D816*/	push esi
	/*0081D817*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D81C*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D821*/	jmp _0081D844
_0081D823:
	/*0081D823*/	mov ax,word ptr ds:[0xAE317E]
	/*0081D829*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D82E*/	push eax
	/*0081D82F*/	push 0x2
	/*0081D831*/	push 0xC
	/*0081D833*/	push ebx
	/*0081D834*/	push 0x1
_0081D836:
	/*0081D836*/	push edi
	/*0081D837*/	push 0x2
	/*0081D839*/	push esi
	/*0081D83A*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D83F*/	call sub_804100		/*call <cm0102.sub_804100>*/
_0081D844:
	/*0081D844*/	push 0xA803C4		/*push cm0102.A803C4*/
	/*0081D849*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D84E*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081D853*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081D859*/	add esp,0x8
	/*0081D85C*/	test al,0x1
	/*0081D85E*/	mov byte ptr ss:[esp+0x13],al
	/*0081D862*/	je _0081D880
	/*0081D864*/	mov cx,word ptr ds:[0xAEBDD4]
	/*0081D86B*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D870*/	push ecx
	/*0081D871*/	push 0x2
	/*0081D873*/	push 0xC
	/*0081D875*/	push ebx
	/*0081D876*/	push 0x801
	/*0081D87B*/	jmp _0081D904
_0081D880:
	/*0081D880*/	cmp dword ptr ds:[0xAE2D04],0x1
	/*0081D887*/	je _0081D8F0
	/*0081D889*/	mov edx,dword ptr ds:[0xAE23BC]
	/*0081D88F*/	xor ecx,ecx
_0081D891:
	/*0081D891*/	mov eax,dword ptr ds:[0xAE2364]
	/*0081D896*/	movsx ebx,cx
	/*0081D899*/	sub eax,ebx
	/*0081D89B*/	dec eax
	/*0081D89C*/	lea ebx,dword ptr ds:[eax+eax*0x4]
	/*0081D89F*/	lea eax,dword ptr ds:[eax+ebx*0x2]
	/*0081D8A2*/	xor ebx,ebx
	/*0081D8A4*/	lea eax,dword ptr ds:[eax+eax*0x4]
	/*0081D8A7*/	cmp byte ptr ds:[edx+eax*0x2+0x5F],bl
	/*0081D8AB*/	lea eax,dword ptr ds:[edx+eax*0x2]
	/*0081D8AE*/	je _0081D8BC
	/*0081D8B0*/	mov eax,dword ptr ds:[eax+0x39]
	/*0081D8B3*/	cmp eax,ebx
	/*0081D8B5*/	je _0081D8BC
	/*0081D8B7*/	cmp dword ptr ds:[eax+0x53],ebp
	/*0081D8BA*/	je _0081D8F0
_0081D8BC:
	/*0081D8BC*/	inc ecx
	/*0081D8BD*/	cmp cx,0x10
	/*0081D8C1*/	jl _0081D891
	/*0081D8C3*/	cmp byte ptr ss:[esp+0x13],bl
	/*0081D8C7*/	je _0081D8F0
	/*0081D8C9*/	mov cx,word ptr ds:[0xAE3184]
	/*0081D8D0*/	push ebp
	/*0081D8D1*/	push 0xE
	/*0081D8D3*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D8D8*/	push ecx
	/*0081D8D9*/	push 0x2
	/*0081D8DB*/	push 0xC
	/*0081D8DD*/	push ebx
	/*0081D8DE*/	push 0x1
	/*0081D8E0*/	push edi
	/*0081D8E1*/	push 0x4
	/*0081D8E3*/	push esi
	/*0081D8E4*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D8E9*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081D8EE*/	jmp _0081D912
_0081D8F0:
	/*0081D8F0*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D8F7*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D8FC*/	push edx
	/*0081D8FD*/	push 0x2
	/*0081D8FF*/	push 0xC
	/*0081D901*/	push ebx
	/*0081D902*/	push 0x1
_0081D904:
	/*0081D904*/	push edi
	/*0081D905*/	push 0x4
	/*0081D907*/	push esi
	/*0081D908*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D90D*/	call sub_804100		/*call <cm0102.sub_804100>*/
_0081D912:
	/*0081D912*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081D918*/	push 0x7D0
	/*0081D91D*/	cmp al,bl
	/*0081D91F*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D924*/	push ebp
	/*0081D925*/	je _0081D98C
	/*0081D927*/	call sub_669F50		/*call <cm0102.sub_669F50>*/
	/*0081D92C*/	add esp,0xC
	/*0081D92F*/	test eax,eax
	/*0081D931*/	je _0081DB79
	/*0081D937*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081D93D*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D942*/	test al,0x4
	/*0081D944*/	je _0081D96A
	/*0081D946*/	mov ax,word ptr ds:[0xAEBDD4]
	/*0081D94C*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D951*/	push eax
	/*0081D952*/	push 0x2
	/*0081D954*/	push 0xC
	/*0081D956*/	push ebx
	/*0081D957*/	push 0x801
	/*0081D95C*/	push edi
	/*0081D95D*/	push 0x6
	/*0081D95F*/	push esi
	/*0081D960*/	call sub_804100		/*call <cm0102.sub_804100>*/
	/*0081D965*/	jmp _0081DB79
_0081D96A:
	/*0081D96A*/	mov cx,word ptr ds:[0xAE317E]
	/*0081D971*/	push ecx
_0081D972:
	/*0081D972*/	push 0x2
	/*0081D974*/	push 0xC
	/*0081D976*/	push ebx
	/*0081D977*/	push 0x1
	/*0081D979*/	push edi
	/*0081D97A*/	push 0x6
	/*0081D97C*/	push esi
	/*0081D97D*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D982*/	call sub_804100		/*call <cm0102.sub_804100>*/
	/*0081D987*/	jmp _0081DB79
_0081D98C:
	/*0081D98C*/	call sub_669F50		/*call <cm0102.sub_669F50>*/
	/*0081D991*/	add esp,0xC
	/*0081D994*/	test eax,eax
	/*0081D996*/	je _0081DB79
	/*0081D99C*/	mov dx,word ptr ds:[0xAE317E]
	/*0081D9A3*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D9A8*/	push edx
	/*0081D9A9*/	jmp _0081D972
_0081D9AB:
	/*0081D9AB*/	lea eax,dword ptr ss:[ebp+0x4]
	/*0081D9AE*/	push eax
	/*0081D9AF*/	push 0x987FF0		/*push cm0102.987FF0*/
	/*0081D9B4*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D9B9*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*0081D9BE*/	mov ecx,dword ptr ss:[esp+0x20]
	/*0081D9C2*/	mov edx,dword ptr ss:[esp+0x24]
	/*0081D9C6*/	add esp,0xC
	/*0081D9C9*/	movsx eax,byte ptr ds:[ecx+edx]
	/*0081D9CD*/	lea eax,dword ptr ds:[eax+eax*0x8]
					push ecx
					mov ecx, [nation_table_ptr]
					add ecx, 8
	/*0081D9D0*/	cmp dword ptr ds:[eax*0x8+ecx],ebx				// 0081D9D0 | 391CC5 683DB600 | cmp dword ptr ds:[eax*8+B63D68],ebx                              |
					pop ecx
	/*0081D9D7*/	jne _0081D9FC
	/*0081D9D9*/	mov cx,word ptr ds:[0xAE317E]
	/*0081D9E0*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081D9E5*/	push ecx
	/*0081D9E6*/	push 0x3
	/*0081D9E8*/	push 0x1
	/*0081D9EA*/	push ebx
	/*0081D9EB*/	push 0x1
	/*0081D9ED*/	push edi
	/*0081D9EE*/	push ebx
	/*0081D9EF*/	push esi
	/*0081D9F0*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081D9F5*/	call sub_804100		/*call <cm0102.sub_804100>*/
	/*0081D9FA*/	jmp _0081DA33
_0081D9FC:
	/*0081D9FC*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081DA02*/	push ebp
	/*0081DA03*/	cmp al,bl
	/*0081DA05*/	push 0xC
	/*0081DA07*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DA0C*/	je _0081DA18
	/*0081DA0E*/	mov dx,word ptr ds:[0xAEBDEC]
	/*0081DA15*/	push edx
	/*0081DA16*/	jmp _0081DA1F
_0081DA18:
	/*0081DA18*/	mov ax,word ptr ds:[0xAE3184]
	/*0081DA1E*/	push eax
_0081DA1F:
	/*0081DA1F*/	push 0x3
	/*0081DA21*/	push 0x1
	/*0081DA23*/	push ebx
	/*0081DA24*/	push 0x1
	/*0081DA26*/	push edi
	/*0081DA27*/	push ebx
	/*0081DA28*/	push esi
	/*0081DA29*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DA2E*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
_0081DA33:
	/*0081DA33*/	mov ecx,dword ptr ss:[esp+0x14]
	/*0081DA37*/	mov edx,dword ptr ss:[esp+0x18]
	/*0081DA3B*/	movsx eax,byte ptr ds:[ecx+edx]
	/*0081DA3F*/	lea eax,dword ptr ds:[eax+eax*0x8]
					push ecx
					mov ecx, [nation_table_ptr]
					add ecx, 8
	/*0081DA42*/	cmp dword ptr ds:[eax*0x8+ecx],ebx
					pop ecx
	/*0081DA49*/	je _0081DB79
	/*0081DA4F*/	push 0xA803D0		/*push cm0102.A803D0*/
	/*0081DA54*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DA59*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081DA5E*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081DA64*/	add esp,0x8
	/*0081DA67*/	test al,0x2
	/*0081DA69*/	push ebp
	/*0081DA6A*/	push 0xD
	/*0081DA6C*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DA71*/	je _0081DA87
	/*0081DA73*/	mov cx,word ptr ds:[0xAEBDD4]
	/*0081DA7A*/	push ecx
	/*0081DA7B*/	push 0x2
	/*0081DA7D*/	push 0xC
	/*0081DA7F*/	push ebx
	/*0081DA80*/	push 0x801
	/*0081DA85*/	jmp _0081DA96
_0081DA87:
	/*0081DA87*/	mov dx,word ptr ds:[0xAE317E]
	/*0081DA8E*/	push edx
	/*0081DA8F*/	push 0x2
	/*0081DA91*/	push 0xC
	/*0081DA93*/	push ebx
	/*0081DA94*/	push 0x1
_0081DA96:
	/*0081DA96*/	push edi
	/*0081DA97*/	push 0x2
	/*0081DA99*/	push esi
	/*0081DA9A*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DA9F*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081DAA4*/	push 0xA803C4		/*push cm0102.A803C4*/
	/*0081DAA9*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DAAE*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081DAB3*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081DAB9*/	add esp,0x8
	/*0081DABC*/	test al,0x1
	/*0081DABE*/	push ebp
	/*0081DABF*/	push 0xE
	/*0081DAC1*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DAC6*/	je _0081DADB
	/*0081DAC8*/	mov ax,word ptr ds:[0xAEBDD4]
	/*0081DACE*/	push eax
	/*0081DACF*/	push 0x2
	/*0081DAD1*/	push 0xC
	/*0081DAD3*/	push ebx
	/*0081DAD4*/	push 0x801
	/*0081DAD9*/	jmp _0081DAEA
_0081DADB:
	/*0081DADB*/	mov cx,word ptr ds:[0xAE317E]
	/*0081DAE2*/	push ecx
	/*0081DAE3*/	push 0x2
	/*0081DAE5*/	push 0xC
	/*0081DAE7*/	push ebx
	/*0081DAE8*/	push 0x1
_0081DAEA:
	/*0081DAEA*/	push edi
	/*0081DAEB*/	push 0x4
	/*0081DAED*/	push esi
	/*0081DAEE*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DAF3*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
	/*0081DAF8*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081DAFE*/	push 0x7D0
	/*0081DB03*/	cmp al,bl
	/*0081DB05*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DB0A*/	push ebp
	/*0081DB0B*/	je _0081DB48
	/*0081DB0D*/	call sub_669F50		/*call <cm0102.sub_669F50>*/
	/*0081DB12*/	add esp,0xC
	/*0081DB15*/	test eax,eax
	/*0081DB17*/	je _0081DB79
	/*0081DB19*/	mov al,byte ptr ss:[ebp+0x11C]
	/*0081DB1F*/	push ebp
	/*0081DB20*/	test al,0x4
	/*0081DB22*/	push 0x38
	/*0081DB24*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DB29*/	je _0081DB3F
	/*0081DB2B*/	mov dx,word ptr ds:[0xAEBDD4]
	/*0081DB32*/	push edx
	/*0081DB33*/	push 0x2
	/*0081DB35*/	push 0xC
	/*0081DB37*/	push ebx
	/*0081DB38*/	push 0x801
	/*0081DB3D*/	jmp _0081DB6B
_0081DB3F:
	/*0081DB3F*/	mov ax,word ptr ds:[0xAE317E]
	/*0081DB45*/	push eax
	/*0081DB46*/	jmp _0081DB64
_0081DB48:
	/*0081DB48*/	call sub_669F50		/*call <cm0102.sub_669F50>*/
	/*0081DB4D*/	add esp,0xC
	/*0081DB50*/	test eax,eax
	/*0081DB52*/	je _0081DB79
	/*0081DB54*/	mov cx,word ptr ds:[0xAE317E]
	/*0081DB5B*/	push ebp
	/*0081DB5C*/	push 0x38
	/*0081DB5E*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081DB63*/	push ecx
_0081DB64:
	/*0081DB64*/	push 0x2
	/*0081DB66*/	push 0xC
	/*0081DB68*/	push ebx
	/*0081DB69*/	push 0x1
_0081DB6B:
	/*0081DB6B*/	push edi
	/*0081DB6C*/	push 0x6
	/*0081DB6E*/	push esi
	/*0081DB6F*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DB74*/	call sub_8040A0		/*call <cm0102.sub_8040A0>*/
_0081DB79:
	/*0081DB79*/	mov ecx,dword ptr ss:[esp+0x14]
	/*0081DB7D*/	inc edi
_0081DB7E:
	/*0081DB7E*/	inc ecx
	/*0081DB7F*/	cmp ecx,dword ptr [TotalNumberOfConsideredNations]							// <----- Number of Leagues to show (normally 0x23 (35))
	/*0081DB82*/	mov dword ptr ss:[esp+0x14],ecx
	/*0081DB86*/	jl _0081D753												// <------ Jump back to top of loop

	/*0081DB8C*/	mov eax,dword ptr ds:[0xDD7118]
	/*0081DB91*/	pop ebp
	/*0081DB92*/	cmp eax,ebx
	/*0081DB94*/	je _0081DBA8
	/*0081DB96*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DB9B*/	call sub_7FEBB0		/*call <cm0102.sub_7FEBB0>*/
	/*0081DBA0*/	neg eax
	/*0081DBA2*/	sbb eax,eax
	/*0081DBA4*/	inc eax
	/*0081DBA5*/	push eax
	/*0081DBA6*/	jmp _0081DBB6
_0081DBA8:
	/*0081DBA8*/	mov ecx,dword ptr ds:[0xAE2D04]
	/*0081DBAE*/	xor edx,edx
	/*0081DBB0*/	cmp ecx,ebx
	/*0081DBB2*/	setne dl
	/*0081DBB5*/	push edx
_0081DBB6:
	/*0081DBB6*/	push ebx
	/*0081DBB7*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DBBC*/	call sub_7FEC60		/*call <cm0102.sub_7FEC60>*/
	/*0081DBC1*/	neg eax
	/*0081DBC3*/	sbb eax,eax
	/*0081DBC5*/	inc eax
	/*0081DBC6*/	push eax
	/*0081DBC7*/	call sub_5EDCC0		/*call <cm0102.sub_5EDCC0>*/
	/*0081DBCC*/	add esp,0x8
	/*0081DBCF*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DBD4*/	push ebx
	/*0081DBD5*/	call sub_7FF010		/*call <cm0102.sub_7FF010>*/
	/*0081DBDA*/	cmp si,0xFFFF
	/*0081DBDE*/	je _0081DC0D
	/*0081DBE0*/	push eax
	/*0081DBE1*/	movsx eax,word ptr ds:[0xB77C7A]
	/*0081DBE8*/	lea ecx,dword ptr ds:[eax+eax*0x2]
	/*0081DBEB*/	movsx eax,si
	/*0081DBEE*/	shl ecx,0x8
	/*0081DBF1*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081DBF4*/	shl edx,0x6
	/*0081DBF7*/	sub edx,eax
	/*0081DBF9*/	shl edx,0x4
	/*0081DBFC*/	add edx,eax
	/*0081DBFE*/	mov eax,dword ptr ds:[ecx+0xB74C4C]
	/*0081DC04*/	lea ecx,dword ptr ds:[eax+edx+0x4]
	/*0081DC08*/	call sub_403320		/*call <cm0102.sub_403320>*/
_0081DC0D:
	/*0081DC0D*/	movsx ecx,si
	/*0081DC10*/	push ebx
	/*0081DC11*/	push ecx
	/*0081DC12*/	push 0x1
	/*0081DC14*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DC19*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
	/*0081DC1E*/	pop edi
	/*0081DC1F*/	pop esi
	/*0081DC20*/	pop ebx
	/*0081DC21*/	add esp,0x2C
	/*0081DC24*/	ret
	}
}

void __declspec(naked) sub_66A0C0()
{
	__asm
	{
	/*0066A0C0*/	xor al,al
	/*0066A0C2*/	mov ecx,[our_sorted_idx_B63D38]		/*mov ecx,cm0102.B63D38*/
_0066A0C7:
	/*0066A0C7*/	mov byte ptr ds:[ecx],al
	/*0066A0C9*/	inc al
	/*0066A0CB*/	inc ecx
					push ebx
					mov ebx, [TotalNumberOfConsideredNations]
	/*0066A0CC*/	cmp al,bl
					pop ebx
	/*0066A0CE*/	jl _0066A0C7
	/*0066A0D0*/	mov eax,dword ptr ss:[esp+0x4]
	/*0066A0D4*/	push OFFSET sub_66A100		/*push <cm0102.sub_66A100>*/
	/*0066A0D9*/	push 0x1
	/*0066A0DB*/	push [TotalNumberOfConsideredNations]
	/*0066A0DD*/	push [our_sorted_idx_B63D38]		/*push cm0102.B63D38*/
	/*0066A0E2*/	mov dword ptr ds:[our_B63D5C],eax
	/*0066A0E7*/	call sub_945333		/*call <cm0102.sub_945333>*/
	/*0066A0EC*/	add esp,0x10
	/*0066A0EF*/	mov eax,[our_sorted_idx_B63D38]		/*mov eax,cm0102.B63D38*/
	/*0066A0F4*/	ret
	}
}

void __declspec(naked) sub_66A100()
{
	__asm
	{
	/*0066A100*/	mov ecx,dword ptr ss:[esp+0x4]
	/*0066A104*/	push ebx
	/*0066A105*/	push esi
	/*0066A106*/	push edi
	/*0066A107*/	test ecx,ecx
	/*0066A109*/	jne _0066A114
	/*0066A10B*/	pop edi
	/*0066A10C*/	pop esi
	/*0066A10D*/	mov eax,0x1
	/*0066A112*/	pop ebx
	/*0066A113*/	ret
_0066A114:
	/*0066A114*/	mov eax,dword ptr ss:[esp+0x14]
	/*0066A118*/	test eax,eax
	/*0066A11A*/	jne _0066A123
	/*0066A11C*/	pop edi
	/*0066A11D*/	pop esi
	/*0066A11E*/	or eax,0xFFFFFFFF
	/*0066A121*/	pop ebx
	/*0066A122*/	ret
_0066A123:
	/*0066A123*/	mov bl,byte ptr ds:[ecx]
	/*0066A125*/	mov dl,byte ptr ds:[eax]
	/*0066A127*/	movsx eax,bl
	/*0066A12A*/	movsx ecx,dl
	/*0066A12D*/	lea eax,dword ptr ds:[eax+eax*0x8]
	/*0066A130*/	shl eax,0x3
	/*0066A133*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]

					push ecx
					mov ecx, [nation_table_ptr]
					add ecx, 4
	/*0066A136*/	mov esi,dword ptr ds:[eax+ecx]
					sub ecx, 4
	/*0066A13C*/	mov eax,dword ptr ds:[eax+ecx]
					pop ecx

	/*0066A142*/	shl ecx,0x3
	/*0066A145*/	test eax,eax

					push ebx
					mov ebx, [nation_table_ptr]
					add ebx, 4
	/*0066A147*/	mov edi,dword ptr ds:[ecx+ebx]
					sub ebx, 4
	/*0066A14D*/	mov ecx,dword ptr ds:[ecx+ebx]
					pop ebx

	/*0066A153*/	jne _0066A168
	/*0066A155*/	test esi,esi
	/*0066A157*/	jne _0066A168
	/*0066A159*/	test ecx,ecx
	/*0066A15B*/	jne _0066A161
	/*0066A15D*/	test edi,edi
	/*0066A15F*/	je _0066A191
_0066A161:
	/*0066A161*/	pop edi
	/*0066A162*/	pop esi
	/*0066A163*/	or eax,0xFFFFFFFF
	/*0066A166*/	pop ebx
	/*0066A167*/	ret
_0066A168:
	/*0066A168*/	test ecx,ecx
	/*0066A16A*/	jne _0066A179
	/*0066A16C*/	test edi,edi
	/*0066A16E*/	jne _0066A179
	/*0066A170*/	pop edi
	/*0066A171*/	pop esi
	/*0066A172*/	mov eax,0x1
	/*0066A177*/	pop ebx
	/*0066A178*/	ret
_0066A179:
	/*0066A179*/	test eax,eax
	/*0066A17B*/	jne _0066A1FB
	/*0066A17D*/	test esi,esi
	/*0066A17F*/	jne _0066A1FF
	/*0066A181*/	test ecx,ecx
	/*0066A183*/	jne _0066A20E
	/*0066A189*/	test edi,edi
	/*0066A18B*/	jne _0066A212
_0066A191:
	/*0066A191*/	test bl,bl
	/*0066A193*/	jne _0066A1B1
	/*0066A195*/	cmp dl,0x1
	/*0066A198*/	jne _0066A1A1
	/*0066A19A*/	pop edi
	/*0066A19B*/	pop esi
	/*0066A19C*/	or eax,0xFFFFFFFF
	/*0066A19F*/	pop ebx
	/*0066A1A0*/	ret
_0066A1A1:
	/*0066A1A1*/	cmp dl,0x2
	/*0066A1A4*/	jne _0066A275
	/*0066A1AA*/	pop edi
	/*0066A1AB*/	pop esi
	/*0066A1AC*/	or eax,0xFFFFFFFF
	/*0066A1AF*/	pop ebx
	/*0066A1B0*/	ret
_0066A1B1:
	/*0066A1B1*/	cmp bl,0x1
	/*0066A1B4*/	jne _0066A1D3
	/*0066A1B6*/	cmp dl,0x2
	/*0066A1B9*/	jne _0066A1C2
	/*0066A1BB*/	pop edi
	/*0066A1BC*/	pop esi
	/*0066A1BD*/	or eax,0xFFFFFFFF
	/*0066A1C0*/	pop ebx
	/*0066A1C1*/	ret
_0066A1C2:
	/*0066A1C2*/	test dl,dl
	/*0066A1C4*/	jne _0066A275
	/*0066A1CA*/	pop edi
	/*0066A1CB*/	pop esi
	/*0066A1CC*/	mov eax,0x1
	/*0066A1D1*/	pop ebx
	/*0066A1D2*/	ret
_0066A1D3:
	/*0066A1D3*/	cmp bl,0x2
	/*0066A1D6*/	jne _0066A275
	/*0066A1DC*/	test dl,dl
	/*0066A1DE*/	jne _0066A1E9
	/*0066A1E0*/	pop edi
	/*0066A1E1*/	pop esi
	/*0066A1E2*/	mov eax,0x1
	/*0066A1E7*/	pop ebx
	/*0066A1E8*/	ret
_0066A1E9:
	/*0066A1E9*/	cmp dl,0x1
	/*0066A1EC*/	jne _0066A275
	/*0066A1F2*/	pop edi
	/*0066A1F3*/	pop esi
	/*0066A1F4*/	mov eax,0x1
	/*0066A1F9*/	pop ebx
	/*0066A1FA*/	ret
_0066A1FB:
	/*0066A1FB*/	test esi,esi
	/*0066A1FD*/	je _0066A20E
_0066A1FF:
	/*0066A1FF*/	test edi,edi
	/*0066A201*/	jne _0066A20A
	/*0066A203*/	pop edi
	/*0066A204*/	pop esi
	/*0066A205*/	or eax,0xFFFFFFFF
	/*0066A208*/	pop ebx
	/*0066A209*/	ret
_0066A20A:
	/*0066A20A*/	test esi,esi
	/*0066A20C*/	jne _0066A21B
_0066A20E:
	/*0066A20E*/	test edi,edi
	/*0066A210*/	je _0066A233
_0066A212:
	/*0066A212*/	pop edi
	/*0066A213*/	pop esi
	/*0066A214*/	mov eax,0x1
	/*0066A219*/	pop ebx
	/*0066A21A*/	ret
_0066A21B:
	/*0066A21B*/	push 0x0
	/*0066A21D*/	add edi,0x4
	/*0066A220*/	push 0x1
	/*0066A222*/	add esi,0x4
	/*0066A225*/	push edi
	/*0066A226*/	push esi
	/*0066A227*/	call sub_90C1D0		/*call <cm0102.sub_90C1D0>*/
	/*0066A22C*/	add esp,0x10
	/*0066A22F*/	pop edi
	/*0066A230*/	pop esi
	/*0066A231*/	pop ebx
	/*0066A232*/	ret
_0066A233:
	/*0066A233*/	test eax,eax
	/*0066A235*/	je _0066A275
	/*0066A237*/	test ecx,ecx
	/*0066A239*/	je _0066A275
	/*0066A23B*/	mov edx,dword ptr ds:[our_B63D5C]
	/*0066A241*/	test edx,edx
	/*0066A243*/	je _0066A25D
	/*0066A245*/	add ecx,0x38		// 56
	/*0066A248*/	push 0x0
	/*0066A24A*/	add eax,0x38
	/*0066A24D*/	push 0x1
	/*0066A24F*/	push ecx
	/*0066A250*/	push eax
	/*0066A251*/	call sub_90C1D0		/*call <cm0102.sub_90C1D0>*/
	/*0066A256*/	add esp,0x10
	/*0066A259*/	pop edi
	/*0066A25A*/	pop esi
	/*0066A25B*/	pop ebx
	/*0066A25C*/	ret
_0066A25D:
	/*0066A25D*/	add ecx,0x4
	/*0066A260*/	push 0x0
	/*0066A262*/	add eax,0x4
	/*0066A265*/	push 0x1
	/*0066A267*/	push ecx
	/*0066A268*/	push eax
	/*0066A269*/	call sub_90C1D0		/*call <cm0102.sub_90C1D0>*/
	/*0066A26E*/	add esp,0x10
	/*0066A271*/	pop edi
	/*0066A272*/	pop esi
	/*0066A273*/	pop ebx
	/*0066A274*/	ret
_0066A275:
	/*0066A275*/	pop edi
	/*0066A276*/	pop esi
	/*0066A277*/	xor eax,eax
	/*0066A279*/	pop ebx
	/*0066A27A*/	ret
	}
}

static int(*sub_7643D0)() = (int(*)())(0x7643D0);
static int(*sub_820D40)() = (int(*)())(0x820D40);
static int(*sub_5A8F60)() = (int(*)())(0x5A8F60);
static int(*sub_5CC7D0)() = (int(*)())(0x5CC7D0);
static int(*sub_7615D0)() = (int(*)())(0x7615D0);
static int(*sub_8388E0)() = (int(*)())(0x8388E0);
static int(*sub_944CFF)() = (int(*)())(0x944CFF);
static int(*sub_828110)() = (int(*)())(0x828110);
static int(*sub_803320)() = (int(*)())(0x803320);
static int(*sub_945A60)() = (int(*)())(0x945A60);
static int(*sub_7FE600)() = (int(*)())(0x7FE600);
static int(*sub_945934)() = (int(*)())(0x945934);

void __declspec(naked) sub_81DC30_UIHandler()
{
	__asm
	{
	/*0081DC30*/	mov eax,dword ptr ds:[0xAE23A8]
	/*0081DC35*/	sub esp,0x250
	/*0081DC3B*/	push ebx
	/*0081DC3C*/	push ebp
	/*0081DC3D*/	xor ebp,ebp
	/*0081DC3F*/	push esi
	/*0081DC40*/	cmp eax,ebp
	/*0081DC42*/	push edi
	/*0081DC43*/	jne _0081DC55
	/*0081DC45*/	pop edi
	/*0081DC46*/	pop esi
	/*0081DC47*/	pop ebp
	/*0081DC48*/	mov eax,0xFFFFFFFE
	/*0081DC4D*/	pop ebx
	/*0081DC4E*/	add esp,0x250
	/*0081DC54*/	ret
_0081DC55:
	/*0081DC55*/	mov esi,dword ptr ss:[esp+0x264]
	/*0081DC5C*/	cmp si,0xFFFF
	/*0081DC60*/	je _0081DCB2
	/*0081DC62*/	push ebp
	/*0081DC63*/	push 0x1
	/*0081DC65*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DC6A*/	call sub_7FF010		/*call <cm0102.sub_7FF010>*/
	/*0081DC6F*/	push eax
	/*0081DC70*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DC75*/	call sub_803320		/*call <cm0102.sub_803320>*/
	/*0081DC7A*/	push eax
	/*0081DC7B*/	push ebp
	/*0081DC7C*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081DC81*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
	/*0081DC86*/	mov cx,word ptr ds:[0xB77C7A]
	/*0081DC8D*/	movsx eax,cx
	/*0081DC90*/	movsx edx,si
	/*0081DC93*/	lea edi,dword ptr ds:[eax+eax*0x2]
	/*0081DC96*/	mov eax,edx
	/*0081DC98*/	shl eax,0x5
	/*0081DC9B*/	shl edi,0x8
	/*0081DC9E*/	add eax,edx
	/*0081DCA0*/	mov edx,dword ptr ds:[edi+0xB74C4C]
	/*0081DCA6*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081DCA9*/	mov eax,dword ptr ds:[edx+eax*0x4+0xBA966]
	/*0081DCB0*/	jmp _0081DCBB
_0081DCB2:
	/*0081DCB2*/	mov cx,word ptr ds:[0xB77C7A]
	/*0081DCB9*/	xor eax,eax
_0081DCBB:
	/*0081DCBB*/	mov di,word ptr ds:[0xDD6BDE]
	/*0081DCC2*/	cmp ax,bp
	/*0081DCC5*/	jne _0081DCCA
	/*0081DCC7*/	mov ax,di
_0081DCCA:
	/*0081DCCA*/	cmp ax,0xA
	/*0081DCCE*/	jne _0081DD78
					
					mov edx, [nation_table_ptr]
					add edx, 8

	/*0081DCD4*/	// mov edx,0xB63D68		/*mov edx,<cm0102.&sub_830620>*/
	/*0081DCD9*/	mov bl,0x2
	/*0081DCDB*/	jmp _0081DCDF
_0081DCDD:
	/*0081DCDD*/	xor ebp,ebp
_0081DCDF:
	/*0081DCDF*/	mov eax,dword ptr ds:[edx-0x8]
	/*0081DCE2*/	cmp eax,ebp
	/*0081DCE4*/	je _0081DD59
	/*0081DCE6*/	cmp dword ptr ds:[edx],ebp
	/*0081DCE8*/	je _0081DD59
	/*0081DCEA*/	mov cl,byte ptr ds:[eax+0x11C]
	/*0081DCF0*/	test cl,cl
	/*0081DCF2*/	jne _0081DD28
	/*0081DCF4*/	mov edi,dword ptr ds:[0xAE2D00]
	/*0081DCFA*/	mov esi,dword ptr ds:[0xAE2D04]
	/*0081DD00*/	inc edi
	/*0081DD01*/	inc esi
	/*0081DD02*/	mov dword ptr ds:[0xAE2D00],edi
	/*0081DD08*/	mov dword ptr ds:[0xAE2D04],esi
	/*0081DD0E*/	mov cl,byte ptr ds:[eax+0x11C]
	/*0081DD14*/	or cl,bl
	/*0081DD16*/	mov byte ptr ds:[eax+0x11C],cl
	/*0081DD1C*/	mov ecx,dword ptr ds:[0xAE2D08]
	/*0081DD22*/	cmp ecx,ebp
	/*0081DD24*/	jne _0081DD59
	/*0081DD26*/	jmp _0081DD54
_0081DD28:
	/*0081DD28*/	test cl,0x1
	/*0081DD2B*/	je _0081DD59
	/*0081DD2D*/	mov ebp,dword ptr ds:[0xAE2D04]
	/*0081DD33*/	inc ebp
	/*0081DD34*/	mov dword ptr ds:[0xAE2D04],ebp
	/*0081DD3A*/	mov cl,byte ptr ds:[eax+0x11C]
	/*0081DD40*/	dec cl
	/*0081DD42*/	or cl,bl
	/*0081DD44*/	mov byte ptr ds:[eax+0x11C],cl
	/*0081DD4A*/	mov ecx,dword ptr ds:[0xAE2D08]
	/*0081DD50*/	test ecx,ecx
	/*0081DD52*/	jne _0081DD59
_0081DD54:
	/*0081DD54*/	mov dword ptr ds:[0xAE2D08],eax
_0081DD59:

	/*0081DD59*/	add edx,0x48
					mov ebp, [nation_table_ptr]
					add ebp, 8
					mov eax, [TotalNumberOfConsideredNations]
					imul eax, 72
					add ebp, eax
					cmp edx, ebp

	/*0081DD5C*/	//cmp edx,0xB64740		/*cmp edx,cm0102.B64740*/	// end of the list
	/*0081DD62*/	jl _0081DCDD
	/*0081DD68*/	pop edi
	/*0081DD69*/	pop esi
	/*0081DD6A*/	pop ebp
	/*0081DD6B*/	mov eax,0xFFFFFFF5
	/*0081DD70*/	pop ebx
	/*0081DD71*/	add esp,0x250
	/*0081DD77*/	ret
_0081DD78:
	/*0081DD78*/	cmp si,0xFFFF
	/*0081DD7C*/	je _0081DDA3
	/*0081DD7E*/	movsx eax,cx
	/*0081DD81*/	movsx edx,si
	/*0081DD84*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081DD87*/	mov eax,edx
	/*0081DD89*/	shl eax,0x5
	/*0081DD8C*/	shl ebx,0x8
	/*0081DD8F*/	add eax,edx
	/*0081DD91*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081DD94*/	mov eax,dword ptr ds:[ebx+0xB74C4C]
	/*0081DD9A*/	mov eax,dword ptr ds:[eax+edx*0x4+0xBA966]
	/*0081DDA1*/	jmp _0081DDA5
_0081DDA3:
	/*0081DDA3*/	xor eax,eax
_0081DDA5:
	/*0081DDA5*/	cmp ax,bp
	/*0081DDA8*/	jne _0081DDAD
	/*0081DDAA*/	mov ax,di
_0081DDAD:
	/*0081DDAD*/	cmp ax,0x39
	/*0081DDB1*/	jne _0081DDCA
	/*0081DDB3*/	pop edi
	/*0081DDB4*/	pop esi
	/*0081DDB5*/	pop ebp
	/*0081DDB6*/	mov byte ptr ds:[0x9B5981],0x1
	/*0081DDBD*/	mov eax,0xFFFFFFF5
	/*0081DDC2*/	pop ebx
	/*0081DDC3*/	add esp,0x250
	/*0081DDC9*/	ret
_0081DDCA:
	/*0081DDCA*/	cmp si,0xFFFF
	/*0081DDCE*/	je _0081DDF5
	/*0081DDD0*/	movsx eax,cx
	/*0081DDD3*/	movsx edx,si
	/*0081DDD6*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081DDD9*/	mov eax,edx
	/*0081DDDB*/	shl eax,0x5
	/*0081DDDE*/	shl ebx,0x8
	/*0081DDE1*/	add eax,edx
	/*0081DDE3*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081DDE6*/	mov eax,dword ptr ds:[ebx+0xB74C4C]
	/*0081DDEC*/	mov eax,dword ptr ds:[eax+edx*0x4+0xBA966]
	/*0081DDF3*/	jmp _0081DDF7
_0081DDF5:
	/*0081DDF5*/	xor eax,eax
_0081DDF7:
	/*0081DDF7*/	cmp ax,bp
	/*0081DDFA*/	jne _0081DDFF
	/*0081DDFC*/	mov ax,di
_0081DDFF:
	/*0081DDFF*/	cmp ax,0x3A
	/*0081DE03*/	jne _0081DE1C
	/*0081DE05*/	pop edi
	/*0081DE06*/	pop esi
	/*0081DE07*/	pop ebp
	/*0081DE08*/	mov byte ptr ds:[0x9B5981],0x0
	/*0081DE0F*/	mov eax,0xFFFFFFF5
	/*0081DE14*/	pop ebx
	/*0081DE15*/	add esp,0x250
	/*0081DE1B*/	ret
_0081DE1C:
	/*0081DE1C*/	cmp si,0xFFFF
	/*0081DE20*/	je _0081DE47
	/*0081DE22*/	movsx eax,cx
	/*0081DE25*/	movsx edx,si
	/*0081DE28*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081DE2B*/	mov eax,edx
	/*0081DE2D*/	shl eax,0x5
	/*0081DE30*/	shl ebx,0x8
	/*0081DE33*/	add eax,edx
	/*0081DE35*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081DE38*/	mov eax,dword ptr ds:[ebx+0xB74C4C]
	/*0081DE3E*/	mov eax,dword ptr ds:[eax+edx*0x4+0xBA966]
	/*0081DE45*/	jmp _0081DE49
_0081DE47:
	/*0081DE47*/	xor eax,eax
_0081DE49:
	/*0081DE49*/	cmp ax,bp
	/*0081DE4C*/	jne _0081DE51
	/*0081DE4E*/	mov ax,di
_0081DE51:
	/*0081DE51*/	cmp ax,0x3C
	/*0081DE55*/	jne _0081DE6E
	/*0081DE57*/	pop edi
	/*0081DE58*/	pop esi
	/*0081DE59*/	pop ebp
	/*0081DE5A*/	mov byte ptr ds:[0x9CC270],0x0
	/*0081DE61*/	mov eax,0xFFFFFFF5
	/*0081DE66*/	pop ebx
	/*0081DE67*/	add esp,0x250
	/*0081DE6D*/	ret
_0081DE6E:
	/*0081DE6E*/	cmp si,0xFFFF
	/*0081DE72*/	je _0081DE99
	/*0081DE74*/	movsx eax,cx
	/*0081DE77*/	movsx edx,si
	/*0081DE7A*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081DE7D*/	mov eax,edx
	/*0081DE7F*/	shl eax,0x5
	/*0081DE82*/	shl ebx,0x8
	/*0081DE85*/	add eax,edx
	/*0081DE87*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081DE8A*/	mov eax,dword ptr ds:[ebx+0xB74C4C]
	/*0081DE90*/	mov eax,dword ptr ds:[eax+edx*0x4+0xBA966]
	/*0081DE97*/	jmp _0081DE9B
_0081DE99:
	/*0081DE99*/	xor eax,eax
_0081DE9B:
	/*0081DE9B*/	cmp ax,bp
	/*0081DE9E*/	jne _0081DEA3
	/*0081DEA0*/	mov ax,di
_0081DEA3:
	/*0081DEA3*/	cmp ax,0x3B
	/*0081DEA7*/	jne _0081DEC0
	/*0081DEA9*/	pop edi
	/*0081DEAA*/	pop esi
	/*0081DEAB*/	pop ebp
	/*0081DEAC*/	mov byte ptr ds:[0x9CC270],0x1
	/*0081DEB3*/	mov eax,0xFFFFFFF5
	/*0081DEB8*/	pop ebx
	/*0081DEB9*/	add esp,0x250
	/*0081DEBF*/	ret
_0081DEC0:
	/*0081DEC0*/	cmp si,0xFFFF
	/*0081DEC4*/	je _0081DEEB
	/*0081DEC6*/	movsx eax,cx
	/*0081DEC9*/	movsx edx,si
	/*0081DECC*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081DECF*/	mov eax,edx
	/*0081DED1*/	shl eax,0x5
	/*0081DED4*/	shl ebx,0x8
	/*0081DED7*/	add eax,edx
	/*0081DED9*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081DEDC*/	mov eax,dword ptr ds:[ebx+0xB74C4C]
	/*0081DEE2*/	mov eax,dword ptr ds:[eax+edx*0x4+0xBA966]
	/*0081DEE9*/	jmp _0081DEED
_0081DEEB:
	/*0081DEEB*/	xor eax,eax
_0081DEED:
	/*0081DEED*/	cmp ax,bp
	/*0081DEF0*/	jne _0081DEF5
	/*0081DEF2*/	mov ax,di
_0081DEF5:
	/*0081DEF5*/	cmp ax,0xB
	/*0081DEF9*/	jne _0081DF48
	/*0081DEFB*/	mov eax,dword ptr ds:[0xAE2350]
	/*0081DF00*/	xor ecx,ecx
	/*0081DF02*/	cmp eax,ebp
	/*0081DF04*/	jle _0081DF26
	/*0081DF06*/	xor eax,eax
_0081DF08:
	/*0081DF08*/	mov edx,dword ptr ds:[0xAE23A8]
	/*0081DF0E*/	inc ecx
	/*0081DF0F*/	mov byte ptr ds:[eax+edx+0x11C],0x0
	/*0081DF17*/	mov edx,dword ptr ds:[0xAE2350]
	/*0081DF1D*/	add eax,0x122
	/*0081DF22*/	cmp ecx,edx
	/*0081DF24*/	jl _0081DF08
_0081DF26:
	/*0081DF26*/	pop edi
	/*0081DF27*/	mov dword ptr ds:[0xAE2D00],ebp
	/*0081DF2D*/	mov dword ptr ds:[0xAE2D04],ebp
	/*0081DF33*/	mov dword ptr ds:[0xAE2D08],ebp
	/*0081DF39*/	pop esi
	/*0081DF3A*/	pop ebp
	/*0081DF3B*/	mov eax,0xFFFFFFF5
	/*0081DF40*/	pop ebx
	/*0081DF41*/	add esp,0x250
	/*0081DF47*/	ret
_0081DF48:
	/*0081DF48*/	cmp si,0xFFFF
	/*0081DF4C*/	je _0081DF73
	/*0081DF4E*/	movsx eax,cx
	/*0081DF51*/	movsx edx,si
	/*0081DF54*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081DF57*/	mov eax,edx
	/*0081DF59*/	shl eax,0x5
	/*0081DF5C*/	shl ebx,0x8
	/*0081DF5F*/	add eax,edx
	/*0081DF61*/	mov edx,dword ptr ds:[ebx+0xB74C4C]
	/*0081DF67*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081DF6A*/	mov eax,dword ptr ds:[edx+eax*0x4+0xBA966]
	/*0081DF71*/	jmp _0081DF75
_0081DF73:
	/*0081DF73*/	xor eax,eax
_0081DF75:
	/*0081DF75*/	cmp ax,bp
	/*0081DF78*/	jne _0081DF7D
	/*0081DF7A*/	mov ax,di
_0081DF7D:
	/*0081DF7D*/	cmp ax,0xC
	/*0081DF81*/	jne _0081E104
	/*0081DF87*/	cmp si,0xFFFF
	/*0081DF8B*/	je _0081DFB2
	/*0081DF8D*/	movsx eax,cx
	/*0081DF90*/	movsx ecx,si
	/*0081DF93*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081DF96*/	mov eax,ecx
	/*0081DF98*/	shl eax,0x5
	/*0081DF9B*/	shl edx,0x8
	/*0081DF9E*/	add eax,ecx
	/*0081DFA0*/	mov ecx,dword ptr ds:[edx+0xB74C4C]
	/*0081DFA6*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081DFA9*/	mov esi,dword ptr ds:[ecx+eax*0x4+0xBA9A6]
	/*0081DFB0*/	jmp _0081DFB4
_0081DFB2:
	/*0081DFB2*/	xor esi,esi
_0081DFB4:
	/*0081DFB4*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081DFBA*/	test al,al
	/*0081DFBC*/	jne _0081E093
	/*0081DFC2*/	mov ebp,dword ptr ds:[0xAE2D00]
	/*0081DFC8*/	call sub_7A1710		/*call <cm0102.sub_7A1710>*/
	/*0081DFCD*/	mov ecx,eax
	/*0081DFCF*/	mov eax,0x92492493
	/*0081DFD4*/	imul ecx
	/*0081DFD6*/	add edx,ecx
	/*0081DFD8*/	sar edx,0x2
	/*0081DFDB*/	mov eax,edx
	/*0081DFDD*/	shr eax,0x1F
	/*0081DFE0*/	add edx,eax
	/*0081DFE2*/	mov edi,edx
	/*0081DFE4*/	jne _0081DFEB
	/*0081DFE6*/	mov edi,0x1
_0081DFEB:
	/*0081DFEB*/	push 0xA80484		/*push cm0102.A80484*/
	/*0081DFF0*/	push 0xAE2C98		/*push cm0102.AE2C98*/
	/*0081DFF5*/	call sub_945A60		/*call <cm0102.sub_945A60>*/
	/*0081DFFA*/	add esp,0x8
	/*0081DFFD*/	test eax,eax
	/*0081DFFF*/	jne _0081E053
	/*0081E001*/	mov eax,dword ptr ds:[0x9CD1FC]
	/*0081E006*/	test eax,eax
	/*0081E008*/	je _0081E053
	/*0081E00A*/	cmp ebp,edi
	/*0081E00C*/	jl _0081E053
	/*0081E00E*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0081E012*/	push 0xA80470		/*push cm0102.A80470*/
	/*0081E017*/	push ecx
	/*0081E018*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E01D*/	add esp,0x8
	/*0081E020*/	push 0xA80440		/*push cm0102.A80440*/
	/*0081E025*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E02A*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E02F*/	push 0x0
	/*0081E031*/	lea edx,dword ptr ss:[esp+0x1C]
	/*0081E035*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E03A*/	push edx
	/*0081E03B*/	call sub_5E8290_message_box		/*call <cm0102.sub_5E8290>*/
	/*0081E040*/	add esp,0x14
	/*0081E043*/	mov eax,0xFFFFFFF5
	/*0081E048*/	pop edi
	/*0081E049*/	pop esi
	/*0081E04A*/	pop ebp
	/*0081E04B*/	pop ebx
	/*0081E04C*/	add esp,0x250
	/*0081E052*/	ret
_0081E053:
	/*0081E053*/	mov edx,dword ptr ds:[0xAE2D00]
	/*0081E059*/	mov ecx,dword ptr ds:[0xAE2D04]
	/*0081E05F*/	inc edx
	/*0081E060*/	inc ecx
	/*0081E061*/	mov dword ptr ds:[0xAE2D00],edx
	/*0081E067*/	mov dword ptr ds:[0xAE2D04],ecx
	/*0081E06D*/	mov byte ptr ds:[esi+0x11C],0x2
	/*0081E074*/	mov eax,dword ptr ds:[0xAE2D08]
	/*0081E079*/	test eax,eax
	/*0081E07B*/	jne _0081E0F4
	/*0081E07D*/	mov dword ptr ds:[0xAE2D08],esi
	/*0081E083*/	pop edi
	/*0081E084*/	pop esi
	/*0081E085*/	pop ebp
	/*0081E086*/	mov eax,0xFFFFFFF5
	/*0081E08B*/	pop ebx
	/*0081E08C*/	add esp,0x250
	/*0081E092*/	ret
_0081E093:
	/*0081E093*/	mov ecx,dword ptr ds:[0xAE2D00]
	/*0081E099*/	mov bl,0x2
	/*0081E09B*/	dec ecx
	/*0081E09C*/	mov dword ptr ds:[0xAE2D00],ecx
	/*0081E0A2*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E0A8*/	test bl,al
	/*0081E0AA*/	je _0081E0B2
	/*0081E0AC*/	dec dword ptr ds:[0xAE2D04]
_0081E0B2:
	/*0081E0B2*/	mov byte ptr ds:[esi+0x11C],0x0
	/*0081E0B9*/	mov eax,dword ptr ds:[0xAE2D08]
	/*0081E0BE*/	cmp esi,eax
	/*0081E0C0*/	jne _0081E0F4
	/*0081E0C2*/	xor edx,edx
	/*0081E0C4*/	mov ecx,[nation_table_ptr] //0xB63D60		/*mov ecx,cm0102.B63D60*/
	/*0081E0C9*/	mov dword ptr ds:[0xAE2D08],edx
_0081E0CF:
	/*0081E0CF*/	cmp edx,ebp
	/*0081E0D1*/	jne _0081E0F4
	/*0081E0D3*/	mov eax,dword ptr ds:[ecx]
	/*0081E0D5*/	cmp eax,ebp
	/*0081E0D7*/	je _0081E0E9
	/*0081E0D9*/	test byte ptr ds:[eax+0x11C],bl
	/*0081E0DF*/	je _0081E0E9
	/*0081E0E1*/	mov edx,eax
	/*0081E0E3*/	mov dword ptr ds:[0xAE2D08],edx
_0081E0E9:
	/*0081E0E9*/	add ecx,0x48

					push ebx
					mov ebx, [nation_table_ptr]
					mov eax, [TotalNumberOfConsideredNations]
					imul eax, 72
					add ebx, eax
					cmp ecx, ebx
					pop ebx

	/*0081E0EC*/	//cmp ecx,0xB64738		/*cmp ecx,cm0102.B64738*/
	/*0081E0F2*/	jl _0081E0CF
_0081E0F4:
	/*0081E0F4*/	pop edi
	/*0081E0F5*/	pop esi
	/*0081E0F6*/	pop ebp
	/*0081E0F7*/	mov eax,0xFFFFFFF5
	/*0081E0FC*/	pop ebx
	/*0081E0FD*/	add esp,0x250
	/*0081E103*/	ret
_0081E104:
	/*0081E104*/	cmp si,0xFFFF
	/*0081E108*/	je _0081E12F
	/*0081E10A*/	movsx eax,cx
	/*0081E10D*/	movsx edx,si
	/*0081E110*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081E113*/	mov eax,edx
	/*0081E115*/	shl eax,0x5
	/*0081E118*/	shl ebx,0x8
	/*0081E11B*/	add eax,edx
	/*0081E11D*/	mov edx,dword ptr ds:[ebx+0xB74C4C]
	/*0081E123*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081E126*/	mov eax,dword ptr ds:[edx+eax*0x4+0xBA966]
	/*0081E12D*/	jmp _0081E131
_0081E12F:
	/*0081E12F*/	xor eax,eax
_0081E131:
	/*0081E131*/	cmp ax,bp
	/*0081E134*/	jne _0081E139
	/*0081E136*/	mov ax,di
_0081E139:
	/*0081E139*/	cmp ax,0x38
	/*0081E13D*/	jne _0081E28F
	/*0081E143*/	cmp si,0xFFFF
	/*0081E147*/	je _0081E16E
	/*0081E149*/	movsx eax,cx
	/*0081E14C*/	movsx ecx,si
	/*0081E14F*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081E152*/	mov eax,ecx
	/*0081E154*/	shl eax,0x5
	/*0081E157*/	shl edx,0x8
	/*0081E15A*/	add eax,ecx
	/*0081E15C*/	mov ecx,dword ptr ds:[edx+0xB74C4C]
	/*0081E162*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081E165*/	mov esi,dword ptr ds:[ecx+eax*0x4+0xBA9A6]
	/*0081E16C*/	jmp _0081E170
_0081E16E:
	/*0081E16E*/	xor esi,esi
_0081E170:
	/*0081E170*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E176*/	test al,al
	/*0081E178*/	jne _0081E23F
	/*0081E17E*/	mov ebp,dword ptr ds:[0xAE2D00]
	/*0081E184*/	call sub_7A1710		/*call <cm0102.sub_7A1710>*/
	/*0081E189*/	mov ecx,eax
	/*0081E18B*/	mov eax,0x92492493
	/*0081E190*/	imul ecx
	/*0081E192*/	add edx,ecx
	/*0081E194*/	sar edx,0x2
	/*0081E197*/	mov eax,edx
	/*0081E199*/	shr eax,0x1F
	/*0081E19C*/	add edx,eax
	/*0081E19E*/	mov edi,edx
	/*0081E1A0*/	jne _0081E1A7
	/*0081E1A2*/	mov edi,0x1
_0081E1A7:
	/*0081E1A7*/	push 0xA80484		/*push cm0102.A80484*/
	/*0081E1AC*/	push 0xAE2C98		/*push cm0102.AE2C98*/
	/*0081E1B1*/	call sub_945A60		/*call <cm0102.sub_945A60>*/
	/*0081E1B6*/	add esp,0x8
	/*0081E1B9*/	test eax,eax
	/*0081E1BB*/	jne _0081E20F
	/*0081E1BD*/	mov eax,dword ptr ds:[0x9CD1FC]
	/*0081E1C2*/	test eax,eax
	/*0081E1C4*/	je _0081E20F
	/*0081E1C6*/	cmp ebp,edi
	/*0081E1C8*/	jl _0081E20F
	/*0081E1CA*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0081E1CE*/	push 0xA80470		/*push cm0102.A80470*/
	/*0081E1D3*/	push ecx
	/*0081E1D4*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E1D9*/	add esp,0x8
	/*0081E1DC*/	push 0xA80440		/*push cm0102.A80440*/
	/*0081E1E1*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E1E6*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E1EB*/	push 0x0
	/*0081E1ED*/	lea edx,dword ptr ss:[esp+0x1C]
	/*0081E1F1*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E1F6*/	push edx
	/*0081E1F7*/	call sub_5E8290_message_box		/*call <cm0102.sub_5E8290>*/
	/*0081E1FC*/	add esp,0x14
	/*0081E1FF*/	mov eax,0xFFFFFFF5
	/*0081E204*/	pop edi
	/*0081E205*/	pop esi
	/*0081E206*/	pop ebp
	/*0081E207*/	pop ebx
	/*0081E208*/	add esp,0x250
	/*0081E20E*/	ret
_0081E20F:
	/*0081E20F*/	mov byte ptr ds:[esi+0x11C],0x2
	/*0081E216*/	mov edx,dword ptr ds:[0xAE2D00]
	/*0081E21C*/	mov ecx,dword ptr ds:[0xAE2D04]
	/*0081E222*/	mov eax,dword ptr ds:[0xAE2D08]
	/*0081E227*/	inc edx
	/*0081E228*/	inc ecx
	/*0081E229*/	test eax,eax
	/*0081E22B*/	mov dword ptr ds:[0xAE2D00],edx
	/*0081E231*/	mov dword ptr ds:[0xAE2D04],ecx
	/*0081E237*/	jne _0081E23F
	/*0081E239*/	mov dword ptr ds:[0xAE2D08],esi
_0081E23F:
	/*0081E23F*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E245*/	test al,0x4
	/*0081E247*/	je _0081E26C
	/*0081E249*/	sub al,0x4
	/*0081E24B*/	pop edi
	/*0081E24C*/	mov byte ptr ds:[esi+0x11C],al
	/*0081E252*/	mov eax,dword ptr ds:[0xAE2D00]
	/*0081E257*/	dec eax
	/*0081E258*/	pop esi
	/*0081E259*/	mov dword ptr ds:[0xAE2D00],eax
	/*0081E25E*/	pop ebp
	/*0081E25F*/	mov eax,0xFFFFFFF5
	/*0081E264*/	pop ebx
	/*0081E265*/	add esp,0x250
	/*0081E26B*/	ret
_0081E26C:
	/*0081E26C*/	or al,0x4
	/*0081E26E*/	pop edi
	/*0081E26F*/	mov byte ptr ds:[esi+0x11C],al
	/*0081E275*/	mov eax,dword ptr ds:[0xAE2D00]
	/*0081E27A*/	inc eax
	/*0081E27B*/	pop esi
	/*0081E27C*/	mov dword ptr ds:[0xAE2D00],eax
	/*0081E281*/	pop ebp
	/*0081E282*/	mov eax,0xFFFFFFF5
	/*0081E287*/	pop ebx
	/*0081E288*/	add esp,0x250
	/*0081E28E*/	ret
_0081E28F:
	/*0081E28F*/	cmp si,0xFFFF
	/*0081E293*/	je _0081E2BA
	/*0081E295*/	movsx eax,cx
	/*0081E298*/	movsx edx,si
	/*0081E29B*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081E29E*/	mov eax,edx
	/*0081E2A0*/	shl eax,0x5
	/*0081E2A3*/	shl ebx,0x8
	/*0081E2A6*/	add eax,edx
	/*0081E2A8*/	mov edx,dword ptr ds:[ebx+0xB74C4C]
	/*0081E2AE*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081E2B1*/	mov eax,dword ptr ds:[edx+eax*0x4+0xBA966]
	/*0081E2B8*/	jmp _0081E2BC
_0081E2BA:
	/*0081E2BA*/	xor eax,eax
_0081E2BC:
	/*0081E2BC*/	cmp ax,bp
	/*0081E2BF*/	jne _0081E2C4
	/*0081E2C1*/	mov ax,di
_0081E2C4:
	/*0081E2C4*/	cmp ax,0xD
	/*0081E2C8*/	jne _0081E49D
	/*0081E2CE*/	cmp si,0xFFFF
	/*0081E2D2*/	je _0081E2F9
	/*0081E2D4*/	movsx eax,cx
	/*0081E2D7*/	movsx ecx,si
	/*0081E2DA*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081E2DD*/	mov eax,ecx
	/*0081E2DF*/	shl eax,0x5
	/*0081E2E2*/	shl edx,0x8
	/*0081E2E5*/	add eax,ecx
	/*0081E2E7*/	mov ecx,dword ptr ds:[edx+0xB74C4C]
	/*0081E2ED*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081E2F0*/	mov esi,dword ptr ds:[ecx+eax*0x4+0xBA9A6]
	/*0081E2F7*/	jmp _0081E2FB
_0081E2F9:
	/*0081E2F9*/	xor esi,esi
_0081E2FB:
	/*0081E2FB*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E301*/	test al,al
	/*0081E303*/	jne _0081E3DE
	/*0081E309*/	mov ebp,dword ptr ds:[0xAE2D00]
	/*0081E30F*/	call sub_7A1710		/*call <cm0102.sub_7A1710>*/
	/*0081E314*/	mov ecx,eax
	/*0081E316*/	mov eax,0x92492493
	/*0081E31B*/	imul ecx
	/*0081E31D*/	add edx,ecx
	/*0081E31F*/	sar edx,0x2
	/*0081E322*/	mov eax,edx
	/*0081E324*/	shr eax,0x1F
	/*0081E327*/	add edx,eax
	/*0081E329*/	mov edi,edx
	/*0081E32B*/	jne _0081E332
	/*0081E32D*/	mov edi,0x1
_0081E332:
	/*0081E332*/	push 0xA80484		/*push cm0102.A80484*/
	/*0081E337*/	push 0xAE2C98		/*push cm0102.AE2C98*/
	/*0081E33C*/	call sub_945A60		/*call <cm0102.sub_945A60>*/
	/*0081E341*/	add esp,0x8
	/*0081E344*/	test eax,eax
	/*0081E346*/	jne _0081E39A
	/*0081E348*/	mov eax,dword ptr ds:[0x9CD1FC]
	/*0081E34D*/	test eax,eax
	/*0081E34F*/	je _0081E39A
	/*0081E351*/	cmp ebp,edi
	/*0081E353*/	jl _0081E39A
	/*0081E355*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0081E359*/	push 0xA80470		/*push cm0102.A80470*/
	/*0081E35E*/	push ecx
	/*0081E35F*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E364*/	add esp,0x8
	/*0081E367*/	push 0xA80440		/*push cm0102.A80440*/
	/*0081E36C*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E371*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E376*/	push 0x0
	/*0081E378*/	lea edx,dword ptr ss:[esp+0x1C]
	/*0081E37C*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E381*/	push edx
	/*0081E382*/	call sub_5E8290_message_box		/*call <cm0102.sub_5E8290>*/
	/*0081E387*/	add esp,0x14
	/*0081E38A*/	mov eax,0xFFFFFFF5
	/*0081E38F*/	pop edi
	/*0081E390*/	pop esi
	/*0081E391*/	pop ebp
	/*0081E392*/	pop ebx
	/*0081E393*/	add esp,0x250
	/*0081E399*/	ret
_0081E39A:
	/*0081E39A*/	mov edx,dword ptr ds:[0xAE2D00]
	/*0081E3A0*/	mov ecx,dword ptr ds:[0xAE2D04]
	/*0081E3A6*/	inc edx
	/*0081E3A7*/	inc ecx
	/*0081E3A8*/	mov dword ptr ds:[0xAE2D00],edx
	/*0081E3AE*/	mov dword ptr ds:[0xAE2D04],ecx
	/*0081E3B4*/	mov byte ptr ds:[esi+0x11C],0x2
	/*0081E3BB*/	mov eax,dword ptr ds:[0xAE2D08]
	/*0081E3C0*/	test eax,eax
	/*0081E3C2*/	jne _0081E48D
	/*0081E3C8*/	mov dword ptr ds:[0xAE2D08],esi
	/*0081E3CE*/	pop edi
	/*0081E3CF*/	pop esi
	/*0081E3D0*/	pop ebp
	/*0081E3D1*/	mov eax,0xFFFFFFF5
	/*0081E3D6*/	pop ebx
	/*0081E3D7*/	add esp,0x250
	/*0081E3DD*/	ret
_0081E3DE:
	/*0081E3DE*/	mov bl,0x2
	/*0081E3E0*/	test bl,al
	/*0081E3E2*/	je _0081E461
	/*0081E3E4*/	mov ecx,dword ptr ds:[0xAE2D00]
	/*0081E3EA*/	dec ecx
	/*0081E3EB*/	mov dword ptr ds:[0xAE2D00],ecx
	/*0081E3F1*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E3F7*/	test al,0x4
	/*0081E3F9*/	je _0081E403
	/*0081E3FB*/	mov eax,ecx
	/*0081E3FD*/	dec eax
	/*0081E3FE*/	mov dword ptr ds:[0xAE2D00],eax
_0081E403:
	/*0081E403*/	mov ecx,dword ptr ds:[0xAE2D04]
	/*0081E409*/	dec ecx
	/*0081E40A*/	mov dword ptr ds:[0xAE2D04],ecx
	/*0081E410*/	mov byte ptr ds:[esi+0x11C],0x0
	/*0081E417*/	cmp esi,dword ptr ds:[0xAE2D08]
	/*0081E41D*/	jne _0081E48D
	/*0081E41F*/	xor edx,edx
	/*0081E421*/	mov ecx,[nation_table_ptr] //0xB63D60		/*mov ecx,cm0102.B63D60*/
	/*0081E426*/	mov dword ptr ds:[0xAE2D08],edx
_0081E42C:
	/*0081E42C*/	cmp edx,ebp
	/*0081E42E*/	jne _0081E48D
	/*0081E430*/	mov eax,dword ptr ds:[ecx]
	/*0081E432*/	cmp eax,ebp
	/*0081E434*/	je _0081E446
	/*0081E436*/	test byte ptr ds:[eax+0x11C],bl
	/*0081E43C*/	je _0081E446
	/*0081E43E*/	mov edx,eax
	/*0081E440*/	mov dword ptr ds:[0xAE2D08],edx
_0081E446:
	/*0081E446*/	add ecx,0x48

					push ebx
					mov ebx, [nation_table_ptr]
					mov eax, [TotalNumberOfConsideredNations]
					imul eax, 72
					add ebx, eax
					cmp ecx, ebx
					pop ebx

	/*0081E449*/	//cmp ecx,0xB64738		/*cmp ecx,cm0102.B64738*/
	/*0081E44F*/	jl _0081E42C
	/*0081E451*/	pop edi
	/*0081E452*/	pop esi
	/*0081E453*/	pop ebp
	/*0081E454*/	mov eax,0xFFFFFFF5
	/*0081E459*/	pop ebx
	/*0081E45A*/	add esp,0x250
	/*0081E460*/	ret
_0081E461:
	/*0081E461*/	mov edi,dword ptr ds:[0xAE2D04]
	/*0081E467*/	inc edi
	/*0081E468*/	mov dword ptr ds:[0xAE2D04],edi
	/*0081E46E*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E474*/	and al,0xFE
	/*0081E476*/	or al,bl
	/*0081E478*/	mov byte ptr ds:[esi+0x11C],al
	/*0081E47E*/	mov eax,dword ptr ds:[0xAE2D08]
	/*0081E483*/	cmp eax,ebp
	/*0081E485*/	jne _0081E48D
	/*0081E487*/	mov dword ptr ds:[0xAE2D08],esi
_0081E48D:
	/*0081E48D*/	pop edi
	/*0081E48E*/	pop esi
	/*0081E48F*/	pop ebp
	/*0081E490*/	mov eax,0xFFFFFFF5
	/*0081E495*/	pop ebx
	/*0081E496*/	add esp,0x250
	/*0081E49C*/	ret
_0081E49D:
	/*0081E49D*/	cmp si,0xFFFF
	/*0081E4A1*/	je _0081E4C8
	/*0081E4A3*/	movsx eax,cx
	/*0081E4A6*/	movsx edx,si
	/*0081E4A9*/	lea ebx,dword ptr ds:[eax+eax*0x2]
	/*0081E4AC*/	mov eax,edx
	/*0081E4AE*/	shl eax,0x5
	/*0081E4B1*/	shl ebx,0x8
	/*0081E4B4*/	add eax,edx
	/*0081E4B6*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081E4B9*/	mov eax,dword ptr ds:[ebx+0xB74C4C]
	/*0081E4BF*/	mov eax,dword ptr ds:[eax+edx*0x4+0xBA966]
	/*0081E4C6*/	jmp _0081E4CA
_0081E4C8:
	/*0081E4C8*/	xor eax,eax
_0081E4CA:
	/*0081E4CA*/	cmp ax,bp
	/*0081E4CD*/	jne _0081E4D2
	/*0081E4CF*/	mov ax,di
_0081E4D2:
	/*0081E4D2*/	cmp ax,0xE
	/*0081E4D6*/	jne _0081E66E
	/*0081E4DC*/	cmp si,0xFFFF
	/*0081E4E0*/	je _0081E507
	/*0081E4E2*/	movsx eax,cx
	/*0081E4E5*/	movsx ecx,si
	/*0081E4E8*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081E4EB*/	mov eax,ecx
	/*0081E4ED*/	shl eax,0x5
	/*0081E4F0*/	shl edx,0x8
	/*0081E4F3*/	add eax,ecx
	/*0081E4F5*/	mov ecx,dword ptr ds:[edx+0xB74C4C]
	/*0081E4FB*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081E4FE*/	mov esi,dword ptr ds:[ecx+eax*0x4+0xBA9A6]
	/*0081E505*/	jmp _0081E509
_0081E507:
	/*0081E507*/	xor esi,esi
_0081E509:
	/*0081E509*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E50F*/	test al,al
	/*0081E511*/	jne _0081E5CA
	/*0081E517*/	mov ebp,dword ptr ds:[0xAE2D00]
	/*0081E51D*/	call sub_7A1710		/*call <cm0102.sub_7A1710>*/
	/*0081E522*/	mov ecx,eax
	/*0081E524*/	mov eax,0x92492493
	/*0081E529*/	imul ecx
	/*0081E52B*/	add edx,ecx
	/*0081E52D*/	sar edx,0x2
	/*0081E530*/	mov eax,edx
	/*0081E532*/	shr eax,0x1F
	/*0081E535*/	add edx,eax
	/*0081E537*/	mov edi,edx
	/*0081E539*/	jne _0081E540
	/*0081E53B*/	mov edi,0x1
_0081E540:
	/*0081E540*/	push 0xA80484		/*push cm0102.A80484*/
	/*0081E545*/	push 0xAE2C98		/*push cm0102.AE2C98*/
	/*0081E54A*/	call sub_945A60		/*call <cm0102.sub_945A60>*/
	/*0081E54F*/	add esp,0x8
	/*0081E552*/	test eax,eax
	/*0081E554*/	jne _0081E5A8
	/*0081E556*/	mov eax,dword ptr ds:[0x9CD1FC]
	/*0081E55B*/	test eax,eax
	/*0081E55D*/	je _0081E5A8
	/*0081E55F*/	cmp ebp,edi
	/*0081E561*/	jl _0081E5A8
	/*0081E563*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0081E567*/	push 0xA80470		/*push cm0102.A80470*/
	/*0081E56C*/	push ecx
	/*0081E56D*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E572*/	add esp,0x8
	/*0081E575*/	push 0xA80440		/*push cm0102.A80440*/
	/*0081E57A*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E57F*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*0081E584*/	push 0x0
	/*0081E586*/	lea edx,dword ptr ss:[esp+0x1C]
	/*0081E58A*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*0081E58F*/	push edx
	/*0081E590*/	call sub_5E8290_message_box		/*call <cm0102.sub_5E8290>*/
	/*0081E595*/	add esp,0x14
	/*0081E598*/	mov eax,0xFFFFFFF5
	/*0081E59D*/	pop edi
	/*0081E59E*/	pop esi
	/*0081E59F*/	pop ebp
	/*0081E5A0*/	pop ebx
	/*0081E5A1*/	add esp,0x250
	/*0081E5A7*/	ret
_0081E5A8:
	/*0081E5A8*/	mov eax,dword ptr ds:[0xAE2D00]
	/*0081E5AD*/	pop edi
	/*0081E5AE*/	inc eax
	/*0081E5AF*/	mov dword ptr ds:[0xAE2D00],eax
	/*0081E5B4*/	mov byte ptr ds:[esi+0x11C],0x1
	/*0081E5BB*/	pop esi
	/*0081E5BC*/	pop ebp
	/*0081E5BD*/	mov eax,0xFFFFFFF5
	/*0081E5C2*/	pop ebx
	/*0081E5C3*/	add esp,0x250
	/*0081E5C9*/	ret
_0081E5CA:
	/*0081E5CA*/	test al,0x1
	/*0081E5CC*/	je _0081E604
	/*0081E5CE*/	mov ecx,dword ptr ds:[0xAE2D00]
	/*0081E5D4*/	dec ecx
	/*0081E5D5*/	mov dword ptr ds:[0xAE2D00],ecx
	/*0081E5DB*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E5E1*/	test al,0x4
	/*0081E5E3*/	je _0081E5ED
	/*0081E5E5*/	mov eax,ecx
	/*0081E5E7*/	dec eax
	/*0081E5E8*/	mov dword ptr ds:[0xAE2D00],eax
_0081E5ED:
	/*0081E5ED*/	mov byte ptr ds:[esi+0x11C],0x0
	/*0081E5F4*/	pop edi
	/*0081E5F5*/	pop esi
	/*0081E5F6*/	pop ebp
	/*0081E5F7*/	mov eax,0xFFFFFFF5
	/*0081E5FC*/	pop ebx
	/*0081E5FD*/	add esp,0x250
	/*0081E603*/	ret
_0081E604:
	/*0081E604*/	mov edi,dword ptr ds:[0xAE2D04]
	/*0081E60A*/	dec edi
	/*0081E60B*/	mov dword ptr ds:[0xAE2D04],edi
	/*0081E611*/	mov al,byte ptr ds:[esi+0x11C]
	/*0081E617*/	and al,0xFD
	/*0081E619*/	or al,0x1
	/*0081E61B*/	mov byte ptr ds:[esi+0x11C],al
	/*0081E621*/	mov eax,dword ptr ds:[0xAE2D08]
	/*0081E626*/	cmp esi,eax
	/*0081E628*/	jne _0081E65E
	/*0081E62A*/	xor edx,edx
	/*0081E62C*/	mov ecx,[nation_table_ptr] //0xB63D60		/*mov ecx,cm0102.B63D60*/
	/*0081E631*/	mov dword ptr ds:[0xAE2D08],edx
	/*0081E637*/	mov bl,0x2
_0081E639:
	/*0081E639*/	cmp edx,ebp
	/*0081E63B*/	jne _0081E65E
	/*0081E63D*/	mov eax,dword ptr ds:[ecx]
	/*0081E63F*/	cmp eax,ebp
	/*0081E641*/	je _0081E653
	/*0081E643*/	cmp byte ptr ds:[eax+0x11C],bl
	/*0081E649*/	jne _0081E653
	/*0081E64B*/	mov edx,eax
	/*0081E64D*/	mov dword ptr ds:[0xAE2D08],edx
_0081E653:
	/*0081E653*/	add ecx,0x48
					
					push ebx
					mov ebx, [nation_table_ptr]
					mov eax, [TotalNumberOfConsideredNations]
					imul eax, 72
					add ebx, eax
					cmp ecx, ebx
					pop ebx

	/*0081E656*/	// cmp ecx,0xB64738		/*cmp ecx,cm0102.B64738*/
	/*0081E65C*/	jl _0081E639
_0081E65E:
	/*0081E65E*/	pop edi
	/*0081E65F*/	pop esi
	/*0081E660*/	pop ebp
	/*0081E661*/	mov eax,0xFFFFFFF5
	/*0081E666*/	pop ebx
	/*0081E667*/	add esp,0x250
	/*0081E66D*/	ret
_0081E66E:
	/*0081E66E*/	cmp si,0xFFFF
	/*0081E672*/	je _0081E699
	/*0081E674*/	movsx eax,cx
	/*0081E677*/	movsx ecx,si
	/*0081E67A*/	lea edx,dword ptr ds:[eax+eax*0x2]
	/*0081E67D*/	mov eax,ecx
	/*0081E67F*/	shl eax,0x5
	/*0081E682*/	shl edx,0x8
	/*0081E685*/	add eax,ecx
	/*0081E687*/	mov ecx,dword ptr ds:[edx+0xB74C4C]
	/*0081E68D*/	lea eax,dword ptr ds:[eax+eax*0x2]
	/*0081E690*/	mov eax,dword ptr ds:[ecx+eax*0x4+0xBA966]
	/*0081E697*/	jmp _0081E69B
_0081E699:
	/*0081E699*/	xor eax,eax
_0081E69B:
	/*0081E69B*/	cmp ax,bp
	/*0081E69E*/	jne _0081E6A3
	/*0081E6A0*/	mov ax,di
_0081E6A3:
	/*0081E6A3*/	cmp ax,0xFFFD
	/*0081E6A7*/	jne _0081E8AD
	/*0081E6AD*/	cmp dword ptr ds:[0xDD7118],ebp
	/*0081E6B3*/	je _0081E6C5
	/*0081E6B5*/	pop edi
	/*0081E6B6*/	pop esi
	/*0081E6B7*/	pop ebp
	/*0081E6B8*/	mov eax,0xFFFFFFFD
	/*0081E6BD*/	pop ebx
	/*0081E6BE*/	add esp,0x250
	/*0081E6C4*/	ret
_0081E6C5:
					call PreCreateLeagues
					cmp eax, 0
					je _TooManyLeaguesSelected

	/*0081E6C5*/	mov eax,dword ptr ds:[0xAE2D04]
	/*0081E6CA*/	cmp eax,ebp
	/*0081E6CC*/	jne _0081E6DB

_TooManyLeaguesSelected:
	/*0081E6CE*/	pop edi
	/*0081E6CF*/	pop esi
	/*0081E6D0*/	pop ebp
	/*0081E6D1*/	xor eax,eax
	/*0081E6D3*/	pop ebx
	/*0081E6D4*/	add esp,0x250
	/*0081E6DA*/	ret
_0081E6DB:
	/*0081E6DB*/	cmp eax,0x1					/// <---- league count determining whether to show the league select screen
	/*0081E6DE*/	jle _0081E707
	/*0081E6E0*/	push ebp
	/*0081E6E1*/	push ebp
	/*0081E6E2*/	push ebp
	/*0081E6E3*/	push 0x81EB00		/*push <cm0102.sub_81EB00>*/
	/*0081E6E8*/	push 0x81E8D0		/*push <cm0102.sub_81E8D0>*/
	/*0081E6ED*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E6F2*/	call sub_7FE600		/*call <cm0102.sub_7FE600>*/
	/*0081E6F7*/	pop edi
	/*0081E6F8*/	pop esi
	/*0081E6F9*/	pop ebp
	/*0081E6FA*/	mov eax,0xFFFFFFFC
	/*0081E6FF*/	pop ebx
	/*0081E700*/	add esp,0x250
	/*0081E706*/	ret
_0081E707:
	/*0081E707*/	push ebp
	/*0081E708*/	mov dword ptr ds:[0xDD7124],0x1

	/*0081E712*/	call sub_828110		/*call <cm0102.sub_828110>*/					/// <---- start the load after pressing next
	/*0081E717*/	add esp,0x4
	/*0081E71A*/	test eax,eax
	/*0081E71C*/	jne _0081E81A
	/*0081E722*/	cmp dword ptr ds:[0xDD7134],ebp
	/*0081E728*/	je _0081E768
	/*0081E72A*/	mov edx,dword ptr ds:[0xDD7118]
	/*0081E730*/	push ebp
	/*0081E731*/	push ebp
	/*0081E732*/	push edx
	/*0081E733*/	push 0x826C20		/*push <cm0102.sub_826C20>*/
	/*0081E738*/	push 0x826AA0		/*push <cm0102.sub_826AA0>*/
	/*0081E73D*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E742*/	call sub_7FE600		/*call <cm0102.sub_7FE600>*/
	/*0081E747*/	test eax,eax
	/*0081E749*/	je _0081E758
	/*0081E74B*/	push ebp
	/*0081E74C*/	push ebp
	/*0081E74D*/	push ebp
	/*0081E74E*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E753*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
_0081E758:
	/*0081E758*/	pop edi
	/*0081E759*/	pop esi
	/*0081E75A*/	pop ebp
	/*0081E75B*/	mov eax,0xFFFFFFFC
	/*0081E760*/	pop ebx
	/*0081E761*/	add esp,0x250
	/*0081E767*/	ret
_0081E768:
	/*0081E768*/	cmp dword ptr ds:[0xDD7138],ebp
	/*0081E76E*/	je _0081E7AD
	/*0081E770*/	mov eax,dword ptr ds:[0xDD7118]
	/*0081E775*/	push ebp
	/*0081E776*/	push ebp
	/*0081E777*/	push eax
	/*0081E778*/	push 0x826E60		/*push <cm0102.sub_826E60>*/
	/*0081E77D*/	push 0x826D20		/*push <cm0102.sub_826D20>*/
	/*0081E782*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E787*/	call sub_7FE600		/*call <cm0102.sub_7FE600>*/
	/*0081E78C*/	test eax,eax
	/*0081E78E*/	je _0081E758
	/*0081E790*/	push ebp
	/*0081E791*/	push ebp
	/*0081E792*/	push ebp
	/*0081E793*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E798*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
	/*0081E79D*/	pop edi
	/*0081E79E*/	pop esi
	/*0081E79F*/	pop ebp
	/*0081E7A0*/	mov eax,0xFFFFFFFC
	/*0081E7A5*/	pop ebx
	/*0081E7A6*/	add esp,0x250
	/*0081E7AC*/	ret
_0081E7AD:
	/*0081E7AD*/	lea ecx,dword ptr ss:[esp+0x60]
	/*0081E7B1*/	lea edx,dword ptr ss:[esp+0x160]
	/*0081E7B8*/	push ecx
	/*0081E7B9*/	push edx
	/*0081E7BA*/	push ebp
	/*0081E7BB*/	push ebp
	/*0081E7BC*/	push 0xA801DC		/*push cm0102.A801DC*/
	/*0081E7C1*/	call sub_944CFF		/*call <cm0102.sub_944CFF>*/
	/*0081E7C6*/	add esp,0x14
	/*0081E7C9*/	lea eax,dword ptr ss:[esp+0x60]
	/*0081E7CD*/	lea ecx,dword ptr ss:[esp+0x160]
	/*0081E7D4*/	push 0xA0C
	/*0081E7D9*/	push eax
	/*0081E7DA*/	push ecx
	/*0081E7DB*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0081E7E0*/	push eax
	/*0081E7E1*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0081E7E6*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0081E7EB*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*0081E7F0*/	push ebp
	/*0081E7F1*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0081E7F6*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0081E7FB*/	call sub_5E8290_message_box		/*call <cm0102.sub_5E8290>*/
	/*0081E800*/	add esp,0x24
	/*0081E803*/	mov dword ptr ds:[0xB67A34],ebp
	/*0081E809*/	call sub_5CC7D0		/*call <cm0102.sub_5CC7D0>*/
	/*0081E80E*/	call sub_5A8F60		/*call <cm0102.sub_5A8F60>*/
	/*0081E813*/	push 0xFFFFFFFF
	/*0081E815*/	call sub_945934		/*call <cm0102.sub_945934>*/
_0081E81A:
	/*0081E81A*/	cmp dword ptr ds:[0xDD712C],ebp
	/*0081E820*/	je _0081E838
	/*0081E822*/	push 0xDD70DC		/*push cm0102.DD70DC*/
	/*0081E827*/	push ebp
	/*0081E828*/	call sub_8388E0		/*call <cm0102.sub_8388E0>*/
	/*0081E82D*/	add esp,0x8
	/*0081E830*/	cmp eax,ebp
	/*0081E832*/	jne _0081E8C3
_0081E838:
	/*0081E838*/	push ebp
	/*0081E839*/	push ebp
	/*0081E83A*/	push ebp
	/*0081E83B*/	push 0x820950		/*push <cm0102.sub_820950>*/
	/*0081E840*/	push 0x81FF10		/*push <cm0102.sub_81FF10>*/
	/*0081E845*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E84A*/	call sub_7FE600		/*call <cm0102.sub_7FE600>*/
	/*0081E84F*/	test eax,eax
	/*0081E851*/	je _0081E898
	/*0081E853*/	push ebp
	/*0081E854*/	push ebp
	/*0081E855*/	push ebp
	/*0081E856*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E85B*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
	/*0081E860*/	push ebp
	/*0081E861*/	push ebp
	/*0081E862*/	push 0x1
	/*0081E864*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E869*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
	/*0081E86E*/	push ebp
	/*0081E86F*/	push ebp
	/*0081E870*/	push 0x2
	/*0081E872*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E877*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
	/*0081E87C*/	push ebp
	/*0081E87D*/	push ebp
	/*0081E87E*/	push 0x3
	/*0081E880*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E885*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
	/*0081E88A*/	push ebp
	/*0081E88B*/	push ebp
	/*0081E88C*/	push 0x4
	/*0081E88E*/	mov ecx,0xB74450		/*mov ecx,cm0102.B74450*/
	/*0081E893*/	call sub_7FF270		/*call <cm0102.sub_7FF270>*/
_0081E898:
	/*0081E898*/	call sub_820D40		/*call <cm0102.sub_820D40>*/
	/*0081E89D*/	pop edi
	/*0081E89E*/	pop esi
	/*0081E89F*/	pop ebp
	/*0081E8A0*/	mov eax,0xFFFFFFFC
	/*0081E8A5*/	pop ebx
	/*0081E8A6*/	add esp,0x250
	/*0081E8AC*/	ret
_0081E8AD:
	/*0081E8AD*/	push esi
	/*0081E8AE*/	call sub_7615D0		/*call <cm0102.sub_7615D0>*/
	/*0081E8B3*/	add esp,0x4
	/*0081E8B6*/	cmp eax,ebp
	/*0081E8B8*/	jne _0081E8C3
	/*0081E8BA*/	push esi
	/*0081E8BB*/	call sub_7643D0		/*call <cm0102.sub_7643D0>*/
	/*0081E8C0*/	add esp,0x4
_0081E8C3:
	/*0081E8C3*/	pop edi
	/*0081E8C4*/	pop esi
	/*0081E8C5*/	pop ebp
	/*0081E8C6*/	pop ebx
	/*0081E8C7*/	add esp,0x250
	/*0081E8CD*/	ret
	}
}

void setup_available_leagues()
{
	PatchFunction(0x81D010, (DWORD)&NationSelect_81D010);
	PatchFunction(0x81DC30, (DWORD)&sub_81DC30_UIHandler);
}
