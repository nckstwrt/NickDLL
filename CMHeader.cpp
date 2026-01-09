#include "CMHeader.h"

cm3_continents **continents = (cm3_continents **)0xAE23A4;
DWORD* continents_count = (DWORD*)0xAE234C;

cm3_nations **nations = (cm3_nations **)0xAE23A8;
DWORD *nations_count = (DWORD *)0xAE2350;

cm3_clubs **clubs = (cm3_clubs **)0xAE23B4;
DWORD *clubs_count = (DWORD *)0xAE235C;

cm3_club_comps **club_comps = (cm3_club_comps **)0xAE23D0;
DWORD *club_comps_count = (DWORD *)0xAE2378;

DWORD *current_year = (DWORD*)0xAE2C92;

DWORD** loaded_leagues = (DWORD**)0xADADFC;