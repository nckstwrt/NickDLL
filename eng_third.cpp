#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "CMHeader.h"
#include "Helper.h"
#include "vtable.h"
#include "generic_functions.h"
#include "LeagueInfo.h"

static int(*sub_48C6D0)() = (int(*)())(0x48C6D0);
static int(*sub_49F450)() = (int(*)())(0x49F450);
static int(*sub_4A1C50)() = (int(*)())(0x4A1C50);
static int(*sub_4A4850)() = (int(*)())(0x4A4850);
static int(*sub_4AE660)() = (int(*)())(0x4AE660);
static int(*sub_4AE8A0)() = (int(*)())(0x4AE8A0);
static int(*sub_51C800)() = (int(*)())(0x51C800);
static int(*sub_521E60)() = (int(*)())(0x521E60);
static int(*sub_521EB0)() = (int(*)())(0x521EB0);
static int(*sub_522E00)() = (int(*)())(0x522E00);
static int(*sub_5E8290)() = (int(*)())(0x5E8290);
static int(*sub_66F4E0)() = (int(*)())(0x66F4E0);
static int(*sub_682300)() = (int(*)())(0x682300);
static int(*sub_682F70)() = (int(*)())(0x682F70);
static int(*sub_683010)() = (int(*)())(0x683010);
static int(*sub_687430)() = (int(*)())(0x687430);
static int(*sub_687970)() = (int(*)())(0x687970);
static int(*sub_68A160)() = (int(*)())(0x68A160);
static int(*sub_68A1C0)() = (int(*)())(0x68A1C0);
static int(*sub_68AA80)() = (int(*)())(0x68AA80);
static int(*sub_79CEE0)() = (int(*)())(0x79CEE0);
static int(*sub_868C50)() = (int(*)())(0x868C50);
static int(*sub_869480)() = (int(*)())(0x869480);
static int(*sub_86A1C0)() = (int(*)())(0x86A1C0);
static int(*sub_86BDD0)() = (int(*)())(0x86BDD0);
static int(*sub_90D130)() = (int(*)())(0x90D130);
static int(*sub_944C94)() = (int(*)())(0x944C94);

static int(*sub_944C9F)() = (int(*)())(0x944C9F);
static int(*sub_944CF1)() = (int(*)())(0x944CF1);
static int(*sub_944CFF)() = (int(*)())(0x944CFF);
static int(*sub_944E46)() = (int(*)())(0x944E46);
static int(*sub_9452CA)() = (int(*)())(0x9452CA);  // Free?

static int(__thiscall* sub_682200)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(0x682200);
static int(__thiscall* sub_687B10)(BYTE* _this, char a2) = (int(__thiscall*)(BYTE * _this, char a2))(0x687B10);
static int(__thiscall* sub_6835C0)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(0x6835C0);
static int(__thiscall* sub_6827D0)(BYTE* _this, BYTE* base) = (int(__thiscall*)(BYTE * _this, BYTE * base))(0x6827D0);
static int(__thiscall* sub_49EE70)(BYTE* _this, BYTE* base) = (int(__thiscall*)(BYTE * _this, BYTE * base))(0x49EE70);
static int(__thiscall* sub_68A850)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(0x68A850);

void sub_577020();
int __fastcall sub_5780C0_set_subs_c(BYTE* _this);		// We cheat with a fastcall here (as the one and only param will be passed as ecx). It's really a __thiscall.
void sub_577000();
void sub_578170();
int __fastcall sub_578330_c(int* _this);				// called by league.cpp on 4th May - Cup related
void sub_576C50();
void sub_578660();
void sub_5785B0();		// +48 vtable;

void __declspec(naked) eng_fixture_caller()		// used as a __thiscall -> __cdecl converter
{
	__asm
	{
		mov eax, esp
		push dword ptr[eax + 0x10]
		push dword ptr[eax + 0xC]
		push dword ptr[eax + 0x8]
		push dword ptr[eax + 0x4]
		push ecx
		call AddEng24TeamFixturesWithPlayoffs
		add esp, 0x14
		ret 0x10
	}
}

/*
eng_third VTable at 00969E84:
0. 00 = 00577000
1. 08 = 00578170
2. 28 = 00578330
3. 30 = 00684640
4. 3C = 005770E0		// Fixtures
5. 44 = 00576C50
6. 48 = 005785B0
7. 50 = 0048E180
8. 68 = 00578660
9. 7C = 0048F2D0
10. 8C = 005780C0		// Subs / Promo/Rele Places / etc
11. B4 = 005788C0		// Awards
12. B8 = 00579610
*/
/*
eng_prm.cpp VTable at 00969D1C:
0. 00 = 005735B0
1. 08 = 00574C10		// Eng prm's 0x8 calls the other league's 0x08 ???
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
// B0 = Could this be the relegation one?

// Normally at: 0x969E84
vtable vtable_eng_third((DWORD)&sub_577000, (DWORD)&sub_578170, /*+28*/ (DWORD)&sub_578330_c, 0x684640, (DWORD)&eng_fixture_caller, /*+44*/ (DWORD)&sub_576C50, (DWORD)&sub_5785B0, 0x48E180, (DWORD)&sub_578660, 0x48F2D0, (DWORD)&sub_5780C0_set_subs_c, -1L /*(DWORD)&sub_689C20_relegation_hook*/, 0x5788C0, 0x579610);

void __declspec(naked) sub_576C50()	//+44
{
	__asm
	{
	/*00576C50*/	mov al,byte ptr ss:[esp+0xC]
	/*00576C54*/	push ebx
	/*00576C55*/	push ebp
	/*00576C56*/	push esi
	/*00576C57*/	cmp al,0xFF
	/*00576C59*/	push edi
	/*00576C5A*/	mov esi,ecx
	/*00576C5C*/	jne _00576CFC
	/*00576C62*/	mov al,byte ptr ss:[esp+0x18]
	/*00576C66*/	cmp al,0x5
	/*00576C68*/	jne _00576C87
	/*00576C6A*/	mov eax,dword ptr ds:[esi+0x4]
	/*00576C6D*/	mov ecx,dword ptr ss:[esp+0x14]
	/*00576C71*/	push eax
	/*00576C72*/	push ecx
	/*00576C73*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00576C79*/	call sub_868C50		/*call cm0102.868C50*/
	/*00576C7E*/	pop edi
	/*00576C7F*/	pop esi
	/*00576C80*/	pop ebp
	/*00576C81*/	xor eax,eax
	/*00576C83*/	pop ebx
	/*00576C84*/	ret 0x18
_00576C87:
	/*00576C87*/	test al,al
	/*00576C89*/	jne _00576CAA
	/*00576C8B*/	mov edx,dword ptr ds:[esi+0x4]
	/*00576C8E*/	mov eax,dword ptr ss:[esp+0x14]
	/*00576C92*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00576C98*/	push 0x64
	/*00576C9A*/	push edx
	/*00576C9B*/	push eax
	/*00576C9C*/	call sub_869480		/*call cm0102.869480*/
	/*00576CA1*/	pop edi
	/*00576CA2*/	pop esi
	/*00576CA3*/	pop ebp
	/*00576CA4*/	xor eax,eax
	/*00576CA6*/	pop ebx
	/*00576CA7*/	ret 0x18
_00576CAA:
	/*00576CAA*/	cmp al,0x1
	/*00576CAC*/	jne _00576CD7
	/*00576CAE*/	mov ecx,dword ptr ds:[esi+0x4]
	/*00576CB1*/	mov edx,dword ptr ss:[esp+0x14]
	/*00576CB5*/	push 0x1E
	/*00576CB7*/	push 0x82
	/*00576CBC*/	push 0xA0
	/*00576CC1*/	push ecx
	/*00576CC2*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00576CC8*/	push edx
	/*00576CC9*/	call sub_86BDD0		/*call cm0102.86BDD0*/
	/*00576CCE*/	pop edi
	/*00576CCF*/	pop esi
	/*00576CD0*/	pop ebp
	/*00576CD1*/	xor eax,eax
	/*00576CD3*/	pop ebx
	/*00576CD4*/	ret 0x18
_00576CD7:
	/*00576CD7*/	cmp al,0x3
	/*00576CD9*/	jne _00576DC7
	/*00576CDF*/	mov eax,dword ptr ds:[esi+0x4]
	/*00576CE2*/	mov ecx,dword ptr ss:[esp+0x14]
	/*00576CE6*/	push eax
	/*00576CE7*/	push ecx
	/*00576CE8*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00576CEE*/	call sub_86A1C0		/*call cm0102.86A1C0*/
	/*00576CF3*/	pop edi
	/*00576CF4*/	pop esi
	/*00576CF5*/	pop ebp
	/*00576CF6*/	xor eax,eax
	/*00576CF8*/	pop ebx
	/*00576CF9*/	ret 0x18
_00576CFC:
	/*00576CFC*/	xor edi,edi
	/*00576CFE*/	cmp word ptr ds:[esi+0x3E],di
	/*00576D02*/	jle _00576DC7
	/*00576D08*/	mov bl,byte ptr ss:[esp+0x18]
	/*00576D0C*/	mov ebp,dword ptr ss:[esp+0x14]
	/*00576D10*/	mov dword ptr ss:[esp+0x1C],edi
_00576D14:
	/*00576D14*/	mov edx,dword ptr ds:[esi+0xB1]
	/*00576D1A*/	mov eax,dword ptr ss:[esp+0x1C]
	/*00576D1E*/	cmp dword ptr ds:[edx+eax],ebp
	/*00576D21*/	jne _00576D54
	/*00576D23*/	cmp bl,0x1
	/*00576D26*/	je _00576D71
	/*00576D28*/	test bl,bl
	/*00576D2A*/	jne _00576D4A
	/*00576D2C*/	mov ecx,dword ptr ds:[esi+0x4]
	/*00576D2F*/	push 0xF
	/*00576D31*/	push 0x96
	/*00576D36*/	push 0xA0
	/*00576D3B*/	push ecx
	/*00576D3C*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00576D42*/	push ebp
	/*00576D43*/	call sub_86BDD0		/*call cm0102.86BDD0*/
	/*00576D48*/	jmp _00576D54
_00576D4A:
	/*00576D4A*/	cmp bl,0xFF
	/*00576D4D*/	je _00576DAD
	/*00576D4F*/	cmp bl,0x2
	/*00576D52*/	je _00576DAD
_00576D54:
	/*00576D54*/	movsx edx,word ptr ds:[esi+0x3E]
	/*00576D58*/	mov ecx,dword ptr ss:[esp+0x1C]
	/*00576D5C*/	inc edi
	/*00576D5D*/	add ecx,0x3B
	/*00576D60*/	cmp edi,edx
	/*00576D62*/	mov dword ptr ss:[esp+0x1C],ecx
	/*00576D66*/	jl _00576D14
	/*00576D68*/	pop edi
	/*00576D69*/	pop esi
	/*00576D6A*/	pop ebp
	/*00576D6B*/	xor eax,eax
	/*00576D6D*/	pop ebx
	/*00576D6E*/	ret 0x18
_00576D71:
	/*00576D71*/	mov eax,dword ptr ds:[esi+0x4]
	/*00576D74*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00576D7A*/	push 0x32
	/*00576D7C*/	push eax
	/*00576D7D*/	push ebp
	/*00576D7E*/	call sub_869480		/*call cm0102.869480*/
	/*00576D83*/	lea ecx,dword ptr ds:[edi*0x8]
	/*00576D8A*/	sub ecx,edi
	/*00576D8C*/	lea edx,dword ptr ds:[edi+ecx*0x4]
	/*00576D8F*/	mov ecx,dword ptr ds:[esi+0xB1]
	/*00576D95*/	lea eax,dword ptr ds:[edi+edx*0x2]
	/*00576D98*/	mov edx,dword ptr ss:[esp+0x20]
	/*00576D9C*/	pop edi
	/*00576D9D*/	pop esi
	/*00576D9E*/	mov byte ptr ds:[eax+ecx+0x37],0x0
	/*00576DA3*/	pop ebp
	/*00576DA4*/	mov byte ptr ds:[edx],0x1
	/*00576DA7*/	xor eax,eax
	/*00576DA9*/	pop ebx
	/*00576DAA*/	ret 0x18
_00576DAD:
	/*00576DAD*/	lea eax,dword ptr ds:[edi*0x8]
	/*00576DB4*/	sub eax,edi
	/*00576DB6*/	lea ecx,dword ptr ds:[edi+eax*0x4]
	/*00576DB9*/	mov eax,dword ptr ds:[esi+0xB1]
	/*00576DBF*/	lea edx,dword ptr ds:[edi+ecx*0x2]
	/*00576DC2*/	mov byte ptr ds:[edx+eax+0x37],0xFE
_00576DC7:
	/*00576DC7*/	pop edi
	/*00576DC8*/	pop esi
	/*00576DC9*/	pop ebp
	/*00576DCA*/	xor eax,eax
	/*00576DCC*/	pop ebx
	/*00576DCD*/	ret 0x18
	}
}

void eng_third_init_additional()
{
	if (NorthernConferenceDivisionCompID != -1L)		// If the Northern league is missing a short acronym add one
	{
		if (_stricmp(get_comp(NorthernConferenceDivisionCompID)->ClubCompNameThreeLetter, "") == 0)
			strcpy(get_comp(NorthernConferenceDivisionCompID)->ClubCompNameThreeLetter, "NLN");
	}

	if (SouthernConferenceDivisionCompID != -1L)		// If the Southern league is missing a short acronym add one
	{
		if (_stricmp(get_comp(SouthernConferenceDivisionCompID)->ClubCompNameThreeLetter, "") == 0)
			strcpy(get_comp(SouthernConferenceDivisionCompID)->ClubCompNameThreeLetter, "NLS");
	}
}

BYTE *eng_third_init(BYTE* _this, WORD year, cm3_club_comps* comp) 
{
	eng_third_init_additional();
	sub_682200(_this);
	comp_stats* data = (comp_stats*)_this;

	BYTE playOffPlaces = 1;
	LeagueInfo* leagueInfo = get_league_info(comp->ClubCompID);
	if (leagueInfo)
		playOffPlaces = leagueInfo->PlayoffPlaces;

	data->competition_db = comp;
	data->comp_vtable = (DWORD*)vtable_eng_third.vtable_ptr;
	data->year = year;
	data->min_stadium_capacity = 4000;
	data->min_stadium_seats = 500;
	data->rules = 0x9;
	int loaded = sub_687B10(_this, 1);
	if (loaded) 
		return _this;
	data->f68 = -1;
	data->current_stage = -1;
	data->num_stages = (playOffPlaces == 0) ? 0 : 1;
	data->stages = (DWORD*)sub_944E46_malloc(data->num_stages * 4);
	sub_5780C0_set_subs_c(_this);
	AddTeams(_this);
	sub_6835C0(_this);
	BYTE* ebx = 0;
	sub_6827D0(_this, ebx);
	BYTE* pMem2 = (BYTE*)sub_944CF1_operator_new(0x5CE);
	BYTE unk1 = 1;
	sub_49EE70(pMem2, _this);
	unk1 = 0;
	data->f8 = (DWORD*)pMem2;
	sub_68A850(_this);
	return _this;
}

void __declspec(naked) sub_576DD0_eng_third_init()
{
	__asm
	{
					pushad
					call eng_third_init_additional
					popad

	/*00576DE5*/	sub esp,0x214
	/*00576DEB*/	push ebx
	/*00576DEC*/	push esi
	/*00576DED*/	mov esi,ecx
	/*00576DEF*/	mov dword ptr ss:[esp+0xC],esi
	/*00576DF3*/	call sub_682200		/*call cm0102.682200*/
	/*00576DF8*/	mov ecx,dword ptr ss:[esp+0x224]
	/*00576DFF*/	mov ax,word ptr ss:[esp+0x220]
	/*00576E07*/	xor ebx,ebx
	/*00576E09*/	mov dword ptr ds:[esi+0x4],ecx
	/*00576E0C*/	push 0x1
	/*00576E0E*/	mov ecx,esi
	/*00576E10*/	mov dword ptr ss:[esp+0x21C],ebx
	/*00576E17*/	// mov dword ptr ds:[esi],0x969E84		/*mov dword ptr ds:[esi],cm0102.969E84*/
					
					push eax
					mov eax, dword ptr[vtable_eng_third.vtable_ptr]
					mov dword ptr ds:[esi], eax
					pop eax

	/*00576E1D*/	mov word ptr ds:[esi+0x40],ax
	/*00576E21*/	mov word ptr ds:[esi+0xE2],0x1770
	/*00576E2A*/	mov word ptr ds:[esi+0xE4],0x3E8
	/*00576E33*/	mov byte ptr ds:[esi+0x50],0x9							// <---- was 9 - davdav's is 11
	/*00576E37*/	call sub_687B10		/*call cm0102.687B10*/
	/*00576E3C*/	test eax,eax
	/*00576E3E*/	jne _00576FE3
	/*00576E44*/	or eax,0xFFFFFFFF
	/*00576E47*/	push 0x4
	/*00576E49*/	mov byte ptr ds:[esi+0x44],al
	/*00576E4C*/	mov dword ptr ds:[esi+0x30],eax
	/*00576E4F*/	mov dword ptr ds:[esi+0x2C],0x1							// <---- Number of fixture schedule sections (1)
	/*00576E56*/	call sub_944E46_malloc		/*call cm0102.944E46*/
	/*00576E5B*/	add esp,0x4
	/*00576E5E*/	mov ecx,esi
	/*00576E60*/	mov dword ptr ds:[esi+0xC],eax
	/*00576E63*/	call sub_5780C0_set_subs_c		/*call cm0102.5780C0*/	// +0x8C
	/*00576E68*/	test eax,eax
	/*00576E6A*/	jne _00576E9C
	/*00576E6C*/	lea edx,dword ptr ss:[esp+0x10]
	/*00576E70*/	lea eax,dword ptr ss:[esp+0x110]
	/*00576E77*/	push edx
	/*00576E78*/	push eax
	/*00576E79*/	push ebx
	/*00576E7A*/	push ebx
	/*00576E7B*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00576E80*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00576E85*/	add esp,0x14
	/*00576E88*/	lea ecx,dword ptr ss:[esp+0x10]
	/*00576E8C*/	lea edx,dword ptr ss:[esp+0x110]
	/*00576E93*/	push 0x4E
	/*00576E95*/	push ecx
	/*00576E96*/	push edx
	/*00576E97*/	jmp _00576FAC
_00576E9C:
	/*00576E9C*/	mov ecx,esi
	/*00576E9E*/	// call sub_577F70_add_teams		/*call cm0102.577F70*/
					
					push ecx
					call AddTeams
					add esp, 0x4

	/*00576EA3*/	test eax,eax
	/*00576EA5*/	jne _00576ED6
	/*00576EA7*/	lea eax,dword ptr ss:[esp+0x110]
	/*00576EAE*/	lea ecx,dword ptr ss:[esp+0x10]
	/*00576EB2*/	push eax
	/*00576EB3*/	push ecx
	/*00576EB4*/	push ebx
	/*00576EB5*/	push ebx
	/*00576EB6*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00576EBB*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00576EC0*/	add esp,0x14
	/*00576EC3*/	lea edx,dword ptr ss:[esp+0x110]
	/*00576ECA*/	lea eax,dword ptr ss:[esp+0x10]
	/*00576ECE*/	push 0x55
	/*00576ED0*/	push edx
	/*00576ED1*/	jmp _00576FAB
_00576ED6:
	/*00576ED6*/	mov ecx,esi
	/*00576ED8*/	call sub_6835C0		/*call cm0102.6835C0*/
	/*00576EDD*/	test eax,eax
	/*00576EDF*/	jne _00576F11
	/*00576EE1*/	lea ecx,dword ptr ss:[esp+0x110]
	/*00576EE8*/	lea edx,dword ptr ss:[esp+0x10]
	/*00576EEC*/	push ecx
	/*00576EED*/	push edx
	/*00576EEE*/	push ebx
	/*00576EEF*/	push ebx
	/*00576EF0*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00576EF5*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00576EFA*/	add esp,0x14
	/*00576EFD*/	lea eax,dword ptr ss:[esp+0x110]
	/*00576F04*/	lea ecx,dword ptr ss:[esp+0x10]
	/*00576F08*/	push 0x5C
	/*00576F0A*/	push eax
	/*00576F0B*/	push ecx
	/*00576F0C*/	jmp _00576FAC
_00576F11:
	/*00576F11*/	push ebx
	/*00576F12*/	mov ecx,esi
	/*00576F14*/	call sub_6827D0		/*call cm0102.6827D0*/
	/*00576F19*/	test eax,eax
	/*00576F1B*/	jne _00576F4A
	/*00576F1D*/	lea edx,dword ptr ss:[esp+0x110]
	/*00576F24*/	lea eax,dword ptr ss:[esp+0x10]
	/*00576F28*/	push edx
	/*00576F29*/	push eax
	/*00576F2A*/	push ebx
	/*00576F2B*/	push ebx
	/*00576F2C*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00576F31*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00576F36*/	add esp,0x14
	/*00576F39*/	lea ecx,dword ptr ss:[esp+0x110]
	/*00576F40*/	lea edx,dword ptr ss:[esp+0x10]
	/*00576F44*/	push 0x65
	/*00576F46*/	push ecx
	/*00576F47*/	push edx
	/*00576F48*/	jmp _00576FAC
_00576F4A:
	/*00576F4A*/	push 0x5CE
	/*00576F4F*/	call sub_944CF1		/*call cm0102.944CF1*/
	/*00576F54*/	add esp,0x4
	/*00576F57*/	mov dword ptr ss:[esp+0x8],eax
	/*00576F5B*/	cmp eax,ebx
	/*00576F5D*/	mov byte ptr ss:[esp+0x218],0x1
	/*00576F65*/	je _00576F71
	/*00576F67*/	push esi
	/*00576F68*/	mov ecx,eax
	/*00576F6A*/	call sub_49EE70		/*call cm0102.49EE70*/
	/*00576F6F*/	jmp _00576F73
_00576F71:
	/*00576F71*/	xor eax,eax
_00576F73:
	/*00576F73*/	cmp eax,ebx
	/*00576F75*/	mov byte ptr ss:[esp+0x218],bl
	/*00576F7C*/	mov dword ptr ds:[esi+0x8],eax
	/*00576F7F*/	jne _00576FDC
	/*00576F81*/	lea eax,dword ptr ss:[esp+0x110]
	/*00576F88*/	lea ecx,dword ptr ss:[esp+0x10]
	/*00576F8C*/	push eax
	/*00576F8D*/	push ecx
	/*00576F8E*/	push ebx
	/*00576F8F*/	push ebx
	/*00576F90*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00576F95*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00576F9A*/	add esp,0x14
	/*00576F9D*/	lea edx,dword ptr ss:[esp+0x110]
	/*00576FA4*/	lea eax,dword ptr ss:[esp+0x10]
	/*00576FA8*/	push 0x6D
	/*00576FAA*/	push edx
_00576FAB:
	/*00576FAB*/	push eax
_00576FAC:
	/*00576FAC*/	call sub_90D130		/*call cm0102.90D130*/
	/*00576FB1*/	push eax
	/*00576FB2*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00576FB7*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00576FBC*/	call sub_944C9F_sprintf		/*call cm0102.944C9F*/
	/*00576FC1*/	push ebx
	/*00576FC2*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00576FC7*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00576FCC*/	call sub_5E8290		/*call cm0102.5E8290*/
	/*00576FD1*/	add esp,0x24
	/*00576FD4*/	mov dword ptr ds:[0xB67A34],ebx
	/*00576FDA*/	jmp _00576FE3
_00576FDC:
	/*00576FDC*/	mov ecx,esi
	/*00576FDE*/	call sub_68A850		/*call cm0102.68A850*/
_00576FE3:
	/*00576FEA*/	mov eax,esi
	/*00576FEC*/	pop esi
	/*00576FED*/	pop ebx
	/*00576FF5*/	add esp,0x214
	/*00576FFB*/	ret 0x8
	}
}

void __declspec(naked) eng_third_init_c()		// used as a __thiscall -> __cdecl converter
{
	__asm
	{
		//jmp sub_576DD0_eng_third_init

		mov eax, esp
		push dword ptr[eax + 0x8]
		push dword ptr[eax + 0x4]
		push ecx
		call eng_third_init
		add esp, 0xc
		ret 8
	}
}

void __declspec(naked) sub_577000()			// Not sure when called, if ever?
{
	__asm
	{
	/*00577000*/	push esi
	/*00577001*/	mov esi,ecx
	/*00577003*/	call sub_577020		/*call cm0102.577020*/
	/*00577008*/	test byte ptr ss:[esp+0x8],0x1
	/*0057700D*/	je _00577018
	/*0057700F*/	push esi
	/*00577010*/	call sub_944C94		/*call cm0102.944C94*/
	/*00577015*/	add esp,0x4
_00577018:
	/*00577018*/	mov eax,esi
	/*0057701A*/	pop esi
	/*0057701B*/	ret 0x4
	}
}

void __declspec(naked) sub_577020()			// Not sure when called, if ever?
{
	__asm
	{
	/*0057702D*/	push eax
	/*00577035*/	push ecx
	/*00577036*/	push esi
	/*00577037*/	mov esi,ecx
	/*00577039*/	push edi
	/*0057703A*/	mov dword ptr ss:[esp+0x8],esi
	/*0057703E*/	//mov dword ptr ds:[esi],0x969E84		/*mov dword ptr ds:[esi],cm0102.969E84*/
					
					push eax
					mov eax, dword ptr[vtable_eng_third.vtable_ptr]
					mov dword ptr ds:[esi], eax
					pop eax

	/*00577044*/	push 0x0
	/*00577046*/	mov dword ptr ss:[esp+0x18],0x0
	/*0057704E*/	call sub_687970		/*call cm0102.687970*/
	/*00577053*/	mov eax,dword ptr ds:[esi+0xBA]
	/*00577059*/	test eax,eax
	/*0057705B*/	je _00577070
	/*0057705D*/	push eax
	/*0057705E*/	call sub_9452CA		/*call cm0102.9452CA*/
	/*00577063*/	add esp,0x4
	/*00577066*/	mov dword ptr ds:[esi+0xBA],0x0
_00577070:
	/*00577070*/	mov eax,dword ptr ds:[esi+0x30]
	/*00577073*/	xor edi,edi
	/*00577075*/	test eax,eax
	/*00577077*/	jl _00577091
_00577079:
	/*00577079*/	mov eax,dword ptr ds:[esi+0xC]
	/*0057707C*/	mov ecx,dword ptr ds:[eax+edi*0x4]
	/*0057707F*/	test ecx,ecx
	/*00577081*/	je _00577089
	/*00577083*/	mov edx,dword ptr ds:[ecx]
	/*00577085*/	push 0x1
	/*00577087*/	call dword ptr ds:[edx]
_00577089:
	/*00577089*/	mov eax,dword ptr ds:[esi+0x30]
	/*0057708C*/	inc edi
	/*0057708D*/	cmp edi,eax
	/*0057708F*/	jle _00577079
_00577091:
	/*00577091*/	mov eax,dword ptr ds:[esi+0xC]
	/*00577094*/	test eax,eax
	/*00577096*/	je _005770A8
	/*00577098*/	push eax
	/*00577099*/	call sub_9452CA		/*call cm0102.9452CA*/
	/*0057709E*/	add esp,0x4
	/*005770A1*/	mov dword ptr ds:[esi+0xC],0x0
_005770A8:
	/*005770A8*/	mov edi,dword ptr ds:[esi+0x8]
	/*005770AB*/	test edi,edi
	/*005770AD*/	je _005770BF
	/*005770AF*/	mov ecx,edi
	/*005770B1*/	call sub_49F450		/*call cm0102.49F450*/
	/*005770B6*/	push edi
	/*005770B7*/	call sub_944C94		/*call cm0102.944C94*/
	/*005770BC*/	add esp,0x4
_005770BF:
	/*005770BF*/	mov ecx,esi
	/*005770C1*/	mov dword ptr ss:[esp+0x14],0xFFFFFFFF
	/*005770C9*/	call sub_682300		/*call cm0102.682300*/
	/*005770D2*/	pop edi
	/*005770D3*/	pop esi
	/*005770DB*/	add esp,0x10
	/*005770DE*/	ret
	}
}

int __fastcall sub_5780C0_set_subs_c(BYTE* _this)				// 0x8C
{
	BYTE* comp = (BYTE*)*(DWORD*)(_this + 4);
	DWORD CompID = *(DWORD*)(comp);
	dprintf("sub_5780C0_set_subs_c - CompID: %08X this: %08X\n", CompID, _this);

	*(WORD*)(_this + 0x3C) = 2;		// Playoff related? (2)
	_this[0xC2] = 3;
	_this[0xC3] = 1;
	_this[0xC4] = 2;
	_this[0x42] = 1;
	_this[0xC5] = 1;
	_this[0xC6] = 2;
	_this[0xC7] = 3;
	_this[0xBE] = 1;		// Promotion Places
	_this[0xBF] = 0;		// Play off places
	_this[0xC0] = 0;		// Relegation Play off places
	_this[0xC1] = 1;		// Relegation places

	*(DWORD*)(_this + 0x1C) = -1L;		// Promotion League
	*(DWORD*)(_this + 0x20) = -1L;		// Relegation League

	//bool includingConference = ((*(BYTE*)(*(DWORD*)(*((DWORD*)_this + 1) + 93) + 284) & 4) != 0);
	cm3_nations *nation = (cm3_nations*)*(DWORD*)(comp + 0x5D);
	bool includingConference = ((nation->NationLeagueSelected & 4) == 4);		// Normally either 2 (no conf) or 6 (conf)

	LeagueInfo *leagueInfo = get_league_info(CompID);

	if (leagueInfo)
	{
		dprintf("Generic League Setup - %s (Promo: %08X Rele: %08X)\n", leagueInfo->Name, leagueInfo->PromotionComp, leagueInfo->RelegationComp);
		_this[0xBE] = leagueInfo->PromotionPlaces;
		_this[0xBF] = leagueInfo->PlayoffPlaces;
		_this[0xC0] = leagueInfo->RelegationPlayOffPlaces;
		_this[0xC1] = leagueInfo->RelegationPlaces;

		*(DWORD*)(_this + 0x1C) = leagueInfo->PromotionComp ? leagueInfo->PromotionComp->ClubCompID : -1L;
		*(DWORD*)(_this + 0x20) = leagueInfo->RelegationComp ? leagueInfo->RelegationComp->ClubCompID : -1L;
	}

	if (CompID == ThirdDivisionCompID)
	{
		_this[0xBE] = 3;		// Promotion Places
		_this[0xBF] = 4;		// Play off places
		_this[0xC1] = 1;		//includingConference ? 2 : 1;		// Relegation places

		*(DWORD*)(_this + 0x1C) = SecondDivisionCompID;
		*(DWORD*)(_this + 0x20) = includingConference ? ConferenceDivisionCompID : -1L;
	}

	if (CompID == ConferenceDivisionCompID)
	{
		_this[0xBE] = 1;		// Promotion Places
		_this[0xBF] = 6;		// Play off places
		_this[0xC1] = 4;		// Relegation places

		*(DWORD*)(_this + 0x1C) = ThirdDivisionCompID;
		*(DWORD*)(_this + 0x20) = -1L;
	}

	if (CompID == NorthernConferenceDivisionCompID)
	{
		_this[0xBE] = 1;		// Promotion Places
		_this[0xBF] = 4;		// Play off places
		_this[0xC1] = 4;		// Relegation places

		*(DWORD*)(_this + 0x1C) = ConferenceDivisionCompID;
		*(DWORD*)(_this + 0x20) = -1L; //ALowerDivisionCompID;
	}

	if (CompID == SouthernConferenceDivisionCompID)
	{
		_this[0xBE] = 1;		// Promotion Places
		_this[0xBF] = 4;		// Play off places
		_this[0xC1] = 4;		// Relegation places

		*(DWORD*)(_this + 0x1C) = ConferenceDivisionCompID;
		*(DWORD*)(_this + 0x20) = -1L;
	}

	_this[0x52] = 2;
	_this[0x4A] = 3;		// Subs Used
	_this[0x49] = 5;		// Subs Named

	//call vtable +3C which is actually add fixtures function
	DWORD vtable = *(DWORD*)_this;
	*(DWORD*)(_this + 0xBA) = (*(int(__thiscall**)(BYTE*, int, BYTE*, BYTE*, DWORD))(vtable + 0x3C))(_this, -1, _this + 0xA9, _this + 0x3A, 0);		// Fixtures saved to 0xBA
	
	return 1;
}

void __declspec(naked) sub_conference_subs_56EDE0()
{
	__asm
	{
	/*0056EDE0*/	push ebx
	/*0056EDE1*/	push esi
	/*0056EDE2*/	mov esi,ecx
	/*0056EDE4*/	mov al,0x3
	/*0056EDE6*/	mov ecx,0x2
	/*0056EDEB*/	mov ebx,0x1
	/*0056EDF0*/	mov word ptr ds:[esi+0x3C],cx				// Playoff related? (2)
	/*0056EDF4*/	mov byte ptr ds:[esi+0xC4],cl
	/*0056EDFA*/	mov byte ptr ds:[esi+0xC6],cl
	/*0056EE00*/	xor ecx,ecx
	/*0056EE02*/	mov byte ptr ds:[esi+0xC2],al
	/*0056EE08*/	mov byte ptr ds:[esi+0xC3],bl
	/*0056EE0E*/	mov byte ptr ds:[esi+0x42],bl
	/*0056EE11*/	mov byte ptr ds:[esi+0xC5],bl
	/*0056EE17*/	mov byte ptr ds:[esi+0xC7],al
	/*0056EE1D*/	mov byte ptr ds:[esi+0xBE],1				// Promotion (1)
	/*0056EE23*/	mov byte ptr ds:[esi+0xBF],0				// Play off (0)
	/*0056EE29*/	mov byte ptr ds:[esi+0xC0],0				// Relegation Playoff (0)
	/*0056EE2F*/	mov byte ptr ds:[esi+0xC1],4				// Relegation (3)
	/*0056EE35*/	mov edx,dword ptr ds:[0x9CF5C8]				// [9cf5c8] = English Third Division
	/*0056EE3B*/	push ecx
	/*0056EE3C*/	mov dword ptr ds:[esi+0x1C],edx
	/*0056EE3F*/	lea ecx,dword ptr ds:[esi+0x3A]
	/*0056EE42*/	lea edx,dword ptr ds:[esi+0xA9]
	/*0056EE48*/	mov byte ptr ds:[esi+0x4A],al
	/*0056EE4B*/	mov eax,dword ptr ds:[esi]
	/*0056EE4D*/	push ecx
	/*0056EE4E*/	push edx
	/*0056EE4F*/	push 0xFFFFFFFF
	/*0056EE51*/	mov ecx,esi

					push eax
					mov eax, dword ptr [NorthernConferenceDivisionCompID]
	/*0056EE53*/	mov dword ptr ds:[esi+0x20], eax // 0xffffffff
					pop eax

	/*0056EE5A*/	mov byte ptr ds:[esi+0x49],0x5
	/*0056EE5E*/	mov byte ptr ds:[esi+0xC5],bl
	/*0056EE64*/	call dword ptr ds:[eax+0x3C]
	/*0056EE67*/	mov dword ptr ds:[esi+0xBA],eax
	/*0056EE6D*/	mov eax,ebx
	/*0056EE6F*/	pop esi
	/*0056EE70*/	pop ebx
	/*0056EE71*/	ret
	}
}
void PrePlus8Function(comp* comp_ptr)
{
	dprintf("sub_578170 (+8 Function) - CompID: %08X %s\n", comp_ptr->competition_db->ClubCompID, comp_ptr->competition_db->ClubCompName);
}

void __declspec(naked) sub_578170()		// 0x8 in vtable
{
	__asm 
	{
		pushad
		push ecx
		call PrePlus8Function
		add esp, 4
		popad
	}
	__asm
	{
	/*00578170*/	sub esp,0x200
	/*00578176*/	push ebx
	/*00578177*/	push esi
	/*00578178*/	mov esi,ecx
	/*0057817A*/	xor ebx,ebx
	/*0057817C*/	push ebx
	/*0057817D*/	mov dword ptr ds:[esi+0x4C],ebx
	/*00578180*/	call sub_687970		/*call cm0102.687970*/
	/*00578185*/	mov eax,dword ptr ds:[esi+0xBA]
	/*0057818B*/	cmp eax,ebx
	/*0057818D*/	je _0057819E
	/*0057818F*/	push eax
	/*00578190*/	call sub_9452CA		/*call cm0102.9452CA*/
	/*00578195*/	add esp,0x4
	/*00578198*/	mov dword ptr ds:[esi+0xBA],ebx
_0057819E:
	/*0057819E*/	mov ecx,dword ptr ds:[esi+0x8]
	/*005781A1*/	cmp ecx,ebx
	/*005781A3*/	je _005781AC
	/*005781A5*/	push 0x1
	/*005781A7*/	call sub_4A1C50		/*call cm0102.4A1C50*/
_005781AC:
	/*005781AC*/	mov eax,dword ptr ds:[esi+0x30]
	/*005781AF*/	push edi
	/*005781B0*/	xor edi,edi
	/*005781B2*/	cmp eax,ebx
	/*005781B4*/	jl _005781CE
_005781B6:
	/*005781B6*/	mov eax,dword ptr ds:[esi+0xC]
	/*005781B9*/	mov ecx,dword ptr ds:[eax+edi*0x4]
	/*005781BC*/	cmp ecx,ebx
	/*005781BE*/	je _005781C6
	/*005781C0*/	mov edx,dword ptr ds:[ecx]
	/*005781C2*/	push 0x1
	/*005781C4*/	call dword ptr ds:[edx]
_005781C6:
	/*005781C6*/	mov eax,dword ptr ds:[esi+0x30]
	/*005781C9*/	inc edi
	/*005781CA*/	cmp edi,eax
	/*005781CC*/	jle _005781B6
_005781CE:
	/*005781CE*/	mov eax,dword ptr ds:[esi]
	/*005781D0*/	inc word ptr ds:[esi+0x40]
	/*005781D4*/	mov ecx,esi
	/*005781D6*/	mov dword ptr ds:[esi+0x30],0xFFFFFFFF
	/*005781DD*/	call dword ptr ds:[eax+0x8C]				// Subs Func
	/*005781E3*/	test eax,eax
	/*005781E5*/	pop edi
	/*005781E6*/	jne _0057821A
	/*005781E8*/	lea ecx,dword ptr ss:[esp+0x8]
	/*005781EC*/	lea edx,dword ptr ss:[esp+0x108]
	/*005781F3*/	push ecx
	/*005781F4*/	push edx
	/*005781F5*/	push ebx
	/*005781F6*/	push ebx
	/*005781F7*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*005781FC*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00578201*/	add esp,0x14
	/*00578204*/	lea eax,dword ptr ss:[esp+0x8]
	/*00578208*/	lea ecx,dword ptr ss:[esp+0x108]
	/*0057820F*/	push 0x26C
	/*00578214*/	push eax
	/*00578215*/	jmp _005782C9
_0057821A:
	/*0057821A*/	mov ecx,esi
	/*0057821C*/	//call sub_577F70_add_teams		/*call cm0102.577F70*/
					
					push ecx
					call AddTeams
					add esp, 0x4

	/*00578221*/	test eax,eax
	/*00578223*/	jne _00578255
	/*00578225*/	lea edx,dword ptr ss:[esp+0x108]
	/*0057822C*/	lea eax,dword ptr ss:[esp+0x8]
	/*00578230*/	push edx
	/*00578231*/	push eax
	/*00578232*/	push ebx
	/*00578233*/	push ebx
	/*00578234*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00578239*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*0057823E*/	add esp,0x14
	/*00578241*/	lea ecx,dword ptr ss:[esp+0x108]
	/*00578248*/	lea edx,dword ptr ss:[esp+0x8]
	/*0057824C*/	push 0x273
	/*00578251*/	push ecx
	/*00578252*/	push edx
	/*00578253*/	jmp _005782CA
_00578255:
	/*00578255*/	mov ecx,esi
	/*00578257*/	call sub_6835C0		/*call cm0102.6835C0*/
	/*0057825C*/	test eax,eax
	/*0057825E*/	jne _00578290
	/*00578260*/	lea eax,dword ptr ss:[esp+0x108]
	/*00578267*/	lea ecx,dword ptr ss:[esp+0x8]
	/*0057826B*/	push eax
	/*0057826C*/	push ecx
	/*0057826D*/	push ebx
	/*0057826E*/	push ebx
	/*0057826F*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00578274*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00578279*/	add esp,0x14
	/*0057827C*/	lea edx,dword ptr ss:[esp+0x108]
	/*00578283*/	lea eax,dword ptr ss:[esp+0x8]
	/*00578287*/	push 0x279
	/*0057828C*/	push edx
	/*0057828D*/	push eax
	/*0057828E*/	jmp _005782CA
_00578290:
	/*00578290*/	push ebx
	/*00578291*/	mov ecx,esi
	/*00578293*/	call sub_6827D0		/*call cm0102.6827D0*/
	/*00578298*/	test eax,eax
	/*0057829A*/	jne _00578301
	/*0057829C*/	lea ecx,dword ptr ss:[esp+0x108]
	/*005782A3*/	lea edx,dword ptr ss:[esp+0x8]
	/*005782A7*/	push ecx
	/*005782A8*/	push edx
	/*005782A9*/	push ebx
	/*005782AA*/	push ebx
	/*005782AB*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*005782B0*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*005782B5*/	add esp,0x14
	/*005782B8*/	lea eax,dword ptr ss:[esp+0x108]
	/*005782BF*/	lea ecx,dword ptr ss:[esp+0x8]
	/*005782C3*/	push 0x280
	/*005782C8*/	push eax
_005782C9:
	/*005782C9*/	push ecx
_005782CA:
	/*005782CA*/	call sub_90D130		/*call cm0102.90D130*/
	/*005782CF*/	push eax
	/*005782D0*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*005782D5*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*005782DA*/	call sub_944C9F_sprintf		/*call cm0102.944C9F*/
	/*005782DF*/	push ebx
	/*005782E0*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*005782E5*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*005782EA*/	call sub_5E8290		/*call cm0102.5E8290*/
	/*005782EF*/	add esp,0x24
	/*005782F2*/	mov dword ptr ds:[0xB67A34],ebx
	/*005782F8*/	pop esi
	/*005782F9*/	pop ebx
	/*005782FA*/	add esp,0x200
	/*00578300*/	ret
_00578301:
	/*00578301*/	mov edx,dword ptr ds:[esi]
	/*00578303*/	mov ecx,esi
	/*00578305*/	call dword ptr ds:[edx+0x5C]
	/*00578308*/	mov ecx,esi
	/*0057830A*/	call sub_68AA80		/*call cm0102.68AA80*/
	/*0057830F*/	mov eax,dword ptr ds:[esi+0x4]
	/*00578312*/	mov ecx,dword ptr ds:[0xB74340]
	/*00578318*/	push eax
	/*00578319*/	call sub_79CEE0		/*call cm0102.79CEE0*/
	/*0057831E*/	pop esi
	/*0057831F*/	pop ebx
	/*00578320*/	add esp,0x200
	/*00578326*/	ret
	}
}

int __fastcall sub_578330_c(int* _this)  // called by league.cpp on 4th May
{
	int result = 0;
	int v1 = _this[12];
	
	if (v1 < _this[11] - 1)
	{
		result = v1 + 1;
		_this[12] = result;
		if (!result)
		{
			BYTE* _thisPtr = (BYTE*)_this;
			dprintf("sub_578330_c - playoff places: %d\n", _thisPtr[0xBF]);
			HandlePlayoffSelection((BYTE*)_this);	// Was sub_5783C0 originally or DE844E in davdav for 6 playoff places
		}
	}
	else
		dprintf("sub_578330_c - Something went wrong!");
	
	return result;
}

void __declspec(naked) sub_5785B0()		// +48 vtable
{
	__asm
	{
	/*005785B0*/	mov eax,dword ptr ss:[esp+0x8]
	/*005785B4*/	mov edx,dword ptr ss:[esp+0xC]
	/*005785B8*/	push esi
	/*005785B9*/	mov esi,dword ptr ss:[esp+0x28]
	/*005785BD*/	cmp al,0x1
	/*005785BF*/	push edi
	/*005785C0*/	jne _0057862A
	/*005785C2*/	test dl,dl
	/*005785C4*/	jne _0057862A
	/*005785C6*/	test esi,esi
	/*005785C8*/	jne _0057862A
	/*005785CA*/	mov eax,dword ptr ss:[esp+0xC]
	/*005785CE*/	lea ecx,dword ptr ds:[eax+eax*0x8]
	/*005785D1*/	shl ecx,0x4
	/*005785D4*/	add ecx,eax
	/*005785D6*/	lea esi,dword ptr ds:[eax+ecx*0x4]
	/*005785D9*/	mov ecx,dword ptr ds:[0xAE23B4]
	/*005785DF*/	movsx eax,byte ptr ds:[esi+ecx+0x52]
	/*005785E4*/	lea edx,dword ptr ds:[esi+ecx+0x38]
	/*005785E8*/	push edx
	/*005785E9*/	push eax
	/*005785EA*/	push eax
	/*005785EB*/	push 0x989C18		/*push cm0102.989C18*/		// {}<%s - Team Name(e.g.Brighton)>{} win promotion
	/*005785F0*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*005785F5*/	call sub_66F4E0		/*call cm0102.66F4E0*/
	/*005785FA*/	mov edi,dword ptr ss:[esp+0x44]
	/*005785FE*/	add esp,0x14
	/*00578601*/	mov ecx,edi
	/*00578603*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*00578608*/	call sub_4AE660		/*call cm0102.4AE660*/
	/*0057860D*/	mov eax,dword ptr ds:[0xAE23B4]
	/*00578612*/	mov ecx,edi
	/*00578614*/	add eax,esi
	/*00578616*/	push eax
	/*00578617*/	add eax,0x38
	/*0057861A*/	push 0x7D5
	/*0057861F*/	push eax
	/*00578620*/	call sub_4AE8A0		/*call cm0102.4AE8A0*/
	/*00578625*/	pop edi
	/*00578626*/	pop esi
	/*00578627*/	ret 0x28
_0057862A:
	/*0057862A*/	mov edi,dword ptr ss:[esp+0x30]
	/*0057862E*/	push edi
	/*0057862F*/	push esi
	/*00578630*/	mov esi,dword ptr ss:[esp+0x30]
	/*00578634*/	push esi
	/*00578635*/	mov esi,dword ptr ss:[esp+0x2C]
	/*00578639*/	push 0x0
	/*0057863B*/	push esi
	/*0057863C*/	mov esi,dword ptr ss:[esp+0x30]
	/*00578640*/	push esi
	/*00578641*/	mov esi,dword ptr ss:[esp+0x30]
	/*00578645*/	push esi
	/*00578646*/	push edx
	/*00578647*/	mov edx,dword ptr ss:[esp+0x2C]
	/*0057864B*/	push eax
	/*0057864C*/	push edx
	/*0057864D*/	call sub_48C6D0		/*call cm0102.48C6D0*/
	/*00578652*/	pop edi
	/*00578653*/	pop esi
	/*00578654*/	ret 0x28
	}
}

void __declspec(naked) sub_578660()
{
	__asm
	{
	/*00578660*/	mov eax,dword ptr ss:[esp+0x4]
	/*00578664*/	mov ecx,dword ptr ds:[ecx+0x8]
	/*00578667*/	push ebx
	/*00578668*/	push esi
	/*00578669*/	push eax
	/*0057866A*/	call sub_4A4850		/*call cm0102.4A4850*/
	/*0057866F*/	mov cl,byte ptr ss:[esp+0x10]
	/*00578673*/	mov esi,eax
	/*00578675*/	cmp cl,0xFF
	/*00578678*/	jne _005786B4
	/*0057867A*/	mov bl,byte ptr ss:[esp+0x18]
	/*0057867E*/	cmp bl,0x4
	/*00578681*/	jb _0057868A
	/*00578683*/	cmp bl,0x7
	/*00578686*/	ja _0057868A
	/*00578688*/	mov bl,0x4
_0057868A:
	/*0057868A*/	mov cl,byte ptr ss:[esp+0x1C]
	/*0057868E*/	cmp cl,0x4
	/*00578691*/	jb _00578762
	/*00578697*/	cmp cl,0x7
	/*0057869A*/	ja _00578762
	/*005786A0*/	mov dl,byte ptr ss:[esp+0x14]
	/*005786A4*/	mov cl,0x7
	/*005786A6*/	mov byte ptr ds:[esi+0x73],dl
	/*005786A9*/	mov byte ptr ds:[esi+0x74],bl
	/*005786AC*/	mov byte ptr ds:[esi+0x75],cl
	/*005786AF*/	pop esi
	/*005786B0*/	pop ebx
	/*005786B1*/	ret 0x14
_005786B4:
	/*005786B4*/	test cl,cl
	/*005786B6*/	jne _0057875A
	/*005786BC*/	mov ecx,dword ptr ss:[esp+0x18]
	/*005786C0*/	and ecx,0xFF
	/*005786C6*/	dec ecx
	/*005786C7*/	je _005786D7
	/*005786C9*/	dec ecx
	/*005786CA*/	je _005786D3
	/*005786CC*/	dec ecx
	/*005786CD*/	jne _005786DB
	/*005786CF*/	mov bl,0x6
	/*005786D1*/	jmp _005786DF
_005786D3:
	/*005786D3*/	mov bl,0x5
	/*005786D5*/	jmp _005786DF
_005786D7:
	/*005786D7*/	mov bl,0x4
	/*005786D9*/	jmp _005786DF
_005786DB:
	/*005786DB*/	mov bl,byte ptr ss:[esp+0x18]
_005786DF:
	/*005786DF*/	mov ecx,dword ptr ss:[esp+0x1C]
	/*005786E3*/	and ecx,0xFF
	/*005786E9*/	dec ecx
	/*005786EA*/	je _005786FA
	/*005786EC*/	dec ecx
	/*005786ED*/	je _005786F6
	/*005786EF*/	dec ecx
	/*005786F0*/	jne _005786FE
	/*005786F2*/	mov cl,0x6
	/*005786F4*/	jmp _00578702
_005786F6:
	/*005786F6*/	mov cl,0x5
	/*005786F8*/	jmp _00578702
_005786FA:
	/*005786FA*/	mov cl,0x4
	/*005786FC*/	jmp _00578702
_005786FE:
	/*005786FE*/	mov cl,byte ptr ss:[esp+0x1C]
_00578702:
	/*00578702*/	mov edx,dword ptr ss:[esp+0x14]
	/*00578706*/	and edx,0xFF
	/*0057870C*/	dec edx
	/*0057870D*/	je _00578743
	/*0057870F*/	dec edx
	/*00578710*/	je _0057872C
	/*00578712*/	dec edx
	/*00578713*/	jne _00578762
	/*00578715*/	mov byte ptr ss:[esp+0x14],0x6
	/*0057871A*/	mov byte ptr ds:[esi+0x74],bl
	/*0057871D*/	mov dl,byte ptr ss:[esp+0x14]
	/*00578721*/	mov byte ptr ds:[esi+0x75],cl
	/*00578724*/	mov byte ptr ds:[esi+0x73],dl
	/*00578727*/	pop esi
	/*00578728*/	pop ebx
	/*00578729*/	ret 0x14
_0057872C:
	/*0057872C*/	mov byte ptr ss:[esp+0x14],0x5
	/*00578731*/	mov byte ptr ds:[esi+0x74],bl
	/*00578734*/	mov dl,byte ptr ss:[esp+0x14]
	/*00578738*/	mov byte ptr ds:[esi+0x75],cl
	/*0057873B*/	mov byte ptr ds:[esi+0x73],dl
	/*0057873E*/	pop esi
	/*0057873F*/	pop ebx
	/*00578740*/	ret 0x14
_00578743:
	/*00578743*/	mov byte ptr ss:[esp+0x14],0x4
	/*00578748*/	mov byte ptr ds:[esi+0x74],bl
	/*0057874B*/	mov dl,byte ptr ss:[esp+0x14]
	/*0057874F*/	mov byte ptr ds:[esi+0x75],cl
	/*00578752*/	mov byte ptr ds:[esi+0x73],dl
	/*00578755*/	pop esi
	/*00578756*/	pop ebx
	/*00578757*/	ret 0x14
_0057875A:
	/*0057875A*/	mov bl,byte ptr ss:[esp+0x18]
	/*0057875E*/	mov cl,byte ptr ss:[esp+0x1C]
_00578762:
	/*00578762*/	mov dl,byte ptr ss:[esp+0x14]
	/*00578766*/	mov byte ptr ds:[esi+0x74],bl
	/*00578769*/	mov byte ptr ds:[esi+0x73],dl
	/*0057876C*/	mov byte ptr ds:[esi+0x75],cl
	/*0057876F*/	pop esi
	/*00578770*/	pop ebx
	/*00578771*/	ret 0x14
	}
}

void __declspec(naked) sub_48CE10_force_league_init()
{
	__asm 
	{
		mov eax, 1
		ret
	}
	__asm
	{
	/*0048CE10*/	push esi
	/*0048CE11*/	mov esi,ecx
	/*0048CE13*/	cmp dword ptr ds:[esi+0x1C],0xFFFFFFFF
	/*0048CE17*/	jle _0048CE1D
	/*0048CE19*/	xor al,al
	/*0048CE1B*/	pop esi
	/*0048CE1C*/	ret
_0048CE1D:
	/*0048CE1D*/	mov eax,dword ptr ds:[esi]
	/*0048CE1F*/	push 0x1
	/*0048CE21*/	push 0x1
	/*0048CE23*/	mov ecx,esi
	/*0048CE25*/	call dword ptr ds:[eax+0x10]
	/*0048CE28*/	test al,al
	/*0048CE2A*/	jne _0048CE30
_0048CE2C:
	/*0048CE2C*/	xor al,al
	/*0048CE2E*/	pop esi
	/*0048CE2F*/	ret
_0048CE30:
	/*0048CE30*/	mov eax,dword ptr ds:[esi+0x20]
	/*0048CE33*/	test eax,eax
	/*0048CE35*/	jl _0048CE56
_0048CE37:
	/*0048CE37*/	mov ecx,dword ptr ds:[0xADADFC]
	/*0048CE3D*/	push 0x1
	/*0048CE3F*/	push 0x1
	/*0048CE41*/	mov esi,dword ptr ds:[ecx+eax*0x4]
	/*0048CE44*/	mov ecx,esi
	/*0048CE46*/	mov edx,dword ptr ds:[esi]
	/*0048CE48*/	call dword ptr ds:[edx+0x10]
	/*0048CE4B*/	test al,al
	/*0048CE4D*/	je _0048CE2C
	/*0048CE4F*/	mov eax,dword ptr ds:[esi+0x20]
	/*0048CE52*/	test eax,eax
	/*0048CE54*/	jge _0048CE37
_0048CE56:
	/*0048CE56*/	mov al,0x1
	/*0048CE58*/	pop esi
	/*0048CE59*/	ret
	}
}

void patch_eng_third()
{
	vtable::PrintVTable(0x969E84, "eng_third");
	vtable::PrintVTable(0x969A74, "eng_conf");
	// vtable::PrintVTable(0x970F80, "wel_first.cpp");
	//PatchFunction(0x576DD0, (DWORD)&sub_576DD0_eng_third_init);
	PatchFunction(0x56EDE0, (DWORD)&sub_conference_subs_56EDE0);
	// vtable_eng_third.SetPointer(0xC, (DWORD)&sub_48CE10_force_league_init);
}

