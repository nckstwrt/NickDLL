#pragma once
#include <Windows.h>
#include "Helper.h"
/*
NSL
0 = 4110C0   calls sub_4110E0
8 = 411DE0   end of season function?
28 = 411F70
30 = 411D90  small func calls a bunch of other aus_nsl functions
3C = 4111A0  fixtures2? (called by subs)
44 = 411980
48 = 411A30
50 = 4110B0  mov al, 3 ret - for ser c1/a it points to 0048E180 | B0 02 | mov al,2 
68 = 412380 called when setting up or adding teams?
7C = 4124E0 small self-contained function. ser c1/a points to 0048F2D0 | 8079 44 FF | cmp byte ptr ds:[ecx+44],FF
8C = 411CE0 subs function
B4 = 412680 awards function
B8 = 412AC0 fixtures function

40 = 686670 Promotion/Relegation


00967768 00   C0 10 41 00 30 5D 68 00 E0 1D 41 00 10 CE 48 00  À.A.0]h.à.A..ÎH.
00967778 10   D0 9A 68 00 C0 47 68 00 10 7B 68 00 C0 91 68 00  Ð.h.ÀGh..{h.À.h.
00967788 20   B0 CE 48 00 A0 CE 48 00 70 1F 41 00 70 CE 48 00  °ÎH. ÎH.p.A.pÎH.
00967798 30   90 1D 41 00 70 34 58 00 B0 CA 48 00 A0 11 41 00  ..A.p4X.°ÊH. .A.
009677A8 40   70 66 68 00 80 19 41 00 30 1A 41 00 A0 DF 48 00  pfh...A.0.A. ßH.
009677B8 50   B0 10 41 00 E0 A3 68 00 C0 E1 48 00 50 A8 68 00  °.A.à£h.ÀáH.P¨h.
009677C8 60   60 E3 48 00 50 B5 5B 00 80 23 41 00 70 34 58 00  `ãH.Pµ[..#A.p4X.
009677D8 70   C0 11 40 00 D0 11 40 00 00 CE 5D 00 E0 24 41 00  À.@.Ð.@..Î].à$A.
009677E8 80   D0 AB 68 00 40 AC 68 00 00 CE 5D 00 E0 1C 41 00  Ð«h.@¬h..Î].à.A.
009677F8 90   D0 AA 68 00 D0 4C 68 00 90 47 68 00 B0 47 68 00  Ðªh.ÐLh..Gh.°Gh.
00967808 A0   20 7A 68 00 30 AA 68 00 E0 11 40 00 F0 11 40 00   zh.0ªh.à.@.ð.@.
00967818 B0   20 9C 68 00 80 26 41 00

ser c1/a
3C = 64AD80 - fixtures2 ? huge for c1/a

58

0096C534 00   A0 AC 64 00 30 5D 68 00 20 B8 64 00 10 CE 48 00   ¬d.0]h. ¸d..ÎH.
0096C544 10   D0 9A 68 00 C0 47 68 00 10 7B 68 00 C0 91 68 00  Ð.h.ÀGh..{h.À.h.
0096C554 20   B0 CE 48 00 A0 CE 48 00 E0 B9 64 00 70 CE 48 00  °ÎH. ÎH.à¹d.pÎH.
0096C564 30   40 46 68 00 70 34 58 00 B0 CA 48 00 80 AD 64 00  @Fh.p4X.°ÊH...d.
0096C574 40   70 66 68 00 80 41 65 00 90 43 65 00 A0 DF 48 00  pfh..Ae..Ce. ßH.
0096C584 50   80 E1 48 00 E0 A3 68 00 C0 E1 48 00 50 A8 68 00  .áH.à£h.ÀáH.P¨h.
0096C594 60   60 E3 48 00 50 B5 5B 00 80 BD 64 00 70 34 58 00  `ãH.Pµ[..½d.p4X.
0096C5A4 70   C0 11 40 00 D0 11 40 00 00 CE 5D 00 D0 F2 48 00  À.@.Ð.@..Î].ÐòH.
0096C5B4 80   D0 AB 68 00 40 AC 68 00 00 CE 5D 00 70 B7 64 00  Ð«h.@¬h..Î].p·d.
0096C5C4 90   D0 AA 68 00 D0 4C 68 00 90 47 68 00 B0 47 68 00  Ðªh.ÐLh..Gh.°Gh.
0096C5D4 A0   20 7A 68 00 50 00 65 00 E0 11 40 00 F0 11 40 00   zh.P.e.à.@.ð.@.
0096C5E4 B0   20 9C 68 00 50 EE 64 00


*/


class vtable
{
public:
	vtable(DWORD loc0 = -1L, DWORD loc8 = -1L, DWORD loc28 = -1L, DWORD loc30 = -1L, DWORD loc3C = -1L, DWORD loc44 = -1L, DWORD loc48 = -1L, DWORD loc50 = -1L, DWORD loc68 = -1L, DWORD loc7C = -1L, DWORD loc8C = -1L, DWORD locB4 = -1L, DWORD locB8 = -1L)
	{
		if (loc0 != -1L) SetPointer(0x0, loc0);
		if (loc8 != -1L) SetPointer(0x8, loc8);
		if (loc28 != -1L) SetPointer(0x28, loc28);
		if (loc30 != -1L) SetPointer(0x30, loc30);
		if (loc3C != -1L) SetPointer(0x3C, loc3C);
		if (loc44 != -1L) SetPointer(0x44, loc44);
		if (loc48 != -1L) SetPointer(0x48, loc48);
		if (loc50 != -1L) SetPointer(0x50, loc50);
		if (loc68 != -1L) SetPointer(0x68, loc68);
		if (loc7C != -1L) SetPointer(0x7C, loc7C);
		if (loc8C != -1L) SetPointer(0x8C, loc8C);
		if (locB4 != -1L) SetPointer(0xB4, locB4);
		if (locB8 != -1L) SetPointer(0xB8, locB8);
	}

	void SetPointer(DWORD offset, DWORD funcAddr)
	{
		WriteDWORD((DWORD)(&vtable_ptr[offset]), funcAddr);
	}

	static void PrintVTable(DWORD addr, const char *tableName = "")
	{
		BYTE* ptr = (BYTE*)addr;
		BYTE locs[] = { 0x0, 0x8, 0x28, 0x30, 0x3C, 0x44, 0x48, 0x50, 0x68, 0x7C, 0x8C, 0xB4, 0xB8 };
		dprintf("%s VTable at %08X:\n", tableName, addr);
		for (BYTE i = 0; i < sizeof(locs); i++)
			dprintf("%d. %02X = %08X\n", i, locs[i], (*(DWORD*)&ptr[locs[i]]));
	}

	/*
		NSL
		0 = 4110C0   calls sub_4110E0
		8 = 411DE0   end of season function?
		30 = 411D90  small func calls a bunch of other aus_nsl functions
		3C = 4111A0  fixtures2? (called by subs)
		50 = 4110B0  mov al, 3 ret
		68 = 412380 called when setting up or adding teams?
		7C = 4124E0 small self-contained function
		8C = 411CE0 subs function
		B4 = 412680 awards function
	*/
	// Filled in with aus_nsl's table
	BYTE* vtable_ptr = vtable_bytes;
	BYTE vtable_bytes[0xB8] = { 0xC0, 0x10, 0x41, 0x00, 0x30, 0x5D, 0x68, 0x00, 0xE0, 0x1D, 0x41, 0x00, 0x10, 0xCE, 0x48, 0x00,		// 00
								0xD0, 0x9A, 0x68, 0x00, 0xC0, 0x47, 0x68, 0x00, 0x10, 0x7B, 0x68, 0x00, 0xC0, 0x91, 0x68, 0x00,		// 10
								0xB0, 0xCE, 0x48, 0x00, 0xA0, 0xCE, 0x48, 0x00, 0x70, 0x1F, 0x41, 0x00, 0x70, 0xCE, 0x48, 0x00,		// 20
								0x90, 0x1D, 0x41, 0x00, 0x70, 0x34, 0x58, 0x00, 0xB0, 0xCA, 0x48, 0x00, 0xA0, 0x11, 0x41, 0x00,		// 30
								0x70, 0x66, 0x68, 0x00, 0x80, 0x19, 0x41, 0x00, 0x30, 0x1A, 0x41, 0x00, 0xA0, 0xDF, 0x48, 0x00,		// 40
								0xB0, 0x10, 0x41, 0x00, 0xE0, 0xA3, 0x68, 0x00, 0xC0, 0xE1, 0x48, 0x00, 0x50, 0xA8, 0x68, 0x00,		// 50
								0x60, 0xE3, 0x48, 0x00, 0x50, 0xB5, 0x5B, 0x00, 0x80, 0x23, 0x41, 0x00, 0x70, 0x34, 0x58, 0x00,		// 60
								0xC0, 0x11, 0x40, 0x00, 0xD0, 0x11, 0x40, 0x00, 0x00, 0xCE, 0x5D, 0x00, 0xE0, 0x24, 0x41, 0x00,		// 70
								0xD0, 0xAB, 0x68, 0x00, 0x40, 0xAC, 0x68, 0x00, 0x00, 0xCE, 0x5D, 0x00, 0xE0, 0x1C, 0x41, 0x00,		// 80
								0xD0, 0xAA, 0x68, 0x00, 0xD0, 0x4C, 0x68, 0x00, 0x90, 0x47, 0x68, 0x00, 0xB0, 0x47, 0x68, 0x00,		// 90
								0x20, 0x7A, 0x68, 0x00, 0x30, 0xAA, 0x68, 0x00, 0xE0, 0x11, 0x40, 0x00, 0xF0, 0x11, 0x40, 0x00,		// A0
								0x20, 0x9C, 0x68, 0x00, 0x80, 0x26, 0x41, 0x00 };													// B0

};