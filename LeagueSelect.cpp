#pragma warning(disable : 4773)	// warning C4733: Inline asm assigning to 'FS:0': handler not registered as safe handler
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "CMHeader.h"
#include "Helper.h"
#include "generic_functions.h"

static int(*sub_7A1710)() = (int(*)())(0x7A1710);
static int(*sub_41BFB0)() = (int(*)())(0x41BFB0);
static int(*sub_66F4E0)() = (int(*)())(0x66F4E0);
static int(*sub_803F30)() = (int(*)())(0x803F30);
static int(*sub_75DB00)() = (int(*)())(0x75DB00);
static int(*sub_803F80)() = (int(*)())(0x803F80);
static int(*sub_55FBA0)() = (int(*)())(0x55FBA0);
static int(*sub_8040A0)() = (int(*)())(0x8040A0);
static int(*sub_804100)() = (int(*)())(0x804100);
static int(*sub_66A0C0)() = (int(*)())(0x66A0C0);
static int(*sub_944C9F)() = (int(*)())(0x944C9F);
static int(*sub_669F50)() = (int(*)())(0x669F50);
static int(*sub_7FEBB0)() = (int(*)())(0x7FEBB0);
static int(*sub_7FEC60)() = (int(*)())(0x7FEC60);
static int(*sub_5EDCC0)() = (int(*)())(0x5EDCC0);
static int(*sub_7FF010)() = (int(*)())(0x7FF010);
static int(*sub_403320)() = (int(*)())(0x403320);
static int(*sub_7FF270)() = (int(*)())(0x7FF270);

static int(*sub_90D130)() = (int(*)())(0x90D130);
static int(*sub_5E8290)() = (int(*)())(0x5E8290);
static int(*sub_945501)() = (int(*)())(0x945501);
static int(*sub_944CF1)() = (int(*)())(0x944CF1);
static int(*sub_404250)() = (int(*)())(0x404250);
static int(*sub_406BF0)() = (int(*)())(0x406BF0);
static int(*sub_549F70)() = (int(*)())(0x549F70);

DWORD Austrian_Premier_Division;

void __declspec(naked) Austria_Setup_832100()		// Originally Argentina
{
	__asm
	{
	/*00832100*/	mov eax,dword ptr fs:[0x0]
	/*00832106*/	push 0xFFFFFFFF
	/*00832108*/	push 0x961A7C		/*push <cm0102.sub_961A7C>*/
	/*0083210D*/	push eax
	/*0083210E*/	mov dword ptr fs:[0x0],esp
	/*00832115*/	sub esp,0x410
	/*0083211B*/	push ebx
	/*0083211C*/	push esi
	/*0083211D*/	mov esi,dword ptr ss:[esp+0x428]
	/*00832124*/	push edi
	/*00832125*/	xor edi,edi
	/*00832127*/	cmp esi,edi
	/*00832129*/	jne _0083218E
	/*0083212B*/	lea eax,dword ptr ss:[esp+0x1C]
	/*0083212F*/	lea ecx,dword ptr ss:[esp+0x21C]
	/*00832136*/	push eax
	/*00832137*/	push ecx
	/*00832138*/	push edi
	/*00832139*/	push edi
	/*0083213A*/	push 0xA801DC		/*push cm0102.A801DC*/
	/*0083213F*/	call sub_944CFF_splitpath		/*call <cm0102.sub_splitpath>*/
	/*00832144*/	add esp,0x14
	/*00832147*/	lea edx,dword ptr ss:[esp+0x1C]
	/*0083214B*/	lea eax,dword ptr ss:[esp+0x21C]
	/*00832152*/	push 0x311F
	/*00832157*/	push edx
	/*00832158*/	push eax
	/*00832159*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*0083215E*/	push eax
	/*0083215F*/	push 0x9870E8		/*push cm0102.9870E8*/
	/*00832164*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00832169*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*0083216E*/	push edi
	/*0083216F*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*00832174*/	push 0x9870E0		/*push cm0102.9870E0*/
	/*00832179*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*0083217E*/	add esp,0x24
	/*00832181*/	mov dword ptr ds:[0xB67A34],edi			// Argentina Specific but should never be called!
	/*00832187*/	xor eax,eax
	/*00832189*/	jmp _0083235D
_0083218E:
	/*0083218E*/	mov word ptr ds:[esi+0x37],0x5
	/*00832194*/	mov word ptr ds:[esi+0x32],0x17
	/*0083219A*/	mov byte ptr ds:[esi+0x34],0x7
	/*0083219E*/	mov cx,word ptr ds:[0xAE2C92]			// Year
	/*008321A5*/	mov eax,0x6
	/*008321AA*/	mov word ptr ds:[esi+0x35],cx
	/*008321AE*/	mov word ptr ds:[esi+0x46],ax
	/*008321B2*/	mov word ptr ds:[esi+0x41],0x13
	/*008321B8*/	mov byte ptr ds:[esi+0x43],al
	/*008321BB*/	mov dx,word ptr ds:[0xAE2C92]			// Year
	/*008321C2*/	inc dx
	/*008321C4*/	push 0x1
	/*008321C6*/	mov word ptr ds:[esi+0x44],dx
	/*008321CA*/	mov bx,word ptr ds:[0xAE2C92]			// Year
	/*008321D1*/	push 0x8
	/*008321D3*/	mov word ptr ss:[esp+0x18],bx
	/*008321D8*/	mov dword ptr ds:[esi+0xC],0x2
	/*008321DF*/	call sub_945501		/*call <cm0102.sub_945501>*/
	/*008321E4*/	add esp,0x8
	/*008321E7*/	cmp eax,edi
	/*008321E9*/	mov dword ptr ds:[esi+0x10],eax
	/*008321EC*/	jne _00832283
	/*008321F2*/	lea eax,dword ptr ss:[esp+0x11C]
	/*008321F9*/	lea ecx,dword ptr ss:[esp+0x31C]
	/*00832200*/	push eax
	/*00832201*/	push ecx
	/*00832202*/	push edi
	/*00832203*/	push edi
	/*00832204*/	push 0xA801DC		/*push cm0102.A801DC*/
	/*00832209*/	call sub_944CFF_splitpath		/*call <cm0102.sub_splitpath>*/
	/*0083220E*/	add esp,0x14
	/*00832211*/	lea edx,dword ptr ss:[esp+0x11C]
	/*00832218*/	lea eax,dword ptr ss:[esp+0x31C]
	/*0083221F*/	push 0xA81EA0		/*push cm0102.A81EA0*/
	/*00832224*/	push 0x313C
	/*00832229*/	push edx
	/*0083222A*/	push eax
	/*0083222B*/	call sub_90D130		/*call <cm0102.sub_90D130>*/
	/*00832230*/	push eax
	/*00832231*/	push 0x9A8120		/*push cm0102.9A8120*/
	/*00832236*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0083223B*/	call sub_944C9F		/*call <cm0102.sub_944C9F>*/
	/*00832240*/	add esp,0x1C
	/*00832243*/	push 0x9A8108		/*push cm0102.9A8108*/
	/*00832248*/	push 0xAE28BC		/*push cm0102.AE28BC*/
	/*0083224D*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*00832252*/	add esp,0x8
	/*00832255*/	push 0xAE24D0		/*push cm0102.AE24D0*/
	/*0083225A*/	push 0x9A7FF8		/*push cm0102.9A7FF8*/
	/*0083225F*/	push 0xAE26C4		/*push cm0102.AE26C4*/
	/*00832264*/	call sub_66F4E0		/*call <cm0102.sub_66F4E0>*/
	/*00832269*/	push edi
	/*0083226A*/	push 0xAE26C4		/*push cm0102.AE26C4*/
	/*0083226F*/	push 0xAE28BC		/*push cm0102.AE28BC*/
	/*00832274*/	call sub_5E8290		/*call <cm0102.sub_5E8290>*/
	/*00832279*/	add esp,0x18
	/*0083227C*/	xor eax,eax
	/*0083227E*/	jmp _0083235D
_00832283:
	/*00832283*/	push ebp
	/*00832284*/	push 0xEE
	/*00832289*/	call sub_944CF1		/*call <cm0102.sub_944CF1>*/
	/*0083228E*/	add esp,0x4
	/*00832291*/	mov dword ptr ss:[esp+0x10],eax
	/*00832295*/	mov ebp,dword ptr ss:[esp+0x14]
	/*00832299*/	cmp eax,edi
	/*0083229B*/	mov dword ptr ss:[esp+0x428],edi
	/*008322A2*/	je _008322C8
	/*008322A4*/	mov edx,0xF5		// dword ptr ds:[0x9CF654]				// Was [9cf654] = Argentinian Premier Division
	/*008322AA*/	lea edi,dword ptr ds:[edx+edx*0x2]
	/*008322AD*/	lea ecx,dword ptr ds:[edi+edi*0x8]
	/*008322B0*/	mov edi,dword ptr ds:[0xAE23D0]
	/*008322B6*/	shl ecx,0x2
	/*008322B9*/	sub ecx,edx
	/*008322BB*/	add ecx,edi
	/*008322BD*/	push ecx
	/*008322BE*/	push ebp
	/*008322BF*/	mov ecx,eax
	/*008322C1*/	call sub_404250		/*call <cm0102.sub_404250>*/			// Load Argentina up !
	/*008322C6*/	jmp _008322CA
_008322C8:
	/*008322C8*/	xor eax,eax
_008322CA:
	/*008322CA*/	mov edx,dword ptr ds:[esi+0x10]
	/*008322CD*/	or edi,0xFFFFFFFF
	/*008322D0*/	push 0xF2
	/*008322D5*/	mov dword ptr ss:[esp+0x42C],edi
	/*008322DC*/	mov dword ptr ds:[edx],eax
	/*008322DE*/	call sub_944CF1		/*call <cm0102.sub_944CF1>*/
	/*008322E3*/	add esp,0x4
	/*008322E6*/	mov dword ptr ss:[esp+0x10],eax
	/*008322EA*/	test eax,eax
	/*008322EC*/	mov dword ptr ss:[esp+0x428],0x1
	/*008322F7*/	je _0083231D
	/*008322F9*/	mov edx,0xf6 				///  dword ptr ds:[0x9CF658]   [9cf658] = Argentinian Second Division
	/*008322FF*/	lea ecx,dword ptr ds:[edx+edx*0x2]
	/*00832302*/	lea ecx,dword ptr ds:[ecx+ecx*0x8]
	/*00832305*/	shl ecx,0x2
	/*00832308*/	sub ecx,edx
	/*0083230A*/	mov edx,dword ptr ds:[0xAE23D0]
	/*00832310*/	add ecx,edx
	/*00832312*/	push ecx
	/*00832313*/	push ebp
	/*00832314*/	mov ecx,eax
	/*00832316*/	call sub_406BF0		/*call <cm0102.sub_406BF0>*/
	/*0083231B*/	jmp _0083231F
_0083231D:
	/*0083231D*/	xor eax,eax
_0083231F:
	/*0083231F*/	mov edx,dword ptr ds:[esi+0x10]
	/*00832322*/	push edi
	/*00832323*/	push 0x7D1
	/*00832328*/	push 0x7
	/*0083232A*/	push 0x1
	/*0083232C*/	lea ecx,dword ptr ss:[esp+0x28]
	/*00832330*/	mov dword ptr ss:[esp+0x438],edi
	/*00832337*/	mov dword ptr ds:[edx+0x4],eax
	/*0083233A*/	call sub_549F70		/*call <cm0102.sub_549F70>*/
	/*0083233F*/	mov ax,word ptr ss:[esp+0x18]
	/*00832344*/	mov word ptr ds:[esi+0x1B],bx
	/*00832348*/	mov word ptr ds:[esi+0x15],ax
	/*0083234C*/	mov byte ptr ds:[esi+0x1D],0x1
	/*00832350*/	mov dword ptr ds:[esi+0x26],0x0
	/*00832357*/	mov eax,0x1
	/*0083235C*/	pop ebp
_0083235D:
	/*0083235D*/	mov ecx,dword ptr ss:[esp+0x41C]
	/*00832364*/	pop edi
	/*00832365*/	pop esi
	/*00832366*/	pop ebx
	/*00832367*/	mov dword ptr fs:[0x0],ecx
	/*0083236E*/	add esp,0x41C
	/*00832374*/	ret
	}
}

/*
0. 00B63D60 00000000
1. 00B63DA8 00000000
2. 00B63DF0 00000000
3. 00B63E38 00000000
4. 00B63E80 00000000
5. 00B63EC8 00000000
6. 00B63F10 00000000
7. 00B63F58 00000000
8. 00B63FA0 1612DF84 Argentina
9. 00B63FE8 1612E2EA Australia
10. 00B64030 1612EBFA Belgium
11. 00B64078 1612F50A Brazil
12. 00B640C0 16130CD4 Croatia
13. 00B64108 1613127E Denmark
14. 00B64150 16131B8E England
15. 00B64198 1613249E Finland
16. 00B641E0 161325C0 France
17. 00B64228 16132A48 Germany
18. 00B64270 16132C8C Greece
19. 00B642B8 1613359C Holland
20. 00B64300 16133FCE Republic of Ireland
21. 00B64348 16134212 Italy
22. 00B64390 16134578 Japan
23. 00B643D8 16136896 Northern Ireland
24. 00B64420 161373EA Norway
25. 00B64468 16137F3E Poland
26. 00B644B0 16138060 Portugal
27. 00B644F8 1613860A Russia
28. 00B64540 16138CD6 Scotland
29. 00B64588 1613982A South Korea
30. 00B645D0 1613994C Spain
31. 00B64618 1613A25C Sweden
32. 00B64660 1613AFF4 Turkey
33. 00B646A8 1613B47C United States
34. 00B646F0 1613C0F2 Wales
*/
DWORD TotalNumberOfConsideredNations = 0x23;

void ModifyLeagues()
{
	BYTE *league_ptr = (BYTE *)0xB63D60;	// Playable Leagues - 72 byte blocks. First 8 are reserved. 0 = World Cup
	for (int i = 0; i < 0x23; i++)
	{
		BYTE* league = league_ptr + (i*72);
		if (league)
		{
			dprintf("%d. %08X %08X %s (Setup Func: %08X)\n", i, league, *(DWORD*)league, (*(DWORD*)league == 0) ? "" : (char*)((*(DWORD*)league)+4), *(DWORD*)(league+8));
		}
	}

	/*
	memcpy((void*)0xB64108, (void*)(0xB63D60 + (10*72)), 72);	// Copy Argentina's block to Denmarks place
	Austria = (DWORD)find_country("Austria");
	memcpy((void*)0xB64108, &Austria, 4);
	*(DWORD*)(0xB64108 + 8) = (DWORD)Austria_Setup_832100;
	*/
	
	
	auto country = find_country("Austria");
	//country->NationContinent = continents[0];
	dprintf("NationContinent: %08X\n", country->NationContinent);
	*(DWORD*)(0xB63D60 + (9 * 72)) = (DWORD)find_country("Austria");
	//memcpy((void*)(0xB63D60 + (9*72)), &Austria, 4);

	// Hack to get around replacing aus, a key nation, with a euro nation that does not have a cup and can't feed the uefa_seeding (?)
	WriteBytes(0x00904819, 11, 0xE9, 0x0A, 0x03, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90);
}

void __declspec(naked) LeagueSelect_81D010()
{
	__asm pushad;
	GetCompIDs();
	ModifyLeagues();
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
	/*0081D70F*/	call sub_66A0C0		/*call <cm0102.sub_66A0C0>*/						// <--- returns a small table of sorted numbers - unsure of use yet
	/*0081D714*/	mov edx,eax
	/*0081D716*/	add esp,0x4
	/*0081D719*/	mov dword ptr ss:[esp+0x14],edx
	/*0081D71D*/	xor ecx,ecx
	/*0081D71F*/	mov dword ptr ds:[0xAE2D04],ebx

_0081D725:																					// Loop counts the number of leagues selected and stores in 0xAE2D04
	/*0081D725*/	movsx eax,byte ptr ds:[ecx+edx]
	/*0081D729*/	lea eax,dword ptr ds:[eax+eax*0x8]										// eax *= 9
	/*0081D72C*/	mov eax,dword ptr ds:[eax*0x8+0xB63D60]									// B63D60 is your fixed table of playable leagues in 72 byte blocks?
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
	/*0081D75E*/	mov ebp,dword ptr ds:[eax*0x8+0xB63D60]
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
	/*0081D9D0*/	cmp dword ptr ds:[eax*0x8+0xB63D68],ebx
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
	/*0081DA42*/	cmp dword ptr ds:[eax*0x8+0xB63D68],ebx
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

void setup_available_leagues()
{
	PatchFunction(0x81D010, (DWORD)&LeagueSelect_81D010);
}
