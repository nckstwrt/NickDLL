#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4786)  // Stops all the weird STL warnings
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

#include "CMHeader.h"
#include "Helper.h"
#include "sudamericana.h"
#include "european_cup.h"
#include "LeagueSelect.h"
#include "aus_nsl.h"
#include "ita_ser_c1a.h"
#include "eng_setup.h"
#include "eng_third.h"
#include "Date.h"

using namespace std;
/*
typedef BOOL(WINAPI *AttachConsole_typedef)(DWORD dwProcessId);
typedef HWND(WINAPI *GetConsoleWindow_typedef)(void);
#define ATTACH_PARENT_PROCESS ((DWORD)-1)
*/
void Setup()
{
	srand((unsigned int)time(NULL)); 

#ifdef _DEBUG
	// 
	szDebugFile = "c:\\nicklog.txt";
	DeleteFile(szDebugFile);

	// All the below is just to force the console window visible in x64dbg
	//AttachConsole_typedef AttachConsole = (AttachConsole_typedef)GetProcAddress(LoadLibrary("Kernel32.DLL"), "AttachConsole");
	//GetConsoleWindow_typedef GetConsoleWindow = (GetConsoleWindow_typedef)GetProcAddress(LoadLibrary("Kernel32.DLL"), "GetConsoleWindow");
	if (!AttachConsole(ATTACH_PARENT_PROCESS))
		AllocConsole();
	HWND hCon = GetConsoleWindow();
	if (hCon)
	{
		ShowWindow(hCon, SW_SHOW);
		SetForegroundWindow(hCon);
	}

	freopen("CONOUT$", "w", stdout);
	dprintf("Hello Out There!\n");

	// Ignore Player Histories On Load for quick loading while debugging
	WriteBytes(0x7C02A1, 5, 0xe9, 0x30, 0xa, 0, 0, 90);

	// Allow multiple CM0102 instances
	WriteBytes(0x68D3B6, 1, 0xEB);
#endif 

	//setup_sudamericana();
	setup_european_cup();
	setup_available_leagues();
	//patch_aus_nsl();
	//patch_ita_ser_c1a();
	//patch_eng_setup();
	patch_eng_third();

	BYTE date_bytes[] = { 0x4E, 0x01, 0xD1, 0x07 };
	Date date(date_bytes);

	date.print();
	date.ToBytes(date_bytes, false);
	dprintf("%02X %02X %02X %02X\n", date_bytes[0], date_bytes[1], date_bytes[2], date_bytes[3]);

	Date date2(2026, 1, 5);
	date2.print("date2");
	Date date3(2026, 1, 10);
	date3.print("date3");
	Date date4(2026, 1, 11);
	date4.print("date4");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
			Setup();
			break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

