#pragma once
#include <windows.h>

// text lengths
#define LONG_TXT_LENGTH 101
#define STANDARD_TXT_LENGTH 51
#define SHORT_TXT_LENGTH 26

#define SI_DOUBLE double

typedef struct cm3_continents CM3_CONTINENTS;
typedef struct cm3_nations CM3_NATIONS;
typedef struct cm3_cities CM3_CITIES;
typedef struct cm3_stadiums CM3_STADIUMS;
typedef struct cm3_colours CM3_COLOURS;
typedef struct cm3_clubs CM3_CLUBS;
typedef struct cm3_club_comps CM3_CLUB_COMPS;

#define CM3_STAFF DWORD*

struct cm3_continents
{
	// original data
	long ContinentID;
	char ContinentName[ SHORT_TXT_LENGTH ];
	char ContinentGenderName;
	char ContinentNameThreeLetter[ 4 ];
	char ContinentNameContinentality[ SHORT_TXT_LENGTH ];
	char ContinentFederationName[ LONG_TXT_LENGTH ];
	char ContinentGenderFederationName;
	char ContinentFederationNameShort[ SHORT_TXT_LENGTH ];
	char ContinentGenderFederationNameShort;
	SI_DOUBLE ContinentRegionalStrength;
};

#pragma pack(push, 1)
struct cm3_nations
{
	// original data
	long NationID;
	char NationName[ STANDARD_TXT_LENGTH ];
	char NationGenderName;
	char NationNameShort[ SHORT_TXT_LENGTH ];
	char NationGenderNameShort;
	char NationNameThreeLetter[ 4 ];
	char NationNameNationality[ SHORT_TXT_LENGTH ];
	CM3_CONTINENTS *NationContinent;
	char NationRegion;
	char NationActualRegion;
	char NationFirstLanguage;
	char NationSecondLanguage;
	char NationThirdLanguage;
	CM3_CITIES *NationCapitalCity;
	char NationStateOfDevelopment;
	char NationGroupMembership;
	CM3_STADIUMS *NationNationalStadium;
	char NationGameImportance;
	char NationLeagueStandard;
	short NationNumberClubs;
	long NationNumberStaff; // Version 0x02 - Added
	short NationSeasonUpdateDay; // Version 0x02 - Added
	short NationReputation; // Version 0x02 - Changed char->short
	CM3_COLOURS *NationForegroundColour1;
	CM3_COLOURS *NationBackgroundColour1;
	CM3_COLOURS *NationForegroundColour2;
	CM3_COLOURS *NationBackgroundColour2;
	CM3_COLOURS *NationForegroundColour3;
	CM3_COLOURS *NationBackgroundColour3;
	SI_DOUBLE NationFIFACoefficient;
	SI_DOUBLE NationFIFACoefficient91;
	SI_DOUBLE NationFIFACoefficient92;
	SI_DOUBLE NationFIFACoefficient93;
	SI_DOUBLE NationFIFACoefficient94;
	SI_DOUBLE NationFIFACoefficient95;
	SI_DOUBLE NationFIFACoefficient96;
	SI_DOUBLE NationUEFACoefficient91;
	SI_DOUBLE NationUEFACoefficient92;
	SI_DOUBLE NationUEFACoefficient93;
	SI_DOUBLE NationUEFACoefficient94;
	SI_DOUBLE NationUEFACoefficient95;
	SI_DOUBLE NationUEFACoefficient96;
	CM3_NATIONS *NationRivals1;
	CM3_NATIONS *NationRivals2;
	CM3_NATIONS *NationRivals3;

	// runtime data
	char NationLeagueSelected;
	long NationShortlistOffset; // Version 0x02 - Added
	char NationGamesPlayed; // Version 0x02 - Moved to runtime

	// char padding[291];  // Padding for other nations table??
};
#pragma pack(pop)

#pragma pack(push, 1)
struct cm3_cities
{
	// original data
	long CityID;
	char CityName[ SHORT_TXT_LENGTH ];
	char CityGenderName;
	CM3_NATIONS *CityNation;
	SI_DOUBLE CityLatitude;
	SI_DOUBLE CityLongitude;
	char CityAttraction;
	long CityWeather;
	// CITY_WEATHER *CityWeatherCity; // Weather city to use for this cities weather
};
#pragma pack(pop)

#pragma pack(push, 1)
struct cm3_colours
{
	long ColourID;
	char ColourName[ STANDARD_TXT_LENGTH ];
	unsigned char ColourRedIntensity;
	unsigned char ColourGreenIntensity;
	unsigned char ColourBlueIntensity;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct cm3_stadiums
{
	// original data
	long StadiumID;
	char StadiumName[ STANDARD_TXT_LENGTH ];
	char StadiumGenderName;
	CM3_CITIES *StadiumCity;
	long StadiumCapacity;
	long StadiumSeatingCapacity;
	long StadiumExpansionCapacity;
	CM3_STADIUMS *StadiumNearbyStadium;
	char StadiumCovered;
	char StadiumUnderSoilHeating;
};
#pragma pack(pop)

// club staff table sizes
#define DIRECTOR_SIZE 3
#define SQUAD_SIZE 50
#define SCOUT_SIZE 7
#define COACH_SIZE 5
#define PHYSIO_SIZE 3

// Maximum number of tactics in training at once
#define MAX_TACTIC_TRAINING 4

// Maximum size of a squad for a match
#define TEAM_SZ 20

#pragma pack(push, 1)
struct cm3_clubs
{
	// original data
	long ClubID;
	char ClubName[ STANDARD_TXT_LENGTH ];
	char ClubGenderName;
	char ClubNameShort[ SHORT_TXT_LENGTH ];
	char ClubGenderNameShort;
	CM3_NATIONS *ClubNation;
	CM3_CLUB_COMPS *ClubDivision;
	CM3_CLUB_COMPS *ClubLastDivision;
	char ClubLastPosition;
	CM3_CLUB_COMPS *ClubReserveDivision;
	char ClubProfessionalStatus;
	long ClubCash;
	CM3_STADIUMS *ClubStadium;
	char ClubOwnStadium;
	CM3_STADIUMS *ClubReserveStadium;
	char ClubHomeMatchDay;
	long ClubAttendance;
	long ClubMinAttendance;
	long ClubMaxAttendance;
	char ClubTraining;
	short ClubReputation; // Version 0x02 - Changed char->short
	char ClubPLC;
	CM3_COLOURS *ClubForegroundColour1;
	CM3_COLOURS *ClubBackgroundColour1;
	CM3_COLOURS *ClubForegroundColour2;
	CM3_COLOURS *ClubBackgroundColour2;
	CM3_COLOURS *ClubForegroundColour3;
	CM3_COLOURS *ClubBackgroundColour3;
	CM3_STAFF *ClubFavouriteStaff1;
	CM3_STAFF *ClubFavouriteStaff2;
	CM3_STAFF *ClubFavouriteStaff3;
	CM3_STAFF *ClubDislikedStaff1;
	CM3_STAFF *ClubDislikedStaff2;
	CM3_STAFF *ClubDislikedStaff3;
	CM3_CLUBS *ClubRivals1;
	CM3_CLUBS *ClubRivals2;
	CM3_CLUBS *ClubRivals3;
	CM3_STAFF *ClubChairman;
	CM3_STAFF *ClubDirectorList[ DIRECTOR_SIZE ];
	CM3_STAFF *ClubManager;
	CM3_STAFF *ClubAssistantManager;
	CM3_STAFF *ClubSquadList[ SQUAD_SIZE ];
	CM3_STAFF *ClubCoachList[ COACH_SIZE ];
	CM3_STAFF *ClubScoutList[ SCOUT_SIZE ];
	CM3_STAFF *ClubPhysioList[ PHYSIO_SIZE ];

	// runtime data
	long ClubEuroFlag;			// ID of the Euro Competition?
	char ClubEuroSeeding;
	CM3_STAFF *ClubTeamSelected[ TEAM_SZ ];
	long ClubTacticTraining[ MAX_TACTIC_TRAINING ];
	long ClubTacticSelected;
	char ClubHasLinkedClub;
};
#pragma pack(pop)


#pragma pack(push, 1)
typedef struct comp
{
	unsigned int* competitions_off;					//0
	unsigned int competition_db;					//4	
	char* unknown;									//8
	char pad44[16];									//28
	int f28;										//32
	int f32;										//36
	char pad40[4];									//40
	unsigned int f40;								//44
	int f44;										//48
	int f48;										//52
	char pad58[6];									//58
	unsigned short f58;								//60
	unsigned short rounds;							//62
	unsigned short teams;							//64
	unsigned short year;							//66
	char f66;										//67
	char f67;										//68
	char f68;										//69
	char pad73[4];									//73
	char max_bench;									//74
	char max_subs;									//75
	char pad80[5];									//80
	char f80;										//81
	char f81;										//82
	char f82;										//83
	char padx[84];									//167
	unsigned short f167;
	unsigned short f169;							//171
	unsigned short f171;							//173
	unsigned int pad177;							//177
	unsigned char* team_league_dta;					//181
	char pad186[5];									//186
	int f186;										//190
	char promotion;
	char prom_playoff;
	char f193;
	char relegations;
	char f194;
	char f195;
	char f196;
	char f197;
	char f198;
	char f199;										//199
	char pad217[17];								//217
	short f217;										//219
	short f219;										//221
	unsigned int f221;								//225
	char f225;										//226
	char pad237[11];								//237
	unsigned char lastchar;
} comp_s;
#pragma pack(pop)

#pragma pack(push, 1)
struct cm3_club_comps
{
	long ClubCompID;
	char ClubCompName[ STANDARD_TXT_LENGTH ];
	char ClubCompGenderName;
	char ClubCompNameShort[ SHORT_TXT_LENGTH ];
	char ClubCompGenderNameShort;
	char ClubCompNameThreeLetter[ 4 ];
	char ClubCompScope;
	char ClubCompSelected;
	CM3_CONTINENTS *ClubCompContinent;
	CM3_NATIONS *ClubCompNation;
	CM3_COLOURS *ClubCompForegroundColour;
	CM3_COLOURS *ClubCompBackgroundColour;
	short ClubCompReputation; // Version 0x02 - Changed char->short
};
#pragma pack(pop)

extern cm3_continents** continents;
extern DWORD* continents_count;

extern cm3_nations **nations;
extern DWORD *nations_count;

extern cm3_clubs **clubs;
extern DWORD *clubs_count;

extern cm3_club_comps **club_comps;
extern DWORD *club_comps_count;

extern DWORD* current_year;