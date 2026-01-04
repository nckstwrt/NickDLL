#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "CMHeader.h"
#include "Helper.h"
#include "vtable.h"

static int(*sub_549F70)() = (int(*)())(0x549F70);
static int(*sub_56AA30)() = (int(*)())(0x56AA30);
static int(*sub_56C2A0)() = (int(*)())(0x56C2A0);
static int(*sub_56D380)() = (int(*)())(0x56D380);
static int(*sub_56DB60)() = (int(*)())(0x56DB60);
static int(*sub_56F040)() = (int(*)())(0x56F040);
static int(*sub_570C00)() = (int(*)())(0x570C00);
static int(*sub_571680)() = (int(*)())(0x571680);
static int(*sub_573380)() = (int(*)())(0x573380);
static int(*sub_5754A0)() = (int(*)())(0x5754A0);
static int(*sub_576DD0)() = (int(*)())(0x576DD0);
static int(*sub_5E8290)() = (int(*)())(0x5E8290);
static int(*sub_66F4E0)() = (int(*)())(0x66F4E0);
static int(*sub_90D130)() = (int(*)())(0x90D130);

static int   (*sub_944C9F_sprintf)()				= (int(*)())(0x944C9F);
static void* (*sub_944CF1_operator_new)(int size)	= (void* (*)(int size))(0x944CF1);
static int   (*sub_944CFF_splitpath)()				= (int(*)())(0x944CFF);
static void* (*sub_945501_alloc)(int size, int a2)	= (void* (*)(int size, int a2))(0x945501);

const char* szEnglisNorthernPremierDivision = "English Northern Premier League Premier Division";
const char* szItalianSerieC1A = "Italian Serie C1/A";
const char* szDanishPremierDivision = "Danish Premier Division";

void sub_64AA70(); // ita_ser_c1a init

BYTE* league_init_caller(BYTE* ee_bytes, short year, cm3_club_comps* comp, DWORD league_init_addr)
{
	BYTE* leaguePtr;
	__asm
	{
		pushad
		mov edx, dword ptr[comp]
		mov ebx, dword ptr[year]
		mov ecx, dword ptr[ee_bytes]
		mov eax, dword ptr[league_init_addr]
		push edx
		push ebx
		call eax
		mov dword ptr[leaguePtr], eax
		popad
	}
	return leaguePtr;
}

void AddLeague(BYTE* _this, const char* szLeagueName, int leagueNo, int year, DWORD league_init_addr)
{
	dprintf("Adding (This: %08X) league %s at slot %d for year %d (calling init addr: %08X).\n", (DWORD)_this, szLeagueName, leagueNo, (short)year, league_init_addr);
	cm3_club_comps* comp = find_club_comp(szLeagueName);
	if (comp)
	{
		BYTE* ee_bytes = (BYTE*)sub_944CF1_operator_new(0xEE);
		BYTE* leagueSetupPtr = league_init_caller(ee_bytes, (short)*current_year, comp, league_init_addr);
		//league_init_caller(
		DWORD* compPtrTable = *(DWORD**)(_this + 0x10);
		compPtrTable[leagueNo] = (DWORD)leagueSetupPtr;
	}
	else
		dprintf("Could not find comp %s!", szLeagueName);
}

void __declspec(naked) sub_833750()
{
	__asm
	{
	/*00833750*/	mov eax,dword ptr fs:[0x0]
	/*00833756*/	push 0xFFFFFFFF
	/*00833758*/	push 0x961D3C		/*push <cm0102.sub_961D3C>*/
	/*0083375D*/	push eax
	/*0083375E*/	mov dword ptr fs:[0x0],esp
	/*00833765*/	sub esp,0x410
	/*0083376B*/	push ebx
	/*0083376C*/	push esi
	/*0083376D*/	mov esi,dword ptr ss:[esp+0x428]
	/*00833774*/	xor ebx,ebx
	/*00833776*/	cmp esi,ebx
	/*00833778*/	jne _008337EF
	/*0083377A*/	lea eax,dword ptr ss:[esp+0x18]
	/*0083377E*/	lea ecx,dword ptr ss:[esp+0x218]
	/*00833785*/	push eax
	/*00833786*/	push ecx
	/*00833787*/	push ebx
	/*00833788*/	push ebx
	/*00833789*/	push 0xA801DC		/*push cm0102.A801DC*/
	/*0083378E*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*00833793*/	add esp,0x14
	/*00833796*/	lea edx,dword ptr ss:[esp+0x18]
	/*0083379A*/	lea eax,dword ptr ss:[esp+0x218]
	/*008337A1*/	push 0x32C1
	/*008337A6*/	push edx
	/*008337A7*/	push eax
	/*008337A8*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*008337AD*/	push eax
	/*008337AE*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*008337B3*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*008337B8*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F>*/
	/*008337BD*/	push ebx
	/*008337BE*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*008337C3*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*008337C8*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*008337CD*/	add esp,0x24
	/*008337D0*/	mov dword ptr ds:[0xB67A34],ebx
	/*008337D6*/	xor eax,eax
	/*008337D8*/	pop esi
	/*008337D9*/	pop ebx
	/*008337DA*/	mov ecx,dword ptr ss:[esp+0x410]
	/*008337E1*/	mov dword ptr fs:[0x0],ecx
	/*008337E8*/	add esp,0x41C
	/*008337EE*/	ret
_008337EF:
	/*008337EF*/	mov eax,0x5
	/*008337F4*/	mov ecx,0xA
	/*008337F9*/	mov word ptr ds:[esi+0x37],ax
	/*008337FD*/	mov word ptr ds:[esi+0x32],cx
	/*00833801*/	mov byte ptr ds:[esi+0x34],0x7
	/*00833805*/	mov dx,word ptr ds:[0xAE2C92]				// [0AE2C92] = Current year
	/*0083380C*/	mov word ptr ds:[esi+0x35],dx
	/*00833810*/	mov word ptr ds:[esi+0x46],ax
	/*00833814*/	mov word ptr ds:[esi+0x41],0x18
	/*0083381A*/	mov byte ptr ds:[esi+0x43],0x4
	/*0083381E*/	mov ax,word ptr ds:[0xAE2C92]
	/*00833824*/	inc ax
	/*00833826*/	mov word ptr ds:[esi+0x44],ax
	/*0083382A*/	mov dx,word ptr ds:[0xAE2C92]				// [0AE2C92] = Current year
	/*00833831*/	mov eax,dword ptr ds:[esi]
	/*00833833*/	mov word ptr ss:[esp+0xC],dx
	/*00833838*/	test byte ptr ds:[eax+0x11C],0x4
	/*0083383F*/	je _00833846
	/*00833841*/	mov dword ptr ds:[esi+0xC],0xB				// Normally 0xA (ecx) for extra leagues/cups
	/*00833844*/	jmp _0083384D
_00833846:
	/*00833846*/	mov dword ptr ds:[esi+0xC],0x8				// Number of leagues/cups (8 = Default)
_0083384D:
	/*0083384D*/	mov ecx,dword ptr ds:[esi+0xC]
	/*00833850*/	push 0x1
	/*00833852*/	shl ecx,0x2
	/*00833855*/	push ecx
	/*00833856*/	call sub_945501_alloc		/*call <cm0102.sub_945501>*/
	/*0083385B*/	add esp,0x8
	/*0083385E*/	cmp eax,ebx
	/*00833860*/	mov dword ptr ds:[esi+0x10],eax
	/*00833863*/	jne _0083390C
	/*00833869*/	lea edx,dword ptr ss:[esp+0x118]
	/*00833870*/	lea eax,dword ptr ss:[esp+0x318]
	/*00833877*/	push edx
	/*00833878*/	push eax
	/*00833879*/	push ebx
	/*0083387A*/	push ebx
	/*0083387B*/	push 0xA801DC		/*push cm0102.A801DC*/
	/*00833880*/	call sub_944CFF_splitpath		/*call <cm0102.sub_944CFF>*/
	/*00833885*/	add esp,0x14
	/*00833888*/	lea ecx,dword ptr ss:[esp+0x118]
	/*0083388F*/	lea edx,dword ptr ss:[esp+0x318]
	/*00833896*/	push 0xA81FE4		/*push cm0102.A81FE4*/
	/*0083389B*/	push 0x32E0
	/*008338A0*/	push ecx
	/*008338A1*/	push edx
	/*008338A2*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*008338A7*/	push eax
	/*008338A8*/	push 0x9A8120		/*push cm0102.9A8120*/
	/*008338AD*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*008338B2*/	call sub_944C9F_sprintf		/*call <cm0102.sub_944C9F>*/
	/*008338B7*/	add esp,0x1C
	/*008338BA*/	push 0x9A8108		/*push cm0102.9A8108*/
	/*008338BF*/	push 0xAE28BC		/*push cm0102.AE28BC*/
	/*008338C4*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*008338C9*/	add esp,0x8
	/*008338CC*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*008338D1*/	push 0x9A7FF8		/*push cm0102.9A7FF8*/
	/*008338D6*/	push 0xAE26C4		/*push cm0102.AE26C4*/
	/*008338DB*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*008338E0*/	push ebx
	/*008338E1*/	push 0xAE26C4		/*push cm0102.AE26C4*/
	/*008338E6*/	push 0xAE28BC		/*push cm0102.AE28BC*/
	/*008338EB*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*008338F0*/	add esp,0x18
	/*008338F3*/	xor eax,eax
	/*008338F5*/	pop esi
	/*008338F6*/	pop ebx
	/*008338F7*/	mov ecx,dword ptr ss:[esp+0x410]
	/*008338FE*/	mov dword ptr fs:[0x0],ecx
	/*00833905*/	add esp,0x41C
	/*0083390B*/	ret
_0083390C:
	/*0083390C*/	push ebp
	/*0083390D*/	push edi
	/*0083390E*/	push 0xEE
	/*00833913*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833918*/	add esp,0x4
	/*0083391B*/	mov dword ptr ss:[esp+0x10],eax
	/*0083391F*/	mov ebp,dword ptr ss:[esp+0x14]
	/*00833923*/	cmp eax,ebx
	/*00833925*/	mov dword ptr ss:[esp+0x428],ebx
	/*0083392C*/	je _00833952
	/*0083392E*/	mov edx,dword ptr ds:[0x9CF5BC]						// [9cf5bc] = English Premier League
	/*00833934*/	lea edi,dword ptr ds:[edx+edx*0x2]
	/*00833937*/	lea ecx,dword ptr ds:[edi+edi*0x8]
	/*0083393A*/	mov edi,dword ptr ds:[0xAE23D0]                    //  cm3_club_comps
	/*00833940*/	shl ecx,0x2
	/*00833943*/	sub ecx,edx
	/*00833945*/	add ecx,edi
	/*00833947*/	push ecx
	/*00833948*/	push ebp
	/*00833949*/	mov ecx,eax
	/*0083394B*/	call sub_573380		/*call <cm0102.sub_573380>*/
	/*00833950*/	jmp _00833954
_00833952:
	/*00833952*/	xor eax,eax
_00833954:
	/*00833954*/	mov edx,dword ptr ds:[esi+0x10]
	/*00833957*/	or edi,0xFFFFFFFF
	/*0083395A*/	push 0xEE
	/*0083395F*/	mov dword ptr ss:[esp+0x42C],edi
	/*00833966*/	mov dword ptr ds:[edx],eax
	/*00833968*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*0083396D*/	add esp,0x4
	/*00833970*/	mov dword ptr ss:[esp+0x10],eax
	/*00833974*/	cmp eax,ebx
	/*00833976*/	mov dword ptr ss:[esp+0x428],0x1
	/*00833981*/	je _008339A7
	/*00833983*/	mov edx,dword ptr ds:[0x9CF5C0]					   // [9cf5c0] = English First Division
	/*00833989*/	lea ecx,dword ptr ds:[edx+edx*0x2]
	/*0083398C*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]
	/*0083398F*/	shl ecx,0x2
	/*00833992*/	sub ecx,edx
	/*00833994*/	mov edx,dword ptr ds:[0xAE23D0]                    //  cm3_club_comps					// club_comps
	/*0083399A*/	add ecx,edx
	/*0083399C*/	push ecx
	/*0083399D*/	push ebp
	/*0083399E*/	mov ecx,eax
	/*008339A0*/	call sub_571680		/*call <cm0102.sub_571680>*/
	/*008339A5*/	jmp _008339A9
_008339A7:
	/*008339A7*/	xor eax,eax
_008339A9:
	/*008339A9*/	mov edx,dword ptr ds:[esi+0x10]
	/*008339AC*/	push 0xEE
	/*008339B1*/	mov dword ptr ss:[esp+0x42C],edi
	/*008339B8*/	mov dword ptr ds:[edx+0x4],eax
	/*008339BB*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*008339C0*/	add esp,0x4
	/*008339C3*/	mov dword ptr ss:[esp+0x10],eax
	/*008339C7*/	cmp eax,ebx
	/*008339C9*/	mov dword ptr ss:[esp+0x428],0x2
	/*008339D4*/	je _008339FA
	/*008339D6*/	mov edx,dword ptr ds:[0x9CF5C4]					   // [9cf5c4] = English Second Division
	/*008339DC*/	lea ecx,dword ptr ds:[edx+edx*0x2]
	/*008339DF*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]
	/*008339E2*/	shl ecx,0x2
	/*008339E5*/	sub ecx,edx
	/*008339E7*/	mov edx,dword ptr ds:[0xAE23D0]                    //  cm3_club_comps
	/*008339ED*/	add ecx,edx
	/*008339EF*/	push ecx
	/*008339F0*/	push ebp
	/*008339F1*/	mov ecx,eax
	/*008339F3*/	call sub_5754A0		/*call <cm0102.sub_5754A0>*/
	/*008339F8*/	jmp _008339FC
_008339FA:
	/*008339FA*/	xor eax,eax
_008339FC:
	/*008339FC*/	mov edx,dword ptr ds:[esi+0x10]
	/*008339FF*/	push 0xEE
	/*00833A04*/	mov dword ptr ss:[esp+0x42C],edi
	/*00833A0B*/	mov dword ptr ds:[edx+0x8],eax
	/*00833A0E*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833A13*/	add esp,0x4
	/*00833A16*/	mov dword ptr ss:[esp+0x10],eax
	/*00833A1A*/	cmp eax,ebx
	/*00833A1C*/	mov dword ptr ss:[esp+0x428],0x3
	/*00833A27*/	je _00833A4D
	/*00833A29*/	mov edx,dword ptr ds:[0x9CF5C8]					   // [9cf5c8] = English Third Division
	/*00833A2F*/	mov ebx,dword ptr ds:[0xAE23D0]                    //  cm3_club_comps
	/*00833A35*/	lea ecx,dword ptr ds:[edx+edx*0x2]
	/*00833A38*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]
	/*00833A3B*/	shl ecx,0x2
	/*00833A3E*/	sub ecx,edx
	/*00833A40*/	add ecx,ebx
	/*00833A42*/	push ecx
	/*00833A43*/	push ebp
	/*00833A44*/	mov ecx,eax
	/*00833A46*/	call sub_576DD0		/*call <cm0102.sub_576DD0>*/
	/*00833A4B*/	jmp _00833A4F
_00833A4D:
	/*00833A4D*/	xor eax,eax
_00833A4F:
	/*00833A4F*/	mov edx,dword ptr ds:[esi+0x10]
	/*00833A52*/	mov dword ptr ss:[esp+0x428],edi
	/*00833A59*/	mov bl,0x4										  // Leagues added counter
	/*00833A5B*/	mov dword ptr ds:[edx+0xC],eax
	/*00833A5E*/	mov eax,dword ptr ds:[esi+0xC]
	/*00833A61*/	cmp eax,0xB										// Normally this would be 0xA - but we've added an extra league
	/*00833A64*/	jne _00833ABE_SkipConference
	/*00833A66*/	push 0xEE
	/*00833A6B*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833A70*/	add esp,0x4
	/*00833A73*/	mov dword ptr ss:[esp+0x10],eax
	/*00833A77*/	test eax,eax
	/*00833A79*/	mov dword ptr ss:[esp+0x428],0x4
	/*00833A84*/	je _00833AAD_SkipNoMemory
	/*00833A86*/	mov edx,dword ptr ds:[0x9CF69C]					   // [9cf69c] = English Conference
	/*00833A8C*/	lea edi,dword ptr ds:[edx+edx*0x2]
	/*00833A8F*/	lea ecx,dword ptr ds:[edi+edi*0x8]
	/*00833A92*/	mov edi,dword ptr ds:[0xAE23D0]                    //  cm3_club_comps
	/*00833A98*/	shl ecx,0x2
	/*00833A9B*/	sub ecx,edx
	/*00833A9D*/	add ecx,edi
	/*00833A9F*/	push ecx
	/*00833AA0*/	push ebp
	/*00833AA1*/	mov ecx,eax
	/*00833AA3*/	call sub_56DB60		/*call <cm0102.sub_56DB60>*/
	/*00833AA8*/	or edi,0xFFFFFFFF
	/*00833AAB*/	jmp _00833AAF_AllGood
_00833AAD_SkipNoMemory:
	/*00833AAD*/	xor eax,eax
_00833AAF_AllGood:
	/*00833AAF*/	mov edx,dword ptr ds:[esi+0x10]					// League Ptrs
	/*00833AB2*/	mov dword ptr ss:[esp+0x428],edi
	/*00833AB9*/	mov bl,0x5
	/*00833ABB*/	mov dword ptr ds:[edx+0x10],eax					// Save the now created League Ptr

					pushad
					movsx ebx, bl
					push sub_64AA70							// league init function
					push ebp								// has the year in it
					push ebx								// league number
					push szEnglisNorthernPremierDivision // szEnglisNorthernPremierDivision // szDanishPremierDivision   //szItalianSerieC1A // //szEnglisNorthernPremierDivision	// league name
					push esi								// this pointer
					call AddLeague
					add esp, 0x14
					popad
					inc bl

_00833ABE_SkipConference:
	/*00833ABE*/	push 0xB5
	/*00833AC3*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833AC8*/	add esp,0x4
	/*00833ACB*/	mov dword ptr ss:[esp+0x10],eax
	/*00833ACF*/	test eax,eax
	/*00833AD1*/	mov dword ptr ss:[esp+0x428],0x5
	/*00833ADC*/	je _00833B05
	/*00833ADE*/	mov edx,dword ptr ds:[0x9CF74C]					   // [9cf74c] = English FA Cup
	/*00833AE4*/	lea edi,dword ptr ds:[edx+edx*0x2]
	/*00833AE7*/	lea ecx,dword ptr ds:[edi+edi*0x8]
	/*00833AEA*/	mov edi,dword ptr ds:[0xAE23D0]                    //  cm3_club_comps
	/*00833AF0*/	shl ecx,0x2
	/*00833AF3*/	sub ecx,edx
	/*00833AF5*/	add ecx,edi
	/*00833AF7*/	push ecx
	/*00833AF8*/	push ebp
	/*00833AF9*/	mov ecx,eax
	/*00833AFB*/	call sub_56F040		/*call <cm0102.sub_56F040>*/
	/*00833B00*/	or edi,0xFFFFFFFF
	/*00833B03*/	jmp _00833B07
_00833B05:
	/*00833B05*/	xor eax,eax
_00833B07:
	/*00833B07*/	mov ecx,dword ptr ds:[esi+0x10]
	/*00833B0A*/	push 0xB3
	/*00833B0F*/	movsx edx,bl
	/*00833B12*/	mov dword ptr ss:[esp+0x42C],edi
	/*00833B19*/	inc bl
	/*00833B1B*/	mov dword ptr ds:[ecx+edx*0x4],eax
	/*00833B1E*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833B23*/	add esp,0x4
	/*00833B26*/	mov dword ptr ss:[esp+0x10],eax
	/*00833B2A*/	test eax,eax
	/*00833B2C*/	mov dword ptr ss:[esp+0x428],0x6
	/*00833B37*/	je _00833B5D
	/*00833B39*/	mov edx,dword ptr ds:[0x9CF750]						// [9cf750] = English League Cup
	/*00833B3F*/	lea ecx,dword ptr ds:[edx+edx*0x2]
	/*00833B42*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]
	/*00833B45*/	shl ecx,0x2
	/*00833B48*/	sub ecx,edx
	/*00833B4A*/	mov edx,dword ptr ds:[0xAE23D0]						//  cm3_club_comps
	/*00833B50*/	add ecx,edx
	/*00833B52*/	push ecx
	/*00833B53*/	push ebp
	/*00833B54*/	mov ecx,eax
	/*00833B56*/	call sub_56C2A0		/*call <cm0102.sub_56C2A0>*/
	/*00833B5B*/	jmp _00833B5F
_00833B5D:
	/*00833B5D*/	xor eax,eax
_00833B5F:
	/*00833B5F*/	mov ecx,dword ptr ds:[esi+0x10]
	/*00833B62*/	push 0xBA
	/*00833B67*/	movsx edx,bl
	/*00833B6A*/	mov dword ptr ss:[esp+0x42C],edi
	/*00833B71*/	inc bl
	/*00833B73*/	mov dword ptr ds:[ecx+edx*0x4],eax
	/*00833B76*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833B7B*/	add esp,0x4
	/*00833B7E*/	mov dword ptr ss:[esp+0x10],eax
	/*00833B82*/	test eax,eax
	/*00833B84*/	mov dword ptr ss:[esp+0x428],0x7
	/*00833B8F*/	je _00833BB5
	/*00833B91*/	mov edx,dword ptr ds:[0x9CF758]						// [9cf758] = English Autoglass Trophy
	/*00833B97*/	lea ecx,dword ptr ds:[edx+edx*0x2]
	/*00833B9A*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]
	/*00833B9D*/	shl ecx,0x2
	/*00833BA0*/	sub ecx,edx
	/*00833BA2*/	mov edx,dword ptr ds:[0xAE23D0]						//  cm3_club_comps
	/*00833BA8*/	add ecx,edx
	/*00833BAA*/	push ecx
	/*00833BAB*/	push ebp
	/*00833BAC*/	mov ecx,eax
	/*00833BAE*/	call sub_56AA30		/*call <cm0102.sub_56AA30>*/
	/*00833BB3*/	jmp _00833BB7
_00833BB5:
	/*00833BB5*/	xor eax,eax
_00833BB7:
	/*00833BB7*/	mov ecx,dword ptr ds:[esi+0x10]
	/*00833BBA*/	push 0xB2
	/*00833BBF*/	movsx edx,bl
	/*00833BC2*/	mov dword ptr ss:[esp+0x42C],edi
	/*00833BC9*/	inc bl
	/*00833BCB*/	mov dword ptr ds:[ecx+edx*0x4],eax
	/*00833BCE*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833BD3*/	add esp,0x4
	/*00833BD6*/	mov dword ptr ss:[esp+0x10],eax
	/*00833BDA*/	test eax,eax
	/*00833BDC*/	mov dword ptr ss:[esp+0x428],0x8
	/*00833BE7*/	je _00833C0D
	/*00833BE9*/	mov ecx,dword ptr ds:[0x9CF754]						// [9cf754] = English Charity Shield
	/*00833BEF*/	lea edx,dword ptr ds:[ecx+ecx*0x2]
	/*00833BF2*/	lea edx,dword ptr ds:[edx+edx*0x8]
	/*00833BF5*/	shl edx,0x2
	/*00833BF8*/	sub edx,ecx
	/*00833BFA*/	mov ecx,dword ptr ds:[0xAE23D0]						//  cm3_club_comps
	/*00833C00*/	add edx,ecx
	/*00833C02*/	mov ecx,eax
	/*00833C04*/	push edx
	/*00833C05*/	push ebp
	/*00833C06*/	call sub_56D380		/*call <cm0102.sub_56D380>*/
	/*00833C0B*/	jmp _00833C0F
_00833C0D:
	/*00833C0D*/	xor eax,eax
_00833C0F:
	/*00833C0F*/	mov edx,dword ptr ds:[esi+0x10]
	/*00833C12*/	mov dword ptr ss:[esp+0x428],edi
	/*00833C19*/	movsx ecx,bl
	/*00833C1C*/	inc bl
	/*00833C1E*/	mov dword ptr ds:[edx+ecx*0x4],eax
	/*00833C21*/	mov eax,dword ptr ds:[esi+0xC]						
	/*00833C24*/	cmp eax,0xB											// Normally this would be 0xA - but we've added an extra league
	/*00833C27*/	jne _00833C82
	/*00833C29*/	push 0xB2
	/*00833C2E*/	call sub_944CF1_operator_new		/*call <cm0102.sub_944CF1>*/
	/*00833C33*/	add esp,0x4
	/*00833C36*/	mov dword ptr ss:[esp+0x10],eax
	/*00833C3A*/	test eax,eax
	/*00833C3C*/	mov dword ptr ss:[esp+0x428],0x9
	/*00833C47*/	je _00833C70
	/*00833C49*/	mov edx,dword ptr ds:[0x9CF6A0]						// [9cf6a0] = English FA Trophy
	/*00833C4F*/	lea edi,dword ptr ds:[edx+edx*0x2]
	/*00833C52*/	lea ecx,dword ptr ds:[edi+edi*0x8]
	/*00833C55*/	mov edi,dword ptr ds:[0xAE23D0]						//  cm3_club_comps
	/*00833C5B*/	shl ecx,0x2
	/*00833C5E*/	sub ecx,edx
	/*00833C60*/	add ecx,edi
	/*00833C62*/	push ecx
	/*00833C63*/	push ebp
	/*00833C64*/	mov ecx,eax
	/*00833C66*/	call sub_570C00		/*call <cm0102.sub_570C00>*/
	/*00833C6B*/	or edi,0xFFFFFFFF
	/*00833C6E*/	jmp _00833C72
_00833C70:
	/*00833C70*/	xor eax,eax
_00833C72:
	/*00833C72*/	mov ecx,dword ptr ds:[esi+0x10]
	/*00833C75*/	mov dword ptr ss:[esp+0x428],edi
	/*00833C7C*/	movsx edx,bl
	/*00833C7F*/	mov dword ptr ds:[ecx+edx*0x4],eax
_00833C82:
	/*00833C82*/	push edi
	/*00833C83*/	push 0x7D1
	/*00833C88*/	push 0x5
	/*00833C8A*/	push 0x14
	/*00833C8C*/	lea ecx,dword ptr ss:[esp+0x28]
	/*00833C90*/	call sub_549F70		/*call <cm0102.sub_549F70>*/
	/*00833C95*/	mov dx,word ptr ss:[esp+0x18]
	/*00833C9A*/	mov ax,word ptr ss:[esp+0x14]
	/*00833C9F*/	mov word ptr ds:[esi+0x15],dx
	/*00833CA3*/	mov word ptr ds:[esi+0x1B],ax
	/*00833CA7*/	mov byte ptr ds:[esi+0x1D],0x1
	/*00833CAB*/	mov eax,dword ptr ds:[0x9CF754]						// [9cf754] = English Charity Shield
	/*00833CB0*/	pop edi
	/*00833CB1*/	pop ebp
	/*00833CB2*/	lea ecx,dword ptr ds:[eax+eax*0x2]
	/*00833CB5*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]
	/*00833CB8*/	shl ecx,0x2
	/*00833CBB*/	sub ecx,eax
	/*00833CBD*/	mov eax,dword ptr ds:[0xAE23D0]						//  cm3_club_comps
	/*00833CC2*/	add ecx,eax
	/*00833CC4*/	mov eax,0x1
	/*00833CC9*/	mov dword ptr ds:[esi+0x26],ecx
	/*00833CCC*/	mov ecx,dword ptr ss:[esp+0x418]
	/*00833CD3*/	pop esi
	/*00833CD4*/	pop ebx
	/*00833CD5*/	mov dword ptr fs:[0x0],ecx
	/*00833CDC*/	add esp,0x41C
	/*00833CE2*/	ret
	}
}

void patch_eng_setup()
{
	PatchFunction(0x833750, (DWORD)&sub_833750);
}