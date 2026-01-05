#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "CMHeader.h"
#include "Helper.h"
#include "vtable.h"
#include "generic_functions.h"

/*
Aus NSL VTable at 00967768:
0. 00 = 004110C0
1. 08 = 00411DE0
2. 28 = 00411F70
3. 30 = 00411D90
4. 3C = 004111A0
5. 44 = 00411980
6. 48 = 00411A30
7. 50 = 004110B0
8. 68 = 00412380
9. 7C = 004124E0
10. 8C = 00411CE0
11. B4 = 00412680
12. B8 = 00412AC0
*/


static int(*sub_682200)() = (int(*)())(0x682200);
static int(*sub_687B10)() = (int(*)())(0x687B10);

static int(*sub_6835C0)() = (int(*)())(0x6835C0);
static int(*sub_6827D0)() = (int(*)())(0x6827D0);
static int(*sub_49EE70)() = (int(*)())(0x49EE70);
static int(*sub_90D130)() = (int(*)())(0x90D130);
static int(*sub_5E8290)() = (int(*)())(0x5E8290);
static int(*sub_68A850)() = (int(*)())(0x68A850);

static int(*sub_687430)() = (int(*)())(0x687430);

static int(*sub_66F4E0)() = (int(*)())(0x66F4E0);
static int(*sub_549F70)() = (int(*)())(0x549F70);

static int(*sub_86F950)() = (int(*)())(0x86F950);
static int(*sub_7671C0)() = (int(*)())(0x7671C0);
static int(*sub_767150)() = (int(*)())(0x767150);

static int(*sub_76A280)() = (int(*)())(0x76A280);
static int(*sub_767AF0)() = (int(*)())(0x767AF0);
static int(*sub_768290)() = (int(*)())(0x768290);

static int(*sub_8AF520)() = (int(*)())(0x8AF520);
static int(*sub_766E10)() = (int(*)())(0x766E10);
static int(*sub_92FE80)() = (int(*)())(0x92FE80);

static int(*sub_768CF0)() = (int(*)())(0x768CF0);
static int(*sub_768940)() = (int(*)())(0x768940);
static int(*sub_669340)() = (int(*)())(0x669340);
static int(*sub_7672E0)() = (int(*)())(0x7672E0);
static int(*sub_768310)() = (int(*)())(0x768310);

static int(*sub_687970)() = (int(*)())(0x687970);
static int(*sub_9452CA)() = (int(*)())(0x9452CA);
static int(*sub_4A1C50)() = (int(*)())(0x4A1C50);
static int(*sub_944C9F)() = (int(*)())(0x944C9F);
static int(*sub_68AA80)() = (int(*)())(0x68AA80);
static int(*sub_79CEE0)() = (int(*)())(0x79CEE0);

static int(*sub_944C94)() = (int(*)())(0x944C94);
static int(*sub_49F450)() = (int(*)())(0x49F450);
static int(*sub_682300)() = (int(*)())(0x682300);

static int(*sub_944E46)() = (int(*)())(0x944E46);
static int(*sub_68A160)() = (int(*)())(0x68A160);
static int(*sub_68A1C0)() = (int(*)())(0x68A1C0);

static int(*sub_521E60)() = (int(*)())(0x521E60);
static int(*sub_521EB0)() = (int(*)())(0x521EB0);
static int(*sub_86BDD0)() = (int(*)())(0x86BDD0);
static int(*sub_86C1D0)() = (int(*)())(0x86C1D0);
static int(*sub_868C50)() = (int(*)())(0x868C50);
static int(*sub_4AE660)() = (int(*)())(0x4AE660);
static int(*sub_4AE8A0)() = (int(*)())(0x4AE8A0);
static int(*sub_4B4590)() = (int(*)())(0x4B4590);
static int(*sub_4B0B80)() = (int(*)())(0x4B0B80);
static int(*sub_4B4420)() = (int(*)())(0x4B4420);

static int(*sub_4AFCE0)() = (int(*)())(0x4AFCE0);

void sub_411DE0();

void sub_411B70_add_teams();
void sub_412680_australia_awards();
void sub_411CE0_subs();

DWORD aus_league_id;
DWORD aus_nation_id;

static int(__thiscall*sub_682200_call)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(0x682200);
static int(__thiscall* sub_6835C0_call)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(0x6835C0);
static int(__thiscall* sub_68A850_call)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(0x68A850);
static DWORD(__thiscall* sub_687B10_call)(BYTE *_this, int a1) = (DWORD(__thiscall*)(BYTE *_this, int a1))(0x687B10);
static int(__thiscall* sub_6827D0_call)(BYTE* _this, int a1) = (int(__thiscall*)(BYTE * _this, int a1))(0x6827D0);
static int(__thiscall* sub_49EE70_call)(void* a1, BYTE* _this) = (int(__thiscall*)(void* a1, BYTE * _this))(0x49EE70);
static int(__thiscall* sub_411CE0_subs_call)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(&sub_411CE0_subs);
static int(__thiscall* sub_411B70_add_teams_call)(BYTE* _this) = (int(__thiscall*)(BYTE * _this))(&sub_411B70_add_teams);


// ecx = 18DB1F78  C0 00 33 03 10 FD DA 18 00 00 00 00 00 00 00 00  À.3..ýÚ.........  

BYTE* __stdcall sub_410E90_init_c(BYTE *_this, short year, cm3_club_comps *club_comp)
{
	sub_682200_call(_this);
	*((DWORD*)(_this + 0x4)) = (DWORD)club_comp;
	*((DWORD*)_this) = 0x967768;
	*((WORD*)(_this + 0x40)) = year;
	*((BYTE*)(_this + 0x50)) = 0x22;
	*((BYTE*)(_this + 0x51)) = 0xA;
	DWORD ret = sub_687B10_call(_this, 1);

	vtable vtable;
	vtable.vtable_ptr = (BYTE*)0x967768;
	vtable.SetPointer(0x8, (DWORD)&sub_411DE0);

	if (!ret)
	{
		*((BYTE*)(_this + 0x44)) = 0xFF;
		*((DWORD*)(_this + 0x30)) = 0xFFFFFFFF;
		*((DWORD*)(_this + 0x2C)) = 0x02;
		void *Bytes8 = sub_944E46_malloc(8);
		*((DWORD*)(_this + 0xC)) = (DWORD)Bytes8;
		sub_411CE0_subs_call(_this);
		//sub_411B70_add_teams_call(_this);
		add_teams(_this);
		sub_6835C0_call(_this);
		sub_6827D0_call(_this, 0);
		void *Bytes5CE = sub_944CF1_operator_new(0x5CE);
		ret = sub_49EE70_call(Bytes5CE, _this);
		*((DWORD*)(_this + 0x8)) = ret;
		sub_68A850_call(_this);
	}
	return _this;
}

void __declspec(naked) sub_410E90_init() // __thiscall style where ecx is this
{
	__asm
	{
	/*00410EA5*/	sub esp, 0x214
	/*00410EAB*/	push ebx
	/*00410EAC*/	push esi
	/*00410EAD*/	mov esi, ecx
	/*00410EAF*/	mov dword ptr ss : [esp + 0xC] , esi
	/*00410EB3*/	call sub_682200		/*call <cm0102.sub_682200>*/
	/*00410EB8*/	mov ecx,dword ptr ss:[esp+0x224]						// League pointer
	/*00410EBF*/	mov ax,word ptr ss:[esp+0x220]							// Year
	/*00410EC7*/	xor ebx,ebx
	/*00410EC9*/	mov dword ptr ds:[esi+0x4],ecx
	/*00410ECC*/	push 0x1
	/*00410ECE*/	mov ecx,esi
	/*00410ED0*/	mov dword ptr ss:[esp+0x21C],ebx
	/*00410ED7*/	mov dword ptr ds:[esi],0x967768		/*mov dword ptr ds:[esi],<cm0102.&sub_4110C0>*/
	/*00410EDD*/	mov word ptr ds:[esi+0x40],ax
	/*00410EE1*/	mov byte ptr ds:[esi+0x50],0x22
	/*00410EE5*/	mov byte ptr ds:[esi+0x51],0xA
	/*00410EE9*/	call sub_687B10		/*call <cm0102.sub_687B10>*/
	/*00410EEE*/	test eax, eax
	/*00410EF0*/	jne _00411095_exit
	/*00410EF6*/	or eax, 0xFFFFFFFF
	/*00410EF9*/	push 0x8
	/*00410EFB*/	mov byte ptr ds : [esi + 0x44] , al
	/*00410EFE*/	mov dword ptr ds : [esi + 0x30] , eax
	/*00410F01*/	mov dword ptr ds : [esi + 0x2C] , 0x2
	/*00410F08*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*00410F0D*/	add esp, 0x4
	/*00410F10*/	mov ecx, esi
	/*00410F12*/	mov dword ptr ds : [esi + 0xC] , eax
	/*00410F15*/	call sub_411CE0_subs		/*call <cm0102.sub_411CE0>*/
	/*00410F4E*/	mov ecx, esi
	/*00410F50*/	call sub_411B70_add_teams		/*call <cm0102.sub_411B70>*/
	/*00410F88*/	mov ecx, esi
	/*00410F8A*/	call sub_6835C0		/*call cm0102.6835C0*/
	/*00410FC3*/	push ebx
	/*00410FC4*/	mov ecx, esi
	/*00410FC6*/	call sub_6827D0		/*call <cm0102.sub_6827D0>*/
	/*00410FFC*/	push 0x5CE
	/*00411001*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*00411006*/	add esp, 0x4
	/*00411009*/	mov dword ptr ss : [esp + 0x8] , eax
	/*0041100D*/	cmp eax, ebx
	/*0041100F*/	mov byte ptr ss : [esp + 0x218] , 0x1
	/*00411017*/	je _00411023
	/*00411019*/	push esi
	/*0041101A*/	mov ecx, eax
	/*0041101C*/	call sub_49EE70		/*call <cm0102.sub_49EE70>*/
	/*00411021*/	jmp _00411025
	_00411023:
	/*00411023*/	xor eax, eax
	_00411025:
	/*00411025*/	cmp eax, ebx
	/*00411027*/	mov byte ptr ss : [esp + 0x218] , bl
	/*0041102E*/	mov dword ptr ds : [esi + 0x8] , eax
	/*0041108E*/	mov ecx, esi
	/*00411090*/	call sub_68A850		/*call <cm0102.sub_68A850>*/
	_00411095_exit:
	/*0041109C*/	mov eax, esi
	/*0041109E*/	pop esi
	/*0041109F*/	pop ebx
	/*004110A7*/	add esp, 0x214
	/*004110AD*/	ret 0x8
	}
}

void __declspec(naked) sub_411B70_add_teams()
{
	__asm
	{
	/*00411B70*/	sub esp,0x200
	/*00411B76*/	push ebx
	/*00411B77*/	push ebp
	/*00411B78*/	push edi
	/*00411B79*/	mov edi,ecx
	/*00411B7B*/	push 0x170C												// number of teams * 59 (0x3B) - was 0x2FF - let's make huge (100 * 59)
	/*00411B80*/	xor ebp,ebp
	/*00411B82*/	mov word ptr ds:[edi+0x3E],0xD							// number of teams (was 0xD)
	/*00411B88*/	xor ebx,ebx
	/*00411B8A*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*00411B8F*/	add esp,0x4
	/*00411B92*/	cmp eax,ebp
	/*00411B94*/	mov dword ptr ds:[edi+0xB1],eax
	/*00411C04*/	mov eax,dword ptr ds:[0xAE235C]	// Number of Clubs
	/*00411C09*/	push esi
	/*00411C0A*/	mov esi,dword ptr ds:[0xAE23B4]	// Clubs
	/*00411C10*/	test eax,eax
	/*00411C12*/	jle _00411C4F
_00411C14:

	/*00411C1A*/	mov eax,dword ptr ds:[esi+0x57]
	/*00411C1D*/	test eax,eax
	/*00411C1F*/	je _00411C3C
	/*00411C21*/	mov ecx,dword ptr ds:[eax]
	/*00411C23*/	mov eax,dword ptr ds:[aus_league_id]
	/*00411C28*/	cmp ecx,eax
	/*00411C2A*/	jne _00411C3C
	/*00411C2C*/	push 0x0
	/*00411C2E*/	mov al,bl
	/*00411C30*/	push 0x0
	/*00411C32*/	push esi
	/*00411C33*/	push eax
	/*00411C34*/	mov ecx,edi
	/*00411C36*/	inc ebx
	/*00411C37*/	call sub_687430		/*call <cm0102.sub_687430>*/
_00411C3C:
	/*00411C3C*/	mov eax,dword ptr ds:[0xAE235C]
	/*00411C41*/	inc ebp
	/*00411C42*/	movsx edx,bp
	/*00411C45*/	add esi,0x245
	/*00411C4B*/	cmp edx,eax
	/*00411C4D*/	jl _00411C14

_00411C4F:
	/*00411C53*/	pop esi
					mov word ptr ds:[edi+0x3E], bx						//  Now set how many teams we have rather than comparing
	/*00411CC5*/	pop edi
	/*00411CC6*/	pop ebp
	/*00411CC7*/	mov eax,0x1
	/*00411CCC*/	pop ebx
	/*00411CCD*/	add esp,0x200
	/*00411CD3*/	ret
	}
}

void __declspec(naked) sub_411CE0_subs()
{
	__asm
	{
	/*00411CE0*/	push esi
	/*00411CE1*/	mov esi,ecx
	/*00411CE3*/	xor eax,eax
	/*00411CE5*/	mov cl,0x2
	/*00411CE7*/	mov word ptr ds:[esi+0xAB],ax
	/*00411CEE*/	mov byte ptr ds:[esi+0xC8],al
	/*00411CF4*/	mov byte ptr ds:[esi+0xBF],al
	/*00411CFA*/	mov byte ptr ds:[esi+0xC0],al
	/*00411D00*/	mov byte ptr ds:[esi+0xC1],al
	/*00411D06*/	push eax
	/*00411D07*/	mov edx,0x3
	/*00411D0C*/	mov byte ptr ds:[esi+0xC4],cl
	/*00411D12*/	mov byte ptr ds:[esi+0xC6],cl
	/*00411D18*/	mov byte ptr ds:[esi+0x52],cl
	/*00411D1B*/	lea eax,dword ptr ds:[esi+0x3A]
	/*00411D1E*/	lea ecx,dword ptr ds:[esi+0xA9]
	/*00411D24*/	mov word ptr ds:[esi+0x3C],dx
	/*00411D28*/	mov byte ptr ds:[esi+0xC2],dl
	// /*00411D2E*/	mov byte ptr ds:[esi+0x4A],dl
	/*00411D31*/	mov edx,dword ptr ds:[esi]
	/*00411D33*/	push eax
	/*00411D34*/	push ecx
	/*00411D35*/	push 0xFFFFFFFF
	/*00411D37*/	mov ecx,esi
	/*00411D39*/	mov byte ptr ds:[esi+0xC3],0x1
	/*00411D40*/	mov byte ptr ds:[esi+0x42],0x1
	/*00411D44*/	mov byte ptr ds:[esi+0xC5],0x1
	/*00411D4B*/	mov byte ptr ds:[esi+0xC7],0x4
	/*00411D52*/	mov byte ptr ds:[esi+0xBE],0x6
	/*00411D59*/	mov dword ptr ds:[esi+0x1C],0xFFFFFFFF
	/*00411D60*/	mov dword ptr ds:[esi+0x20],0xFFFFFFFF
	/*00411D67*/	mov word ptr ds:[esi+0xD9],0x28
	/*00411D70*/	mov byte ptr ds:[esi+0x49],0x4				// Subs Named (4)
					mov byte ptr ds:[esi+0x4A],0x3				// Subs Used  (3)
	/*00411D74*/	call dword ptr ds:[edx+0x3C]				// Calls sub_4111A0_fixtures2
	/*00411D77*/	mov dword ptr ds:[esi+0xBA],eax
	/*00411D7D*/	mov eax,0x1
	/*00411D82*/	pop esi
	/*00411D83*/	ret
	}
}

void ChangeAusIDs()
{
	aus_league_id = *(DWORD*)0x9CF89C;
	aus_nation_id = *(DWORD*)0x9CF224;

	
	cm3_club_comps* comp = find_club_comp("Austrian Premier Division");
	if (comp)
	{
		aus_league_id = comp->ClubCompID;
		aus_nation_id = comp->ClubCompNation->NationID;
	}
	else
		dprintf("aus_nsl - could not find comp!");

	dprintf("aus_league_id: %X aus_nation_id: %X \n", aus_league_id, aus_nation_id);
}

static BYTE* (__thiscall* sub_549F70_call)(DWORD *num, DWORD a1, DWORD a2, DWORD a3, DWORD a4) = (BYTE * (__thiscall*)(DWORD *num, DWORD a1, DWORD a2, DWORD a3, DWORD a4))(0x549F70);

int sub_832380_setup_aus_c(BYTE *_this)
{
	ChangeAusIDs();
	*(WORD*)(_this + 0x32) = 0x2;
	*(WORD*)(_this + 0x37) = 0x5;
	*(BYTE*)(_this + 0x34) = 0x9;
	*(WORD*)(_this + 0x46) = 0x5;
	*(WORD*)(_this + 0x35) = (WORD)*current_year;
	*(WORD*)(_this + 0x41) = 0xA;
	*(BYTE*)(_this + 0x43) = 0x5;
	*(WORD*)(_this + 0x44) = (WORD)((*current_year) + 1);
	*(DWORD*)(_this + 0x0C) = 0x1;						// Number of competitions ?!  (1)
	*(DWORD*)(_this + 0x10) = (DWORD)sub_945501_alloc(0x4, 0x1);
	BYTE* esp_0c = (BYTE *)sub_944CF1_operator_new(0xEE);
	cm3_club_comps *leaguePtr = &(*club_comps)[aus_league_id];
	BYTE* leagueSetupPtr = sub_410E90_init_c(esp_0c, (short)*current_year, leaguePtr);
	BYTE* compPtr = *(BYTE**)(_this + 0x10);
	*(DWORD*)(compPtr) = (DWORD)leagueSetupPtr;

	/*
	BYTE* league2 = (BYTE*)sub_944CF1_operator_new(0xEE);
	cm3_club_comps* league2Ptr = &(*club_comps)[aus_league_id + 1];
	BYTE* league2SetupPtr = sub_410E90_init_c(league2, (short)*current_year, league2Ptr);
	*(DWORD*)(compPtr+0x4) = (DWORD)league2SetupPtr;
	*/
	BYTE num[8]; // Date?
	sub_549F70_call((DWORD*)&num, 0x14, 0x6, 0x7D1, 0xFFFFFFFF);
	*(WORD*)(_this + 0x15) = (WORD)(*(WORD*)num);
	*(WORD*)(_this + 0x1B) = (WORD)*current_year;
	*(BYTE*)(_this + 0x1D) = 0x1;
	*(DWORD*)(_this + 0x26) = 0x0;
	return 1;
}

void __declspec(naked) sub_832380_setup_aus()			// Setup.cpp for Aus
{
	__asm pushad;
	ChangeAusIDs();
	__asm popad;

	__asm
	{
	/*00832395*/	sub esp,0x41C
	/*0083239B*/	push ebp
	/*0083239C*/	push esi
	/*0083239D*/	mov esi,dword ptr ss:[esp+0x428]
	/*008323A4*/	test esi,esi
	/*0083241D*/	mov eax,0x5
	/*00832422*/	mov word ptr ds:[esi+0x32],0x2
	/*00832428*/	mov word ptr ds:[esi+0x37],ax
	/*0083242C*/	mov byte ptr ds:[esi+0x34],0x9
	/*00832430*/	mov cx,word ptr ds:[0xAE2C92]						// [0AE2C92] = Current year
	/*00832437*/	mov word ptr ds:[esi+0x46],ax
	/*0083243B*/	mov word ptr ds:[esi+0x35],cx
	/*0083243F*/	mov word ptr ds:[esi+0x41],0xA
	/*00832445*/	mov byte ptr ds:[esi+0x43],al
	/*00832448*/	mov dx,word ptr ds:[0xAE2C92]
	/*0083244F*/	inc dx
	/*00832451*/	push 0x1
	/*00832453*/	mov word ptr ds:[esi+0x44],dx
	/*00832457*/	mov bp,word ptr ds:[0xAE2C92]
	/*0083245E*/	push 0x4
	/*00832460*/	mov word ptr ss:[esp+0x10],bp
	/*00832465*/	mov dword ptr ds:[esi+0xC],0x1						// Number of competitions ?!  (1)
	/*0083246C*/	call sub_945501_alloc		/*call <cm0102.sub_945501>*/
	/*00832471*/	add esp,0x8
	/*00832474*/	mov dword ptr ds:[esi+0x10],eax
	/*00832525*/	push 0xEE
	/*0083252A*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*0083252F*/	add esp,0x4
	/*00832532*/	mov dword ptr ss:[esp+0xC],eax
	/*00832536*/	test eax,eax
	/*00832538*/	mov dword ptr ss:[esp+0x420],0x0
	/*00832543*/	je _0083256F
	/*00832545*/	mov edx,dword ptr ds:[aus_league_id]
	/*0083254B*/	push edi
	/*0083254C*/	lea edi,dword ptr ds:[edx+edx*0x2]
	/*0083254F*/	lea ecx,dword ptr ds:[edi+edi*0x8]
	/*00832552*/	mov edi,dword ptr ds:[0xAE23D0]
	/*00832558*/	shl ecx,0x2
	/*0083255B*/	sub ecx,edx
	/*0083255D*/	mov edx,dword ptr ss:[esp+0xC]
	/*00832561*/	add ecx,edi
	/*00832563*/	push ecx					// Pointer to the league
	/*00832564*/	push edx					// Year (short)
	/*00832565*/	mov ecx,eax					// EE Bytes
					push eax					// push for our c function as it's __stdcall
	/*00832567*/	call sub_410E90_init_c	/*call <cm0102.sub_410E90>*/
	/*0083256C*/	pop edi
	/*0083256D*/	jmp _00832571
_0083256F:
	/*0083256F*/	xor eax,eax
_00832571:
	/*00832571*/	mov ecx,dword ptr ds:[esi+0x10]
	/*00832574*/	push 0xFFFFFFFF
	/*00832576*/	push 0x7D1
	/*0083257B*/	push 0x6
	/*0083257D*/	mov dword ptr ds:[ecx],eax
	/*0083257D*/	// mov dword ptr ds : [ecx+4] , eax		// duplicate comp ! Works"
	/*0083257F*/	push 0x14
	/*00832581*/	lea ecx,dword ptr ss:[esp+0x20]
	/*00832585*/	mov dword ptr ss:[esp+0x430],0xFFFFFFFF
	/*00832590*/	call sub_549F70		/*call <cm0102.sub_549F70>*/
	/*00832595*/	mov dx,word ptr ss:[esp+0x10]
	/*0083259A*/	mov ecx,dword ptr ss:[esp+0x418]
	/*008325A1*/	mov word ptr ds:[esi+0x15],dx
	/*008325A5*/	mov word ptr ds:[esi+0x1B],bp
	/*008325A9*/	mov byte ptr ds:[esi+0x1D],0x1
	/*008325AD*/	mov dword ptr ds:[esi+0x26],0x0
	/*008325B4*/	pop esi
	/*008325B5*/	mov eax,0x1
	/*008325BA*/	pop ebp
	/*008325C2*/	add esp,0x41C
	/*008325C8*/	ret
	}
}

void __declspec(naked) sub_412AC0_fixtures()
{
	__asm
	{
	/*00412AC0*/	sub esp,0x10
	/*00412AC3*/	push esi
	/*00412AC4*/	push edi
	/*00412AC5*/	mov edi,dword ptr ss:[esp+0x1C]
	/*00412AC9*/	push 0xFFFFFFFF
	/*00412ACB*/	mov esi,ecx
	/*00412ACD*/	mov ax,word ptr ds:[edi+0x2]
	/*00412AD1*/	lea ecx,dword ptr ss:[esp+0x14]
	/*00412AD5*/	push eax
	/*00412AD6*/	push 0x5
	/*00412AD8*/	push 0x14
	/*00412ADA*/	call sub_549F70		/*call <cm0102.sub_549F70>*/
	/*00412ADF*/	mov ecx,dword ptr ds:[eax]
	/*00412AE1*/	mov eax,dword ptr ds:[eax+0x4]
	/*00412AE4*/	mov dword ptr ss:[esp+0x8],ecx
	/*00412AE8*/	mov dx,word ptr ss:[esp+0xA]
	/*00412AED*/	cmp dx,word ptr ds:[edi+0x2]
	/*00412AF1*/	mov dword ptr ss:[esp+0xC],eax
	/*00412AF5*/	jne _00412BA9
	/*00412AFB*/	cmp cx,word ptr ds:[edi]
	/*00412AFE*/	jne _00412BA9
	/*00412B04*/	mov eax,dword ptr ds:[esi+0x4]
	/*00412B07*/	mov edx,dword ptr ds:[aus_league_id]
	/*00412B0D*/	push 0xFFFFFFFF
	/*00412B0F*/	push 0xFFFFFFFF
	/*00412B11*/	mov ecx,dword ptr ds:[eax+0x10]
	/*00412B14*/	push 0xFFFFFFFF
	/*00412B16*/	push 0xFFFFFFFF
	/*00412B18*/	push 0x11
	/*00412B1A*/	push 0x0
	/*00412B1C*/	push 0xFFFFFFFF
	/*00412B1E*/	push ecx
	/*00412B1F*/	push edi
	/*00412B20*/	push edx
	/*00412B21*/	mov ecx,esi
	/*00412B23*/	call sub_768CF0		/*call <cm0102.sub_768CF0>*/
	/*00412B28*/	mov eax,dword ptr ds:[esi+0x4]
	/*00412B2B*/	mov edx,dword ptr ds:[aus_league_id]
	/*00412B31*/	push 0xFFFFFFFF
	/*00412B33*/	push 0xFFFFFFFF
	/*00412B35*/	mov ecx,dword ptr ds:[eax+0x14]
	/*00412B38*/	push 0xFFFFFFFF
	/*00412B3A*/	push 0xFFFFFFFF
	/*00412B3C*/	push 0x11
	/*00412B3E*/	push 0x0
	/*00412B40*/	push 0x15
	/*00412B42*/	push ecx
	/*00412B43*/	push edi
	/*00412B44*/	push edx
	/*00412B45*/	mov ecx,esi
	/*00412B47*/	call sub_768CF0		/*call <cm0102.sub_768CF0>*/
	/*00412B4C*/	mov eax,dword ptr ds:[esi+0x4]
	/*00412B4F*/	mov edx,dword ptr ds:[aus_league_id]
	/*00412B55*/	push 0xFFFFFFFF
	/*00412B57*/	push 0xFFFFFFFF
	/*00412B59*/	mov ecx,dword ptr ds:[eax+0x18]
	/*00412B5C*/	push 0xFFFFFFFF
	/*00412B5E*/	push 0xFFFFFFFF
	/*00412B60*/	push 0x11
	/*00412B62*/	push 0x1
	/*00412B64*/	push 0xFFFFFFFF
	/*00412B66*/	push ecx
	/*00412B67*/	push edi
	/*00412B68*/	push edx
	/*00412B69*/	mov ecx,esi
	/*00412B6B*/	call sub_768CF0		/*call <cm0102.sub_768CF0>*/
	/*00412B70*/	mov eax,dword ptr ds:[esi+0x4]
	/*00412B73*/	mov edx,dword ptr ds:[aus_league_id]
	/*00412B79*/	push 0xFFFFFFFF
	/*00412B7B*/	push 0xFFFFFFFF
	/*00412B7D*/	mov ecx,dword ptr ds:[eax+0x1C]
	/*00412B80*/	push 0xFFFFFFFF
	/*00412B82*/	push 0xFFFFFFFF
	/*00412B84*/	push 0x2
	/*00412B86*/	push 0xFFFFFFFF
	/*00412B88*/	push 0xFFFFFFFF
	/*00412B8A*/	push ecx
	/*00412B8B*/	push edi
	/*00412B8C*/	push edx
	/*00412B8D*/	mov ecx,esi
	/*00412B8F*/	call sub_768CF0		/*call <cm0102.sub_768CF0>*/
	/*00412B94*/	mov ecx,dword ptr ds:[esi+0x4]
	/*00412B97*/	mov eax,dword ptr ds:[aus_league_id]
	/*00412B9C*/	push eax
	/*00412B9D*/	mov edx,dword ptr ds:[ecx+0x20]
	/*00412BA0*/	mov ecx,esi
	/*00412BA2*/	push edx
	/*00412BA3*/	push edi
	/*00412BA4*/	call sub_768940		/*call <cm0102.sub_768940>*/
_00412BA9:
	/*00412BA9*/	mov eax,dword ptr ds:[esi+0xE]
	/*00412BAC*/	push ebx
	/*00412BAD*/	mov bx,word ptr ds:[edi]
	/*00412BB0*/	push eax
	/*00412BB1*/	call sub_669340		/*call <cm0102.sub_669340>*/
	/*00412BB6*/	movsx eax,al
	/*00412BB9*/	xor edx,edx
	/*00412BBB*/	add esp,0x4
	/*00412BBE*/	lea ecx,dword ptr ds:[eax+eax*0x8]
	/*00412BC1*/	movsx eax,bx
	/*00412BC4*/	mov dx,word ptr ds:[ecx*0x8+0xB63D75]
	/*00412BCC*/	pop ebx
	/*00412BCD*/	cmp eax,edx
	/*00412BCF*/	jne _00412C01
	/*00412BD1*/	mov cx,word ptr ds:[edi+0x2]
	/*00412BD5*/	mov edx,dword ptr ds:[esi+0x4]
	/*00412BD8*/	push ecx
	/*00412BD9*/	mov ecx,dword ptr ds:[edx+0x4]
	/*00412BDC*/	call sub_7672E0		/*call <cm0102.sub_7672E0>*/
	/*00412BE1*/	mov ecx,dword ptr ds:[esi+0x4]
	/*00412BE4*/	mov ax,word ptr ds:[edi+0x2]
	/*00412BE8*/	push eax
	/*00412BE9*/	mov ecx,dword ptr ds:[ecx+0x8]
	/*00412BEC*/	call sub_7672E0		/*call <cm0102.sub_7672E0>*/
	/*00412BF1*/	mov eax,dword ptr ds:[esi+0x4]
	/*00412BF4*/	mov dx,word ptr ds:[edi+0x2]
	/*00412BF8*/	push edx
	/*00412BF9*/	mov ecx,dword ptr ds:[eax+0xC]
	/*00412BFC*/	call sub_7672E0		/*call <cm0102.sub_7672E0>*/
_00412C01:
	/*00412C01*/	push edi
	/*00412C02*/	mov ecx,esi
	/*00412C04*/	call sub_768310		/*call <cm0102.sub_768310>*/
	/*00412C09*/	pop edi
	/*00412C0A*/	pop esi
	/*00412C0B*/	add esp,0x10
	/*00412C0E*/	ret 0x4
	}
}

void __declspec(naked) sub_4111A0_fixtures2()
{
	__asm
	{
	/*004111A0*/	mov al,byte ptr ss:[esp+0x4]
	/*004111A4*/	sub esp,0x200
	/*004111AA*/	cmp al,0xFF
	/*004111AC*/	push ebx
	/*004111AD*/	push esi
	/*004111AE*/	push edi
	/*004111AF*/	mov edi,ecx
	/*004111B1*/	jne _0041162B
	/*004111B7*/	mov eax,dword ptr ss:[esp+0x21C]
	/*004111BE*/	xor ebx,ebx
	/*004111C0*/	cmp eax,ebx
	/*004111C2*/	je _004111CA
	/*004111C4*/	mov dword ptr ds:[eax],0x1
_004111CA:
	/*004111CA*/	mov eax,dword ptr ss:[esp+0x214]
	/*004111D1*/	mov ecx,dword ptr ss:[esp+0x218]
	/*004111D8*/	push 0x618
	/*004111DD*/	mov word ptr ds:[eax],0x18
	/*004111E2*/	mov word ptr ds:[ecx],0x434
	/*004111E7*/	call sub_944E46		/*call <cm0102.sub_944E46>*/
	/*004111EC*/	mov esi,eax
	/*004111EE*/	add esp,0x4
	/*004111F1*/	cmp esi,ebx
	/*004111F3*/	jne _00411228
	/*004111F5*/	lea edx,dword ptr ss:[esp+0xC]
	/*004111F9*/	lea eax,dword ptr ss:[esp+0x10C]
	/*00411200*/	push edx
	/*00411201*/	push eax
	/*00411202*/	push ebx
	/*00411203*/	push ebx
	/*00411204*/	push 0x987C20		/*push cm0102.987C20*/
	/*00411209*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0041120E*/	add esp,0x14
	/*00411211*/	lea ecx,dword ptr ss:[esp+0xC]
	/*00411215*/	lea edx,dword ptr ss:[esp+0x10C]
	/*0041121C*/	push 0xA7
	/*00411221*/	push ecx
	/*00411222*/	push edx
	/*00411223*/	jmp _004118BA
_00411228:
	/*00411228*/	mov ax,word ptr ds:[edi+0x40]
	/*0041122C*/	push ebx
	/*0041122D*/	push eax
	/*0041122E*/	push 0x1
	/*00411230*/	push 0x5
	/*00411232*/	push ebx
	/*00411233*/	push 0x9
	/*00411235*/	push 0x5
	/*00411237*/	push ebx
	/*00411238*/	push esi
	/*00411239*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041123E*/	push ebx
	/*0041123F*/	push 0xFFFFFFFF
	/*00411241*/	push 0xFFFFFFFF
	/*00411243*/	push 0xFFFFFFFF
	/*00411245*/	push ebx
	/*00411246*/	push ebx
	/*00411247*/	push esi
	/*00411248*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041124D*/	mov cx,word ptr ds:[edi+0x40]
	/*00411251*/	add esp,0x40
	/*00411254*/	push ebx
	/*00411255*/	push ecx
	/*00411256*/	push 0x1
	/*00411258*/	push 0x5
	/*0041125A*/	push ebx
	/*0041125B*/	push 0x9
	/*0041125D*/	push 0xC
	/*0041125F*/	push 0x1
	/*00411261*/	push esi
	/*00411262*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411267*/	push ebx
	/*00411268*/	push 0xFFFFFFFF
	/*0041126A*/	push 0xFFFFFFFF
	/*0041126C*/	push 0xFFFFFFFF
	/*0041126E*/	push ebx
	/*0041126F*/	push 0x1
	/*00411271*/	push esi
	/*00411272*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411277*/	mov dx,word ptr ds:[edi+0x40]
	/*0041127B*/	add esp,0x40
	/*0041127E*/	push ebx
	/*0041127F*/	push edx
	/*00411280*/	push 0x1
	/*00411282*/	push 0x5
	/*00411284*/	push ebx
	/*00411285*/	push 0x9
	/*00411287*/	push 0x13
	/*00411289*/	push 0x2
	/*0041128B*/	push esi
	/*0041128C*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411291*/	push ebx
	/*00411292*/	push 0xFFFFFFFF
	/*00411294*/	push 0xFFFFFFFF
	/*00411296*/	push 0xFFFFFFFF
	/*00411298*/	push ebx
	/*00411299*/	push 0x2
	/*0041129B*/	push esi
	/*0041129C*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004112A1*/	mov ax,word ptr ds:[edi+0x40]
	/*004112A5*/	add esp,0x40
	/*004112A8*/	push ebx
	/*004112A9*/	push eax
	/*004112AA*/	push 0x1
	/*004112AC*/	push 0x5
	/*004112AE*/	push ebx
	/*004112AF*/	push 0x9
	/*004112B1*/	push 0x1A
	/*004112B3*/	push 0x3
	/*004112B5*/	push esi
	/*004112B6*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004112BB*/	push ebx
	/*004112BC*/	push 0xFFFFFFFF
	/*004112BE*/	push 0xFFFFFFFF
	/*004112C0*/	push 0xFFFFFFFF
	/*004112C2*/	push ebx
	/*004112C3*/	push 0x3
	/*004112C5*/	push esi
	/*004112C6*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004112CB*/	add esp,0x40
	/*004112CE*/	push ebx
	/*004112CF*/	mov cx,word ptr ds:[edi+0x40]
	/*004112D3*/	push ecx
	/*004112D4*/	push 0x1
	/*004112D6*/	push 0x5
	/*004112D8*/	push ebx
	/*004112D9*/	push 0xA
	/*004112DB*/	push 0x2
	/*004112DD*/	push 0x4
	/*004112DF*/	push esi
	/*004112E0*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004112E5*/	push ebx
	/*004112E6*/	push 0xFFFFFFFF
	/*004112E8*/	push 0xFFFFFFFF
	/*004112EA*/	push 0xFFFFFFFF
	/*004112EC*/	push ebx
	/*004112ED*/	push 0x4
	/*004112EF*/	push esi
	/*004112F0*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004112F5*/	mov dx,word ptr ds:[edi+0x40]
	/*004112F9*/	add esp,0x40
	/*004112FC*/	push ebx
	/*004112FD*/	push edx
	/*004112FE*/	push 0x1
	/*00411300*/	push 0x5
	/*00411302*/	push ebx
	/*00411303*/	push 0xA
	/*00411305*/	push 0x9
	/*00411307*/	push 0x5
	/*00411309*/	push esi
	/*0041130A*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041130F*/	push ebx
	/*00411310*/	push 0xFFFFFFFF
	/*00411312*/	push 0xFFFFFFFF
	/*00411314*/	push 0xFFFFFFFF
	/*00411316*/	push ebx
	/*00411317*/	push 0x5
	/*00411319*/	push esi
	/*0041131A*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041131F*/	mov ax,word ptr ds:[edi+0x40]
	/*00411323*/	add esp,0x40
	/*00411326*/	push ebx
	/*00411327*/	push eax
	/*00411328*/	push 0x2
	/*0041132A*/	push 0x2
	/*0041132C*/	push ebx
	/*0041132D*/	push 0xA
	/*0041132F*/	push 0x10
	/*00411331*/	push 0x6
	/*00411333*/	push esi
	/*00411334*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411339*/	push ebx
	/*0041133A*/	push 0xFFFFFFFF
	/*0041133C*/	push 0xFFFFFFFF
	/*0041133E*/	push 0xFFFFFFFF
	/*00411340*/	push ebx
	/*00411341*/	push 0x6
	/*00411343*/	push esi
	/*00411344*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411349*/	mov cx,word ptr ds:[edi+0x40]
	/*0041134D*/	add esp,0x40
	/*00411350*/	push ebx
	/*00411351*/	push ecx
	/*00411352*/	push 0x1
	/*00411354*/	push 0x5
	/*00411356*/	push ebx
	/*00411357*/	push 0xA
	/*00411359*/	push 0x17
	/*0041135B*/	push 0x7
	/*0041135D*/	push esi
	/*0041135E*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411363*/	push ebx
	/*00411364*/	push 0xFFFFFFFF
	/*00411366*/	push 0xFFFFFFFF
	/*00411368*/	push 0xFFFFFFFF
	/*0041136A*/	push ebx
	/*0041136B*/	push 0x7
	/*0041136D*/	push esi
	/*0041136E*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411373*/	mov dx,word ptr ds:[edi+0x40]
	/*00411377*/	add esp,0x40
	/*0041137A*/	push ebx
	/*0041137B*/	push edx
	/*0041137C*/	push 0x1
	/*0041137E*/	push 0x5
	/*00411380*/	push ebx
	/*00411381*/	push 0xA
	/*00411383*/	push 0x1E
	/*00411385*/	push 0x8
	/*00411387*/	push esi
	/*00411388*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041138D*/	push ebx
	/*0041138E*/	push 0xFFFFFFFF
	/*00411390*/	push 0xFFFFFFFF
	/*00411392*/	push 0xFFFFFFFF
	/*00411394*/	push ebx
	/*00411395*/	push 0x8
	/*00411397*/	push esi
	/*00411398*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041139D*/	mov ax,word ptr ds:[edi+0x40]
	/*004113A1*/	add esp,0x40
	/*004113A4*/	push ebx
	/*004113A5*/	push eax
	/*004113A6*/	push 0x1
	/*004113A8*/	push 0x5
	/*004113AA*/	push ebx
	/*004113AB*/	push 0xB
	/*004113AD*/	push 0x7
	/*004113AF*/	push 0x9
	/*004113B1*/	push esi
	/*004113B2*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004113B7*/	push ebx
	/*004113B8*/	push 0xFFFFFFFF
	/*004113BA*/	push 0xFFFFFFFF
	/*004113BC*/	push 0xFFFFFFFF
	/*004113BE*/	push ebx
	/*004113BF*/	push 0x9
	/*004113C1*/	push esi
	/*004113C2*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004113C7*/	mov cx,word ptr ds:[edi+0x40]
	/*004113CB*/	add esp,0x40
	/*004113CE*/	push ebx
	/*004113CF*/	push ecx
	/*004113D0*/	push 0x1
	/*004113D2*/	push 0x5
	/*004113D4*/	push ebx
	/*004113D5*/	push 0xB
	/*004113D7*/	push 0xE
	/*004113D9*/	push 0xA
	/*004113DB*/	push esi
	/*004113DC*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004113E1*/	push ebx
	/*004113E2*/	push 0xFFFFFFFF
	/*004113E4*/	push 0xFFFFFFFF
	/*004113E6*/	push 0xFFFFFFFF
	/*004113E8*/	push ebx
	/*004113E9*/	push 0xA
	/*004113EB*/	push esi
	/*004113EC*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004113F1*/	mov dx,word ptr ds:[edi+0x40]
	/*004113F5*/	add esp,0x40
	/*004113F8*/	push ebx
	/*004113F9*/	push edx
	/*004113FA*/	push 0x1
	/*004113FC*/	push 0x5
	/*004113FE*/	push ebx
	/*004113FF*/	push 0xB
	/*00411401*/	push 0x15
	/*00411403*/	push 0xB
	/*00411405*/	push esi
	/*00411406*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041140B*/	push ebx
	/*0041140C*/	push 0xFFFFFFFF
	/*0041140E*/	push 0xFFFFFFFF
	/*00411410*/	push 0xFFFFFFFF
	/*00411412*/	push ebx
	/*00411413*/	push 0xB
	/*00411415*/	push esi
	/*00411416*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041141B*/	mov ax,word ptr ds:[edi+0x40]
	/*0041141F*/	add esp,0x40
	/*00411422*/	push ebx
	/*00411423*/	push eax
	/*00411424*/	push 0x1
	/*00411426*/	push 0x5
	/*00411428*/	push ebx
	/*00411429*/	push 0xB
	/*0041142B*/	push 0x1C
	/*0041142D*/	push 0xC
	/*0041142F*/	push esi
	/*00411430*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411435*/	push ebx
	/*00411436*/	push 0xFFFFFFFF
	/*00411438*/	push 0xFFFFFFFF
	/*0041143A*/	push 0xFFFFFFFF
	/*0041143C*/	push ebx
	/*0041143D*/	push 0xC
	/*0041143F*/	push esi
	/*00411440*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411445*/	mov cx,word ptr ds:[edi+0x40]
	/*00411449*/	add esp,0x40
	/*0041144C*/	push ebx
	/*0041144D*/	push ecx
	/*0041144E*/	push 0x1
	/*00411450*/	push 0x5
	/*00411452*/	push 0x1
	/*00411454*/	push ebx
	/*00411455*/	push 0x4
	/*00411457*/	push 0xD
	/*00411459*/	push esi
	/*0041145A*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041145F*/	push ebx
	/*00411460*/	push 0xFFFFFFFF
	/*00411462*/	push 0xFFFFFFFF
	/*00411464*/	push 0xFFFFFFFF
	/*00411466*/	push ebx
	/*00411467*/	push 0xD
	/*00411469*/	push esi
	/*0041146A*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041146F*/	mov dx,word ptr ds:[edi+0x40]
	/*00411473*/	add esp,0x40
	/*00411476*/	push ebx
	/*00411477*/	push edx
	/*00411478*/	push 0x1
	/*0041147A*/	push 0x5
	/*0041147C*/	push 0x1
	/*0041147E*/	push ebx
	/*0041147F*/	push 0xB
	/*00411481*/	push 0xE
	/*00411483*/	push esi
	/*00411484*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411489*/	push ebx
	/*0041148A*/	push 0xFFFFFFFF
	/*0041148C*/	push 0xFFFFFFFF
	/*0041148E*/	push 0xFFFFFFFF
	/*00411490*/	push ebx
	/*00411491*/	push 0xE
	/*00411493*/	push esi
	/*00411494*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411499*/	mov ax,word ptr ds:[edi+0x40]
	/*0041149D*/	add esp,0x40
	/*004114A0*/	push ebx
	/*004114A1*/	push eax
	/*004114A2*/	push 0x1
	/*004114A4*/	push 0x5
	/*004114A6*/	push 0x1
	/*004114A8*/	push ebx
	/*004114A9*/	push 0x12
	/*004114AB*/	push 0xF
	/*004114AD*/	push esi
	/*004114AE*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004114B3*/	push ebx
	/*004114B4*/	push 0xFFFFFFFF
	/*004114B6*/	push 0xFFFFFFFF
	/*004114B8*/	push 0xFFFFFFFF
	/*004114BA*/	push ebx
	/*004114BB*/	push 0xF
	/*004114BD*/	push esi
	/*004114BE*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004114C3*/	mov cx,word ptr ds:[edi+0x40]
	/*004114C7*/	add esp,0x40
	/*004114CA*/	push ebx
	/*004114CB*/	push ecx
	/*004114CC*/	push 0x1
	/*004114CE*/	push 0x5
	/*004114D0*/	push 0x1
	/*004114D2*/	push ebx
	/*004114D3*/	push 0x19
	/*004114D5*/	push 0x10
	/*004114D7*/	push esi
	/*004114D8*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004114DD*/	push ebx
	/*004114DE*/	push 0xFFFFFFFF
	/*004114E0*/	push 0xFFFFFFFF
	/*004114E2*/	push 0xFFFFFFFF
	/*004114E4*/	push ebx
	/*004114E5*/	push 0x10
	/*004114E7*/	push esi
	/*004114E8*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004114ED*/	mov dx,word ptr ds:[edi+0x40]
	/*004114F1*/	add esp,0x40
	/*004114F4*/	push ebx
	/*004114F5*/	push edx
	/*004114F6*/	push 0x1
	/*004114F8*/	push 0x5
	/*004114FA*/	push 0x1
	/*004114FC*/	push 0x1
	/*004114FE*/	push 0x1
	/*00411500*/	push 0x11
	/*00411502*/	push esi
	/*00411503*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411508*/	push ebx
	/*00411509*/	push 0xFFFFFFFF
	/*0041150B*/	push 0xFFFFFFFF
	/*0041150D*/	push 0xFFFFFFFF
	/*0041150F*/	push ebx
	/*00411510*/	push 0x11
	/*00411512*/	push esi
	/*00411513*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411518*/	mov ax,word ptr ds:[edi+0x40]
	/*0041151C*/	add esp,0x40
	/*0041151F*/	push ebx
	/*00411520*/	push eax
	/*00411521*/	push 0x1
	/*00411523*/	push 0x5
	/*00411525*/	push 0x1
	/*00411527*/	push 0x1
	/*00411529*/	push 0x8
	/*0041152B*/	push 0x12
	/*0041152D*/	push esi
	/*0041152E*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411533*/	push ebx
	/*00411534*/	push 0xFFFFFFFF
	/*00411536*/	push 0xFFFFFFFF
	/*00411538*/	push 0xFFFFFFFF
	/*0041153A*/	push ebx
	/*0041153B*/	push 0x12
	/*0041153D*/	push esi
	/*0041153E*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411543*/	mov cx,word ptr ds:[edi+0x40]
	/*00411547*/	add esp,0x40
	/*0041154A*/	push ebx
	/*0041154B*/	push ecx
	/*0041154C*/	push 0x1
	/*0041154E*/	push 0x5
	/*00411550*/	push 0x1
	/*00411552*/	push 0x1
	/*00411554*/	push 0xF
	/*00411556*/	push 0x13
	/*00411558*/	push esi
	/*00411559*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041155E*/	push ebx
	/*0041155F*/	push 0xFFFFFFFF
	/*00411561*/	push 0xFFFFFFFF
	/*00411563*/	push 0xFFFFFFFF
	/*00411565*/	push ebx
	/*00411566*/	push 0x13
	/*00411568*/	push esi
	/*00411569*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041156E*/	mov dx,word ptr ds:[edi+0x40]
	/*00411572*/	add esp,0x40
	/*00411575*/	push ebx
	/*00411576*/	push edx
	/*00411577*/	push 0x1
	/*00411579*/	push 0x5
	/*0041157B*/	push 0x1
	/*0041157D*/	push 0x1
	/*0041157F*/	push 0x16
	/*00411581*/	push 0x14
	/*00411583*/	push esi
	/*00411584*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411589*/	push ebx
	/*0041158A*/	push 0xFFFFFFFF
	/*0041158C*/	push 0xFFFFFFFF
	/*0041158E*/	push 0xFFFFFFFF
	/*00411590*/	push ebx
	/*00411591*/	push 0x14
	/*00411593*/	push esi
	/*00411594*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411599*/	mov ax,word ptr ds:[edi+0x40]
	/*0041159D*/	add esp,0x40
	/*004115A0*/	push ebx
	/*004115A1*/	push eax
	/*004115A2*/	push 0x1
	/*004115A4*/	push 0x5
	/*004115A6*/	push 0x1
	/*004115A8*/	push 0x2
	/*004115AA*/	push 0x1
	/*004115AC*/	push 0x15
	/*004115AE*/	push esi
	/*004115AF*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004115B4*/	push ebx
	/*004115B5*/	push 0xFFFFFFFF
	/*004115B7*/	push 0xFFFFFFFF
	/*004115B9*/	push 0xFFFFFFFF
	/*004115BB*/	push ebx
	/*004115BC*/	push 0x15
	/*004115BE*/	push esi
	/*004115BF*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004115C4*/	mov cx,word ptr ds:[edi+0x40]
	/*004115C8*/	add esp,0x40
	/*004115CB*/	push ebx
	/*004115CC*/	push ecx
	/*004115CD*/	push 0x1
	/*004115CF*/	push 0x5
	/*004115D1*/	push 0x1
	/*004115D3*/	push 0x2
	/*004115D5*/	push 0x8
	/*004115D7*/	push 0x16
	/*004115D9*/	push esi
	/*004115DA*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004115DF*/	push ebx
	/*004115E0*/	push 0xFFFFFFFF
	/*004115E2*/	push 0xFFFFFFFF
	/*004115E4*/	push 0xFFFFFFFF
	/*004115E6*/	push ebx
	/*004115E7*/	push 0x16
	/*004115E9*/	push esi
	/*004115EA*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004115EF*/	mov dx,word ptr ds:[edi+0x40]
	/*004115F3*/	add esp,0x40
	/*004115F6*/	push ebx
	/*004115F7*/	push edx
	/*004115F8*/	push 0x1
	/*004115FA*/	push 0x5
	/*004115FC*/	push 0x1
	/*004115FE*/	push 0x2
	/*00411600*/	push 0xF
	/*00411602*/	push 0x17
	/*00411604*/	push esi
	/*00411605*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041160A*/	push ebx
	/*0041160B*/	push 0xFFFFFFFF
	/*0041160D*/	push 0xFFFFFFFF
	/*0041160F*/	push 0xFFFFFFFF
	/*00411611*/	push ebx
	/*00411612*/	push 0x17
	/*00411614*/	push esi
	/*00411615*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041161A*/	add esp,0x40
	/*0041161D*/	mov eax,esi
	/*0041161F*/	pop edi
	/*00411620*/	pop esi
	/*00411621*/	pop ebx
	/*00411622*/	add esp,0x200
	/*00411628*/	ret 0x10
_0041162B:
	/*0041162B*/	xor ebx,ebx
	/*0041162D*/	cmp al,bl
	/*0041162F*/	mov eax,dword ptr ss:[esp+0x21C]
	/*00411636*/	jne _0041185E
	/*0041163C*/	cmp eax,ebx
	/*0041163E*/	je _00411646
	/*00411640*/	mov dword ptr ds:[eax],0x1
_00411646:
	/*00411646*/	mov eax,dword ptr ss:[esp+0x214]
	/*0041164D*/	mov ecx,dword ptr ss:[esp+0x218]
	/*00411654*/	push 0x28A
	/*00411659*/	mov word ptr ds:[eax],0xA
	/*0041165E*/	mov word ptr ds:[ecx],0x435
	/*00411663*/	call sub_944E46		/*call <cm0102.sub_944E46>*/
	/*00411668*/	mov esi,eax
	/*0041166A*/	add esp,0x4
	/*0041166D*/	cmp esi,ebx
	/*0041166F*/	jne _004116A4
	/*00411671*/	lea edx,dword ptr ss:[esp+0x10C]
	/*00411678*/	lea eax,dword ptr ss:[esp+0xC]
	/*0041167C*/	push edx
	/*0041167D*/	push eax
	/*0041167E*/	push ebx
	/*0041167F*/	push ebx
	/*00411680*/	push 0x987C20		/*push cm0102.987C20*/
	/*00411685*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0041168A*/	add esp,0x14
	/*0041168D*/	lea ecx,dword ptr ss:[esp+0x10C]
	/*00411694*/	lea edx,dword ptr ss:[esp+0xC]
	/*00411698*/	push 0x123
	/*0041169D*/	push ecx
	/*0041169E*/	push edx
	/*0041169F*/	jmp _004118BA
_004116A4:
	/*004116A4*/	mov ax,word ptr ds:[edi+0x40]
	/*004116A8*/	push ebx
	/*004116A9*/	push eax
	/*004116AA*/	push 0x1
	/*004116AC*/	push 0x5
	/*004116AE*/	push 0x1
	/*004116B0*/	push 0x2
	/*004116B2*/	push 0x1D
	/*004116B4*/	push ebx
	/*004116B5*/	push esi
	/*004116B6*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004116BB*/	push ebx
	/*004116BC*/	push 0xFFFFFFFF
	/*004116BE*/	push 0xFFFFFFFF
	/*004116C0*/	push 0xFFFFFFFF
	/*004116C2*/	push ebx
	/*004116C3*/	push ebx
	/*004116C4*/	push esi
	/*004116C5*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004116CA*/	mov cx,word ptr ds:[edi+0x40]
	/*004116CE*/	add esp,0x40
	/*004116D1*/	push ebx
	/*004116D2*/	push ecx
	/*004116D3*/	push 0x1
	/*004116D5*/	push 0x5
	/*004116D7*/	push 0x1
	/*004116D9*/	push 0x3
	/*004116DB*/	push 0x5
	/*004116DD*/	push 0x1
	/*004116DF*/	push esi
	/*004116E0*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004116E5*/	push ebx
	/*004116E6*/	push 0xFFFFFFFF
	/*004116E8*/	push 0xFFFFFFFF
	/*004116EA*/	push 0xFFFFFFFF
	/*004116EC*/	push ebx
	/*004116ED*/	push 0x1
	/*004116EF*/	push esi
	/*004116F0*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004116F5*/	mov dx,word ptr ds:[edi+0x40]
	/*004116F9*/	add esp,0x40
	/*004116FC*/	push ebx
	/*004116FD*/	push edx
	/*004116FE*/	push 0x1
	/*00411700*/	push 0x5
	/*00411702*/	push 0x1
	/*00411704*/	push 0x3
	/*00411706*/	push 0xC
	/*00411708*/	push 0x2
	/*0041170A*/	push esi
	/*0041170B*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411710*/	push ebx
	/*00411711*/	push 0xFFFFFFFF
	/*00411713*/	push 0xFFFFFFFF
	/*00411715*/	push 0xFFFFFFFF
	/*00411717*/	push ebx
	/*00411718*/	push 0x2
	/*0041171A*/	push esi
	/*0041171B*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411720*/	mov ax,word ptr ds:[edi+0x40]
	/*00411724*/	add esp,0x40
	/*00411727*/	push ebx
	/*00411728*/	push eax
	/*00411729*/	push 0x1
	/*0041172B*/	push 0x5
	/*0041172D*/	push 0x1
	/*0041172F*/	push 0x3
	/*00411731*/	push 0x11
	/*00411733*/	push 0x3
	/*00411735*/	push esi
	/*00411736*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041173B*/	push ebx
	/*0041173C*/	push 0xFFFFFFFF
	/*0041173E*/	push 0xFFFFFFFF
	/*00411740*/	push 0xFFFFFFFF
	/*00411742*/	push ebx
	/*00411743*/	push 0x3
	/*00411745*/	push esi
	/*00411746*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041174B*/	add esp,0x40
	/*0041174E*/	push ebx
	/*0041174F*/	mov cx,word ptr ds:[edi+0x40]
	/*00411753*/	push ecx
	/*00411754*/	push 0x1
	/*00411756*/	push 0x5
	/*00411758*/	push 0x1
	/*0041175A*/	push 0x3
	/*0041175C*/	push 0x18
	/*0041175E*/	push 0x4
	/*00411760*/	push esi
	/*00411761*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411766*/	push ebx
	/*00411767*/	push 0xFFFFFFFF
	/*00411769*/	push 0xFFFFFFFF
	/*0041176B*/	push 0xFFFFFFFF
	/*0041176D*/	push ebx
	/*0041176E*/	push 0x4
	/*00411770*/	push esi
	/*00411771*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411776*/	mov dx,word ptr ds:[edi+0x40]
	/*0041177A*/	add esp,0x40
	/*0041177D*/	push ebx
	/*0041177E*/	push edx
	/*0041177F*/	push 0x1
	/*00411781*/	push 0x5
	/*00411783*/	push 0x1
	/*00411785*/	push 0x5
	/*00411787*/	push 0x1
	/*00411789*/	push 0x5
	/*0041178B*/	push esi
	/*0041178C*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411791*/	push ebx
	/*00411792*/	push 0xFFFFFFFF
	/*00411794*/	push 0xFFFFFFFF
	/*00411796*/	push 0xFFFFFFFF
	/*00411798*/	push ebx
	/*00411799*/	push 0x5
	/*0041179B*/	push esi
	/*0041179C*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004117A1*/	mov ax,word ptr ds:[edi+0x40]
	/*004117A5*/	add esp,0x40
	/*004117A8*/	push ebx
	/*004117A9*/	push eax
	/*004117AA*/	push 0x1
	/*004117AC*/	push 0x5
	/*004117AE*/	push 0x1
	/*004117B0*/	push 0x5
	/*004117B2*/	push 0x8
	/*004117B4*/	push 0x6
	/*004117B6*/	push esi
	/*004117B7*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004117BC*/	push ebx
	/*004117BD*/	push 0xFFFFFFFF
	/*004117BF*/	push 0xFFFFFFFF
	/*004117C1*/	push 0xFFFFFFFF
	/*004117C3*/	push ebx
	/*004117C4*/	push 0x6
	/*004117C6*/	push esi
	/*004117C7*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004117CC*/	mov cx,word ptr ds:[edi+0x40]
	/*004117D0*/	add esp,0x40
	/*004117D3*/	push ebx
	/*004117D4*/	push ecx
	/*004117D5*/	push 0x1
	/*004117D7*/	push 0x5
	/*004117D9*/	push 0x1
	/*004117DB*/	push 0x5
	/*004117DD*/	push 0xF
	/*004117DF*/	push 0x7
	/*004117E1*/	push esi
	/*004117E2*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*004117E7*/	push ebx
	/*004117E8*/	push 0xFFFFFFFF
	/*004117EA*/	push 0xFFFFFFFF
	/*004117EC*/	push 0xFFFFFFFF
	/*004117EE*/	push ebx
	/*004117EF*/	push 0x7
	/*004117F1*/	push esi
	/*004117F2*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*004117F7*/	mov dx,word ptr ds:[edi+0x40]
	/*004117FB*/	add esp,0x40
	/*004117FE*/	push ebx
	/*004117FF*/	push edx
	/*00411800*/	push 0x1
	/*00411802*/	push 0x5
	/*00411804*/	push 0x1
	/*00411806*/	push 0x5
	/*00411808*/	push 0x16
	/*0041180A*/	push 0x8
	/*0041180C*/	push esi
	/*0041180D*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*00411812*/	push ebx
	/*00411813*/	push 0xFFFFFFFF
	/*00411815*/	push 0xFFFFFFFF
	/*00411817*/	push 0xFFFFFFFF
	/*00411819*/	push ebx
	/*0041181A*/	push 0x8
	/*0041181C*/	push esi
	/*0041181D*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*00411822*/	mov ax,word ptr ds:[edi+0x40]
	/*00411826*/	add esp,0x40
	/*00411829*/	push ebx
	/*0041182A*/	push eax
	/*0041182B*/	push 0x1
	/*0041182D*/	push 0x5
	/*0041182F*/	push 0x1
	/*00411831*/	push 0x5
	/*00411833*/	push 0x1D
	/*00411835*/	push 0x9
	/*00411837*/	push esi
	/*00411838*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0041183D*/	push ebx
	/*0041183E*/	push 0xFFFFFFFF
	/*00411840*/	push 0xFFFFFFFF
	/*00411842*/	push 0xFFFFFFFF
	/*00411844*/	push ebx
	/*00411845*/	push 0x9
	/*00411847*/	push esi
	/*00411848*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0041184D*/	add esp,0x40
	/*00411850*/	mov eax,esi
	/*00411852*/	pop edi
	/*00411853*/	pop esi
	/*00411854*/	pop ebx
	/*00411855*/	add esp,0x200
	/*0041185B*/	ret 0x10
_0041185E:
	/*0041185E*/	cmp eax,ebx
	/*00411860*/	je _00411864
	/*00411862*/	mov dword ptr ds:[eax],ebx
_00411864:
	/*00411864*/	mov ecx,dword ptr ss:[esp+0x214]
	/*0041186B*/	mov edx,dword ptr ss:[esp+0x218]
	/*00411872*/	push 0x68
	/*00411874*/	mov word ptr ds:[ecx],0x1
	/*00411879*/	mov word ptr ds:[edx],0x96
	/*0041187E*/	call sub_944E46		/*call <cm0102.sub_944E46>*/
	/*00411883*/	mov esi,eax
	/*00411885*/	add esp,0x4
	/*00411888*/	cmp esi,ebx
	/*0041188A*/	jne _004118F6
	/*0041188C*/	lea eax,dword ptr ss:[esp+0x10C]
	/*00411893*/	lea ecx,dword ptr ss:[esp+0xC]
	/*00411897*/	push eax
	/*00411898*/	push ecx
	/*00411899*/	push ebx
	/*0041189A*/	push ebx
	/*0041189B*/	push 0x987C20		/*push cm0102.987C20*/
	/*004118A0*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*004118A5*/	add esp,0x14
	/*004118A8*/	lea edx,dword ptr ss:[esp+0x10C]
	/*004118AF*/	lea eax,dword ptr ss:[esp+0xC]
	/*004118B3*/	push 0x164
	/*004118B8*/	push edx
	/*004118B9*/	push eax
_004118BA:
	/*004118BA*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*004118BF*/	push eax
	/*004118C0*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*004118C5*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*004118CA*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*004118CF*/	push ebx
	/*004118D0*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*004118D5*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*004118DA*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*004118DF*/	add esp,0x24
	/*004118E2*/	mov dword ptr ds:[0xB67A34],ebx
	/*004118E8*/	xor eax,eax
	/*004118EA*/	pop edi
	/*004118EB*/	pop esi
	/*004118EC*/	pop ebx
	/*004118ED*/	add esp,0x200
	/*004118F3*/	ret 0x10
_004118F6:
	/*004118F6*/	movsx ecx,word ptr ds:[edi+0x40]
	/*004118FA*/	push ecx
	/*004118FB*/	push ebx
	/*004118FC*/	push 0x1
	/*004118FE*/	push 0x6
	/*00411900*/	push 0x1
	/*00411902*/	push ebx
	/*00411903*/	push esi
	/*00411904*/	call sub_521E60		/*call <cm0102.sub_521E60>*/
	/*00411909*/	movsx edx,word ptr ds:[edi+0x40]
	/*0041190D*/	push ebx
	/*0041190E*/	push edx
	/*0041190F*/	push 0x1
	/*00411911*/	push 0x5
	/*00411913*/	push 0x1
	/*00411915*/	push 0x6
	/*00411917*/	push 0x7
	/*00411919*/	push ebx
	/*0041191A*/	push esi
	/*0041191B*/	call sub_521EB0		/*call <cm0102.sub_521EB0>*/
	/*00411920*/	mov word ptr ds:[esi+0x7],bx
	/*00411924*/	mov word ptr ds:[esi+0x9],bx
	/*00411928*/	mov word ptr ds:[esi+0xB],bx
	/*0041192C*/	mov word ptr ds:[esi+0xD],0x83
	/*00411932*/	mov byte ptr ds:[esi+0x17],0x5
	/*00411936*/	mov word ptr ds:[esi+0x18],0x2
	/*0041193C*/	mov word ptr ds:[esi+0x1A],0x1
	/*00411942*/	mov word ptr ds:[esi+0x1C],0x2
	/*00411948*/	mov word ptr ds:[esi+0xF],bx
	/*0041194C*/	mov word ptr ds:[esi+0x11],bx
	/*00411950*/	mov word ptr ds:[esi+0x1E],bx
	/*00411954*/	mov byte ptr ds:[esi+0x20],bl
	/*00411957*/	mov byte ptr ds:[esi+0x21],0x1
	/*0041195B*/	add esp,0x40
	/*0041195E*/	mov byte ptr ds:[esi+0x22],bl
	/*00411961*/	mov dword ptr ds:[esi+0x5C],ebx
	/*00411964*/	mov dword ptr ds:[esi+0x60],0x2EE0
	/*0041196B*/	mov dword ptr ds:[esi+0x64],0x1388
	/*00411972*/	mov eax,esi
	/*00411974*/	pop edi
	/*00411975*/	pop esi
	/*00411976*/	pop ebx
	/*00411977*/	add esp,0x200
	/*0041197D*/	ret 0x10
	/*00411980*/	mov al,byte ptr ss:[esp+0xC]
	/*00411984*/	cmp al,0xFF
	/*00411986*/	jne _004119BC
	/*00411988*/	mov al,byte ptr ss:[esp+0x8]
	/*0041198C*/	cmp al,0x6
	/*0041198E*/	jne _004119B2
	/*00411990*/	mov eax,dword ptr ds:[ecx+0x4]
	/*00411993*/	mov ecx,dword ptr ss:[esp+0x4]
	/*00411997*/	push 0x28
	/*00411999*/	push 0x0
	/*0041199B*/	push 0x435
	/*004119A0*/	push eax
	/*004119A1*/	push ecx
	/*004119A2*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*004119A8*/	call sub_86BDD0		/*call <cm0102.sub_86BDD0>*/
	/*004119AD*/	xor eax,eax
	/*004119AF*/	ret 0x18
_004119B2:
	/*004119B2*/	cmp al,0xFE
	/*004119B4*/	jne _00411A27
	/*004119B6*/	or eax,0xFFFFFFFF
	/*004119B9*/	ret 0x18
_004119BC:
	/*004119BC*/	test al,al
	/*004119BE*/	mov al,byte ptr ss:[esp+0x8]
	/*004119C2*/	jne _00411A0F
	/*004119C4*/	cmp al,0x6
	/*004119C6*/	jne _004119EA
	/*004119C8*/	mov edx,dword ptr ds:[ecx+0x4]
	/*004119CB*/	mov eax,dword ptr ss:[esp+0x4]
	/*004119CF*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*004119D5*/	push 0x28
	/*004119D7*/	push 0x96
	/*004119DC*/	push 0x0
	/*004119DE*/	push edx
	/*004119DF*/	push eax
	/*004119E0*/	call sub_86BDD0		/*call <cm0102.sub_86BDD0>*/
	/*004119E5*/	xor eax,eax
	/*004119E7*/	ret 0x18
_004119EA:
	/*004119EA*/	cmp al,0xFE
	/*004119EC*/	jne _00411A27
	/*004119EE*/	mov ecx,dword ptr ds:[ecx+0x4]
	/*004119F1*/	mov edx,dword ptr ss:[esp+0x4]
	/*004119F5*/	push 0x28
	/*004119F7*/	push 0x435
	/*004119FC*/	push ecx
	/*004119FD*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00411A03*/	push edx
	/*00411A04*/	call sub_86C1D0		/*call <cm0102.sub_86C1D0>*/
	/*00411A09*/	or eax,0xFFFFFFFF
	/*00411A0C*/	ret 0x18
_00411A0F:
	/*00411A0F*/	cmp al,0x1
	/*00411A11*/	jne _00411A27
	/*00411A13*/	mov eax,dword ptr ds:[ecx+0x4]
	/*00411A16*/	mov ecx,dword ptr ss:[esp+0x4]
	/*00411A1A*/	push eax
	/*00411A1B*/	push ecx
	/*00411A1C*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00411A22*/	call sub_868C50		/*call <cm0102.sub_868C50>*/
_00411A27:
	/*00411A27*/	xor eax,eax
	/*00411A29*/	ret 0x18
	/*00411A2C*/	nop
	/*00411A2D*/	nop
	/*00411A2E*/	nop
	/*00411A2F*/	nop
	/*00411A30*/	mov al,byte ptr ss:[esp+0xC]
	/*00411A34*/	push esi
	/*00411A35*/	cmp al,0xFF
	/*00411A37*/	push edi
	/*00411A38*/	jne _00411AAD
	/*00411A3A*/	cmp byte ptr ss:[esp+0x10],0x6
	/*00411A3F*/	jne _00411B5C
	/*00411A45*/	mov eax,dword ptr ss:[esp+0x2C]
	/*00411A49*/	test eax,eax
	/*00411A4B*/	jne _00411AC4
	/*00411A4D*/	mov eax,dword ptr ss:[esp+0xC]
	/*00411A51*/	lea ecx,dword ptr ds:[eax+eax*0x8]
	/*00411A54*/	shl ecx,0x4
	/*00411A57*/	add ecx,eax
	/*00411A59*/	lea esi,dword ptr ds:[eax+ecx*0x4]
	/*00411A5C*/	mov ecx,dword ptr ds:[0xAE23B4]
	/*00411A62*/	movsx eax,byte ptr ds:[esi+ecx+0x52]
	/*00411A67*/	lea edx,dword ptr ds:[esi+ecx+0x38]
	/*00411A6B*/	push edx
	/*00411A6C*/	push eax
	/*00411A6D*/	push eax
	/*00411A6E*/	push 0x987C88		/*push cm0102.987C88*/
_00411A73:
	/*00411A73*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*00411A78*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*00411A7D*/	mov edi,dword ptr ss:[esp+0x44]
	/*00411A81*/	add esp,0x14
	/*00411A84*/	mov ecx,edi
	/*00411A86*/	push 0xDE1F64		/*push cm0102.DE1F64*/
	/*00411A8B*/	call sub_4AE660		/*call <cm0102.sub_4AE660>*/
	/*00411A90*/	mov eax,dword ptr ds:[0xAE23B4]
	/*00411A95*/	mov ecx,edi
	/*00411A97*/	add eax,esi
	/*00411A99*/	push eax
	/*00411A9A*/	add eax,0x38
	/*00411A9D*/	push 0x7D5
	/*00411AA2*/	push eax
	/*00411AA3*/	call sub_4AE8A0		/*call <cm0102.sub_4AE8A0>*/
	/*00411AA8*/	pop edi
	/*00411AA9*/	pop esi
	/*00411AAA*/	ret 0x28
_00411AAD:
	/*00411AAD*/	test al,al
	/*00411AAF*/	jne _00411B12
	/*00411AB1*/	cmp byte ptr ss:[esp+0x10],0x6
	/*00411AB6*/	jne _00411B5C
	/*00411ABC*/	mov eax,dword ptr ss:[esp+0x2C]
	/*00411AC0*/	test eax,eax
	/*00411AC2*/	je _00411AE7
_00411AC4:
	/*00411AC4*/	mov edx,dword ptr ss:[esp+0x30]
	/*00411AC8*/	push edx
	/*00411AC9*/	mov edx,dword ptr ss:[esp+0x10]
	/*00411ACD*/	push eax
	/*00411ACE*/	mov eax,dword ptr ds:[ecx+0x4]
	/*00411AD1*/	mov ecx,dword ptr ss:[esp+0x20]
	/*00411AD5*/	push 0x6
	/*00411AD7*/	push eax
	/*00411AD8*/	push ecx
	/*00411AD9*/	push edx
	/*00411ADA*/	call sub_4B4590		/*call <cm0102.sub_4B4590>*/
	/*00411ADF*/	add esp,0x18
	/*00411AE2*/	pop edi
	/*00411AE3*/	pop esi
	/*00411AE4*/	ret 0x28
_00411AE7:
	/*00411AE7*/	mov eax,dword ptr ss:[esp+0xC]
	/*00411AEB*/	lea ecx,dword ptr ds:[eax+eax*0x8]
	/*00411AEE*/	shl ecx,0x4
	/*00411AF1*/	add ecx,eax
	/*00411AF3*/	lea esi,dword ptr ds:[eax+ecx*0x4]
	/*00411AF6*/	mov ecx,dword ptr ds:[0xAE23B4]
	/*00411AFC*/	movsx eax,byte ptr ds:[esi+ecx+0x52]
	/*00411B01*/	lea edx,dword ptr ds:[esi+ecx+0x38]
	/*00411B05*/	push edx
	/*00411B06*/	push eax
	/*00411B07*/	push eax
	/*00411B08*/	push 0x987C58		/*push cm0102.987C58*/
	/*00411B0D*/	jmp _00411A73
_00411B12:
	/*00411B12*/	mov eax,dword ptr ss:[esp+0x2C]
	/*00411B16*/	mov ecx,dword ptr ss:[esp+0x30]
	/*00411B1A*/	test eax,eax
	/*00411B1C*/	push ecx
	/*00411B1D*/	je _00411B45
	/*00411B1F*/	mov edx,dword ptr ss:[esp+0x24]
	/*00411B23*/	mov eax,dword ptr ss:[esp+0x14]
	/*00411B27*/	mov ecx,dword ptr ss:[esp+0x2C]
	/*00411B2B*/	push edx
	/*00411B2C*/	mov edx,dword ptr ss:[esp+0x24]
	/*00411B30*/	push eax
	/*00411B31*/	mov eax,dword ptr ss:[esp+0x18]
	/*00411B35*/	push ecx
	/*00411B36*/	push edx
	/*00411B37*/	push eax
	/*00411B38*/	call sub_4B0B80		/*call <cm0102.sub_4B0B80>*/
	/*00411B3D*/	add esp,0x18
	/*00411B40*/	pop edi
	/*00411B41*/	pop esi
	/*00411B42*/	ret 0x28
_00411B45:
	/*00411B45*/	mov edx,dword ptr ss:[esp+0x14]
	/*00411B49*/	mov eax,dword ptr ss:[esp+0x20]
	/*00411B4D*/	mov ecx,dword ptr ss:[esp+0x10]
	/*00411B51*/	push edx
	/*00411B52*/	push eax
	/*00411B53*/	push ecx
	/*00411B54*/	call sub_4B4420		/*call <cm0102.sub_4B4420>*/
	/*00411B59*/	add esp,0x10
_00411B5C:
	/*00411B5C*/	pop edi
	/*00411B5D*/	pop esi
	/*00411B5E*/	ret 0x28
	}
}

void __declspec(naked) sub_412C20_australia_rules()
{
	__asm
	{
	/*00412C20*/	mov eax,dword ptr ds:[aus_league_id]
	/*00412C25*/	push esi
	/*00412C26*/	mov esi,ecx
	/*00412C28*/	push eax
	/*00412C29*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00412C2F*/	call sub_86F950		/*call <cm0102.sub_86F950>*/
	/*00412C34*/	test eax,eax
	/*00412C36*/	je _00412C5B
	/*00412C38*/	mov ecx,dword ptr ds:[0xDD7F00]
	/*00412C3E*/	mov dx,word ptr ds:[ecx+0x16]
	/*00412C42*/	mov cl,byte ptr ds:[ecx+0x14]
	/*00412C45*/	push edx
	/*00412C46*/	mov edx,dword ptr ds:[eax+0x39]
	/*00412C49*/	push ecx
	/*00412C4A*/	mov ecx,dword ptr ds:[edx]
	/*00412C4C*/	mov edx,dword ptr ds:[eax]
	/*00412C4E*/	mov eax,dword ptr ds:[esi+0x4]
	/*00412C51*/	push ecx
	/*00412C52*/	push edx
	/*00412C53*/	mov ecx,dword ptr ds:[eax+0x4]
	/*00412C56*/	call sub_7671C0		/*call <cm0102.sub_7671C0>*/
_00412C5B:
	/*00412C5B*/	mov ecx,dword ptr ds:[esi+0xA]
	/*00412C5E*/	mov edx,dword ptr ds:[esi+0x4]
	/*00412C61*/	push 0xFFFFFFFF
	/*00412C63*/	push ecx
	/*00412C64*/	mov ecx,dword ptr ds:[edx+0x8]
	/*00412C67*/	call sub_767150		/*call <cm0102.sub_767150>*/
	/*00412C6C*/	mov ecx,dword ptr ds:[esi+0x4]
	/*00412C6F*/	mov eax,dword ptr ds:[esi+0xA]
	/*00412C72*/	push 0x15
	/*00412C74*/	push eax
	/*00412C75*/	mov ecx,dword ptr ds:[ecx+0xC]
	/*00412C78*/	call sub_767150		/*call <cm0102.sub_767150>*/
	/*00412C7D*/	pop esi
	/*00412C7E*/	ret
	}
}

void __declspec(naked) sub_412540_australia_awards()
{
	__asm pushad
	WriteDWORD(0x96781C, (DWORD)&sub_412680_australia_awards);		// change the vtable
	__asm popad

	__asm
	{
	/*00412540*/	push 0xFFFFFFFF
	/*00412542*/	push 0x953A69		/*push <cm0102.sub_953A69>*/
	/*00412547*/	mov eax,dword ptr fs:[0x0]
	/*0041254D*/	push eax
	/*0041254E*/	mov dword ptr fs:[0x0],esp
	/*00412555*/	sub esp,0x208
	/*0041255B*/	push esi
	/*0041255C*/	mov esi,ecx
	/*0041255E*/	push edi
	/*0041255F*/	mov dword ptr ss:[esp+0xC],esi
	/*00412563*/	call sub_768290		/*call <cm0102.sub_768290>*/
	/*00412568*/	mov dword ptr ds:[esi], 0x96781C		/*mov dword ptr ds:[esi],<cm0102.&sub_412680>*/  // This address is a ptr to the vtable - so can't just replace this one as it gets used as an offset i.e. call [esi+4]
	/*0041256E*/	mov eax,dword ptr ds:[aus_nation_id]		// Australia 0x9CF224
	/*00412573*/	mov edx,dword ptr ds:[0xAE23A8]
	/*00412579*/	mov edi,dword ptr ss:[esp+0x220]
	/*00412580*/	lea ecx,dword ptr ds:[eax+eax*0x8]
	/*00412583*/	mov dword ptr ss:[esp+0x218],0x0
	/*0041258E*/	shl ecx,0x4
	/*00412591*/	add ecx,eax
	/*00412593*/	mov dword ptr ds:[esi+0x13],0x18
	/*0041259A*/	test edi,edi
	/*0041259C*/	lea eax,dword ptr ds:[edx+ecx*0x2]
	/*0041259F*/	mov byte ptr ds:[esi+0x12],0x1
	/*004125A3*/	mov dword ptr ds:[esi+0xE],eax
	/*004125A6*/	je _004125B8
	/*004125A8*/	push edi
	/*004125A9*/	mov ecx,esi
	/*004125AB*/	call sub_76A280		/*call <cm0102.sub_76A280>*/
	/*004125B0*/	test eax,eax
	/*004125B2*/	jne _00412656
_004125B8:
	/*004125B8*/	push 0xF
	/*004125BA*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*004125BF*/	add esp,0x4
	/*004125C2*/	mov dword ptr ss:[esp+0x8],eax
	/*004125C6*/	test eax,eax
	/*004125C8*/	mov byte ptr ss:[esp+0x218],0x1
	/*004125D0*/	je _004125DD
	/*004125D2*/	push 0x0
	/*004125D4*/	mov ecx,eax
	/*004125D6*/	call sub_767AF0		/*call cm0102.767AF0*/
	/*004125DB*/	jmp _004125DF
_004125DD:
	/*004125DD*/	xor eax,eax
_004125DF:
	/*004125DF*/	test eax,eax
	/*004125E1*/	mov byte ptr ss:[esp+0x218],0x0
	/*004125E9*/	mov dword ptr ds:[esi+0xA],eax
	/*004125EC*/	jne _0041264E
	/*004125EE*/	lea ecx,dword ptr ss:[esp+0x10]
	/*004125F2*/	lea edx,dword ptr ss:[esp+0x110]
	/*004125F9*/	push ecx
	/*004125FA*/	push edx
	/*004125FB*/	push eax
	/*004125FC*/	push eax
	/*004125FD*/	push 0x987CC0		/*push cm0102.987CC0*/
	/*00412602*/	call sub_944CFF_splitpath		/*call <cm0102.sub_splitpath>*/
	/*00412607*/	add esp,0x14
	/*0041260A*/	lea eax,dword ptr ss:[esp+0x10]
	/*0041260E*/	lea ecx,dword ptr ss:[esp+0x110]
	/*00412615*/	push 0x4C
	/*00412617*/	push eax
	/*00412618*/	push ecx
	/*00412619*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0041261E*/	push eax
	/*0041261F*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00412624*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00412629*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0041262E*/	push 0x0
	/*00412630*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00412635*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0041263A*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0041263F*/	add esp,0x24
	/*00412642*/	mov dword ptr ds:[0xB67A34],0x0
	/*0041264C*/	jmp _00412656
_0041264E:
	/*0041264E*/	push edi
	/*0041264F*/	mov ecx,esi
	/*00412651*/	call sub_412680_australia_awards		/*call <cm0102.sub_412680>*/
_00412656:
	/*00412656*/	mov ecx,dword ptr ss:[esp+0x210]
	/*0041265D*/	mov eax,esi
	/*0041265F*/	pop edi
	/*00412660*/	pop esi
	/*00412661*/	mov dword ptr fs:[0x0],ecx
	/*00412668*/	add esp,0x214
	/*0041266E*/	ret 0x4
	}
}

void __declspec(naked) sub_412680_australia_awards()
{
	__asm
	{
	/*00412680*/	push 0xFFFFFFFF
	/*00412682*/	push 0x953AFE		/*push <cm0102.sub_953AFE>*/
	/*00412687*/	mov eax,dword ptr fs:[0x0]
	/*0041268D*/	push eax
	/*0041268E*/	mov dword ptr fs:[0x0],esp
	/*00412695*/	sub esp,0x208
	/*0041269B*/	mov ax,word ptr ds:[0xAE2C92]
	/*004126A1*/	push ebp
	/*004126A2*/	push esi
	/*004126A3*/	mov ebp,ecx
	/*004126A5*/	push edi
	/*004126A6*/	push 0x24
	/*004126A8*/	mov edi,dword ptr ss:[ebp+0x13]
	/*004126AB*/	mov word ptr ss:[esp+0x14],ax
	/*004126B0*/	xor esi,esi
	/*004126B2*/	mov word ptr ss:[ebp+0x8],0x9
	/*004126B8*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*004126BD*/	add esp,0x4
	/*004126C0*/	cmp eax,esi
	/*004126C2*/	mov dword ptr ss:[ebp+0x4],eax
	/*004126C5*/	jne _00412725
	/*004126C7*/	lea ecx,dword ptr ss:[esp+0x14]
	/*004126CB*/	lea edx,dword ptr ss:[esp+0x114]
	/*004126D2*/	push ecx
	/*004126D3*/	push edx
	/*004126D4*/	push esi
	/*004126D5*/	push esi
	/*004126D6*/	push 0x987CC0		/*push cm0102.987CC0*/
	/*004126DB*/	call sub_944CFF_splitpath		/*call <cm0102.sub_splitpath>*/
	/*004126E0*/	add esp,0x14
	/*004126E3*/	lea eax,dword ptr ss:[esp+0x14]
	/*004126E7*/	lea ecx,dword ptr ss:[esp+0x114]
	/*004126EE*/	push 0x74
	/*004126F0*/	push eax
	/*004126F1*/	push ecx
	/*004126F2*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*004126F7*/	push eax
	/*004126F8*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*004126FD*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00412702*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*00412707*/	push esi
	/*00412708*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0041270D*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00412712*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*00412717*/	add esp,0x24
	/*0041271A*/	mov dword ptr ds:[0xB67A34],esi
	/*00412720*/	jmp _00412A98
_00412725:
	/*00412725*/	push ebx
	/*00412726*/	push 0x25D
	/*0041272B*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*00412730*/	add esp,0x4
	/*00412733*/	mov dword ptr ss:[esp+0x10],eax
	/*00412737*/	mov ebx,dword ptr ss:[esp+0x228]
	/*0041273E*/	cmp eax,esi
	/*00412740*/	mov dword ptr ss:[esp+0x220],esi
	/*00412747*/	je _00412777
	/*00412749*/	mov edx,dword ptr ds:[aus_league_id]				// 0x9CF89C
	/*0041274F*/	mov ecx,dword ptr ds:[0x9CFE7C]
	/*00412755*/	mov esi,0x1
	/*0041275A*/	push esi
	/*0041275B*/	push ebx
	/*0041275C*/	push 0x0
	/*0041275E*/	push esi
	/*0041275F*/	push edx
	/*00412760*/	push 0x1F4
	/*00412765*/	push 0x3E8
	/*0041276A*/	push ecx
	/*0041276B*/	push 0x0
	/*0041276D*/	push edi
	/*0041276E*/	mov ecx,eax
	/*00412770*/	call sub_8AF520		/*call <cm0102.sub_8AF520>*/
	/*00412775*/	jmp _00412779
_00412777:
	/*00412777*/	xor eax,eax
_00412779:
	/*00412779*/	mov edx,dword ptr ss:[ebp+0x4]
	/*0041277C*/	push 0xA2
	/*00412781*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*0041278C*/	mov dword ptr ds:[edx],eax
	/*0041278E*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*00412793*/	add esp,0x4
	/*00412796*/	mov dword ptr ss:[esp+0x10],eax
	/*0041279A*/	test eax,eax
	/*0041279C*/	mov dword ptr ss:[esp+0x220],0x1
	/*004127A7*/	je _004127E1
	/*004127A9*/	mov edx,dword ptr ss:[esp+0x14]
	/*004127AD*/	mov ecx,esi
	/*004127AF*/	inc esi
	/*004127B0*/	push 0x0
	/*004127B2*/	inc edx
	/*004127B3*/	push ebx
	/*004127B4*/	push edx
	/*004127B5*/	mov edx,dword ptr ss:[esp+0x20]
	/*004127B9*/	push 0x4
	/*004127BB*/	push edx
	/*004127BC*/	mov edx,dword ptr ds:[aus_league_id]
	/*004127C2*/	push 0x9
	/*004127C4*/	push edx
	/*004127C5*/	mov edx,dword ptr ds:[0x9CFE80]
	/*004127CB*/	push 0x2BC
	/*004127D0*/	push 0x5DC
	/*004127D5*/	push edx
	/*004127D6*/	push ecx
	/*004127D7*/	push edi
	/*004127D8*/	mov ecx,eax
	/*004127DA*/	call sub_766E10		/*call <cm0102.sub_766E10>*/
	/*004127DF*/	jmp _004127E3
_004127E1:
	/*004127E1*/	xor eax,eax
_004127E3:
	/*004127E3*/	mov ecx,dword ptr ss:[ebp+0x4]
	/*004127E6*/	push 0xA2
	/*004127EB*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*004127F6*/	mov dword ptr ds:[ecx+0x4],eax
	/*004127F9*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*004127FE*/	add esp,0x4
	/*00412801*/	mov dword ptr ss:[esp+0x10],eax
	/*00412805*/	test eax,eax
	/*00412807*/	mov dword ptr ss:[esp+0x220],0x2
	/*00412812*/	je _0041284C
	/*00412814*/	mov ecx,dword ptr ss:[esp+0x14]
	/*00412818*/	mov edx,esi
	/*0041281A*/	inc esi
	/*0041281B*/	push 0x1
	/*0041281D*/	inc ecx
	/*0041281E*/	push ebx
	/*0041281F*/	push ecx
	/*00412820*/	mov ecx,dword ptr ss:[esp+0x20]
	/*00412824*/	push 0x4
	/*00412826*/	push ecx
	/*00412827*/	mov ecx,dword ptr ds:[aus_league_id]
	/*0041282D*/	push 0x9
	/*0041282F*/	push ecx
	/*00412830*/	mov ecx,dword ptr ds:[0x9CFE84]
	/*00412836*/	push 0x1F4
	/*0041283B*/	push 0x3E8
	/*00412840*/	push ecx
	/*00412841*/	push edx
	/*00412842*/	push edi
	/*00412843*/	mov ecx,eax
	/*00412845*/	call sub_766E10		/*call <cm0102.sub_766E10>*/
	/*0041284A*/	jmp _0041284E
_0041284C:
	/*0041284C*/	xor eax,eax
_0041284E:
	/*0041284E*/	mov edx,dword ptr ss:[ebp+0x4]
	/*00412851*/	push 0xA2
	/*00412856*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*00412861*/	mov dword ptr ds:[edx+0x8],eax
	/*00412864*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*00412869*/	add esp,0x4
	/*0041286C*/	mov dword ptr ss:[esp+0x10],eax
	/*00412870*/	test eax,eax
	/*00412872*/	mov dword ptr ss:[esp+0x220],0x3
	/*0041287D*/	je _004128B7
	/*0041287F*/	mov edx,dword ptr ss:[esp+0x14]
	/*00412883*/	mov ecx,esi
	/*00412885*/	inc esi
	/*00412886*/	push 0x1
	/*00412888*/	inc edx
	/*00412889*/	push ebx
	/*0041288A*/	push edx
	/*0041288B*/	mov edx,dword ptr ss:[esp+0x20]
	/*0041288F*/	push 0x4
	/*00412891*/	push edx
	/*00412892*/	mov edx,dword ptr ds:[aus_league_id]
	/*00412898*/	push 0x9
	/*0041289A*/	push edx
	/*0041289B*/	mov edx,dword ptr ds:[0x9CFE88]
	/*004128A1*/	push 0x190
	/*004128A6*/	push 0x320
	/*004128AB*/	push edx
	/*004128AC*/	push ecx
	/*004128AD*/	push edi
	/*004128AE*/	mov ecx,eax
	/*004128B0*/	call sub_766E10		/*call <cm0102.sub_766E10>*/
	/*004128B5*/	jmp _004128B9
_004128B7:
	/*004128B7*/	xor eax,eax
_004128B9:
	/*004128B9*/	mov ecx,dword ptr ss:[ebp+0x4]
	/*004128BC*/	push 0x2B
	/*004128BE*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*004128C9*/	mov dword ptr ds:[ecx+0xC],eax
	/*004128CC*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*004128D1*/	add esp,0x4
	/*004128D4*/	mov dword ptr ss:[esp+0x10],eax
	/*004128D8*/	test eax,eax
	/*004128DA*/	mov dword ptr ss:[esp+0x220],0x4
	/*004128E5*/	je _00412916
	/*004128E7*/	mov edx,dword ptr ds:[aus_league_id]
	/*004128ED*/	push 0x1
	/*004128EF*/	push ebx
	/*004128F0*/	push 0x0
	/*004128F2*/	push 0x0
	/*004128F4*/	push 0x1
	/*004128F6*/	push edx
	/*004128F7*/	mov edx,dword ptr ds:[0x9CFE8C]
	/*004128FD*/	push 0x3E8
	/*00412902*/	mov ecx,esi
	/*00412904*/	push 0x7D0
	/*00412909*/	push edx
	/*0041290A*/	push ecx
	/*0041290B*/	push edi
	/*0041290C*/	mov ecx,eax
	/*0041290E*/	inc esi
	/*0041290F*/	call sub_92FE80		/*call <cm0102.sub_92FE80>*/
	/*00412914*/	jmp _00412918
_00412916:
	/*00412916*/	xor eax,eax
_00412918:
	/*00412918*/	mov ecx,dword ptr ss:[ebp+0x4]
	/*0041291B*/	push 0x2B
	/*0041291D*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*00412928*/	mov dword ptr ds:[ecx+0x10],eax
	/*0041292B*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*00412930*/	add esp,0x4
	/*00412933*/	mov dword ptr ss:[esp+0x10],eax
	/*00412937*/	test eax,eax
	/*00412939*/	mov dword ptr ss:[esp+0x220],0x5
	/*00412944*/	je _00412975
	/*00412946*/	mov edx,dword ptr ds:[aus_league_id]
	/*0041294C*/	push 0x1
	/*0041294E*/	push ebx
	/*0041294F*/	push 0x0
	/*00412951*/	push 0x0
	/*00412953*/	push 0x1
	/*00412955*/	push edx
	/*00412956*/	mov edx,dword ptr ds:[0x9CFE90]
	/*0041295C*/	push 0x2EE
	/*00412961*/	mov ecx,esi
	/*00412963*/	push 0x5DC
	/*00412968*/	push edx
	/*00412969*/	push ecx
	/*0041296A*/	push edi
	/*0041296B*/	mov ecx,eax
	/*0041296D*/	inc esi
	/*0041296E*/	call sub_92FE80		/*call <cm0102.sub_92FE80>*/
	/*00412973*/	jmp _00412977
_00412975:
	/*00412975*/	xor eax,eax
_00412977:
	/*00412977*/	mov ecx,dword ptr ss:[ebp+0x4]
	/*0041297A*/	push 0x2B
	/*0041297C*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*00412987*/	mov dword ptr ds:[ecx+0x14],eax
	/*0041298A*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*0041298F*/	add esp,0x4
	/*00412992*/	mov dword ptr ss:[esp+0x10],eax
	/*00412996*/	test eax,eax
	/*00412998*/	mov dword ptr ss:[esp+0x220],0x6
	/*004129A3*/	je _004129D4
	/*004129A5*/	mov edx,dword ptr ds:[aus_league_id]
	/*004129AB*/	push 0x1
	/*004129AD*/	push ebx
	/*004129AE*/	push 0x0
	/*004129B0*/	push 0x0
	/*004129B2*/	push 0x1
	/*004129B4*/	push edx
	/*004129B5*/	mov edx,dword ptr ds:[0x9CFE94]
	/*004129BB*/	push 0x2EE
	/*004129C0*/	mov ecx,esi
	/*004129C2*/	push 0x5DC
	/*004129C7*/	push edx
	/*004129C8*/	push ecx
	/*004129C9*/	push edi
	/*004129CA*/	mov ecx,eax
	/*004129CC*/	inc esi
	/*004129CD*/	call sub_92FE80		/*call <cm0102.sub_92FE80>*/
	/*004129D2*/	jmp _004129D6
_004129D4:
	/*004129D4*/	xor eax,eax
_004129D6:
	/*004129D6*/	mov ecx,dword ptr ss:[ebp+0x4]
	/*004129D9*/	push 0x2B
	/*004129DB*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*004129E6*/	mov dword ptr ds:[ecx+0x18],eax
	/*004129E9*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*004129EE*/	add esp,0x4
	/*004129F1*/	mov dword ptr ss:[esp+0x10],eax
	/*004129F5*/	test eax,eax
	/*004129F7*/	mov dword ptr ss:[esp+0x220],0x7
	/*00412A02*/	je _00412A33
	/*00412A04*/	mov edx,dword ptr ds:[aus_league_id]
	/*00412A0A*/	push 0x1
	/*00412A0C*/	push ebx
	/*00412A0D*/	push 0x1
	/*00412A0F*/	push 0x0
	/*00412A11*/	push 0x1
	/*00412A13*/	push edx
	/*00412A14*/	mov edx,dword ptr ds:[0x9CFE98]
	/*00412A1A*/	push 0x2EE
	/*00412A1F*/	mov ecx,esi
	/*00412A21*/	push 0x5DC
	/*00412A26*/	push edx
	/*00412A27*/	push ecx
	/*00412A28*/	push edi
	/*00412A29*/	mov ecx,eax
	/*00412A2B*/	inc esi
	/*00412A2C*/	call sub_92FE80		/*call <cm0102.sub_92FE80>*/
	/*00412A31*/	jmp _00412A35
_00412A33:
	/*00412A33*/	xor eax,eax
_00412A35:
	/*00412A35*/	mov ecx,dword ptr ss:[ebp+0x4]
	/*00412A38*/	push 0x2B
	/*00412A3A*/	mov dword ptr ss:[esp+0x224],0xFFFFFFFF
	/*00412A45*/	mov dword ptr ds:[ecx+0x1C],eax
	/*00412A48*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*00412A4D*/	add esp,0x4
	/*00412A50*/	mov dword ptr ss:[esp+0x10],eax
	/*00412A54*/	test eax,eax
	/*00412A56*/	mov dword ptr ss:[esp+0x220],0x8
	/*00412A61*/	je _00412A8F
	/*00412A63*/	mov edx,dword ptr ds:[aus_league_id]
	/*00412A69*/	mov ecx,dword ptr ds:[0x9CFE9C]
	/*00412A6F*/	push 0x0
	/*00412A71*/	push ebx
	/*00412A72*/	push 0x0
	/*00412A74*/	push 0x0
	/*00412A76*/	push 0x1
	/*00412A78*/	push edx
	/*00412A79*/	push 0x2EE
	/*00412A7E*/	push 0x5DC
	/*00412A83*/	push ecx
	/*00412A84*/	push esi
	/*00412A85*/	push edi
	/*00412A86*/	mov ecx,eax
	/*00412A88*/	call sub_92FE80		/*call <cm0102.sub_92FE80>*/
	/*00412A8D*/	jmp _00412A91
_00412A8F:
	/*00412A8F*/	xor eax,eax
_00412A91:
	/*00412A91*/	mov edx,dword ptr ss:[ebp+0x4]
	/*00412A94*/	pop ebx
	/*00412A95*/	mov dword ptr ds:[edx+0x20],eax
_00412A98:
	/*00412A98*/	mov ecx,dword ptr ss:[esp+0x214]
	/*00412A9F*/	pop edi
	/*00412AA0*/	pop esi
	/*00412AA1*/	pop ebp
	/*00412AA2*/	mov dword ptr fs:[0x0],ecx
	/*00412AA9*/	add esp,0x214
	/*00412AAF*/	ret 0x4
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void __declspec(naked) sub_411D90()
{
	__asm
	{
	/*00411D90*/	mov eax,dword ptr ds:[ecx+0xC]
	/*00411D93*/	push esi
	/*00411D94*/	push edi
	/*00411D95*/	xor edi,edi
	/*00411D97*/	mov eax,dword ptr ds:[eax+0x4]
	/*00411D9A*/	xor esi,esi
	/*00411D9C*/	mov dx,word ptr ds:[eax+0x3E]
	/*00411DA0*/	test dx,dx
	/*00411DA3*/	jle _00411DC7
	/*00411DA5*/	mov eax,dword ptr ds:[eax+0xA7]
	/*00411DAB*/	push ebx
	/*00411DAC*/	movsx ebx,dx
_00411DAF:
	/*00411DAF*/	mov dl,byte ptr ds:[eax+0x5]
	/*00411DB2*/	cmp dl,0x1
	/*00411DB5*/	jne _00411DB9
	/*00411DB7*/	mov edi,dword ptr ds:[eax]
_00411DB9:
	/*00411DB9*/	cmp dl,0x2
	/*00411DBC*/	jne _00411DC0
	/*00411DBE*/	mov esi,dword ptr ds:[eax]
_00411DC0:
	/*00411DC0*/	add eax,0x6
	/*00411DC3*/	dec ebx
	/*00411DC4*/	jne _00411DAF
	/*00411DC6*/	pop ebx
_00411DC7:
	/*00411DC7*/	mov edx,dword ptr ds:[ecx+0xB1]
	/*00411DCD*/	push 0x0
	/*00411DCF*/	mov eax,dword ptr ds:[edx]
	/*00411DD1*/	push eax
	/*00411DD2*/	push esi
	/*00411DD3*/	push edi
	/*00411DD4*/	push ecx
	/*00411DD5*/	call sub_4AFCE0		/*call <cm0102.sub_4AFCE0>*/
	/*00411DDA*/	add esp,0x14
	/*00411DDD*/	pop edi
	/*00411DDE*/	pop esi
	/*00411DDF*/	ret
	}
}

void __declspec(naked) sub_411DE0()			// End of season function?
{
	__asm
	{
	/*00411DE0*/	sub esp,0x200
	/*00411DE6*/	push esi
	/*00411DE7*/	push edi
	/*00411DE8*/	mov esi,ecx
	/*00411DEA*/	xor edi,edi
	/*00411DEC*/	push edi
	/*00411DED*/	mov dword ptr ds:[esi+0x4C],edi
	/*00411DF0*/	call sub_687970		/*call <cm0102.sub_687970>*/
	/*00411DF5*/	mov eax,dword ptr ds:[esi+0xBA]
	/*00411DFB*/	cmp eax,edi
	/*00411DFD*/	je _00411E0E
	/*00411DFF*/	push eax
	/*00411E00*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*00411E05*/	add esp,0x4
	/*00411E08*/	mov dword ptr ds:[esi+0xBA],edi
_00411E0E:
	/*00411E0E*/	mov ecx,dword ptr ds:[esi+0x8]
	/*00411E11*/	cmp ecx,edi
	/*00411E13*/	je _00411E1C
	/*00411E15*/	push 0x1
	/*00411E17*/	call sub_4A1C50		/*call <cm0102.sub_4A1C50>*/
_00411E1C:
	/*00411E1C*/	mov eax,dword ptr ds:[esi]
	/*00411E1E*/	inc word ptr ds:[esi+0x40]
	/*00411E22*/	mov ecx,esi
	/*00411E24*/	call dword ptr ds:[eax+0x8C]
	/*00411E2A*/	test eax,eax
	/*00411E2C*/	jne _00411E60
	/*00411E2E*/	lea ecx,dword ptr ss:[esp+0x8]
	/*00411E32*/	lea edx,dword ptr ss:[esp+0x108]
	/*00411E39*/	push ecx
	/*00411E3A*/	push edx
	/*00411E3B*/	push edi
	/*00411E3C*/	push edi
	/*00411E3D*/	push 0x987C20		/*push cm0102.987C20*/
	/*00411E42*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*00411E47*/	add esp,0x14
	/*00411E4A*/	lea eax,dword ptr ss:[esp+0x8]
	/*00411E4E*/	lea ecx,dword ptr ss:[esp+0x108]
	/*00411E55*/	push 0x2BD
	/*00411E5A*/	push eax
	/*00411E5B*/	jmp _00411F0F
_00411E60:
	/*00411E60*/	// mov ecx,esi
	/*00411E62*/	// call sub_411B70		/*call <cm0102.sub_411B70>*/				/// Add Teams ?
					push esi
					call add_teams
					add esp, 0x4

	/*00411E67*/	test eax,eax
	/*00411E69*/	jne _00411E9B
	/*00411E6B*/	lea edx,dword ptr ss:[esp+0x108]
	/*00411E72*/	lea eax,dword ptr ss:[esp+0x8]
	/*00411E76*/	push edx
	/*00411E77*/	push eax
	/*00411E78*/	push edi
	/*00411E79*/	push edi
	/*00411E7A*/	push 0x987C20		/*push cm0102.987C20*/
	/*00411E7F*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*00411E84*/	add esp,0x14
	/*00411E87*/	lea ecx,dword ptr ss:[esp+0x108]
	/*00411E8E*/	lea edx,dword ptr ss:[esp+0x8]
	/*00411E92*/	push 0x2C4
	/*00411E97*/	push ecx
	/*00411E98*/	push edx
	/*00411E99*/	jmp _00411F10
_00411E9B:
	/*00411E9B*/	mov ecx,esi
	/*00411E9D*/	call sub_6835C0		/*call <cm0102.sub_6835C0>*/
	/*00411EA2*/	test eax,eax
	/*00411EA4*/	jne _00411ED6
	/*00411EA6*/	lea eax,dword ptr ss:[esp+0x108]
	/*00411EAD*/	lea ecx,dword ptr ss:[esp+0x8]
	/*00411EB1*/	push eax
	/*00411EB2*/	push ecx
	/*00411EB3*/	push edi
	/*00411EB4*/	push edi
	/*00411EB5*/	push 0x987C20		/*push cm0102.987C20*/
	/*00411EBA*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*00411EBF*/	add esp,0x14
	/*00411EC2*/	lea edx,dword ptr ss:[esp+0x108]
	/*00411EC9*/	lea eax,dword ptr ss:[esp+0x8]
	/*00411ECD*/	push 0x2CA
	/*00411ED2*/	push edx
	/*00411ED3*/	push eax
	/*00411ED4*/	jmp _00411F10
_00411ED6:
	/*00411ED6*/	push edi
	/*00411ED7*/	mov ecx,esi
	/*00411ED9*/	call sub_6827D0		/*call <cm0102.sub_6827D0>*/
	/*00411EDE*/	test eax,eax
	/*00411EE0*/	jne _00411F47
	/*00411EE2*/	lea ecx,dword ptr ss:[esp+0x108]
	/*00411EE9*/	lea edx,dword ptr ss:[esp+0x8]
	/*00411EED*/	push ecx
	/*00411EEE*/	push edx
	/*00411EEF*/	push edi
	/*00411EF0*/	push edi
	/*00411EF1*/	push 0x987C20		/*push cm0102.987C20*/
	/*00411EF6*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*00411EFB*/	add esp,0x14
	/*00411EFE*/	lea eax,dword ptr ss:[esp+0x108]
	/*00411F05*/	lea ecx,dword ptr ss:[esp+0x8]
	/*00411F09*/	push 0x2D1
	/*00411F0E*/	push eax
_00411F0F:
	/*00411F0F*/	push ecx
_00411F10:
	/*00411F10*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*00411F15*/	push eax
	/*00411F16*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00411F1B*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00411F20*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*00411F25*/	push edi
	/*00411F26*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00411F2B*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00411F30*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*00411F35*/	add esp,0x24
	/*00411F38*/	mov dword ptr ds:[0xB67A34],edi
	/*00411F3E*/	pop edi
	/*00411F3F*/	pop esi
	/*00411F40*/	add esp,0x200
	/*00411F46*/	ret
_00411F47:
	/*00411F47*/	mov edx,dword ptr ds:[esi]
	/*00411F49*/	mov ecx,esi
	/*00411F4B*/	call dword ptr ds:[edx+0x5C]
	/*00411F4E*/	mov ecx,esi
	/*00411F50*/	call sub_68AA80		/*call <cm0102.sub_68AA80>*/
	/*00411F55*/	mov eax,dword ptr ds:[esi+0x4]
	/*00411F58*/	mov ecx,dword ptr ds:[0xB74340]
	/*00411F5E*/	push eax
	/*00411F5F*/	call sub_79CEE0		/*call <cm0102.sub_79CEE0>*/
	/*00411F64*/	pop edi
	/*00411F65*/	pop esi
	/*00411F66*/	add esp,0x200
	/*00411F6C*/	ret
	}
}

void __declspec(naked) sub_4110E0()
{
	__asm
	{
	/*004110E0*/	push 0xFFFFFFFF
	/*004110E2*/	push 0x9539F8		/*push <cm0102.sub_9539F8>*/
	/*004110E7*/	mov eax,dword ptr fs:[0x0]
	/*004110ED*/	push eax
	/*004110EE*/	mov dword ptr fs:[0x0],esp
	/*004110F5*/	push ecx
	/*004110F6*/	push esi
	/*004110F7*/	mov esi,ecx
	/*004110F9*/	push edi
	/*004110FA*/	mov dword ptr ss:[esp+0x8],esi
	/*004110FE*/	mov dword ptr ds:[esi],0x967768		/*mov dword ptr ds:[esi],cm0102.967768*/
	/*00411104*/	push 0x0
	/*00411106*/	mov dword ptr ss:[esp+0x18],0x0
	/*0041110E*/	call sub_687970		/*call <cm0102.sub_687970>*/
	/*00411113*/	mov eax,dword ptr ds:[esi+0xBA]
	/*00411119*/	test eax,eax
	/*0041111B*/	je _00411130
	/*0041111D*/	push eax
	/*0041111E*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*00411123*/	add esp,0x4
	/*00411126*/	mov dword ptr ds:[esi+0xBA],0x0
_00411130:
	/*00411130*/	mov eax,dword ptr ds:[esi+0x30]
	/*00411133*/	xor edi,edi
	/*00411135*/	test eax,eax
	/*00411137*/	jl _00411151
_00411139:
	/*00411139*/	mov eax,dword ptr ds:[esi+0xC]
	/*0041113C*/	mov ecx,dword ptr ds:[eax+edi*0x4]
	/*0041113F*/	test ecx,ecx
	/*00411141*/	je _00411149
	/*00411143*/	mov edx,dword ptr ds:[ecx]
	/*00411145*/	push 0x1
	/*00411147*/	call dword ptr ds:[edx]
_00411149:
	/*00411149*/	mov eax,dword ptr ds:[esi+0x30]
	/*0041114C*/	inc edi
	/*0041114D*/	cmp edi,eax
	/*0041114F*/	jle _00411139
_00411151:
	/*00411151*/	mov eax,dword ptr ds:[esi+0xC]
	/*00411154*/	test eax,eax
	/*00411156*/	je _00411168
	/*00411158*/	push eax
	/*00411159*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*0041115E*/	add esp,0x4
	/*00411161*/	mov dword ptr ds:[esi+0xC],0x0
_00411168:
	/*00411168*/	mov edi,dword ptr ds:[esi+0x8]
	/*0041116B*/	test edi,edi
	/*0041116D*/	je _0041117F
	/*0041116F*/	mov ecx,edi
	/*00411171*/	call sub_49F450		/*call <cm0102.sub_49F450>*/
	/*00411176*/	push edi
	/*00411177*/	call sub_944C94		/*call <cm0102.sub_944C94>*/
	/*0041117C*/	add esp,0x4
_0041117F:
	/*0041117F*/	mov ecx,esi
	/*00411181*/	mov dword ptr ss:[esp+0x14],0xFFFFFFFF
	/*00411189*/	call sub_682300		/*call <cm0102.sub_682300>*/
	/*0041118E*/	mov ecx,dword ptr ss:[esp+0xC]
	/*00411192*/	pop edi
	/*00411193*/	pop esi
	/*00411194*/	mov dword ptr fs:[0x0],ecx
	/*0041119B*/	add esp,0x10
	/*0041119E*/	ret
	}
}

void __declspec(naked) sub_4110C0()
{
	__asm
	{
		/*004110C0*/	push esi
		/*004110C1*/	mov esi, ecx
		/*004110C3*/	call sub_4110E0		/*call <cm0102.sub_4110E0>*/
		/*004110C8*/	test byte ptr ss : [esp + 0x8] , 0x1
		/*004110CD*/	je _004110D8
		/*004110CF*/	push esi
		/*004110D0*/	call sub_944C94		/*call <cm0102.sub_944C94>*/
		/*004110D5*/	add esp, 0x4
		_004110D8 :
		/*004110D8*/	mov eax, esi
		/*004110DA*/	pop esi
		/*004110DB*/	ret 0x4
	}
}

void __declspec(naked) sub_4110B0()
{
	__asm
	{
	/*004110B0*/	mov al,0x3
	/*004110B2*/	ret
	}
}

void __declspec(naked) sub_4124E0()
{
	__asm
	{
	/*004124E0*/	mov edx,dword ptr ss:[esp+0x4]
	/*004124E4*/	push esi
	/*004124E5*/	mov esi,ecx
	/*004124E7*/	cmp byte ptr ds:[edx+0x42],0xFF
	/*004124EB*/	jle _00412500
	/*004124ED*/	mov ax,word ptr ds:[edx+0x4D]
	/*004124F1*/	pop esi
	/*004124F2*/	and eax,0xFF35
	/*004124F7*/	or al,0x35
	/*004124F9*/	mov word ptr ds:[edx+0x4D],ax
	/*004124FD*/	ret 0x4
_00412500:
	/*00412500*/	mov cl,byte ptr ds:[esi+0x49]
	/*00412503*/	and cl,0xF
	/*00412506*/	movsx ax,cl
	/*0041250A*/	mov cx,word ptr ds:[edx+0x4D]
	/*0041250E*/	and ecx,0xFFF0
	/*00412514*/	or eax,ecx
	/*00412516*/	mov word ptr ds:[edx+0x4D],ax
	/*0041251A*/	mov cl,byte ptr ds:[esi+0x4A]
	/*0041251D*/	and cl,0xF
	/*00412520*/	and eax,0xFF0F
	/*00412525*/	movsx cx,cl
	/*00412529*/	shl ecx,0x4
	/*0041252C*/	or ecx,eax
	/*0041252E*/	pop esi
	/*0041252F*/	mov word ptr ds:[edx+0x4D],cx
	/*00412533*/	ret 0x4
	}
}

void patch_aus_nsl()
{
	vtable::PrintVTable(0x967768, "Aus NSL");

	PatchFunction(0x832380, (DWORD)&sub_832380_setup_aus_c);
	PatchFunction(0x412C20, (DWORD)&sub_412C20_australia_rules);
	PatchFunction(0x412540, (DWORD)&sub_412540_australia_awards);
	PatchFunction(0x412AC0, (DWORD)&sub_412AC0_fixtures);
	PatchFunction(0x411CE0, (DWORD)&sub_411CE0_subs);
}

/*
C0 2A 41

00967768  C0 10 41 00 30 5D 68 00 E0 1D 41 00 10 CE 48 00  À.A.0]h.à.A..ÎH.		00
00967778  D0 9A 68 00 C0 47 68 00 10 7B 68 00 C0 91 68 00  Ð.h.ÀGh..{h.À.h.		10
00967788  B0 CE 48 00 A0 CE 48 00 70 1F 41 00 70 CE 48 00  °ÎH.ÎH.p.A.pÎH.		20
00967798  90 1D 41 00 70 34 58 00 B0 CA 48 00 A0 11 41 00  ..A.p4X.°ÊH..A.		30
009677A8  70 66 68 00 80 19 41 00 30 1A 41 00 A0 DF 48 00  pfh...A.0.A.ßH.		40
009677B8  B0 10 41 00 E0 A3 68 00 C0 E1 48 00 50 A8 68 00  °.A.à£h.ÀáH.P¨h.		50
009677C8  60 E3 48 00 50 B5 5B 00 80 23 41 00 70 34 58 00  `ãH.Pµ[..#A.p4X.		60
009677D8  C0 11 40 00 D0 11 40 00 00 CE 5D 00 E0 24 41 00  À.@.Ð.@..Î].à$A.		70
009677E8  D0 AB 68 00 40 AC 68 00 00 CE 5D 00 E0 1C 41 00  Ð«h.@¬h..Î].à.A.		80
009677F8  D0 AA 68 00 D0 4C 68 00 90 47 68 00 B0 47 68 00  Ðªh.ÐLh..Gh.°Gh.		90
00967808  20 7A 68 00 30 AA 68 00 E0 11 40 00 F0 11 40 00   zh.0ªh.à.@.ð.@.		A0
00967818  20 9C 68 00 80 26 41 00 C0 2A 41 00 B0 96 5A 00.h.. & A.À * A.°.Z.	B0
00967828  20 2C 41 00 60 F0 90 00 70 34 58 00 70 34 58 00, A.`ð..p4X.p4X.		C0
00967838  70 34 58 00 00 88 8E 00 60 85 8E 00 F0 A5 40 00  p4X.....`...ð¥@.		D0
00967848  70 E7 66 00 B0 2D 41 00 D0 2D 41 00 10 A6 40 00  pçf.° - A.Ð - A..¦@. E0
00967858  A0 F1 90 00 80 90 8E 00 B0 91 8E 00 D0 2E 41 00   ñ......°...Ð.A.		F0
00967868  70 34 58 00 C0 53 5A 00 C0 2E 41 00 00 00 00 00  p4X.ÀSZ.À.A.....		100
*/