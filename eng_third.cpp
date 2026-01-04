#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "CMHeader.h"
#include "Helper.h"
#include "vtable.h"

static int(*sub_48C6D0)() = (int(*)())(0x48C6D0);
static int(*sub_49EE70)() = (int(*)())(0x49EE70);
static int(*sub_49F450)() = (int(*)())(0x49F450);
static int(*sub_4A1C50)() = (int(*)())(0x4A1C50);
static int(*sub_4A4850)() = (int(*)())(0x4A4850);
static int(*sub_4AE660)() = (int(*)())(0x4AE660);
static int(*sub_4AE8A0)() = (int(*)())(0x4AE8A0);
static int(*sub_51C800)() = (int(*)())(0x51C800);
static int(*sub_521E60)() = (int(*)())(0x521E60);
static int(*sub_521EB0)() = (int(*)())(0x521EB0);
static int(*sub_522E00)() = (int(*)())(0x522E00);
static int(*sub_549F70)() = (int(*)())(0x549F70);
static int(*sub_5783C0)() = (int(*)())(0x5783C0);
static int(*sub_5E8290)() = (int(*)())(0x5E8290);
static int(*sub_66F4E0)() = (int(*)())(0x66F4E0);
static int(*sub_682200)() = (int(*)())(0x682200);
static int(*sub_682300)() = (int(*)())(0x682300);
static int(*sub_6827D0)() = (int(*)())(0x6827D0);
static int(*sub_682F70)() = (int(*)())(0x682F70);
static int(*sub_683010)() = (int(*)())(0x683010);
static int(*sub_6835C0)() = (int(*)())(0x6835C0);
static int(*sub_687430)() = (int(*)())(0x687430);
static int(*sub_687970)() = (int(*)())(0x687970);
static int(*sub_687B10)() = (int(*)())(0x687B10);
static int(*sub_68A160)() = (int(*)())(0x68A160);
static int(*sub_68A1C0)() = (int(*)())(0x68A1C0);
static int(*sub_68A850)() = (int(*)())(0x68A850);
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

static int   (*sub_944C9F_sprintf)() = (int(*)())(0x944C9F);
static void* (*sub_944CF1_operator_new)(int size) = (void* (*)(int size))(0x944CF1);
static int   (*sub_944CFF_splitpath)() = (int(*)())(0x944CFF);
static void* (*sub_944E46_malloc)(int size) = (void* (*)(int size))(0x944E46);
static void* (*sub_945501_alloc)(int size, int a2) = (void* (*)(int size, int a2))(0x945501);

void sub_577020();
void sub_577F70();
void sub_5780C0();
void sub_577000();
void sub_578170();
void sub_578330();
void sub_5770E0();
void sub_576C50();
void sub_5785B0();
void sub_578660();

/*
eng_third VTable at 00969E84:
0. 00 = 00577000
1. 08 = 00578170
2. 28 = 00578330
3. 30 = 00684640
4. 3C = 005770E0
5. 44 = 00576C50
6. 48 = 005785B0
7. 50 = 0048E180
8. 68 = 00578660
9. 7C = 0048F2D0
10. 8C = 005780C0
11. B4 = 005788C0		// Awards
12. B8 = 00579610
*/

// Normally at: 0x969E84
vtable vtable_eng_third((DWORD)&sub_577000, (DWORD)&sub_578170, (DWORD)&sub_578330, 0x684640, (DWORD)&sub_5770E0/*fixture_caller*/, (DWORD)&sub_576C50, (DWORD)&sub_5785B0, 0x48E180, (DWORD)&sub_578660, 0x48F2D0, (DWORD)&sub_5780C0, 0x5788C0, 0x579610);

void __declspec(naked) sub_576C50()
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

void __declspec(naked) sub_576DD0()
{
	__asm
	{
	/*00576DD0*/	push 0xFFFFFFFF
	/*00576DD2*/	push 0x958489		/*push cm0102.958489*/
	/*00576DD7*/	mov eax,dword ptr fs:[0x0]
	/*00576DDD*/	push eax
	/*00576DDE*/	mov dword ptr fs:[0x0],esp
	/*00576DE5*/	sub esp,0x208
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
	/*00576E33*/	mov byte ptr ds:[esi+0x50],0x9
	/*00576E37*/	call sub_687B10		/*call cm0102.687B10*/
	/*00576E3C*/	test eax,eax
	/*00576E3E*/	jne _00576FE3
	/*00576E44*/	or eax,0xFFFFFFFF
	/*00576E47*/	push 0x4
	/*00576E49*/	mov byte ptr ds:[esi+0x44],al
	/*00576E4C*/	mov dword ptr ds:[esi+0x30],eax
	/*00576E4F*/	mov dword ptr ds:[esi+0x2C],0x1
	/*00576E56*/	call sub_944E46_malloc		/*call cm0102.944E46*/
	/*00576E5B*/	add esp,0x4
	/*00576E5E*/	mov ecx,esi
	/*00576E60*/	mov dword ptr ds:[esi+0xC],eax
	/*00576E63*/	call sub_5780C0		/*call cm0102.5780C0*/
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
	/*00576E9E*/	call sub_577F70		/*call cm0102.577F70*/
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
	/*00576FE3*/	mov ecx,dword ptr ss:[esp+0x210]
	/*00576FEA*/	mov eax,esi
	/*00576FEC*/	pop esi
	/*00576FED*/	pop ebx
	/*00576FEE*/	mov dword ptr fs:[0x0],ecx
	/*00576FF5*/	add esp,0x214
	/*00576FFB*/	ret 0x8
	}
}

void __declspec(naked) sub_577000()
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

void __declspec(naked) sub_577020()
{
	__asm
	{
	/*00577020*/	push 0xFFFFFFFF
	/*00577022*/	push 0x9584A8		/*push cm0102.9584A8*/
	/*00577027*/	mov eax,dword ptr fs:[0x0]
	/*0057702D*/	push eax
	/*0057702E*/	mov dword ptr fs:[0x0],esp
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
	/*005770CE*/	mov ecx,dword ptr ss:[esp+0xC]
	/*005770D2*/	pop edi
	/*005770D3*/	pop esi
	/*005770D4*/	mov dword ptr fs:[0x0],ecx
	/*005770DB*/	add esp,0x10
	/*005770DE*/	ret
	}
}

void __declspec(naked) sub_5770E0()
{
	__asm
	{
	/*005770E0*/	mov al,byte ptr ss:[esp+0x4]
	/*005770E4*/	sub esp,0x208
	/*005770EA*/	cmp al,0xFF
	/*005770EC*/	push ebx
	/*005770ED*/	push esi
	/*005770EE*/	push edi
	/*005770EF*/	mov edi,ecx
	/*005770F1*/	jne _00577D8B
	/*005770F7*/	mov eax,dword ptr ss:[esp+0x224]
	/*005770FE*/	xor ebx,ebx
	/*00577100*/	cmp eax,ebx
	/*00577102*/	je _0057710A
	/*00577104*/	mov dword ptr ds:[eax],0x1
_0057710A:
	/*0057710A*/	mov eax,dword ptr ss:[esp+0x21C]
	/*00577111*/	mov ecx,dword ptr ss:[esp+0x220]
	/*00577118*/	push 0xBAE
	/*0057711D*/	mov word ptr ds:[eax],0x2E
	/*00577122*/	mov word ptr ds:[ecx],bx
	/*00577125*/	call sub_944E46_malloc		/*call cm0102.944E46*/
	/*0057712A*/	mov esi,eax
	/*0057712C*/	add esp,0x4
	/*0057712F*/	cmp esi,ebx
	/*00577131*/	jne _00577165
	/*00577133*/	lea edx,dword ptr ss:[esp+0x14]
	/*00577137*/	lea eax,dword ptr ss:[esp+0x114]
	/*0057713E*/	push edx
	/*0057713F*/	push eax
	/*00577140*/	push ebx
	/*00577141*/	push ebx
	/*00577142*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00577147*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*0057714C*/	add esp,0x14
	/*0057714F*/	lea ecx,dword ptr ss:[esp+0x14]
	/*00577153*/	lea edx,dword ptr ss:[esp+0x114]
	/*0057715A*/	push 0xB3
	/*0057715F*/	push ecx
	/*00577160*/	jmp _00577DFA
_00577165:
	/*00577165*/	mov ax,word ptr ds:[edi+0x40]
	/*00577169*/	push ebx
	/*0057716A*/	push eax
	/*0057716B*/	push 0x1
	/*0057716D*/	push 0x5
	/*0057716F*/	push ebx
	/*00577170*/	push 0x7
	/*00577172*/	push 0xC
	/*00577174*/	push ebx
	/*00577175*/	push esi
	/*00577176*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057717B*/	push ebx
	/*0057717C*/	push 0xFFFFFFFF
	/*0057717E*/	push 0xFFFFFFFF
	/*00577180*/	push 0xFFFFFFFF
	/*00577182*/	push ebx
	/*00577183*/	push ebx
	/*00577184*/	push esi
	/*00577185*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057718A*/	mov cx,word ptr ds:[edi+0x40]
	/*0057718E*/	add esp,0x40
	/*00577191*/	push ebx
	/*00577192*/	push ecx
	/*00577193*/	push 0x1
	/*00577195*/	push 0x5
	/*00577197*/	push ebx
	/*00577198*/	push 0x7
	/*0057719A*/	push 0x13
	/*0057719C*/	push 0x1
	/*0057719E*/	push esi
	/*0057719F*/	call sub_68A160		/*call cm0102.68A160*/
	/*005771A4*/	push ebx
	/*005771A5*/	push 0xFFFFFFFF
	/*005771A7*/	push 0xFFFFFFFF
	/*005771A9*/	push 0xFFFFFFFF
	/*005771AB*/	push ebx
	/*005771AC*/	push 0x1
	/*005771AE*/	push esi
	/*005771AF*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005771B4*/	mov dx,word ptr ds:[edi+0x40]
	/*005771B8*/	add esp,0x40
	/*005771BB*/	push ebx
	/*005771BC*/	push edx
	/*005771BD*/	push 0x1
	/*005771BF*/	push 0x5
	/*005771C1*/	push ebx
	/*005771C2*/	push 0x7
	/*005771C4*/	push 0x1A
	/*005771C6*/	push 0x2
	/*005771C8*/	push esi
	/*005771C9*/	call sub_68A160		/*call cm0102.68A160*/
	/*005771CE*/	push ebx
	/*005771CF*/	push 0xFFFFFFFF
	/*005771D1*/	push 0xFFFFFFFF
	/*005771D3*/	push 0xFFFFFFFF
	/*005771D5*/	push ebx
	/*005771D6*/	push 0x2
	/*005771D8*/	push esi
	/*005771D9*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005771DE*/	mov ax,word ptr ds:[edi+0x40]
	/*005771E2*/	add esp,0x40
	/*005771E5*/	push ebx
	/*005771E6*/	push eax
	/*005771E7*/	push 0x2
	/*005771E9*/	push ebx
	/*005771EA*/	push ebx
	/*005771EB*/	push 0x7
	/*005771ED*/	push 0x1C
	/*005771EF*/	push 0x3
	/*005771F1*/	push esi
	/*005771F2*/	call sub_68A160		/*call cm0102.68A160*/
	/*005771F7*/	push ebx
	/*005771F8*/	push 0xFFFFFFFF
	/*005771FA*/	push 0xFFFFFFFF
	/*005771FC*/	push 0xFFFFFFFF
	/*005771FE*/	push ebx
	/*005771FF*/	push 0x3
	/*00577201*/	push esi
	/*00577202*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577207*/	add esp,0x40
	/*0057720A*/	push ebx
	/*0057720B*/	mov cx,word ptr ds:[edi+0x40]
	/*0057720F*/	push ecx
	/*00577210*/	push 0x1
	/*00577212*/	push 0x5
	/*00577214*/	push ebx
	/*00577215*/	push 0x8
	/*00577217*/	push 0x2
	/*00577219*/	push 0x4
	/*0057721B*/	push esi
	/*0057721C*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577221*/	push ebx
	/*00577222*/	push 0xFFFFFFFF
	/*00577224*/	push 0xFFFFFFFF
	/*00577226*/	push 0xFFFFFFFF
	/*00577228*/	push ebx
	/*00577229*/	push 0x4
	/*0057722B*/	push esi
	/*0057722C*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577231*/	mov dx,word ptr ds:[edi+0x40]
	/*00577235*/	add esp,0x40
	/*00577238*/	push ebx
	/*00577239*/	push edx
	/*0057723A*/	push 0x1
	/*0057723C*/	push 0x5
	/*0057723E*/	push ebx
	/*0057723F*/	push 0x8
	/*00577241*/	push 0x9
	/*00577243*/	push 0x5
	/*00577245*/	push esi
	/*00577246*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057724B*/	push ebx
	/*0057724C*/	push 0xFFFFFFFF
	/*0057724E*/	push 0xFFFFFFFF
	/*00577250*/	push 0xFFFFFFFF
	/*00577252*/	push ebx
	/*00577253*/	push 0x5
	/*00577255*/	push esi
	/*00577256*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057725B*/	mov ax,word ptr ds:[edi+0x40]
	/*0057725F*/	add esp,0x40
	/*00577262*/	push ebx
	/*00577263*/	push eax
	/*00577264*/	push 0x2
	/*00577266*/	push 0x2
	/*00577268*/	push ebx
	/*00577269*/	push 0x8
	/*0057726B*/	push 0xD
	/*0057726D*/	push 0x6
	/*0057726F*/	push esi
	/*00577270*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577275*/	push ebx
	/*00577276*/	push 0xFFFFFFFF
	/*00577278*/	push 0xFFFFFFFF
	/*0057727A*/	push 0xFFFFFFFF
	/*0057727C*/	push ebx
	/*0057727D*/	push 0x6
	/*0057727F*/	push esi
	/*00577280*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577285*/	mov cx,word ptr ds:[edi+0x40]
	/*00577289*/	add esp,0x40
	/*0057728C*/	push ebx
	/*0057728D*/	push ecx
	/*0057728E*/	push 0x1
	/*00577290*/	push 0x5
	/*00577292*/	push ebx
	/*00577293*/	push 0x8
	/*00577295*/	push 0x10
	/*00577297*/	push 0x7
	/*00577299*/	push esi
	/*0057729A*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057729F*/	push ebx
	/*005772A0*/	push 0xFFFFFFFF
	/*005772A2*/	push 0xFFFFFFFF
	/*005772A4*/	push 0xFFFFFFFF
	/*005772A6*/	push ebx
	/*005772A7*/	push 0x7
	/*005772A9*/	push esi
	/*005772AA*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005772AF*/	mov dx,word ptr ds:[edi+0x40]
	/*005772B3*/	add esp,0x40
	/*005772B6*/	push ebx
	/*005772B7*/	push edx
	/*005772B8*/	push 0x1
	/*005772BA*/	push 0x5
	/*005772BC*/	push ebx
	/*005772BD*/	push 0x8
	/*005772BF*/	push 0x17
	/*005772C1*/	push 0x8
	/*005772C3*/	push esi
	/*005772C4*/	call sub_68A160		/*call cm0102.68A160*/
	/*005772C9*/	push ebx
	/*005772CA*/	push 0xFFFFFFFF
	/*005772CC*/	push 0xFFFFFFFF
	/*005772CE*/	push 0xFFFFFFFF
	/*005772D0*/	push ebx
	/*005772D1*/	push 0x8
	/*005772D3*/	push esi
	/*005772D4*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005772D9*/	mov ax,word ptr ds:[edi+0x40]
	/*005772DD*/	add esp,0x40
	/*005772E0*/	push ebx
	/*005772E1*/	push eax
	/*005772E2*/	push 0x1
	/*005772E4*/	push 0x5
	/*005772E6*/	push ebx
	/*005772E7*/	push 0x8
	/*005772E9*/	push 0x1E
	/*005772EB*/	push 0x9
	/*005772ED*/	push esi
	/*005772EE*/	call sub_68A160		/*call cm0102.68A160*/
	/*005772F3*/	push ebx
	/*005772F4*/	push 0xFFFFFFFF
	/*005772F6*/	push 0xFFFFFFFF
	/*005772F8*/	push 0xFFFFFFFF
	/*005772FA*/	push ebx
	/*005772FB*/	push 0x9
	/*005772FD*/	push esi
	/*005772FE*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577303*/	mov cx,word ptr ds:[edi+0x40]
	/*00577307*/	add esp,0x40
	/*0057730A*/	push ebx
	/*0057730B*/	push ecx
	/*0057730C*/	push 0x1
	/*0057730E*/	push 0x5
	/*00577310*/	push ebx
	/*00577311*/	push 0x9
	/*00577313*/	push 0x7
	/*00577315*/	push 0xA
	/*00577317*/	push esi
	/*00577318*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057731D*/	push ebx
	/*0057731E*/	push 0xFFFFFFFF
	/*00577320*/	push 0xFFFFFFFF
	/*00577322*/	push 0xFFFFFFFF
	/*00577324*/	push ebx
	/*00577325*/	push 0xA
	/*00577327*/	push esi
	/*00577328*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057732D*/	mov dx,word ptr ds:[edi+0x40]
	/*00577331*/	add esp,0x40
	/*00577334*/	push ebx
	/*00577335*/	push edx
	/*00577336*/	push 0x1
	/*00577338*/	push 0x5
	/*0057733A*/	push ebx
	/*0057733B*/	push 0x9
	/*0057733D*/	push 0xE
	/*0057733F*/	push 0xB
	/*00577341*/	push esi
	/*00577342*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577347*/	push ebx
	/*00577348*/	push 0xFFFFFFFF
	/*0057734A*/	push 0xFFFFFFFF
	/*0057734C*/	push 0xFFFFFFFF
	/*0057734E*/	push ebx
	/*0057734F*/	push 0xB
	/*00577351*/	push esi
	/*00577352*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577357*/	mov ax,word ptr ds:[edi+0x40]
	/*0057735B*/	add esp,0x40
	/*0057735E*/	push ebx
	/*0057735F*/	push eax
	/*00577360*/	push 0x2
	/*00577362*/	push 0x1
	/*00577364*/	push ebx
	/*00577365*/	push 0x9
	/*00577367*/	push 0x11
	/*00577369*/	push 0xC
	/*0057736B*/	push esi
	/*0057736C*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577371*/	push ebx
	/*00577372*/	push 0xFFFFFFFF
	/*00577374*/	push 0xFFFFFFFF
	/*00577376*/	push 0xFFFFFFFF
	/*00577378*/	push ebx
	/*00577379*/	push 0xC
	/*0057737B*/	push esi
	/*0057737C*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577381*/	mov cx,word ptr ds:[edi+0x40]
	/*00577385*/	add esp,0x40
	/*00577388*/	push ebx
	/*00577389*/	push ecx
	/*0057738A*/	push 0x1
	/*0057738C*/	push 0x5
	/*0057738E*/	push ebx
	/*0057738F*/	push 0x9
	/*00577391*/	push 0x15
	/*00577393*/	push 0xD
	/*00577395*/	push esi
	/*00577396*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057739B*/	push ebx
	/*0057739C*/	push 0xFFFFFFFF
	/*0057739E*/	push 0xFFFFFFFF
	/*005773A0*/	push 0xFFFFFFFF
	/*005773A2*/	push ebx
	/*005773A3*/	push 0xD
	/*005773A5*/	push esi
	/*005773A6*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005773AB*/	mov dx,word ptr ds:[edi+0x40]
	/*005773AF*/	add esp,0x40
	/*005773B2*/	push ebx
	/*005773B3*/	push edx
	/*005773B4*/	push 0x2
	/*005773B6*/	push 0x1
	/*005773B8*/	push ebx
	/*005773B9*/	push 0x9
	/*005773BB*/	push 0x18
	/*005773BD*/	push 0xE
	/*005773BF*/	push esi
	/*005773C0*/	call sub_68A160		/*call cm0102.68A160*/
	/*005773C5*/	push ebx
	/*005773C6*/	push 0xFFFFFFFF
	/*005773C8*/	push 0xFFFFFFFF
	/*005773CA*/	push 0xFFFFFFFF
	/*005773CC*/	push ebx
	/*005773CD*/	push 0xE
	/*005773CF*/	push esi
	/*005773D0*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005773D5*/	mov ax,word ptr ds:[edi+0x40]
	/*005773D9*/	add esp,0x40
	/*005773DC*/	push ebx
	/*005773DD*/	push eax
	/*005773DE*/	push 0x1
	/*005773E0*/	push 0x5
	/*005773E2*/	push ebx
	/*005773E3*/	push 0x9
	/*005773E5*/	push 0x1C
	/*005773E7*/	push 0xF
	/*005773E9*/	push esi
	/*005773EA*/	call sub_68A160		/*call cm0102.68A160*/
	/*005773EF*/	push ebx
	/*005773F0*/	push 0xFFFFFFFF
	/*005773F2*/	push 0xFFFFFFFF
	/*005773F4*/	push 0xFFFFFFFF
	/*005773F6*/	push ebx
	/*005773F7*/	push 0xF
	/*005773F9*/	push esi
	/*005773FA*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005773FF*/	mov cx,word ptr ds:[edi+0x40]
	/*00577403*/	add esp,0x40
	/*00577406*/	push ebx
	/*00577407*/	push ecx
	/*00577408*/	push 0x1
	/*0057740A*/	push 0x5
	/*0057740C*/	push ebx
	/*0057740D*/	push 0xA
	/*0057740F*/	push 0x4
	/*00577411*/	push 0x10
	/*00577413*/	push esi
	/*00577414*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577419*/	push ebx
	/*0057741A*/	push 0xFFFFFFFF
	/*0057741C*/	push 0xFFFFFFFF
	/*0057741E*/	push 0xFFFFFFFF
	/*00577420*/	push ebx
	/*00577421*/	push 0x10
	/*00577423*/	push esi
	/*00577424*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577429*/	mov dx,word ptr ds:[edi+0x40]
	/*0057742D*/	add esp,0x40
	/*00577430*/	push ebx
	/*00577431*/	push edx
	/*00577432*/	push 0x1
	/*00577434*/	push 0x5
	/*00577436*/	push ebx
	/*00577437*/	push 0xA
	/*00577439*/	push 0xB
	/*0057743B*/	push 0x11
	/*0057743D*/	push esi
	/*0057743E*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577443*/	push ebx
	/*00577444*/	push 0xFFFFFFFF
	/*00577446*/	push 0xFFFFFFFF
	/*00577448*/	push 0xFFFFFFFF
	/*0057744A*/	push ebx
	/*0057744B*/	push 0x11
	/*0057744D*/	push esi
	/*0057744E*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577453*/	mov ax,word ptr ds:[edi+0x40]
	/*00577457*/	add esp,0x40
	/*0057745A*/	push ebx
	/*0057745B*/	push eax
	/*0057745C*/	push 0x1
	/*0057745E*/	push 0x5
	/*00577460*/	push ebx
	/*00577461*/	push 0xA
	/*00577463*/	push 0x12
	/*00577465*/	push 0x12
	/*00577467*/	push esi
	/*00577468*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057746D*/	push ebx
	/*0057746E*/	push 0xFFFFFFFF
	/*00577470*/	push 0xFFFFFFFF
	/*00577472*/	push 0xFFFFFFFF
	/*00577474*/	push ebx
	/*00577475*/	push 0x12
	/*00577477*/	push esi
	/*00577478*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057747D*/	mov cx,word ptr ds:[edi+0x40]
	/*00577481*/	add esp,0x40
	/*00577484*/	push ebx
	/*00577485*/	push ecx
	/*00577486*/	push 0x1
	/*00577488*/	push 0x5
	/*0057748A*/	push ebx
	/*0057748B*/	push 0xA
	/*0057748D*/	push 0x19
	/*0057748F*/	push 0x13
	/*00577491*/	push esi
	/*00577492*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577497*/	push ebx
	/*00577498*/	push 0xFFFFFFFF
	/*0057749A*/	push 0xFFFFFFFF
	/*0057749C*/	push 0xFFFFFFFF
	/*0057749E*/	push ebx
	/*0057749F*/	push 0x13
	/*005774A1*/	push esi
	/*005774A2*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005774A7*/	mov dx,word ptr ds:[edi+0x40]
	/*005774AB*/	add esp,0x40
	/*005774AE*/	push ebx
	/*005774AF*/	push edx
	/*005774B0*/	push 0x1
	/*005774B2*/	push 0x5
	/*005774B4*/	push ebx
	/*005774B5*/	push 0xB
	/*005774B7*/	push 0x2
	/*005774B9*/	push 0x14
	/*005774BB*/	push esi
	/*005774BC*/	call sub_68A160		/*call cm0102.68A160*/
	/*005774C1*/	push ebx
	/*005774C2*/	push 0xFFFFFFFF
	/*005774C4*/	push 0xFFFFFFFF
	/*005774C6*/	push 0xFFFFFFFF
	/*005774C8*/	push ebx
	/*005774C9*/	push 0x14
	/*005774CB*/	push esi
	/*005774CC*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005774D1*/	mov ax,word ptr ds:[edi+0x40]
	/*005774D5*/	add esp,0x40
	/*005774D8*/	push ebx
	/*005774D9*/	push eax
	/*005774DA*/	push 0x1
	/*005774DC*/	push 0x5
	/*005774DE*/	push ebx
	/*005774DF*/	push 0xB
	/*005774E1*/	push 0x9
	/*005774E3*/	push 0x15
	/*005774E5*/	push esi
	/*005774E6*/	call sub_68A160		/*call cm0102.68A160*/
	/*005774EB*/	push ebx
	/*005774EC*/	push 0xFFFFFFFF
	/*005774EE*/	push 0xFFFFFFFF
	/*005774F0*/	push 0xFFFFFFFF
	/*005774F2*/	push ebx
	/*005774F3*/	push 0x15
	/*005774F5*/	push esi
	/*005774F6*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005774FB*/	mov cx,word ptr ds:[edi+0x40]
	/*005774FF*/	add esp,0x40
	/*00577502*/	push ebx
	/*00577503*/	push ecx
	/*00577504*/	push 0x1
	/*00577506*/	push 0x5
	/*00577508*/	push ebx
	/*00577509*/	push 0xB
	/*0057750B*/	push 0x10
	/*0057750D*/	push 0x16
	/*0057750F*/	push esi
	/*00577510*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577515*/	push ebx
	/*00577516*/	push 0xFFFFFFFF
	/*00577518*/	push 0xFFFFFFFF
	/*0057751A*/	push 0xFFFFFFFF
	/*0057751C*/	push ebx
	/*0057751D*/	push 0x16
	/*0057751F*/	push esi
	/*00577520*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577525*/	mov dx,word ptr ds:[edi+0x40]
	/*00577529*/	add esp,0x40
	/*0057752C*/	lea ecx,dword ptr ss:[esp+0xC]
	/*00577530*/	push 0xFFFFFFFF
	/*00577532*/	push edx
	/*00577533*/	push 0xB
	/*00577535*/	push 0x1
	/*00577537*/	call sub_549F70		/*call cm0102.549F70*/
	/*0057753C*/	mov cx,word ptr ds:[esi+0x596]
	/*00577543*/	sub cx,word ptr ds:[eax]
	/*00577546*/	inc ecx
	/*00577547*/	movsx eax,cx
	/*0057754A*/	add eax,0xFFFFFFF3
	/*0057754D*/	cmp eax,0x6
	/*00577550*/	ja _0057794C
	/*00577556*/	jmp dword ptr ds:[eax*0x4+0x577F4C]
	/*0057755D*/	mov dx,word ptr ds:[edi+0x40]
	/*00577561*/	push ebx
	/*00577562*/	push edx
	/*00577563*/	push 0x1
	/*00577565*/	push 0xFFFFFFFF
	/*00577567*/	push ebx
	/*00577568*/	push 0xB
	/*0057756A*/	push 0x14
	/*0057756C*/	push 0x17
	/*0057756E*/	push esi
	/*0057756F*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577574*/	push ebx
	/*00577575*/	push 0xFFFFFFFF
	/*00577577*/	push 0xFFFFFFFF
	/*00577579*/	push 0xFFFFFFFF
	/*0057757B*/	push ebx
	/*0057757C*/	push 0x17
	/*0057757E*/	push esi
	/*0057757F*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577584*/	mov ax,word ptr ds:[edi+0x40]
	/*00577588*/	add esp,0x40
	/*0057758B*/	push ebx
	/*0057758C*/	push eax
	/*0057758D*/	push 0x1
	/*0057758F*/	push 0xFFFFFFFF
	/*00577591*/	push ebx
	/*00577592*/	push 0xB
	/*00577594*/	push 0x1B
	/*00577596*/	push 0x18
	/*00577598*/	push esi
	/*00577599*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057759E*/	push ebx
	/*0057759F*/	push 0xFFFFFFFF
	/*005775A1*/	push 0xFFFFFFFF
	/*005775A3*/	push 0xFFFFFFFF
	/*005775A5*/	push ebx
	/*005775A6*/	push 0x18
	/*005775A8*/	push esi
	/*005775A9*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005775AE*/	mov cx,word ptr ds:[edi+0x40]
	/*005775B2*/	add esp,0x40
	/*005775B5*/	push ebx
	/*005775B6*/	push ecx
	/*005775B7*/	push 0x2
	/*005775B9*/	push 0xFFFFFFFF
	/*005775BB*/	push ebx
	/*005775BC*/	push 0xB
	/*005775BE*/	push 0x1E
	/*005775C0*/	push 0x19
	/*005775C2*/	push esi
	/*005775C3*/	call sub_68A160		/*call cm0102.68A160*/
	/*005775C8*/	push ebx
	/*005775C9*/	push 0xFFFFFFFF
	/*005775CB*/	push 0xFFFFFFFF
	/*005775CD*/	push 0xFFFFFFFF
	/*005775CF*/	push ebx
	/*005775D0*/	push 0x19
	/*005775D2*/	push esi
	/*005775D3*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005775D8*/	mov dx,word ptr ds:[edi+0x40]
	/*005775DC*/	add esp,0x40
	/*005775DF*/	push ebx
	/*005775E0*/	push edx
	/*005775E1*/	push 0x1
	/*005775E3*/	push 0xFFFFFFFF
	/*005775E5*/	push 0x1
	/*005775E7*/	push ebx
	/*005775E8*/	push 0x3
	/*005775EA*/	jmp _0057792C
	/*005775EF*/	mov ax,word ptr ds:[edi+0x40]
	/*005775F3*/	push ebx
	/*005775F4*/	push eax
	/*005775F5*/	push 0x1
	/*005775F7*/	push 0xFFFFFFFF
	/*005775F9*/	push ebx
	/*005775FA*/	push 0xB
	/*005775FC*/	push 0x15
	/*005775FE*/	push 0x17
	/*00577600*/	push esi
	/*00577601*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577606*/	push ebx
	/*00577607*/	push 0xFFFFFFFF
	/*00577609*/	push 0xFFFFFFFF
	/*0057760B*/	push 0xFFFFFFFF
	/*0057760D*/	push ebx
	/*0057760E*/	push 0x17
	/*00577610*/	push esi
	/*00577611*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577616*/	mov cx,word ptr ds:[edi+0x40]
	/*0057761A*/	add esp,0x40
	/*0057761D*/	push ebx
	/*0057761E*/	push ecx
	/*0057761F*/	push 0x1
	/*00577621*/	push 0xFFFFFFFF
	/*00577623*/	push ebx
	/*00577624*/	push 0xB
	/*00577626*/	push 0x1A
	/*00577628*/	push 0x18
	/*0057762A*/	push esi
	/*0057762B*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577630*/	push ebx
	/*00577631*/	push 0xFFFFFFFF
	/*00577633*/	push 0xFFFFFFFF
	/*00577635*/	push 0xFFFFFFFF
	/*00577637*/	push ebx
	/*00577638*/	push 0x18
	/*0057763A*/	push esi
	/*0057763B*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577640*/	mov dx,word ptr ds:[edi+0x40]
	/*00577644*/	add esp,0x40
	/*00577647*/	push ebx
	/*00577648*/	push edx
	/*00577649*/	push 0x1
	/*0057764B*/	push 0xFFFFFFFF
	/*0057764D*/	push ebx
	/*0057764E*/	push 0xB
	/*00577650*/	push 0x1C
	/*00577652*/	push 0x19
	/*00577654*/	push esi
	/*00577655*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057765A*/	push ebx
	/*0057765B*/	push 0xFFFFFFFF
	/*0057765D*/	push 0xFFFFFFFF
	/*0057765F*/	push 0xFFFFFFFF
	/*00577661*/	push ebx
	/*00577662*/	push 0x19
	/*00577664*/	push esi
	/*00577665*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057766A*/	mov ax,word ptr ds:[edi+0x40]
	/*0057766E*/	add esp,0x40
	/*00577671*/	push ebx
	/*00577672*/	push eax
	/*00577673*/	push 0x1
	/*00577675*/	push 0xFFFFFFFF
	/*00577677*/	push 0x1
	/*00577679*/	push ebx
	/*0057767A*/	push 0x1
	/*0057767C*/	jmp _0057792C
	/*00577681*/	mov cx,word ptr ds:[edi+0x40]
	/*00577685*/	push ebx
	/*00577686*/	push ecx
	/*00577687*/	push 0x1
	/*00577689*/	push 0xFFFFFFFF
	/*0057768B*/	push ebx
	/*0057768C*/	push 0xB
	/*0057768E*/	push 0x16
	/*00577690*/	push 0x17
	/*00577692*/	push esi
	/*00577693*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577698*/	push ebx
	/*00577699*/	push 0xFFFFFFFF
	/*0057769B*/	push 0xFFFFFFFF
	/*0057769D*/	push 0xFFFFFFFF
	/*0057769F*/	push ebx
	/*005776A0*/	push 0x17
	/*005776A2*/	push esi
	/*005776A3*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005776A8*/	mov dx,word ptr ds:[edi+0x40]
	/*005776AC*/	add esp,0x40
	/*005776AF*/	push ebx
	/*005776B0*/	push edx
	/*005776B1*/	push 0x1
	/*005776B3*/	push 0xFFFFFFFF
	/*005776B5*/	push ebx
	/*005776B6*/	push 0xB
	/*005776B8*/	push 0x1A
	/*005776BA*/	push 0x18
	/*005776BC*/	push esi
	/*005776BD*/	call sub_68A160		/*call cm0102.68A160*/
	/*005776C2*/	push ebx
	/*005776C3*/	push 0xFFFFFFFF
	/*005776C5*/	push 0xFFFFFFFF
	/*005776C7*/	push 0xFFFFFFFF
	/*005776C9*/	push ebx
	/*005776CA*/	push 0x18
	/*005776CC*/	push esi
	/*005776CD*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005776D2*/	mov ax,word ptr ds:[edi+0x40]
	/*005776D6*/	add esp,0x40
	/*005776D9*/	push ebx
	/*005776DA*/	push eax
	/*005776DB*/	push 0x1
	/*005776DD*/	push 0xFFFFFFFF
	/*005776DF*/	push ebx
	/*005776E0*/	push 0xB
	/*005776E2*/	push 0x1D
_005776E4:
	/*005776E4*/	push 0x19
	/*005776E6*/	push esi
	/*005776E7*/	call sub_68A160		/*call cm0102.68A160*/
	/*005776EC*/	push ebx
	/*005776ED*/	push 0xFFFFFFFF
	/*005776EF*/	push 0xFFFFFFFF
	/*005776F1*/	push 0xFFFFFFFF
	/*005776F3*/	push ebx
	/*005776F4*/	push 0x19
	/*005776F6*/	push esi
	/*005776F7*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005776FC*/	mov cx,word ptr ds:[edi+0x40]
	/*00577700*/	add esp,0x40
	/*00577703*/	push ebx
	/*00577704*/	push ecx
	/*00577705*/	push 0x1
	/*00577707*/	push 0xFFFFFFFF
	/*00577709*/	push 0x1
	/*0057770B*/	push ebx
	/*0057770C*/	push 0x1
	/*0057770E*/	jmp _0057792C
	/*00577713*/	mov dx,word ptr ds:[edi+0x40]
	/*00577717*/	push ebx
	/*00577718*/	push edx
	/*00577719*/	push 0x1
	/*0057771B*/	push 0xFFFFFFFF
	/*0057771D*/	push ebx
	/*0057771E*/	push 0xB
	/*00577720*/	push 0x17
	/*00577722*/	push 0x17
	/*00577724*/	push esi
	/*00577725*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057772A*/	push ebx
	/*0057772B*/	push 0xFFFFFFFF
	/*0057772D*/	push 0xFFFFFFFF
	/*0057772F*/	push 0xFFFFFFFF
	/*00577731*/	push ebx
	/*00577732*/	push 0x17
	/*00577734*/	push esi
	/*00577735*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057773A*/	mov ax,word ptr ds:[edi+0x40]
	/*0057773E*/	add esp,0x40
	/*00577741*/	push ebx
	/*00577742*/	push eax
	/*00577743*/	push 0x1
	/*00577745*/	push 0xFFFFFFFF
	/*00577747*/	push ebx
	/*00577748*/	push 0xB
	/*0057774A*/	push 0x1A
	/*0057774C*/	push 0x18
	/*0057774E*/	push esi
	/*0057774F*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577754*/	push ebx
	/*00577755*/	push 0xFFFFFFFF
	/*00577757*/	push 0xFFFFFFFF
	/*00577759*/	push 0xFFFFFFFF
	/*0057775B*/	push ebx
	/*0057775C*/	push 0x18
	/*0057775E*/	push esi
	/*0057775F*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577764*/	mov cx,word ptr ds:[edi+0x40]
	/*00577768*/	add esp,0x40
	/*0057776B*/	push ebx
	/*0057776C*/	push ecx
	/*0057776D*/	push 0x1
	/*0057776F*/	push 0xFFFFFFFF
	/*00577771*/	push ebx
	/*00577772*/	push 0xB
	/*00577774*/	push 0x1E
	/*00577776*/	push 0x19
	/*00577778*/	push esi
	/*00577779*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057777E*/	push ebx
	/*0057777F*/	push 0xFFFFFFFF
	/*00577781*/	push 0xFFFFFFFF
	/*00577783*/	push 0xFFFFFFFF
	/*00577785*/	push ebx
	/*00577786*/	push 0x19
	/*00577788*/	push esi
	/*00577789*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057778E*/	mov dx,word ptr ds:[edi+0x40]
	/*00577792*/	add esp,0x40
	/*00577795*/	push ebx
	/*00577796*/	push edx
	/*00577797*/	push 0x1
	/*00577799*/	push 0xFFFFFFFF
	/*0057779B*/	push 0x1
	/*0057779D*/	push ebx
	/*0057779E*/	push 0x1
	/*005777A0*/	jmp _0057792C
	/*005777A5*/	mov ax,word ptr ds:[edi+0x40]
	/*005777A9*/	push ebx
	/*005777AA*/	push eax
	/*005777AB*/	push 0x2
	/*005777AD*/	push 0xFFFFFFFF
	/*005777AF*/	push ebx
	/*005777B0*/	push 0xB
	/*005777B2*/	push 0x15
	/*005777B4*/	push 0x17
	/*005777B6*/	push esi
	/*005777B7*/	call sub_68A160		/*call cm0102.68A160*/
	/*005777BC*/	push ebx
	/*005777BD*/	push 0xFFFFFFFF
	/*005777BF*/	push 0xFFFFFFFF
	/*005777C1*/	push 0xFFFFFFFF
	/*005777C3*/	push ebx
	/*005777C4*/	push 0x17
	/*005777C6*/	push esi
	/*005777C7*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005777CC*/	mov cx,word ptr ds:[edi+0x40]
	/*005777D0*/	add esp,0x40
	/*005777D3*/	push ebx
	/*005777D4*/	push ecx
	/*005777D5*/	push 0x1
	/*005777D7*/	push 0xFFFFFFFF
	/*005777D9*/	push ebx
	/*005777DA*/	push 0xB
	/*005777DC*/	push 0x1A
	/*005777DE*/	push 0x18
	/*005777E0*/	push esi
	/*005777E1*/	call sub_68A160		/*call cm0102.68A160*/
	/*005777E6*/	push ebx
	/*005777E7*/	push 0xFFFFFFFF
	/*005777E9*/	push 0xFFFFFFFF
	/*005777EB*/	push 0xFFFFFFFF
	/*005777ED*/	push ebx
	/*005777EE*/	push 0x18
	/*005777F0*/	push esi
	/*005777F1*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005777F6*/	mov dx,word ptr ds:[edi+0x40]
	/*005777FA*/	add esp,0x40
	/*005777FD*/	push ebx
	/*005777FE*/	push edx
	/*005777FF*/	push 0x1
	/*00577801*/	push 0xFFFFFFFF
	/*00577803*/	push ebx
	/*00577804*/	push 0xB
	/*00577806*/	push 0x1F
	/*00577808*/	push 0x19
	/*0057780A*/	push esi
	/*0057780B*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577810*/	push ebx
	/*00577811*/	push 0xFFFFFFFF
	/*00577813*/	push 0xFFFFFFFF
	/*00577815*/	push 0xFFFFFFFF
	/*00577817*/	push ebx
	/*00577818*/	push 0x19
	/*0057781A*/	push esi
	/*0057781B*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577820*/	mov ax,word ptr ds:[edi+0x40]
	/*00577824*/	add esp,0x40
	/*00577827*/	push ebx
	/*00577828*/	push eax
	/*00577829*/	push 0x2
	/*0057782B*/	push 0xFFFFFFFF
	/*0057782D*/	push 0x1
	/*0057782F*/	push ebx
	/*00577830*/	push 0x4
	/*00577832*/	jmp _0057792C
	/*00577837*/	mov cx,word ptr ds:[edi+0x40]
	/*0057783B*/	push ebx
	/*0057783C*/	push ecx
	/*0057783D*/	push 0x2
	/*0057783F*/	push 0xFFFFFFFF
	/*00577841*/	push ebx
	/*00577842*/	push 0xB
	/*00577844*/	push 0x16
	/*00577846*/	push 0x17
	/*00577848*/	push esi
	/*00577849*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057784E*/	push ebx
	/*0057784F*/	push 0xFFFFFFFF
	/*00577851*/	push 0xFFFFFFFF
	/*00577853*/	push 0xFFFFFFFF
	/*00577855*/	push ebx
	/*00577856*/	push 0x17
	/*00577858*/	push esi
	/*00577859*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057785E*/	mov dx,word ptr ds:[edi+0x40]
	/*00577862*/	add esp,0x40
	/*00577865*/	push ebx
	/*00577866*/	push edx
	/*00577867*/	push 0x1
	/*00577869*/	push 0xFFFFFFFF
	/*0057786B*/	push ebx
	/*0057786C*/	push 0xB
	/*0057786E*/	push 0x1A
	/*00577870*/	push 0x18
	/*00577872*/	push esi
	/*00577873*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577878*/	push ebx
	/*00577879*/	push 0xFFFFFFFF
	/*0057787B*/	push 0xFFFFFFFF
	/*0057787D*/	push 0xFFFFFFFF
	/*0057787F*/	push ebx
	/*00577880*/	push 0x18
	/*00577882*/	push esi
	/*00577883*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577888*/	mov ax,word ptr ds:[edi+0x40]
	/*0057788C*/	add esp,0x40
	/*0057788F*/	push ebx
	/*00577890*/	push eax
	/*00577891*/	push 0x2
	/*00577893*/	push 0xFFFFFFFF
	/*00577895*/	push ebx
	/*00577896*/	push 0xB
	/*00577898*/	push 0x1C
	/*0057789A*/	jmp _005776E4
	/*0057789F*/	mov dx,word ptr ds:[edi+0x40]
	/*005778A3*/	push ebx
	/*005778A4*/	push edx
	/*005778A5*/	push 0x1
	/*005778A7*/	push 0xFFFFFFFF
	/*005778A9*/	push ebx
	/*005778AA*/	push 0xB
	/*005778AC*/	push 0x1A
	/*005778AE*/	push 0x17
	/*005778B0*/	push esi
	/*005778B1*/	call sub_68A160		/*call cm0102.68A160*/
	/*005778B6*/	push ebx
	/*005778B7*/	push 0xFFFFFFFF
	/*005778B9*/	push 0xFFFFFFFF
	/*005778BB*/	push 0xFFFFFFFF
	/*005778BD*/	push ebx
	/*005778BE*/	push 0x17
	/*005778C0*/	push esi
	/*005778C1*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005778C6*/	mov ax,word ptr ds:[edi+0x40]
	/*005778CA*/	add esp,0x40
	/*005778CD*/	push ebx
	/*005778CE*/	push eax
	/*005778CF*/	push 0x2
	/*005778D1*/	push 0xFFFFFFFF
	/*005778D3*/	push ebx
	/*005778D4*/	push 0xB
	/*005778D6*/	push 0x1C
	/*005778D8*/	push 0x18
	/*005778DA*/	push esi
	/*005778DB*/	call sub_68A160		/*call cm0102.68A160*/
	/*005778E0*/	push ebx
	/*005778E1*/	push 0xFFFFFFFF
	/*005778E3*/	push 0xFFFFFFFF
	/*005778E5*/	push 0xFFFFFFFF
	/*005778E7*/	push ebx
	/*005778E8*/	push 0x18
	/*005778EA*/	push esi
	/*005778EB*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005778F0*/	mov cx,word ptr ds:[edi+0x40]
	/*005778F4*/	add esp,0x40
	/*005778F7*/	push ebx
	/*005778F8*/	push ecx
	/*005778F9*/	push 0x1
	/*005778FB*/	push 0xFFFFFFFF
	/*005778FD*/	push 0x1
	/*005778FF*/	push ebx
	/*00577900*/	push 0x2
	/*00577902*/	push 0x19
	/*00577904*/	push esi
	/*00577905*/	call sub_68A160		/*call cm0102.68A160*/
	/*0057790A*/	push ebx
	/*0057790B*/	push 0xFFFFFFFF
	/*0057790D*/	push 0xFFFFFFFF
	/*0057790F*/	push 0xFFFFFFFF
	/*00577911*/	push ebx
	/*00577912*/	push 0x19
	/*00577914*/	push esi
	/*00577915*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*0057791A*/	mov dx,word ptr ds:[edi+0x40]
	/*0057791E*/	add esp,0x40
	/*00577921*/	push ebx
	/*00577922*/	push edx
	/*00577923*/	push 0x2
	/*00577925*/	push 0xFFFFFFFF
	/*00577927*/	push 0x1
	/*00577929*/	push ebx
	/*0057792A*/	push 0x5
_0057792C:
	/*0057792C*/	push 0x1A
	/*0057792E*/	push esi
	/*0057792F*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577934*/	push ebx
	/*00577935*/	push 0xFFFFFFFF
	/*00577937*/	push 0xFFFFFFFF
	/*00577939*/	push 0xFFFFFFFF
	/*0057793B*/	push ebx
	/*0057793C*/	push 0x1A
	/*0057793E*/	push esi
	/*0057793F*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577944*/	add esp,0x40
	/*00577947*/	jmp _00577A4F
_0057794C:
	/*0057794C*/	lea eax,dword ptr ss:[esp+0x114]
	/*00577953*/	lea ecx,dword ptr ss:[esp+0x14]
	/*00577957*/	push eax
	/*00577958*/	push ecx
	/*00577959*/	push ebx
	/*0057795A*/	push ebx
	/*0057795B*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00577960*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00577965*/	add esp,0x14
	/*00577968*/	lea edx,dword ptr ss:[esp+0x114]
	/*0057796F*/	lea eax,dword ptr ss:[esp+0x14]
	/*00577973*/	push 0x161
	/*00577978*/	push edx
	/*00577979*/	push eax
	/*0057797A*/	call sub_90D130		/*call cm0102.90D130*/
	/*0057797F*/	push eax
	/*00577980*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00577985*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0057798A*/	call sub_944C9F_sprintf		/*call cm0102.944C9F*/
	/*0057798F*/	push ebx
	/*00577990*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00577995*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0057799A*/	call sub_5E8290		/*call cm0102.5E8290*/
	/*0057799F*/	mov dword ptr ds:[0xB67A34],ebx
	/*005779A5*/	mov cx,word ptr ds:[edi+0x40]
	/*005779A9*/	push ebx
	/*005779AA*/	push ecx
	/*005779AB*/	push 0x1
	/*005779AD*/	push 0x5
	/*005779AF*/	push ebx
	/*005779B0*/	push 0xB
	/*005779B2*/	push 0x1A
	/*005779B4*/	push 0x17
	/*005779B6*/	push esi
	/*005779B7*/	call sub_68A160		/*call cm0102.68A160*/
	/*005779BC*/	add esp,0x48
	/*005779BF*/	push ebx
	/*005779C0*/	push 0xFFFFFFFF
	/*005779C2*/	push 0xFFFFFFFF
	/*005779C4*/	push 0xFFFFFFFF
	/*005779C6*/	push ebx
	/*005779C7*/	push 0x17
	/*005779C9*/	push esi
	/*005779CA*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005779CF*/	mov dx,word ptr ds:[edi+0x40]
	/*005779D3*/	push ebx
	/*005779D4*/	push edx
	/*005779D5*/	push 0x2
	/*005779D7*/	push ebx
	/*005779D8*/	push ebx
	/*005779D9*/	push 0xB
	/*005779DB*/	push 0x1C
	/*005779DD*/	push 0x18
	/*005779DF*/	push esi
	/*005779E0*/	call sub_68A160		/*call cm0102.68A160*/
	/*005779E5*/	add esp,0x40
	/*005779E8*/	push ebx
	/*005779E9*/	push 0xFFFFFFFF
	/*005779EB*/	push 0xFFFFFFFF
	/*005779ED*/	push 0xFFFFFFFF
	/*005779EF*/	push ebx
	/*005779F0*/	push 0x18
	/*005779F2*/	push esi
	/*005779F3*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*005779F8*/	mov ax,word ptr ds:[edi+0x40]
	/*005779FC*/	push ebx
	/*005779FD*/	push eax
	/*005779FE*/	push 0x1
	/*00577A00*/	push 0xFFFFFFFF
	/*00577A02*/	push 0x1
	/*00577A04*/	push ebx
	/*00577A05*/	push 0x2
	/*00577A07*/	push 0x19
	/*00577A09*/	push esi
	/*00577A0A*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577A0F*/	add esp,0x40
	/*00577A12*/	push ebx
	/*00577A13*/	push 0xFFFFFFFF
	/*00577A15*/	push 0xFFFFFFFF
	/*00577A17*/	push 0xFFFFFFFF
	/*00577A19*/	push ebx
	/*00577A1A*/	push 0x19
	/*00577A1C*/	push esi
	/*00577A1D*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577A22*/	mov cx,word ptr ds:[edi+0x40]
	/*00577A26*/	push ebx
	/*00577A27*/	push ecx
	/*00577A28*/	push 0x2
	/*00577A2A*/	push 0xFFFFFFFF
	/*00577A2C*/	push 0x1
	/*00577A2E*/	push ebx
	/*00577A2F*/	push 0x5
	/*00577A31*/	push 0x1A
	/*00577A33*/	push esi
	/*00577A34*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577A39*/	add esp,0x40
	/*00577A3C*/	push ebx
	/*00577A3D*/	push 0xFFFFFFFF
	/*00577A3F*/	push 0xFFFFFFFF
	/*00577A41*/	push 0xFFFFFFFF
	/*00577A43*/	push ebx
	/*00577A44*/	push 0x1A
	/*00577A46*/	push esi
	/*00577A47*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577A4C*/	add esp,0x1C
_00577A4F:
	/*00577A4F*/	mov dx,word ptr ds:[edi+0x40]
	/*00577A53*/	push ebx
	/*00577A54*/	push edx
	/*00577A55*/	push 0x1
	/*00577A57*/	push 0x5
	/*00577A59*/	push 0x1
	/*00577A5B*/	push ebx
	/*00577A5C*/	push 0xD
	/*00577A5E*/	push 0x1B
	/*00577A60*/	push esi
	/*00577A61*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577A66*/	push ebx
	/*00577A67*/	push 0xFFFFFFFF
	/*00577A69*/	push 0xFFFFFFFF
	/*00577A6B*/	push 0xFFFFFFFF
	/*00577A6D*/	push ebx
	/*00577A6E*/	push 0x1B
	/*00577A70*/	push esi
	/*00577A71*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577A76*/	mov ax,word ptr ds:[edi+0x40]
	/*00577A7A*/	add esp,0x40
	/*00577A7D*/	push ebx
	/*00577A7E*/	push eax
	/*00577A7F*/	push 0x1
	/*00577A81*/	push 0x5
	/*00577A83*/	push 0x1
	/*00577A85*/	push ebx
	/*00577A86*/	push 0x14
	/*00577A88*/	push 0x1C
	/*00577A8A*/	push esi
	/*00577A8B*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577A90*/	push ebx
	/*00577A91*/	push 0xFFFFFFFF
	/*00577A93*/	push 0xFFFFFFFF
	/*00577A95*/	push 0xFFFFFFFF
	/*00577A97*/	push ebx
	/*00577A98*/	push 0x1C
	/*00577A9A*/	push esi
	/*00577A9B*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577AA0*/	mov cx,word ptr ds:[edi+0x40]
	/*00577AA4*/	add esp,0x40
	/*00577AA7*/	push ebx
	/*00577AA8*/	push ecx
	/*00577AA9*/	push 0x1
	/*00577AAB*/	push 0x5
	/*00577AAD*/	push 0x1
	/*00577AAF*/	push 0x1
	/*00577AB1*/	push 0x3
	/*00577AB3*/	push 0x1D
	/*00577AB5*/	push esi
	/*00577AB6*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577ABB*/	push ebx
	/*00577ABC*/	push 0xFFFFFFFF
	/*00577ABE*/	push 0xFFFFFFFF
	/*00577AC0*/	push 0xFFFFFFFF
	/*00577AC2*/	push ebx
	/*00577AC3*/	push 0x1D
	/*00577AC5*/	push esi
	/*00577AC6*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577ACB*/	mov dx,word ptr ds:[edi+0x40]
	/*00577ACF*/	add esp,0x40
	/*00577AD2*/	push ebx
	/*00577AD3*/	push edx
	/*00577AD4*/	push 0x1
	/*00577AD6*/	push 0x5
	/*00577AD8*/	push 0x1
	/*00577ADA*/	push 0x1
	/*00577ADC*/	push 0xA
	/*00577ADE*/	push 0x1E
	/*00577AE0*/	push esi
	/*00577AE1*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577AE6*/	push ebx
	/*00577AE7*/	push 0xFFFFFFFF
	/*00577AE9*/	push 0xFFFFFFFF
	/*00577AEB*/	push 0xFFFFFFFF
	/*00577AED*/	push ebx
	/*00577AEE*/	push 0x1E
	/*00577AF0*/	push esi
	/*00577AF1*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577AF6*/	add esp,0x40
	/*00577AF9*/	push ebx
	/*00577AFA*/	mov ax,word ptr ds:[edi+0x40]
	/*00577AFE*/	push eax
	/*00577AFF*/	push 0x1
	/*00577B01*/	push 0x5
	/*00577B03*/	push 0x1
	/*00577B05*/	push 0x1
	/*00577B07*/	push 0x11
	/*00577B09*/	push 0x1F
	/*00577B0B*/	push esi
	/*00577B0C*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577B11*/	push ebx
	/*00577B12*/	push 0xFFFFFFFF
	/*00577B14*/	push 0xFFFFFFFF
	/*00577B16*/	push 0xFFFFFFFF
	/*00577B18*/	push ebx
	/*00577B19*/	push 0x1F
	/*00577B1B*/	push esi
	/*00577B1C*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577B21*/	mov cx,word ptr ds:[edi+0x40]
	/*00577B25*/	add esp,0x40
	/*00577B28*/	push ebx
	/*00577B29*/	push ecx
	/*00577B2A*/	push 0x2
	/*00577B2C*/	push 0x1
	/*00577B2E*/	push 0x1
	/*00577B30*/	push 0x1
	/*00577B32*/	push 0x14
	/*00577B34*/	push 0x20
	/*00577B36*/	push esi
	/*00577B37*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577B3C*/	push ebx
	/*00577B3D*/	push 0xFFFFFFFF
	/*00577B3F*/	push 0xFFFFFFFF
	/*00577B41*/	push 0xFFFFFFFF
	/*00577B43*/	push ebx
	/*00577B44*/	push 0x20
	/*00577B46*/	push esi
	/*00577B47*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577B4C*/	mov dx,word ptr ds:[edi+0x40]
	/*00577B50*/	add esp,0x40
	/*00577B53*/	push ebx
	/*00577B54*/	push edx
	/*00577B55*/	push 0x1
	/*00577B57*/	push 0x5
	/*00577B59*/	push 0x1
	/*00577B5B*/	push 0x1
	/*00577B5D*/	push 0x18
	/*00577B5F*/	push 0x21
	/*00577B61*/	push esi
	/*00577B62*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577B67*/	push ebx
	/*00577B68*/	push 0xFFFFFFFF
	/*00577B6A*/	push 0xFFFFFFFF
	/*00577B6C*/	push 0xFFFFFFFF
	/*00577B6E*/	push ebx
	/*00577B6F*/	push 0x21
	/*00577B71*/	push esi
	/*00577B72*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577B77*/	mov ax,word ptr ds:[edi+0x40]
	/*00577B7B*/	add esp,0x40
	/*00577B7E*/	push ebx
	/*00577B7F*/	push eax
	/*00577B80*/	push 0x1
	/*00577B82*/	push 0x5
	/*00577B84*/	push 0x1
	/*00577B86*/	push 0x2
	/*00577B88*/	push 0x3
	/*00577B8A*/	push 0x22
	/*00577B8C*/	push esi
	/*00577B8D*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577B92*/	push ebx
	/*00577B93*/	push 0xFFFFFFFF
	/*00577B95*/	push 0xFFFFFFFF
	/*00577B97*/	push 0xFFFFFFFF
	/*00577B99*/	push ebx
	/*00577B9A*/	push 0x22
	/*00577B9C*/	push esi
	/*00577B9D*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577BA2*/	mov cx,word ptr ds:[edi+0x40]
	/*00577BA6*/	add esp,0x40
	/*00577BA9*/	push ebx
	/*00577BAA*/	push ecx
	/*00577BAB*/	push 0x2
	/*00577BAD*/	push 0x2
	/*00577BAF*/	push 0x1
	/*00577BB1*/	push 0x2
	/*00577BB3*/	push 0x7
	/*00577BB5*/	push 0x23
	/*00577BB7*/	push esi
	/*00577BB8*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577BBD*/	push ebx
	/*00577BBE*/	push 0xFFFFFFFF
	/*00577BC0*/	push 0xFFFFFFFF
	/*00577BC2*/	push 0xFFFFFFFF
	/*00577BC4*/	push ebx
	/*00577BC5*/	push 0x23
	/*00577BC7*/	push esi
	/*00577BC8*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577BCD*/	mov dx,word ptr ds:[edi+0x40]
	/*00577BD1*/	add esp,0x40
	/*00577BD4*/	push ebx
	/*00577BD5*/	push edx
	/*00577BD6*/	push 0x1
	/*00577BD8*/	push 0x5
	/*00577BDA*/	push 0x1
	/*00577BDC*/	push 0x2
	/*00577BDE*/	push 0xA
	/*00577BE0*/	push 0x24
	/*00577BE2*/	push esi
	/*00577BE3*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577BE8*/	push ebx
	/*00577BE9*/	push 0xFFFFFFFF
	/*00577BEB*/	push 0xFFFFFFFF
	/*00577BED*/	push 0xFFFFFFFF
	/*00577BEF*/	push ebx
	/*00577BF0*/	push 0x24
	/*00577BF2*/	push esi
	/*00577BF3*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577BF8*/	mov ax,word ptr ds:[edi+0x40]
	/*00577BFC*/	add esp,0x40
	/*00577BFF*/	push ebx
	/*00577C00*/	push eax
	/*00577C01*/	push 0x2
	/*00577C03*/	push 0x1
	/*00577C05*/	push 0x1
	/*00577C07*/	push 0x2
	/*00577C09*/	push 0x11
	/*00577C0B*/	push 0x25
	/*00577C0D*/	push esi
	/*00577C0E*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577C13*/	push ebx
	/*00577C14*/	push 0xFFFFFFFF
	/*00577C16*/	push 0xFFFFFFFF
	/*00577C18*/	push 0xFFFFFFFF
	/*00577C1A*/	push ebx
	/*00577C1B*/	push 0x25
	/*00577C1D*/	push esi
	/*00577C1E*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577C23*/	mov cx,word ptr ds:[edi+0x40]
	/*00577C27*/	add esp,0x40
	/*00577C2A*/	push ebx
	/*00577C2B*/	push ecx
	/*00577C2C*/	push 0x1
	/*00577C2E*/	push 0x5
	/*00577C30*/	push 0x1
	/*00577C32*/	push 0x2
	/*00577C34*/	push 0x18
	/*00577C36*/	push 0x26
	/*00577C38*/	push esi
	/*00577C39*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577C3E*/	push ebx
	/*00577C3F*/	push 0xFFFFFFFF
	/*00577C41*/	push 0xFFFFFFFF
	/*00577C43*/	push 0xFFFFFFFF
	/*00577C45*/	push ebx
	/*00577C46*/	push 0x26
	/*00577C48*/	push esi
	/*00577C49*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577C4E*/	mov dx,word ptr ds:[edi+0x40]
	/*00577C52*/	add esp,0x40
	/*00577C55*/	push ebx
	/*00577C56*/	push edx
	/*00577C57*/	push 0x1
	/*00577C59*/	push 0x5
	/*00577C5B*/	push 0x1
	/*00577C5D*/	push 0x2
	/*00577C5F*/	push 0x1F
	/*00577C61*/	push 0x27
	/*00577C63*/	push esi
	/*00577C64*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577C69*/	push ebx
	/*00577C6A*/	push 0xFFFFFFFF
	/*00577C6C*/	push 0xFFFFFFFF
	/*00577C6E*/	push 0xFFFFFFFF
	/*00577C70*/	push ebx
	/*00577C71*/	push 0x27
	/*00577C73*/	push esi
	/*00577C74*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577C79*/	mov ax,word ptr ds:[edi+0x40]
	/*00577C7D*/	add esp,0x40
	/*00577C80*/	push ebx
	/*00577C81*/	push eax
	/*00577C82*/	push 0x1
	/*00577C84*/	push 0x5
	/*00577C86*/	push 0x1
	/*00577C88*/	push 0x3
	/*00577C8A*/	push 0x7
	/*00577C8C*/	push 0x28
	/*00577C8E*/	push esi
	/*00577C8F*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577C94*/	push ebx
	/*00577C95*/	push 0xFFFFFFFF
	/*00577C97*/	push 0xFFFFFFFF
	/*00577C99*/	push 0xFFFFFFFF
	/*00577C9B*/	push ebx
	/*00577C9C*/	push 0x28
	/*00577C9E*/	push esi
	/*00577C9F*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577CA4*/	mov cx,word ptr ds:[edi+0x40]
	/*00577CA8*/	add esp,0x40
	/*00577CAB*/	push ebx
	/*00577CAC*/	push ecx
	/*00577CAD*/	push 0x1
	/*00577CAF*/	push 0x5
	/*00577CB1*/	push 0x1
	/*00577CB3*/	push 0x3
	/*00577CB5*/	push 0xE
	/*00577CB7*/	push 0x29
	/*00577CB9*/	push esi
	/*00577CBA*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577CBF*/	push ebx
	/*00577CC0*/	push 0xFFFFFFFF
	/*00577CC2*/	push 0xFFFFFFFF
	/*00577CC4*/	push 0xFFFFFFFF
	/*00577CC6*/	push ebx
	/*00577CC7*/	push 0x29
	/*00577CC9*/	push esi
	/*00577CCA*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577CCF*/	mov dx,word ptr ds:[edi+0x40]
	/*00577CD3*/	add esp,0x40
	/*00577CD6*/	push ebx
	/*00577CD7*/	push edx
	/*00577CD8*/	push 0x2
	/*00577CDA*/	push ebx
	/*00577CDB*/	push 0x1
	/*00577CDD*/	push 0x3
	/*00577CDF*/	push 0x10
	/*00577CE1*/	push 0x2A
	/*00577CE3*/	push esi
	/*00577CE4*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577CE9*/	push ebx
	/*00577CEA*/	push 0xFFFFFFFF
	/*00577CEC*/	push 0xFFFFFFFF
	/*00577CEE*/	push 0xFFFFFFFF
	/*00577CF0*/	push ebx
	/*00577CF1*/	push 0x2A
	/*00577CF3*/	push esi
	/*00577CF4*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577CF9*/	mov ax,word ptr ds:[edi+0x40]
	/*00577CFD*/	add esp,0x40
	/*00577D00*/	push ebx
	/*00577D01*/	push eax
	/*00577D02*/	push 0x1
	/*00577D04*/	push 0x5
	/*00577D06*/	push 0x1
	/*00577D08*/	push 0x3
	/*00577D0A*/	push 0x15
	/*00577D0C*/	push 0x2B
	/*00577D0E*/	push esi
	/*00577D0F*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577D14*/	push ebx
	/*00577D15*/	push 0xFFFFFFFF
	/*00577D17*/	push 0xFFFFFFFF
	/*00577D19*/	push 0xFFFFFFFF
	/*00577D1B*/	push ebx
	/*00577D1C*/	push 0x2B
	/*00577D1E*/	push esi
	/*00577D1F*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577D24*/	mov cx,word ptr ds:[edi+0x40]
	/*00577D28*/	add esp,0x40
	/*00577D2B*/	push ebx
	/*00577D2C*/	push ecx
	/*00577D2D*/	push 0x1
	/*00577D2F*/	push 0x5
	/*00577D31*/	push 0x1
	/*00577D33*/	push 0x3
	/*00577D35*/	push 0x1C
	/*00577D37*/	push 0x2C
	/*00577D39*/	push esi
	/*00577D3A*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577D3F*/	push ebx
	/*00577D40*/	push 0xFFFFFFFF
	/*00577D42*/	push 0xFFFFFFFF
	/*00577D44*/	push 0xFFFFFFFF
	/*00577D46*/	push ebx
	/*00577D47*/	push 0x2C
	/*00577D49*/	push esi
	/*00577D4A*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577D4F*/	mov dx,word ptr ds:[edi+0x40]
	/*00577D53*/	add esp,0x40
	/*00577D56*/	push ebx
	/*00577D57*/	push edx
	/*00577D58*/	push 0x1
	/*00577D5A*/	push 0x6
	/*00577D5C*/	push 0x1
	/*00577D5E*/	push 0x4
	/*00577D60*/	push 0x6
	/*00577D62*/	push 0x2D
	/*00577D64*/	push esi
	/*00577D65*/	call sub_68A160		/*call cm0102.68A160*/
	/*00577D6A*/	push ebx
	/*00577D6B*/	push 0xFFFFFFFF
	/*00577D6D*/	push 0xFFFFFFFF
	/*00577D6F*/	push 0xFFFFFFFF
	/*00577D71*/	push ebx
	/*00577D72*/	push 0x2D
	/*00577D74*/	push esi
	/*00577D75*/	call sub_68A1C0		/*call cm0102.68A1C0*/
	/*00577D7A*/	add esp,0x40
	/*00577D7D*/	mov eax,esi
	/*00577D7F*/	pop edi
	/*00577D80*/	pop esi
	/*00577D81*/	pop ebx
	/*00577D82*/	add esp,0x208
	/*00577D88*/	ret 0x10
_00577D8B:
	/*00577D8B*/	xor ebx,ebx
	/*00577D8D*/	cmp al,bl
	/*00577D8F*/	jne _00577E29
	/*00577D95*/	mov eax,dword ptr ss:[esp+0x224]
	/*00577D9C*/	cmp eax,ebx
	/*00577D9E*/	je _00577DA2
	/*00577DA0*/	mov dword ptr ds:[eax],ebx
_00577DA2:
	/*00577DA2*/	mov eax,dword ptr ss:[esp+0x21C]
	/*00577DA9*/	mov ecx,dword ptr ss:[esp+0x220]
	/*00577DB0*/	push 0xD0
	/*00577DB5*/	mov word ptr ds:[eax],0x2
	/*00577DBA*/	mov word ptr ds:[ecx],0xA0
	/*00577DBF*/	call sub_944E46_malloc		/*call cm0102.944E46*/
	/*00577DC4*/	mov esi,eax
	/*00577DC6*/	add esp,0x4
	/*00577DC9*/	cmp esi,ebx
	/*00577DCB*/	jne _00577E37
	/*00577DCD*/	lea edx,dword ptr ss:[esp+0x114]
	/*00577DD4*/	lea eax,dword ptr ss:[esp+0x14]
	/*00577DD8*/	push edx
	/*00577DD9*/	push eax
	/*00577DDA*/	push ebx
	/*00577DDB*/	push ebx
	/*00577DDC*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00577DE1*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00577DE6*/	add esp,0x14
	/*00577DE9*/	lea ecx,dword ptr ss:[esp+0x114]
	/*00577DF0*/	lea edx,dword ptr ss:[esp+0x14]
	/*00577DF4*/	push 0x1BA
	/*00577DF9*/	push ecx
_00577DFA:
	/*00577DFA*/	push edx
	/*00577DFB*/	call sub_90D130		/*call cm0102.90D130*/
	/*00577E00*/	push eax
	/*00577E01*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00577E06*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00577E0B*/	call sub_944C9F_sprintf		/*call cm0102.944C9F*/
	/*00577E10*/	push ebx
	/*00577E11*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00577E16*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00577E1B*/	call sub_5E8290		/*call cm0102.5E8290*/
	/*00577E20*/	add esp,0x24
	/*00577E23*/	mov dword ptr ds:[0xB67A34],ebx
_00577E29:
	/*00577E29*/	pop edi
	/*00577E2A*/	pop esi
	/*00577E2B*/	xor eax,eax
	/*00577E2D*/	pop ebx
	/*00577E2E*/	add esp,0x208
	/*00577E34*/	ret 0x10
_00577E37:
	/*00577E37*/	movsx eax,word ptr ds:[edi+0x40]
	/*00577E3B*/	push eax
	/*00577E3C*/	push ebx
	/*00577E3D*/	push 0x1
	/*00577E3F*/	push 0x4
	/*00577E41*/	push 0x7
	/*00577E43*/	push ebx
	/*00577E44*/	push esi
	/*00577E45*/	call sub_521E60		/*call cm0102.521E60*/
	/*00577E4A*/	movsx ecx,word ptr ds:[edi+0x40]
	/*00577E4E*/	push ebx
	/*00577E4F*/	push ecx
	/*00577E50*/	push 0x1
	/*00577E52*/	push 0x5
	/*00577E54*/	push 0x1
	/*00577E56*/	push 0x4
	/*00577E58*/	push 0xC
	/*00577E5A*/	push ebx
	/*00577E5B*/	push esi
	/*00577E5C*/	call sub_521EB0		/*call cm0102.521EB0*/
	/*00577E61*/	mov word ptr ds:[esi+0x7],0x82
	/*00577E67*/	mov word ptr ds:[esi+0x9],bx
	/*00577E6B*/	mov word ptr ds:[esi+0xB],bx
	/*00577E6F*/	mov word ptr ds:[esi+0xD],0x204
	/*00577E75*/	mov byte ptr ds:[esi+0x17],0x5
	/*00577E79*/	mov word ptr ds:[esi+0x18],0x4
	/*00577E7F*/	mov word ptr ds:[esi+0x1A],0x2
	/*00577E85*/	mov word ptr ds:[esi+0x1C],0x4
	/*00577E8B*/	mov word ptr ds:[esi+0xF],0x3
	/*00577E91*/	mov word ptr ds:[esi+0x1E],bx
	/*00577E95*/	mov byte ptr ds:[esi+0x20],bl
	/*00577E98*/	mov byte ptr ds:[esi+0x21],0x2
	/*00577E9C*/	mov byte ptr ds:[esi+0x22],0x4
	/*00577EA0*/	mov dword ptr ds:[esi+0x5C],ebx
	/*00577EA3*/	mov dword ptr ds:[esi+0x60],ebx
	/*00577EA6*/	mov dword ptr ds:[esi+0x64],ebx
	/*00577EA9*/	movsx edx,word ptr ds:[edi+0x40]
	/*00577EAD*/	add esp,0x40
	/*00577EB0*/	push edx
	/*00577EB1*/	push 0x3
	/*00577EB3*/	push 0x1
	/*00577EB5*/	push 0x4
	/*00577EB7*/	push 0x11
	/*00577EB9*/	push 0x1
	/*00577EBB*/	push esi
	/*00577EBC*/	call sub_521E60		/*call cm0102.521E60*/
	/*00577EC1*/	movsx eax,word ptr ds:[edi+0x40]
	/*00577EC5*/	push 0x4
	/*00577EC7*/	mov edi,0x1
	/*00577ECC*/	push eax
	/*00577ECD*/	push edi
	/*00577ECE*/	push 0x5
	/*00577ED0*/	push edi
	/*00577ED1*/	push 0x4
	/*00577ED3*/	push 0x1A
	/*00577ED5*/	push edi
	/*00577ED6*/	push esi
	/*00577ED7*/	call sub_521EB0		/*call cm0102.521EB0*/
	/*00577EDC*/	add esp,0x40
	/*00577EDF*/	mov word ptr ds:[esi+0x71],di
	/*00577EE3*/	mov word ptr ds:[esi+0x82],di
	/*00577EEA*/	mov word ptr ds:[esi+0x6F],0x96
	/*00577EF0*/	mov word ptr ds:[esi+0x73],bx
	/*00577EF4*/	mov word ptr ds:[esi+0x75],0x3
	/*00577EFA*/	mov byte ptr ds:[esi+0x7F],0x5
	/*00577EFE*/	mov word ptr ds:[esi+0x80],0x2
	/*00577F07*/	mov word ptr ds:[esi+0x84],bx
	/*00577F0E*/	mov word ptr ds:[esi+0x77],bx
	/*00577F12*/	mov word ptr ds:[esi+0x86],bx
	/*00577F19*/	mov byte ptr ds:[esi+0x88],bl
	/*00577F1F*/	mov byte ptr ds:[esi+0x89],0x1
	/*00577F26*/	mov byte ptr ds:[esi+0x8A],bl
	/*00577F2C*/	mov dword ptr ds:[esi+0xC4],ebx
	/*00577F32*/	mov dword ptr ds:[esi+0xC8],ebx
	/*00577F38*/	mov dword ptr ds:[esi+0xCC],ebx
	/*00577F3E*/	mov eax,esi
	/*00577F40*/	pop edi
	/*00577F41*/	pop esi
	/*00577F42*/	pop ebx
	/*00577F43*/	add esp,0x208
	/*00577F49*/	ret 0x10
	}
}

void __declspec(naked) sub_577F70()
{
	__asm
	{
	/*00577F70*/	sub esp,0x200
	/*00577F76*/	push ebx
	/*00577F77*/	push ebp
	/*00577F78*/	push esi
	/*00577F79*/	mov esi,ecx
	/*00577F7B*/	push 0x588
	/*00577F80*/	xor bl,bl
	/*00577F82*/	mov word ptr ds:[esi+0x3E],0x18
	/*00577F88*/	call sub_944E46_malloc		/*call cm0102.944E46*/
	/*00577F8D*/	xor ebp,ebp
	/*00577F8F*/	add esp,0x4
	/*00577F92*/	cmp eax,ebp
	/*00577F94*/	mov dword ptr ds:[esi+0xB1],eax
	/*00577F9A*/	jne _00578004
	/*00577F9C*/	lea eax,dword ptr ss:[esp+0xC]
	/*00577FA0*/	lea ecx,dword ptr ss:[esp+0x10C]
	/*00577FA7*/	push eax
	/*00577FA8*/	push ecx
	/*00577FA9*/	push ebp
	/*00577FAA*/	push ebp
	/*00577FAB*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00577FB0*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00577FB5*/	add esp,0x14
	/*00577FB8*/	lea edx,dword ptr ss:[esp+0xC]
	/*00577FBC*/	lea eax,dword ptr ss:[esp+0x10C]
	/*00577FC3*/	push 0x1FA
	/*00577FC8*/	push edx
	/*00577FC9*/	push eax
	/*00577FCA*/	call sub_90D130		/*call cm0102.90D130*/
	/*00577FCF*/	push eax
	/*00577FD0*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00577FD5*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00577FDA*/	call sub_944C9F_sprintf		/*call cm0102.944C9F*/
	/*00577FDF*/	push ebp
	/*00577FE0*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00577FE5*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00577FEA*/	call sub_5E8290		/*call cm0102.5E8290*/
	/*00577FEF*/	add esp,0x24
	/*00577FF2*/	mov dword ptr ds:[0xB67A34],ebp
	/*00577FF8*/	xor eax,eax
	/*00577FFA*/	pop esi
	/*00577FFB*/	pop ebp
	/*00577FFC*/	pop ebx
	/*00577FFD*/	add esp,0x200
	/*00578003*/	ret
_00578004:
	/*00578004*/	mov eax,dword ptr ds:[0xAE235C]
	/*00578009*/	push edi
	/*0057800A*/	mov edi,dword ptr ds:[0xAE23B4]
	/*00578010*/	test eax,eax
	/*00578012*/	jle _00578055
_00578014:
	/*00578014*/	mov eax,dword ptr ds:[edi+0x57]
	/*00578017*/	test eax,eax
	/*00578019*/	je _00578041
	/*0057801B*/	mov ecx,dword ptr ds:[eax]
	/*0057801D*/	mov eax,dword ptr ds:[0x9CF5C8]
	/*00578022*/	cmp ecx,eax
	/*00578024*/	jne _00578041
	/*00578026*/	push 0x0
	/*00578028*/	mov al,bl
	/*0057802A*/	push 0x0
	/*0057802C*/	push edi
	/*0057802D*/	push eax
	/*0057802E*/	mov ecx,esi
	/*00578030*/	inc bl
	/*00578032*/	call sub_687430		/*call cm0102.687430*/
	/*00578037*/	movsx dx,bl
	/*0057803B*/	cmp dx,word ptr ds:[esi+0x3E]
	/*0057803F*/	je _00578055
_00578041:
	/*00578041*/	mov ecx,dword ptr ds:[0xAE235C]
	/*00578047*/	inc ebp
	/*00578048*/	movsx eax,bp
	/*0057804B*/	add edi,0x245
	/*00578051*/	cmp eax,ecx
	/*00578053*/	jl _00578014
_00578055:
	/*00578055*/	movsx cx,bl
	/*00578059*/	cmp cx,word ptr ds:[esi+0x3E]
	/*0057805D*/	pop edi
	/*0057805E*/	je _0057806C
	/*00578060*/	pop esi
	/*00578061*/	pop ebp
	/*00578062*/	xor eax,eax
	/*00578064*/	pop ebx
	/*00578065*/	add esp,0x200
	/*0057806B*/	ret
_0057806C:
	/*0057806C*/	push 0x2710
	/*00578071*/	mov ecx,esi
	/*00578073*/	call sub_682F70		/*call cm0102.682F70*/
	/*00578078*/	mov dword ptr ds:[esi+0x28],eax
	/*0057807B*/	mov byte ptr ds:[esi+0xE1],0x1
	/*00578082*/	cmp word ptr ds:[0xAE2C92],0x7CF
	/*0057808B*/	push 0x0
	/*0057808D*/	jbe _00578096
	/*0057808F*/	push 0xF4240
	/*00578094*/	jmp _0057809B
_00578096:
	/*00578096*/	push 0x30D40
_0057809B:
	/*0057809B*/	mov ecx,esi
	/*0057809D*/	call sub_683010		/*call cm0102.683010*/
	/*005780A2*/	pop esi
	/*005780A3*/	pop ebp
	/*005780A4*/	mov eax,0x1
	/*005780A9*/	pop ebx
	/*005780AA*/	add esp,0x200
	/*005780B0*/	ret
	}
}

void __declspec(naked) sub_5780C0()
{
	__asm
	{
	/*005780C0*/	push ebx
	/*005780C1*/	push esi
	/*005780C2*/	mov esi,ecx
	/*005780C4*/	mov al,0x3
	/*005780C6*/	mov ecx,0x2
	/*005780CB*/	mov ebx,0x1
	/*005780D0*/	mov dl,0x4
	/*005780D2*/	push edi
	/*005780D3*/	mov word ptr ds:[esi+0x3C],cx
	/*005780D7*/	mov byte ptr ds:[esi+0xC2],al
	/*005780DD*/	mov byte ptr ds:[esi+0xC3],bl
	/*005780E3*/	mov byte ptr ds:[esi+0xC4],cl
	/*005780E9*/	mov byte ptr ds:[esi+0x42],bl
	/*005780EC*/	mov byte ptr ds:[esi+0xC5],bl
	/*005780F2*/	mov byte ptr ds:[esi+0xC6],cl
	/*005780F8*/	mov byte ptr ds:[esi+0xC7],al
	/*005780FE*/	mov byte ptr ds:[esi+0xBE],al
	/*00578104*/	mov byte ptr ds:[esi+0xBF],dl
	/*0057810A*/	mov byte ptr ds:[esi+0xC0],0x0
	/*00578111*/	mov byte ptr ds:[esi+0xC1],bl
	/*00578117*/	mov edi,dword ptr ds:[0x9CF5C4]
	/*0057811D*/	mov dword ptr ds:[esi+0x1C],edi
	/*00578120*/	mov edi,dword ptr ds:[esi+0x4]
	/*00578123*/	mov edi,dword ptr ds:[edi+0x5D]
	/*00578126*/	test byte ptr ds:[edi+0x11C],dl
	/*0057812C*/	je _00578139
	/*0057812E*/	mov edx,dword ptr ds:[0x9CF69C]
	/*00578134*/	mov dword ptr ds:[esi+0x20],edx
	/*00578137*/	jmp _00578140
_00578139:
	/*00578139*/	mov dword ptr ds:[esi+0x20],0xFFFFFFFF
_00578140:
	/*00578140*/	mov byte ptr ds:[esi+0x52],cl
	/*00578143*/	lea ecx,dword ptr ds:[esi+0x3A]
	/*00578146*/	push 0x0
	/*00578148*/	lea edx,dword ptr ds:[esi+0xA9]
	/*0057814E*/	mov byte ptr ds:[esi+0x4A],al
	/*00578151*/	mov eax,dword ptr ds:[esi]
	/*00578153*/	push ecx
	/*00578154*/	push edx
	/*00578155*/	push 0xFFFFFFFF
	/*00578157*/	mov ecx,esi
	/*00578159*/	mov byte ptr ds:[esi+0x49],0x5
	/*0057815D*/	call dword ptr ds:[eax+0x3C]
	/*00578160*/	mov dword ptr ds:[esi+0xBA],eax
	/*00578166*/	pop edi
	/*00578167*/	mov eax,ebx
	/*00578169*/	pop esi
	/*0057816A*/	pop ebx
	/*0057816B*/	ret
	}
}

void __declspec(naked) sub_578170()
{
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
	/*005781DD*/	call dword ptr ds:[eax+0x8C]
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
	/*0057821C*/	call sub_577F70		/*call cm0102.577F70*/
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

void __declspec(naked) sub_578330()
{
	__asm
	{
	/*00578330*/	mov edx,dword ptr ds:[ecx+0x2C]
	/*00578333*/	mov eax,dword ptr ds:[ecx+0x30]
	/*00578336*/	sub esp,0x200
	/*0057833C*/	dec edx
	/*0057833D*/	cmp eax,edx
	/*0057833F*/	jl _005783AB
	/*00578341*/	lea eax,dword ptr ss:[esp]
	/*00578345*/	lea ecx,dword ptr ss:[esp+0x100]
	/*0057834C*/	push eax
	/*0057834D*/	push ecx
	/*0057834E*/	push 0x0
	/*00578350*/	push 0x0
	/*00578352*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*00578357*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*0057835C*/	add esp,0x14
	/*0057835F*/	lea edx,dword ptr ss:[esp]
	/*00578363*/	lea eax,dword ptr ss:[esp+0x100]
	/*0057836A*/	push 0x29C
	/*0057836F*/	push edx
	/*00578370*/	push eax
	/*00578371*/	call sub_90D130		/*call cm0102.90D130*/
	/*00578376*/	push eax
	/*00578377*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*0057837C*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00578381*/	call sub_944C9F_sprintf		/*call cm0102.944C9F*/
	/*00578386*/	push 0x0
	/*00578388*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0057838D*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00578392*/	call sub_5E8290		/*call cm0102.5E8290*/
	/*00578397*/	add esp,0x24
	/*0057839A*/	mov dword ptr ds:[0xB67A34],0x0
	/*005783A4*/	add esp,0x200
	/*005783AA*/	ret
_005783AB:
	/*005783AB*/	inc eax
	/*005783AC*/	test eax,eax
	/*005783AE*/	mov dword ptr ds:[ecx+0x30],eax
	/*005783B1*/	jne _005783B8
	/*005783B3*/	call sub_5783C0		/*call cm0102.5783C0*/
_005783B8:
	/*005783B8*/	add esp,0x200
	/*005783BE*/	ret
	/*005783BF*/	nop
	/*005783C0*/	mov eax,dword ptr fs:[0x0]
	/*005783C6*/	push 0xFFFFFFFF
	/*005783C8*/	push 0x9584CE		/*push cm0102.9584CE*/
	/*005783CD*/	push eax
	/*005783CE*/	mov dword ptr fs:[0x0],esp
	/*005783D5*/	sub esp,0x40C
	/*005783DB*/	push esi
	/*005783DC*/	mov esi,ecx
	/*005783DE*/	push edi
	/*005783DF*/	movsx eax,byte ptr ds:[esi+0xBF]
	/*005783E6*/	shl eax,0x2
	/*005783E9*/	push eax
	/*005783EA*/	call sub_944E46_malloc		/*call cm0102.944E46*/
	/*005783EF*/	mov edi,eax
	/*005783F1*/	add esp,0x4
	/*005783F4*/	test edi,edi
	/*005783F6*/	jne _0057842B
	/*005783F8*/	lea ecx,dword ptr ss:[esp+0x14]
	/*005783FC*/	lea edx,dword ptr ss:[esp+0x214]
	/*00578403*/	push ecx
	/*00578404*/	push edx
	/*00578405*/	push eax
	/*00578406*/	push eax
	/*00578407*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*0057840C*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00578411*/	add esp,0x14
	/*00578414*/	lea eax,dword ptr ss:[esp+0x14]
	/*00578418*/	lea ecx,dword ptr ss:[esp+0x214]
	/*0057841F*/	push 0x2BE
	/*00578424*/	push eax
	/*00578425*/	push ecx
	/*00578426*/	jmp _00578539
_0057842B:
	/*0057842B*/	mov edx,dword ptr ds:[esi+0xB1]
	/*00578431*/	push ebx
	/*00578432*/	push 0x0
	/*00578434*/	mov eax,dword ptr ds:[edx+0x162]
	/*0057843A*/	mov dword ptr ds:[edi],eax
	/*0057843C*/	mov ecx,dword ptr ds:[esi+0xB1]
	/*00578442*/	mov edx,dword ptr ds:[ecx+0xB1]
	/*00578448*/	mov dword ptr ds:[edi+0x4],edx
	/*0057844B*/	mov eax,dword ptr ds:[esi+0xB1]
	/*00578451*/	mov ecx,dword ptr ds:[eax+0x127]
	/*00578457*/	mov dword ptr ds:[edi+0x8],ecx
	/*0057845A*/	mov edx,dword ptr ds:[esi+0xB1]
	/*00578460*/	lea ecx,dword ptr ss:[esp+0x10]
	/*00578464*/	mov eax,dword ptr ds:[edx+0xEC]
	/*0057846A*/	mov dword ptr ds:[edi+0xC],eax
	/*0057846D*/	mov edx,dword ptr ds:[esi]
	/*0057846F*/	lea eax,dword ptr ss:[esp+0x14]
	/*00578473*/	push eax
	/*00578474*/	push ecx
	/*00578475*/	push 0x0
	/*00578477*/	mov ecx,esi
	/*00578479*/	call dword ptr ds:[edx+0x3C]
	/*0057847C*/	push 0xB2
	/*00578481*/	mov ebx,eax
	/*00578483*/	call sub_944CF1		/*call cm0102.944CF1*/
	/*00578488*/	add esp,0x4
	/*0057848B*/	mov dword ptr ss:[esp+0x14],eax
	/*0057848F*/	test eax,eax
	/*00578491*/	mov dword ptr ss:[esp+0x420],0x0
	/*0057849C*/	je _005784D4
	/*0057849E*/	mov edx,dword ptr ss:[esp+0x10]
	/*005784A2*/	mov cx,word ptr ds:[esi+0x40]
	/*005784A6*/	push 0x0
	/*005784A8*/	push 0x0
	/*005784AA*/	push 0x0
	/*005784AC*/	push 0x0
	/*005784AE*/	push 0x14
	/*005784B0*/	push edx
	/*005784B1*/	mov edx,dword ptr ds:[esi+0x4]
	/*005784B4*/	push 0x1
	/*005784B6*/	push 0x0
	/*005784B8*/	push ecx
	/*005784B9*/	mov ecx,dword ptr ss:[esp+0x30]
	/*005784BD*/	push ebx
	/*005784BE*/	push edx
	/*005784BF*/	push ecx
	/*005784C0*/	movsx dx,byte ptr ds:[esi+0xBF]
	/*005784C8*/	push edi
	/*005784C9*/	push edx
	/*005784CA*/	push esi
	/*005784CB*/	mov ecx,eax
	/*005784CD*/	call sub_522E00		/*call cm0102.522E00*/
	/*005784D2*/	jmp _005784D6
_005784D4:
	/*005784D4*/	xor eax,eax
_005784D6:
	/*005784D6*/	mov ecx,dword ptr ds:[esi+0xC]
	/*005784D9*/	push edi
	/*005784DA*/	mov dword ptr ss:[esp+0x424],0xFFFFFFFF
	/*005784E5*/	mov dword ptr ds:[ecx],eax
	/*005784E7*/	call sub_9452CA		/*call cm0102.9452CA*/
	/*005784EC*/	push ebx
	/*005784ED*/	call sub_9452CA		/*call cm0102.9452CA*/
	/*005784F2*/	mov edx,dword ptr ds:[esi+0xC]
	/*005784F5*/	add esp,0x8
	/*005784F8*/	mov ecx,dword ptr ds:[edx]
	/*005784FA*/	pop ebx
	/*005784FB*/	test ecx,ecx
	/*005784FD*/	jne _00578583
	/*00578503*/	lea eax,dword ptr ss:[esp+0x114]
	/*0057850A*/	lea ecx,dword ptr ss:[esp+0x314]
	/*00578511*/	push eax
	/*00578512*/	push ecx
	/*00578513*/	push 0x0
	/*00578515*/	push 0x0
	/*00578517*/	push 0x9C4424		/*push cm0102.9C4424*/
	/*0057851C*/	call sub_944CFF_splitpath		/*call cm0102.944CFF*/
	/*00578521*/	add esp,0x14
	/*00578524*/	lea edx,dword ptr ss:[esp+0x114]
	/*0057852B*/	lea eax,dword ptr ss:[esp+0x314]
	/*00578532*/	push 0x2D5
	/*00578537*/	push edx
	/*00578538*/	push eax
_00578539:
	/*00578539*/	call sub_90D130		/*call cm0102.90D130*/
	/*0057853E*/	push eax
	/*0057853F*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00578544*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00578549*/	call sub_944C9F_sprintf		/*call cm0102.944C9F*/
	/*0057854E*/	push 0x0
	/*00578550*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00578555*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*0057855A*/	call sub_5E8290		/*call cm0102.5E8290*/
	/*0057855F*/	add esp,0x24
	/*00578562*/	mov dword ptr ds:[0xB67A34],0x0
	/*0057856C*/	pop edi
	/*0057856D*/	pop esi
	/*0057856E*/	mov ecx,dword ptr ss:[esp+0x40C]
	/*00578575*/	mov dword ptr fs:[0x0],ecx
	/*0057857C*/	add esp,0x418
	/*00578582*/	ret
_00578583:
	/*00578583*/	push 0x0
	/*00578585*/	call sub_51C800		/*call cm0102.51C800*/
	/*0057858A*/	mov ecx,dword ptr ss:[esp+0x414]
	/*00578591*/	pop edi
	/*00578592*/	pop esi
	/*00578593*/	mov dword ptr fs:[0x0],ecx
	/*0057859A*/	add esp,0x418
	/*005785A0*/	ret
	}
}

void __declspec(naked) sub_5785B0()
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
	/*005785EB*/	push 0x989C18		/*push cm0102.989C18*/
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

void patch_eng_third()
{
	vtable::PrintVTable(0x969E84, "eng_third");
	PatchFunction(0x576DD0, (DWORD)&sub_576DD0);
}