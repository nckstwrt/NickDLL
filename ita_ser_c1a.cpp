#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "generic_functions.h"
#include "CMHeader.h"
#include "Helper.h"
#include "vtable.h"
#include "Date.h"

static int(*sub_49EE70)() = (int(*)())(0x49EE70);
static int(*sub_49F450)() = (int(*)())(0x49F450);
static int(*sub_4A1C50)() = (int(*)())(0x4A1C50);
static int(*sub_4A4850)() = (int(*)())(0x4A4850);

static int(*sub_51C800)() = (int(*)())(0x51C800);
static int(*sub_521E60)() = (int(*)())(0x521E60);
static int(*sub_521EB0)() = (int(*)())(0x521EB0);
static int(*sub_522E00)() = (int(*)())(0x522E00);

static int(*sub_5E8290)() = (int(*)())(0x5E8290);

static int(*sub_682200)() = (int(*)())(0x682200);
static int(*sub_682300)() = (int(*)())(0x682300);
static int(*sub_6827D0)() = (int(*)())(0x6827D0);
static int(*sub_6835C0)() = (int(*)())(0x6835C0);

static int(*sub_687430)() = (int(*)())(0x687430);
static int(*sub_687970)() = (int(*)())(0x687970);
static int(*sub_687B10)() = (int(*)())(0x687B10);

static int(*sub_68A160)() = (int(*)())(0x68A160);
static int(*sub_68A1C0)() = (int(*)())(0x68A1C0);
static int(*sub_68A850)() = (int(*)())(0x68A850);
static int(*sub_68AA80)() = (int(*)())(0x68AA80);
static int(*sub_68AFF0)() = (int(*)())(0x68AFF0);

static int(*sub_79CEE0)() = (int(*)())(0x79CEE0);
static int(*sub_90D130)() = (int(*)())(0x90D130);

static int(*sub_9452CA)() = (int(*)())(0x9452CA);
static int(*sub_9462BB)() = (int(*)())(0x9462BB);
static int(*sub_9463AF)() = (int(*)())(0x9463AF);

/*
* ita_ser_b vtable
VTable at 0096C480:
0. 00 = 00645A40
1. 08 = 00646960
2. 30 = 00684640
3. 3C = 00645AF0
4. 50 = 0048E180
5. 68 = 0048E380
6. 7C = 0048F2D0
7. 8C = 006468A0
8. B4 = 0064ACA0
 
ita_ser_c1a VTable at 0096C534:
0. 00 = 0064ACA0
1. 08 = 0064B820
2. 28 = 0064B9E0
3. 30 = 00684640
4. 3C = 0064AD80
5. 44 = 00654180
6. 48 = 00654390
7. 50 = 0048E180
8. 68 = 0064BD80
9. 7C = 0048F2D0
10. 8C = 0064B770
11. B4 = 0064EE50
12. B8 = 00685D30

0096C534 00   A0 AC 64 00 30 5D 68 00 20 B8 64 00 10 CE 48 00   ¬d.0]h.¸d..ÎH.
0096C544 10   D0 9A 68 00 C0 47 68 00 10 7B 68 00 C0 91 68 00  Ð.h.ÀGh..{h.À.h.
0096C554 20   B0 CE 48 00 A0 CE 48 00 E0 B9 64 00 70 CE 48 00  °ÎH.ÎH.à¹d.pÎH.
0096C564 30   40 46 68 00 70 34 58 00 B0 CA 48 00 80 AD 64 00  @Fh.p4X.°ÊH...d.
0096C574 40   70 66 68 00 80 41 65 00 90 43 65 00 A0 DF 48 00  pfh..Ae..Ce.ßH.
0096C584 50   80 E1 48 00 E0 A3 68 00 C0 E1 48 00 50 A8 68 00.áH.à£h.ÀáH.P¨h.
0096C594 60   60 E3 48 00 50 B5 5B 00 80 BD 64 00 70 34 58 00  `ãH.Pµ[..½d.p4X.
0096C5A4 70   C0 11 40 00 D0 11 40 00 00 CE 5D 00 D0 F2 48 00  À.@.Ð.@..Î].ÐòH.
0096C5B4 80   D0 AB 68 00 40 AC 68 00 00 CE 5D 00 70 B7 64 00  Ð«h.@¬h..Î].p·d.
0096C5C4 90   D0 AA 68 00 D0 4C 68 00 90 47 68 00 B0 47 68 00  Ðªh.ÐLh..Gh.°Gh.
0096C5D4 A0   20 7A 68 00 50 00 65 00 E0 11 40 00 F0 11 40 00   zh.P.e.à.@.ð.@.
0096C5E4 B0   20 9C 68 00 50 EE 64 00
*/
// sub_64BD80  <--- has jmp table

void sub_64B770();
void sub_64B670_add_teams();		// Add Teams
void sub_64ACC0();
void sub_64BA70();
void sub_64BE90_big_fixtures();
void sub_64ACA0();
void sub_64B820();
void sub_64AD80_fixtures();
void sub_64BD80();
void sub_64B9E0();

int AddTeams(BYTE* _this);
void fixture_caller();

vtable vtable_ita_ser_c1a((DWORD)&sub_64ACA0, (DWORD)&sub_64B820, (DWORD)&sub_64B9E0, 0x684640, (DWORD)&fixture_caller/*sub_64AD80_fixtures*/, 0x654180, 0x654390, 0x48E180, (DWORD)&sub_64BD80, 0x48F2D0, (DWORD)&sub_64B770, 0x64EE50, 0x685D30);

void __declspec(naked) sub_64AA70()
{
	__asm
	{
	/*0064AA70*/	push 0xFFFFFFFF
	/*0064AA72*/	push 0x95BA99		/*push cm0102.95BA99*/
	/*0064AA77*/	mov eax,dword ptr fs:[0x0]
	/*0064AA7D*/	push eax
	/*0064AA7E*/	mov dword ptr fs:[0x0],esp
	/*0064AA85*/	sub esp,0x208
	/*0064AA8B*/	push ebx
	/*0064AA8C*/	push esi
	/*0064AA8D*/	mov esi,ecx
	/*0064AA8F*/	mov dword ptr ss:[esp+0xC],esi
	/*0064AA93*/	call sub_682200		/*call <cm0102.sub_682200>*/
	/*0064AA98*/	mov ecx,dword ptr ss:[esp+0x224]
	/*0064AA9F*/	mov ax,word ptr ss:[esp+0x220]
	/*0064AAA7*/	xor ebx,ebx
	/*0064AAA9*/	mov dword ptr ds:[esi+0x4],ecx
	/*0064AAAC*/	push 0x1
	/*0064AAAE*/	mov ecx,esi
	/*0064AAB0*/	mov dword ptr ss:[esp+0x21C],ebx
	/*0064AAB7*/	mov dword ptr ds:[esi],0x96C534		/*mov dword ptr ds:[esi],cm0102.96C534*/
					
					push eax
					mov eax, dword ptr [vtable_ita_ser_c1a.vtable_ptr]
					mov dword ptr ds:[esi], eax
					pop eax
					
	/*0064AABD*/	mov word ptr ds:[esi+0x40],ax
	/*0064AAC1*/	mov byte ptr ds:[esi+0x50],0x11
	/*0064AAC5*/	call sub_687B10		/*call <cm0102.sub_687B10>*/
	/*0064AACA*/	test eax,eax
	/*0064AACC*/	jne _0064AC78
	/*0064AAD2*/	or eax,0xFFFFFFFF
	/*0064AAD5*/	push 0x8
	/*0064AAD7*/	mov byte ptr ds:[esi+0x44],al
	/*0064AADA*/	mov dword ptr ds:[esi+0x30],eax
	/*0064AADD*/	mov dword ptr ds:[esi+0x2C],0x0			// <--- How many different schedule sections? (2 for ser c1/a)
	/*0064AAE4*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*0064AAE9*/	add esp,0x4
	/*0064AAEC*/	mov ecx,esi
	/*0064AAEE*/	mov dword ptr ds:[esi+0xC],eax
	/*0064AAF1*/	call sub_64B770		/*call <cm0102.sub_64B770>*/
	/*0064AAF6*/	test eax,eax
	/*0064AAF8*/	jne _0064AB2A
	/*0064AAFA*/	lea edx,dword ptr ss:[esp+0x10]
	/*0064AAFE*/	lea eax,dword ptr ss:[esp+0x110]
	/*0064AB05*/	push edx
	/*0064AB06*/	push eax
	/*0064AB07*/	push ebx
	/*0064AB08*/	push ebx
	/*0064AB09*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064AB0E*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064AB13*/	add esp,0x14
	/*0064AB16*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0064AB1A*/	lea edx,dword ptr ss:[esp+0x110]
	/*0064AB21*/	push 0x49
	/*0064AB23*/	push ecx
	/*0064AB24*/	push edx
	/*0064AB25*/	jmp _0064AC41
_0064AB2A:
	/*0064AB2A*/	mov ecx,esi
	// /*0064AB2C*/	call sub_64B670_add_teams		/*call <cm0102.sub_64B670_add_teams>*/

					push ecx
					call AddTeams
					add esp,0x4

	/*0064AB31*/	test eax,eax
	/*0064AB33*/	jne _0064AB64
	/*0064AB35*/	lea eax,dword ptr ss:[esp+0x110]
	/*0064AB3C*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0064AB40*/	push eax
	/*0064AB41*/	push ecx
	/*0064AB42*/	push ebx
	/*0064AB43*/	push ebx
	/*0064AB44*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064AB49*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064AB4E*/	add esp,0x14
	/*0064AB51*/	lea edx,dword ptr ss:[esp+0x110]
	/*0064AB58*/	lea eax,dword ptr ss:[esp+0x10]
	/*0064AB5C*/	push 0x50
	/*0064AB5E*/	push edx
	/*0064AB5F*/	jmp _0064AC40
_0064AB64:
	/*0064AB64*/	//mov ecx,esi
	/*0064AB66*/	//call sub_64BE90_big_fixtures		/*call <cm0102.sub_64BE90_big_fixtures>*/
	/*0064AB6B*/	mov ecx,esi
	/*0064AB6D*/	call sub_6835C0		/*call <cm0102.sub_6835C0>*/
	/*0064AB72*/	test eax,eax
	/*0064AB74*/	jne _0064ABA6
	/*0064AB76*/	lea ecx,dword ptr ss:[esp+0x110]
	/*0064AB7D*/	lea edx,dword ptr ss:[esp+0x10]
	/*0064AB81*/	push ecx
	/*0064AB82*/	push edx
	/*0064AB83*/	push ebx
	/*0064AB84*/	push ebx
	/*0064AB85*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064AB8A*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064AB8F*/	add esp,0x14
	/*0064AB92*/	lea eax,dword ptr ss:[esp+0x110]
	/*0064AB99*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0064AB9D*/	push 0x5A
	/*0064AB9F*/	push eax
	/*0064ABA0*/	push ecx
	/*0064ABA1*/	jmp _0064AC41
_0064ABA6:
	/*0064ABA6*/	push ebx
	/*0064ABA7*/	mov ecx,esi
	/*0064ABA9*/	call sub_6827D0		/*call <cm0102.sub_6827D0>*/
	/*0064ABAE*/	test eax,eax
	/*0064ABB0*/	jne _0064ABDF
	/*0064ABB2*/	lea edx,dword ptr ss:[esp+0x110]
	/*0064ABB9*/	lea eax,dword ptr ss:[esp+0x10]
	/*0064ABBD*/	push edx
	/*0064ABBE*/	push eax
	/*0064ABBF*/	push ebx
	/*0064ABC0*/	push ebx
	/*0064ABC1*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064ABC6*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064ABCB*/	add esp,0x14
	/*0064ABCE*/	lea ecx,dword ptr ss:[esp+0x110]
	/*0064ABD5*/	lea edx,dword ptr ss:[esp+0x10]
	/*0064ABD9*/	push 0x63
	/*0064ABDB*/	push ecx
	/*0064ABDC*/	push edx
	/*0064ABDD*/	jmp _0064AC41
_0064ABDF:
	/*0064ABDF*/	push 0x5CE
	/*0064ABE4*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*0064ABE9*/	add esp,0x4
	/*0064ABEC*/	mov dword ptr ss:[esp+0x8],eax
	/*0064ABF0*/	cmp eax,ebx
	/*0064ABF2*/	mov byte ptr ss:[esp+0x218],0x1
	/*0064ABFA*/	je _0064AC06
	/*0064ABFC*/	push esi
	/*0064ABFD*/	mov ecx,eax
	/*0064ABFF*/	call sub_49EE70		/*call <cm0102.sub_49EE70>*/
	/*0064AC04*/	jmp _0064AC08
_0064AC06:
	/*0064AC06*/	xor eax,eax
_0064AC08:
	/*0064AC08*/	cmp eax,ebx
	/*0064AC0A*/	mov byte ptr ss:[esp+0x218],bl
	/*0064AC11*/	mov dword ptr ds:[esi+0x8],eax
	/*0064AC14*/	jne _0064AC71
	/*0064AC16*/	lea eax,dword ptr ss:[esp+0x110]
	/*0064AC1D*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0064AC21*/	push eax
	/*0064AC22*/	push ecx
	/*0064AC23*/	push ebx
	/*0064AC24*/	push ebx
	/*0064AC25*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064AC2A*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064AC2F*/	add esp,0x14
	/*0064AC32*/	lea edx,dword ptr ss:[esp+0x110]
	/*0064AC39*/	lea eax,dword ptr ss:[esp+0x10]
	/*0064AC3D*/	push 0x6A
	/*0064AC3F*/	push edx
_0064AC40:
	/*0064AC40*/	push eax
_0064AC41:
	/*0064AC41*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0064AC46*/	push eax
	/*0064AC47*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0064AC4C*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064AC51*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0064AC56*/	push ebx
	/*0064AC57*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064AC5C*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0064AC61*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0064AC66*/	add esp,0x24
	/*0064AC69*/	mov dword ptr ds:[0xB67A34],ebx
	/*0064AC6F*/	jmp _0064AC78
_0064AC71:
	/*0064AC71*/	mov ecx,esi
	/*0064AC73*/	call sub_68A850		/*call <cm0102.sub_68A850>*/
_0064AC78:
	/*0064AC78*/	mov ecx,dword ptr ss:[esp+0x210]
	/*0064AC7F*/	mov eax,esi
	/*0064AC81*/	pop esi
	/*0064AC82*/	pop ebx
	/*0064AC83*/	mov dword ptr fs:[0x0],ecx
	/*0064AC8A*/	add esp,0x214
	/*0064AC90*/	ret 0x8
	}
}

void __declspec(naked) sub_64ACA0()
{
	__asm
	{
	/*0064ACA0*/	push esi
	/*0064ACA1*/	mov esi,ecx
	/*0064ACA3*/	call sub_64ACC0		/*call <cm0102.sub_64ACC0>*/
	/*0064ACA8*/	test byte ptr ss:[esp+0x8],0x1
	/*0064ACAD*/	je _0064ACB8
	/*0064ACAF*/	push esi
	/*0064ACB0*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc_malloc>*/
	/*0064ACB5*/	add esp,0x4
_0064ACB8:
	/*0064ACB8*/	mov eax,esi
	/*0064ACBA*/	pop esi
	/*0064ACBB*/	ret 0x4
	}
}

void __declspec(naked) sub_64ACC0()
{
	__asm
	{
	/*0064ACC0*/	push 0xFFFFFFFF
	/*0064ACC2*/	push 0x95BAB8		/*push <cm0102.sub_95BAB8>*/
	/*0064ACC7*/	mov eax,dword ptr fs:[0x0]
	/*0064ACCD*/	push eax
	/*0064ACCE*/	mov dword ptr fs:[0x0],esp
	/*0064ACD5*/	push ecx
	/*0064ACD6*/	push esi
	/*0064ACD7*/	mov esi,ecx
	/*0064ACD9*/	push edi
	/*0064ACDA*/	mov dword ptr ss:[esp+0x8],esi
	/*0064ACDE*/	//mov dword ptr ds:[esi],0x96C534		/*mov dword ptr ds:[esi],cm0102.96C534*/
					push eax
					mov eax, dword ptr[vtable_ita_ser_c1a.vtable_ptr]
					mov dword ptr ds:[esi], eax
					pop eax

	/*0064ACE4*/	push 0x0
	/*0064ACE6*/	mov dword ptr ss:[esp+0x18],0x0
	/*0064ACEE*/	call sub_687970		/*call <cm0102.sub_687970>*/
	/*0064ACF3*/	mov eax,dword ptr ds:[esi+0xBA]
	/*0064ACF9*/	test eax,eax
	/*0064ACFB*/	je _0064AD10
	/*0064ACFD*/	push eax
	/*0064ACFE*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*0064AD03*/	add esp,0x4
	/*0064AD06*/	mov dword ptr ds:[esi+0xBA],0x0
_0064AD10:
	/*0064AD10*/	mov eax,dword ptr ds:[esi+0x30]
	/*0064AD13*/	xor edi,edi
	/*0064AD15*/	test eax,eax
	/*0064AD17*/	jl _0064AD31
_0064AD19:
	/*0064AD19*/	mov eax,dword ptr ds:[esi+0xC]
	/*0064AD1C*/	mov ecx,dword ptr ds:[eax+edi*0x4]
	/*0064AD1F*/	test ecx,ecx
	/*0064AD21*/	je _0064AD29
	/*0064AD23*/	mov edx,dword ptr ds:[ecx]
	/*0064AD25*/	push 0x1
	/*0064AD27*/	call dword ptr ds:[edx]
_0064AD29:
	/*0064AD29*/	mov eax,dword ptr ds:[esi+0x30]
	/*0064AD2C*/	inc edi
	/*0064AD2D*/	cmp edi,eax
	/*0064AD2F*/	jle _0064AD19
_0064AD31:
	/*0064AD31*/	mov eax,dword ptr ds:[esi+0xC]
	/*0064AD34*/	push eax
	/*0064AD35*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*0064AD3A*/	mov edi,dword ptr ds:[esi+0x8]
	/*0064AD3D*/	add esp,0x4
	/*0064AD40*/	test edi,edi
	/*0064AD42*/	je _0064AD54
	/*0064AD44*/	mov ecx,edi
	/*0064AD46*/	call sub_49F450		/*call <cm0102.sub_49F450>*/
	/*0064AD4B*/	push edi
	/*0064AD4C*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc_malloc>*/
	/*0064AD51*/	add esp,0x4
_0064AD54:
	/*0064AD54*/	mov ecx,esi
	/*0064AD56*/	mov dword ptr ss:[esp+0x14],0xFFFFFFFF
	/*0064AD5E*/	call sub_682300		/*call <cm0102.sub_682300>*/
	/*0064AD63*/	mov ecx,dword ptr ss:[esp+0xC]
	/*0064AD67*/	pop edi
	/*0064AD68*/	pop esi
	/*0064AD69*/	mov dword ptr fs:[0x0],ecx
	/*0064AD70*/	add esp,0x10
	/*0064AD73*/	ret
	}
}

DWORD add_fixtures(BYTE* _this, BYTE a2, WORD* a3, WORD* a4, DWORD* a5)
{
	dprintf("add_fixtures called with this=%08X a2=%02X, a3=%08X, a4=%08X, a5=%08X\n", _this, a2, a3, a4, a5);

	if (a2 == 0xFF)	// -1
	{
		if (a5)
			*a5 = 1;
		*a3 = 23 * 2;		// Number of Fixtures = 0x22 (34 i.e. number of teams * 2) 18 in ser c1/a (23 in nothern prem)
		*a4 = 0;
		BYTE *pMem = (BYTE*)sub_944E46_malloc((*a3) * 65);	// Allocate memory for fixtures
		WORD year = *(WORD*)(_this+0x40);

		Date date(year, 9, 5); // Start date: 5th September

		for (int i = 0; i < (*a3); i++)
		{
			//sub_68A160_call(pMem, i, 5 /* Day */, 8 /* Month - 1 */, 0 /* add to year */, 6, 1, year, 0);
			sub_68A160_add_fixture_call(pMem, i, date.getDay(), date.getMonth() -1 /* Month - 1 */, date.getYear() - year /* add to year */, 6 /* day of week - 1 */, 1, year, 0);
			sub_68A1C0_add_fixture_call(pMem, i, 0, -1, -1, -1, 0);
			date.addDays(7); // Next fixture in 7 days	
		}
		return (DWORD)pMem;
	}
	if (((BYTE)a2) == 0) // 0
	{

	}
	return 0;
}

/*
1: [esp + 4] FFFFFFFF FFFFFFFF
2 : [esp + 8] 18C65CC9 18C65CC9
3 : [esp + C] 18C65C5A 18C65C5A 
4 : [esp + 10] 00000000 00000000
5 : [esp + 14] 18C65C20 18C65C20
*/
void __declspec(naked) fixture_caller()
{
	__asm 
	{ 
		//jmp sub_64AD80_fixtures
		mov eax, esp
		push dword ptr [eax+0x10]
		push dword ptr [eax+0xC]
		push dword ptr [eax+0x8]
		push dword ptr [eax+0x4]
		push ecx
		call add_fixtures
		add esp, 0x14
		ret 0x10
	}
}

void __declspec(naked) sub_64AD80_fixtures()
{
	__asm
	{
	/*0064AD80*/	mov al,byte ptr ss:[esp+0x4]			// a2 (BYTE)
	/*0064AD84*/	sub esp,0x200
	/*0064AD8A*/	cmp al,0xFF
	/*0064AD8C*/	push ebx
	/*0064AD8D*/	push esi
	/*0064AD8E*/	push edi
	/*0064AD8F*/	mov edi,ecx								// this
	/*0064AD91*/	jne _0064B3B4
	/*0064AD97*/	mov eax,dword ptr ss:[esp+0x21C]		// a5
	/*0064AD9E*/	xor ebx,ebx
	/*0064ADA0*/	cmp eax,ebx
	/*0064ADA2*/	je _0064ADAA
	/*0064ADA4*/	mov dword ptr ds:[eax],0x1
_0064ADAA:
	/*0064ADAA*/	mov eax,dword ptr ss:[esp+0x214]		// a3  (Number of Teams)
	/*0064ADB1*/	mov ecx,dword ptr ss:[esp+0x218]		// a4
	/*0064ADB8*/	push 0x8A2								// 2210  (0x8A2)
	/*0064ADBD*/	mov word ptr ds:[eax],0x22				// Normally there's 18 teams - 18 * 2 = 34 (0x22)	2210 / 34 = 65 * 34 = 2210
					//push 0xBAE // 23 * 2 * 65 = 2990 (0xBAE)
					//mov word ptr ds:[eax], 46			// 23 teams * 2 = 46

	/*0064ADC2*/	mov word ptr ds:[ecx],bx
	/*0064ADC5*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*0064ADCA*/	mov esi,eax
	/*0064ADCC*/	add esp,0x4
	/*0064ADCF*/	cmp esi,ebx
	/*0064ADD1*/	jne _0064AE06
	/*0064ADD3*/	lea edx,dword ptr ss:[esp+0xC]
	/*0064ADD7*/	lea eax,dword ptr ss:[esp+0x10C]
	/*0064ADDE*/	push edx
	/*0064ADDF*/	push eax
	/*0064ADE0*/	push ebx
	/*0064ADE1*/	push ebx
	/*0064ADE2*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064ADE7*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064ADEC*/	add esp,0x14
	/*0064ADEF*/	lea ecx,dword ptr ss:[esp+0xC]
	/*0064ADF3*/	lea edx,dword ptr ss:[esp+0x10C]
	/*0064ADFA*/	push 0xAB
	/*0064ADFF*/	push ecx
	/*0064AE00*/	push edx
	/*0064AE01*/	jmp _0064B5A8
_0064AE06:
	/*0064AE06*/	mov ax,word ptr ds:[edi+0x40]
	/*0064AE0A*/	push ebx
	/*0064AE0B*/	push eax
	/*0064AE0C*/	push 0x1
	/*0064AE0E*/	push 0x6
	/*0064AE10*/	push ebx
	/*0064AE11*/	push 0x8
	/*0064AE13*/	push 0x5
	/*0064AE15*/	push ebx
	/*0064AE16*/	push esi
	/*0064AE17*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AE1C*/	push ebx
	/*0064AE1D*/	push 0xFFFFFFFF
	/*0064AE1F*/	push 0xFFFFFFFF
	/*0064AE21*/	push 0xFFFFFFFF
	/*0064AE23*/	push ebx
	/*0064AE24*/	push ebx
	/*0064AE25*/	push esi
	/*0064AE26*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AE2B*/	mov cx,word ptr ds:[edi+0x40]
	/*0064AE2F*/	add esp,0x40
	/*0064AE32*/	push ebx
	/*0064AE33*/	push ecx
	/*0064AE34*/	push 0x1
	/*0064AE36*/	push 0x6
	/*0064AE38*/	push ebx
	/*0064AE39*/	push 0x8
	/*0064AE3B*/	push 0xC
	/*0064AE3D*/	push 0x1
	/*0064AE3F*/	push esi
	/*0064AE40*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AE45*/	push ebx
	/*0064AE46*/	push 0xFFFFFFFF
	/*0064AE48*/	push 0xFFFFFFFF
	/*0064AE4A*/	push 0xFFFFFFFF
	/*0064AE4C*/	push ebx
	/*0064AE4D*/	push 0x1
	/*0064AE4F*/	push esi
	/*0064AE50*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AE55*/	mov dx,word ptr ds:[edi+0x40]
	/*0064AE59*/	add esp,0x40
	/*0064AE5C*/	push ebx
	/*0064AE5D*/	push edx
	/*0064AE5E*/	push 0x1
	/*0064AE60*/	push 0x6
	/*0064AE62*/	push ebx
	/*0064AE63*/	push 0x8
	/*0064AE65*/	push 0x13
	/*0064AE67*/	push 0x2
	/*0064AE69*/	push esi
	/*0064AE6A*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AE6F*/	push ebx
	/*0064AE70*/	push 0xFFFFFFFF
	/*0064AE72*/	push 0xFFFFFFFF
	/*0064AE74*/	push 0xFFFFFFFF
	/*0064AE76*/	push ebx
	/*0064AE77*/	push 0x2
	/*0064AE79*/	push esi
	/*0064AE7A*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AE7F*/	mov ax,word ptr ds:[edi+0x40]
	/*0064AE83*/	add esp,0x40
	/*0064AE86*/	push ebx
	/*0064AE87*/	push eax
	/*0064AE88*/	push 0x1
	/*0064AE8A*/	push 0x6
	/*0064AE8C*/	push ebx
	/*0064AE8D*/	push 0x8
	/*0064AE8F*/	push 0x1A
	/*0064AE91*/	push 0x3
	/*0064AE93*/	push esi
	/*0064AE94*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AE99*/	push ebx
	/*0064AE9A*/	push 0xFFFFFFFF
	/*0064AE9C*/	push 0xFFFFFFFF
	/*0064AE9E*/	push 0xFFFFFFFF
	/*0064AEA0*/	push ebx
	/*0064AEA1*/	push 0x3
	/*0064AEA3*/	push esi
	/*0064AEA4*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AEA9*/	add esp,0x40
	/*0064AEAC*/	push ebx
	/*0064AEAD*/	mov cx,word ptr ds:[edi+0x40]
	/*0064AEB1*/	push ecx
	/*0064AEB2*/	push 0x1
	/*0064AEB4*/	push 0x6
	/*0064AEB6*/	push ebx
	/*0064AEB7*/	push 0x9
	/*0064AEB9*/	push 0x3
	/*0064AEBB*/	push 0x4
	/*0064AEBD*/	push esi
	/*0064AEBE*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AEC3*/	push ebx
	/*0064AEC4*/	push 0xFFFFFFFF
	/*0064AEC6*/	push 0xFFFFFFFF
	/*0064AEC8*/	push 0xFFFFFFFF
	/*0064AECA*/	push ebx
	/*0064AECB*/	push 0x4
	/*0064AECD*/	push esi
	/*0064AECE*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AED3*/	mov dx,word ptr ds:[edi+0x40]
	/*0064AED7*/	add esp,0x40
	/*0064AEDA*/	push ebx
	/*0064AEDB*/	push edx
	/*0064AEDC*/	push 0x1
	/*0064AEDE*/	push 0x6
	/*0064AEE0*/	push ebx
	/*0064AEE1*/	push 0x9
	/*0064AEE3*/	push 0xA
	/*0064AEE5*/	push 0x5
	/*0064AEE7*/	push esi
	/*0064AEE8*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AEED*/	push ebx
	/*0064AEEE*/	push 0xFFFFFFFF
	/*0064AEF0*/	push 0xFFFFFFFF
	/*0064AEF2*/	push 0xFFFFFFFF
	/*0064AEF4*/	push ebx
	/*0064AEF5*/	push 0x5
	/*0064AEF7*/	push esi
	/*0064AEF8*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AEFD*/	mov ax,word ptr ds:[edi+0x40]
	/*0064AF01*/	add esp,0x40
	/*0064AF04*/	push ebx
	/*0064AF05*/	push eax
	/*0064AF06*/	push 0x1
	/*0064AF08*/	push 0x6
	/*0064AF0A*/	push ebx
	/*0064AF0B*/	push 0x9
	/*0064AF0D*/	push 0x11
	/*0064AF0F*/	push 0x6
	/*0064AF11*/	push esi
	/*0064AF12*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AF17*/	push ebx
	/*0064AF18*/	push 0xFFFFFFFF
	/*0064AF1A*/	push 0xFFFFFFFF
	/*0064AF1C*/	push 0xFFFFFFFF
	/*0064AF1E*/	push ebx
	/*0064AF1F*/	push 0x6
	/*0064AF21*/	push esi
	/*0064AF22*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AF27*/	mov cx,word ptr ds:[edi+0x40]
	/*0064AF2B*/	add esp,0x40
	/*0064AF2E*/	push ebx
	/*0064AF2F*/	push ecx
	/*0064AF30*/	push 0x1
	/*0064AF32*/	push 0x6
	/*0064AF34*/	push ebx
	/*0064AF35*/	push 0x9
	/*0064AF37*/	push 0x18
	/*0064AF39*/	push 0x7
	/*0064AF3B*/	push esi
	/*0064AF3C*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AF41*/	push ebx
	/*0064AF42*/	push 0xFFFFFFFF
	/*0064AF44*/	push 0xFFFFFFFF
	/*0064AF46*/	push 0xFFFFFFFF
	/*0064AF48*/	push ebx
	/*0064AF49*/	push 0x7
	/*0064AF4B*/	push esi
	/*0064AF4C*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AF51*/	mov dx,word ptr ds:[edi+0x40]
	/*0064AF55*/	add esp,0x40
	/*0064AF58*/	push ebx
	/*0064AF59*/	push edx
	/*0064AF5A*/	push 0x1
	/*0064AF5C*/	push 0x6
	/*0064AF5E*/	push ebx
	/*0064AF5F*/	push 0x9
	/*0064AF61*/	push 0x1F
	/*0064AF63*/	push 0x8
	/*0064AF65*/	push esi
	/*0064AF66*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AF6B*/	push ebx
	/*0064AF6C*/	push 0xFFFFFFFF
	/*0064AF6E*/	push 0xFFFFFFFF
	/*0064AF70*/	push 0xFFFFFFFF
	/*0064AF72*/	push ebx
	/*0064AF73*/	push 0x8
	/*0064AF75*/	push esi
	/*0064AF76*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AF7B*/	mov ax,word ptr ds:[edi+0x40]
	/*0064AF7F*/	add esp,0x40
	/*0064AF82*/	push ebx
	/*0064AF83*/	push eax
	/*0064AF84*/	push 0x1
	/*0064AF86*/	push 0x6
	/*0064AF88*/	push ebx
	/*0064AF89*/	push 0xA
	/*0064AF8B*/	push 0x7
	/*0064AF8D*/	push 0x9
	/*0064AF8F*/	push esi
	/*0064AF90*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AF95*/	push ebx
	/*0064AF96*/	push 0xFFFFFFFF
	/*0064AF98*/	push 0xFFFFFFFF
	/*0064AF9A*/	push 0xFFFFFFFF
	/*0064AF9C*/	push ebx
	/*0064AF9D*/	push 0x9
	/*0064AF9F*/	push esi
	/*0064AFA0*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AFA5*/	mov cx,word ptr ds:[edi+0x40]
	/*0064AFA9*/	add esp,0x40
	/*0064AFAC*/	push ebx
	/*0064AFAD*/	push ecx
	/*0064AFAE*/	push 0x1
	/*0064AFB0*/	push 0x6
	/*0064AFB2*/	push ebx
	/*0064AFB3*/	push 0xA
	/*0064AFB5*/	push 0xE
	/*0064AFB7*/	push 0xA
	/*0064AFB9*/	push esi
	/*0064AFBA*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AFBF*/	push ebx
	/*0064AFC0*/	push 0xFFFFFFFF
	/*0064AFC2*/	push 0xFFFFFFFF
	/*0064AFC4*/	push 0xFFFFFFFF
	/*0064AFC6*/	push ebx
	/*0064AFC7*/	push 0xA
	/*0064AFC9*/	push esi
	/*0064AFCA*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AFCF*/	mov dx,word ptr ds:[edi+0x40]
	/*0064AFD3*/	add esp,0x40
	/*0064AFD6*/	push ebx
	/*0064AFD7*/	push edx
	/*0064AFD8*/	push 0x1
	/*0064AFDA*/	push 0x6
	/*0064AFDC*/	push ebx
	/*0064AFDD*/	push 0xA
	/*0064AFDF*/	push 0x15
	/*0064AFE1*/	push 0xB
	/*0064AFE3*/	push esi
	/*0064AFE4*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064AFE9*/	push ebx
	/*0064AFEA*/	push 0xFFFFFFFF
	/*0064AFEC*/	push 0xFFFFFFFF
	/*0064AFEE*/	push 0xFFFFFFFF
	/*0064AFF0*/	push ebx
	/*0064AFF1*/	push 0xB
	/*0064AFF3*/	push esi
	/*0064AFF4*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064AFF9*/	mov ax,word ptr ds:[edi+0x40]
	/*0064AFFD*/	add esp,0x40
	/*0064B000*/	push ebx
	/*0064B001*/	push eax
	/*0064B002*/	push 0x1
	/*0064B004*/	push 0x6
	/*0064B006*/	push ebx
	/*0064B007*/	push 0xA
	/*0064B009*/	push 0x1C
	/*0064B00B*/	push 0xC
	/*0064B00D*/	push esi
	/*0064B00E*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B013*/	push ebx
	/*0064B014*/	push 0xFFFFFFFF
	/*0064B016*/	push 0xFFFFFFFF
	/*0064B018*/	push 0xFFFFFFFF
	/*0064B01A*/	push ebx
	/*0064B01B*/	push 0xC
	/*0064B01D*/	push esi
	/*0064B01E*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B023*/	mov cx,word ptr ds:[edi+0x40]
	/*0064B027*/	add esp,0x40
	/*0064B02A*/	push ebx
	/*0064B02B*/	push ecx
	/*0064B02C*/	push 0x1
	/*0064B02E*/	push 0x6
	/*0064B030*/	push ebx
	/*0064B031*/	push 0xB
	/*0064B033*/	push 0x5
	/*0064B035*/	push 0xD
	/*0064B037*/	push esi
	/*0064B038*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B03D*/	push ebx
	/*0064B03E*/	push 0xFFFFFFFF
	/*0064B040*/	push 0xFFFFFFFF
	/*0064B042*/	push 0xFFFFFFFF
	/*0064B044*/	push ebx
	/*0064B045*/	push 0xD
	/*0064B047*/	push esi
	/*0064B048*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B04D*/	mov dx,word ptr ds:[edi+0x40]
	/*0064B051*/	add esp,0x40
	/*0064B054*/	push ebx
	/*0064B055*/	push edx
	/*0064B056*/	push 0x1
	/*0064B058*/	push 0x6
	/*0064B05A*/	push ebx
	/*0064B05B*/	push 0xB
	/*0064B05D*/	push 0xC
	/*0064B05F*/	push 0xE
	/*0064B061*/	push esi
	/*0064B062*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B067*/	push ebx
	/*0064B068*/	push 0xFFFFFFFF
	/*0064B06A*/	push 0xFFFFFFFF
	/*0064B06C*/	push 0xFFFFFFFF
	/*0064B06E*/	push ebx
	/*0064B06F*/	push 0xE
	/*0064B071*/	push esi
	/*0064B072*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B077*/	mov ax,word ptr ds:[edi+0x40]
	/*0064B07B*/	add esp,0x40
	/*0064B07E*/	push ebx
	/*0064B07F*/	push eax
	/*0064B080*/	push 0x1
	/*0064B082*/	push 0x6
	/*0064B084*/	push ebx
	/*0064B085*/	push 0xB
	/*0064B087*/	push 0x13
	/*0064B089*/	push 0xF
	/*0064B08B*/	push esi
	/*0064B08C*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B091*/	push ebx
	/*0064B092*/	push 0xFFFFFFFF
	/*0064B094*/	push 0xFFFFFFFF
	/*0064B096*/	push 0xFFFFFFFF
	/*0064B098*/	push ebx
	/*0064B099*/	push 0xF
	/*0064B09B*/	push esi
	/*0064B09C*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B0A1*/	mov cx,word ptr ds:[edi+0x40]
	/*0064B0A5*/	add esp,0x40
	/*0064B0A8*/	push ebx
	/*0064B0A9*/	push ecx
	/*0064B0AA*/	push 0x2
	/*0064B0AC*/	push 0x3
	/*0064B0AE*/	push 0x1
	/*0064B0B0*/	push ebx
	/*0064B0B1*/	push 0x6
	/*0064B0B3*/	push 0x10
	/*0064B0B5*/	push esi
	/*0064B0B6*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B0BB*/	push ebx
	/*0064B0BC*/	push 0xFFFFFFFF
	/*0064B0BE*/	push 0xFFFFFFFF
	/*0064B0C0*/	push 0xFFFFFFFF
	/*0064B0C2*/	push ebx
	/*0064B0C3*/	push 0x10
	/*0064B0C5*/	push esi
	/*0064B0C6*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B0CB*/	mov dx,word ptr ds:[edi+0x40]
	/*0064B0CF*/	add esp,0x40
	/*0064B0D2*/	push ebx
	/*0064B0D3*/	push edx
	/*0064B0D4*/	push 0x1
	/*0064B0D6*/	push 0x6
	/*0064B0D8*/	push 0x1
	/*0064B0DA*/	push ebx
	/*0064B0DB*/	push 0x10
	/*0064B0DD*/	push 0x11
	/*0064B0DF*/	push esi
	/*0064B0E0*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B0E5*/	push ebx
	/*0064B0E6*/	push 0xFFFFFFFF
	/*0064B0E8*/	push 0xFFFFFFFF
	/*0064B0EA*/	push 0xFFFFFFFF
	/*0064B0EC*/	push ebx
	/*0064B0ED*/	push 0x11
	/*0064B0EF*/	push esi
	/*0064B0F0*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B0F5*/	mov ax,word ptr ds:[edi+0x40]
	/*0064B0F9*/	add esp,0x40
	/*0064B0FC*/	push ebx
	/*0064B0FD*/	push eax
	/*0064B0FE*/	push 0x1
	/*0064B100*/	push 0x6
	/*0064B102*/	push 0x1
	/*0064B104*/	push ebx
	/*0064B105*/	push 0x17
	/*0064B107*/	push 0x12
	/*0064B109*/	push esi
	/*0064B10A*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B10F*/	push ebx
	/*0064B110*/	push 0xFFFFFFFF
	/*0064B112*/	push 0xFFFFFFFF
	/*0064B114*/	push 0xFFFFFFFF
	/*0064B116*/	push ebx
	/*0064B117*/	push 0x12
	/*0064B119*/	push esi
	/*0064B11A*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B11F*/	mov cx,word ptr ds:[edi+0x40]
	/*0064B123*/	add esp,0x40
	/*0064B126*/	push ebx
	/*0064B127*/	push ecx
	/*0064B128*/	push 0x1
	/*0064B12A*/	push 0x6
	/*0064B12C*/	push 0x1
	/*0064B12E*/	push ebx
	/*0064B12F*/	push 0x1E
	/*0064B131*/	push 0x13
	/*0064B133*/	push esi
	/*0064B134*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B139*/	push ebx
	/*0064B13A*/	push 0xFFFFFFFF
	/*0064B13C*/	push 0xFFFFFFFF
	/*0064B13E*/	push 0xFFFFFFFF
	/*0064B140*/	push ebx
	/*0064B141*/	push 0x13
	/*0064B143*/	push esi
	/*0064B144*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B149*/	mov dx,word ptr ds:[edi+0x40]
	/*0064B14D*/	add esp,0x40
	/*0064B150*/	push ebx
	/*0064B151*/	push edx
	/*0064B152*/	push 0x1
	/*0064B154*/	push 0x6
	/*0064B156*/	push 0x1
	/*0064B158*/	push 0x1
	/*0064B15A*/	push 0xD
	/*0064B15C*/	push 0x14
	/*0064B15E*/	push esi
	/*0064B15F*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B164*/	push ebx
	/*0064B165*/	push 0xFFFFFFFF
	/*0064B167*/	push 0xFFFFFFFF
	/*0064B169*/	push 0xFFFFFFFF
	/*0064B16B*/	push ebx
	/*0064B16C*/	push 0x14
	/*0064B16E*/	push esi
	/*0064B16F*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B174*/	mov ax,word ptr ds:[edi+0x40]
	/*0064B178*/	add esp,0x40
	/*0064B17B*/	push ebx
	/*0064B17C*/	push eax
	/*0064B17D*/	push 0x1
	/*0064B17F*/	push 0x6
	/*0064B181*/	push 0x1
	/*0064B183*/	push 0x1
	/*0064B185*/	push 0x14
	/*0064B187*/	push 0x15
	/*0064B189*/	push esi
	/*0064B18A*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B18F*/	push ebx
	/*0064B190*/	push 0xFFFFFFFF
	/*0064B192*/	push 0xFFFFFFFF
	/*0064B194*/	push 0xFFFFFFFF
	/*0064B196*/	push ebx
	/*0064B197*/	push 0x15
	/*0064B199*/	push esi
	/*0064B19A*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B19F*/	mov cx,word ptr ds:[edi+0x40]
	/*0064B1A3*/	add esp,0x40
	/*0064B1A6*/	push ebx
	/*0064B1A7*/	push ecx
	/*0064B1A8*/	push 0x1
	/*0064B1AA*/	push 0x6
	/*0064B1AC*/	push 0x1
	/*0064B1AE*/	push 0x1
	/*0064B1B0*/	push 0x1B
	/*0064B1B2*/	push 0x16
	/*0064B1B4*/	push esi
	/*0064B1B5*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B1BA*/	push ebx
	/*0064B1BB*/	push 0xFFFFFFFF
	/*0064B1BD*/	push 0xFFFFFFFF
	/*0064B1BF*/	push 0xFFFFFFFF
	/*0064B1C1*/	push ebx
	/*0064B1C2*/	push 0x16
	/*0064B1C4*/	push esi
	/*0064B1C5*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B1CA*/	mov dx,word ptr ds:[edi+0x40]
	/*0064B1CE*/	add esp,0x40
	/*0064B1D1*/	push ebx
	/*0064B1D2*/	push edx
	/*0064B1D3*/	push 0x1
	/*0064B1D5*/	push 0x6
	/*0064B1D7*/	push 0x1
	/*0064B1D9*/	push 0x2
	/*0064B1DB*/	push 0x5
	/*0064B1DD*/	push 0x17
	/*0064B1DF*/	push esi
	/*0064B1E0*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B1E5*/	push ebx
	/*0064B1E6*/	push 0xFFFFFFFF
	/*0064B1E8*/	push 0xFFFFFFFF
	/*0064B1EA*/	push 0xFFFFFFFF
	/*0064B1EC*/	push ebx
	/*0064B1ED*/	push 0x17
	/*0064B1EF*/	push esi
	/*0064B1F0*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B1F5*/	mov ax,word ptr ds:[edi+0x40]
	/*0064B1F9*/	add esp,0x40
	/*0064B1FC*/	push ebx
	/*0064B1FD*/	push eax
	/*0064B1FE*/	push 0x1
	/*0064B200*/	push 0x6
	/*0064B202*/	push 0x1
	/*0064B204*/	push 0x2
	/*0064B206*/	push 0xC
	/*0064B208*/	push 0x18
	/*0064B20A*/	push esi
	/*0064B20B*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B210*/	push ebx
	/*0064B211*/	push 0xFFFFFFFF
	/*0064B213*/	push 0xFFFFFFFF
	/*0064B215*/	push 0xFFFFFFFF
	/*0064B217*/	push ebx
	/*0064B218*/	push 0x18
	/*0064B21A*/	push esi
	/*0064B21B*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B220*/	mov cx,word ptr ds:[edi+0x40]
	/*0064B224*/	add esp,0x40
	/*0064B227*/	push ebx
	/*0064B228*/	push ecx
	/*0064B229*/	push 0x1
	/*0064B22B*/	push 0x6
	/*0064B22D*/	push 0x1
	/*0064B22F*/	push 0x2
	/*0064B231*/	push 0x13
	/*0064B233*/	push 0x19
	/*0064B235*/	push esi
	/*0064B236*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B23B*/	push ebx
	/*0064B23C*/	push 0xFFFFFFFF
	/*0064B23E*/	push 0xFFFFFFFF
	/*0064B240*/	push 0xFFFFFFFF
	/*0064B242*/	push ebx
	/*0064B243*/	push 0x19
	/*0064B245*/	push esi
	/*0064B246*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B24B*/	mov dx,word ptr ds:[edi+0x40]
	/*0064B24F*/	add esp,0x40
	/*0064B252*/	push ebx
	/*0064B253*/	push edx
	/*0064B254*/	push 0x1
	/*0064B256*/	push 0x6
	/*0064B258*/	push 0x1
	/*0064B25A*/	push 0x2
	/*0064B25C*/	push 0x1A
	/*0064B25E*/	push 0x1A
	/*0064B260*/	push esi
	/*0064B261*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B266*/	push ebx
	/*0064B267*/	push 0xFFFFFFFF
	/*0064B269*/	push 0xFFFFFFFF
	/*0064B26B*/	push 0xFFFFFFFF
	/*0064B26D*/	push ebx
	/*0064B26E*/	push 0x1A
	/*0064B270*/	push esi
	/*0064B271*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B276*/	mov ax,word ptr ds:[edi+0x40]
	/*0064B27A*/	add esp,0x40
	/*0064B27D*/	push ebx
	/*0064B27E*/	push eax
	/*0064B27F*/	push 0x1
	/*0064B281*/	push 0x6
	/*0064B283*/	push 0x1
	/*0064B285*/	push 0x3
	/*0064B287*/	push 0x2
	/*0064B289*/	push 0x1B
	/*0064B28B*/	push esi
	/*0064B28C*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B291*/	push ebx
	/*0064B292*/	push 0xFFFFFFFF
	/*0064B294*/	push 0xFFFFFFFF
	/*0064B296*/	push 0xFFFFFFFF
	/*0064B298*/	push ebx
	/*0064B299*/	push 0x1B
	/*0064B29B*/	push esi
	/*0064B29C*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B2A1*/	mov cx,word ptr ds:[edi+0x40]
	/*0064B2A5*/	add esp,0x40
	/*0064B2A8*/	push ebx
	/*0064B2A9*/	push ecx
	/*0064B2AA*/	push 0x2
	/*0064B2AC*/	push 0x2
	/*0064B2AE*/	push 0x1
	/*0064B2B0*/	push 0x3
	/*0064B2B2*/	push 0x5
	/*0064B2B4*/	push 0x1C
	/*0064B2B6*/	push esi
	/*0064B2B7*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B2BC*/	push ebx
	/*0064B2BD*/	push 0xFFFFFFFF
	/*0064B2BF*/	push 0xFFFFFFFF
	/*0064B2C1*/	push 0xFFFFFFFF
	/*0064B2C3*/	push ebx
	/*0064B2C4*/	push 0x1C
	/*0064B2C6*/	push esi
	/*0064B2C7*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B2CC*/	mov dx,word ptr ds:[edi+0x40]
	/*0064B2D0*/	add esp,0x40
	/*0064B2D3*/	push ebx
	/*0064B2D4*/	push edx
	/*0064B2D5*/	push 0x1
	/*0064B2D7*/	push 0x6
	/*0064B2D9*/	push 0x1
	/*0064B2DB*/	push 0x3
	/*0064B2DD*/	push 0x9
	/*0064B2DF*/	push 0x1D
	/*0064B2E1*/	push esi
	/*0064B2E2*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B2E7*/	push ebx
	/*0064B2E8*/	push 0xFFFFFFFF
	/*0064B2EA*/	push 0xFFFFFFFF
	/*0064B2EC*/	push 0xFFFFFFFF
	/*0064B2EE*/	push ebx
	/*0064B2EF*/	push 0x1D
	/*0064B2F1*/	push esi
	/*0064B2F2*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B2F7*/	mov ax,word ptr ds:[edi+0x40]
	/*0064B2FB*/	add esp,0x40
	/*0064B2FE*/	push ebx
	/*0064B2FF*/	push eax
	/*0064B300*/	push 0x1
	/*0064B302*/	push 0x6
	/*0064B304*/	push 0x1
	/*0064B306*/	push 0x3
	/*0064B308*/	push 0x10
	/*0064B30A*/	push 0x1E
	/*0064B30C*/	push esi
	/*0064B30D*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B312*/	push ebx
	/*0064B313*/	push 0xFFFFFFFF
	/*0064B315*/	push 0xFFFFFFFF
	/*0064B317*/	push 0xFFFFFFFF
	/*0064B319*/	push ebx
	/*0064B31A*/	push 0x1E
	/*0064B31C*/	push esi
	/*0064B31D*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B322*/	mov cx,word ptr ds:[edi+0x40]
	/*0064B326*/	add esp,0x40
	/*0064B329*/	push ebx
	/*0064B32A*/	push ecx
	/*0064B32B*/	push 0x1
	/*0064B32D*/	push 0x6
	/*0064B32F*/	push 0x1
	/*0064B331*/	push 0x3
	/*0064B333*/	push 0x17
	/*0064B335*/	push 0x1F
	/*0064B337*/	push esi
	/*0064B338*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B33D*/	push ebx
	/*0064B33E*/	push 0xFFFFFFFF
	/*0064B340*/	push 0xFFFFFFFF
	/*0064B342*/	push 0xFFFFFFFF
	/*0064B344*/	push ebx
	/*0064B345*/	push 0x1F
	/*0064B347*/	push esi
	/*0064B348*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B34D*/	mov dx,word ptr ds:[edi+0x40]
	/*0064B351*/	add esp,0x40
	/*0064B354*/	push ebx
	/*0064B355*/	push edx
	/*0064B356*/	push 0x1
	/*0064B358*/	push 0x6
	/*0064B35A*/	push 0x1
	/*0064B35C*/	push 0x3
	/*0064B35E*/	push 0x1E
	/*0064B360*/	push 0x20
	/*0064B362*/	push esi
	/*0064B363*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B368*/	push ebx
	/*0064B369*/	push 0xFFFFFFFF
	/*0064B36B*/	push 0xFFFFFFFF
	/*0064B36D*/	push 0xFFFFFFFF
	/*0064B36F*/	push ebx
	/*0064B370*/	push 0x20
	/*0064B372*/	push esi
	/*0064B373*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B378*/	mov ax,word ptr ds:[edi+0x40]
	/*0064B37C*/	add esp,0x40
	/*0064B37F*/	push ebx
	/*0064B380*/	push eax
	/*0064B381*/	push 0x1
	/*0064B383*/	push 0x6
	/*0064B385*/	push 0x1
	/*0064B387*/	push 0x4
	/*0064B389*/	push 0x7
	/*0064B38B*/	push 0x21
	/*0064B38D*/	push esi
	/*0064B38E*/	call sub_68A160		/*call <cm0102.sub_68A160>*/
	/*0064B393*/	push ebx
	/*0064B394*/	push 0xFFFFFFFF
	/*0064B396*/	push 0xFFFFFFFF
	/*0064B398*/	push 0xFFFFFFFF
	/*0064B39A*/	push ebx
	/*0064B39B*/	push 0x21
	/*0064B39D*/	push esi
	/*0064B39E*/	call sub_68A1C0		/*call <cm0102.sub_68A1C0>*/
	/*0064B3A3*/	add esp,0x40
	/*0064B3A6*/	mov eax,esi
	/*0064B3A8*/	pop edi
	/*0064B3A9*/	pop esi
	/*0064B3AA*/	pop ebx
	/*0064B3AB*/	add esp,0x200
	/*0064B3B1*/	ret 0x10
_0064B3B4:
	/*0064B3B4*/	xor ebx,ebx
	/*0064B3B6*/	cmp al,bl
	/*0064B3B8*/	jne _0064B53F
	/*0064B3BE*/	mov eax,dword ptr ss:[esp+0x21C]
	/*0064B3C5*/	cmp eax,ebx
	/*0064B3C7*/	je _0064B3CB
	/*0064B3C9*/	mov dword ptr ds:[eax],ebx
_0064B3CB:
	/*0064B3CB*/	mov ecx,dword ptr ss:[esp+0x214]
	/*0064B3D2*/	mov edx,dword ptr ss:[esp+0x218]
	/*0064B3D9*/	push 0xD0
	/*0064B3DE*/	mov word ptr ds:[ecx],0x2
	/*0064B3E3*/	mov word ptr ds:[edx],0xA0
	/*0064B3E8*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*0064B3ED*/	mov esi,eax
	/*0064B3EF*/	add esp,0x4
	/*0064B3F2*/	cmp esi,ebx
	/*0064B3F4*/	jne _0064B429
	/*0064B3F6*/	lea eax,dword ptr ss:[esp+0x10C]
	/*0064B3FD*/	lea ecx,dword ptr ss:[esp+0xC]
	/*0064B401*/	push eax
	/*0064B402*/	push ecx
	/*0064B403*/	push ebx
	/*0064B404*/	push ebx
	/*0064B405*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064B40A*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064B40F*/	add esp,0x14
	/*0064B412*/	lea edx,dword ptr ss:[esp+0x10C]
	/*0064B419*/	lea eax,dword ptr ss:[esp+0xC]
	/*0064B41D*/	push 0x155
	/*0064B422*/	push edx
	/*0064B423*/	push eax
	/*0064B424*/	jmp _0064B5A8
_0064B429:
	/*0064B429*/	movsx ecx,word ptr ds:[edi+0x40]
	/*0064B42D*/	push ecx
	/*0064B42E*/	push ebx
	/*0064B42F*/	push 0x1
	/*0064B431*/	push 0x4
	/*0064B433*/	push 0x8
	/*0064B435*/	push ebx
	/*0064B436*/	push esi
	/*0064B437*/	call sub_521E60		/*call <cm0102.sub_521E60>*/
	/*0064B43C*/	movsx edx,word ptr ds:[edi+0x40]
	/*0064B440*/	push ebx
	/*0064B441*/	push edx
	/*0064B442*/	push 0x1
	/*0064B444*/	push 0x6
	/*0064B446*/	push 0x1
	/*0064B448*/	push 0x4
	/*0064B44A*/	push 0x15
	/*0064B44C*/	push ebx
	/*0064B44D*/	push esi
	/*0064B44E*/	call sub_521EB0		/*call <cm0102.sub_521EB0>*/
	/*0064B453*/	mov word ptr ds:[esi+0x7],0x82
	/*0064B459*/	mov word ptr ds:[esi+0x9],bx
	/*0064B45D*/	mov word ptr ds:[esi+0xB],bx
	/*0064B461*/	mov word ptr ds:[esi+0xD],0xA00
	/*0064B467*/	mov byte ptr ds:[esi+0x17],0x5
	/*0064B46B*/	mov word ptr ds:[esi+0x18],0x4
	/*0064B471*/	mov word ptr ds:[esi+0x1A],0x2
	/*0064B477*/	mov word ptr ds:[esi+0x1C],0x4
	/*0064B47D*/	mov word ptr ds:[esi+0xF],0x802
	/*0064B483*/	mov word ptr ds:[esi+0x1E],bx
	/*0064B487*/	mov byte ptr ds:[esi+0x20],bl
	/*0064B48A*/	mov byte ptr ds:[esi+0x21],0x2
	/*0064B48E*/	mov byte ptr ds:[esi+0x22],0x7
	/*0064B492*/	mov dword ptr ds:[esi+0x5C],ebx
	/*0064B495*/	mov dword ptr ds:[esi+0x60],ebx
	/*0064B498*/	mov dword ptr ds:[esi+0x64],ebx
	/*0064B49B*/	movsx eax,word ptr ds:[edi+0x40]
	/*0064B49F*/	add esp,0x40
	/*0064B4A2*/	push eax
	/*0064B4A3*/	push ebx
	/*0064B4A4*/	push 0x1
	/*0064B4A6*/	push 0x4
	/*0064B4A8*/	push 0x1D
	/*0064B4AA*/	push 0x1
	/*0064B4AC*/	push esi
	/*0064B4AD*/	call sub_521E60		/*call <cm0102.sub_521E60>*/
	/*0064B4B2*/	movsx ecx,word ptr ds:[edi+0x40]
	/*0064B4B6*/	push ebx
	/*0064B4B7*/	mov edi,0x1
	/*0064B4BC*/	push ecx
	/*0064B4BD*/	push edi
	/*0064B4BE*/	push 0x6
	/*0064B4C0*/	push edi
	/*0064B4C1*/	push 0x5
	/*0064B4C3*/	push 0x4
	/*0064B4C5*/	push edi
	/*0064B4C6*/	push esi
	/*0064B4C7*/	call sub_521EB0		/*call <cm0102.sub_521EB0>*/
	/*0064B4CC*/	add esp,0x40
	/*0064B4CF*/	mov word ptr ds:[esi+0x71],di
	/*0064B4D3*/	mov word ptr ds:[esi+0x82],di
	/*0064B4DA*/	mov word ptr ds:[esi+0x6F],0x96
	/*0064B4E0*/	mov word ptr ds:[esi+0x73],bx
	/*0064B4E4*/	mov word ptr ds:[esi+0x75],0x800
	/*0064B4EA*/	mov byte ptr ds:[esi+0x7F],0x5
	/*0064B4EE*/	mov word ptr ds:[esi+0x80],0x2
	/*0064B4F7*/	mov word ptr ds:[esi+0x84],bx
	/*0064B4FE*/	mov word ptr ds:[esi+0x77],0x802
	/*0064B504*/	mov word ptr ds:[esi+0x86],bx
	/*0064B50B*/	mov byte ptr ds:[esi+0x88],bl
	/*0064B511*/	mov byte ptr ds:[esi+0x89],0x2
	/*0064B518*/	mov byte ptr ds:[esi+0x8A],0x7
	/*0064B51F*/	mov dword ptr ds:[esi+0xC4],ebx
	/*0064B525*/	mov dword ptr ds:[esi+0xC8],ebx
	/*0064B52B*/	mov dword ptr ds:[esi+0xCC],ebx
	/*0064B531*/	mov eax,esi
	/*0064B533*/	pop edi
	/*0064B534*/	pop esi
	/*0064B535*/	pop ebx
	/*0064B536*/	add esp,0x200
	/*0064B53C*/	ret 0x10
_0064B53F:
	/*0064B53F*/	cmp al,0x1
	/*0064B541*/	jne _0064B5D6
	/*0064B547*/	mov eax,dword ptr ss:[esp+0x21C]
	/*0064B54E*/	cmp eax,ebx
	/*0064B550*/	je _0064B554
	/*0064B552*/	mov dword ptr ds:[eax],ebx
_0064B554:
	/*0064B554*/	mov edx,dword ptr ss:[esp+0x214]
	/*0064B55B*/	mov eax,dword ptr ss:[esp+0x218]
	/*0064B562*/	push 0x68
	/*0064B564*/	mov word ptr ds:[edx],0x1
	/*0064B569*/	mov word ptr ds:[eax],bx
	/*0064B56C*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*0064B571*/	mov esi,eax
	/*0064B573*/	add esp,0x4
	/*0064B576*/	cmp esi,ebx
	/*0064B578*/	jne _0064B5E4
	/*0064B57A*/	lea ecx,dword ptr ss:[esp+0x10C]
	/*0064B581*/	lea edx,dword ptr ss:[esp+0xC]
	/*0064B585*/	push ecx
	/*0064B586*/	push edx
	/*0064B587*/	push ebx
	/*0064B588*/	push ebx
	/*0064B589*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064B58E*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064B593*/	add esp,0x14
	/*0064B596*/	lea eax,dword ptr ss:[esp+0x10C]
	/*0064B59D*/	lea ecx,dword ptr ss:[esp+0xC]
	/*0064B5A1*/	push 0x18F
	/*0064B5A6*/	push eax
	/*0064B5A7*/	push ecx
_0064B5A8:
	/*0064B5A8*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0064B5AD*/	push eax
	/*0064B5AE*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0064B5B3*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064B5B8*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0064B5BD*/	push ebx
	/*0064B5BE*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064B5C3*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0064B5C8*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0064B5CD*/	add esp,0x24
	/*0064B5D0*/	mov dword ptr ds:[0xB67A34],ebx
_0064B5D6:
	/*0064B5D6*/	pop edi
	/*0064B5D7*/	pop esi
	/*0064B5D8*/	xor eax,eax
	/*0064B5DA*/	pop ebx
	/*0064B5DB*/	add esp,0x200
	/*0064B5E1*/	ret 0x10
_0064B5E4:
	/*0064B5E4*/	movsx edx,word ptr ds:[edi+0x40]
	/*0064B5E8*/	push edx
	/*0064B5E9*/	push ebx
	/*0064B5EA*/	push 0x1
	/*0064B5EC*/	push 0x4
	/*0064B5EE*/	push 0x8
	/*0064B5F0*/	push ebx
	/*0064B5F1*/	push esi
	/*0064B5F2*/	call sub_521E60		/*call <cm0102.sub_521E60>*/
	/*0064B5F7*/	movsx eax,word ptr ds:[edi+0x40]
	/*0064B5FB*/	push ebx
	/*0064B5FC*/	push eax
	/*0064B5FD*/	push 0x1
	/*0064B5FF*/	push 0x6
	/*0064B601*/	push 0x1
	/*0064B603*/	push 0x4
	/*0064B605*/	push 0x15
	/*0064B607*/	push ebx
	/*0064B608*/	push esi
	/*0064B609*/	call sub_521EB0		/*call <cm0102.sub_521EB0>*/
	/*0064B60E*/	add esp,0x40
	/*0064B611*/	mov word ptr ds:[esi+0x7],0xBE
	/*0064B617*/	mov word ptr ds:[esi+0x9],bx
	/*0064B61B*/	mov word ptr ds:[esi+0xB],bx
	/*0064B61F*/	mov word ptr ds:[esi+0xD],0x200
	/*0064B625*/	mov byte ptr ds:[esi+0x17],0x5
	/*0064B629*/	mov word ptr ds:[esi+0x18],0x4
	/*0064B62F*/	mov word ptr ds:[esi+0x1A],0x2
	/*0064B635*/	mov word ptr ds:[esi+0x1C],0x4
	/*0064B63B*/	mov word ptr ds:[esi+0xF],0x800
	/*0064B641*/	mov word ptr ds:[esi+0x1E],bx
	/*0064B645*/	mov byte ptr ds:[esi+0x20],bl
	/*0064B648*/	mov byte ptr ds:[esi+0x21],0x2
	/*0064B64C*/	mov byte ptr ds:[esi+0x22],0x7
	/*0064B650*/	mov dword ptr ds:[esi+0x5C],ebx
	/*0064B653*/	mov dword ptr ds:[esi+0x60],ebx
	/*0064B656*/	mov dword ptr ds:[esi+0x64],ebx
	/*0064B659*/	mov eax,esi
	/*0064B65B*/	pop edi
	/*0064B65C*/	pop esi
	/*0064B65D*/	pop ebx
	/*0064B65E*/	add esp,0x200
	/*0064B664*/	ret 0x10
	}
}


void __declspec(naked) sub_64B670_add_teams()
{
	__asm
	{
	/*0064B670*/	sub esp,0x200
	/*0064B676*/	push ebx
	/*0064B677*/	push ebp
	/*0064B678*/	push edi
	/*0064B679*/	mov edi,ecx
	/*0064B67B*/	push 0x426
	/*0064B680*/	xor bl,bl
	/*0064B682*/	mov word ptr ds:[edi+0x3E],0x12
	/*0064B688*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*0064B68D*/	xor ebp,ebp
	/*0064B68F*/	add esp,0x4
	/*0064B692*/	cmp eax,ebp
	/*0064B694*/	mov dword ptr ds:[edi+0xB1],eax
	/*0064B69A*/	jne _0064B704
	/*0064B69C*/	lea eax,dword ptr ss:[esp+0xC]
	/*0064B6A0*/	lea ecx,dword ptr ss:[esp+0x10C]
	/*0064B6A7*/	push eax
	/*0064B6A8*/	push ecx
	/*0064B6A9*/	push ebp
	/*0064B6AA*/	push ebp
	/*0064B6AB*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064B6B0*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064B6B5*/	add esp,0x14
	/*0064B6B8*/	lea edx,dword ptr ss:[esp+0xC]
	/*0064B6BC*/	lea eax,dword ptr ss:[esp+0x10C]
	/*0064B6C3*/	push 0x1BD
	/*0064B6C8*/	push edx
	/*0064B6C9*/	push eax
	/*0064B6CA*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0064B6CF*/	push eax
	/*0064B6D0*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0064B6D5*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064B6DA*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0064B6DF*/	push ebp
	/*0064B6E0*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064B6E5*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0064B6EA*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0064B6EF*/	add esp,0x24
	/*0064B6F2*/	mov dword ptr ds:[0xB67A34],ebp
	/*0064B6F8*/	xor eax,eax
	/*0064B6FA*/	pop edi
	/*0064B6FB*/	pop ebp
	/*0064B6FC*/	pop ebx
	/*0064B6FD*/	add esp,0x200
	/*0064B703*/	ret
_0064B704:
	/*0064B704*/	mov eax,dword ptr ds:[0xAE235C]
	/*0064B709*/	push esi
	/*0064B70A*/	mov esi,dword ptr ds:[0xAE23B4]
	/*0064B710*/	test eax,eax
	/*0064B712*/	jle _0064B755
_0064B714:
	/*0064B714*/	mov eax,dword ptr ds:[esi+0x57]
	/*0064B717*/	test eax,eax
	/*0064B719*/	je _0064B741
	/*0064B71B*/	mov ecx,dword ptr ds:[eax]
	/*0064B71D*/	mov eax,dword ptr ds:[0x9CF578] // [9cf578] = Italian Serie C1 A
	/*0064B722*/	cmp ecx,eax
	/*0064B724*/	jne _0064B741
	/*0064B726*/	push 0x0
	/*0064B728*/	mov al,bl
	/*0064B72A*/	push 0x0
	/*0064B72C*/	push esi
	/*0064B72D*/	push eax
	/*0064B72E*/	mov ecx,edi
	/*0064B730*/	inc bl
	/*0064B732*/	call sub_687430		/*call <cm0102.sub_687430>*/
	/*0064B737*/	movsx dx,bl
	/*0064B73B*/	cmp dx,word ptr ds:[edi+0x3E]
	/*0064B73F*/	je _0064B755
_0064B741:
	/*0064B741*/	mov ecx,dword ptr ds:[0xAE235C]
	/*0064B747*/	inc ebp
	/*0064B748*/	movsx eax,bp
	/*0064B74B*/	add esi,0x245
	/*0064B751*/	cmp eax,ecx
	/*0064B753*/	jl _0064B714
_0064B755:
	/*0064B755*/	movsx cx,bl
	/*0064B759*/	xor eax,eax
	/*0064B75B*/	cmp cx,word ptr ds:[edi+0x3E]
	/*0064B75F*/	pop esi
	/*0064B760*/	pop edi
	/*0064B761*/	pop ebp
	/*0064B762*/	pop ebx
	/*0064B763*/	sete al
	/*0064B766*/	add esp,0x200
	/*0064B76C*/	ret
	}
}

void __declspec(naked) sub_64B770()
{
	__asm
	{
	/*0064B770*/	push ebx
	/*0064B771*/	push esi
	/*0064B772*/	mov esi,ecx
	/*0064B774*/	mov dl,0x3
	/*0064B776*/	mov ecx,0x2
	/*0064B77B*/	mov ebx,0x1
	/*0064B780*/	mov word ptr ds:[esi+0x3C],cx
	/*0064B784*/	mov byte ptr ds:[esi+0xC4],cl
	/*0064B78A*/	mov byte ptr ds:[esi+0xC6],cl
	/*0064B790*/	xor eax,eax
	/*0064B792*/	mov cl,0x4
	/*0064B794*/	mov byte ptr ds:[esi+0xC2],dl
	/*0064B79A*/	mov byte ptr ds:[esi+0xC3],bl
	/*0064B7A0*/	mov word ptr ds:[esi+0xAB],ax
	/*0064B7A7*/	mov word ptr ds:[esi+0xDB],ax
	/*0064B7AE*/	mov byte ptr ds:[esi+0x42],bl
	/*0064B7B1*/	mov byte ptr ds:[esi+0xC5],bl
	/*0064B7B7*/	mov byte ptr ds:[esi+0xC7],al
	/*0064B7BD*/	mov byte ptr ds:[esi+0xBE],bl
	/*0064B7C3*/	mov byte ptr ds:[esi+0xBF],cl
	/*0064B7C9*/	mov byte ptr ds:[esi+0xC0],cl
	/*0064B7CF*/	mov byte ptr ds:[esi+0xC1],bl
	/*0064B7D5*/	mov ecx,dword ptr ds:[0x9CF574]				// [9cf574] = Italian Serie B
	/*0064B7DB*/	push eax
	/*0064B7DC*/	mov dword ptr ds:[esi+0x1C], ecx			// +1C = Promotion League   ( 0xffffffff = none )
	/*0064B7DF*/	mov ecx,dword ptr ds:[0x9CF57C]				// [9cf57c] = Italian Serie C1 B
	/*0064B7E5*/	or byte ptr ds:[esi+0xD9],0x40
	/*0064B7EC*/	mov dword ptr ds:[esi+0x20], ecx			// +20 = Relegation League  ( 0xffffffff = none )
	/*0064B7EF*/	lea eax,dword ptr ds:[esi+0x3A]
	/*0064B7F2*/	lea ecx,dword ptr ds:[esi+0xA9]
	/*0064B7F8*/	mov byte ptr ds:[esi+0x4A],dl
	/*0064B7FB*/	mov edx,dword ptr ds:[esi]
	/*0064B7FD*/	push eax
	/*0064B7FE*/	push ecx
	/*0064B7FF*/	push 0xFFFFFFFF
	/*0064B801*/	mov ecx,esi
	/*0064B803*/	mov byte ptr ds:[esi+0x49],0x7
	/*0064B807*/	call dword ptr ds:[edx+0x3C]
	/*0064B80A*/	mov dword ptr ds:[esi+0xBA],eax
	/*0064B810*/	mov eax,ebx
	/*0064B812*/	pop esi
	/*0064B813*/	pop ebx
	/*0064B814*/	ret
	}
}

void __declspec(naked) sub_64B820()
{
	__asm
	{
	/*0064B820*/	sub esp,0x200
	/*0064B826*/	push ebx
	/*0064B827*/	push esi
	/*0064B828*/	mov esi,ecx
	/*0064B82A*/	xor ebx,ebx
	/*0064B82C*/	push ebx
	/*0064B82D*/	mov dword ptr ds:[esi+0x4C],ebx
	/*0064B830*/	call sub_687970		/*call <cm0102.sub_687970>*/
	/*0064B835*/	mov eax,dword ptr ds:[esi+0xBA]
	/*0064B83B*/	cmp eax,ebx
	/*0064B83D*/	je _0064B84E
	/*0064B83F*/	push eax
	/*0064B840*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*0064B845*/	add esp,0x4
	/*0064B848*/	mov dword ptr ds:[esi+0xBA],ebx
_0064B84E:
	/*0064B84E*/	mov ecx,dword ptr ds:[esi+0x8]
	/*0064B851*/	cmp ecx,ebx
	/*0064B853*/	je _0064B85C
	/*0064B855*/	push 0x1
	/*0064B857*/	call sub_4A1C50		/*call <cm0102.sub_4A1C50>*/
_0064B85C:
	/*0064B85C*/	mov eax,dword ptr ds:[esi+0x30]
	/*0064B85F*/	push edi
	/*0064B860*/	xor edi,edi
	/*0064B862*/	cmp eax,ebx
	/*0064B864*/	jl _0064B87E
_0064B866:
	/*0064B866*/	mov eax,dword ptr ds:[esi+0xC]
	/*0064B869*/	mov ecx,dword ptr ds:[eax+edi*0x4]
	/*0064B86C*/	cmp ecx,ebx
	/*0064B86E*/	je _0064B876
	/*0064B870*/	mov edx,dword ptr ds:[ecx]
	/*0064B872*/	push 0x1
	/*0064B874*/	call dword ptr ds:[edx]
_0064B876:
	/*0064B876*/	mov eax,dword ptr ds:[esi+0x30]
	/*0064B879*/	inc edi
	/*0064B87A*/	cmp edi,eax
	/*0064B87C*/	jle _0064B866
_0064B87E:
	/*0064B87E*/	mov eax,dword ptr ds:[esi]
	/*0064B880*/	inc word ptr ds:[esi+0x40]
	/*0064B884*/	mov ecx,esi
	/*0064B886*/	mov dword ptr ds:[esi+0x30],0xFFFFFFFF
	/*0064B88D*/	call dword ptr ds:[eax+0x8C]
	/*0064B893*/	test eax,eax
	/*0064B895*/	pop edi
	/*0064B896*/	jne _0064B8CA
	/*0064B898*/	lea ecx,dword ptr ss:[esp+0x8]
	/*0064B89C*/	lea edx,dword ptr ss:[esp+0x108]
	/*0064B8A3*/	push ecx
	/*0064B8A4*/	push edx
	/*0064B8A5*/	push ebx
	/*0064B8A6*/	push ebx
	/*0064B8A7*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064B8AC*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064B8B1*/	add esp,0x14
	/*0064B8B4*/	lea eax,dword ptr ss:[esp+0x8]
	/*0064B8B8*/	lea ecx,dword ptr ss:[esp+0x108]
	/*0064B8BF*/	push 0x220
	/*0064B8C4*/	push eax
	/*0064B8C5*/	jmp _0064B979
_0064B8CA:
	/*0064B8CA*/	mov ecx,esi
	///*0064B8CC*/	call sub_64B670_add_teams		/*call <cm0102.sub_64B670_add_teams>*/
					push ecx
					call AddTeams
					add esp, 0x4

	/*0064B8D1*/	test eax,eax
	/*0064B8D3*/	jne _0064B905
	/*0064B8D5*/	lea edx,dword ptr ss:[esp+0x108]
	/*0064B8DC*/	lea eax,dword ptr ss:[esp+0x8]
	/*0064B8E0*/	push edx
	/*0064B8E1*/	push eax
	/*0064B8E2*/	push ebx
	/*0064B8E3*/	push ebx
	/*0064B8E4*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064B8E9*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064B8EE*/	add esp,0x14
	/*0064B8F1*/	lea ecx,dword ptr ss:[esp+0x108]
	/*0064B8F8*/	lea edx,dword ptr ss:[esp+0x8]
	/*0064B8FC*/	push 0x227
	/*0064B901*/	push ecx
	/*0064B902*/	push edx
	/*0064B903*/	jmp _0064B97A
_0064B905:
	/*0064B905*/	mov ecx,esi
	/*0064B907*/	call sub_6835C0		/*call <cm0102.sub_6835C0>*/
	/*0064B90C*/	test eax,eax
	/*0064B90E*/	jne _0064B940
	/*0064B910*/	lea eax,dword ptr ss:[esp+0x108]
	/*0064B917*/	lea ecx,dword ptr ss:[esp+0x8]
	/*0064B91B*/	push eax
	/*0064B91C*/	push ecx
	/*0064B91D*/	push ebx
	/*0064B91E*/	push ebx
	/*0064B91F*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064B924*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064B929*/	add esp,0x14
	/*0064B92C*/	lea edx,dword ptr ss:[esp+0x108]
	/*0064B933*/	lea eax,dword ptr ss:[esp+0x8]
	/*0064B937*/	push 0x22D
	/*0064B93C*/	push edx
	/*0064B93D*/	push eax
	/*0064B93E*/	jmp _0064B97A
_0064B940:
	/*0064B940*/	push ebx
	/*0064B941*/	mov ecx,esi
	/*0064B943*/	call sub_6827D0		/*call <cm0102.sub_6827D0>*/
	/*0064B948*/	test eax,eax
	/*0064B94A*/	jne _0064B9B1
	/*0064B94C*/	lea ecx,dword ptr ss:[esp+0x108]
	/*0064B953*/	lea edx,dword ptr ss:[esp+0x8]
	/*0064B957*/	push ecx
	/*0064B958*/	push edx
	/*0064B959*/	push ebx
	/*0064B95A*/	push ebx
	/*0064B95B*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064B960*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064B965*/	add esp,0x14
	/*0064B968*/	lea eax,dword ptr ss:[esp+0x108]
	/*0064B96F*/	lea ecx,dword ptr ss:[esp+0x8]
	/*0064B973*/	push 0x234
	/*0064B978*/	push eax
_0064B979:
	/*0064B979*/	push ecx
_0064B97A:
	/*0064B97A*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0064B97F*/	push eax
	/*0064B980*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0064B985*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064B98A*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0064B98F*/	push ebx
	/*0064B990*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064B995*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0064B99A*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0064B99F*/	add esp,0x24
	/*0064B9A2*/	mov dword ptr ds:[0xB67A34],ebx
	/*0064B9A8*/	pop esi
	/*0064B9A9*/	pop ebx
	/*0064B9AA*/	add esp,0x200
	/*0064B9B0*/	ret
_0064B9B1:
	/*0064B9B1*/	mov edx,dword ptr ds:[esi]
	/*0064B9B3*/	mov ecx,esi
	/*0064B9B5*/	call dword ptr ds:[edx+0x5C]
	/*0064B9B8*/	mov ecx,esi
	/*0064B9BA*/	call sub_68AA80		/*call <cm0102.sub_68AA80>*/
	/*0064B9BF*/	mov eax,dword ptr ds:[esi+0x4]
	/*0064B9C2*/	mov ecx,dword ptr ds:[0xB74340]
	/*0064B9C8*/	push eax
	/*0064B9C9*/	call sub_79CEE0		/*call <cm0102.sub_79CEE0>*/
	/*0064B9CE*/	pop esi
	/*0064B9CF*/	pop ebx
	/*0064B9D0*/	add esp,0x200
	/*0064B9D6*/	ret
	}
}

void __declspec(naked) sub_64B9E0()			// Loads up the function linking to the super cup
{
	__asm
	{
					ret											// Skip this function for now

	/*0064B9E0*/	mov edx,dword ptr ds:[ecx+0x2C]
	/*0064B9E3*/	mov eax,dword ptr ds:[ecx+0x30]
	/*0064B9E6*/	sub esp,0x200
	/*0064B9EC*/	dec edx
	/*0064B9ED*/	cmp eax,edx
	/*0064B9EF*/	jl _0064BA5B
	/*0064B9F1*/	lea eax,dword ptr ss:[esp]
	/*0064B9F5*/	lea ecx,dword ptr ss:[esp+0x100]
	/*0064B9FC*/	push eax
	/*0064B9FD*/	push ecx
	/*0064B9FE*/	push 0x0
	/*0064BA00*/	push 0x0
	/*0064BA02*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064BA07*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064BA0C*/	add esp,0x14
	/*0064BA0F*/	lea edx,dword ptr ss:[esp]
	/*0064BA13*/	lea eax,dword ptr ss:[esp+0x100]
	/*0064BA1A*/	push 0x250
	/*0064BA1F*/	push edx
	/*0064BA20*/	push eax
	/*0064BA21*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0064BA26*/	push eax
	/*0064BA27*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0064BA2C*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064BA31*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0064BA36*/	push 0x0
	/*0064BA38*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064BA3D*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0064BA42*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0064BA47*/	add esp,0x24
	/*0064BA4A*/	mov dword ptr ds:[0xB67A34],0x0
	/*0064BA54*/	add esp,0x200
	/*0064BA5A*/	ret
_0064BA5B:
	/*0064BA5B*/	inc eax
	/*0064BA5C*/	test eax,eax
	/*0064BA5E*/	mov dword ptr ds:[ecx+0x30],eax
	/*0064BA61*/	jne _0064BA68
	/*0064BA63*/	call sub_64BA70		/*call <cm0102.sub_64BA70>*/
_0064BA68:
	/*0064BA68*/	add esp,0x200
	/*0064BA6E*/	ret
	}
}

void __declspec(naked) sub_64BA70()
{
	__asm
	{
	/*0064BA70*/	push 0xFFFFFFFF
	/*0064BA72*/	push 0x95BAEC		/*push <cm0102.sub_95BAEC>*/
	/*0064BA77*/	mov eax,dword ptr fs:[0x0]
	/*0064BA7D*/	push eax
	/*0064BA7E*/	mov dword ptr fs:[0x0],esp
	/*0064BA85*/	sub esp,0x410
	/*0064BA8B*/	mov eax,dword ptr ds:[0xADADFC]
	/*0064BA90*/	push ebx
	/*0064BA91*/	push ebp
	/*0064BA92*/	push esi
	/*0064BA93*/	mov esi,ecx
	/*0064BA95*/	mov byte ptr ss:[esp+0xC],0x4
	/*0064BA9A*/	mov ecx,dword ptr ds:[0x9CF938]				// [9cf938] = Italian C1 Super Cup
	/*0064BAA0*/	mov byte ptr ss:[esp+0xD],0x1
	/*0064BAA5*/	mov edx,dword ptr ds:[esi+0xB1]
	/*0064BAAB*/	mov byte ptr ss:[esp+0xE],0x3
	/*0064BAB0*/	mov byte ptr ss:[esp+0xF],0x2
	/*0064BAB5*/	mov eax,dword ptr ds:[eax+ecx*0x4]
	/*0064BAB8*/	xor ebx,ebx
	/*0064BABA*/	push edi
	/*0064BABB*/	mov eax,dword ptr ds:[eax+0xA7]
	/*0064BAC1*/	mov ecx,dword ptr ds:[eax]
	/*0064BAC3*/	cmp ecx,ebx
	/*0064BAC5*/	mov ecx,dword ptr ds:[edx]
	/*0064BAC7*/	je _0064BACE
	/*0064BAC9*/	mov dword ptr ds:[eax+0x6],ecx
	/*0064BACC*/	jmp _0064BAD0
_0064BACE:
	/*0064BACE*/	mov dword ptr ds:[eax],ecx
_0064BAD0:
	/*0064BAD0*/	push 0x10
	/*0064BAD2*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc>*/
	/*0064BAD7*/	mov edi,eax
	/*0064BAD9*/	add esp,0x4
	/*0064BADC*/	cmp edi,ebx
	/*0064BADE*/	jne _0064BB13
	/*0064BAE0*/	lea edx,dword ptr ss:[esp+0x120]
	/*0064BAE7*/	lea eax,dword ptr ss:[esp+0x20]
	/*0064BAEB*/	push edx
	/*0064BAEC*/	push eax
	/*0064BAED*/	push ebx
	/*0064BAEE*/	push ebx
	/*0064BAEF*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064BAF4*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064BAF9*/	add esp,0x14
	/*0064BAFC*/	lea ecx,dword ptr ss:[esp+0x120]
	/*0064BB03*/	lea edx,dword ptr ss:[esp+0x20]
	/*0064BB07*/	push 0x27C
	/*0064BB0C*/	push ecx
	/*0064BB0D*/	push edx
	/*0064BB0E*/	jmp _0064BD26
_0064BB13:
	/*0064BB13*/	mov eax,dword ptr ds:[esi+0xB1]
	/*0064BB19*/	push ebx
	/*0064BB1A*/	mov ecx,dword ptr ds:[eax+0xEC]
	/*0064BB20*/	mov dword ptr ds:[edi],ecx
	/*0064BB22*/	mov edx,dword ptr ds:[esi+0xB1]
	/*0064BB28*/	mov eax,dword ptr ds:[edx+0x3B]
	/*0064BB2B*/	mov dword ptr ds:[edi+0x4],eax
	/*0064BB2E*/	mov ecx,dword ptr ds:[esi+0xB1]
	/*0064BB34*/	mov edx,dword ptr ds:[ecx+0xB1]
	/*0064BB3A*/	mov dword ptr ds:[edi+0x8],edx
	/*0064BB3D*/	mov eax,dword ptr ds:[esi+0xB1]
	/*0064BB43*/	mov ecx,dword ptr ds:[eax+0x76]
	/*0064BB46*/	lea eax,dword ptr ss:[esp+0x18]
	/*0064BB4A*/	mov dword ptr ds:[edi+0xC],ecx
	/*0064BB4D*/	mov edx,dword ptr ds:[esi]
	/*0064BB4F*/	lea ecx,dword ptr ss:[esp+0x1C]
	/*0064BB53*/	push eax
	/*0064BB54*/	push ecx
	/*0064BB55*/	push ebx
	/*0064BB56*/	mov ecx,esi
	/*0064BB58*/	call dword ptr ds:[edx+0x3C]
	/*0064BB5B*/	push 0xB2
	/*0064BB60*/	mov ebp,eax
	/*0064BB62*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*0064BB67*/	add esp,0x4
	/*0064BB6A*/	mov dword ptr ss:[esp+0x1C],eax
	/*0064BB6E*/	cmp eax,ebx
	/*0064BB70*/	mov dword ptr ss:[esp+0x428],ebx
	/*0064BB77*/	je _0064BBAE
	/*0064BB79*/	mov ecx,dword ptr ss:[esp+0x14]
	/*0064BB7D*/	lea edx,dword ptr ss:[esp+0x10]
	/*0064BB81*/	push edx
	/*0064BB82*/	mov dx,word ptr ds:[esi+0x40]
	/*0064BB86*/	push ebx
	/*0064BB87*/	push ebx
	/*0064BB88*/	push ebx
	/*0064BB89*/	push 0x14
	/*0064BB8B*/	push ecx
	/*0064BB8C*/	mov ecx,dword ptr ds:[esi+0x4]
	/*0064BB8F*/	push 0x1
	/*0064BB91*/	push ebx
	/*0064BB92*/	push edx
	/*0064BB93*/	mov edx,dword ptr ss:[esp+0x3C]
	/*0064BB97*/	push ebp
	/*0064BB98*/	push ecx
	/*0064BB99*/	movsx cx,byte ptr ds:[esi+0xBF]
	/*0064BBA1*/	push edx
	/*0064BBA2*/	push edi
	/*0064BBA3*/	push ecx
	/*0064BBA4*/	push esi
	/*0064BBA5*/	mov ecx,eax
	/*0064BBA7*/	call sub_522E00		/*call <cm0102.sub_522E00>*/
	/*0064BBAC*/	jmp _0064BBB0
_0064BBAE:
	/*0064BBAE*/	xor eax,eax
_0064BBB0:
	/*0064BBB0*/	mov edx,dword ptr ds:[esi+0xC]
	/*0064BBB3*/	mov dword ptr ss:[esp+0x428],0xFFFFFFFF
	/*0064BBBE*/	mov dword ptr ds:[edx],eax
	/*0064BBC0*/	mov eax,dword ptr ds:[esi+0xC]
	/*0064BBC3*/	mov ecx,dword ptr ds:[eax]
	/*0064BBC5*/	cmp ecx,ebx
	/*0064BBC7*/	jne _0064BBFC
	/*0064BBC9*/	lea ecx,dword ptr ss:[esp+0x20]
	/*0064BBCD*/	lea edx,dword ptr ss:[esp+0x120]
	/*0064BBD4*/	push ecx
	/*0064BBD5*/	push edx
	/*0064BBD6*/	push ebx
	/*0064BBD7*/	push ebx
	/*0064BBD8*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064BBDD*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064BBE2*/	add esp,0x14
	/*0064BBE5*/	lea eax,dword ptr ss:[esp+0x20]
	/*0064BBE9*/	lea ecx,dword ptr ss:[esp+0x120]
	/*0064BBF0*/	push 0x290
	/*0064BBF5*/	push eax
	/*0064BBF6*/	push ecx
	/*0064BBF7*/	jmp _0064BD26
_0064BBFC:
	/*0064BBFC*/	push ebx
	/*0064BBFD*/	call sub_51C800		/*call <cm0102.sub_51C800>*/
	/*0064BC02*/	push ebp
	/*0064BC03*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*0064BC08*/	mov edx,dword ptr ds:[esi]
	/*0064BC0A*/	add esp,0x4
	/*0064BC0D*/	lea eax,dword ptr ss:[esp+0x14]
	/*0064BC11*/	lea ecx,dword ptr ss:[esp+0x18]
	/*0064BC15*/	push ebx
	/*0064BC16*/	push eax
	/*0064BC17*/	push ecx
	/*0064BC18*/	push 0x1
	/*0064BC1A*/	mov ecx,esi
	/*0064BC1C*/	call dword ptr ds:[edx+0x3C]
	/*0064BC1F*/	mov edx,dword ptr ds:[esi+0xB1]
	/*0064BC25*/	mov ebp,eax
	/*0064BC27*/	push 0xB2
	/*0064BC2C*/	mov eax,dword ptr ds:[edx+0x3B0]
	/*0064BC32*/	mov dword ptr ds:[edi],eax
	/*0064BC34*/	mov ecx,dword ptr ds:[esi+0xB1]
	/*0064BC3A*/	mov edx,dword ptr ds:[ecx+0x2FF]
	/*0064BC40*/	mov dword ptr ds:[edi+0x4],edx
	/*0064BC43*/	mov eax,dword ptr ds:[esi+0xB1]
	/*0064BC49*/	mov ecx,dword ptr ds:[eax+0x375]
	/*0064BC4F*/	mov dword ptr ds:[edi+0x8],ecx
	/*0064BC52*/	mov edx,dword ptr ds:[esi+0xB1]
	/*0064BC58*/	mov eax,dword ptr ds:[edx+0x33A]
	/*0064BC5E*/	mov dword ptr ds:[edi+0xC],eax
	/*0064BC61*/	mov byte ptr ss:[esp+0x14],0x10
	/*0064BC66*/	mov byte ptr ss:[esp+0x15],0xD
	/*0064BC6B*/	mov byte ptr ss:[esp+0x16],0xF
	/*0064BC70*/	mov byte ptr ss:[esp+0x17],0xE
	/*0064BC75*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*0064BC7A*/	add esp,0x4
	/*0064BC7D*/	mov dword ptr ss:[esp+0x1C],eax
	/*0064BC81*/	cmp eax,ebx
	/*0064BC83*/	mov dword ptr ss:[esp+0x428],0x1
	/*0064BC8E*/	je _0064BCC6
	/*0064BC90*/	mov edx,dword ptr ss:[esp+0x14]
	/*0064BC94*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0064BC98*/	push ecx
	/*0064BC99*/	mov cx,word ptr ds:[esi+0x40]
	/*0064BC9D*/	push ebx
	/*0064BC9E*/	push ebx
	/*0064BC9F*/	push ebx
	/*0064BCA0*/	push 0x14
	/*0064BCA2*/	push edx
	/*0064BCA3*/	mov edx,dword ptr ds:[esi+0x4]
	/*0064BCA6*/	push 0x1
	/*0064BCA8*/	push 0x1
	/*0064BCAA*/	push ecx
	/*0064BCAB*/	mov ecx,dword ptr ss:[esp+0x3C]
	/*0064BCAF*/	push ebp
	/*0064BCB0*/	push edx
	/*0064BCB1*/	movsx dx,byte ptr ds:[esi+0xBF]
	/*0064BCB9*/	push ecx
	/*0064BCBA*/	push edi
	/*0064BCBB*/	push edx
	/*0064BCBC*/	push esi
	/*0064BCBD*/	mov ecx,eax
	/*0064BCBF*/	call sub_522E00		/*call <cm0102.sub_522E00>*/
	/*0064BCC4*/	jmp _0064BCC8
_0064BCC6:
	/*0064BCC6*/	xor eax,eax
_0064BCC8:
	/*0064BCC8*/	mov ecx,dword ptr ds:[esi+0xC]
	/*0064BCCB*/	push edi
	/*0064BCCC*/	mov dword ptr ss:[esp+0x42C],0xFFFFFFFF
	/*0064BCD7*/	mov dword ptr ds:[ecx+0x4],eax
	/*0064BCDA*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*0064BCDF*/	push ebp
	/*0064BCE0*/	call sub_9452CA		/*call <cm0102.sub_9452CA>*/
	/*0064BCE5*/	mov edx,dword ptr ds:[esi+0xC]
	/*0064BCE8*/	add esp,0x8
	/*0064BCEB*/	mov ecx,dword ptr ds:[edx+0x4]
	/*0064BCEE*/	cmp ecx,ebx
	/*0064BCF0*/	jne _0064BD56
	/*0064BCF2*/	lea eax,dword ptr ss:[esp+0x220]
	/*0064BCF9*/	lea ecx,dword ptr ss:[esp+0x320]
	/*0064BD00*/	push eax
	/*0064BD01*/	push ecx
	/*0064BD02*/	push ebx
	/*0064BD03*/	push ebx
	/*0064BD04*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064BD09*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064BD0E*/	add esp,0x14
	/*0064BD11*/	lea edx,dword ptr ss:[esp+0x220]
	/*0064BD18*/	lea eax,dword ptr ss:[esp+0x320]
	/*0064BD1F*/	push 0x2B3
	/*0064BD24*/	push edx
	/*0064BD25*/	push eax
_0064BD26:
	/*0064BD26*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0064BD2B*/	push eax
	/*0064BD2C*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0064BD31*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064BD36*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0064BD3B*/	push ebx
	/*0064BD3C*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064BD41*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0064BD46*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0064BD4B*/	add esp,0x24
	/*0064BD4E*/	mov dword ptr ds:[0xB67A34],ebx
	/*0064BD54*/	jmp _0064BD63
_0064BD56:
	/*0064BD56*/	push ebx
	/*0064BD57*/	call sub_51C800		/*call <cm0102.sub_51C800>*/
	/*0064BD5C*/	mov dword ptr ds:[esi+0x30],0x1
_0064BD63:
	/*0064BD63*/	mov ecx,dword ptr ss:[esp+0x420]
	/*0064BD6A*/	pop edi
	/*0064BD6B*/	pop esi
	/*0064BD6C*/	pop ebp
	/*0064BD6D*/	pop ebx
	/*0064BD6E*/	mov dword ptr fs:[0x0],ecx
	/*0064BD75*/	add esp,0x41C
	/*0064BD7B*/	ret
	}
}

//			 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F	
// 0064BE58  00 00 00 00 02 02 02 02 02 02 02 02 01 01 01 01  ................  
// 0064BE4C  BA BD 64 00 BE BD 64 00 C2 BD 64 00 00 00 00 00  º½d.¾½d.Â½d.....  
// 0 = 64BDBA
// 1 = 64BDBE
// 2 = 64BDC2
//			 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F	
// 0064BE74  00 00 00 00 02 02 02 02 02 02 02 02 01 01 01 01  ................  
// 0064BE68  E6 BD 64 00 ED BD 64 00 35 BE 64 00 00 00 00 00  æ½d.í½d.5¾d.....
// 0 = 64BDE6
// 1 = 64BDEB
// 2 = 64BE35

void __declspec(naked) sub_64BD80()	// jmp tables
{
	__asm
	{
	/*0064BD80*/	mov eax,dword ptr ss:[esp+0x4]
	/*0064BD84*/	mov ecx,dword ptr ds:[ecx+0x8]
	/*0064BD87*/	push esi
	/*0064BD88*/	push eax
	/*0064BD89*/	call sub_4A4850		/*call <cm0102.sub_4A4850>*/
	/*0064BD8E*/	mov cl,byte ptr ss:[esp+0xC]
	/*0064BD92*/	mov esi,eax
	/*0064BD94*/	cmp cl,0xFF
	/*0064BD97*/	jne _0064BDF4
	/*0064BD99*/	mov ecx,dword ptr ss:[esp+0x14]
	/*0064BD9D*/	and ecx,0xFF
	/*0064BDA3*/	add ecx,0xFFFFFFFE
	/*0064BDA6*/	cmp ecx,0xF
	/*0064BDA9*/	ja _0064BDC2
	/*0064BDAB*/	xor edx,edx
	/*0064BDAD*/	//mov dl,byte ptr ds:[ecx+0x64BE58]
	/*0064BDB3*/	//jmp dword ptr ds:[edx*0x4+0x64BE4C]
					cmp cl, 0x3
					jle _0064BDBA
					cmp cl, 0xB
					jle _0064BDC2
					jmp _0064BDBE
_0064BDBA:
	/*0064BDBA*/	mov cl,0x2
	/*0064BDBC*/	jmp _0064BDC6
_0064BDBE:
	/*0064BDBE*/	mov cl,0xE
	/*0064BDC0*/	jmp _0064BDC6
_0064BDC2:
	/*0064BDC2*/	mov cl,byte ptr ss:[esp+0x14]
_0064BDC6:
	/*0064BDC6*/	mov eax,dword ptr ss:[esp+0x18]
	/*0064BDCA*/	and eax,0xFF
	/*0064BDCF*/	lea edx,dword ptr ds:[eax-0x2]
	/*0064BDD2*/	cmp edx,0xF
	/*0064BDD5*/	ja _0064BE35
	/*0064BDD7*/	xor eax,eax
					cmp dl, 0x3
					jle _0064BDE6
					cmp dl, 0xB
					jle _0064BE35
					jmp _0064BDED
	/*0064BDD9*/	//mov al,byte ptr ds:[edx+0x64BE74]
	/*0064BDDF*/	//jmp dword ptr ds:[eax*0x4+0x64BE68]
_0064BDE6:
	/*0064BDE6*/	mov byte ptr ss:[esp+0x18],0x5
	/*0064BDEB*/	jmp _0064BE35
_0064BDED:
	/*0064BDED*/	mov byte ptr ss:[esp+0x18],0x11
	/*0064BDF2*/	jmp _0064BE35
_0064BDF4:
	/*0064BDF4*/	test cl,cl
	/*0064BDF6*/	jne _0064BE14
	/*0064BDF8*/	mov cl,byte ptr ss:[esp+0x14]
	/*0064BDFC*/	mov dl,byte ptr ss:[esp+0x18]
	/*0064BE00*/	mov al,byte ptr ss:[esp+0x10]
	/*0064BE04*/	inc cl
	/*0064BE06*/	inc dl
	/*0064BE08*/	inc al
	/*0064BE0A*/	mov byte ptr ss:[esp+0x18],dl
	/*0064BE0E*/	mov byte ptr ss:[esp+0x10],al
	/*0064BE12*/	jmp _0064BE35
_0064BE14:
	/*0064BE14*/	cmp cl,0x1
	/*0064BE17*/	jne _0064BE31
	/*0064BE19*/	mov ecx,dword ptr ss:[esp+0x14]
	/*0064BE1D*/	and ecx,0xFF
	/*0064BE23*/	dec ecx
	/*0064BE24*/	je _0064BE2D
	/*0064BE26*/	dec ecx
	/*0064BE27*/	jne _0064BE31
	/*0064BE29*/	mov cl,0x10
	/*0064BE2B*/	jmp _0064BE35
_0064BE2D:
	/*0064BE2D*/	mov cl,0xE
	/*0064BE2F*/	jmp _0064BE35
_0064BE31:
	/*0064BE31*/	mov cl,byte ptr ss:[esp+0x14]
_0064BE35:
	/*0064BE35*/	mov dl,byte ptr ss:[esp+0x10]
	/*0064BE39*/	mov al,byte ptr ss:[esp+0x18]
	/*0064BE3D*/	mov byte ptr ds:[esi+0x73],dl
	/*0064BE40*/	mov byte ptr ds:[esi+0x74],cl
	/*0064BE43*/	mov byte ptr ds:[esi+0x75],al
	/*0064BE46*/	pop esi
	/*0064BE47*/	ret 0x14
	}
}

void __declspec(naked) sub_64BE90_big_fixtures()
{
	__asm
	{
	/*0064BE90*/	push 0xFFFFFFFF
	/*0064BE92*/	push 0x95BB0E		/*push <cm0102.sub_95BB0E>*/
	/*0064BE97*/	mov eax,dword ptr fs:[0x0]
	/*0064BE9D*/	push eax
	/*0064BE9E*/	mov dword ptr fs:[0x0],esp
	/*0064BEA5*/	sub esp,0x204
	/*0064BEAB*/	push ebx
	/*0064BEAC*/	push esi
	/*0064BEAD*/	mov esi,ecx
	/*0064BEAF*/	push edi
	/*0064BEB0*/	movsx eax,word ptr ds:[esi+0x3E]
	/*0064BEB4*/	cdq
	/*0064BEB5*/	sub eax,edx
	/*0064BEB7*/	mov edi,eax
	/*0064BEB9*/	movsx eax,word ptr ds:[esi+0xA9]
	/*0064BEC0*/	sar edi,0x1
	/*0064BEC2*/	imul edi,eax
	/*0064BEC5*/	mov ecx,edi
	/*0064BEC7*/	shl ecx,0x4
	/*0064BECA*/	add ecx,0x4
	/*0064BECD*/	push ecx
	/*0064BECE*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1_operator_new>*/
	/*0064BED3*/	add esp,0x4
	/*0064BED6*/	mov dword ptr ss:[esp+0xC],eax
	/*0064BEDA*/	test eax,eax
	/*0064BEDC*/	mov dword ptr ss:[esp+0x218],0x0
	/*0064BEE7*/	je _0064BF05
	/*0064BEE9*/	push 0x5A53C0		/*push <cm0102.sub_5A53C0>*/
	/*0064BEEE*/	push 0x645800		/*push <cm0102.sub_645800>*/
	/*0064BEF3*/	lea ebx,dword ptr ds:[eax+0x4]
	/*0064BEF6*/	push edi
	/*0064BEF7*/	push 0x10
	/*0064BEF9*/	push ebx
	/*0064BEFA*/	mov dword ptr ds:[eax],edi
	/*0064BEFC*/	call sub_9463AF		/*call <cm0102.sub_9463AF>*/
	/*0064BF01*/	mov ecx,ebx
	/*0064BF03*/	jmp _0064BF07
_0064BF05:
	/*0064BF05*/	xor ecx,ecx
_0064BF07:
	/*0064BF07*/	or edi,0xFFFFFFFF
	/*0064BF0A*/	mov dword ptr ds:[esi+0xEA],ecx
	/*0064BF10*/	test ecx,ecx
	/*0064BF12*/	mov dword ptr ss:[esp+0x218],edi
	/*0064BF19*/	jne _0064BF81
	/*0064BF1B*/	lea edx,dword ptr ss:[esp+0x10]
	/*0064BF1F*/	lea eax,dword ptr ss:[esp+0x110]
	/*0064BF26*/	push edx
	/*0064BF27*/	push eax
	/*0064BF28*/	push ecx
	/*0064BF29*/	push ecx
	/*0064BF2A*/	push 0x9EA474		/*push cm0102.9EA474*/
	/*0064BF2F*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*0064BF34*/	add esp,0x14
	/*0064BF37*/	lea ecx,dword ptr ss:[esp+0x10]
	/*0064BF3B*/	lea edx,dword ptr ss:[esp+0x110]
	/*0064BF42*/	push 0x3FD
	/*0064BF47*/	push ecx
	/*0064BF48*/	push edx
	/*0064BF49*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0064BF4E*/	push eax
	/*0064BF4F*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0064BF54*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064BF59*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F_sprintf>*/
	/*0064BF5E*/	push 0x0
	/*0064BF60*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0064BF65*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0064BF6A*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0064BF6F*/	add esp,0x24
	/*0064BF72*/	mov dword ptr ds:[0xB67A34],0x0
	/*0064BF7C*/	jmp _0064EBFA
_0064BF81:
	/*0064BF81*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064BF86*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064BF8B*/	push 0x7D1
	/*0064BF90*/	push 0x8
	/*0064BF92*/	push 0x2
	/*0064BF94*/	push esi
	/*0064BF95*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064BF9A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064BFA0*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064BFA5*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064BFAA*/	push 0x7D1
	/*0064BFAF*/	push 0x8
	/*0064BFB1*/	push 0x2
	/*0064BFB3*/	add ecx,0x10
	/*0064BFB6*/	push esi
	/*0064BFB7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064BFBC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064BFC2*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064BFC7*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064BFCC*/	push 0x7D1
	/*0064BFD1*/	push 0x8
	/*0064BFD3*/	push 0x2
	/*0064BFD5*/	add ecx,0x20
	/*0064BFD8*/	push esi
	/*0064BFD9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064BFDE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064BFE4*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064BFE9*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064BFEE*/	push 0x7D1
	/*0064BFF3*/	push 0x8
	/*0064BFF5*/	push 0x2
	/*0064BFF7*/	add ecx,0x30
	/*0064BFFA*/	push esi
	/*0064BFFB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C000*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C006*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C00B*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C010*/	push 0x7D1
	/*0064C015*/	push 0x8
	/*0064C017*/	push 0x2
	/*0064C019*/	add ecx,0x40
	/*0064C01C*/	push esi
	/*0064C01D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C022*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C028*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C02D*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C032*/	push 0x7D1
	/*0064C037*/	push 0x8
	/*0064C039*/	push 0x2
	/*0064C03B*/	add ecx,0x50
	/*0064C03E*/	push esi
	/*0064C03F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C044*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C04A*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C04F*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C054*/	push 0x7D1
	/*0064C059*/	push 0x8
	/*0064C05B*/	push 0x2
	/*0064C05D*/	add ecx,0x60
	/*0064C060*/	push esi
	/*0064C061*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C066*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C06C*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C071*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C076*/	push 0x7D1
	/*0064C07B*/	push 0x8
	/*0064C07D*/	push 0x2
	/*0064C07F*/	add ecx,0x70
	/*0064C082*/	push esi
	/*0064C083*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C088*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C08E*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C093*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C098*/	push 0x7D1
	/*0064C09D*/	push 0x8
	/*0064C09F*/	push 0x2
	/*0064C0A1*/	add ecx,0x80
	/*0064C0A7*/	push esi
	/*0064C0A8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C0AD*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C0B3*/	add ecx,0x90
	/*0064C0B9*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C0BE*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064C0C3*/	push 0x7D1
	/*0064C0C8*/	push 0x8
	/*0064C0CA*/	push 0x9
	/*0064C0CC*/	push esi
	/*0064C0CD*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C0D2*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C0D8*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C0DD*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064C0E2*/	push 0x7D1
	/*0064C0E7*/	push 0x8
	/*0064C0E9*/	push 0x9
	/*0064C0EB*/	add ecx,0xA0
	/*0064C0F1*/	push esi
	/*0064C0F2*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C0F7*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C0FD*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C102*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064C107*/	push 0x7D1
	/*0064C10C*/	push 0x8
	/*0064C10E*/	push 0x9
	/*0064C110*/	add ecx,0xB0
	/*0064C116*/	push esi
	/*0064C117*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C11C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C122*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C127*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064C12C*/	push 0x7D1
	/*0064C131*/	push 0x8
	/*0064C133*/	push 0x9
	/*0064C135*/	add ecx,0xC0
	/*0064C13B*/	push esi
	/*0064C13C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C141*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C147*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064C14C*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C151*/	push 0x7D1
	/*0064C156*/	push 0x8
	/*0064C158*/	push 0x9
	/*0064C15A*/	add ecx,0xD0
	/*0064C160*/	push esi
	/*0064C161*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C166*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C16C*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C171*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C176*/	push 0x7D1
	/*0064C17B*/	push 0x8
	/*0064C17D*/	push 0x9
	/*0064C17F*/	add ecx,0xE0
	/*0064C185*/	push esi
	/*0064C186*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C18B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C191*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C196*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C19B*/	push 0x7D1
	/*0064C1A0*/	push 0x8
	/*0064C1A2*/	push 0x9
	/*0064C1A4*/	add ecx,0xF0
	/*0064C1AA*/	push esi
	/*0064C1AB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C1B0*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C1B6*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C1BB*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C1C0*/	push 0x7D1
	/*0064C1C5*/	push 0x8
	/*0064C1C7*/	push 0x9
	/*0064C1C9*/	add ecx,0x100
	/*0064C1CF*/	push esi
	/*0064C1D0*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C1D5*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C1DB*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C1E0*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C1E5*/	push 0x7D1
	/*0064C1EA*/	push 0x8
	/*0064C1EC*/	push 0x9
	/*0064C1EE*/	add ecx,0x110
	/*0064C1F4*/	push esi
	/*0064C1F5*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C1FA*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C200*/	add ecx,0x120
	/*0064C206*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C20B*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C210*/	push 0x7D1
	/*0064C215*/	push 0x8
	/*0064C217*/	push 0x10
	/*0064C219*/	push esi
	/*0064C21A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C21F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C225*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C22A*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C22F*/	push 0x7D1
	/*0064C234*/	push 0x8
	/*0064C236*/	push 0x10
	/*0064C238*/	add ecx,0x130
	/*0064C23E*/	push esi
	/*0064C23F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C244*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C24A*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064C24F*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064C254*/	push 0x7D1
	/*0064C259*/	push 0x8
	/*0064C25B*/	push 0x10
	/*0064C25D*/	add ecx,0x140
	/*0064C263*/	push esi
	/*0064C264*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C269*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C26F*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C274*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064C279*/	push 0x7D1
	/*0064C27E*/	push 0x8
	/*0064C280*/	push 0x10
	/*0064C282*/	add ecx,0x150
	/*0064C288*/	push esi
	/*0064C289*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C28E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C294*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C299*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C29E*/	push 0x7D1
	/*0064C2A3*/	push 0x8
	/*0064C2A5*/	push 0x10
	/*0064C2A7*/	add ecx,0x160
	/*0064C2AD*/	push esi
	/*0064C2AE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C2B3*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C2B9*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C2BE*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064C2C3*/	push 0x7D1
	/*0064C2C8*/	push 0x8
	/*0064C2CA*/	push 0x10
	/*0064C2CC*/	add ecx,0x170
	/*0064C2D2*/	push esi
	/*0064C2D3*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C2D8*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C2DE*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C2E3*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C2E8*/	push 0x7D1
	/*0064C2ED*/	push 0x8
	/*0064C2EF*/	push 0x10
	/*0064C2F1*/	add ecx,0x180
	/*0064C2F7*/	push esi
	/*0064C2F8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C2FD*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C303*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064C308*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C30D*/	push 0x7D1
	/*0064C312*/	push 0x8
	/*0064C314*/	push 0x10
	/*0064C316*/	add ecx,0x190
	/*0064C31C*/	push esi
	/*0064C31D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C322*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C328*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C32D*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C332*/	push 0x7D1
	/*0064C337*/	push 0x8
	/*0064C339*/	push 0x10
	/*0064C33B*/	add ecx,0x1A0
	/*0064C341*/	push esi
	/*0064C342*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C347*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C34D*/	add ecx,0x1B0
	/*0064C353*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C358*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064C35D*/	push 0x7D1
	/*0064C362*/	push 0x8
	/*0064C364*/	push 0x17
	/*0064C366*/	push esi
	/*0064C367*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C36C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C372*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C377*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064C37C*/	push 0x7D1
	/*0064C381*/	push 0x8
	/*0064C383*/	push 0x17
	/*0064C385*/	add ecx,0x1C0
	/*0064C38B*/	push esi
	/*0064C38C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C391*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C397*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064C39C*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C3A1*/	push 0x7D1
	/*0064C3A6*/	push 0x8
	/*0064C3A8*/	push 0x17
	/*0064C3AA*/	add ecx,0x1D0
	/*0064C3B0*/	push esi
	/*0064C3B1*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C3B6*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C3BC*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C3C1*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C3C6*/	push 0x7D1
	/*0064C3CB*/	push 0x8
	/*0064C3CD*/	push 0x17
	/*0064C3CF*/	add ecx,0x1E0
	/*0064C3D5*/	push esi
	/*0064C3D6*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C3DB*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C3E1*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C3E6*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C3EB*/	push 0x7D1
	/*0064C3F0*/	push 0x8
	/*0064C3F2*/	push 0x17
	/*0064C3F4*/	add ecx,0x1F0
	/*0064C3FA*/	push esi
	/*0064C3FB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C400*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C406*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C40B*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C410*/	push 0x7D1
	/*0064C415*/	push 0x8
	/*0064C417*/	push 0x17
	/*0064C419*/	add ecx,0x200
	/*0064C41F*/	push esi
	/*0064C420*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C425*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C42B*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C430*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C435*/	push 0x7D1
	/*0064C43A*/	push 0x8
	/*0064C43C*/	push 0x17
	/*0064C43E*/	add ecx,0x210
	/*0064C444*/	push esi
	/*0064C445*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C44A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C450*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064C455*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C45A*/	push 0x7D1
	/*0064C45F*/	push 0x8
	/*0064C461*/	push 0x17
	/*0064C463*/	add ecx,0x220
	/*0064C469*/	push esi
	/*0064C46A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C46F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C475*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064C47A*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C47F*/	push 0x7D1
	/*0064C484*/	push 0x8
	/*0064C486*/	push 0x17
	/*0064C488*/	add ecx,0x230
	/*0064C48E*/	push esi
	/*0064C48F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C494*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C49A*/	add ecx,0x240
	/*0064C4A0*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C4A5*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C4AA*/	push 0x7D1
	/*0064C4AF*/	push 0x8
	/*0064C4B1*/	push 0x1E
	/*0064C4B3*/	push esi
	/*0064C4B4*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C4B9*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C4BF*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C4C4*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C4C9*/	push 0x7D1
	/*0064C4CE*/	push 0x8
	/*0064C4D0*/	push 0x1E
	/*0064C4D2*/	add ecx,0x250
	/*0064C4D8*/	push esi
	/*0064C4D9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C4DE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C4E4*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C4E9*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064C4EE*/	push 0x7D1
	/*0064C4F3*/	push 0x8
	/*0064C4F5*/	push 0x1E
	/*0064C4F7*/	add ecx,0x260
	/*0064C4FD*/	push esi
	/*0064C4FE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C503*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C509*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064C50E*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064C513*/	push 0x7D1
	/*0064C518*/	push 0x8
	/*0064C51A*/	push 0x1E
	/*0064C51C*/	add ecx,0x270
	/*0064C522*/	push esi
	/*0064C523*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C528*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C52E*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C533*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C538*/	push 0x7D1
	/*0064C53D*/	push 0x8
	/*0064C53F*/	push 0x1E
	/*0064C541*/	add ecx,0x280
	/*0064C547*/	push esi
	/*0064C548*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C54D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C553*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C558*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064C55D*/	push 0x7D1
	/*0064C562*/	push 0x8
	/*0064C564*/	push 0x1E
	/*0064C566*/	add ecx,0x290
	/*0064C56C*/	push esi
	/*0064C56D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C572*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C578*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C57D*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C582*/	push 0x7D1
	/*0064C587*/	push 0x8
	/*0064C589*/	push 0x1E
	/*0064C58B*/	add ecx,0x2A0
	/*0064C591*/	push esi
	/*0064C592*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C597*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C59D*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C5A2*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C5A7*/	push 0x7D1
	/*0064C5AC*/	push 0x8
	/*0064C5AE*/	push 0x1E
	/*0064C5B0*/	add ecx,0x2B0
	/*0064C5B6*/	push esi
	/*0064C5B7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C5BC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C5C2*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064C5C7*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C5CC*/	push 0x7D1
	/*0064C5D1*/	push 0x8
	/*0064C5D3*/	push 0x1E
	/*0064C5D5*/	add ecx,0x2C0
	/*0064C5DB*/	push esi
	/*0064C5DC*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C5E1*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C5E7*/	add ecx,0x2D0
	/*0064C5ED*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C5F2*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C5F7*/	push 0x7D1
	/*0064C5FC*/	push 0x9
	/*0064C5FE*/	push 0x7
	/*0064C600*/	push esi
	/*0064C601*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C606*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C60C*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064C611*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C616*/	push 0x7D1
	/*0064C61B*/	push 0x9
	/*0064C61D*/	push 0x7
	/*0064C61F*/	add ecx,0x2E0
	/*0064C625*/	push esi
	/*0064C626*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C62B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C631*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C636*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064C63B*/	push 0x7D1
	/*0064C640*/	push 0x9
	/*0064C642*/	push 0x7
	/*0064C644*/	add ecx,0x2F0
	/*0064C64A*/	push esi
	/*0064C64B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C650*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C656*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064C65B*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C660*/	push 0x7D1
	/*0064C665*/	push 0x9
	/*0064C667*/	push 0x7
	/*0064C669*/	add ecx,0x300
	/*0064C66F*/	push esi
	/*0064C670*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C675*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C67B*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C680*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C685*/	push 0x7D1
	/*0064C68A*/	push 0x9
	/*0064C68C*/	push 0x7
	/*0064C68E*/	add ecx,0x310
	/*0064C694*/	push esi
	/*0064C695*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C69A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C6A0*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C6A5*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C6AA*/	push 0x7D1
	/*0064C6AF*/	push 0x9
	/*0064C6B1*/	push 0x7
	/*0064C6B3*/	add ecx,0x320
	/*0064C6B9*/	push esi
	/*0064C6BA*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C6BF*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C6C5*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064C6CA*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C6CF*/	push 0x7D1
	/*0064C6D4*/	push 0x9
	/*0064C6D6*/	push 0x7
	/*0064C6D8*/	add ecx,0x330
	/*0064C6DE*/	push esi
	/*0064C6DF*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C6E4*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C6EA*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064C6EF*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C6F4*/	push 0x7D1
	/*0064C6F9*/	push 0x9
	/*0064C6FB*/	push 0x7
	/*0064C6FD*/	add ecx,0x340
	/*0064C703*/	push esi
	/*0064C704*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C709*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C70F*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C714*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C719*/	push 0x7D1
	/*0064C71E*/	push 0x9
	/*0064C720*/	push 0x7
	/*0064C722*/	add ecx,0x350
	/*0064C728*/	push esi
	/*0064C729*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C72E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C734*/	add ecx,0x360
	/*0064C73A*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C73F*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C744*/	push 0x7D1
	/*0064C749*/	push 0x9
	/*0064C74B*/	push 0xE
	/*0064C74D*/	push esi
	/*0064C74E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C753*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C759*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C75E*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064C763*/	push 0x7D1
	/*0064C768*/	push 0x9
	/*0064C76A*/	push 0xE
	/*0064C76C*/	add ecx,0x370
	/*0064C772*/	push esi
	/*0064C773*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C778*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C77E*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C783*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064C788*/	push 0x7D1
	/*0064C78D*/	push 0x9
	/*0064C78F*/	push 0xE
	/*0064C791*/	add ecx,0x380
	/*0064C797*/	push esi
	/*0064C798*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C79D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C7A3*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C7A8*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C7AD*/	push 0x7D1
	/*0064C7B2*/	push 0x9
	/*0064C7B4*/	push 0xE
	/*0064C7B6*/	add ecx,0x390
	/*0064C7BC*/	push esi
	/*0064C7BD*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C7C2*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C7C8*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C7CD*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064C7D2*/	push 0x7D1
	/*0064C7D7*/	push 0x9
	/*0064C7D9*/	push 0xE
	/*0064C7DB*/	add ecx,0x3A0
	/*0064C7E1*/	push esi
	/*0064C7E2*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C7E7*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C7ED*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C7F2*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064C7F7*/	push 0x7D1
	/*0064C7FC*/	push 0x9
	/*0064C7FE*/	push 0xE
	/*0064C800*/	add ecx,0x3B0
	/*0064C806*/	push esi
	/*0064C807*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C80C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C812*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C817*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C81C*/	push 0x7D1
	/*0064C821*/	push 0x9
	/*0064C823*/	push 0xE
	/*0064C825*/	add ecx,0x3C0
	/*0064C82B*/	push esi
	/*0064C82C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C831*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C837*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C83C*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C841*/	push 0x7D1
	/*0064C846*/	push 0x9
	/*0064C848*/	push 0xE
	/*0064C84A*/	add ecx,0x3D0
	/*0064C850*/	push esi
	/*0064C851*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C856*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C85C*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064C861*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C866*/	push 0x7D1
	/*0064C86B*/	push 0x9
	/*0064C86D*/	push 0xE
	/*0064C86F*/	add ecx,0x3E0
	/*0064C875*/	push esi
	/*0064C876*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C87B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C881*/	add ecx,0x3F0
	/*0064C887*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064C88C*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C891*/	push 0x7D1
	/*0064C896*/	push 0x9
	/*0064C898*/	push 0x15
	/*0064C89A*/	push esi
	/*0064C89B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C8A0*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C8A6*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C8AB*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064C8B0*/	push 0x7D1
	/*0064C8B5*/	push 0x9
	/*0064C8B7*/	push 0x15
	/*0064C8B9*/	add ecx,0x400
	/*0064C8BF*/	push esi
	/*0064C8C0*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C8C5*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C8CB*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064C8D0*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064C8D5*/	push 0x7D1
	/*0064C8DA*/	push 0x9
	/*0064C8DC*/	push 0x15
	/*0064C8DE*/	add ecx,0x410
	/*0064C8E4*/	push esi
	/*0064C8E5*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C8EA*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C8F0*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C8F5*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064C8FA*/	push 0x7D1
	/*0064C8FF*/	push 0x9
	/*0064C901*/	push 0x15
	/*0064C903*/	add ecx,0x420
	/*0064C909*/	push esi
	/*0064C90A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C90F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C915*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064C91A*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064C91F*/	push 0x7D1
	/*0064C924*/	push 0x9
	/*0064C926*/	push 0x15
	/*0064C928*/	add ecx,0x430
	/*0064C92E*/	push esi
	/*0064C92F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C934*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C93A*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064C93F*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064C944*/	push 0x7D1
	/*0064C949*/	push 0x9
	/*0064C94B*/	push 0x15
	/*0064C94D*/	add ecx,0x440
	/*0064C953*/	push esi
	/*0064C954*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C959*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C95F*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064C964*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C969*/	push 0x7D1
	/*0064C96E*/	push 0x9
	/*0064C970*/	push 0x15
	/*0064C972*/	add ecx,0x450
	/*0064C978*/	push esi
	/*0064C979*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C97E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C984*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064C989*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064C98E*/	push 0x7D1
	/*0064C993*/	push 0x9
	/*0064C995*/	push 0x15
	/*0064C997*/	add ecx,0x460
	/*0064C99D*/	push esi
	/*0064C99E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C9A3*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C9A9*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064C9AE*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064C9B3*/	push 0x7D1
	/*0064C9B8*/	push 0x9
	/*0064C9BA*/	push 0x15
	/*0064C9BC*/	add ecx,0x470
	/*0064C9C2*/	push esi
	/*0064C9C3*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C9C8*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C9CE*/	add ecx,0x480
	/*0064C9D4*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064C9D9*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064C9DE*/	push 0x7D1
	/*0064C9E3*/	push 0x9
	/*0064C9E5*/	push 0x1C
	/*0064C9E7*/	push esi
	/*0064C9E8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064C9ED*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064C9F3*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064C9F8*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064C9FD*/	push 0x7D1
	/*0064CA02*/	push 0x9
	/*0064CA04*/	push 0x1C
	/*0064CA06*/	add ecx,0x490
	/*0064CA0C*/	push esi
	/*0064CA0D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CA12*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CA18*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064CA1D*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064CA22*/	push 0x7D1
	/*0064CA27*/	push 0x9
	/*0064CA29*/	push 0x1C
	/*0064CA2B*/	add ecx,0x4A0
	/*0064CA31*/	push esi
	/*0064CA32*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CA37*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CA3D*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064CA42*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064CA47*/	push 0x7D1
	/*0064CA4C*/	push 0x9
	/*0064CA4E*/	push 0x1C
	/*0064CA50*/	add ecx,0x4B0
	/*0064CA56*/	push esi
	/*0064CA57*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CA5C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CA62*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064CA67*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064CA6C*/	push 0x7D1
	/*0064CA71*/	push 0x9
	/*0064CA73*/	push 0x1C
	/*0064CA75*/	add ecx,0x4C0
	/*0064CA7B*/	push esi
	/*0064CA7C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CA81*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CA87*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064CA8C*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064CA91*/	push 0x7D1
	/*0064CA96*/	push 0x9
	/*0064CA98*/	push 0x1C
	/*0064CA9A*/	add ecx,0x4D0
	/*0064CAA0*/	push esi
	/*0064CAA1*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CAA6*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CAAC*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064CAB1*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064CAB6*/	push 0x7D1
	/*0064CABB*/	push 0x9
	/*0064CABD*/	push 0x1C
	/*0064CABF*/	add ecx,0x4E0
	/*0064CAC5*/	push esi
	/*0064CAC6*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CACB*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CAD1*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064CAD6*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064CADB*/	push 0x7D1
	/*0064CAE0*/	push 0x9
	/*0064CAE2*/	push 0x1C
	/*0064CAE4*/	add ecx,0x4F0
	/*0064CAEA*/	push esi
	/*0064CAEB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CAF0*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CAF6*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064CAFB*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064CB00*/	push 0x7D1
	/*0064CB05*/	push 0x9
	/*0064CB07*/	push 0x1C
	/*0064CB09*/	add ecx,0x500
	/*0064CB0F*/	push esi
	/*0064CB10*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CB15*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CB1B*/	add ecx,0x510
	/*0064CB21*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064CB26*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064CB2B*/	push 0x7D1
	/*0064CB30*/	push 0xA
	/*0064CB32*/	push 0x4
	/*0064CB34*/	push esi
	/*0064CB35*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CB3A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CB40*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064CB45*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064CB4A*/	push 0x7D1
	/*0064CB4F*/	push 0xA
	/*0064CB51*/	push 0x4
	/*0064CB53*/	add ecx,0x520
	/*0064CB59*/	push esi
	/*0064CB5A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CB5F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CB65*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064CB6A*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064CB6F*/	push 0x7D1
	/*0064CB74*/	push 0xA
	/*0064CB76*/	push 0x4
	/*0064CB78*/	add ecx,0x530
	/*0064CB7E*/	push esi
	/*0064CB7F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CB84*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CB8A*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064CB8F*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064CB94*/	push 0x7D1
	/*0064CB99*/	push 0xA
	/*0064CB9B*/	push 0x4
	/*0064CB9D*/	add ecx,0x540
	/*0064CBA3*/	push esi
	/*0064CBA4*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CBA9*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CBAF*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064CBB4*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064CBB9*/	push 0x7D1
	/*0064CBBE*/	push 0xA
	/*0064CBC0*/	push 0x4
	/*0064CBC2*/	add ecx,0x550
	/*0064CBC8*/	push esi
	/*0064CBC9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CBCE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CBD4*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064CBD9*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064CBDE*/	push 0x7D1
	/*0064CBE3*/	push 0xA
	/*0064CBE5*/	push 0x4
	/*0064CBE7*/	add ecx,0x560
	/*0064CBED*/	push esi
	/*0064CBEE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CBF3*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CBF9*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064CBFE*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064CC03*/	push 0x7D1
	/*0064CC08*/	push 0xA
	/*0064CC0A*/	push 0x4
	/*0064CC0C*/	add ecx,0x570
	/*0064CC12*/	push esi
	/*0064CC13*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CC18*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CC1E*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064CC23*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064CC28*/	push 0x7D1
	/*0064CC2D*/	push 0xA
	/*0064CC2F*/	push 0x4
	/*0064CC31*/	add ecx,0x580
	/*0064CC37*/	push esi
	/*0064CC38*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CC3D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CC43*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064CC48*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064CC4D*/	push 0x7D1
	/*0064CC52*/	push 0xA
	/*0064CC54*/	push 0x4
	/*0064CC56*/	add ecx,0x590
	/*0064CC5C*/	push esi
	/*0064CC5D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CC62*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CC68*/	add ecx,0x5A0
	/*0064CC6E*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064CC73*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064CC78*/	push 0x7D1
	/*0064CC7D*/	push 0xA
	/*0064CC7F*/	push 0xB
	/*0064CC81*/	push esi
	/*0064CC82*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CC87*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CC8D*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064CC92*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064CC97*/	push 0x7D1
	/*0064CC9C*/	push 0xA
	/*0064CC9E*/	push 0xB
	/*0064CCA0*/	add ecx,0x5B0
	/*0064CCA6*/	push esi
	/*0064CCA7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CCAC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CCB2*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064CCB7*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064CCBC*/	push 0x7D1
	/*0064CCC1*/	push 0xA
	/*0064CCC3*/	push 0xB
	/*0064CCC5*/	add ecx,0x5C0
	/*0064CCCB*/	push esi
	/*0064CCCC*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CCD1*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CCD7*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064CCDC*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064CCE1*/	push 0x7D1
	/*0064CCE6*/	push 0xA
	/*0064CCE8*/	push 0xB
	/*0064CCEA*/	add ecx,0x5D0
	/*0064CCF0*/	push esi
	/*0064CCF1*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CCF6*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CCFC*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064CD01*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064CD06*/	push 0x7D1
	/*0064CD0B*/	push 0xA
	/*0064CD0D*/	push 0xB
	/*0064CD0F*/	add ecx,0x5E0
	/*0064CD15*/	push esi
	/*0064CD16*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CD1B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CD21*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064CD26*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064CD2B*/	push 0x7D1
	/*0064CD30*/	push 0xA
	/*0064CD32*/	push 0xB
	/*0064CD34*/	add ecx,0x5F0
	/*0064CD3A*/	push esi
	/*0064CD3B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CD40*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CD46*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064CD4B*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064CD50*/	push 0x7D1
	/*0064CD55*/	push 0xA
	/*0064CD57*/	push 0xB
	/*0064CD59*/	add ecx,0x600
	/*0064CD5F*/	push esi
	/*0064CD60*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CD65*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CD6B*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064CD70*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064CD75*/	push 0x7D1
	/*0064CD7A*/	push 0xA
	/*0064CD7C*/	push 0xB
	/*0064CD7E*/	add ecx,0x610
	/*0064CD84*/	push esi
	/*0064CD85*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CD8A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CD90*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064CD95*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064CD9A*/	push 0x7D1
	/*0064CD9F*/	push 0xA
	/*0064CDA1*/	push 0xB
	/*0064CDA3*/	add ecx,0x620
	/*0064CDA9*/	push esi
	/*0064CDAA*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CDAF*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CDB5*/	add ecx,0x630
	/*0064CDBB*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064CDC0*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064CDC5*/	push 0x7D1
	/*0064CDCA*/	push 0xA
	/*0064CDCC*/	push 0x12
	/*0064CDCE*/	push esi
	/*0064CDCF*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CDD4*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CDDA*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064CDDF*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064CDE4*/	push 0x7D1
	/*0064CDE9*/	push 0xA
	/*0064CDEB*/	push 0x12
	/*0064CDED*/	add ecx,0x640
	/*0064CDF3*/	push esi
	/*0064CDF4*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CDF9*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CDFF*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064CE04*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064CE09*/	push 0x7D1
	/*0064CE0E*/	push 0xA
	/*0064CE10*/	push 0x12
	/*0064CE12*/	add ecx,0x650
	/*0064CE18*/	push esi
	/*0064CE19*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CE1E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CE24*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064CE29*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064CE2E*/	push 0x7D1
	/*0064CE33*/	push 0xA
	/*0064CE35*/	push 0x12
	/*0064CE37*/	add ecx,0x660
	/*0064CE3D*/	push esi
	/*0064CE3E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CE43*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CE49*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064CE4E*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064CE53*/	push 0x7D1
	/*0064CE58*/	push 0xA
	/*0064CE5A*/	push 0x12
	/*0064CE5C*/	add ecx,0x670
	/*0064CE62*/	push esi
	/*0064CE63*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CE68*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CE6E*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064CE73*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064CE78*/	push 0x7D1
	/*0064CE7D*/	push 0xA
	/*0064CE7F*/	push 0x12
	/*0064CE81*/	add ecx,0x680
	/*0064CE87*/	push esi
	/*0064CE88*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CE8D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CE93*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064CE98*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064CE9D*/	push 0x7D1
	/*0064CEA2*/	push 0xA
	/*0064CEA4*/	push 0x12
	/*0064CEA6*/	add ecx,0x690
	/*0064CEAC*/	push esi
	/*0064CEAD*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CEB2*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CEB8*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064CEBD*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064CEC2*/	push 0x7D1
	/*0064CEC7*/	push 0xA
	/*0064CEC9*/	push 0x12
	/*0064CECB*/	add ecx,0x6A0
	/*0064CED1*/	push esi
	/*0064CED2*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CED7*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CEDD*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064CEE2*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064CEE7*/	push 0x7D1
	/*0064CEEC*/	push 0xA
	/*0064CEEE*/	push 0x12
	/*0064CEF0*/	add ecx,0x6B0
	/*0064CEF6*/	push esi
	/*0064CEF7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CEFC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CF02*/	add ecx,0x6C0
	/*0064CF08*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064CF0D*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064CF12*/	push 0x7D1
	/*0064CF17*/	push 0xA
	/*0064CF19*/	push 0x19
	/*0064CF1B*/	push esi
	/*0064CF1C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CF21*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CF27*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064CF2C*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064CF31*/	push 0x7D1
	/*0064CF36*/	push 0xA
	/*0064CF38*/	push 0x19
	/*0064CF3A*/	add ecx,0x6D0
	/*0064CF40*/	push esi
	/*0064CF41*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CF46*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CF4C*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064CF51*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064CF56*/	push 0x7D1
	/*0064CF5B*/	push 0xA
	/*0064CF5D*/	push 0x19
	/*0064CF5F*/	add ecx,0x6E0
	/*0064CF65*/	push esi
	/*0064CF66*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CF6B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CF71*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064CF76*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064CF7B*/	push 0x7D1
	/*0064CF80*/	push 0xA
	/*0064CF82*/	push 0x19
	/*0064CF84*/	add ecx,0x6F0
	/*0064CF8A*/	push esi
	/*0064CF8B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CF90*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CF96*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064CF9B*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064CFA0*/	push 0x7D1
	/*0064CFA5*/	push 0xA
	/*0064CFA7*/	push 0x19
	/*0064CFA9*/	add ecx,0x700
	/*0064CFAF*/	push esi
	/*0064CFB0*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CFB5*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CFBB*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064CFC0*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064CFC5*/	push 0x7D1
	/*0064CFCA*/	push 0xA
	/*0064CFCC*/	push 0x19
	/*0064CFCE*/	add ecx,0x710
	/*0064CFD4*/	push esi
	/*0064CFD5*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CFDA*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064CFE0*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064CFE5*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064CFEA*/	push 0x7D1
	/*0064CFEF*/	push 0xA
	/*0064CFF1*/	push 0x19
	/*0064CFF3*/	add ecx,0x720
	/*0064CFF9*/	push esi
	/*0064CFFA*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064CFFF*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D005*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D00A*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D00F*/	push 0x7D1
	/*0064D014*/	push 0xA
	/*0064D016*/	push 0x19
	/*0064D018*/	add ecx,0x730
	/*0064D01E*/	push esi
	/*0064D01F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D024*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D02A*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D02F*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D034*/	push 0x7D1
	/*0064D039*/	push 0xA
	/*0064D03B*/	push 0x19
	/*0064D03D*/	add ecx,0x740
	/*0064D043*/	push esi
	/*0064D044*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D049*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D04F*/	add ecx,0x750
	/*0064D055*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D05A*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064D05F*/	push 0x7D1
	/*0064D064*/	push 0xB
	/*0064D066*/	push 0x2
	/*0064D068*/	push esi
	/*0064D069*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D06E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D074*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064D079*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D07E*/	push 0x7D1
	/*0064D083*/	push 0xB
	/*0064D085*/	push 0x2
	/*0064D087*/	add ecx,0x760
	/*0064D08D*/	push esi
	/*0064D08E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D093*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D099*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064D09E*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D0A3*/	push 0x7D1
	/*0064D0A8*/	push 0xB
	/*0064D0AA*/	push 0x2
	/*0064D0AC*/	add ecx,0x770
	/*0064D0B2*/	push esi
	/*0064D0B3*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D0B8*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D0BE*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D0C3*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D0C8*/	push 0x7D1
	/*0064D0CD*/	push 0xB
	/*0064D0CF*/	push 0x2
	/*0064D0D1*/	add ecx,0x780
	/*0064D0D7*/	push esi
	/*0064D0D8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D0DD*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D0E3*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D0E8*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D0ED*/	push 0x7D1
	/*0064D0F2*/	push 0xB
	/*0064D0F4*/	push 0x2
	/*0064D0F6*/	add ecx,0x790
	/*0064D0FC*/	push esi
	/*0064D0FD*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D102*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D108*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D10D*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064D112*/	push 0x7D1
	/*0064D117*/	push 0xB
	/*0064D119*/	push 0x2
	/*0064D11B*/	add ecx,0x7A0
	/*0064D121*/	push esi
	/*0064D122*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D127*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D12D*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064D132*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064D137*/	push 0x7D1
	/*0064D13C*/	push 0xB
	/*0064D13E*/	push 0x2
	/*0064D140*/	add ecx,0x7B0
	/*0064D146*/	push esi
	/*0064D147*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D14C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D152*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D157*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D15C*/	push 0x7D1
	/*0064D161*/	push 0xB
	/*0064D163*/	push 0x2
	/*0064D165*/	add ecx,0x7C0
	/*0064D16B*/	push esi
	/*0064D16C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D171*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D177*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064D17C*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D181*/	push 0x7D1
	/*0064D186*/	push 0xB
	/*0064D188*/	push 0x2
	/*0064D18A*/	add ecx,0x7D0
	/*0064D190*/	push esi
	/*0064D191*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D196*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D19C*/	add ecx,0x7E0
	/*0064D1A2*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D1A7*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064D1AC*/	push 0x7D1
	/*0064D1B1*/	push 0xB
	/*0064D1B3*/	push 0x9
	/*0064D1B5*/	push esi
	/*0064D1B6*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D1BB*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D1C1*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064D1C6*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064D1CB*/	push 0x7D1
	/*0064D1D0*/	push 0xB
	/*0064D1D2*/	push 0x9
	/*0064D1D4*/	add ecx,0x7F0
	/*0064D1DA*/	push esi
	/*0064D1DB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D1E0*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D1E6*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D1EB*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D1F0*/	push 0x7D1
	/*0064D1F5*/	push 0xB
	/*0064D1F7*/	push 0x9
	/*0064D1F9*/	add ecx,0x800
	/*0064D1FF*/	push esi
	/*0064D200*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D205*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D20B*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D210*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064D215*/	push 0x7D1
	/*0064D21A*/	push 0xB
	/*0064D21C*/	push 0x9
	/*0064D21E*/	add ecx,0x810
	/*0064D224*/	push esi
	/*0064D225*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D22A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D230*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D235*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D23A*/	push 0x7D1
	/*0064D23F*/	push 0xB
	/*0064D241*/	push 0x9
	/*0064D243*/	add ecx,0x820
	/*0064D249*/	push esi
	/*0064D24A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D24F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D255*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D25A*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D25F*/	push 0x7D1
	/*0064D264*/	push 0xB
	/*0064D266*/	push 0x9
	/*0064D268*/	add ecx,0x830
	/*0064D26E*/	push esi
	/*0064D26F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D274*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D27A*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D27F*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064D284*/	push 0x7D1
	/*0064D289*/	push 0xB
	/*0064D28B*/	push 0x9
	/*0064D28D*/	add ecx,0x840
	/*0064D293*/	push esi
	/*0064D294*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D299*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D29F*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064D2A4*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D2A9*/	push 0x7D1
	/*0064D2AE*/	push 0xB
	/*0064D2B0*/	push 0x9
	/*0064D2B2*/	add ecx,0x850
	/*0064D2B8*/	push esi
	/*0064D2B9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D2BE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D2C4*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064D2C9*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D2CE*/	push 0x7D1
	/*0064D2D3*/	push 0xB
	/*0064D2D5*/	push 0x9
	/*0064D2D7*/	add ecx,0x860
	/*0064D2DD*/	push esi
	/*0064D2DE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D2E3*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D2E9*/	add ecx,0x870
	/*0064D2EF*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D2F4*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064D2F9*/	push 0x7D1
	/*0064D2FE*/	push 0xB
	/*0064D300*/	push 0x10
	/*0064D302*/	push esi
	/*0064D303*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D308*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D30E*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064D313*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D318*/	push 0x7D1
	/*0064D31D*/	push 0xB
	/*0064D31F*/	push 0x10
	/*0064D321*/	add ecx,0x880
	/*0064D327*/	push esi
	/*0064D328*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D32D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D333*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D338*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D33D*/	push 0x7D1
	/*0064D342*/	push 0xB
	/*0064D344*/	push 0x10
	/*0064D346*/	add ecx,0x890
	/*0064D34C*/	push esi
	/*0064D34D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D352*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D358*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D35D*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D362*/	push 0x7D1
	/*0064D367*/	push 0xB
	/*0064D369*/	push 0x10
	/*0064D36B*/	add ecx,0x8A0
	/*0064D371*/	push esi
	/*0064D372*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D377*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D37D*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064D382*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D387*/	push 0x7D1
	/*0064D38C*/	push 0xB
	/*0064D38E*/	push 0x10
	/*0064D390*/	add ecx,0x8B0
	/*0064D396*/	push esi
	/*0064D397*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D39C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D3A2*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064D3A7*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064D3AC*/	push 0x7D1
	/*0064D3B1*/	push 0xB
	/*0064D3B3*/	push 0x10
	/*0064D3B5*/	add ecx,0x8C0
	/*0064D3BB*/	push esi
	/*0064D3BC*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D3C1*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D3C7*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D3CC*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064D3D1*/	push 0x7D1
	/*0064D3D6*/	push 0xB
	/*0064D3D8*/	push 0x10
	/*0064D3DA*/	add ecx,0x8D0
	/*0064D3E0*/	push esi
	/*0064D3E1*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D3E6*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D3EC*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064D3F1*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D3F6*/	push 0x7D1
	/*0064D3FB*/	push 0xB
	/*0064D3FD*/	push 0x10
	/*0064D3FF*/	add ecx,0x8E0
	/*0064D405*/	push esi
	/*0064D406*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D40B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D411*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D416*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D41B*/	push 0x7D1
	/*0064D420*/	push 0xB
	/*0064D422*/	push 0x10
	/*0064D424*/	add ecx,0x8F0
	/*0064D42A*/	push esi
	/*0064D42B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D430*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D436*/	add ecx,0x900
	/*0064D43C*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D441*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064D446*/	push 0x7D1
	/*0064D44B*/	push 0xB
	/*0064D44D*/	push 0x17
	/*0064D44F*/	push esi
	/*0064D450*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D455*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D45B*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D460*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064D465*/	push 0x7D1
	/*0064D46A*/	push 0xB
	/*0064D46C*/	push 0x17
	/*0064D46E*/	add ecx,0x910
	/*0064D474*/	push esi
	/*0064D475*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D47A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D480*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D485*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D48A*/	push 0x7D1
	/*0064D48F*/	push 0xB
	/*0064D491*/	push 0x17
	/*0064D493*/	add ecx,0x920
	/*0064D499*/	push esi
	/*0064D49A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D49F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D4A5*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064D4AA*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064D4AF*/	push 0x7D1
	/*0064D4B4*/	push 0xB
	/*0064D4B6*/	push 0x17
	/*0064D4B8*/	add ecx,0x930
	/*0064D4BE*/	push esi
	/*0064D4BF*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D4C4*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D4CA*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D4CF*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D4D4*/	push 0x7D1
	/*0064D4D9*/	push 0xB
	/*0064D4DB*/	push 0x17
	/*0064D4DD*/	add ecx,0x940
	/*0064D4E3*/	push esi
	/*0064D4E4*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D4E9*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D4EF*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064D4F4*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D4F9*/	push 0x7D1
	/*0064D4FE*/	push 0xB
	/*0064D500*/	push 0x17
	/*0064D502*/	add ecx,0x950
	/*0064D508*/	push esi
	/*0064D509*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D50E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D514*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064D519*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064D51E*/	push 0x7D1
	/*0064D523*/	push 0xB
	/*0064D525*/	push 0x17
	/*0064D527*/	add ecx,0x960
	/*0064D52D*/	push esi
	/*0064D52E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D533*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D539*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D53E*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D543*/	push 0x7D1
	/*0064D548*/	push 0xB
	/*0064D54A*/	push 0x17
	/*0064D54C*/	add ecx,0x970
	/*0064D552*/	push esi
	/*0064D553*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D558*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D55E*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D563*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D568*/	push 0x7D1
	/*0064D56D*/	push 0xB
	/*0064D56F*/	push 0x17
	/*0064D571*/	add ecx,0x980
	/*0064D577*/	push esi
	/*0064D578*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D57D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D583*/	add ecx,0x990
	/*0064D589*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064D58E*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D593*/	push 0x7D2
	/*0064D598*/	push 0x0
	/*0064D59A*/	push 0x6
	/*0064D59C*/	push esi
	/*0064D59D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D5A2*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D5A8*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064D5AD*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064D5B2*/	push 0x7D2
	/*0064D5B7*/	push 0x0
	/*0064D5B9*/	push 0x6
	/*0064D5BB*/	add ecx,0x9A0
	/*0064D5C1*/	push esi
	/*0064D5C2*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D5C7*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D5CD*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D5D2*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D5D7*/	push 0x7D2
	/*0064D5DC*/	push 0x0
	/*0064D5DE*/	push 0x6
	/*0064D5E0*/	add ecx,0x9B0
	/*0064D5E6*/	push esi
	/*0064D5E7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D5EC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D5F2*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064D5F7*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D5FC*/	push 0x7D2
	/*0064D601*/	push 0x0
	/*0064D603*/	push 0x6
	/*0064D605*/	add ecx,0x9C0
	/*0064D60B*/	push esi
	/*0064D60C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D611*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D617*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D61C*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D621*/	push 0x7D2
	/*0064D626*/	push 0x0
	/*0064D628*/	push 0x6
	/*0064D62A*/	add ecx,0x9D0
	/*0064D630*/	push esi
	/*0064D631*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D636*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D63C*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064D641*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D646*/	push 0x7D2
	/*0064D64B*/	push 0x0
	/*0064D64D*/	push 0x6
	/*0064D64F*/	add ecx,0x9E0
	/*0064D655*/	push esi
	/*0064D656*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D65B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D661*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D666*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064D66B*/	push 0x7D2
	/*0064D670*/	push 0x0
	/*0064D672*/	push 0x6
	/*0064D674*/	add ecx,0x9F0
	/*0064D67A*/	push esi
	/*0064D67B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D680*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D686*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064D68B*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D690*/	push 0x7D2
	/*0064D695*/	push 0x0
	/*0064D697*/	push 0x6
	/*0064D699*/	add ecx,0xA00
	/*0064D69F*/	push esi
	/*0064D6A0*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D6A5*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D6AB*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D6B0*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D6B5*/	push 0x7D2
	/*0064D6BA*/	push 0x0
	/*0064D6BC*/	push 0x6
	/*0064D6BE*/	add ecx,0xA10
	/*0064D6C4*/	push esi
	/*0064D6C5*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D6CA*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D6D0*/	add ecx,0xA20
	/*0064D6D6*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064D6DB*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D6E0*/	push 0x7D2
	/*0064D6E5*/	push 0x0
	/*0064D6E7*/	push 0xD
	/*0064D6E9*/	push esi
	/*0064D6EA*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D6EF*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D6F5*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D6FA*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D6FF*/	push 0x7D2
	/*0064D704*/	push 0x0
	/*0064D706*/	push 0xD
	/*0064D708*/	add ecx,0xA30
	/*0064D70E*/	push esi
	/*0064D70F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D714*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D71A*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D71F*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064D724*/	push 0x7D2
	/*0064D729*/	push 0x0
	/*0064D72B*/	push 0xD
	/*0064D72D*/	add ecx,0xA40
	/*0064D733*/	push esi
	/*0064D734*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D739*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D73F*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D744*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D749*/	push 0x7D2
	/*0064D74E*/	push 0x0
	/*0064D750*/	push 0xD
	/*0064D752*/	add ecx,0xA50
	/*0064D758*/	push esi
	/*0064D759*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D75E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D764*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D769*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064D76E*/	push 0x7D2
	/*0064D773*/	push 0x0
	/*0064D775*/	push 0xD
	/*0064D777*/	add ecx,0xA60
	/*0064D77D*/	push esi
	/*0064D77E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D783*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D789*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D78E*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D793*/	push 0x7D2
	/*0064D798*/	push 0x0
	/*0064D79A*/	push 0xD
	/*0064D79C*/	add ecx,0xA70
	/*0064D7A2*/	push esi
	/*0064D7A3*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D7A8*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D7AE*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064D7B3*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064D7B8*/	push 0x7D2
	/*0064D7BD*/	push 0x0
	/*0064D7BF*/	push 0xD
	/*0064D7C1*/	add ecx,0xA80
	/*0064D7C7*/	push esi
	/*0064D7C8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D7CD*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D7D3*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D7D8*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064D7DD*/	push 0x7D2
	/*0064D7E2*/	push 0x0
	/*0064D7E4*/	push 0xD
	/*0064D7E6*/	add ecx,0xA90
	/*0064D7EC*/	push esi
	/*0064D7ED*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D7F2*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D7F8*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D7FD*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064D802*/	push 0x7D2
	/*0064D807*/	push 0x0
	/*0064D809*/	push 0xD
	/*0064D80B*/	add ecx,0xAA0
	/*0064D811*/	push esi
	/*0064D812*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D817*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D81D*/	add ecx,0xAB0
	/*0064D823*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064D828*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064D82D*/	push 0x7D2
	/*0064D832*/	push 0x0
	/*0064D834*/	push 0x14
	/*0064D836*/	push esi
	/*0064D837*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D83C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D842*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064D847*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064D84C*/	push 0x7D2
	/*0064D851*/	push 0x0
	/*0064D853*/	push 0x14
	/*0064D855*/	add ecx,0xAC0
	/*0064D85B*/	push esi
	/*0064D85C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D861*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D867*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064D86C*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D871*/	push 0x7D2
	/*0064D876*/	push 0x0
	/*0064D878*/	push 0x14
	/*0064D87A*/	add ecx,0xAD0
	/*0064D880*/	push esi
	/*0064D881*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D886*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D88C*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D891*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064D896*/	push 0x7D2
	/*0064D89B*/	push 0x0
	/*0064D89D*/	push 0x14
	/*0064D89F*/	add ecx,0xAE0
	/*0064D8A5*/	push esi
	/*0064D8A6*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D8AB*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D8B1*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D8B6*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064D8BB*/	push 0x7D2
	/*0064D8C0*/	push 0x0
	/*0064D8C2*/	push 0x14
	/*0064D8C4*/	add ecx,0xAF0
	/*0064D8CA*/	push esi
	/*0064D8CB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D8D0*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D8D6*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064D8DB*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D8E0*/	push 0x7D2
	/*0064D8E5*/	push 0x0
	/*0064D8E7*/	push 0x14
	/*0064D8E9*/	add ecx,0xB00
	/*0064D8EF*/	push esi
	/*0064D8F0*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D8F5*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D8FB*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D900*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D905*/	push 0x7D2
	/*0064D90A*/	push 0x0
	/*0064D90C*/	push 0x14
	/*0064D90E*/	add ecx,0xB10
	/*0064D914*/	push esi
	/*0064D915*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D91A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D920*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D925*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D92A*/	push 0x7D2
	/*0064D92F*/	push 0x0
	/*0064D931*/	push 0x14
	/*0064D933*/	add ecx,0xB20
	/*0064D939*/	push esi
	/*0064D93A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D93F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D945*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064D94A*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064D94F*/	push 0x7D2
	/*0064D954*/	push 0x0
	/*0064D956*/	push 0x14
	/*0064D958*/	add ecx,0xB30
	/*0064D95E*/	push esi
	/*0064D95F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D964*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D96A*/	add ecx,0xB40
	/*0064D970*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064D975*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064D97A*/	push 0x7D2
	/*0064D97F*/	push 0x0
	/*0064D981*/	push 0x1B
	/*0064D983*/	push esi
	/*0064D984*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D989*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D98F*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064D994*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064D999*/	push 0x7D2
	/*0064D99E*/	push 0x0
	/*0064D9A0*/	push 0x1B
	/*0064D9A2*/	add ecx,0xB50
	/*0064D9A8*/	push esi
	/*0064D9A9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D9AE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D9B4*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064D9B9*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064D9BE*/	push 0x7D2
	/*0064D9C3*/	push 0x0
	/*0064D9C5*/	push 0x1B
	/*0064D9C7*/	add ecx,0xB60
	/*0064D9CD*/	push esi
	/*0064D9CE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D9D3*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D9D9*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064D9DE*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064D9E3*/	push 0x7D2
	/*0064D9E8*/	push 0x0
	/*0064D9EA*/	push 0x1B
	/*0064D9EC*/	add ecx,0xB70
	/*0064D9F2*/	push esi
	/*0064D9F3*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064D9F8*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064D9FE*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064DA03*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064DA08*/	push 0x7D2
	/*0064DA0D*/	push 0x0
	/*0064DA0F*/	push 0x1B
	/*0064DA11*/	add ecx,0xB80
	/*0064DA17*/	push esi
	/*0064DA18*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DA1D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DA23*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064DA28*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064DA2D*/	push 0x7D2
	/*0064DA32*/	push 0x0
	/*0064DA34*/	push 0x1B
	/*0064DA36*/	add ecx,0xB90
	/*0064DA3C*/	push esi
	/*0064DA3D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DA42*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DA48*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064DA4D*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064DA52*/	push 0x7D2
	/*0064DA57*/	push 0x0
	/*0064DA59*/	push 0x1B
	/*0064DA5B*/	add ecx,0xBA0
	/*0064DA61*/	push esi
	/*0064DA62*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DA67*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DA6D*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064DA72*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064DA77*/	push 0x7D2
	/*0064DA7C*/	push 0x0
	/*0064DA7E*/	push 0x1B
	/*0064DA80*/	add ecx,0xBB0
	/*0064DA86*/	push esi
	/*0064DA87*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DA8C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DA92*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064DA97*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064DA9C*/	push 0x7D2
	/*0064DAA1*/	push 0x0
	/*0064DAA3*/	push 0x1B
	/*0064DAA5*/	add ecx,0xBC0
	/*0064DAAB*/	push esi
	/*0064DAAC*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DAB1*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DAB7*/	add ecx,0xBD0
	/*0064DABD*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064DAC2*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064DAC7*/	push 0x7D2
	/*0064DACC*/	push 0x1
	/*0064DACE*/	push 0x3
	/*0064DAD0*/	push esi
	/*0064DAD1*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DAD6*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DADC*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064DAE1*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064DAE6*/	push 0x7D2
	/*0064DAEB*/	push 0x1
	/*0064DAED*/	push 0x3
	/*0064DAEF*/	add ecx,0xBE0
	/*0064DAF5*/	push esi
	/*0064DAF6*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DAFB*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DB01*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064DB06*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064DB0B*/	push 0x7D2
	/*0064DB10*/	push 0x1
	/*0064DB12*/	push 0x3
	/*0064DB14*/	add ecx,0xBF0
	/*0064DB1A*/	push esi
	/*0064DB1B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DB20*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DB26*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064DB2B*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064DB30*/	push 0x7D2
	/*0064DB35*/	push 0x1
	/*0064DB37*/	push 0x3
	/*0064DB39*/	add ecx,0xC00
	/*0064DB3F*/	push esi
	/*0064DB40*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DB45*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DB4B*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064DB50*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064DB55*/	push 0x7D2
	/*0064DB5A*/	push 0x1
	/*0064DB5C*/	push 0x3
	/*0064DB5E*/	add ecx,0xC10
	/*0064DB64*/	push esi
	/*0064DB65*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DB6A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DB70*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064DB75*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064DB7A*/	push 0x7D2
	/*0064DB7F*/	push 0x1
	/*0064DB81*/	push 0x3
	/*0064DB83*/	add ecx,0xC20
	/*0064DB89*/	push esi
	/*0064DB8A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DB8F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DB95*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064DB9A*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064DB9F*/	push 0x7D2
	/*0064DBA4*/	push 0x1
	/*0064DBA6*/	push 0x3
	/*0064DBA8*/	add ecx,0xC30
	/*0064DBAE*/	push esi
	/*0064DBAF*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DBB4*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DBBA*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064DBBF*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064DBC4*/	push 0x7D2
	/*0064DBC9*/	push 0x1
	/*0064DBCB*/	push 0x3
	/*0064DBCD*/	add ecx,0xC40
	/*0064DBD3*/	push esi
	/*0064DBD4*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DBD9*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DBDF*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064DBE4*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064DBE9*/	push 0x7D2
	/*0064DBEE*/	push 0x1
	/*0064DBF0*/	push 0x3
	/*0064DBF2*/	add ecx,0xC50
	/*0064DBF8*/	push esi
	/*0064DBF9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DBFE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DC04*/	add ecx,0xC60
	/*0064DC0A*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064DC0F*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064DC14*/	push 0x7D2
	/*0064DC19*/	push 0x1
	/*0064DC1B*/	push 0xA
	/*0064DC1D*/	push esi
	/*0064DC1E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DC23*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DC29*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064DC2E*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064DC33*/	push 0x7D2
	/*0064DC38*/	push 0x1
	/*0064DC3A*/	push 0xA
	/*0064DC3C*/	add ecx,0xC70
	/*0064DC42*/	push esi
	/*0064DC43*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DC48*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DC4E*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064DC53*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064DC58*/	push 0x7D2
	/*0064DC5D*/	push 0x1
	/*0064DC5F*/	push 0xA
	/*0064DC61*/	add ecx,0xC80
	/*0064DC67*/	push esi
	/*0064DC68*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DC6D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DC73*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064DC78*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064DC7D*/	push 0x7D2
	/*0064DC82*/	push 0x1
	/*0064DC84*/	push 0xA
	/*0064DC86*/	add ecx,0xC90
	/*0064DC8C*/	push esi
	/*0064DC8D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DC92*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DC98*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064DC9D*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064DCA2*/	push 0x7D2
	/*0064DCA7*/	push 0x1
	/*0064DCA9*/	push 0xA
	/*0064DCAB*/	add ecx,0xCA0
	/*0064DCB1*/	push esi
	/*0064DCB2*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DCB7*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DCBD*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064DCC2*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064DCC7*/	push 0x7D2
	/*0064DCCC*/	push 0x1
	/*0064DCCE*/	push 0xA
	/*0064DCD0*/	add ecx,0xCB0
	/*0064DCD6*/	push esi
	/*0064DCD7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DCDC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DCE2*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064DCE7*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064DCEC*/	push 0x7D2
	/*0064DCF1*/	push 0x1
	/*0064DCF3*/	push 0xA
	/*0064DCF5*/	add ecx,0xCC0
	/*0064DCFB*/	push esi
	/*0064DCFC*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DD01*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DD07*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064DD0C*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064DD11*/	push 0x7D2
	/*0064DD16*/	push 0x1
	/*0064DD18*/	push 0xA
	/*0064DD1A*/	add ecx,0xCD0
	/*0064DD20*/	push esi
	/*0064DD21*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DD26*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DD2C*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064DD31*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064DD36*/	push 0x7D2
	/*0064DD3B*/	push 0x1
	/*0064DD3D*/	push 0xA
	/*0064DD3F*/	add ecx,0xCE0
	/*0064DD45*/	push esi
	/*0064DD46*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DD4B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DD51*/	add ecx,0xCF0
	/*0064DD57*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064DD5C*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064DD61*/	push 0x7D2
	/*0064DD66*/	push 0x1
	/*0064DD68*/	push 0x11
	/*0064DD6A*/	push esi
	/*0064DD6B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DD70*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DD76*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064DD7B*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064DD80*/	push 0x7D2
	/*0064DD85*/	push 0x1
	/*0064DD87*/	push 0x11
	/*0064DD89*/	add ecx,0xD00
	/*0064DD8F*/	push esi
	/*0064DD90*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DD95*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DD9B*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064DDA0*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064DDA5*/	push 0x7D2
	/*0064DDAA*/	push 0x1
	/*0064DDAC*/	push 0x11
	/*0064DDAE*/	add ecx,0xD10
	/*0064DDB4*/	push esi
	/*0064DDB5*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DDBA*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DDC0*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064DDC5*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064DDCA*/	push 0x7D2
	/*0064DDCF*/	push 0x1
	/*0064DDD1*/	push 0x11
	/*0064DDD3*/	add ecx,0xD20
	/*0064DDD9*/	push esi
	/*0064DDDA*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DDDF*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DDE5*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064DDEA*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064DDEF*/	push 0x7D2
	/*0064DDF4*/	push 0x1
	/*0064DDF6*/	push 0x11
	/*0064DDF8*/	add ecx,0xD30
	/*0064DDFE*/	push esi
	/*0064DDFF*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DE04*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DE0A*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064DE0F*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064DE14*/	push 0x7D2
	/*0064DE19*/	push 0x1
	/*0064DE1B*/	push 0x11
	/*0064DE1D*/	add ecx,0xD40
	/*0064DE23*/	push esi
	/*0064DE24*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DE29*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DE2F*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064DE34*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064DE39*/	push 0x7D2
	/*0064DE3E*/	push 0x1
	/*0064DE40*/	push 0x11
	/*0064DE42*/	add ecx,0xD50
	/*0064DE48*/	push esi
	/*0064DE49*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DE4E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DE54*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064DE59*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064DE5E*/	push 0x7D2
	/*0064DE63*/	push 0x1
	/*0064DE65*/	push 0x11
	/*0064DE67*/	add ecx,0xD60
	/*0064DE6D*/	push esi
	/*0064DE6E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DE73*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DE79*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064DE7E*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064DE83*/	push 0x7D2
	/*0064DE88*/	push 0x1
	/*0064DE8A*/	push 0x11
	/*0064DE8C*/	add ecx,0xD70
	/*0064DE92*/	push esi
	/*0064DE93*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DE98*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DE9E*/	add ecx,0xD80
	/*0064DEA4*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064DEA9*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064DEAE*/	push 0x7D2
	/*0064DEB3*/	push 0x2
	/*0064DEB5*/	push 0x3
	/*0064DEB7*/	push esi
	/*0064DEB8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DEBD*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DEC3*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064DEC8*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064DECD*/	push 0x7D2
	/*0064DED2*/	push 0x2
	/*0064DED4*/	push 0x3
	/*0064DED6*/	add ecx,0xD90
	/*0064DEDC*/	push esi
	/*0064DEDD*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DEE2*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DEE8*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064DEED*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064DEF2*/	push 0x7D2
	/*0064DEF7*/	push 0x2
	/*0064DEF9*/	push 0x3
	/*0064DEFB*/	add ecx,0xDA0
	/*0064DF01*/	push esi
	/*0064DF02*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DF07*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DF0D*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064DF12*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064DF17*/	push 0x7D2
	/*0064DF1C*/	push 0x2
	/*0064DF1E*/	push 0x3
	/*0064DF20*/	add ecx,0xDB0
	/*0064DF26*/	push esi
	/*0064DF27*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DF2C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DF32*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064DF37*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064DF3C*/	push 0x7D2
	/*0064DF41*/	push 0x2
	/*0064DF43*/	push 0x3
	/*0064DF45*/	add ecx,0xDC0
	/*0064DF4B*/	push esi
	/*0064DF4C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DF51*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DF57*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064DF5C*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064DF61*/	push 0x7D2
	/*0064DF66*/	push 0x2
	/*0064DF68*/	push 0x3
	/*0064DF6A*/	add ecx,0xDD0
	/*0064DF70*/	push esi
	/*0064DF71*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DF76*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DF7C*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064DF81*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064DF86*/	push 0x7D2
	/*0064DF8B*/	push 0x2
	/*0064DF8D*/	push 0x3
	/*0064DF8F*/	add ecx,0xDE0
	/*0064DF95*/	push esi
	/*0064DF96*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DF9B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DFA1*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064DFA6*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064DFAB*/	push 0x7D2
	/*0064DFB0*/	push 0x2
	/*0064DFB2*/	push 0x3
	/*0064DFB4*/	add ecx,0xDF0
	/*0064DFBA*/	push esi
	/*0064DFBB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DFC0*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DFC6*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064DFCB*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064DFD0*/	push 0x7D2
	/*0064DFD5*/	push 0x2
	/*0064DFD7*/	push 0x3
	/*0064DFD9*/	add ecx,0xE00
	/*0064DFDF*/	push esi
	/*0064DFE0*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064DFE5*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064DFEB*/	add ecx,0xE10
	/*0064DFF1*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064DFF6*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064DFFB*/	push 0x7D2
	/*0064E000*/	push 0x2
	/*0064E002*/	push 0xA
	/*0064E004*/	push esi
	/*0064E005*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E00A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E010*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E015*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E01A*/	push 0x7D2
	/*0064E01F*/	push 0x2
	/*0064E021*/	push 0xA
	/*0064E023*/	add ecx,0xE20
	/*0064E029*/	push esi
	/*0064E02A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E02F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E035*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E03A*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064E03F*/	push 0x7D2
	/*0064E044*/	push 0x2
	/*0064E046*/	push 0xA
	/*0064E048*/	add ecx,0xE30
	/*0064E04E*/	push esi
	/*0064E04F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E054*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E05A*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E05F*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E064*/	push 0x7D2
	/*0064E069*/	push 0x2
	/*0064E06B*/	push 0xA
	/*0064E06D*/	add ecx,0xE40
	/*0064E073*/	push esi
	/*0064E074*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E079*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E07F*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E084*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E089*/	push 0x7D2
	/*0064E08E*/	push 0x2
	/*0064E090*/	push 0xA
	/*0064E092*/	add ecx,0xE50
	/*0064E098*/	push esi
	/*0064E099*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E09E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E0A4*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E0A9*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E0AE*/	push 0x7D2
	/*0064E0B3*/	push 0x2
	/*0064E0B5*/	push 0xA
	/*0064E0B7*/	add ecx,0xE60
	/*0064E0BD*/	push esi
	/*0064E0BE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E0C3*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E0C9*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E0CE*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064E0D3*/	push 0x7D2
	/*0064E0D8*/	push 0x2
	/*0064E0DA*/	push 0xA
	/*0064E0DC*/	add ecx,0xE70
	/*0064E0E2*/	push esi
	/*0064E0E3*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E0E8*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E0EE*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064E0F3*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E0F8*/	push 0x7D2
	/*0064E0FD*/	push 0x2
	/*0064E0FF*/	push 0xA
	/*0064E101*/	add ecx,0xE80
	/*0064E107*/	push esi
	/*0064E108*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E10D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E113*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064E118*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E11D*/	push 0x7D2
	/*0064E122*/	push 0x2
	/*0064E124*/	push 0xA
	/*0064E126*/	add ecx,0xE90
	/*0064E12C*/	push esi
	/*0064E12D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E132*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E138*/	add ecx,0xEA0
	/*0064E13E*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E143*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064E148*/	push 0x7D2
	/*0064E14D*/	push 0x2
	/*0064E14F*/	push 0x11
	/*0064E151*/	push esi
	/*0064E152*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E157*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E15D*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E162*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E167*/	push 0x7D2
	/*0064E16C*/	push 0x2
	/*0064E16E*/	push 0x11
	/*0064E170*/	add ecx,0xEB0
	/*0064E176*/	push esi
	/*0064E177*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E17C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E182*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064E187*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E18C*/	push 0x7D2
	/*0064E191*/	push 0x2
	/*0064E193*/	push 0x11
	/*0064E195*/	add ecx,0xEC0
	/*0064E19B*/	push esi
	/*0064E19C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E1A1*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E1A7*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E1AC*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064E1B1*/	push 0x7D2
	/*0064E1B6*/	push 0x2
	/*0064E1B8*/	push 0x11
	/*0064E1BA*/	add ecx,0xED0
	/*0064E1C0*/	push esi
	/*0064E1C1*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E1C6*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E1CC*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E1D1*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E1D6*/	push 0x7D2
	/*0064E1DB*/	push 0x2
	/*0064E1DD*/	push 0x11
	/*0064E1DF*/	add ecx,0xEE0
	/*0064E1E5*/	push esi
	/*0064E1E6*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E1EB*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E1F1*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E1F6*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064E1FB*/	push 0x7D2
	/*0064E200*/	push 0x2
	/*0064E202*/	push 0x11
	/*0064E204*/	add ecx,0xEF0
	/*0064E20A*/	push esi
	/*0064E20B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E210*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E216*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E21B*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E220*/	push 0x7D2
	/*0064E225*/	push 0x2
	/*0064E227*/	push 0x11
	/*0064E229*/	add ecx,0xF00
	/*0064E22F*/	push esi
	/*0064E230*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E235*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E23B*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064E240*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E245*/	push 0x7D2
	/*0064E24A*/	push 0x2
	/*0064E24C*/	push 0x11
	/*0064E24E*/	add ecx,0xF10
	/*0064E254*/	push esi
	/*0064E255*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E25A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E260*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064E265*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E26A*/	push 0x7D2
	/*0064E26F*/	push 0x2
	/*0064E271*/	push 0x11
	/*0064E273*/	add ecx,0xF20
	/*0064E279*/	push esi
	/*0064E27A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E27F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E285*/	add ecx,0xF30
	/*0064E28B*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064E290*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E295*/	push 0x7D2
	/*0064E29A*/	push 0x2
	/*0064E29C*/	push 0x18
	/*0064E29E*/	push esi
	/*0064E29F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E2A4*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E2AA*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E2AF*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064E2B4*/	push 0x7D2
	/*0064E2B9*/	push 0x2
	/*0064E2BB*/	push 0x18
	/*0064E2BD*/	add ecx,0xF40
	/*0064E2C3*/	push esi
	/*0064E2C4*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E2C9*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E2CF*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E2D4*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064E2D9*/	push 0x7D2
	/*0064E2DE*/	push 0x2
	/*0064E2E0*/	push 0x18
	/*0064E2E2*/	add ecx,0xF50
	/*0064E2E8*/	push esi
	/*0064E2E9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E2EE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E2F4*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E2F9*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E2FE*/	push 0x7D2
	/*0064E303*/	push 0x2
	/*0064E305*/	push 0x18
	/*0064E307*/	add ecx,0xF60
	/*0064E30D*/	push esi
	/*0064E30E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E313*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E319*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E31E*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E323*/	push 0x7D2
	/*0064E328*/	push 0x2
	/*0064E32A*/	push 0x18
	/*0064E32C*/	add ecx,0xF70
	/*0064E332*/	push esi
	/*0064E333*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E338*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E33E*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E343*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E348*/	push 0x7D2
	/*0064E34D*/	push 0x2
	/*0064E34F*/	push 0x18
	/*0064E351*/	add ecx,0xF80
	/*0064E357*/	push esi
	/*0064E358*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E35D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E363*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064E368*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064E36D*/	push 0x7D2
	/*0064E372*/	push 0x2
	/*0064E374*/	push 0x18
	/*0064E376*/	add ecx,0xF90
	/*0064E37C*/	push esi
	/*0064E37D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E382*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E388*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E38D*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E392*/	push 0x7D2
	/*0064E397*/	push 0x2
	/*0064E399*/	push 0x18
	/*0064E39B*/	add ecx,0xFA0
	/*0064E3A1*/	push esi
	/*0064E3A2*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E3A7*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E3AD*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064E3B2*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E3B7*/	push 0x7D2
	/*0064E3BC*/	push 0x2
	/*0064E3BE*/	push 0x18
	/*0064E3C0*/	add ecx,0xFB0
	/*0064E3C6*/	push esi
	/*0064E3C7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E3CC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E3D2*/	add ecx,0xFC0
	/*0064E3D8*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064E3DD*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064E3E2*/	push 0x7D2
	/*0064E3E7*/	push 0x2
	/*0064E3E9*/	push 0x1E
	/*0064E3EB*/	push esi
	/*0064E3EC*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E3F1*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E3F7*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E3FC*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E401*/	push 0x7D2
	/*0064E406*/	push 0x2
	/*0064E408*/	push 0x1E
	/*0064E40A*/	add ecx,0xFD0
	/*0064E410*/	push esi
	/*0064E411*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E416*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E41C*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E421*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E426*/	push 0x7D2
	/*0064E42B*/	push 0x2
	/*0064E42D*/	push 0x1E
	/*0064E42F*/	add ecx,0xFE0
	/*0064E435*/	push esi
	/*0064E436*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E43B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E441*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E446*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E44B*/	push 0x7D2
	/*0064E450*/	push 0x2
	/*0064E452*/	push 0x1E
	/*0064E454*/	add ecx,0xFF0
	/*0064E45A*/	push esi
	/*0064E45B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E460*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E466*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064E46B*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E470*/	push 0x7D2
	/*0064E475*/	push 0x2
	/*0064E477*/	push 0x1E
	/*0064E479*/	add ecx,0x1000
	/*0064E47F*/	push esi
	/*0064E480*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E485*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E48B*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E490*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E495*/	push 0x7D2
	/*0064E49A*/	push 0x2
	/*0064E49C*/	push 0x1E
	/*0064E49E*/	add ecx,0x1010
	/*0064E4A4*/	push esi
	/*0064E4A5*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E4AA*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E4B0*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E4B5*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064E4BA*/	push 0x7D2
	/*0064E4BF*/	push 0x2
	/*0064E4C1*/	push 0x1E
	/*0064E4C3*/	add ecx,0x1020
	/*0064E4C9*/	push esi
	/*0064E4CA*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E4CF*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E4D5*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064E4DA*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E4DF*/	push 0x7D2
	/*0064E4E4*/	push 0x2
	/*0064E4E6*/	push 0x1E
	/*0064E4E8*/	add ecx,0x1030
	/*0064E4EE*/	push esi
	/*0064E4EF*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E4F4*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E4FA*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064E4FF*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E504*/	push 0x7D2
	/*0064E509*/	push 0x2
	/*0064E50B*/	push 0x1E
	/*0064E50D*/	add ecx,0x1040
	/*0064E513*/	push esi
	/*0064E514*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E519*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E51F*/	add ecx,0x1050
	/*0064E525*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E52A*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064E52F*/	push 0x7D2
	/*0064E534*/	push 0x3
	/*0064E536*/	push 0x7
	/*0064E538*/	push esi
	/*0064E539*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E53E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E544*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E549*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E54E*/	push 0x7D2
	/*0064E553*/	push 0x3
	/*0064E555*/	push 0x7
	/*0064E557*/	add ecx,0x1060
	/*0064E55D*/	push esi
	/*0064E55E*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E563*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E569*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E56E*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E573*/	push 0x7D2
	/*0064E578*/	push 0x3
	/*0064E57A*/	push 0x7
	/*0064E57C*/	add ecx,0x1070
	/*0064E582*/	push esi
	/*0064E583*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E588*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E58E*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064E593*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E598*/	push 0x7D2
	/*0064E59D*/	push 0x3
	/*0064E59F*/	push 0x7
	/*0064E5A1*/	add ecx,0x1080
	/*0064E5A7*/	push esi
	/*0064E5A8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E5AD*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E5B3*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E5B8*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E5BD*/	push 0x7D2
	/*0064E5C2*/	push 0x3
	/*0064E5C4*/	push 0x7
	/*0064E5C6*/	add ecx,0x1090
	/*0064E5CC*/	push esi
	/*0064E5CD*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E5D2*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E5D8*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E5DD*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064E5E2*/	push 0x7D2
	/*0064E5E7*/	push 0x3
	/*0064E5E9*/	push 0x7
	/*0064E5EB*/	add ecx,0x10A0
	/*0064E5F1*/	push esi
	/*0064E5F2*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E5F7*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E5FD*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E602*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E607*/	push 0x7D2
	/*0064E60C*/	push 0x3
	/*0064E60E*/	push 0x7
	/*0064E610*/	add ecx,0x10B0
	/*0064E616*/	push esi
	/*0064E617*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E61C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E622*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064E627*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064E62C*/	push 0x7D2
	/*0064E631*/	push 0x3
	/*0064E633*/	push 0x7
	/*0064E635*/	add ecx,0x10C0
	/*0064E63B*/	push esi
	/*0064E63C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E641*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E647*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064E64C*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E651*/	push 0x7D2
	/*0064E656*/	push 0x3
	/*0064E658*/	push 0x7
	/*0064E65A*/	add ecx,0x10D0
	/*0064E660*/	push esi
	/*0064E661*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E666*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E66C*/	add ecx,0x10E0
	/*0064E672*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064E677*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064E67C*/	push 0x7D2
	/*0064E681*/	push 0x3
	/*0064E683*/	push 0xE
	/*0064E685*/	push esi
	/*0064E686*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E68B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E691*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E696*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E69B*/	push 0x7D2
	/*0064E6A0*/	push 0x3
	/*0064E6A2*/	push 0xE
	/*0064E6A4*/	add ecx,0x10F0
	/*0064E6AA*/	push esi
	/*0064E6AB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E6B0*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E6B6*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E6BB*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E6C0*/	push 0x7D2
	/*0064E6C5*/	push 0x3
	/*0064E6C7*/	push 0xE
	/*0064E6C9*/	add ecx,0x1100
	/*0064E6CF*/	push esi
	/*0064E6D0*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E6D5*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E6DB*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E6E0*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E6E5*/	push 0x7D2
	/*0064E6EA*/	push 0x3
	/*0064E6EC*/	push 0xE
	/*0064E6EE*/	add ecx,0x1110
	/*0064E6F4*/	push esi
	/*0064E6F5*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E6FA*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E700*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E705*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064E70A*/	push 0x7D2
	/*0064E70F*/	push 0x3
	/*0064E711*/	push 0xE
	/*0064E713*/	add ecx,0x1120
	/*0064E719*/	push esi
	/*0064E71A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E71F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E725*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E72A*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E72F*/	push 0x7D2
	/*0064E734*/	push 0x3
	/*0064E736*/	push 0xE
	/*0064E738*/	add ecx,0x1130
	/*0064E73E*/	push esi
	/*0064E73F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E744*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E74A*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E74F*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064E754*/	push 0x7D2
	/*0064E759*/	push 0x3
	/*0064E75B*/	push 0xE
	/*0064E75D*/	add ecx,0x1140
	/*0064E763*/	push esi
	/*0064E764*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E769*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E76F*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064E774*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E779*/	push 0x7D2
	/*0064E77E*/	push 0x3
	/*0064E780*/	push 0xE
	/*0064E782*/	add ecx,0x1150
	/*0064E788*/	push esi
	/*0064E789*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E78E*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E794*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064E799*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E79E*/	push 0x7D2
	/*0064E7A3*/	push 0x3
	/*0064E7A5*/	push 0xE
	/*0064E7A7*/	add ecx,0x1160
	/*0064E7AD*/	push esi
	/*0064E7AE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E7B3*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E7B9*/	add ecx,0x1170
	/*0064E7BF*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E7C4*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064E7C9*/	push 0x7D2
	/*0064E7CE*/	push 0x3
	/*0064E7D0*/	push 0x15
	/*0064E7D2*/	push esi
	/*0064E7D3*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E7D8*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E7DE*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E7E3*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064E7E8*/	push 0x7D2
	/*0064E7ED*/	push 0x3
	/*0064E7EF*/	push 0x15
	/*0064E7F1*/	add ecx,0x1180
	/*0064E7F7*/	push esi
	/*0064E7F8*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E7FD*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E803*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E808*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E80D*/	push 0x7D2
	/*0064E812*/	push 0x3
	/*0064E814*/	push 0x15
	/*0064E816*/	add ecx,0x1190
	/*0064E81C*/	push esi
	/*0064E81D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E822*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E828*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064E82D*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E832*/	push 0x7D2
	/*0064E837*/	push 0x3
	/*0064E839*/	push 0x15
	/*0064E83B*/	add ecx,0x11A0
	/*0064E841*/	push esi
	/*0064E842*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E847*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E84D*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E852*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E857*/	push 0x7D2
	/*0064E85C*/	push 0x3
	/*0064E85E*/	push 0x15
	/*0064E860*/	add ecx,0x11B0
	/*0064E866*/	push esi
	/*0064E867*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E86C*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E872*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E877*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064E87C*/	push 0x7D2
	/*0064E881*/	push 0x3
	/*0064E883*/	push 0x15
	/*0064E885*/	add ecx,0x11C0
	/*0064E88B*/	push esi
	/*0064E88C*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E891*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E897*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E89C*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E8A1*/	push 0x7D2
	/*0064E8A6*/	push 0x3
	/*0064E8A8*/	push 0x15
	/*0064E8AA*/	add ecx,0x11D0
	/*0064E8B0*/	push esi
	/*0064E8B1*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E8B6*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E8BC*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064E8C1*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E8C6*/	push 0x7D2
	/*0064E8CB*/	push 0x3
	/*0064E8CD*/	push 0x15
	/*0064E8CF*/	add ecx,0x11E0
	/*0064E8D5*/	push esi
	/*0064E8D6*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E8DB*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E8E1*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064E8E6*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E8EB*/	push 0x7D2
	/*0064E8F0*/	push 0x3
	/*0064E8F2*/	push 0x15
	/*0064E8F4*/	add ecx,0x11F0
	/*0064E8FA*/	push esi
	/*0064E8FB*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E900*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E906*/	add ecx,0x1200
	/*0064E90C*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064E911*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064E916*/	push 0x7D2
	/*0064E91B*/	push 0x3
	/*0064E91D*/	push 0x1C
	/*0064E91F*/	push esi
	/*0064E920*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E925*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E92B*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064E930*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064E935*/	push 0x7D2
	/*0064E93A*/	push 0x3
	/*0064E93C*/	push 0x1C
	/*0064E93E*/	add ecx,0x1210
	/*0064E944*/	push esi
	/*0064E945*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E94A*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E950*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064E955*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064E95A*/	push 0x7D2
	/*0064E95F*/	push 0x3
	/*0064E961*/	push 0x1C
	/*0064E963*/	add ecx,0x1220
	/*0064E969*/	push esi
	/*0064E96A*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E96F*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E975*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064E97A*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064E97F*/	push 0x7D2
	/*0064E984*/	push 0x3
	/*0064E986*/	push 0x1C
	/*0064E988*/	add ecx,0x1230
	/*0064E98E*/	push esi
	/*0064E98F*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E994*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E99A*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064E99F*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064E9A4*/	push 0x7D2
	/*0064E9A9*/	push 0x3
	/*0064E9AB*/	push 0x1C
	/*0064E9AD*/	add ecx,0x1240
	/*0064E9B3*/	push esi
	/*0064E9B4*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E9B9*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E9BF*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064E9C4*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064E9C9*/	push 0x7D2
	/*0064E9CE*/	push 0x3
	/*0064E9D0*/	push 0x1C
	/*0064E9D2*/	add ecx,0x1250
	/*0064E9D8*/	push esi
	/*0064E9D9*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064E9DE*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064E9E4*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064E9E9*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064E9EE*/	push 0x7D2
	/*0064E9F3*/	push 0x3
	/*0064E9F5*/	push 0x1C
	/*0064E9F7*/	add ecx,0x1260
	/*0064E9FD*/	push esi
	/*0064E9FE*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EA03*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EA09*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064EA0E*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064EA13*/	push 0x7D2
	/*0064EA18*/	push 0x3
	/*0064EA1A*/	push 0x1C
	/*0064EA1C*/	add ecx,0x1270
	/*0064EA22*/	push esi
	/*0064EA23*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EA28*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EA2E*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064EA33*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064EA38*/	push 0x7D2
	/*0064EA3D*/	push 0x3
	/*0064EA3F*/	push 0x1C
	/*0064EA41*/	add ecx,0x1280
	/*0064EA47*/	push esi
	/*0064EA48*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EA4D*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EA53*/	add ecx,0x1290
	/*0064EA59*/	push 0x9EA530		/*push cm0102.9EA530*/
	/*0064EA5E*/	push 0x9EA528		/*push cm0102.9EA528*/
	/*0064EA63*/	push 0x7D2
	/*0064EA68*/	push 0x4
	/*0064EA6A*/	push 0x5
	/*0064EA6C*/	push esi
	/*0064EA6D*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EA72*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EA78*/	push 0x9EA538		/*push cm0102.9EA538*/
	/*0064EA7D*/	push 0x9EA4D4		/*push cm0102.9EA4D4*/
	/*0064EA82*/	push 0x7D2
	/*0064EA87*/	push 0x4
	/*0064EA89*/	push 0x5
	/*0064EA8B*/	add ecx,0x12A0
	/*0064EA91*/	push esi
	/*0064EA92*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EA97*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EA9D*/	push 0x9EA520		/*push cm0102.9EA520*/
	/*0064EAA2*/	push 0x9EA4B8		/*push cm0102.9EA4B8*/
	/*0064EAA7*/	push 0x7D2
	/*0064EAAC*/	push 0x4
	/*0064EAAE*/	push 0x5
	/*0064EAB0*/	add ecx,0x12B0
	/*0064EAB6*/	push esi
	/*0064EAB7*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EABC*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EAC2*/	push 0x9EA50C		/*push cm0102.9EA50C*/
	/*0064EAC7*/	push 0x9EA4DC		/*push cm0102.9EA4DC*/
	/*0064EACC*/	push 0x7D2
	/*0064EAD1*/	push 0x4
	/*0064EAD3*/	push 0x5
	/*0064EAD5*/	add ecx,0x12C0
	/*0064EADB*/	push esi
	/*0064EADC*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EAE1*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EAE7*/	push 0x9EA4CC		/*push cm0102.9EA4CC*/
	/*0064EAEC*/	push 0x9EA4F0		/*push cm0102.9EA4F0*/
	/*0064EAF1*/	push 0x7D2
	/*0064EAF6*/	push 0x4
	/*0064EAF8*/	push 0x5
	/*0064EAFA*/	add ecx,0x12D0
	/*0064EB00*/	push esi
	/*0064EB01*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EB06*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EB0C*/	push 0x9EA4FC		/*push cm0102.9EA4FC*/
	/*0064EB11*/	push 0x9EA4E4		/*push cm0102.9EA4E4*/
	/*0064EB16*/	push 0x7D2
	/*0064EB1B*/	push 0x4
	/*0064EB1D*/	push 0x5
	/*0064EB1F*/	add ecx,0x12E0
	/*0064EB25*/	push esi
	/*0064EB26*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EB2B*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EB31*/	push 0x9EA4C4		/*push cm0102.9EA4C4*/
	/*0064EB36*/	push 0x9EA540		/*push cm0102.9EA540*/
	/*0064EB3B*/	push 0x7D2
	/*0064EB40*/	push 0x4
	/*0064EB42*/	push 0x5
	/*0064EB44*/	add ecx,0x12F0
	/*0064EB4A*/	push esi
	/*0064EB4B*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EB50*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EB56*/	push 0x9EA504		/*push cm0102.9EA504*/
	/*0064EB5B*/	push 0x9EA518		/*push cm0102.9EA518*/
	/*0064EB60*/	push 0x7D2
	/*0064EB65*/	push 0x4
	/*0064EB67*/	push 0x5
	/*0064EB69*/	add ecx,0x1300
	/*0064EB6F*/	push esi
	/*0064EB70*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EB75*/	mov ecx,dword ptr ds:[esi+0xEA]
	/*0064EB7B*/	push 0x9EA4B0		/*push cm0102.9EA4B0*/
	/*0064EB80*/	push 0x9EA54C		/*push cm0102.9EA54C*/
	/*0064EB85*/	push 0x7D2
	/*0064EB8A*/	push 0x4
	/*0064EB8C*/	push 0x5
	/*0064EB8E*/	add ecx,0x1310
	/*0064EB94*/	push esi
	/*0064EB95*/	call sub_68AFF0		/*call <cm0102.sub_68AFF0>*/
	/*0064EB9A*/	movsx eax,word ptr ds:[esi+0x3E]
	/*0064EB9E*/	xor ecx,ecx
	/*0064EBA0*/	cdq
	/*0064EBA1*/	sub eax,edx
	/*0064EBA3*/	movsx edx,word ptr ds:[esi+0xA9]
	/*0064EBAA*/	sar eax,0x1
	/*0064EBAC*/	imul eax,edx
	/*0064EBAF*/	test eax,eax
	/*0064EBB1*/	jle _0064EBFA
	/*0064EBB3*/	mov ebx,dword ptr ds:[esi+0xEA]
	/*0064EBB9*/	lea edx,dword ptr ds:[ebx+0xC]
_0064EBBC:
	/*0064EBBC*/	cmp dword ptr ds:[edx-0x4],edi
	/*0064EBBF*/	je _0064EBCF
	/*0064EBC1*/	cmp dword ptr ds:[edx],edi
	/*0064EBC3*/	je _0064EBCF
	/*0064EBC5*/	inc ecx
	/*0064EBC6*/	add edx,0x10
	/*0064EBC9*/	cmp ecx,eax
	/*0064EBCB*/	jl _0064EBBC
	/*0064EBCD*/	jmp _0064EBFA
_0064EBCF:
	/*0064EBCF*/	test ebx,ebx
	/*0064EBD1*/	je _0064EBF0
	/*0064EBD3*/	mov eax,dword ptr ds:[ebx-0x4]
	/*0064EBD6*/	lea edi,dword ptr ds:[ebx-0x4]
	/*0064EBD9*/	push 0x5A53C0		/*push <cm0102.sub_5A53C0>*/
	/*0064EBDE*/	push eax
	/*0064EBDF*/	push 0x10
	/*0064EBE1*/	push ebx
	/*0064EBE2*/	call sub_9462BB		/*call <cm0102.sub_9462BB>*/
	/*0064EBE7*/	push edi
	/*0064EBE8*/	call sub_944E46_malloc		/*call <cm0102.sub_944E46_malloc_malloc>*/
	/*0064EBED*/	add esp,0x4
_0064EBF0:
	/*0064EBF0*/	mov dword ptr ds:[esi+0xEA],0x0
_0064EBFA:
	/*0064EBFA*/	mov ecx,dword ptr ss:[esp+0x210]
	/*0064EC01*/	pop edi
	/*0064EC02*/	pop esi
	/*0064EC03*/	pop ebx
	/*0064EC04*/	mov dword ptr fs:[0x0],ecx
	/*0064EC0B*/	add esp,0x210
	/*0064EC11*/	ret
	}
}

void patch_ita_ser_c1a()
{
	vtable::PrintVTable(0x96C534, "ita_ser_c1a");
	PatchFunction(0x64AA70, (DWORD)&sub_64AA70);
	
	DWORD Size = 0x64EC11 - 0x64AA70;
	DWORD oldProtect;
	VirtualProtect((void*)0x64AA70, Size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset((void*)(0x64AA70 + 0x5), 0xcc, Size - 0x5);
}