#define _CRT_SECURE_NO_WARNINGS
#include "LeagueInfo.h"

void sub_576DD0_eng_third_init();
void eng_third_init_c();

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
	this->Comp = find_club_comp(Name, AlternativeName);

	if (!this->Comp)
		dprintf("Warning: Could not find Comp for league '%s'\n", Name);
}

NationLeagueInfo::NationLeagueInfo(const char* nationName)
{
	this->nationName = nationName;
}

void NationLeagueInfo::AddLeague(const char* Name, const char* AlternativeName, BYTE PromotionPlaces, BYTE PlayoffPlaces, BYTE RelegationPlayOffPlaces, BYTE RelegationPlaces, DWORD SetupFunction)
{
	LeagueInfo league_info(Name, AlternativeName, PromotionPlaces, PlayoffPlaces, RelegationPlayOffPlaces, RelegationPlaces, SetupFunction);
	if (leagues.size() > 0)
	{
		LeagueInfo* previous_league = &leagues.back();
		league_info.PromotionComp = previous_league->Comp;
		previous_league->RelegationComp = league_info.Comp;
	}
	leagues.push_back(league_info);
}

int NationLeagueInfo::GetPlayableLeagues()
{
	int playableLeagues = 0;
	for (size_t i = 0; i < leagues.size(); i++)
		if (leagues[i].SetupFunction != 0)
			playableLeagues++;
	return playableLeagues;
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

LeagueInfo* get_league_info(DWORD CompID)
{
	for (size_t i = 0; i < nationLeagues.size(); i++)
	{
		for (size_t j = 0; j < nationLeagues[i].leagues.size(); j++)
		{
			if (nationLeagues[i].leagues[j].Comp->ClubCompID == CompID)
				return &nationLeagues[i].leagues[j];
		}
	}
	return NULL;
}

void SetupNationLeagueInfo()
{
	NationLeagueInfo* austria = add_nation_league_info("Austria");
	austria->AddLeague("Austrian Premier Division", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	austria->AddLeague("Austrian First Division", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	austria->AddLeague("Austrian Lower Division", NULL, 0, 0, 0, 0, NULL);

	NationLeagueInfo* czech_republic = add_nation_league_info("Czech Republic");
	czech_republic->AddLeague("Czech First Division", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	czech_republic->AddLeague("Czech Second Division", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	czech_republic->AddLeague("Czech Third Division CFL", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	czech_republic->AddLeague("Czech Third Division MSFL", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);

	NationLeagueInfo* hong_kong = add_nation_league_info("Hong Kong");
	hong_kong->AddLeague("Hong Kong First Division", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	hong_kong->AddLeague("Hong Kong Second Division", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	hong_kong->AddLeague("Hong Kong Third Division A", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	hong_kong->AddLeague("Hong Kong Third Division B", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);

	NationLeagueInfo* china = add_nation_league_info("China PR");
	china->AddLeague("Chinese First Division A", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	china->AddLeague("Chinese First Division B", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	china->AddLeague("Chinese Second Division", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);

	NationLeagueInfo* luxembourg = add_nation_league_info("Luxembourg");
	luxembourg->AddLeague("Luxembourg National Division", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);

	// Luxembourg Second Division is spelt wrong in the original data
	if (find_club_comp("Luxembourg Second Dvision") != NULL)
		strcpy(find_club_comp("Luxembourg Second Dvision")->ClubCompName, "Luxembourg Second Division");

	luxembourg->AddLeague("Luxembourg Second Division", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);

	NationLeagueInfo* malaysia = add_nation_league_info("Malaysia");
	malaysia->AddLeague("Malaysian League Premier One", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	malaysia->AddLeague("Malaysian League Premier Two", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);

	NationLeagueInfo* mexico = add_nation_league_info("Mexico");
	mexico->AddLeague("Mexican First Division", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	mexico->AddLeague("Mexican First Division A", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);

	NationLeagueInfo* south_africa = add_nation_league_info("South Africa");
	south_africa->AddLeague("South African Premier Division", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	south_africa->AddLeague("South African First Division Inland", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	south_africa->AddLeague("South African First Division Coastal", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);

	NationLeagueInfo* yugoslavia = add_nation_league_info("Yugoslavia");
	yugoslavia->AddLeague("Yugoslav First Division", NULL, 1, 0, 0, 2, (DWORD)&eng_third_init_c);
	yugoslavia->AddLeague("Yugoslav Second Division East", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	yugoslavia->AddLeague("Yugoslav Second Division North", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	yugoslavia->AddLeague("Yugoslav Second Division South", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
	yugoslavia->AddLeague("Yugoslav Second Division West", NULL, 2, 0, 0, 2, (DWORD)&eng_third_init_c);
}
