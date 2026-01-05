#pragma once
#include <windows.h>
#include <vector>
#include "CMHeader.h"

using namespace std;

extern char *szDebugFile;

void dprintf(const char* fmt, ...);
void WriteBytes(DWORD addr, int bytes, ...);
void WriteDWORD(DWORD addr, DWORD data);
void PatchFunction(DWORD addr, DWORD jmpTo);
int GetKey();

cm3_nations *find_country(const char *szCountry);
cm3_clubs* find_club(const char *szClub);
cm3_club_comps* find_club_comp(const char *szClubComp);
vector<cm3_club_comps*> find_club_comps_of_nation(const char *szNation);

vector<cm3_clubs*> find_clubs_of_country(DWORD nation_id);
bool vector_contains_club(vector<cm3_clubs*> &vec, cm3_clubs* club);
bool compareClubRep(cm3_clubs* c1, cm3_clubs* c2);
int CountNumberOfTeamsInComp(DWORD CompID);
