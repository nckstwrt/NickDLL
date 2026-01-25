#pragma once
#include <windows.h>
#include <vector>
#include "CMHeader.h"
#include "Helper.h"

class LeagueInfo
{
public:
	LeagueInfo::LeagueInfo(const char* Name, const char* AlternativeName, BYTE PromotionPlaces, BYTE PlayoffPlaces, BYTE RelegationPlayOffPlaces, BYTE RelegationPlaces, DWORD SetupFunction = 0);

	const char* Name = NULL;
	const char* AlternativeName = NULL;
	BYTE PromotionPlaces = 0;
	BYTE PlayoffPlaces = 0;
	BYTE RelegationPlayOffPlaces = 0;
	BYTE RelegationPlaces = 0;
	DWORD SetupFunction = 0;
	cm3_club_comps* Comp = NULL;
	cm3_club_comps* PromotionComp = NULL;
	cm3_club_comps* RelegationComp = NULL;
};

class NationLeagueInfo
{
public:
	NationLeagueInfo(const char* nationName);
	void AddLeague(const char* Name, const char* AlternativeName, BYTE PromotionPlaces, BYTE PlayoffPlaces, BYTE RelegationPlayOffPlaces, BYTE RelegationPlaces, DWORD SetupFunction = 0);
	int GetPlayableLeagues();

	const char* nationName;
	std::vector<LeagueInfo> leagues;
};

NationLeagueInfo* add_nation_league_info(const char* nationName);
NationLeagueInfo* get_nation_league_info(const char* nationName);
LeagueInfo* get_league_info(DWORD CompID);

void SetupNationLeagueInfo();

extern std::vector<NationLeagueInfo> nationLeagues;


