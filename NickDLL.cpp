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
#endif 

	//setup_sudamericana();
	setup_european_cup();
	setup_available_leagues();
	patch_aus_nsl();
	patch_ita_ser_c1a();
	patch_eng_setup();
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

