#define _CRT_SECURE_NO_WARNINGS
#include "LeagueInfo.h"

void sub_576DD0_eng_third_init();

std::vector<NationLeagueInfo> nationLeagues;

LeagueInfo::LeagueInfo(const char* Name, const char* AlternativeName, BYTE PromotionPlaces, BYTE PlayoffPlaces, BYTE RelegationPlayOffPlaces, BYTE RelegationPlaces, DWORD SetupFunction)
{
	this->Name = Name;
	this->AlternativeName = AlternativeName;
	this->PromotionPlaces = PromotionPlaces;
	this->PlayoffPlaces = PlayoffPlaces;
	this->RelegationPlayOffPlaces = RelegationPlayOffPlaces;
	this->RelegationPlaces = RelegationPlaces;
	this->SetupFunction = SetupFunction;
	this->CompID = find_club_comp_id(Name, AlternativeName);

	if (this->CompID == -1L)
		dprintf("Warning: Could not find CompID for league '%s'\n", Name);
}

NationLeagueInfo::NationLeagueInfo(const char* nationName)
{
	this->nationName = nationName;
}

void NationLeagueInfo::AddLeague(const char* Name, const char* AlternativeName, BYTE PromotionPlaces, BYTE PlayoffPlaces, BYTE RelegationPlayOffPlaces, BYTE RelegationPlaces, DWORD SetupFunction)
{
	leagues.push_back(LeagueInfo(Name, AlternativeName, PromotionPlaces, PlayoffPlaces, RelegationPlayOffPlaces, RelegationPlaces, SetupFunction));
}

NationLeagueInfo* add_nation_league_info(const char* nationName)
{
	nationLeagues.push_back(NationLeagueInfo(nationName));
	return &nationLeagues.back();
}

NationLeagueInfo *get_nation_league_info(const char* nationName)
{
	for (size_t i = 0; i < nationLeagues.size(); i++)
		if (strcmp(nationLeagues[i].nationName, nationName) == 0)
			return &nationLeagues[i];
	dprintf("Warning: Could not find league info for nation '%s'\n", nationName);
	return NULL;
}

void SetupNationLeagueInfo()
{
	NationLeagueInfo* austria = add_nation_league_info("Austria");
	austria->AddLeague("Austrian Premier Division", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	austria->AddLeague("Austrian First Division", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* czech_republic = add_nation_league_info("Czech Republic");
	czech_republic->AddLeague("Czech First Division", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	czech_republic->AddLeague("Czech Second Division", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	czech_republic->AddLeague("Czech Third Division CFL", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	czech_republic->AddLeague("Czech Third Division MSFL", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* hong_kong = add_nation_league_info("Hong Kong");
	hong_kong->AddLeague("Hong Kong First Division", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	hong_kong->AddLeague("Hong Kong Second Division", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	hong_kong->AddLeague("Hong Kong Third Division A", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	hong_kong->AddLeague("Hong Kong Third Division B", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* china = add_nation_league_info("China PR");
	china->AddLeague("Chinese First Division A", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	china->AddLeague("Chinese First Division B", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	china->AddLeague("Chinese Second Division", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* luxembourg = add_nation_league_info("Luxembourg");
	luxembourg->AddLeague("Luxembourg National Division", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	// Luxembourg Second Division is spelt wrong in the original data
	if (find_club_comp("Luxembourg Second Dvision") != NULL)
		strcpy(find_club_comp("Luxembourg Second Dvision")->ClubCompName, "Luxembourg Second Division");

	luxembourg->AddLeague("Luxembourg Second Division", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* malaysia = add_nation_league_info("Malaysia");
	malaysia->AddLeague("Malaysian League Premier One", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	malaysia->AddLeague("Malaysian League Premier Two", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* mexico = add_nation_league_info("Mexico");
	mexico->AddLeague("Mexican First Division", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	mexico->AddLeague("Mexican First Division A", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* south_africa = add_nation_league_info("South Africa");
	south_africa->AddLeague("South African Premier Division", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	south_africa->AddLeague("South African First Division Inland", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	south_africa->AddLeague("South African First Division Coastal", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);

	NationLeagueInfo* yugoslavia = add_nation_league_info("Yugoslavia");
	yugoslavia->AddLeague("Yugoslav First Division", NULL, 1, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	yugoslavia->AddLeague("Yugoslav Second Division East", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	yugoslavia->AddLeague("Yugoslav Second Division North", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	yugoslavia->AddLeague("Yugoslav Second Division South", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
	yugoslavia->AddLeague("Yugoslav Second Division West", NULL, 2, 0, 0, 2, (DWORD)&sub_576DD0_eng_third_init);
}
