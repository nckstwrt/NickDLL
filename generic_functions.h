#pragma once
#include <Windows.h>
#include "CMHeader.h"
#include "Helper.h"

static int(*sub_549F70_convert_to_cm_date)() = (int(*)())(0x549F70);

static int(*sub_68A160_add_fixture_call)(BYTE* a1, __int16 a2, __int16 a3, unsigned __int8 a4, __int16 a5, int a6, char a7, __int16 a8, int a9) = (int(*)(BYTE * a1, __int16 a2, __int16 a3, unsigned __int8 a4, __int16 a5, int a6, char a7, __int16 a8, int a9))(0x68A160);
static int(*sub_68A1C0_add_fixture_call)(BYTE* a1, __int16 a2, unsigned __int16 a3, __int16 a4, char a5, char a6, int a7) = (int(*)(BYTE * a1, __int16 a2, unsigned __int16 a3, __int16 a4, char a5, char a6, int a7))(0x68A1C0);

static int(*sub_521E60_add_playoff_fixture_call)(BYTE* a1, __int16 a2, __int16 a3, BYTE a4, __int16 a5, int a6, __int16 a7) = (int(*)(BYTE* a1, __int16 a2, __int16 a3, unsigned __int8 a4, __int16 a5, int a6, __int16 a7))(0x521E60);
static int(*sub_521EB0_add_playoff_fixture_call)(BYTE* a1, __int16 a2, __int16 a3, BYTE a4, __int16 a5, int a6, char a7, __int16 a8, int a9) = (int(*)(BYTE * a1, __int16 a2, __int16 a3, unsigned __int8 a4, __int16 a5, int a6, char a7, __int16 a8, int a9))(0x521EB0);

static int   (*sub_944C9F_sprintf)() = (int(*)())(0x944C9F);
static void* (*sub_944CF1_operator_new)(int size) = (void* (*)(int size))(0x944CF1);
static int   (*sub_944CFF_splitpath)() = (int(*)())(0x944CFF);
static void* (*sub_944E46_malloc)(int size) = (void* (*)(int size))(0x944E46);
static void* (*sub_945501_alloc)(int size, int a2) = (void* (*)(int size, int a2))(0x945501);
static int   (*sub_5E8290_message_box_call)(LPCSTR lpCaption, CHAR* lpText, int type) = (int(*)(LPCSTR lpCaption, CHAR *lpText, int type))(0x5E8290);

static int(__thiscall* sub_687430_add_team_call)(BYTE* _this, BYTE teamNo, cm3_clubs* club, BYTE a3, DWORD* a4) = (int(__thiscall*)(BYTE * _this, BYTE teamNo, cm3_clubs * club, BYTE a3, DWORD * a4))(0x687430);
static void(__thiscall* sub_689C80_promote)(BYTE* _this, BYTE* top, BYTE* btm, int a3, int a4, char a5, char a6) = (void(__thiscall*)(BYTE * _this, BYTE * top, BYTE * btm, int a3, int a4, char a5, char a6))(0x689C80);

extern DWORD SecondDivisionCompID;
extern DWORD ThirdDivisionCompID;
extern DWORD ConferenceDivisionCompID;
extern DWORD NorthernConferenceDivisionCompID;
extern DWORD SouthernConferenceDivisionCompID;
extern DWORD ALowerDivisionCompID;

void GetCompIDs();
int AddTeams(BYTE* _this);
void AddLeague(BYTE* _this, DWORD compID, int leagueNo, int year, DWORD league_init_addr);
DWORD GenericAddTeamFixtures(BYTE* _this, BYTE a2, WORD* a3, WORD* a4, DWORD* a5);
DWORD AddEng24TeamFixturesWithPlayoffs(BYTE* _this, BYTE a2, WORD* a3, WORD* a4, DWORD* a5);
void sub_689C20_relegation_hook();
int __fastcall HandlePlayoffSelection(BYTE* _this);
void PromotionRelegateCaller();
void GenericPromotionRelegation(BYTE* _this, int a2);