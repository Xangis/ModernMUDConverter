
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include "merc.h"

/* 
 * Race types
 */
// Races must be kept in order and player-available races must be first
// in the list.  If a race becomes player available, move it to the first
// part of the race definitions
const   struct    race_type       race_table      [MAX_RACE]	=
{
// 0
    {
	"Human",
	"&+CHuman&n",
        "PH",
	RACE_PC_AVAIL | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        70, 155,
        50,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_COMMON,
        RACEWAR_GOOD,
        17, 90, &race_human
    },

// 1
    {
	"Barbarian",
	"&+BBarbarian&n",
        "PB",
	RACE_PC_AVAIL | RACE_WEAPON_WIELD | RACE_BODYSLAM | RACE_DOORBASH,
	SIZE_BIG,
        75, 205,
        0,
	138, 85, 85, 95, 142, 90, 90, 90, 90,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_BARBARIAN,
        RACEWAR_GOOD,
        16, 80, &race_barbarian
    },

// 2
    {
	"Grey Elf",
	"&+cGrey Elf&n",
        "PE",
	RACE_PC_AVAIL | RACE_INFRAVISION | RACE_WEAPON_WIELD |
		RACE_ODSNEAK | RACE_SHRUG,
	SIZE_PETITE,
        66, 135,
        100,
	90, 120, 110, 100, 85, 110, 100, 100, 110,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_CHARM,
	RIS_NONE,
	RIS_IRON,
	LANG_ELVEN,
        RACEWAR_GOOD,
        100, 900, &race_grey_elf
    },

// 3
    {
	"Rakshasa",
	"&+RRak&+Yshasa&n",
        "RA",
	RACE_PC_AVAIL | RACE_ULTRAVISION | RACE_WEAPON_WIELD | 
		RACE_SHRUG | RACE_UDSNEAK,
	SIZE_MEDIUM,
        72, 150,
        -700,
	84, 122, 112, 101, 87, 110, 100, 100, 105,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_CHARM,
	RIS_NONE,
	RIS_IRON,
	LANG_RAKSHASA,
        RACEWAR_EVIL,
        17, 90, &race_rakshasa
    },

// 4
    {
	"Half-Elf",
	"&+cHalf&+C-Elf&n",
        "P2",
	RACE_PC_AVAIL | RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        68, 145,
        0,
	95, 105, 100, 105, 95, 105, 90, 100, 102,
	0, 2, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_CHARM | RIS_POISON,
	RIS_NONE,
	RIS_IRON,
	LANG_COMMON,
        RACEWAR_GOOD,
        18, 200, &race_half_elf
    },

// 5
// Flind suck.
// They might make okay rogue or assassin types, average clerics and casters,
// but they have nothing in which to make them excel.

    {
	"Flind",
	"&+MFlind&n",
        "FL",
	RACE_PC_AVAIL | RACE_ULTRAVISION | RACE_WEAPON_WIELD | RACE_BITE,
	SIZE_BIG,
        73, 160,
        -500,
	105, 101, 99, 105, 99, 108, 90, 90, 103,
	0, 2, 0,
	0, 0,
	"bites",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_CHARM | RIS_POISON,
	RIS_NONE,
	RIS_IRON,
	LANG_FLIND,
        RACEWAR_EVIL,
        14, 70, &race_gnoll
    },

// 6
    {
	"Drow Elf",
	"&+mDrow Elf&n",
        "PL",
	RACE_PC_AVAIL | RACE_ULTRAVISION | RACE_WEAPON_WIELD | 
		RACE_LEVITATE | RACE_SHRUG | RACE_FAERIE_FIRE,
	SIZE_PETITE,
        65, 130,
        -925,
	80, 125, 110, 115, 78, 120, 70, 110, 110,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_MAGIC,
	RIS_NONE,
	RIS_NONE,
	LANG_DROW,
        RACEWAR_EVIL,
        50, 600, &race_drow_elf
    },

// 7
    {
	"Dwarf",
	"&+YDwarf&n",
        "PM",
	RACE_PC_AVAIL | RACE_INFRAVISION | RACE_STRENGTH
		| RACE_WEAPON_WIELD,
	SIZE_PETITE,
        49, 190,
        250,
	123, 80, 105, 85, 123, 95, 80, 95, 100,
	0, 0, 0,
	0, 1,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_POISON | RIS_DISEASE,
	RIS_NONE,
	RIS_DROWNING,
	LANG_DWARVEN,
        RACEWAR_GOOD,
        40, 250, &race_dwarf
    },

// 8
    {
	"Duergar",
	"&+rDuergar&n",
        "PD",
	RACE_PC_AVAIL | RACE_ULTRAVISION | RACE_WEAPON_WIELD | RACE_UDSNEAK | RACE_ENLARGE | RACE_INVIS,
	SIZE_SMALL,
        48, 175,
        -750,
	120, 80, 100, 95, 120, 100, 75, 85, 100,
	0, 0, 0,
	0, 1,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_POISON | RIS_DISEASE,
	RIS_NONE,
	RIS_DROWNING,
	LANG_DUERGAR,
        RACEWAR_EVIL,
        30, 225, &race_duergar
    },

// 9
    {
	"Halfling",
	"&+yHalfling&n",
        "PF",
	RACE_PC_AVAIL | RACE_INFRAVISION | RACE_WEAPON_WIELD | RACE_STEAL,
	SIZE_SMALL,
        38, 85,
        50,
	75, 90, 95, 140, 90, 140, 100, 100, 135,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_POISON | RIS_DISEASE | RIS_MAGIC,
	RIS_NONE,
	RIS_NONE,
	LANG_HALFLING,
        RACEWAR_GOOD,
        15, 70, &race_halfling
    },

// 10
    {
	"Troll",
	"&+gTroll&n",
        "PT",
	RACE_PC_AVAIL | RACE_ULTRAVISION | RACE_WEAPON_WIELD | 
		RACE_BODYSLAM | RACE_DOORBASH,
	SIZE_LARGE,
        89, 255,
        -450,
	120, 70, 75, 80, 130, 80, 65, 70, 90,
	10, 0, 0,
	0, 3,
	"fist",
        "walks",
	"Human Elf Halfelf Dwarf Halfdwarf Hobbit Vampire Werewolf Gnome",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_CLAWS | PART_FANGS,
	RIS_CHARM | RIS_BASH,
	RIS_NONE,
	RIS_FIRE | RIS_ACID,
	LANG_TROLL,
        RACEWAR_EVIL,
        12, 45, &race_troll
    },

// 11
    {
	"Ogre",
	"&+bOgre&n",
        "PO",
	RACE_PC_AVAIL | RACE_WEAPON_WIELD | RACE_BODYSLAM | 
		RACE_DOORBASH | RACE_ULTRAVISION |
                RACE_EXTRA_STRONG_WIELD,
	SIZE_HUGE,
        96, 650,
        -400,
	147, 55, 55, 60, 150, 65, 65, 40, 65,
	2, -3, -1,
	0, 2,
	"fist",
        "lumbers",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_MENTAL,
	LANG_OGRE,
        RACEWAR_EVIL,
        14, 60, &race_ogre
    },

// 12
    {
	"Orc",
	"&+LOrc&n",
        "HO",
	RACE_PC_AVAIL | RACE_ULTRAVISION | RACE_WEAPON_WIELD | 
		RACE_SUMMON_HOARDE,
	SIZE_MEDIUM,
        71, 165,
        -350,
	110, 100, 95, 99, 105, 99, 90, 99, 99,
	2, -1, -1,
	0, 1,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_DISEASE,
	RIS_NONE,
	RIS_NONE,
	LANG_ORC,
        RACEWAR_EVIL,
        16, 85, &race_orc
    },

// 13
    {
	"Gnome",
	"&+RGnome&n",
        "PG",
	RACE_PC_AVAIL | RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_SMALL,
        43, 80,
        150,
	80, 130, 110, 105, 110, 105, 90, 110, 150,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_POISON | RIS_DISEASE | RIS_MAGIC,
	RIS_NONE,
	RIS_NONE,
	LANG_GNOME,
        RACEWAR_GOOD,
        35, 180, &race_gnome
    },

// 14
    {
	"Centaur",
	"&+gCen&+Ltaur&n",
        "CT",
	RACE_PC_AVAIL | RACE_WEAPON_WIELD | RACE_BODYSLAM | RACE_DOORBASH | RACE_EXTRA_STRONG_WIELD,
	SIZE_LARGE,
        74, 450,
        75,
	140, 65, 82, 83, 145, 82, 80, 100, 95,
	3, 0, -1,
	0, 3,
	"fist",
        "trots",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_TAIL,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_CENTAUR,
        RACEWAR_GOOD,
        10, 40, &race_centaur
    },

// 15
    {
	"Githyanki",
	"&+GGith&+Wyanki&n",
        "GI",
	RACE_PC_AVAIL | RACE_WEAPON_WIELD | RACE_ULTRAVISION | RACE_SHRUG |
		RACE_SHIFT_PRIME | RACE_SHIFT_ASTRAL,
	SIZE_MEDIUM,
        70, 140,
        -975,
	90, 120, 110, 90, 90, 90, 70, 140, 90,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"Illithid",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_GITHYANKI,
        RACEWAR_EVIL,
        17, 120, &race_githyanki
    },


// 16
    {
	"Goblin",
	"&+GGoblin&n",
        "HG",
	RACE_ULTRAVISION | RACE_WEAPON_WIELD | RACE_PC_AVAIL,
	SIZE_SMALL,
        52, 100,
        -600,
	80, 105, 130, 110, 105, 110, 70, 70, 110,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"Elf Halfelf Dwarf Halfdwarf Hobbit Vampire Werewolf Gnome",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_TUSKS,
	RIS_DISEASE,
	RIS_NONE,
	RIS_MAGIC,
	LANG_GOBLIN,
        RACEWAR_EVIL,
        15, 70, &race_goblin
    },

// 17

    {
	"Minotaur",
	"&+rMino&+Ltaur&n",
        "MT",
	RACE_WEAPON_WIELD | RACE_BODYSLAM | RACE_PC_AVAIL | RACE_CHARGE |
		RACE_ULTRAVISION | RACE_DOORBASH,
	SIZE_BIG,
        80, 270,
        -250,
	145, 80, 90, 90, 135, 90, 80, 100, 100,
	3, 0, -1,
	0, 3,
	"fist",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_TAIL | PART_HORNS,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_MINOTAUR,
        RACEWAR_EVIL,
        22, 90, &race_minotaur
    },


// 18
    {
	"Githzerai",
	"&+GGith&n&+yzerai&n",
        "GZ",
	RACE_PC_AVAIL | RACE_WEAPON_WIELD | RACE_ULTRAVISION | RACE_SHRUG,
	SIZE_MEDIUM,
        70, 140,
        -975,
	98, 100, 105, 110, 97, 110, 80, 140, 94,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"Illithid",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_GITHZERAI,
        RACEWAR_GOOD,
        17, 120, &race_githzerai
    },

// 19
    {
	"Thri-Kreen",
	"&+GThri-&+YKreen&n",
        "TK",
	RACE_WEAPON_WIELD | RACE_PC_AVAIL,
	SIZE_MEDIUM,
        72, 250,
        -50,
	100, 96, 96, 88, 88, 105, 80, 137, 70,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_COLD,
	LANG_THRI_KREEN,
        RACEWAR_NONE,
        7, 35, &race_thri_kreen
    },

// End of PC available races.  If you want to add a PC available race,
// you will need to place them before this comment, increase MAX_PC_RACE
// in merc.h by one, and edit the class_avail chart in this file do
// determine what classes they get

// 20
    {
	"Aquatic Elf",
	"&+bAquatic Elf&n",
        "PA",
	RACE_INFRAVISION | RACE_WEAPON_WIELD | RACE_SWIM,
	SIZE_MEDIUM,
        65, 110,
        0,
	95, 105, 120, 105, 90, 115, 100, 95, 100,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_CHARM,
	RIS_NONE,
	RIS_IRON,
	LANG_AQUA_ELF,
        RACEWAR_NONE,
        17, 90, &race_aquatic_elf
    },

// 21
    {
	"Sahaugin",
	"&+bSahau&+ggin&n",
        "SA",
	RACE_INFRAVISION | RACE_WEAPON_WIELD | RACE_SWIM,
	SIZE_MEDIUM,
        72, 150,
        0,
	115, 85, 95, 105, 90, 115, 100, 95, 100,
	0, 4, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_CHARM,
	RIS_NONE,
	RIS_IRON,
	LANG_ELVEN,
        RACEWAR_NONE,
        17, 90, &race_sahaugin
    },

// 22
    {
	"Half-Orc",
	"&+cHalf&n-&+LOrc&n",
        "H2",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	105, 98, 100, 98, 102, 98, 94, 98, 98,
	2, -1, -1,
	0, 1,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_DISEASE,
	RIS_NONE,
	RIS_NONE,
	LANG_ORC,
        RACEWAR_NONE,
        17, 90, &race_half_orc
    },

// 23
    {
	"Half-Dwarf",
	"&+CHalf-&+YDwarf&n",
        "D2",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_PETITE,
        72, 150,
        0,
	110, 95, 100, 95, 110, 95, 95, 100, 100,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_POISON | RIS_DISEASE,
	RIS_NONE,
	RIS_DROWNING,
	LANG_DWARVEN,
        RACEWAR_NONE,
        17, 90, &race_half_dwarf
    },

// 24
    {
	"Half-Kobold",
	"&+CHalf-&+rKobold&n",
        "K2",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_PETITE,
        72, 150,
        0,
	85, 85, 85, 110, 95, 110, 65, 75, 110,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_TAIL,
	RIS_POISON,
	RIS_NONE,
	RIS_MAGIC,
	LANG_KOBOLD
        ,RACEWAR_NONE,
        17, 90, &race_kobold
    },

// 25
    {
	"Giant",
	"Giant",
        "G",
	RACE_WEAPON_WIELD,
	SIZE_GIANT,
        72, 150,
        0,
	170, 70, 100, 80, 130, 90, 90, 80, 100,
	3, -5, -2,
	2, 4,
	"fist",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_FIRE | RIS_COLD,
	RIS_NONE,
	RIS_MENTAL,
	LANG_COMMON
        ,RACEWAR_NONE,
        17, 90, &race_giant
    },

// 26
    {
	"Illithid",
	"&+mIllithid&n",
        "MF",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	60, 160, 130, 80, 70, 90, 70, 160, 90,
	0, 6, 0,
	0, 0,
	"punch",
        "walks",
	"Githyanki",
	PART_LEGS | PART_HEART | PART_GUTS | PART_FEET | PART_TENTACLES,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_COMMON
        ,RACEWAR_NONE,
        17, 90, &race_illithid
    },

// 27
    {
	"Neogi",
	"&+LN&+me&+Lo&+mg&+Li&n",
        "NE",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	75, 160, 135, 90, 75, 95, 40, 170, 100,
	0, 6, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_LEGS | PART_HEART | PART_GUTS | PART_FEET,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_COMMON
        ,RACEWAR_NONE,
        17, 90, &race_neogi
    },

// 28
    {
	"Kobold",
	"&+rKobold&n",
        "K",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_SMALL,
        72, 150,
        0,
	80, 80, 85, 120, 90, 120, 60, 70, 115,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_TAIL,
	RIS_POISON,
	RIS_NONE,
	RIS_MAGIC,
	LANG_KOBOLD
        ,RACEWAR_NONE,
        17, 90, &race_kobold
    },

// 29
    {
	"Hobgoblin",
	"Hobgoblin",
        "HB",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_BIG,
        72, 150,
        0,
	110, 90, 85, 95, 115, 95, 90, 90, 90,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_DISEASE | RIS_POISON,
	RIS_NONE,
	RIS_NONE,
	LANG_COMMON
        ,RACEWAR_NONE,
        17, 90, &race_hobgoblin
    },

// 30
    {
	"Humanoid",
	"Humanoid",
        "H",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	100, 90, 85, 95, 100, 95, 90, 90, 90,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_DISEASE | RIS_POISON,
	RIS_NONE,
	RIS_NONE,
	LANG_COMMON
        ,RACEWAR_NONE,
        17, 90, &race_humanoid
    },

// 31
    {
	"Demon",
	"&+rDemon&n",
        "X",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
		RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD | RACE_SHRUG,
	SIZE_GARGANTUAN,
        72, 150,
        0,
	200, 130, 150, 120, 190, 120, 10, 160, 140,
	15, 0, -10,
	0, 10,
	"claw",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_WINGS | PART_TAIL | PART_CLAWS | PART_FANGS |
		PART_SCALES,
	RIS_BASH | RIS_CHARM,
	RIS_FIRE,
	RIS_PIERCE | RIS_COLD,
	LANG_DRAGON
        ,RACEWAR_NONE,
        17, 90, &race_demon
    },

// 32
    {
	"God",
	"&+WGod&n",
        "GD",
	RACE_WATERBREATH | RACE_FLY | RACE_WATERWALK |
		RACE_PASSDOOR | RACE_ULTRAVISION | RACE_DETECT_ALIGN |
		RACE_DETECT_INVIS | RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD | RACE_SHRUG,
	SIZE_GARGANTUAN,
        72, 150,
        0,
	250, 250, 250, 250, 250, 250, 250, 250, 250,
	20, 0, 10,
	0, 0,
	"smite",
        "struts",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_MAGIC | RIS_POISON | RIS_MENTAL | RIS_CHARM,
	RIS_DROWNING | RIS_DISEASE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_god
    },

// 33
    {
	"Devil",
	"&+rDevil&n",
        "Y",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
		RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD | RACE_SHRUG,
	SIZE_GARGANTUAN,
        72, 150,
        0,
	190, 180, 190, 140, 180, 140, 160, 190, 180,
	15, 0, -10,
	0, 10,
	"claw",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_WINGS | PART_TAIL | PART_CLAWS | PART_FANGS |
		PART_SCALES,
	RIS_BASH | RIS_CHARM,
	RIS_FIRE,
	RIS_PIERCE | RIS_COLD,
	LANG_DRAGON
        ,RACEWAR_NONE,
        17, 90, &race_devil
    },

	// 34
    {
	"Angel",
	"&+WAngel&n",
        "AN",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
		RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD | RACE_SHRUG,
	SIZE_MEDIUM,
        72, 150,
        0,
	180, 160, 180, 100, 150, 120, 140, 170, 120,
	15, 0, -10,
	0, 10,
	"hit",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_WINGS | PART_TAIL | PART_CLAWS | PART_FANGS |
		PART_SCALES,
	RIS_BASH | RIS_CHARM,
	RIS_FIRE,
	RIS_PIERCE | RIS_COLD,
	LANG_DRAGON,
        RACEWAR_NONE,
        17, 90, &race_angel
    },

// 35
    {
	"Faerie",
	"&+RFae&+Yrie&n",
        "HF",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_INVIS | RACE_DETECT_HIDDEN |
		RACE_WEAPON_WIELD,
	SIZE_TINY,
        72, 150,
        0,
	40, 130, 130, 170, 40, 150, 130, 120, 110,
	0, 0, 7,
	0, 0,
	"punch",
        "flutters",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_WINGS,
	RIS_MAGIC,
	RIS_NONE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_faerie
    },

// 36
    {
	"Vampire",
	"&+rVampire&n",
        "UV",
	RACE_FLY | RACE_PASSDOOR | RACE_INFRAVISION | RACE_DETECT_ALIGN |
		RACE_DETECT_INVIS | RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	135, 120, 110, 110, 120, 110, 130, 130, 100,
	10, 3, 3,
	-1, 10,
	"claw",
        "walks",
	"Human Elf Halfelf Drow Dwarf Halfdwarf Hobbit Giant Ogre Orc Kobold Minotaur Troll Hobgoblin Werewolf Goblin Faerie Gnome",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_FANGS,
	RIS_DISEASE | RIS_BLACK_MANA,
	RIS_POISON,
	RIS_DROWNING | RIS_WOOD | RIS_LIGHT | RIS_WHITE_MANA,
	LANG_COMMON
        ,RACEWAR_NONE,
        17, 90, &race_vampire
    },

// 37
    {
	"Werewolf",
	"&+yWere&+Lwolf&n",
        "LW",
	RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
	    RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	145, 90, 90, 120, 160, 120, 70, 110, 100,
	10, 0, 5,
	0, 5,
	"claw",
        "walks",
	"Human Elf Halfelf Drow Dwarf Halfdwarf Hobbit Giant Ogre Orc Kobold Minotaur Troll Hobgoblin Vampire Goblin Faerie Gnome",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_TAIL | PART_CLAWS | PART_FANGS,
	RIS_BASH,
	RIS_NONE,
	RIS_SILVER,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_werewolf
    },

// 38
    {
	"Dragon",
	"&+gDragon&n",
        "D",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
		RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_GARGANTUAN,
        72, 150,
        0,
	200, 140, 170, 90, 140, 90, 110, 120, 100,
	15, 0, -10,
	0, 10,
	"claw",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_WINGS | PART_TAIL | PART_CLAWS | PART_FANGS |
		PART_SCALES,
	RIS_FIRE | RIS_BASH | RIS_CHARM,
	RIS_NONE,
	RIS_PIERCE | RIS_COLD,
	LANG_DRAGON
        ,RACEWAR_NONE,
        17, 90, &race_dragon
    },

// 39
    {
	"Beholder",
	"&+LBe&+mhol&+Lder&n",
        "BH",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
		RACE_DETECT_HIDDEN,
	SIZE_HUGE,
        72, 150,
        0,
	110, 160, 160, 90, 120, 100, 105, 160, 100,
	15, 0, -10,
	0, 10,
	"bite",
        "floats",
	"",
	PART_HEAD | PART_HEART | PART_BRAINS | PART_GUTS | PART_EYE | PART_SCALES |
           PART_EYESTALKS,
	RIS_FIRE | RIS_BASH | RIS_CHARM,
	RIS_NONE,
	RIS_PIERCE | RIS_COLD,
	LANG_DRAGON
        ,RACEWAR_NONE,
        17, 90, &race_beholder
    },

// 40
    {
	"Derro",
	"&+yDerro&n",
        "DE",
	RACE_INFRAVISION | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	105, 85, 90, 85, 100, 85, 85, 90, 90,
	0, 0, 0,
	0, 0,
	"punch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_POISON | RIS_DISEASE,
	RIS_NONE,
	RIS_DROWNING,
	LANG_DWARVEN,
        RACEWAR_NONE,
        17, 90, &race_derro
    },

// End of coin-carrying races.  If you want to have a race carry money on
// them, you will have to put it above this comment and augment the
// MAX_COIN_RACE in merc.h

// 41
    {
	"Golem",
	"Golem",
        "OG",
	RACE_WEAPON_WIELD | RACE_MUTE,
	SIZE_HUGE,
        72, 150,
        0,
	170, 50, 50, 80, 140, 90, 90, 80, 100,
	3, -5, -2,
	2, 4,
	"fist",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_FIRE | RIS_COLD,
	RIS_NONE,
	RIS_MENTAL,
	LANG_COMMON
        ,RACEWAR_NONE,
        17, 90, &race_golem
    },

// 42
    {
	"Dracolich",
	"&+gDraco&+Wlich&n",
        "UD",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
		RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_GARGANTUAN,
        72, 150,
        0,
	170, 90, 90, 90, 140, 90, 110, 120, 100,
	15, 0, -10,
	0, 10,
	"claw",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_WINGS | PART_TAIL | PART_CLAWS | PART_FANGS |
		PART_SCALES,
	RIS_FIRE | RIS_BASH | RIS_CHARM,
	RIS_NONE,
	RIS_PIERCE | RIS_COLD,
	LANG_DRAGON
        ,RACEWAR_NONE,
        17, 90, &race_dracolich
    },

// 43
    {
	"Dragonkin",
	"&+gDragon&+Wkin&n",
        "DK",
	RACE_FLY | RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
		RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_HUGE,
        72, 150,
        0,
	160, 110, 130, 90, 120, 90, 105, 110, 100,
	15, 0, -10,
	0, 10,
	"claw",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_WINGS | PART_TAIL | PART_CLAWS | PART_FANGS |
		PART_SCALES,
	RIS_FIRE | RIS_BASH | RIS_CHARM,
	RIS_NONE,
	RIS_PIERCE | RIS_COLD,
	LANG_DRAGON
        ,RACEWAR_NONE,
        17, 90, &race_dragonkin
    },

// 44
    {
	"Insect",
	"Insect",
        "I",
	RACE_MUTE,
	SIZE_TINY,
        72, 150,
        0,
	50, 10, 10, 80, 100, 100, 10, 10, 50,
	0, 0, 5,
	0, 0,
	"bite",
        "crawls",
	"",
	PART_HEAD | PART_LEGS | PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_insect
    },

// 45
    {
	"Animal",
	"Animal",
        "A",
	RACE_MUTE,
	SIZE_SMALL,
        72, 150,
        0,
	100, 40, 40, 80, 100, 100, 90, 40, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_GUTS | PART_FEET |
		PART_EAR | PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_MAGIC,
	LANG_ANIMAL
        ,RACEWAR_NONE,
        17, 90, &race_animal
    },

// 46
    {
	"Herbivore",
	"Herbivore",
        "AH",
	RACE_MUTE,
	SIZE_SMALL,
        72, 150,
        0,
	80, 50, 50, 80, 100, 110, 90, 40, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_GUTS | PART_FEET |
		PART_EAR | PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_MAGIC,
	LANG_ANIMAL
        ,RACEWAR_NONE,
        17, 90, &race_herbivore
    },

// 47
    {
	"Carnivore",
	"Carnivore",
        "AC",
	RACE_MUTE,
	SIZE_SMALL,
        72, 150,
        0,
	110, 50, 50, 90, 105, 105, 70, 30, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_GUTS | PART_FEET |
		PART_EAR | PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_MAGIC,
	LANG_ANIMAL
        ,RACEWAR_NONE,
        17, 90, &race_carnivore
    },

// 48
    {
	"Bird",
	"Bird",
        "B",
	RACE_FLY | RACE_DETECT_HIDDEN | RACE_MUTE,
	SIZE_SMALL,
        72, 150,
        0,
	100, 50, 50, 80, 100, 100, 90, 40, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_GUTS | PART_FEET |
		PART_EAR | PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_MAGIC,
	LANG_ANIMAL
        ,RACEWAR_NONE,
        17, 90, &race_bird
    },

// 49
    {
	"Horse",
	"&+yHorse&n",
        "AE",
	RACE_DETECT_HIDDEN | RACE_MUTE,
	SIZE_BIG,
        72, 150,
        0,
	110, 50, 50, 80, 105, 100, 90, 40, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "trots",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_GUTS | PART_FEET |
		PART_EAR | PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_MAGIC,
	LANG_ANIMAL
        ,RACEWAR_NONE,
        17, 90, &race_horse
    },

// 50
    {
	"Primate",
	"Primate",
        "AA",
	RACE_DETECT_HIDDEN | RACE_MUTE,
	SIZE_PETITE,
        72, 150,
        0,
	100, 70, 70, 90, 100, 100, 90, 50, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "walks",
	"Kobold Halfkobold",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_GUTS | PART_FEET |
		PART_EAR | PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_MAGIC,
	LANG_ANIMAL
        ,RACEWAR_NONE,
        17, 90, &race_primate
    },

	// 51
    {
	"Undead",
	"Undead",
        "U",
	RACE_INFRAVISION | RACE_DETECT_ALIGN |
	           RACE_DETECT_INVIS | RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	110, 10, 10, 50, 100, 50, 10, 120, 10,
	0, 0, 0,
	-1, -1,
	"touch",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_WEAPON,
	RIS_DISEASE | RIS_POISON,
	RIS_LIGHT | RIS_WHITE_MANA,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_undead
    },

	// 52
    {
	"Ghost",
	"&+WGhost&n",
        "UG",
	RACE_PASSDOOR | RACE_INFRAVISION | RACE_DETECT_ALIGN |
	           RACE_DETECT_INVIS | RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	110, 100, 100, 100, 100, 100, 10, 130, 70,
	0, 0, 0,
	-1, -1,
	"touch",
        "floats",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_WEAPON,
	RIS_DISEASE | RIS_POISON,
	RIS_LIGHT | RIS_WHITE_MANA,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_ghost
    },

	// 53
    {
	"Harpy",
	"Harpy",
        "HP",
	RACE_FLY | RACE_DETECT_INVIS | RACE_MUTE,
	SIZE_MEDIUM,
        72, 150,
        0,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 6,
	0, 0,
	"claw",
        "walks",
	"Human Elf Halfelf Dwarf Halfdwarf Hobbit Gnome",
	PART_HEAD | PART_LEGS | PART_HEART | PART_BRAINS | PART_GUTS |
		PART_FEET | PART_FINGERS | PART_EAR | PART_EYE | PART_WINGS |
		PART_TAIL | PART_CLAWS | PART_FANGS | PART_SCALES,
	RIS_SOUND,
	RIS_NONE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_harpy
    },

	// 54
    {
	"Bear",
	"&+yBear&n",
        "BE",
	RACE_DETECT_HIDDEN | RACE_MUTE,
	SIZE_LARGE,
        72, 150,
        0,
	120, 40, 45, 90, 110, 100, 100, 90, 100,
	0, 0, 0,
	0, 3,
	"swipe",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_EAR | PART_EYE |
		PART_CLAWS | PART_FANGS,
	RIS_BASH | RIS_COLD,
	RIS_NONE,
	RIS_NONE,
	LANG_ANIMAL,
        RACEWAR_NONE,
        17, 90, &race_bear
    },

	// 55
    {
	"Rust Monster",
	"&+rRust &+yMonster&n",
        "RM",
	RACE_MUTE,
	SIZE_LARGE,
        72, 150,
        0,
	120, 40, 45, 90, 110, 100, 100, 90, 100,
	0, 0, 0,
	0, 3,
	"bite",
        "walks",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_EAR | PART_EYE |
		PART_CLAWS | PART_FANGS,
	RIS_BASH | RIS_COLD,
	RIS_NONE,
	RIS_NONE,
	LANG_ANIMAL,
        RACEWAR_NONE,
        17, 90, &race_rust_monster
    },

	// 56
    {
	"Fire Elemental",
	"&+rFire Elemental&n",
        "EF",
	RACE_INFRAVISION,
	SIZE_LARGE,
        72, 150,
        0,
	110, 10, 10, 100, 110, 100, 10, 10, 10,
	0, 0, 0,
	-1, -1,
	"punch",
        "blazes",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_MAGICAL
        ,RACEWAR_NONE,
        17, 90, &race_fire_elemental
    },

	// 57
    {
	"Air Elemental",
	"&+CAir Elemental&n",
        "EA",
	RACE_INFRAVISION,
	SIZE_LARGE,
        72, 150,
        0,
	110, 10, 10, 100, 110, 100, 10, 10, 10,
	0, 0, 0,
	-1, -1,
	"punch",
        "blows",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_MAGICAL
        ,RACEWAR_NONE,
        17, 90, &race_air_elemental
    },

	// 58
    {
	"Water Elemental",
	"&+bWater Elemental&n",
        "EW",
	RACE_INFRAVISION,
	SIZE_LARGE,
        72, 150,
        0,
	110, 10, 10, 100, 110, 100, 10, 10, 10,
	0, 0, 0,
	-1, -1,
	"punch",
        "flows",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_MAGICAL
        ,RACEWAR_NONE,
        17, 90, &race_water_elemental
    },

	// 59
    {
	"Earth Elemental",
	"&+yEarth Elemental&n",
        "EE",
	RACE_INFRAVISION,
	SIZE_LARGE,
        72, 150,
        0,
	110, 10, 10, 100, 110, 100, 10, 10, 10,
	0, 0, 0,
	-1, -1,
	"punch",
        "lumbers",
	"",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_MAGICAL
        ,RACEWAR_NONE,
        17, 90, &race_earth_elemental
    },

	// 60
    {
	"Bat",
	"&+LBat&n",
        "BB",
	RACE_FLY | RACE_INFRAVISION | RACE_MUTE,
	SIZE_TINY,
        72, 150,
        0,
	40, 20, 20, 40, 90, 110, 20, 20, 100,
	0, 0, 4,
	0, 0,
	"bite",
        "flies",
	"",
	PART_HEAD | PART_LEGS | PART_HEART | PART_BRAINS | PART_GUTS |
		PART_FEET | PART_EAR | PART_EYE | PART_WINGS | PART_CLAWS |
		PART_FANGS,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_bat
    },

	// 61
    {
	"Plant",
	"&+gPlant&n",
        "VP",
	RACE_MUTE,
	SIZE_SMALL,
        72, 150,
        0,
	100, 10, 10, 50, 110, 60, 100, 70, 100,
	0, 0, 0,
	-1, 0,
	"swipe",
        "walks",
	"",
	PART_BARK | PART_LEAVES,
	RIS_DROWNING,
	RIS_NONE,
	RIS_FIRE | RIS_COLD,
 	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_plant
    },

	// 62
    {
	"Tree",
	"&+gTree&n",
        "VT",
	RACE_MUTE,
	SIZE_HUGE,
        72, 150,
        0,
	120, 10, 10, 50, 110, 60, 100, 70, 100,
	0, 0, 0,
	-1, 0,
	"swipe",
        "walks",
	"",
	PART_BARK | PART_BRANCHES | PART_LEAVES | PART_TRUNK,
	RIS_DROWNING,
	RIS_NONE,
	RIS_FIRE | RIS_COLD,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_tree
    },

	// 63
    {
	"Rat",
	"&+yRat&n",
        "AR",
	RACE_PASSDOOR | RACE_MUTE,
	SIZE_TINY,
        72, 150,
        0,
	35, 20, 20, 160, 70, 110, 30, 20, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "scurries",
	"",
	PART_HEAD | PART_LEGS | PART_HEART | PART_BRAINS | PART_GUTS |
		PART_FEET | PART_EAR | PART_EYE | PART_FANGS,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_rat
    },

	// 64
    {
	"Parasite",
	"Parasite",
        "AP",
	RACE_MUTE,
	SIZE_TINY,
        72, 150,
        0,
	35, 20, 20, 40, 70, 40, 30, 20, 40,
	0, 0, 0,
	0, 0,
	"bite",
        "walks",
	"",
	PART_HEAD | PART_LEGS | PART_HEART | PART_BRAINS | PART_GUTS |
		PART_FEET | PART_EAR | PART_EYE | PART_FANGS,
	RIS_NONE,
	RIS_NONE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_parasite
    },

	// 65
    {
	"Lycanthrope",
	"&+yLycanthrope&n",
        "L",
	RACE_INFRAVISION | RACE_DETECT_ALIGN | RACE_DETECT_INVIS |
	    RACE_DETECT_HIDDEN | RACE_WEAPON_WIELD,
	SIZE_MEDIUM,
        72, 150,
        0,
	130, 90, 90, 110, 140, 110, 70, 100, 100,
	10, 0, 5,
	0, 5,
	"claw",
        "walks",
	"Human Elf Halfelf Drow Dwarf Halfdwarf Hobbit Giant Ogre Orc Kobold Minotaur Troll Hobgoblin Vampire Goblin Faerie Gnome",
	PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
		PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
		PART_EYE | PART_TAIL | PART_CLAWS | PART_FANGS,
	RIS_BASH,
	RIS_NONE,
	RIS_SILVER,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_lycanthrope
    },

	// 66
    {
	"Arachnid",
	"Arachnid",
        "AS",
	RACE_NO_ABILITIES | RACE_WEAPON_WIELD | RACE_MUTE,
	SIZE_SMALL,
        72, 150,
        0,
	70, 10, 10, 80, 100, 100, 10, 10, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "crawls",
	"",
	PART_HEAD | PART_LEGS | PART_HEART | PART_FEET | PART_EYE |
		PART_FANGS,
	RIS_POISON,
	RIS_NONE,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_arachnid
    },

	// 67
    {
	"Object",
	"Object",
        "O",
	RACE_WATERBREATH | RACE_MUTE,
	SIZE_BIG,
        72, 150,
        0,
	100, 10, 10, 10, 100, 10, 10, 10, 10,
	0, 0, 0,
	-1, -1,
	"swing",
        "moves",
	"",
	PART_NONE,
	RIS_LIGHT,
	RIS_POISON | RIS_DISEASE | RIS_DROWNING,
	RIS_ENERGY,
	LANG_MAGICAL
        ,RACEWAR_NONE,
        17, 90, &race_object
    },

	// 68
    {
	"Mist",
	"Mist",
        "M",
	RACE_FLY | RACE_PASSDOOR | RACE_MUTE,
	SIZE_PETITE,
        72, 150,
        0,
	30, 100, 100, 100, 100, 100, 10, 100, 100,
	0, 0, 20,
	-1, -1,
	"gas",
        "floats",
	"",
	PART_NONE,
	RIS_NONE,
	RIS_DISEASE | RIS_POISON,
	RIS_MAGIC,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_mist
    },

	// 69
    {
	"Snake",
	"&+gSnake&n",
        "RS",
	RACE_MUTE,
	SIZE_TINY,
        72, 150,
        0,
	100, 60, 60, 110, 100, 110, 100, 60, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "slithers",
	"",
	PART_HEAD | PART_HEART | PART_BRAINS | PART_GUTS | PART_EYE |
		PART_TAIL | PART_FANGS | PART_SCALES,
	RIS_POISON,
	RIS_NONE,
	RIS_COLD,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_snake
    },

	// 70
    {
	"Worm",
	"Worm",
        "AW",
	RACE_PASSDOOR | RACE_MUTE,
	SIZE_TINY,
        72, 150,
        0,
	100, 10, 10, 30, 100, 40, 10, 10, 100,
	0, 0, 0,
	0, 0,
	"slime",
        "crawls",
	"",
	PART_HEAD | PART_TAIL,
	RIS_NONE,
	RIS_NONE,
	RIS_BASH,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_worm
    },

	// 71
    {
	"Fish",
	"&+bFish&n",
        "F",
	RACE_WATERBREATH | RACE_SWIM | RACE_MUTE,
	SIZE_TINY,
        72, 150,
        0,
	70, 40, 40, 120, 100, 120, 100, 40, 100,
	0, 0, 0,
	-1, 0,
	"slap",
        "swims",
	"",
	PART_HEAD | PART_HEART | PART_BRAINS | PART_GUTS | PART_EYE |
		PART_TAIL | PART_SCALES | PART_FINS,
	RIS_NONE,
	RIS_DROWNING,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_fish
    },

	// 72
    {
	"Ixitxachitl",
	"&+mIxitxachitlh&n",
        "IX",
	RACE_SWIM | RACE_MUTE,
	SIZE_PETITE,
        72, 150,
        0,
	70, 40, 40, 120, 100, 120, 100, 40, 100,
	0, 0, 0,
	-1, 0,
	"sting",
        "swims",
	"",
	PART_HEAD | PART_HEART | PART_BRAINS | PART_GUTS | PART_EYE |
		PART_TAIL | PART_SCALES | PART_FINS,
	RIS_NONE,
	RIS_DROWNING,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_ixitxachitl
    },

	// 73
    {
	"Aboleth",
	"&+bAboleth&n",
        "AB",
	RACE_SWIM | RACE_MUTE,
	SIZE_MEDIUM,
        72, 150,
        0,
	70, 120, 120, 120, 100, 120, 100, 40, 100,
	0, 0, 0,
	-1, 0,
	"hit",
        "swims",
	"",
	PART_HEAD | PART_HEART | PART_BRAINS | PART_GUTS | PART_EYE |
		PART_TAIL | PART_SCALES | PART_FINS,
	RIS_NONE,
	RIS_DROWNING,
	RIS_NONE,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_aboleth
    },

	// 74
    {
	"Hydra",
	"&+gHydra&n",
        "DH",
	RACE_DETECT_HIDDEN | RACE_MUTE,
	SIZE_TITANIC,
        72, 150,
        0,
	180, 90, 90, 90, 170, 90, 50, 100, 100,
	0, 0, 0,
	0, 0,
	"bite",
        "walks",
	"",
	PART_HEAD | PART_LEGS | PART_HEART | PART_BRAINS | PART_GUTS |
		PART_FEET | PART_EYE | PART_TAIL | PART_FANGS | PART_SCALES,
	RIS_BASH,
	RIS_NONE,
	RIS_PIERCE,
	LANG_DRAGON
        ,RACEWAR_NONE,
        17, 90, &race_hydra
    },

	// 75
    {
	"Reptile",
	"&+gReptile&n",
        "R",
	RACE_MUTE,
	SIZE_PETITE,
        72, 150,
        0,
	70, 70, 70, 100, 100, 100, 70, 70, 100,
	0, 0, 0,
	0, 0,
	"lash",
        "walks",
	"",
	PART_HEAD | PART_LEGS | PART_HEART | PART_BRAINS | PART_GUTS |
		PART_FEET | PART_EYE | PART_TAIL | PART_FANGS,
	RIS_POISON,
	RIS_NONE,
	RIS_COLD,
	LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_reptile
    },

    // 76
    {
        "Boar",
        "Boar",
        "BO",
        RACE_MUTE,
        SIZE_MEDIUM,
        42, 150,
        0,
        105, 50, 50, 75, 105, 100, 90, 40, 100,
        0, 0, 0,
        0, 0,
        "tusk",
        "walks",
        "",
        PART_HEAD | PART_LEGS | PART_HEART | PART_GUTS | PART_FEET | PART_EAR | PART_EYE,
        RIS_NONE,
        RIS_NONE,
        RIS_NONE,
        LANG_ANIMAL,
        RACEWAR_NONE,
        17, 90, &race_boar
    },

	// 77
    {
	    "Umber Hulk",
	    "&+yUmber &+LHulk&n",
        "UH",
	    RACE_INFRAVISION,
	    SIZE_LARGE,
        72, 150,
        0,
	    110, 10, 10, 100, 110, 100, 10, 10, 10,
	    0, 0, 0,
	    -1, -1,
	    "claw",
        "lumbers",
	    "",
	    PART_HEAD | PART_ARMS | PART_LEGS | PART_HEART | PART_BRAINS |
	    PART_GUTS | PART_HANDS | PART_FEET | PART_FINGERS | PART_EAR |
	    PART_EYE,
	    RIS_NONE,
	    RIS_NONE,
	    RIS_NONE,
	    LANG_UNKNOWN,
        RACEWAR_NONE,
        17, 90, &race_air_elemental
    },

};

struct	skill_type	skills_table	[MAX_SKILL]	=
{
    {
	"reserved",		{ L_APP },
	NULL,			0,
	"",			"",
    },

/*
 * Fighter and thief skills, as well as magic item skills.
 */
    {
	"backstab",		{ L_APP },
	&gsn_backstab,		15,
	"vicious backstab",	"!Backstab!",
    },

    {
	"doorbash", 	 	{ L_APP },
	&gsn_doorbash,		24,
	"powerful bash",	"!DoorBash!",
    },

    {
        "berserk",              { L_APP },
        &gsn_berserk,           12,
        "",                     "The &+rbloody&n haze lifts.",
    },

    {
        "circle",		{ L_APP },
        &gsn_circle,		12,
        "sneak attack",		"!Circle!",
    },

    {
	"disarm",		{ L_APP },
	&gsn_disarm,		36,
	"",			"!Disarm!",
    },

    {
	"dodge",		{ L_APP },
	&gsn_dodge,		0,
	"",			"!Dodge!",
    },

    {
        "dual wield",         	{ L_APP },
        &gsn_dual,      	0,
        "",                     "!Dual!",
    },

    {
	"offense",		{ L_APP },
	&gsn_enhanced_damage,	0,
	"",			"!Enhanced Damage!",
    },

    {
	"hide",			{ L_APP },
	&gsn_hide,		12,
	"",			"!Hide!",
    },

    {
	"kick",			{ L_APP },
	&gsn_kick,		22,
	"kick",		"!Kick!",
    },

    {
	"bash",			{ L_APP },
	&gsn_bash,		27,
	"mighty bash",		"!Bash!",
    },

    {
	"springleap",		{ L_APP },
	&gsn_springleap,	28,
	"springleap",		"!Springleap!",
    },

    {
	"charge",		{ L_APP },
	&gsn_charge,		20,
	"wild charge",		"!Charge!",
    },

    {
	"bodyslam",		{ L_APP },
	&gsn_bodyslam,		34,
	"mighty slam",		"!Bodyslam!",
    },

    {
	"headbutt",		{ L_APP },
	&gsn_headbutt,		28,
	"headbutt",		"!Headbutt!",
    },

    {
	"parry",		{ L_APP },
	&gsn_parry,		0,
	"",			"!Parry!",
    },

    {
	"riposte",		{ L_APP },
	&gsn_riposte,		0,
	"",			"!Riposte!",
    },

    {
	"peek",			{ L_APP },
	&gsn_peek,		0,
	"",			"!Peek!",
    },

    {
	"pick lock",		{ L_APP },
	&gsn_pick_lock,		12,
	"",			"!Pick!",
    },

    {
        "poison",        { L_APP },
        &gsn_poison,     12,
        "poison",        "!Poison!",
    },

    {
        "poison bite",        { L_APP },
        &gsn_poison_bite,     12,
        "poison bite",        "You feel the poison dissipate.",
    },

    {
	"poison weapon",	{ L_APP },
	&gsn_poison_weapon,	12,
	"poison weapon",	"!Poison Weapon!",
    },

    {
	"rescue",		{ L_APP },
	&gsn_rescue,		12,
	"",			"!Rescue!",
    },

    {
	"scrolls",      	{ L_APP },
	&gsn_scrolls,	 	0,
	"blazing scroll",	"!Scrolls!",
    },

    {
	"second attack",	{ L_APP },
	&gsn_second_attack,	0,
	"",			"!Second Attack!",
    },

    {
	"capture",		{ L_APP },
	&gsn_capture,		12,
	"",			"You are no longer captured.",
    },

    {
	"sneak",		{ L_APP },
	&gsn_sneak,		12,
	"",			NULL,
    },

    {
	"staves",       	{ L_APP },
	&gsn_staves,	 	0,
	"shattered staff",	"!Staves!",
    },

    {
	"steal",		{ L_APP },
	&gsn_steal,		24,
	"",			"!Steal!",
    },

    {
	"third attack",		{ L_APP },
	&gsn_third_attack,	0,
	"",			"!Third Attack!",
    },

    {
        "untangle",		{ L_APP },
        &gsn_untangle,		24,
        "",                     "!Untangle!",
    },

    {
	"wands",        	{ L_APP },
	&gsn_wands,	 	0,
	"exploding wand",	"!Wands!",
    },

    {
        "chameleon power",      { L_APP },
        &gsn_chameleon,         12,
        "",                     "!Chameleon Power!",
    },

    {
        "heighten senses",      { L_APP },
        &gsn_heighten,          0,
        "",                     "Your senses return to normal.",
    },

    {
        "shadow form",          { L_APP },
        &gsn_shadow,            12,
        "",                     "You no longer move in the shadows.",
    },

    {
        "shield block",         { L_APP },
        &gsn_shield_block,      0,
        "",                     "!Shield Block!",
    },

    {
        "fast healing",         { L_APP },
        &gsn_fast_healing,      0,
        "",                     "!Fast Healing!",
    },

   {
        "fourth attack",        { L_APP },
        &gsn_fourth_attack,     0,
        "",                     "!Fourth Attack!",
    },

    {
	"brew",			{ L_APP },
	&gsn_brew,		24,
	"blunder",		"!Brew!",
    },

    {
	"scribe",		{ L_APP },
	&gsn_scribe,		24,
	"blunder",		"!Scribe!",
    },

    {
        "track",		{ L_APP },
        &gsn_track,		3,
        "",			"!Track!",
    },

    {
	"whirlwind",		{ L_APP },
	&gsn_whirlwind,		22,
	"whirlwind",		"!whirlwind!",
    },

    {
        "mount",		{ L_APP },
        &gsn_mount,		5,
        "",			"!Mount!",
    },

    {
        "dirt kicking",		{ L_APP },
        &gsn_dirt,              24,
        "kicked dirt",          "You rub the dirt out of your eyes.",
    },

    {
        "swim",                 { L_APP },
	&gsn_swim,		0,
	"",			"!Swim!",
    },

    {
        "meditate",         	{ L_APP },
        &gsn_meditate,      	6,
        "",			"!Meditate!",
    },

/*
 * Weapon proficiencies.
 * These must all be together and after "pugilism".
 *
 * Most importantly, the two handed version of a
 * weapon skill HAS to be the next skill after a
 * onehanded version.
 */
    {
	"barehanded fighting",	{ L_APP },
	&gsn_hit,		0,
	"",			"!Barehanded Fighting!",
    },

    {
	"1h slashing",		{ L_APP },
	&gsn_slash,		0,
	"",			"!1h slashing!",
    },

    {
	"2h slashing",		{ L_APP },
	NULL,			0,
	"",			"!2h slashing!",
    },

    {
	"1h piercing",		{ L_APP },
	&gsn_pierce,		0,
	"",			"!1h piercing!",
    },

    {
	"2h piercing",		{ L_APP },
	NULL,			0,
	"",			"!2h piercing!",
    },

    {
	"1h misc",		{ L_APP },
	&gsn_whip,		0,
	"",			"!1h misc!",
    },

    {
	"2h misc",		{ L_APP },
	NULL,			0,
	"",			"!2h misc!",
    },

    {
	"blast weapons",	{ L_APP },
	&gsn_explode,		0,
	"",			"!Blast Weapons!",
    },

    {
	"1h bludgeoning",		{ L_APP },
	&gsn_pound,		0,
	"",			"!1h bludgeoning!",
    },

    {
	"2h bludgeoning",		{ L_APP },
	NULL,			0,
	"",			"!2h bludgeoning!",
    },

    {
	"tornado suction",	{ L_APP },
	&gsn_suction,		0,
	"",			"!Tornado Suction!",
    },

    {
	"archery",		{ L_APP },
	&gsn_shot,		0,
	"",			"!Archery!",
    },

	  /* Race ability spells */
    {
        "vampiric bite",        { L_APP },
        &gsn_vampiric_bite,     0,
        "vampiric bite",        "You feel well fed.",
    },

    {
        "carve",                { L_APP },
        &gsn_carve,             0,
        "",                     "!Carve!",
    },

    {
        "aerial casting",       { L_APP },
        NULL,                   0,
        "",                     "!Aerial Casting!",
    },

    {
        "aerial combat",        { L_APP },
        NULL,                   0,
        "",                     "!Aerial Casting!",
    },

    {
        "bandage",              { L_APP },
        &gsn_bandage,            4,
        "",                     "!Bandage!",
    },

    {
        "quick chant",          { L_APP },
        &gsn_quick_chant,       0,
        "",                     "!Quick Chant!",
    },

    {
        "trip",                 { L_APP },
        &gsn_trip,              24,
        "trip",                 "!Trip!",
    },

    {
        "guard",                { L_APP },
        &gsn_guard,             0,
        "",                     "!Guard!",
    },

    {
        "blindfighting",        { L_APP },
        &gsn_blindfighting,     0,
        "",                     "!Blindfighting!",
    },

    {
        "switch opponents",     { L_APP },
        &gsn_switch,            11,
        "",                     "!Switch Opponents!",
    },

    {
        "awareness",            { L_APP },
        &gsn_aware,             6,
        "",                     "You are no longer aware.",
    },

    {
        "unarmed damage",       { L_APP },
        &gsn_unarmed,           0,
        "",                     "!Unarmed Damage!",
    },

    {
        "mounted combat",       { L_APP },
        &gsn_mounted_combat,	0,
        "",                     "!Mounted Combat!",
    },

    {
        "bladeflash",       { L_APP },
        &gsn_bladeflash,	0,
        "",                     "!BladeFlash!",
    },

    {
        "alcohol tolerance",    { L_APP },
        &gsn_alcohol_tolerance, 0,
        "",                     "!Alcohol Tolerance!",
    },

    {
        "singing",              { L_APP },
        &gsn_singing,           24,
        "",                     "!Singing!",
    },

    {
        "drums",                { L_APP },
        &gsn_drums,             24,
        "",                     "!Drums!",
    },

    {
        "flute",                { L_APP },
        &gsn_flute,             24,
        "",                     "!Flute!",
    },

    {
        "pipes",                { L_APP },
        &gsn_pipes,             24,
        "",                     "!Pipes!",
    },

    {
        "lyre",                 { L_APP },
        &gsn_lyre,              24,
        "",                     "!Lyre!",
    },

    {
        "harp",                 { L_APP },
        &gsn_harp,              24,
        "",                     "!Harp!",
    },

    {
        "horn",                 { L_APP },
        &gsn_horn,              24,
        "",                     "!Horn!",
    },

    {
        "fiddle",               { L_APP },
        &gsn_fiddle,            24,
        "",                     "!Fiddle!",
    },

    {
        "mandolin",             { L_APP },
        &gsn_mandolin,          24,
        "",                     "!Mandolin!",
    },

    {
        "dulcimer",             { L_APP },
        &gsn_dulcimer,          24,
        "",                     "!Dulcimer!",
    },

    {
	"summon mount",		{ L_APP },
	&gsn_summon_mount,	12,
	"",		"!Summon Mount!",
    },

    {
        "instant kill",         { L_APP },
        &gsn_instant_kill,      0,
        "",                     "!Instant Kill!",
    },

    {
        "safe fall",            { L_APP },
	&gsn_safe_fall,		0,
	"",			"!Safe Fall!",
    },

    {
        "climb",            	{ L_APP },
	&gsn_climb,		0,
	"",			"!Climb!",
    },

    {
        "tumble",            	{ L_APP },
	&gsn_tumble,		0,
	"",			"!Tumbling!",
    },

    {
        "layhandstimer",              { L_APP },
        &gsn_layhands_timer,           0,
        "",                     "",
    },

    {
        "summon mount",              { L_APP },
        &gsn_summon_mount,           0,
        "",                     "",
    },

    {
        "throat crush",              { L_APP },
        &gsn_throat_crush,           0,
        "",                     "",
    },

    {
        "throw",              { L_APP },
        &gsn_throw,           0,
        "",                     "",
    },

    {
        "appraise",              { L_APP },
        &gsn_appraise,           0,
        "",                     "",
    },

    {
        "listen",              { L_APP },
        &gsn_listen,           0,
        "",                     "",
    },

    {
        "pickpocket",              { L_APP },
        &gsn_pickpocket,           0,
        "",                     "",
    }

};

const int lesser_memchart [ MAX_LEVEL ] [ 12 ] =
// memorization chart for partial spell casters:
// rangers, paladins, antipaladins
{
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 10
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0 }, // 20
  { 0, 0, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 3, 2, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 3, 2, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 3, 3, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 3, 3, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 4, 3, 2, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 4, 3, 2, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0 }, // 30
  { 0, 0, 5, 4, 3, 3, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 5, 4, 3, 3, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 5, 4, 4, 3, 2, 0, 0, 0, 0, 0 },
  { 0, 0, 5, 4, 4, 3, 2, 0, 0, 0, 0, 0 },
  { 0, 0, 5, 4, 4, 3, 3, 0, 0, 0, 0, 0 },
  { 0, 0, 5, 5, 4, 3, 3, 0, 0, 0, 0, 0 },
  { 0, 0, 5, 5, 4, 3, 3, 1, 0, 0, 0, 0 },                         
  { 0, 0, 5, 5, 4, 4, 3, 1, 0, 0, 0, 0 },
  { 0, 0, 5, 5, 4, 4, 3, 2, 0, 0, 0, 0 },
  { 0, 0, 5, 5, 4, 4, 3, 2, 0, 0, 0, 0 }, // 40
  { 0, 0, 5, 5, 5, 4, 3, 3, 1, 0, 0, 0 },
  { 0, 0, 5, 5, 5, 4, 3, 3, 1, 0, 0, 0 },
  { 0, 0, 5, 5, 5, 4, 4, 3, 2, 0, 0, 0 },
  { 0, 0, 5, 5, 5, 4, 4, 3, 2, 0, 0, 0 },
  { 0, 0, 5, 5, 5, 4, 4, 3, 3, 0, 0, 0 },
  { 0, 0, 5, 5, 5, 5, 4, 3, 3, 0, 0, 0 },
  { 0, 0, 5, 5, 5, 5, 4, 3, 3, 1, 0, 0 },
  { 0, 0, 5, 5, 5, 5, 4, 3, 3, 1, 0, 0 },
  { 0, 0, 5, 5, 5, 5, 4, 4, 3, 2, 0, 0 },
  { 0, 0, 5, 5, 5, 5, 4, 4, 3, 2, 1, 0 }, // 50
  { 0, 0, 6, 6, 6, 5, 5, 4, 3, 3, 1, 0 },
  { 0, 0, 6, 6, 6, 5, 5, 4, 3, 3, 2, 0 },
  { 0, 0, 6, 6, 6, 5, 5, 4, 4, 3, 2, 0 },
  { 0, 0, 6, 6, 6, 6, 5, 4, 4, 3, 3, 0 },
  { 0, 0, 6, 6, 6, 6, 5, 4, 4, 3, 3, 0 },
  { 0, 0, 6, 6, 6, 6, 5, 4, 4, 3, 3, 1 },
  { 0, 0, 6, 6, 6, 6, 5, 5, 4, 3, 3, 1 },
  { 0, 0, 6, 6, 6, 6, 5, 5, 4, 3, 3, 2 },
  { 0, 0, 6, 6, 6, 6, 6, 5, 4, 4, 3, 2 },
  { 0, 0, 6, 6, 6, 6, 6, 5, 4, 4, 3, 3 }, // 60
  { 0, 0, 6, 6, 6, 6, 6, 5, 5, 4, 3, 3 },
  { 0, 0, 6, 6, 6, 6, 6, 5, 5, 4, 4, 3 },
  { 0, 0, 6, 6, 6, 6, 6, 5, 5, 4, 4, 3 },
  { 0, 0, 6, 6, 6, 6, 6, 5, 5, 4, 4, 3 }, // 64
  { 0, 0, 6, 6, 6, 6, 6, 5, 5, 4, 4, 3 }, // 65
};

const int memchart [ MAX_LEVEL ] [ 12 ] =
// memorization chart for full spellcasting classes:
// cleric, shaman, druid, conjurer, necromancer, sorcerer
{
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 10
  { 6, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 7, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 7, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 7, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 7, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 7, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 7, 6, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 8, 7, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 8, 7, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 8, 7, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0 }, // 20
  { 8, 7, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 8, 7, 6, 6, 2, 0, 0, 0, 0, 0, 0, 0 },
  { 8, 7, 6, 6, 3, 0, 0, 0, 0, 0, 0, 0 },
  { 8, 7, 7, 6, 4, 0, 0, 0, 0, 0, 0, 0 },
  { 9, 8, 7, 6, 5, 0, 0, 0, 0, 0, 0, 0 },
  { 9, 8, 7, 6, 6, 1, 0, 0, 0, 0, 0, 0 },
  { 9, 8, 7, 6, 6, 2, 0, 0, 0, 0, 0, 0 },
  { 9, 8, 7, 6, 6, 3, 0, 0, 0, 0, 0, 0 },
  { 9, 8, 7, 7, 6, 4, 0, 0, 0, 0, 0, 0 },
  { 9, 8, 7, 7, 6, 5, 0, 0, 0, 0, 0, 0 }, // 30
  { 9, 8, 7, 7, 6, 6, 1, 0, 0, 0, 0, 0 },
  {10, 9, 8, 7, 6, 6, 2, 0, 0, 0, 0, 0 },
  {10, 9, 8, 7, 6, 6, 3, 0, 0, 0, 0, 0 },
  {10, 9, 8, 7, 7, 6, 4, 0, 0, 0, 0, 0 },
  {10, 9, 8, 7, 7, 6, 5, 0, 0, 0, 0, 0 },
  {10, 9, 8, 7, 7, 6, 6, 1, 0, 0, 0, 0 },
  {10, 9, 8, 8, 7, 6, 6, 2, 0, 0, 0, 0 },
  {10, 9, 8, 8, 7, 6, 6, 3, 0, 0, 0, 0 },
  {11,10, 8, 8, 7, 7, 6, 4, 0, 0, 0, 0 },
  {11,10, 9, 8, 7, 7, 6, 5, 0, 0, 0, 0 }, // 40
  {11,10, 9, 8, 7, 7, 6, 6, 1, 0, 0, 0 },
  {11,10, 9, 8, 8, 7, 6, 6, 2, 0, 0, 0 },
  {11,10, 9, 8, 8, 7, 6, 6, 3, 0, 0, 0 },
  {11,10, 9, 8, 8, 7, 7, 6, 4, 0, 0, 0 },
  {11,10, 9, 9, 8, 7, 7, 6, 5, 0, 0, 0 },
  {12,11, 9, 9, 8, 7, 7, 6, 6, 1, 0, 0 },
  {12,11, 9, 9, 8, 8, 7, 6, 6, 2, 0, 0 },
  {12,11,10, 9, 8, 8, 7, 7, 6, 3, 0, 0 },
  {12,11,10, 9, 8, 8, 7, 7, 6, 4, 0, 0 },
  {12,11,10, 9, 9, 8, 7, 7, 6, 5, 0, 0 }, // 50
  {12,11,10, 9, 9, 8, 7, 7, 6, 6, 1, 0 },
  {12,11,10,10, 9, 8, 8, 7, 6, 6, 2, 0 },
  {13,12,10,10, 9, 8, 8, 7, 6, 6, 3, 0 },
  {13,12,10,10, 9, 8, 8, 7, 7, 6, 4, 0 },
  {13,12,11,10, 9, 8, 8, 7, 7, 6, 5, 0 },
  {13,12,11,10, 9, 9, 8, 8, 7, 6, 6, 1 }, // 56 -- end of mortal levels
  {13,12,11,10,10, 9, 8, 8, 7, 6, 6, 2 },
  {13,12,11,10,10, 9, 8, 8, 7, 6, 6, 3 },
  {13,12,11,11,10, 9, 8, 8, 7, 7, 6, 4 },
  {14,13,11,11,10, 9, 9, 8, 7, 7, 6, 5 }, // 60
  {14,13,11,11,10, 9, 9, 8, 7, 7, 6, 6 },
  {14,13,12,11,10, 9, 9, 8, 8, 7, 6, 6 },
  {14,13,12,11,10,10, 9, 8, 8, 7, 7, 6 },
  {14,13,12,11,10,10, 9, 8, 8, 7, 7, 6 },
  {16,16,16,16,16,16, 9, 8, 8, 7, 7, 6 }, // 65
};

/*
 * WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
 *
 * Spells begin here.  Before changing anything, be sure you understand it.
 * This means you should at the very *LEAST* check out the spell_type
 * struct that is found in merc.h
 *
 * Spells on this MUD are not quite identical to those found on any other
 * MUD.  There are subtleties and oddities that are strewn about the code, and
 * you should be familiar with everything pertaining to your particular spell
 * before you make changes to it.
 *
 * The extra messages in the spell struct are *NOT* used for every type of spell.
 * Most of them are used only for offensive spells.  The messages are in the
 * following order:
 *
 * 1) Message caster gets when casting offensive spell at someone
 * 2) Message target of offensive spell gets.
 * 3) Message onlooker in same room gets when offensive spell hits target.
 * 4) Message caster gets when hitting self with offensive spell.
 * 5) Message onlookers in same room get when caster targets self with
 *    offensive spell.
 * 6) Message to caster and onlookers in same room when target is killed
 *    by offensive spell.
 * 7) Wear-off message for duration spells.
 *
 * Note that messages 1-6 are used exclusively for offensive/damaging spells
 * and it's pointless to enter messages for non-offensive spells in these slots.
 *
 * Note also that message 7 is for duration spells only and is pointless for
 * instant one-shot spells.  This message will only be seen by a person when
 * the spell is affecting them and it wears off.
 *
 * I wrote most of the changes, so bug me if you don't understand something
 */

struct	spell_type	spells_table	[MAX_SPELL]	=
{
/*
 * Magic spells.
 */
    {
	"reserved",		{ L_APP },
	NULL,			0,	 0,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_NONE,
	MANA_NONE,
        FALSE
    },

    {
	"acid blast",		{ L_APP },
	&spl_acid_blast,	20,	12,
	"You blast $N&n with &+Gacid&n, melting flesh from $S body.",
	"$n&n blasts you with &+Gacid&n!  Ouch!",
	"$n&n blasts $N&n with &+Gacid&n, melting flesh from $S body.",
	"You blast yourself with &+Gacid&n!  As if you weren't ugly enough already...",
	"$n&n screams out in agony as $e blasts $mself with &+Gacid&n.",
	"$N&n's body dissolves into goo.",
	"!Acid Blast!",
	SCHOOL_EVOCATION,
	MANA_WATER,
        TRUE
    },

    {
	"bird of prey",		{ L_APP },
	&spl_bird_prey,			20,	11,
	"&+wYou conjure a &+yhawk&N&+w, which &+rclaws&N&+w at $N&n.",
	"&+wOut of nowhere, the &+rcl&+Raw&n&+rs&+w of a &+yhawk&+w bury themselves deep into your &+rflesh&N&+w.&N",
	"$n&n&+w conjures a &+yhawk&N&+w, which &+rclaws&+w at $N&n.",
	"&+wYou are &+Rm&N&+rau&+Lle&N&+rd&+w by a &+yhawk&+w!&n",
	"$n&n &+wis &+Rm&N&+rau&+Lle&N&+rd&+w by a &+yhawk&+w!&N",
	"$N&n&+w is &+rcl&+Raw&N&+red&+w to &+Ldeath &N&+wby a &+yhawk&+w.&N",
	"!Bird of Prey!",
	SCHOOL_EVOCATION,
	MANA_EARTH,
        TRUE
    },

    {
	"armor",		{ L_APP },
	&spl_armor,		5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less protected.",
	SCHOOL_CONJURATION,
	MANA_EARTH
        , TRUE
    },

    {
	"darkness",		{ L_APP },
	&spl_darkness,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"fiery starshell",	{ L_APP },
	&spl_fiery_starshell,	5,	20,
	"",
	"",
	"",
	"You blast yourself with &+Rfire&n!",
	"$n&n screams out in agony as $e blasts $mself with &+Ffire&n.",
	"$N&n's body burns to the ground.",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"airy starshell",	{ L_APP },
	&spl_airy_starshell,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"watery starshell",	{ L_APP },
	&spl_watery_starshell,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_WATER,
        TRUE
    },

    {
	"earthen starshell",	{ L_APP },
	&spl_earthen_starshell,	5,	20,
	"",
	"",
	"",
	"&+lYou are pounded by the &+yearth&n!",
	"$n&n screams out in agony as $e pounds $mself with &+yearth&n.",
	"$N&n&+l's body is pounded to death.",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"earthen tomb",		{ L_APP },
	&spl_earthen_tomb,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"stornogs spheres",	{ L_APP },
	&spl_stornogs_spheres,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"elemental form",	{ L_APP },
	&spl_elemental_form,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"airy water",	{ L_APP },
	&spl_airy_water,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"telekinesis",	{ L_APP },
	&spl_telekinesis,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"hypnotic pattern",	{ L_APP },
	&spl_hypnotic_pattern,	5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"miners intuition",	{ L_APP },
	&spl_miners_intuition,			5,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DIVINATION,
	MANA_EARTH,
        TRUE
    },

    {
	"wall of iron",		{ L_APP },
	&spl_wall_iron,			5,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"wall of stone",		{ L_APP },
	&spl_wall_stone,			5,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"wall of force",	{ L_APP },
	&spl_wall_force,			5,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"wall of fire",		{ L_APP },
	&spl_wall_of_fire,	5,	16,
	"&+rYou are burned as you pass through a wall of flames! &+ROUCH!&n",
	"&+rYou are burned as you pass through a wall of flames! &+ROUCH!&n",
        "&+r$N&+r is burned severely as $E walks through a wall of &+RFIRE&+r!&n",
	"&+rYou are burned as you pass through a wall of flames! &+ROUCH!&n",
        "&+r$n&+r is burned severely as $E walks through a wall of &+RFIRE&+r!&n",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"wall of sparks",	{ L_APP },
	&spl_wall_of_sparks,	5,	16,
	"&+rYou are zapped as you pass through a wall of &+Wsparks&+r!&n",
	"&+rYou are zapped as you pass through a wall of &+Wsparks&+r!&n",
        "&+r$N&+r is &+Wzapped&n as $E walks through a wall of &+Wsparks&+r!&n",
	"&+rYou are zapped as you pass through a wall of &+Wsparks&+r!&n",
        "&+r$N&+r is &+Wzapped&n as $E walks through a wall of &+Wsparks&+r!&n",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"wall of mist",		{ L_APP },
	&spl_wall_of_mist,	5,	16,
	"&+cYou choke as you pass through a &+gpoisonous&+c wall of &+Wmist&+c!&n",
	"&+cYou choke as you pass through a &+gpoisonous&+c wall of &+Wmist&+c!&n",
	"&+c$N&+c chokes and sputters as $E passes through a &+gpoisonous&+c wall of &+Wmist&+c!&n",
	"&+cYou choke as you pass through a &+gpoisonous&+c wall of &+Wmist&+c!&n",
	"&+c$N&+c chokes and sputters as $E passes through a &+gpoisonous&+c wall of &+Wmist&+c!&n",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"lightning curtain",	{ L_APP },
	&spl_lightning_curtain,	5,	21,
	"&+BYou are shocked severely as you pass through a lightning curtain!&n",
	"&+BYou are shocked severely as you pass through a lightning curtain!&n",
	"&+B$n&+B is shocked severely as $E passes through a lightning curtain!&n",
	"&+BYou are shocked severely as you pass through a lightning curtain!&n",
	"&+B$n&+B is shocked severely as $E passes through a lightning curtain!&n",
	"$N&n crumples to the ground in a sizzling, blackened heap.",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"wall of ice",		{ L_APP },
	&spl_wall_of_ice,	5,	16,
	"&+WThe intense cold of the wall sends shivers down your spine.&n",
	"&+WThe intense cold of the wall sends shivers down your spine.&n",
	"&+W$N&+W shivers from the intense cold as $E bumps into a wall of ice.&n",
	"&+WThe intense cold of the wall sends shivers down your spine.&n",
	"&+W$n&+W shivers from the intense cold as $e bumps into a wall of ice.&n",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_WATER,
        TRUE
    },

    {
	"illusionary wall",	{ L_APP },
	&spl_wall_illusion,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ILLUSION,
	MANA_EARTH,
        TRUE
    },

    {
	"mirror image",		{ L_APP },
	&spl_mirror_image,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your images dissipate.",
	SCHOOL_ILLUSION,
	MANA_EARTH,
        TRUE
    },

    {
	"illusion of prowess",	{ L_APP },
	&spl_prowess,		5,	7,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer look quite so intimidating.",
	SCHOOL_ILLUSION,
	MANA_AIR,
        TRUE
    },

    {
	"illusion of incompetence",{ L_APP },
	&spl_incompetence,	5,	7,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer look quite so intimidating.",
	SCHOOL_ILLUSION,
	MANA_AIR,
        TRUE
    },

    {
	"shadow monsters",	{ L_APP },
	&spl_shadow_monsters,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your shadow monsters dissipate.",
	SCHOOL_ILLUSION,
	MANA_EARTH,
        TRUE
    },

    {
	"demi shadow monsters",	{ L_APP },
	&spl_demi_shad_monster,			5,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your shadow monsters dissipate.",
	SCHOOL_ILLUSION,
	MANA_EARTH,
        TRUE
    },

    {
	"shades",		{ L_APP },
	&spl_shades,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your shadow monsters dissipate.",
	SCHOOL_ILLUSION,
	MANA_EARTH,
        TRUE
    },

    {
        "cloak of fear",                { L_APP },
        &spl_cloak_fear,                   5,      17,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Cloak Of Fear!",
        SCHOOL_NECROMANCY,
        MANA_EARTH,
        TRUE
    },

    {
	"clone",		{ L_APP },
	&spl_clone,			5,	17,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your clone disintegrates.",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"haste",		{ L_APP },
	&spl_haste,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RYou feel the world speed up around you.&n",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"enthrall",		{ L_APP },
	&spl_enthrall,		5,	9,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+WYour vision clears and you regain control of your nervous system.&n",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"dazzle",		{ L_APP },
	&spl_dazzle,		5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RYou feel much less noticeable.&n",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"enlarge",		{ L_APP },
	&spl_enlarge,		5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"You return to your normal size.",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"reduce",		{ L_APP },
	&spl_reduce,		5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You return to your normal size.",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"misdirection",		{ L_APP },
	&spl_misdirection,	5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less disoriented.",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },


    {
	"blur",			{ L_APP },
	&spl_blur,		5,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RYour form is no longer blurred.&n",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"barkskin",		{ L_APP },
	&spl_barkskin,		5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYour skin feels soft again.&n",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"spirit armor",		{ L_APP },
	&spl_spirit_armor,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+mYou feel less protected.&n",
	SCHOOL_SPIRITUAL,
	MANA_EARTH,
        TRUE
    },

    {
	"bless",		{ L_APP },
	&spl_bless,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less righteous.",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR
        , TRUE
    },

    {
	"power word blind",	{ L_APP },
	&spl_power_word_blind,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You can see again.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"blindness",		{ L_APP },
	&spl_blindness,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You can see again.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"fear",			{ L_APP },
	&spl_fear,		5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer feel so panicked and afraid.",
	SCHOOL_ABJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"cowardice",		{ L_APP },
	&spl_cowardice,		5,	11,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer feel so unsure.",
	SCHOOL_ABJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"spook",		{ L_APP },
	&spl_spook,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer feel so spooked.",
	SCHOOL_ABJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"sunray",		{ L_APP },
	&spl_sunray,		5,	14,
	"You blast $N&N with a &+Ysunray&n!",
	"&+YYou are blasted by a blinding ray of light!&n",
	"&+Y$n&+Y hits $N&+Y with a blinding ray of light!&n",
	"You sunray yourself.  Blink.  Blink.",
	"$n&n looks dazed after blasting $mself with a ray of light.",
	"",
	"You can see again.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"sunburst",		{ L_APP },
	&spl_sunburst,			5,	17,
	"You blast $N&N with a &+Ysunburst&n!",
	"&+YYou are blasted by a blinding burst of light!&n",
	"&+Y$n&+Y hits $N&+Y with a blinding burst of light!&n",
	"You sunburst yourself.  Blink.  Blink.",
	"$n&n looks dazed after blasting $mself with a burst of light.",
	"",
	"You can see again.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"molevision",		{ L_APP },
	&spl_mole,		5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your vision clears.",
	SCHOOL_ANIMAL,
	MANA_FIRE,
        TRUE
    },

    {
	"mousestrength",	{ L_APP },
	&spl_mouse,		5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your strength returns.",
	SCHOOL_ANIMAL,
	MANA_FIRE,
        TRUE
    },

    {
	"wither",		{ L_APP },
	&spl_wither,		5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your no longer feel so weak and powerless.",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
        TRUE
    },

    {
	"water breathing",	{ L_APP },
	&spl_water_breathing, 	 5,	12,
	"",
	"Your lungs burn for air!",
	"",
	"",
	"",
	"",
	"You can no longer breathe underwater.",
	SCHOOL_SURVIVAL,
	MANA_WATER
        , TRUE
    },

    {
	"burning hands",	{ L_APP },
	&spl_burning_hands,     15,	12,
	"You &+Rbu&+Yrn&n $N&n with your hot little hands.",
	"$n&n &+Rbu&+Yrns&n you with $s spell.",
	"$n&n &+Rbu&+Yrns&n $N&n with $s hands.",
	"You touch yourself with your &+Rbur&+Yning &Nhands&n.",
	"$n&n's hands &+Rbla&+Yze&n as $e touches $mself, setting &+rf&+Rir&N&+re&N to $s clothing!",
	"$n&n's hands were a little too warm for $N&n, who is now quite dead.",
	"!Burning Hands!",
	SCHOOL_ALTERATION,
	MANA_FIRE
        , TRUE
    },

    {
	"call lightning",	{ L_APP },
	&spl_call_lightning,			15,	12,
	"You blast $N with &+Ylig&+Whtn&+Ying&n!",
	"$n blasts you with &+Ylig&+Whtn&+Ying&n!",
	"$n blasts $N with &+Ylig&+Whtn&+Ying&N!",
	"You blast yourself with &+Ylig&+Whtn&+Ying&n!",
	"$n blasts $mself with &+Ylig&+Whtn&+Ying&n!",
	"With a final surge from the storm, $N&n has been &N&+rin&+Rci&N&+rner&+Rat&N&+re&+Rd&N by &+Ylig&+Whtn&+Ying&N!&N.",
	"!Call Lightning!",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"cause critical",	{ L_APP },
	&spl_cause_critical,	20,	12,
	"$N&N doubles over in pain at your simple touch.",
	"$n&N critically injures you with $s touch.",
	"$n&N's touch causes $N&N to double over in pain.",
	"You touch yourself, sending blinding waves of pain through your body.",
	"$n&N twitches violently as $e touches $mself.",
	"",
	"!Cause Critical!",
	SCHOOL_NECROMANCY,
	MANA_AIR
        , TRUE
    },

    {
	"greater agony",	{ L_APP },
	&spl_gr_agony,	20,	12,
	"$N&N doubles over in pain and agony at your touch.",
	"$n&N injures you with $s painful touch.",
	"$n&N's touch causes $N&N to double over in pain.",
	"You touch yourself, sending blinding waves of pain through your body.",
	"$n&N twitches violently as $e touches $mself.",
	"",
	"!Greater Agony!",
	SCHOOL_NECROMANCY,
	MANA_AIR,
        TRUE
    },

    {
	"cause light",		{ L_APP },
	&spl_cause_light,	15,	12,
	"A pained look crosses $N&N's face as you touch $M.",
	"$n&N causes pain to shoot through your body with a touch.",
	"$n&N causes $N&N to grimace in pain with $s touch.",
	"You touch yourself, sending pain through your body.",
	"$n&N grimaces as $e touches $mself.",
	"",
	"!Cause Light!",
	SCHOOL_NECROMANCY,
	MANA_AIR
        , TRUE
    },

    {
	"minor agony",		{ L_APP },
	&spl_m_agony,			15,	12,
	"A agonized look crosses $N&N's face as you touch $M.",
	"$n&N causes pain to shoot through your body with a touch.",
	"$n&N causes $N&N to grimace in pain with $s touch.",
	"You touch yourself, sending pain through your body.",
	"$n&N grimaces wickedly as $e touches $mself.",
	"",
	"!Minor Agony!",
	SCHOOL_NECROMANCY,
	MANA_AIR,
        TRUE
    },

    {
	"cause serious",	{ L_APP },
	&spl_cause_serious,	17,	12,
	"$N&N's body is wracked with spasms of pain as you touch $M.",
	"$n&N seriously injures you with $s touch.",
	"$N&N's body is wracked with spasms of pain as $n&n touches $M.",
	"You touch yourself, sending waves of pain through your body.",
	"$n&N twitches as $e touches $mself.",
	"",
	"!Cause Serious!",
	SCHOOL_NECROMANCY,
	MANA_AIR
        , TRUE
    },

    {
	"ravenous vines",	{ L_APP },
	&spl_ravenous_vines,			17,	12,
	"&+gYou conjure ravenous vines to choke $N&N.",
	"&+g$n&+g conjures vines to choke and constrict you.&n",
	"$N&+g is choked and constricted by vines conjured by $N&+g.&n",
	"&+gYou strangle yourself with vines.&N",
	"&+g$n&+g's face turns &+Bblue&+g as $e strangles $mself with conjured vines.&n",
	"Gasping and sputtering, $N&n goes down!",
	"!Ravenous Viens!",
	SCHOOL_NECROMANCY,
	MANA_AIR,
        TRUE
    },

    {
	"agony",		{ L_APP },
	&spl_agony,		17,	12,
	"$N&N's body is wracked with spasms of pain as you touch $M.",
	"$n&N seriously injures you with $s touch.",
	"$N&N's body is wracked with spasms of pain as $n&n touches $M.",
	"You touch yourself, sending waves of pain through your body.",
	"$n&N twitches as $e touches $mself.",
	"",
	"!Agony!",
	SCHOOL_NECROMANCY,
	MANA_AIR,
        TRUE
    },

    {
	"change sex",		{ L_APP },
	&spl_change_sex,			15,	0,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your body feels familiar again.",
	SCHOOL_ENCHANTMENT | SCHOOL_ALTERATION,
	MANA_ANY
        , TRUE
    },

    {
	"charm person",		{ L_APP },
	&spl_charm_person,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel more self-confident.",
	SCHOOL_ENCHANTMENT | SCHOOL_CHARM,
	MANA_ANY
        , TRUE
    },

    {
	"chill touch",		{ L_APP },
	&spl_chill_touch,	15,	12,
	"You &+Bchill&n $N&n with your &+cfreezing&n touch.",
	"$n &+Bchills&n you to the bone with $S freezing touch.",
	"$N&n shivers as $n&n &+Cchills&n $M.",
	"You &+Bchill&n yourself to the bone with your touch.",
	"$n&n shivers uncontrollably as $e touches $mself.",
	"$n&N's &+Bchilled&N $N to death! Don't forget to put flowers on the grave.",
	"You feel less cold.",
	SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"color spray",		{ L_APP },
	&spl_color_spray,			15,	12,
        "&+BYour &+Gblast &n&+yof &+Ycolors &+Rstrikes $N &+Msolidly!&n",
	"$n's &+Gblast &n&+yof &+Ycolors &+Rstrikes you &+Msolidly!&n",
	"$n's &+Gblast &n&+yof &+Ycolors &+Rstrikes $N &+Msolidly!&n",
	"&+BYour &+Gblast &n&+yof &+Ycolors &+Rstrikes you &+Msolidly!&n",
	"$n &+Bsprays &+Gcolors &n&+Yall &+yover &+R$mself.&n",
	"",
	"!Colour Spray!",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"prismatic spray",	{ L_APP },
	&spl_prismatic_spray,	15,	16,
        "",
	"",
	"",
	"",
	"",
	"",
	"!Prismatic Spray!",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"prismatic orb",	{ L_APP },
	&spl_prismatic_orb,			15,	11,
        "&+BYour &+Morb &+Bof &+Ycol&+gors &+Bstrikes &+R$N &+Bsolidly!&n",
        "&+B$n&+B's &+Morb &+Bof &+Ycol&+gors &+Bstrikes &+Ryou &+Bsolidly!&n",
        "&+B$n&+B's &+Morb &+Bof &+Ycol&+gors &+Bstrikes &+R$N &+Bsolidly!&n",
	"&+BYour &+Mprismatic orb &+Bstrikes &+Ryou &+Bsolidly!&n",
	"$n &+Bsprays &+Gcolors &n&+Yall &+yover &+R$mself.&n",
	"",
	"!Prismatic Orb!",
	SCHOOL_ILLUSION,
	MANA_AIR,
        TRUE
    },

    {
        "shadow magic",         { L_APP },
        &spl_shadow_magic,			15,	12,
        "&+LYou blast $N&n with your shadow magic.&n",
        "&+L$n&+L blasts you with $s spell.&n",
        "&+L$n&n blasts $N&n with &+Lshadow magic.&n",
        "You hit yourself with &+Lshadow magic&n.",
        "$n&n hits $mself with &+Lshadow magic&n.",
        "",
        "!Shadow Magic!",
        SCHOOL_ILLUSION,
        MANA_AIR,
        TRUE
    },

    {
        "phantasmal killer",    { L_APP },
        &spl_phantasmal_killer, 15,	14,
        "&+LA phantasmal killer stabs $N&n viciously.&n",
        "&+L$n&+L's phantasmal killer stabs you!&n",
        "&+L$n&n's killer stabs $N&n viciously.&n",
        "You hit yourself with a &+Lphantasmal killer&n.",
        "$n&n hits $mself with a &+Lphantasmal killer&n.",
        "",
        "!Phantasmal Killer!",
        SCHOOL_ILLUSION,
        MANA_AIR,
        TRUE
    },

    {
        "demi shadow magic",    { L_APP },
        &spl_demi_shad_magic,			15,	12,
        "&+LYou blast $N&n with your demi shadow magic.&n",
        "&+L$n&+L blasts you with $s spell.&n",
        "&+L$n&n blasts $N&n with &+Ldemi shadow magic.&n",
        "You hit yourself with &+Ldemi shadow magic&n.",
        "$n&n hits $mself with &+Ldemi shadow magic&n.",
        "",
        "!Demi Shadow Magic!",
        SCHOOL_ILLUSION,
        MANA_AIR,
        TRUE
    },

    {
        "cone of silence",		{ L_APP },
        &spl_cone_silence,			35,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Cone of Silence!",
        SCHOOL_INVOCATION,
        MANA_EARTH
        , TRUE
    },

    {
	"continual light",	{ L_APP },
	&spl_continual_light,			7,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Continual Light!",
	SCHOOL_ALTERATION,
	MANA_FIRE
        , TRUE
    },

    {
	"twilight",		{ L_APP },
	&spl_twilight,			7,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Twilight!",
	SCHOOL_ALTERATION,
	MANA_FIRE,
        TRUE
    },

    {
	"control weather",	{ L_APP },
	&spl_control_weather,			25,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Control Weather!",
	SCHOOL_ALTERATION,
	MANA_AIR
        , TRUE
    },

    {
	"create food",		{ L_APP },
	&spl_create_food,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Create Food!",
	SCHOOL_CONJURATION,
	MANA_EARTH
        , TRUE
    },

    {
        "create dracolich",          { L_APP },
        &spl_create_dracolich,                   5,      12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Create Dracolich!",
        SCHOOL_NECROMANCY,
        MANA_EARTH
        , TRUE
    },

    {
	"conjure windsabre",	{ L_APP },
	&spl_conjure_windsaber,			5,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Conjure Windsaber!",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },
    {
	"celestial sword",	{ L_APP },
	&spl_celestial_sword,			5,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Celestial Sword!",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"create skin",		{ L_APP },
	&spl_create_skin,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Create Skin!",
	SCHOOL_CONJURATION,
	MANA_WATER
        , TRUE
    },

    {
	"create spring",	{ L_APP },
	&spl_create_spring,			20,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Create Spring!",
	SCHOOL_CONJURATION,
	MANA_WATER,
        TRUE
    },

    {
	"create water",		{ L_APP },
	&spl_create_watern,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Create Water!",
	SCHOOL_ALTERATION,
	MANA_WATER
        , TRUE
    },

    {
	"cure blindness",	{ L_APP },
	&spl_cure_blind,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Cure Blindness!",
	SCHOOL_ABJURATION | SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"purify",		{ L_APP },
	&spl_purify,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Purify!",
	SCHOOL_ALTERATION,
	MANA_WATER,
        TRUE
    },

    {
        "purify spirit",        { L_APP },
        &spl_purify_spirit,                     5,      12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Purify Spirit!",
        SCHOOL_SPIRITUAL,
        MANA_WATER,
        TRUE
    },

    {
	"cure critical",	{ L_APP },
	&spl_cure_critical,	20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Cure Critical!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"soothe wound",		{ L_APP },
	&spl_soothe,		20,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Soothe Wound!",
	SCHOOL_NECROMANCY,
	MANA_EARTH,
        TRUE
    },

    {
	"cure disease",		{ L_APP },
	&spl_cure_disease,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Cure Disease!",
	SCHOOL_ABJURATION | SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"cure light",		{ L_APP },
	&spl_cure_light,	10,	10,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Cure Light!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"lesser herbal remedy",	{ L_APP },
	&spl_ls_herbal_remedy,	10,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Lesser Herbal Remedy!",
	SCHOOL_NECROMANCY,
	MANA_EARTH,
        TRUE
    },

    {
	"remove poison",	{ L_APP },
	&spl_remove_poison,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Remove Poison!",
	SCHOOL_ABJURATION | SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"cure serious",		{ L_APP },
	&spl_cure_serious,	15,	11,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Cure Serious!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"herbal remedy",	{ L_APP },
	&spl_herbal_remedy,	15,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Herbal Remedy!",
	SCHOOL_NECROMANCY,
	MANA_EARTH,
        TRUE
    },

    {
	"lesser mending",	{ L_APP },
	&spl_ls_mending,	15,	11,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Lesser Mending!",
	SCHOOL_SPIRITUAL,
	MANA_EARTH,
        TRUE
    },

    {
	"mending",		{ L_APP },
	&spl_mending,		15,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Mending!",
	SCHOOL_SPIRITUAL,
	MANA_EARTH,
        TRUE
    },

    {
	"greater mending",	{ L_APP },
	&spl_gr_mending,	15,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Greater Mending!",
	SCHOOL_SPIRITUAL,
	MANA_EARTH,
        TRUE
    },

    {
	"sustenance",		{ L_APP },
	&spl_sustenance,	10,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Sustenance!",
	SCHOOL_SPIRITUAL,
	MANA_EARTH,
        TRUE
    },

    {
	"nourishment",		{ L_APP },
	&spl_nourishment,			10,	10,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Nourishment!",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"lesser nourishment",	{ L_APP },
	&spl_ls_nourishment,			10,	9,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Lesser Nourishment!",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"greater sustenance",	{ L_APP },
	&spl_gr_sustenance,			10,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Greater Sustenance!",
	SCHOOL_SPIRITUAL,
	MANA_EARTH,
        TRUE
    },

    {
	"rain maker",		{ L_APP },
	&spl_rain_maker,			10,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Rain Maker!",
	SCHOOL_SPIRITUAL,
	MANA_EARTH,
        TRUE
    },

    {
	"curse",		{ L_APP },
	&spl_curse,		20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
        "The curse wears off.",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR
        , TRUE
    },

    {
	"hex",			{ L_APP },
	&spl_hex,		20,	13,
	"",
	"",
	"",
	"",
	"",
	"",
        "The hex upon you is broken.",
	SCHOOL_NECROMANCY,
	MANA_AIR,
        TRUE
    },

    {
	"malison",		{ L_APP },
	&spl_malison,		20,	12,
	"curse",
	"",
	"",
	"",
	"",
	"",
        "You no longer feel so susceptible to the world around you.",
	SCHOOL_SPIRITUAL,
	MANA_AIR,
        TRUE
    },

    {
	"destroy cursed",	{ L_APP },
	&spl_destroy_cursed,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!destroy cursed!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"spirit sight",		{ L_APP },
	&spl_spirit_sight,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You can no longer sense auras.",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"analyze balance",	{ L_APP },
	&spl_analyze_balance,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer know the balance of things.",
	SCHOOL_DIVINATION,
	MANA_FIRE,
        TRUE
    },

    {
	"detect evil",		{ L_APP },
	&spl_detect_evil,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"The red in your vision disappears.",
	SCHOOL_DIVINATION,
	MANA_FIRE
        , TRUE
    },

    {
	"sense life",		{ L_APP },
	&spl_sense_life,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less aware of nearby lifeforms.",
	SCHOOL_DIVINATION,
	MANA_FIRE,
        TRUE
    },

    {
	"sense spirit",		{ L_APP },
	&spl_sense_spirit,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less aware of surrounding spirits.",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"greater spirit sight",	{ L_APP },
	&spl_gr_spirit_sight,			5,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less aware of surrounding spirits and beings.",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"true seeing",		{ L_APP },
	&spl_true_seeing,			5,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your sight is no longer as truthful.",
	SCHOOL_DIVINATION,
	MANA_FIRE,
        TRUE
    },

    {
        "elemental sight",         { L_APP },
        &spl_elemental_sight,      5,      12,
        "",
        "",
        "",
        "",
        "",
        "",
        "You no longer see invisible objects.",
        SCHOOL_DIVINATION,
        MANA_FIRE
        , TRUE
    },

    {
	"detect invis",		{ L_APP },
	&spl_detect_invis,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer see invisible objects.",
	SCHOOL_DIVINATION,
	MANA_FIRE
        , TRUE
    },

    {
	"comprehend languages",	{ L_APP },
	&spl_comp_lang,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer comprehend languages.",
	SCHOOL_DIVINATION,
	MANA_FIRE,
        TRUE
    },

    {
	"detect magic",		{ L_APP },
	&spl_detect_magic,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"The detect magic wears off.",
	SCHOOL_DIVINATION,
	MANA_FIRE
        , TRUE
    },

    {
	"detect poison",	{ L_APP },
	&spl_detect_poison,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Detect Poison!",
	SCHOOL_DIVINATION,
	MANA_FIRE
        , TRUE
    },

    {
	"dispel evil",		{ L_APP },
	&spl_dispel_evil,			15,	12,
	"&+LYou fire a bolt of pure energy into $N&N&+L's soul.&N",
	"$n&N fires a bolt of pure energy into your soul.&N",
	"$n&N fires a bolt of pure energy into $N&N&+L's soul.&N",
	"&+LYou try to purge yourself of evil&N.",
	"$n&N&+L tries to purge $s body of evil&N.",
	"The evil in $N&n's soul has moved on to a lower plane.",
	"!Dispel Evil!",
	SCHOOL_ABJURATION,
	MANA_WATER
        , TRUE
    },

    {
	"gleam of dawn",	{ L_APP },
	&spl_gleam_dawn,			15,	13,
	"&+LYou fire a bolt of &+Wlight&n into $N&N&+L's soul.&N",
	"$n&N fires a bolt of &+Wlight&n into your soul.&N",
	"$n&N fires a bolt of &+Wlight&n into $N&N&+L's soul.&N",
	"&+LYou try to purge yourself of darkness&N.",
	"$n&N&+L tries to purge $s body of darkness&N.",
	"The evil in $N&n's soul has been purged.",
	"!Gleam of Dawn!",
	SCHOOL_ABJURATION,
	MANA_WATER
        , TRUE
    },

    {
	"gleam of dusk",	{ L_APP },
	&spl_gleam_dusk,			15,	13,
	"&+LYou fire a bolt of &+Ldarkness&n into $N&N&+L's soul.&N",
	"$n&N fires a bolt of &+Ldarkness&n into your soul.&N",
	"$n&N fires a bolt of &+Ldarkness&n into $N&N&+L's soul.&N",
	"&+LYou try to purge yourself of light&N.",
	"$n&N&+L tries to purge $s body of light&N.",
	"The good in $N&n's soul has been purged.",
	"!Gleam of Dusk!",
	SCHOOL_ABJURATION,
	MANA_WATER,
        TRUE
    },

    {
	"dispel magic",		{ L_APP },
	&spl_dispel_magic,			15,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Dispel Magic!",
	SCHOOL_ABJURATION,
	MANA_EARTH
        , TRUE
    },

    {
	"earthquake",		{ L_APP },
	&spl_earthquake,	15,	12,
	"&+yThe ground shakes and rumbles at your bidding!&N",
	"&+yThe ground quakes at $n&+y's bidding, pummeling you!&n",
	"&+yThe ground quakes at $n&+y's bidding, pummeling $N&n",
	"You catch yourself in your own earthquake.",
	"",
	"",
	"!Earthquake!",
	SCHOOL_ALTERATION,
	MANA_EARTH
        , TRUE
    },

    {
	"enchant weapon",	{ L_APP },
	&spl_enchant_weapon,			100,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Enchant Weapon!",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE
        , TRUE
    },

    {
	"energy drain",		{ L_APP },
	&spl_energy_drain,	55,	12,
	"You drain $N&n.",
	"$n&n drains you.",
	"$n&n drains $N&n.",
	"You drain yourself.",
	"",
	"$N&n turns into an empty, dried-up shell of a being.",
	"!Energy Drain!",
	SCHOOL_NECROMANCY,
	MANA_FIRE
        , TRUE
    },

    {
	"exorcise",		{ L_APP },
	&spl_exorcise,			35,	12,
	"",
	"",
	"",
	"",
	"",
	"",
        "!Exorcise!",
	SCHOOL_ALTERATION | SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"faerie fire",		{ L_APP },
	&spl_faerie_fire,			5,	12,
	"Your faerie fire surrounds $N&n.",
	"$n points at you and you start to emit a faint aura!",
	"$n points at $N, making $M glow with a faint aura!",
	"You glow with a faint aura.",
	"$n points at $Mself and starts to glow with a faint aura.",
	"",
	"The pink aura around you fades away.",
	SCHOOL_ALTERATION,
	MANA_FIRE
        , TRUE
    },

    {
	"faerie fog",		{ L_APP },
	&spl_faerie_fog,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Faerie Fog!",
	SCHOOL_CONJURATION,
	MANA_AIR
        , TRUE
    },

    {
	"reveal true form",	{ L_APP },
	&spl_reveal_true_form,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Reveal True Form!",
	SCHOOL_SPIRITUAL,
	MANA_AIR,
        TRUE
    },

    {
	"reveal true name",	{ L_APP },
	&spl_reveal_true_name,			12,	8,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Reveal True Name!",
	SCHOOL_DIVINATION,
	MANA_AIR,
        TRUE
    },

    {
	"dispel invisible",	{ L_APP },
	&spl_dispel_invisible,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Dispel Invisible!",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"negate veil",		{ L_APP },
	&spl_negate_veil,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Negate Veil!",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"negate luster",	{ L_APP },
	&spl_negate_luster,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Negate Luster!",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"illumination",		{ L_APP },
	&spl_illumination,			12,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Illumination!",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"fireball",		{ L_APP },
	&spl_fireball,		15,	12,
	"You smirk as your &+rfi&+Rre&+Yba&+Rll&n explodes in $N&n's face.",
	"$n&n blasts you with a &+rfi&+Rre&+Yba&+Rll&n!  Ouch!",
	"$n&n smirks as $s &+rfi&+Rre&+Yba&+Rll&n explodes in $N&n's face.",
	"You blast yourself with a &+rfi&+Rre&+Yba&+Rll&n, melting the flesh from your bones.",
	"$n&n blasts $mself with a &+rfi&+Rre&+Yba&+Rll&n, melting the flesh from $s bones.",
	"The fireball from $n&n turns $N&n into a smoldering ash heap!",
	"!Fireball!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"firestorm",		{ L_APP },
	&spl_firestorm,		15,	16,
	"Your &+rfi&+Rre&+Yst&+Rorm&n engulfs $N&n.",
	"$n&n blasts you with a &+rfi&+Rre&+Yst&+Rorm&n!",
	"$n&n's &+rfi&+Rre&+Yst&+Rorm&n burns $N&n severely.",
	"You blast yourself with a &+rfi&+Rre&+Yst&+Rorm&n, melting the flesh from your bones.",
	"$n&n blasts $mself with a &+rfi&+Rre&+Yst&+Rorm&n, melting the flesh from $s bones.",
	"&+L$n&+L turns $N&+L into a smoldering pile of ash!&n",
	"!Firestorm!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"bigbys clenched fist",	{ L_APP },
	&spl_bigby_fist,			15,	12,
	"Your &+Ygiant fist&N slams into $N&n, sending &+rblood&n pouring!",
	"$n&n's &+Ygiant fist&N slams into you!  &+ROUCH!&n",
	"$n&n's &+Ygiant fist&N slams into $N&n, sending &+rblood&n pouring!",
	"You just fisted yourself, you dummy!.",
	"$n&n blasts $mself with a giant fist!",
	"$N&n is crushed into a pulp!",
	"!Bigbys Clenched Fist!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"akiaurns power word",	{ L_APP },
	&spl_akiaurn_word,			15,	21,
	"$n&+W utters a word of power, and nearly tears &N$N&+W apart!&N",
	"&+WYour soul is nearly rended from your body by the force of &N$n&+W's word! &+ROUCH!&n",
	"$N&+W reels in agony from &N$n&+W's word of power!&N",
	"&+WPerhaps the power of such magic should not be in the hands on someone like yourself... &+ROUCH!&N",
	"$n&n&+W blasts $mself with a word of power. &N&+wWhat a twit.&N",
	"",
	"!Akiaurns Power Word!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"arieks shattering iceball",	{ L_APP },
	&spl_iceball,		15,	18,
	"Your &+Ciceball&n shatters on impact, sending shards of ice flying into $N&n!",
	"$n&n's giant &+Cball of ice&n slams into you and shatters into tiny fragments.",
	"$n&n's &+Ciceball&n shatters upon impacting $N&n, sending shards of ice everywhere!",
	"You just &+Ciceballed&n yourself, you dummy!.",
	"$n&n blasts $mself with a giant &+Cball of ice&n!",
	"$N&n is smashed to frozen little bits.!",
	"!Arieks Shattering Iceball!",
	SCHOOL_ELEMENTAL,
	MANA_WATER,
        TRUE
    },

    {
	"flamestrike",		{ L_APP },
	&spl_flamestrike,	20,	12,
	"You call down a roaring &+rflamestrike&n which hits $N&n dead on.",
	"$n calls down a &+rflamestrike&n which hits you dead on!",
	"$n calls down a roaring &+rflamestrike&n on $N&N, who starts to melt!",
	"You call down a roaring &+rflamestrike&n on yourself!",
	"$n's god sends a holy &+rflamestrike&n down upon $m.  $n thanks $s god for the attention.",
	"",
	"!Flamestrike!",
	SCHOOL_CONJURATION,
	MANA_FIRE
        , TRUE
    },

    {
	"chill of the windsaber",{ L_APP },
	&spl_windsaber,			20,	14,
	"&+bYou conjure a chilling &+Cwindsaber&+b which hits $N&+b hard.&n",
	"&+b$n&n conjures a chilling &+Cwindsaber&+b which hits you hard.&n",
	"&+b$n&+b conjures a chilling &+Cwindsaber&+b which hits $N&+b hard.&n",
	"&+bYou conjure a chilling &+Cwindsaber&+b which hits you hard.&n",
	"&+b$n&n conjures a chilling &+Cwindsaber&+b which hits $m hard.&n",
	"",
	"!Chill of the Windsaber!",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"fly",			{ L_APP },
	&spl_fly,		10,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your fly spell wears off.",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    // self-only fly for psis
    {
	"flight",		{ L_APP },
	&spl_flight,			80,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your fly spell wears off.",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },


    {
	"ravenflight",		{ L_APP },
	&spl_ravenflight,	10,	19,
	"",
	"",
	"",
	"",
	"",
	"",
	"Shoulders tingling, you float gently to the ground.",
	SCHOOL_ANIMAL,
	MANA_AIR,
        TRUE
    },

    {
	"greater ravenflight",	{ L_APP },
	&spl_gr_ravenflight,			10,	26,
	"",
	"",
	"",
	"",
	"",
	"",
	"Shoulders tingling, you float gently to the ground.",
	SCHOOL_ANIMAL,
	MANA_AIR,
        TRUE
    },

    {
	"gate",			{ L_APP },
	&spl_gate,			50,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Gate!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_EARTH
        , TRUE
    },

    {
	"strength",		{ L_APP },
	&spl_giant_strength,	20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel weaker.",
	SCHOOL_ALTERATION,
	MANA_EARTH
        , TRUE
    },

    {
	"bearstrength",		{ L_APP },
	&spl_bear,		20,	19,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYour load feels heavier as the spirit of the bear leaves your body.&n",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"elephantstrength",	{ L_APP },
	&spl_elephant,		20,	21,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your load feels heavier as the spirit of the &+Lelephant&n leaves your body.",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"lionrage",		{ L_APP },
	&spl_lion,		20,	22,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYou feel calmer as the spirit of the lion leaves your body.&n",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"hawkvision",		{ L_APP },
	&spl_hawk,		20,	22,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your vision is no longer as sharp.",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"shrewtameness",	{ L_APP },
	&spl_shrew,		20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel more like yourself as the spirit of the shrew leaves your body.",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"slowness",		{ L_APP },
	&spl_slowness,		20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RYour movements are now full speed again.&n",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"dexterity",		{ L_APP },
	&spl_dexterity,		20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel clumsier.",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
	"magnetism",		{ L_APP },
	&spl_magnetism,		20,	10,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less attractive.",
	SCHOOL_ILLUSION,
	MANA_EARTH,
        TRUE
    },

    {
	"harm",			{ L_APP },
	&spl_harm,		35,	16,
	"You tear $N&n's insides apart with a mighty harm spell!",
	"$n&n tears apart your insides with a mighty harm spell!",
	"$n&n hits $N&n with a harm spell!",
	"You harm yourself.  Ouch.",
	"$n&n performs a ritual of pain upon $mself.",
	"$n&n has done $N&n too much harm.",
	"!Harm!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"full harm",		{ L_APP },
	&spl_full_harm,		35,	22,
	"You call upon the power of your god to rend $N&n from the inside!",
	"$n&n shreds your insides with the power of $s god!",
	"$n&n blasts $N&n with a full harm spell!",
	"You full harm yourself.  Ouch.",
	"$n&n performs a ritual of pain upon $mself.",
	"$n&n has destroyed $N&n.",
	"!Full Harm!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"resurrect",			{ L_APP },
	&spl_resurrect,		50,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Heal!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"heal",			{ L_APP },
	&spl_heal,		50,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Heal!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
        "heal undead",                 { L_APP },
        &spl_heal_undead,              50,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Heal Undead!",
        SCHOOL_NECROMANCY,
        MANA_EARTH
        , TRUE
    },

    {
	"full heal",		{ L_APP },
	&spl_fullheal,		50,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Full Heal!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {   // Spell # 155
	"vitality",		{ L_APP },
	&spl_vitality,		50,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less vitalized.",
	SCHOOL_NECROMANCY,
	MANA_EARTH,
        TRUE
    },

    {
	"wolfspeed",		{ L_APP },
	&spl_wolf,		50,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYou feel less like a wolf and more like yourself.&n",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"pantherspeed",		{ L_APP },
	&spl_panther,		50,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYou feel less like the panther and more like yourself.&n",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"snailspeed",		{ L_APP },
	&spl_snail,		50,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYou feel less like the snail and more like yourself.&n.",
	SCHOOL_ANIMAL,
	MANA_EARTH,
        TRUE
    },

    {
	"identify",		{ L_APP },
	&spl_identify,		12,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Identify!",
	SCHOOL_DIVINATION,
	MANA_ANY
        , TRUE
    },

    {
	"infravision",		{ L_APP },
	&spl_infravision,	5,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer see in the dark.",
	SCHOOL_ILLUSION,
	MANA_FIRE
        , TRUE
    },

    {
	"chameleons charm",	{ L_APP },
	&spl_invis,		70,	11,
	"",
	"",
	"",
	"",
	"",
	"",
	"You are no longer invisible.",
	SCHOOL_ILLUSION,
	MANA_AIR,
        TRUE
    },

    {
	"invisibility",		{ L_APP },
	&spl_invis,		70,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You are no longer invisible.",
	SCHOOL_ILLUSION,
	MANA_AIR
        , TRUE
    },

    {
	"vacancy",		{ L_APP },
	&spl_vacancy,		70,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You are no longer hidden.",
	SCHOOL_ILLUSION,
	MANA_AIR,
        TRUE
    },

    {
	"mirage arcana",	{ L_APP },
	&spl_mirage_arcana,	70,	26,
	"",
	"",
	"",
	"",
	"",
	"",
	"You are no longer hidden.",
	SCHOOL_ILLUSION,
	MANA_AIR,
        TRUE
    },


    {
	"farsee",		{ L_APP },
	&spl_farsee,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"You vision is no longer extended.",
	SCHOOL_DIVINATION,
	MANA_AIR,
        TRUE
    },

    {
	"know alignment",	{ L_APP },
	&spl_know_alignment,			9,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Know Alignment!",
	SCHOOL_DIVINATION,
	MANA_FIRE
        , TRUE
    },

    {
	"reveal spirit essence",	{ L_APP },
	&spl_reveal_spirit_essence,			9,	10,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Reveal Spirit Essence!",
	SCHOOL_SPIRITUAL,
	MANA_FIRE
        , TRUE
    },

    {
	"lightning bolt",	{ L_APP },
	&spl_lightning_bolt,	15,	13,
	"Your &+Ylig&+Whtn&+Ying&N bolt&n hits $N&n, sending violent spasms through $S body.",
	"$n&n's &+Ylig&+Whtn&+Ying bolt&n slams into you!",
	"$n&n hits $N&n with a &+Ylig&+Whtn&+Ying bolt&n!",
	"You lightning bolt yourself like the fool that you are.",
	"$n&n shoots $mself in the arse with a bolt of lightning.",
	"$N&n crumples to the ground in a sizzling, blackened heap.",
	"!Lightning Bolt!",
	SCHOOL_EVOCATION,
	MANA_FIRE
        , TRUE
    },

    {
	"lightanddark",		{ L_APP },
	&spl_lightanddark,	15,	13,
	"&+LA searing cylindrical &+cshaf&+Ct of li&+cght&+L pierces through $N&n&+L, rending $S flesh and bones alike.",
	"$n&n&+L's sword sends &+ca niv&+Ceous sh&+caft of &+L&+Rfl&+res&+Rh-&+rt&+Re&+raring&+L light through you!",
	"&+LA searing cylindrical &+cshaf&+Ct of li&+cght&+L pierces through $N&n&+L, rending $S flesh and bones alike.",
	"&+MOUCH!&+L That REALLY did hurt!&n",
	"$n&n&+L blasts himself with his sword.",
	"$N&n&+L's body is blown to pieces in a fie&+cry ar&+Ctific&+ce of lig&+Lht!",
	"!LightAndDark!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

	{
	"tridenttides",		{ L_APP },
	&spl_tridenttides,	15,	13,
	"&+BA tor&+br&+ge&+Cn&+Gt&+cial s&+Cp&+cring of &+Cseawater ri&+cse&+gs a&n&+cbo&+Cut &n$N leaving $M &+Wgasping &nfor &+Cbreath!",
	"&+CYou &+Wgasp &+Cf&+cor&+C &+Cair&n&+c a&n&+gs &+ca &+Ctorrent&n&+c of &+Cwater&n&+c ri&+gs&n&+ge&n&+cs about you!",
	"&+BA tor&+br&+ge&+Cn&+Gt&+cial s&+Cp&+cring of &+Cseawater ri&+cse&+gs a&n&+cbo&+Cut &n$N leaving $M &+Wgasping &nfor &+Cbreath!",
	"&+MOUCH!&+L That REALLY did hurt!&n",
	"$n&n&+B nearly drowns himself again.",
	"$N&n&+L's body turn&ns a pale livid white as he falls &+Llifeless&n to the ground.",
	"!TridentTides!",
	SCHOOL_EVOCATION,
	MANA_WATER
        , TRUE
    },

    {
	"ball lightning",	{ L_APP },
	&spl_ball_lightning,	15,	13,
	"Your &+Ylig&+Whtn&+Ying&N ball&n hits $N&n, sending violent spasms through $S body.",
	"$n&n's &+Ylig&+Whtn&+Ying ball&n slams into you!",
	"$n&n hits $N&n with a &+Ylig&+Whtn&+Ying ball&n!",
	"You lightning ball yourself like the fool that you are.",
	"$n&n shoots $mself in the arse with a ball of lightning.",
	"$N&n crumples to the ground in a sizzling, blackened heap.",
	"!Lightning Ball!",
	SCHOOL_EVOCATION,
	MANA_FIRE
        , TRUE
    },

    {
	"touch of nightshade",	{ L_APP },
	&spl_touch_nightshade,			15,	14,
	"Your &+Ltouch of nightshade&n hits $N&n, sending pain through $S body.",
	"$n&n's &+Ltouch of nighshade&n causes you to writhe in pain!",
	"$n&n hits $N&n with a &+Ltouch of nighshade&n!",
	"You touch yourself with &+Lnighshade&n.  Duh.",
	"$n&n invoked a touch of &+Lnightshade&n upon $mself.",
	"$N&n crumples to the ground writhing in pain.",
	"!Touch of Nightshade!",
	SCHOOL_EVOCATION,
	MANA_EARTH,
        TRUE
    },

    {
	"cone of cold",		{ L_APP },
	&spl_cone_of_cold,	15,	16,
	"Your &+Ccone of cold&n &+bfreezes&n $N&n.",
	"$n&+b hits you with a &+Ccone of cold&n!",
	"$n&+b hits &n$N&+b with a &+Ccone of cold&n!",
	"&+bYou &+Cfreeze&+b yourself&n.",
	"$n&n blasts $mself with a cone of cold.",
	"$N&+W falls to the ground, covered in icicles.&n",
	"!Cone of Cold!",
	SCHOOL_EVOCATION,
	MANA_WATER,
        TRUE
    },

    {
	"locate object",	{ L_APP },
	&spl_locate_object,			20,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Locate Object!",
	SCHOOL_DIVINATION,
	MANA_ANY,
        TRUE
    },

    {
	"minor creation",	{ L_APP },
	&spl_minor_creation,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Minor Creation!",
	SCHOOL_CONJURATION,
	MANA_ANY,
        TRUE
    },

    {
	"elemental creation",	{ L_APP },
	&spl_elemental_creation,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Elemental Creation!",
	SCHOOL_CONJURATION,
	MANA_ANY,
        TRUE
    },

    {
	"animate dead",		{ L_APP },
	&spl_animate_dead,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Animate Dead!",
	SCHOOL_NECROMANCY,
	MANA_ANY,
	TRUE
    },

    {
        "raise skeleton",         { L_APP },
        &spl_raise_skeleton,                   20,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Raise Skeleton!",
        SCHOOL_NECROMANCY,
        MANA_ANY,
        TRUE
    },

    {
        "raise zombie",         { L_APP },
        &spl_raise_zombie,                   20,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Raise Zombie!",
        SCHOOL_NECROMANCY,
        MANA_ANY,
        TRUE
    },

    {
        "raise spectre",         { L_APP },
        &spl_raise_spectre,                   20,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Raise Spectre!",
        SCHOOL_NECROMANCY,
        MANA_ANY,
        TRUE
    },

    {
        "raise wraith",         { L_APP },
        &spl_raise_wraith,                   20,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Raise Wraith!",
        SCHOOL_NECROMANCY,
        MANA_ANY,
        TRUE
    },

    {
        "raise vampire",         { L_APP },
        &spl_raise_vampire,                   20,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Raise Vampire!",
        SCHOOL_NECROMANCY,
        MANA_ANY,
        TRUE
    },

    {
        "raise lich",         { L_APP },
        &spl_raise_lich,                   20,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Raise Lich!",
        SCHOOL_NECROMANCY,
        MANA_ANY,
        TRUE
    },

    {
	"magic missile",	{ L_APP },
	&spl_magic_missile,	15,	8,
	"Your &+Ymagic missile&n strikes $N&n solidly.",
	"You are hit by a &+Ymagic missile&n from $n&n!",
	"$N&n staggers as $E is hit by a &+Ymagic missile&n from $n&n.",
	"You &+Ymagic missile&n yourself.",
	"$n&n hits $mself with a &+Ymagic missile&n!",
	"$N&n is slain by a mighty &+Ymagic missile&n sent by $n&n!",
	"!Magic Missile!",
	SCHOOL_EVOCATION,
	MANA_FIRE
        , TRUE
    },

    {
	"ultra death ray",	{ L_APP },
	&spl_ultra_death_ray,	15,	16,
	"Your &+Ymagic missile&n strikes $N&n solidly.",
	"You are hit by a &+Ymagic missile&n from $n&n!",
	"$N&n staggers as $E is hit by a &+Ymagic missile&n from $n&n.",
	"You &+Ymagic missile&n yourself.",
	"$n&n hits $mself with a &+Ymagic missile&n!",
	"$N&n is slain by a mighty &+Ymagic missile&n sent by $n&n!",
	"!Magic Missile!",
	SCHOOL_EVOCATION,
	MANA_FIRE
        , TRUE
    },

    {
	"bonethunder",		{ L_APP },
	&spl_bonethunder,	15,	8,
	"$N&n shudders violently at the staff's effects!",
	"$n&n's staff makes a loud cracking sound and your bones feel like they are breaking!",
	"$N&n shudders violents at the sound of $n&n's staff!",
	"",
	"",
	"$N&n gives a violent shudder and collapses, $S back broken!",
	"!Bonethunder!",
	SCHOOL_EVOCATION,
	MANA_WATER
        , TRUE
    },

    {
	"flameburst",		{ L_APP },
	&spl_flameburst,	15,	12,
	"Your &+Rflameburst&n &+rburns&n $N&n.",
	"$n&n &+rburns&n you with $s &+rflameburst&n.",
	"$n&n &+rburns&n $N&n with $s &+rflameburst&n.",
	"You hit yourself with your &+rflameburst&n.  Duh.",
	"$n&n bursts into &+rflames&n!",
	"$N&n is burned to death!",
	"!Flameburst!",
	SCHOOL_ELEMENTAL,
	MANA_WATER,
        TRUE
    },

    {
	"ice missile",		{ L_APP },
	&spl_ice_missile,	15,	10,
	"Your &+Cice missile&n hits $N&n.",
	"You are hit by an &+Cice missile&n from $n&n!",
	"$n&n hits &n$N with an &+Cice missile&n.",
	"Like a genius, you hit yourself with your &+Cice missile&n.",
	"$n&n shoots $mself in the foot with an &+Cice missile&n",
	"",
	"!Ice Missile!",
	SCHOOL_ELEMENTAL,
	MANA_WATER,
        TRUE
    },

    {
	"scalding blast",	{ L_APP },
	&spl_scalding,		15,	19,
	"You &+rscald&n $N&n with a burning column of water.",
	"$n&n &+rburns&n you with a boiling column of water.",
	"$n&n &+rburns&n $N&n with a scalding column of water.",
	"You boil yourself in a bath of hot water.",
	"$n&n boils $mself in a bath of hot water.!",
	"$N&n drops to the ground, $S flesh red and blistered!",
	"!Scalding Blast!",
	SCHOOL_ELEMENTAL,
	MANA_WATER,
        TRUE
    },

    {
	"molten spray",		{ L_APP },
	&spl_molten,		15,	15,
	"Your &+rburst of lava&n slams into $N&n.",
	"Ouch!  Lava slams into you!",
	"$n&n &+rburns&n $N&n with a &+Rburst of lava&n from $s fingertips.",
	"You douse yourself with hot lava.",
	"$n&n covers $mself with &+Rburning lava&n!",
	"$N&n drops to the ground, cooked to a crisp.",
	"!Molten Spray!",
	SCHOOL_ELEMENTAL,
	MANA_FIRE,
        TRUE
    },

    {
	"scorching touch",	{ L_APP },
	&spl_scorching,		15,	17,
	"Your scorching touch hurts $N&n.",
	"You get scorched by $n&n!",
	"$N&n cries out in pain as $n&n scorches $M.",
	"You scorch yourself.",
	"$n&n scorches $mself with $s spell.  What a bungling idiot!",
	"$N&n drops to the ground, cooked cajun-style.",
	"!Scorching Touch!",
	SCHOOL_ELEMENTAL,
	MANA_FIRE,
        TRUE
    },

    {
	"scathing wind",	{ L_APP },
	&spl_scathing_wind,	15,	15,
	"Your scathing wind hits $N&n.",
	"You are hit by $n&n's scathing wind!",
	"$N&n cries out in pain as $n&n's scathing wind hits $M.",
	"You scathe yourself.",
	"$n&n scathes $mself with $s spell.",
	"$N&n drops to the ground, torn to shreds.",
	"!Scathing Wind!",
	SCHOOL_ELEMENTAL,
	MANA_FIRE,
        TRUE
    },

    {
	"tidal wave",		{ L_APP },
	&spl_tidal_wave,			15,	16,
	"&+bYour tidal wave bruises and batters $N&n.",
	"&+bYou are hit by gigantic tidal wave!&n",
	"&+b$N&+b is battered severely be a giant wall of water.&n",
	"&+bYou drown yourself.&n",
	"&+b$n&+b drowns $mself with $s spell.&n",
	"",
	"!Tidal Wave!",
	SCHOOL_INVOCATION,
	MANA_WATER,
        TRUE
    },

    {
	"cyclone",		{ L_APP },
	&spl_cyclone,			15,	16,
	"&+cYour cyclone batters $N&n.",
	"&+cYou are battered by $n&n's&+c cyclone!&N",
	"$N&n is tossed and battered as $n&n's cyclone hits $M.",
	"&+CYou cyclone yourself.&N",
	"$n&n&+c batters $mself with $s cyclone.&N",
	"$N&n&+c falls to the ground, torn to shreds.&N",
	"!Cyclone!",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"whirlwind",		{ L_APP },
	&spl_whirlwind,			15,	18,
	"&+WYour whirlwind beats and batters $N&n.",
	"&+WYou are knocked about by $n&n's&+W whirlwind!&N",
	"$N&+W is tossed and battered as $n&+W's whirlwind hits $M.",
	"&+WYou whirlwind yourself.&N",
	"$n&n&+W batters $mself with $s whirlwind.&N",
	"&+WPieces of $N&n&+c fall to the ground, scattered in different locations.&N",
	"!Whirlwind!",
	SCHOOL_CONJURATION,
	MANA_AIR,
        TRUE
    },

    {
	"ice storm",		{ L_APP },
	&spl_ice_storm,		15,	16,
	"Your &+Wice storm&n hits $N&n.",
	"You are hit by a storm of &+Wice and snow&n conjured by $n&n's!",
	"$N&n shivers $n&n's &+Wice storm&n hits $M.",
	"You ice storm yourself.",
	"$n&n freezes $mself with $s spell.",
	"$N&n falls over, &+Wfrozen&n solid.",
	"!Ice Storm!",
	SCHOOL_INVOCATION,
	MANA_AIR,
        TRUE
    },

    {
	"inferno",		{ L_APP },
	&spl_inferno,			15,	17,
	"Your &+rinferno&n burns $N&n.",
	"You are hit by a raging &+rinferno&n!",
	"$N&n is burned severely by the &+rflames&n.",
	"You &+rinferno&n yourself.",
	"$n&n &+rburns&n $mself with $s spell.",
	"$N&n falls over, &+Lcharred&n beyond recognition.",
	"!Inferno!",
	SCHOOL_INVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"earthen rain",		{ L_APP },
	&spl_earthen_rain,			15,	18,
	"Your pelt $N&n with &+Lstones&n.",
	"You are hit by &+Lstones&n falling from the sky!",
	"$N&n is pelted by &+Lstones&n falling from the sky.",
	"You pummel yourself with stones.",
	"$n&n pummels $mself with &+Lstones&n.",
	"$N&n crumples to the ground, smashed to death.",
	"!Earthen Rain!",
	SCHOOL_ELEMENTAL,
	MANA_FIRE,
        TRUE
    },

    {
	"spirit anguish",	{ L_APP },
	&spl_spirit_anguish,	15,	14,
	"&+WYour spirit attacks $N&n viciously.&N",
	"&+WYour spirit shudders at $n&n's attack upon it.&N",
	"&+W$n&n unleashes $s spirit venomously at $N!&N",
	"Your spirit shudders as it battles with your will.",
	"$n&n seems to be suffering from an inner turmoil.",
	"$N&n's body suddenly turns pale as it gives up the ghost.",
	"!Spirit Anguish!",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"soul disturbance",	{ L_APP },
	&spl_soul_disturbance,	15,	16,
	"You disturb $N&n's soul.",
	"Your soul feels really uncomfortable.",
	"$n&n raises $s arms and $N&n looks really uncomfortable.",
	"You try to fold up your soul, but fail.",
	"$n&n tries to fold $s soul up and put it in $s pocket.",
	"$N&n drops to the ground, $S body half as battered as $S soul.",
	"!Soul Disturbance!",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"greater soul disturbance",{ L_APP },
	&spl_gr_soul_dist,			15,	18,
	"You wrinkle the hell out of $N&n's soul.",
	"Your soul is folded in half as $n&n raises $s arms.",
	"$N&n's body contorts wildly as his soul is manhandled by $n&n.",
	"You take out your soul and jump on it a few times, then put it back.",
	"$n&n tries to turn $s sould into a jigsaw puzzle.",
	"$N&n's soul is battered and contorted beyond repair.",
	"!Greater Soul Disturbance!",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"melfs acid arrow",	{ L_APP },
	&spl_acid_arrow,		15,	9,
	"The &+gacid&n eats at $N&n's flesh.",
	"The &+gacid arrow&n eats at your flesh.",
	"$N&n winces in pain as the &+gacid&n eats at $S flesh.",
	"Your &+gacid arrow&n burns you.",
	"$n&n burns $mself with an &+gacid arrow&n!",
	"$N&n is slain by a viscous &+gacid arrow&n sent by $n&n!",
	"!Acid Arrow!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"immolate",		{ L_APP },
	&spl_immolate,		15,	16,
	"The &+rfire&n burns $N&n's flesh.",
	"&+rThe flames cause you intense pain!&n",
	"$N&n screams as the &+rfire&n burns $S flesh.",
	"Your &+rimmolate&n burns you.",
	"$n&n burns $mself with an &+rimmolate&n spell!",
	"",
	"!Immolate!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"nightmares",		{ L_APP },
	&spl_nightmares,	15,	16,
	"$N&n is tormented with visions of unspeakable horror.",
	"&+LYou are tormented by visions of unspeakable horror.",
	"$N&n is tormented by visions of unspeakable horror.",
	"Your nightmares torment you.",
	"$n&n torments $mself with nightmares!",
	"",
	"!Nightmares!",
	SCHOOL_ILLUSION,
	MANA_WATER,
        TRUE
    },

    {
	"wierd",		{ L_APP },
	&spl_wierd,		15,	18,
	"&+m$N&+m's mind is warped and stretched to its limits.",
	"&+mAn invisible force grabs hold of your mind and begins to twist violently.&n.",
	"&+m$N&+m's mind is twisted and stretched by $n&n.",
	"Your wierdness warps your mind.",
	"$n&n torments $mself with wierdness!",
	"",
	"!Wierd!",
	SCHOOL_ILLUSION,
	MANA_WATER,
        TRUE
    },


    {
	"conflaguration",	{ L_APP },
	&spl_conflaguration,	15,	17,
	"The &+rfire&n burns $N&n's flesh.",
	"&+rThe fiery conflaguration burns away your flesh!&n",
	"$N&n screams as the &+rconflaguration&n burns $S flesh.",
	"&+rThe fiery conflaguration burns away your flesh!&n",
	"$n&n burns $mself with an &+rconflaguration&n spell!",
	"",
	"!Conflaguration!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"incendiary cloud",	{ L_APP },
	&spl_incendiary_cloud,	15,	17,
	"The &+rcloud of flames&n burns $N&n's flesh.",
	"&+rThe cascading cloud of flames burns you severely!&n",
	"&+rThe cloud of flames burns $N&+r severely.&n",
	"Your &+rincendiary cloud&n burns you.",
	"$n&n burns $mself with an &+rincendiary cloud&n spell!",
	"",
	"!Incendiary Cloud!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"creeping doom",	{ L_APP },
	&spl_creeping_doom,	15,	18,
	"&+LThe insects devour $N&+L's flesh.&n",
	"&+LA cloud of crawling, stinging, flesh-eating &+yins&+gects&+L tears the flesh from your bones!&n",
	"&+L$N&+L screams as insects devour $S flesh.&n",
	"&+LYour insects chew on you.&n",
	"&+LHungry bugs chew on $n&n.",
	"$N&n's bones fall to the ground, stripped of all flesh and covered in crawling insects.",
	"!Creeping Doom!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },

    {
	"mass heal",		{ L_APP },
	&spl_mass_heal,        	50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Mass Heal!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"group heal",		{ L_APP },
	&spl_group_heal,           	50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Group Heal!",
	SCHOOL_NECROMANCY,
	MANA_EARTH
        , TRUE
    },

    {
	"wellness",		{ L_APP },
	&spl_wellness,           	50,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Wellness!",
	SCHOOL_SPIRITUAL,
	MANA_EARTH
        , TRUE
    },

    {
	"mass invisibility",		{ L_APP },
	&spl_mass_invis,	20,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"You are no longer invisible.",
	SCHOOL_ILLUSION,
	MANA_AIR
        , TRUE
    },

    {
        "silence",		{ L_APP },
        &spl_silence,		20,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You are no longer muted.",
	SCHOOL_ABJURATION | SCHOOL_NECROMANCY,
        MANA_WATER
        , TRUE
    },

    {
	"pass door",		{ L_APP },
	&spl_pass_door,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel solid again.",
	SCHOOL_ALTERATION,
	MANA_AIR
        , TRUE
    },

    {
	"plague",		{ L_APP },
	&spl_plague,		20,	12,
	"Your sickness infests $N&n",
	"You feel sick.",
	"$n&n infects $N&n with the plague.",
	"You plague yourself.",
	"",
	"",
	"Your sores vanish.",
	SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"poison",		{ L_APP },
	&spl_poison,		10,	12,
	"You smirk as $N&n writhes in agony from the poison.",
	"You feel a burning sensation in your blood.",
	"$n&n has poisoned $N&n!",
	"Your poison coarses through your veins.",
	"",
	"",
	"You feel the poison in your body dissipate.",
	SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"pythonsting",		{ L_APP },
	&spl_pythonsting,	10,	17,
	"&+gA python suddenly appears and bites &n$N&n&+g in the leg!&n",
	"&+gA python suddenly appears and bites you in the leg!&n",
	"&+gA python suddenly appears and bites &n$N&n&+g in the leg!&n",
	"&+gYou conjure a python that starts gnawing on your arm.&n",
	"&+g$n&n conjures a python which sinks its fangs deeply into $s arm.&n",
	"&+gThe python disappears before taking the time to swallow $N&n.",
	"You feel less sick.",
	SCHOOL_ANIMAL,
	MANA_WATER,
        TRUE
    },

    {
	"greater pythonsting",	{ L_APP },
	&spl_gr_pythonsting,			10,	19,
	"&+gA large python suddenly appears and bites &n$N&n&+g in the leg!&n",
	"&+gA large python suddenly appears and bites you in the leg!&n",
	"&+gA large python suddenly appears and bites &n$N&n&+g in the leg!&n",
	"&+gYou conjure a python that starts gnawing on your ass.&n",
	"&+g$n&n conjures a python which sinks its fangs deeply into $s ass.&n",
	"&+gThe large python disappears before taking the time to swallow $N&n.",
	"You feel less sick.",
	SCHOOL_ANIMAL,
	MANA_WATER,
        TRUE
    },

    {
	"polymorph other",	{ L_APP },
	&spl_polymorph,		20,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your body feels familiar again.",
	SCHOOL_ALTERATION,
	MANA_ANY
        , TRUE
    },

    {
	"change self",	        { L_APP },
	&spl_change_self,	20,	10,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your return to your normal self.",
	SCHOOL_ALTERATION,
	MANA_ANY,
        TRUE
    },

    {
	"xcall of the wild",	{ L_APP },
	&spl_call_wild,			20,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your body feels familiar again.",
	SCHOOL_ANIMAL,
	MANA_ANY,
        TRUE
    },

    {
	"minor globe",		{ L_APP },
	&spl_minor_globe,			5,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RYour globe shimmers and fades into thin air.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"major globe",		{ L_APP },
	&spl_major_globe,	5,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RYour globe shimmers and fades into thin air.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"group globe",		{ L_APP },
	&spl_group_globe, 			5,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RYour globe shimmers and fades into thin air.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"spirit ward",		{ L_APP },
	&spl_spirit_ward,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+WYour protective aura dissipates.&n",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"greater spirit ward",	{ L_APP },
	&spl_gr_spirit_ward,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+WYour protective aura dissipates.&n",
	SCHOOL_SPIRITUAL,
	MANA_FIRE,
        TRUE
    },

    {
	"deny air",		{ L_APP },
	&spl_deny_air,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+CYou feel less protected from air.&n",
	SCHOOL_ENCHANTMENT,
	MANA_AIR,
        TRUE
    },

    {
	"deny earth",		{ L_APP },
	&spl_deny_earth,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYou feel less protected from air.&n",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"deny fire",		{ L_APP },
	&spl_deny_fire,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+rYou feel less protected from fire.&n",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
        TRUE
    },

    {
	"deny water",		{ L_APP },
	&spl_deny_water,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+bYou feel less protected from water.&n",
	SCHOOL_ENCHANTMENT,
	MANA_WATER,
        TRUE
    },

    {
	"protection from evil",	{ L_APP },
	&spl_prot_evil,		5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less protected from &+revil&n.",
	SCHOOL_ABJURATION,
	MANA_FIRE
        , TRUE
    },


    {
	"protection from good",	{ L_APP },
	&spl_protection_good,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less protected.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"harbor of balance",	{ L_APP },
	&spl_harbor_balance,			5,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less protected from the unbalanced.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"protection from acid",	{ L_APP },
	&spl_protect_acid,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+gYou feel less protected.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"protection from cold",	{ L_APP },
	&spl_protect_cold,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+WYou feel less protected.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"protection from fire",	{ L_APP },
	&spl_protect_fire,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+rYou feel less protected.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"adaptation",		{ L_APP },
	&spl_adaptation,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"You are no longer so well-adapted to other environments.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"fire ward",		{ L_APP },
	&spl_fire_ward,		5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+rYou are no longer warded against fire.&n",
	SCHOOL_ELEMENTAL,
	MANA_FIRE,
        TRUE
    },

    {
	"cold ward",		{ L_APP },
	&spl_cold_ward,		5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+WYou are no longer warded against cold.&n",
	SCHOOL_ELEMENTAL,
	MANA_AIR,
        TRUE
    },

    {
	"protection from gas",	{ L_APP },
	&spl_protect_gas,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+YYou feel less protected.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"protection from lightning",{ L_APP },
	&spl_protect_lightning,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+BYou feel less &+Yprotected.&n",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
        "protect undead",{ L_APP },
        &spl_protect_undead,                   5,      12,
        "",
        "",
        "",
        "",
        "",
        "",
        "!Protect Undead!",
        SCHOOL_NECROMANCY,
        MANA_EARTH,
        TRUE
    },

    {                                  
        "recharge item",        { L_APP },
        &spl_recharge_item,                   25,     12,
        "blunder",
	"",
	"",
	"",
	"",
	"",
        "!Recharge Item!",
        SCHOOL_INVOCATION | SCHOOL_ENCHANTMENT,
        MANA_ANY
        , TRUE
    }, 

    {
	"rejuvenate",		{ L_APP },
	&spl_rejuvenate,	12,	48,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Rejuvenate!",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
	"vigorize light",	{ L_APP },
	&spl_vig_light,		12,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Vigorize Light!",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
	"stamina",		{ L_APP },
	&spl_stamina,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Stamina!",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
	"vigorize serious",	{ L_APP },
	&spl_vig_serious,	12,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Vigorize Serious!",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
	"greater stamina",	{ L_APP },
	&spl_gr_stamina,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Greater Stamina!",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
	"vigorize critical",	{ L_APP },
	&spl_vig_critical,	12,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Vigorize Critical!",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
        "remove alignment",	{ L_APP },
        &spl_remove_alignment,			10,	12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Remove Alignment!",
	SCHOOL_ABJURATION,
        MANA_WATER
        , TRUE
    },

    {
        "preserve",		{ L_APP },
        &spl_preserve,			10,	13,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Preserve!",
	SCHOOL_ENCHANTMENT,
        MANA_WATER,
        TRUE
    },

    {
	"remove curse",		{ L_APP },
	&spl_remove_curse,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Remove Curse!",
	SCHOOL_ABJURATION,
	MANA_WATER
        , TRUE
    },

    {
	"negate hex",		{ L_APP },
	&spl_negate_hex,			5,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Negate Hex!",
	SCHOOL_ABJURATION,
	MANA_WATER,
        TRUE
    },

    {
        "remove silence",	{ L_APP },
        &spl_remove_silence,			15,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Remove Silence!",
	SCHOOL_ABJURATION | SCHOOL_NECROMANCY,
        MANA_WATER
        , TRUE
    },

    {
	"sanctuary",		{ L_APP },
	&spl_sanctuary,			75,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"The white aura around your body fades.",
	SCHOOL_ABJURATION,
	MANA_WATER
        , TRUE
    },

    {
	"shield",		{ L_APP },
	&spl_shield,		12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your force shield shimmers then fades away.",
	SCHOOL_CONJURATION,
	MANA_ANY,
        TRUE
    },

    {
	"shadow shield",	{ L_APP },
	&spl_shadow_shield,			12,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+LYou are no longer protected by the shadows.&n",
	SCHOOL_CONJURATION,
	MANA_ANY,
        TRUE
    },

    {
	"shocking grasp",	{ L_APP },
	&spl_shocking_grasp,	15,	12,
	"Your &+Wshocking&+B grasp&n sends spasms of pain through $N&n's body.",
	"You are &+WSho&+Bcked&n by $n&n!",
	"$n&n grabs $N&n, &+Wsho&+Bcking&n $M!",
	"You &+WSh&+Bock&n yourself.",
	"$n&n &+Wsho&+Bocks&n $mself, making $s hair stand on end!",
	"$N&n dies with a look of shock on $S face.",
	"!Shocking Grasp!",
	SCHOOL_EVOCATION,
	MANA_FIRE
        , TRUE
    },

    {
	"sleep",		{ L_APP },
	&spl_sleep,		15,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less tired.",
	SCHOOL_ENCHANTMENT | SCHOOL_CHARM,
	MANA_EARTH
        , TRUE
    },

    {
	"minor paralysis",	{ L_APP },
	&spl_minor_para,	15,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+YYou can move again.&n",
	SCHOOL_ENCHANTMENT | SCHOOL_CHARM,
	MANA_EARTH,
        TRUE
    },

    {
	"entangle",		{ L_APP },
	&spl_entangle,			15,	13,
	"&+gYou conjure grasping &+Gvines&+g to restrain $N.&n",
	"&+gGrasping &+Gvines&+g grab hold of your limbs and squeeze you tightly.&n",
	"&+g$n&+g conjures grasping &+Gvines&n to restrain $N.&n",
	"You entangle yourself",
	"$n&n entangles $mself.",
	"$N&n is strangled to death by the &+gvines&n.",
	"&+gYou are no longer entangled.&n",
	SCHOOL_ENCHANTMENT | SCHOOL_CHARM,
	MANA_EARTH,
        TRUE
    },

    {
	"thirst",		{ L_APP },
	&spl_thirst,			15,	13,
	"You make $N&n's face shrivel inward!",
	"Your face shrivels inward.",
	"$N&n's face shrivels inward.",
	"Your face shrivels inward.",
	"$n&n's face shrivels inward..",
	"$N&n thirsts to death.",
	"&+BYou are no longer so thirsty.&n",
	SCHOOL_ENCHANTMENT | SCHOOL_CHARM,
	MANA_EARTH,
        TRUE
    },

    {
	"earthen grasp",	{ L_APP },
	&spl_earthen_grasp,	15,	16,
	"&+yYou conjure an earthen hand, which grasps at $N&n",
	"&+yA giant hand forms from the earth and grasps at you!&n",
	"&+y$n&+y conjures an earthen hand that grasps at $N&+y.&n",
	"&+yYou hit yourself with a grasping hand.&n",
	"&+y$n&+y is hit by $s own spell.&n",
	"&+y$N&+y's body returns to the earth.&n",
	"&+yYou can move again.&n",
	SCHOOL_ELEMENTAL,
	MANA_EARTH,
        TRUE
    },

    {
	"greater earthen grasp",{ L_APP },
	&spl_gr_earthen_grasp,	15,	24,
	"&+yYou conjure an earthen hand, which grasps at $N&n",
	"&+yA giant hand forms from the earth and grasps at you!&n",
	"&+y$n&+y conjures an earthen hand that grasps at $N&+y.&n",
	"&+yYou hit yourself with a grasping hand.&n",
	"&+y$n&+y is hit by $s own spell.&n",
	"&+y$N&+y's body returns to the earth.&n",
	"&+yYou can move again.&n",
	SCHOOL_ELEMENTAL,
	MANA_EARTH,
        TRUE
    },


    {
	"group stoneskin",	{ L_APP },
	&spl_group_stone,			20,	19,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your skin returns to normal.",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"battering stonestorm",	{ L_APP },
	&spl_stonestorm,	20,	17,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
        TRUE
    },
    
    {
    	"hurricane",		{ L_APP },
    	&spl_hurricane,			20, 	13,
    	"Your &+churricane&N tears $N&n to shreds.",
	"$n conjures a &+churricane&n to destroy you!",
	"A &+churricane&n blows through the area tearing into $N&n.",
	"You try to blow yourself away.",
	"$n&n is twirled around by $s own &+churricane!&n",
	"$N&n gasps as the &+Churricane&n steals their last breath.",
	"",
    	SCHOOL_CONJURATION,
    	MANA_AIR,
    	TRUE
    },
    
    {
	"flashfire",		{ L_APP },
	&spl_flashfire,			20,	10,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+RThe sparks fade as the world speeds up around you.&n",
	SCHOOL_CONJURATION,
	MANA_FIRE,
    	TRUE
    },
    
    {
    	"bombard",		{ L_APP },
    	&spl_bombard,		20, 	17,
    	"Your &+Lrocks and stones&n crush $N&n.",
	"$n causes &+Lrocks and stones&n to fall right on top of you!",
	"A &+Lrocks and stones&n fall from the sky crushing $N&n.",
	"You drop rocks on your own head.",
	"$n&n is crushed by $s own &+Lrocks and stones!&n",
    	"$N&+L is crushed to death by falling rocks.&n",
	"",
    	SCHOOL_CONJURATION,
    	MANA_EARTH,
    	TRUE
    },
    
    {
    	"mass dispel magic",	{ L_APP },
   	&spl_mass_dispel_magic,			20, 	19,
    	"",
	"",
	"",
	"",
	"",
    	"",
	"",
   	SCHOOL_CONJURATION,
    	MANA_AIR,
    	TRUE
    },
    
    {
	"stonestrength",	{ L_APP },
	&spl_stonestrength,			20,	13,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+yYour added strength returns to the earth.&n",
	SCHOOL_ALTERATION,
	MANA_EARTH,
    	TRUE
    },

    {
	"stoneskin",		{ L_APP },
	&spl_stoneskin,		12,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+LYou feel your skin soften and become normal again.&n",
	SCHOOL_ALTERATION,
	MANA_EARTH,
        TRUE
    },

    {
	"summon",		{ L_APP },
	&spl_summon,			50,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Summon!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR
        , TRUE
    },

    {
	"teleport",		{ L_APP },
	&spl_teleport,		50,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Teleport!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR
        , TRUE
    },

    {
	"plane shift",		{ L_APP },
	&spl_plane_shift,	 		35,	30,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Plane Shift!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },


    {
	"flickering flame",	{ L_APP },
	&spl_flickering_flame,	 		35,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Flickering Flame!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

    {
	"ripple",		{ L_APP },
	&spl_ripple,	 		35,	11,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Ripple!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_WATER,
        TRUE
    },

    {
	"turn undead",		{ L_APP },
	&spl_turn_undead,	10,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Turn undead!",
	SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"destroy undead",	{ L_APP },
        &spl_destroy_undead,		10,	13,
	"You call upon your god to return $N&n to the grave.",
	"A beam of light from the heavens strikes you!  AARRRRRGGGHHH!",
	"$n&n blasts $N&n with holy power!",
	"You try to destroy yourself.",
	"&n&n destroys $mself.",
	"$N&n explodes!",
	"!Turn undead!",
	SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"ventriloquate",	{ L_APP },
	&spl_ventriloquate,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Ventriloquate!",
	SCHOOL_PHANTASM,
	MANA_AIR
        , TRUE
    },

    {
	"weaken",		{ L_APP },
	&spl_enfeeblement,	20,	12,
	"weakening spell",
	"",
	"",
	"",
	"",
	"",
	"You feel stronger.",
	SCHOOL_NECROMANCY,
	MANA_WATER
        , TRUE
    },

    {
	"feeblemind",		{ L_APP },
	&spl_feeblemind,	20,	15,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer feel like a total moron.",
	SCHOOL_ENCHANTMENT,
	MANA_WATER,
        TRUE
    },

    {
	"word of recall",	{ L_APP },
	&spl_recall,		5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Word of Recall!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

    {
	"group recall",		{ L_APP },
	&spl_group_recall,			0,	20,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Group Recall!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

/*
 * Dragon breath.
 */
    {
	"acid breath",		{ L_APP },
	&spl_acid_breath,			50,	12,
	"You breathe &+Gacid&n on $N&n, melting flesh from $S body.",
	"$n&n breathes &+Gacid&n on you!",
	"$n&n breathes &+Gacid&n on $N&n, melting flesh from $S body.",
	"You breathe &+Gacid&n on yourself!",
	"$n&n screams out in agony as $e breathes &+Gacid&n on $mself.",
	"$N&n's body dissolves into &+Gg&N&+goo&n.",
	"!Acid Breath!",
	SCHOOL_EVOCATION,
	MANA_WATER,
        FALSE
    },

    {
	"fire breath",		{ L_APP },
	&spl_fire_breath,			50,	12,
	"You breathe $N&n with &+rfire&n, burning flesh from $S body.",
	"$n&n breathes &+rfire&n on you!",
	"$n&n breathes &+rfire&n on $N&n, burning flesh from $S body.",
	"You breathe &+rfire&n on yourself!",
	"$n&n screams out in agony as $e breathes &+rfire&n on $mself.",
	"$N&n's body collapses into a pile of &+lash&n.",
	"!Fire Breath!",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        FALSE
    },

    {
	"water breath",		{ L_APP },
	&spl_water_breath,			50,	12,
	"You breathe &+csteam&n on $N&n, burning flesh from $S body.",
	"$n&n breathes &+csteam&n on you!",
	"$n&n breathes &+csteam&n on $N&n, burning flesh from $S body.",
	"You breathe &+csteam&n on yourself!",
	"$n&n screams out in agony as $e breathes &+csteam&n on $mself.",
	"$N&n's body collapses into a pile of &+rbloody &+yg&+wo&+mo&n.",
	"!Water Breath!",
	SCHOOL_EVOCATION,
	MANA_WATER
        , FALSE
    },

    {
	"frost breath",		{ L_APP },
	&spl_frost_breath,			50,	12,
	"You breathe &+Bfrost&n on $N&n, &+cchilling&n $M&N.",
	"$n&n breathes &+Bfrost&n on you!",
	"$n&n breathes &+Bfrost&n on $N&n, &+cchilling&n $M&N.",
	"You breathe &+Bfrost&n on yourself!",
	"$n&n screams out in agony as $e breathes &+Bfrost&n on $mself.",
	"$N&n's body crystallizes into an &+ci&+bc&+ce &+cst&+bat&+cue&n.",
	"!Frost Breath!",
	SCHOOL_EVOCATION,
	MANA_WATER
        , FALSE
    },

    {
	"gas breath",		{ L_APP },
	&spl_gas_breath,			50,	12,
	"You breathe &+Ggas&n on $N&n, &+gchoking&n $M&N.",
	"$n&n breathes &+Ggas&n on you!",
	"$n&n breathes &+Ggas&n on $N&n, &+gchoking&n $M&N.",
	"You breathe &+Ggas&n on yourself!",
	"$n&n screams out in agony as $e breathes &+Ggas&n on $mself.",
	"$N&n's body dissolves into &+Mt&n&+mox&+Mi&n&+mc &+gg&+Go&n&+go&n.",
	"!Gas Breath!",
	SCHOOL_EVOCATION,
	MANA_AIR
        , FALSE
    },

    {
	"lightning breath",	{ L_APP },
	&spl_lightning_breath,			50,	12,
	"You breathe &+Ylig&+Whtn&+Ying&n on $N&n, &+yshocking&n $M&N.",
	"$n&n breathes &+Ylig&+Whtn&+Ying&n on you!",
	"$n&n breathes &+Ylig&+Whtn&+Ying&n on $N&n, &+yshocking&n $M&N.",
	"You breathe &+Ylig&+Whtn&+Ying&n on yourself!",
	"$n&n screams out in agony as $e breathes &+Ylig&+Whtn&+Ying&n on $mself.",
	"$N&n's body &+Yconv&nulses o&+Yn&n the f&+Ylo&nor, and t&+Yh&nen is &+lstill&n.",
	"!Lightning Breath!",
	SCHOOL_EVOCATION,
	MANA_ANY
        , FALSE
    },

    {
        "general purpose",      { L_APP },
	&spl_general_purpose,                   0,      12,
	"general purpose ammo",
	"",
	"",
	"",
	"",
	"",
	"!General Purpose Ammo!",
	SCHOOL_NONE,
	MANA_NONE
        , FALSE
    },

    {
        "high explosive",       { L_APP },
	&spl_high_explosive,                   0,      12,
	"high explosive ammo", 
	"",
	"",
	"",
	"",
	"",
	"!High Explosive Ammo!",
	SCHOOL_NONE,
	MANA_NONE
        , FALSE
    },

    {
        "adrenaline control",   { L_APP },
        &spl_adrenaline_control,                           40,      12,
        "",
	"",
	"",
	"",
	"",
	"",
        "The adrenaline rush wears off.",
	SCHOOL_ALTERATION,
        MANA_WATER
        , TRUE
    },

    {
        "agitation",            { L_APP },
        &spl_agitation,         10,     13,
	"You agitate $N&n's molecules.",
	"The molecules in your body begin burning with intense pain!",
	"$N bends over in pain as $S molecules burn!",
	"You feel a painful burn in your skin as you use your powers on yourself.",
	"$n looks silly as $e uses $s own mental powers to agitate $s molecules.",
	"$N&n's &+lbody &+rbursts in&+Rto flame!",
        "!Agitation!",
        SCHOOL_EVOCATION,
        MANA_AIR
        , TRUE
    },

    {
        "aura sight",           { L_APP },
        &spl_aura_sight,                   70,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "&+lYour eyes revert to their normal colour.",
        SCHOOL_DIVINATION,
        MANA_FIRE
        , TRUE
    },

    {
        "awe",                  { L_APP },
        &spl_awe,                   80,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Awe!",
        SCHOOL_PHANTASM,
        MANA_WATER
        , TRUE
    },

    {
        "ballistic attack",     { L_APP },
        &spl_ballistic_attack,                   5,     12,
	"You chuckle as a stone strikes $N&n.",
	"$n&n creates a rock and strikes you with it!",
	"$n&n concentrates and creates a rock which then strikes $N solidly.",
	"You use the awesome powers of your mind to create a rock, then use those same powers to hit yourself with it.",
	"$n uses his incredible mental powers to create a rock, then uses those powers to hit himself with it.",
	"$N's head caves in.",
        "!Ballistic Attack!",
        SCHOOL_EVOCATION,
        MANA_AIR
        , TRUE
    },

    {
        "biofeedback",          { L_APP },
        &spl_biofeedback,                   75,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "Your biofeedback is no longer effective.",
        SCHOOL_ALTERATION,
        MANA_WATER
        , TRUE
    },

    {
        "cell adjustment",      { L_APP },
        &spl_cell_adjustment,                   60,     12,
        "", 
	"",
	"",
	"",
	"",
	"",
        "!Cell Adjustment!",
        SCHOOL_ALTERATION,
        MANA_EARTH
        , TRUE
    },

    {
        "combat mind",          { L_APP },
        &spl_combat_mind,                   15,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "&+wYour battle sense has faded.&n",
	SCHOOL_EVOCATION | SCHOOL_SUMMONING,
        MANA_EARTH
        , TRUE
    },

    {
        "complete healing",     { L_APP },
        &spl_complete_healing,                   100,    12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Complete Healing!",
	SCHOOL_NECROMANCY,
        MANA_EARTH
        , TRUE
    },

    {
        "control flames",       { L_APP },
        &spl_control_flames,                   15,     12,
        "tongue of flame",
	"",
	"",
	"",
	"",
	"",
        "!Control Flames!",
        SCHOOL_EVOCATION,
        MANA_FIRE
        , TRUE
    },

    {
        "create sound",         { L_APP },
        &spl_create_sound,                   65,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Create Sound!",
        SCHOOL_PHANTASM,
        MANA_AIR
        , TRUE
    },

    {
        "deathfield",          { L_APP },
        &spl_deathfield,                   150,    18,
        "&+LYou send out a wave of psionic death!&n",
	"$n&n &+Lsends out a wave of psionic death, engulfing YOU!&n",
	"$n&n &+Lsends out a wave of psionic death, engulfing $N&n!&n",
	"Your deathfield nearly tears your brain out of your head.",
	"",
	"",
        "!Death Field!",
        SCHOOL_EVOCATION | SCHOOL_NECROMANCY,
        MANA_FIRE
        , TRUE
    },

    {
        "detonate",             { L_APP },
        &spl_detonate,                   75,     20,
        "Tiny &+rexplo&+ysions&n wrack $N&n's body.",
	"Tiny explosions from $n&N wrack your body.",
	"Tiny explosions from $n&N wrack $N&N's body.",
	"You detonate yourself.",
	"",
	"",
        "!Detonate!",
        SCHOOL_EVOCATION,
        MANA_FIRE
        , TRUE
    },

    {
        "neural fragmentation", { L_APP },
        &spl_neurofrag,                   105,     18,
        "$N&n convulses wildly as tiny &+rexplosions&n wrack $N&n's &+Mbrain&n.",
	"You convulse wildly as tiny &+rexplosions&n from $n&N wrack your &+Mbrain&n.",
	"$N&n convulses wildly.",
	"You neurofrag yourself.",
	"",
	"",
        "!Neural Fragmentation!",
        SCHOOL_EVOCATION,
        MANA_FIRE,
        TRUE
    },

    {
        "disintegrate",         { L_APP },
        &spl_disintegrate,      150,    18,
	"&+GYou disintegrate $N&n!",
	"$n&n&+G disintegrates you!&n",
	"$n&n&+G disintegrates &n$N&n!",
	"&+GYou disintegrate yourself.&n",
	"",
	"",
        "!Disintegrate!",
        SCHOOL_EVOCATION | SCHOOL_NECROMANCY,
        MANA_FIRE
        , TRUE
    },

    {
        "displacement",         { L_APP },
        &spl_displacement,                   100,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You are no longer displaced.",
        SCHOOL_ALTERATION,
        MANA_AIR
        , TRUE
    },

    {
        "domination",           { L_APP },
        &spl_domination,        150,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You regain control of your body.",
	SCHOOL_ENCHANTMENT | SCHOOL_CHARM,
        MANA_ANY
        , TRUE
    },

    {
        "ectoplasmic form",     { L_APP },
        &spl_ectoplasmic_form,                   110,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You feel solid again.",
	SCHOOL_ALTERATION,
        MANA_AIR
        , TRUE
    },

    {
        "ego whip",             { L_APP },
        &spl_ego_whip,                   8,     10,
	"You pelt $N&n's ego.",
	"",
	"",
	"",
	"",
	"",
        "!Ego Whip!",
        SCHOOL_PHANTASM,
        MANA_WATER
        , TRUE
    },

    {
        "energy containment",   { L_APP },
        &spl_energy_containment,                           40,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You no longer absorb energy.",
        SCHOOL_ALTERATION,
        MANA_EARTH
        , TRUE
    },

    {
        "enhance armor",        { L_APP },
        &spl_enhance_armor,                   130,    24,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Enhance Armor!",
	SCHOOL_ENCHANTMENT,
        MANA_FIRE
        , TRUE
    },

    {
        "enhanced strength",    { L_APP },
        &spl_enhanced_strength,                           30,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You no longer feel so HUGE.",
	SCHOOL_ALTERATION,
        MANA_EARTH
        , TRUE
    },

    {
        "flesh armor",          { L_APP },
        &spl_flesh_armor,                   75,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "Your skin returns to normal.",
	SCHOOL_ALTERATION,
        MANA_EARTH
        , TRUE
    },

    {
        "inertial barrier",     { L_APP },
        &spl_inertial_barrier,                   150,     24,
        "",
	"",
	"",
	"",
	"",
	"",
        "Your inertial barrier dissipates.",
        SCHOOL_CONJURATION,
        MANA_AIR
        , TRUE
    },

    {
        "inflict pain",         { L_APP },
        &spl_inflict_pain,                   35,     12,
	"$N&n &+Bscreams out in &+Rpain&+B!&n",
	"OUCH!  That really HURT!",
	"$N&n grabs $S head and screams out in pain!",
	"",
	"",
	"",
        "!Inflict Pain!",
	SCHOOL_EVOCATION,
        MANA_FIRE
        , TRUE
    },

    {
        "intellect fortress",   { L_APP },
        &spl_intellect_fortress,                           50,     24,
         "", 
	"",
	"",
	"",
	"",
	"",
        "Your intellectual fortress crumbles.",
        SCHOOL_EVOCATION,
        MANA_ANY
        , TRUE
    },

    {
        "lend health",          { L_APP },
        &spl_lend_health,                   40,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Lend Health!",
        SCHOOL_NECROMANCY,
        MANA_EARTH
        , TRUE
    },

    {
        "transfer wellness",    { L_APP },
        &spl_transfer_wellness,                   10,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Transfer Wellness!",
        SCHOOL_SPIRITUAL,
        MANA_EARTH,
        TRUE
    },

    {
        "levitation",           { L_APP },
        &spl_levitation,        25,     18,
        "",
	"",
	"",
	"",
	"",
	"",
        "You slowly float to the ground.",
        SCHOOL_ALTERATION,
        MANA_AIR
        , TRUE
    },

    {
        "mental barrier",       { L_APP },
        &spl_mental_barrier,                   100,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "Your mental barrier breaks down.",
	SCHOOL_CONJURATION,
        MANA_EARTH
        , TRUE
    },

    {
        "mind thrust",          { L_APP },
        &spl_mind_thrust,                  25,     12,
        "Your thrust pain into $N&n's mind.",
	"You feel pain in your skull!",
	"$N&n shutters for a moment.",
	"",
	"",
	"&+l$N&+l's body falls to the ground twitching...",
        "!Mind Thrust!",
        SCHOOL_PHANTASM,
        MANA_WATER
        , TRUE
    },

    {
        "project force",        { L_APP },
        &spl_project_force,                   35,     12,
        "Your projected force hits $N&n.",
	"You are hit by projected force!",
	"$N&n staggers a bit.",
	"",
	"",
	"&+l$N&+l's body makes strange snapping noises and collapses.",
        "!Project Force!",
        SCHOOL_EVOCATION,
        MANA_EARTH,
        TRUE
    },

    {
        "psionic blast",        { L_APP },
        &spl_psionic_blast,                   45,     9,
        "&+MYour psionic blast hits $N&n.",
	"&+WYou are hit by a psionic blast!&n",
	"&+W$N&+W winces in pain.&n",
	"",
	"",
	"&+l$N&+l falls over motionless.",
        "!Psionic Blast!",
        SCHOOL_EVOCATION,
        MANA_FIRE,
        TRUE
    },

    {
        "psychic crush",        { L_APP },
        &spl_psychic_crush,                   15,     18,
        "psychic crush",
	"",
	"",
	"",
	"",
	"",
        "!Psychic Crush!",
        SCHOOL_EVOCATION,
        MANA_EARTH
        , TRUE
    },

    {
        "mana drain",           { L_APP },
        &spl_psychic_drain,                   50,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You no longer feel drained.",
	SCHOOL_NECROMANCY,
        MANA_FIRE
        , TRUE
    },

    {
        "psychic healing",      { L_APP },
        &spl_psychic_healing,                   20,      12,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Psychic Healing!",
	SCHOOL_NECROMANCY,
        MANA_EARTH
        , TRUE
    },

    {
        "share strength",       { L_APP },
        &spl_share_strength,                   30,     12,
        "",
	"",
	"",
	"",
	"",
	"",
        "You no longer share strength with another.",
	SCHOOL_CONJURATION,
        MANA_EARTH
        , TRUE
    },

    {
        "thought shield",       { L_APP },
        &spl_thought_shield,                   15,     14,
        "",
	"",
	"",
	"",
	"",
	"",
        "You no longer feel so protected.",
	SCHOOL_CONJURATION,
        MANA_ANY
        , TRUE
    },

    {
        "ultrablast",           { L_APP },
        &spl_ultrablast,                   75,     24,
        "Your ultrablast hits $N&n.",
	"$n&n makes you feel very icky.",
	"",
	"",
	"",
	"",
        "!Ultrablast!",
        SCHOOL_EVOCATION,
        MANA_FIRE
        , TRUE
    },

    {
        "meteor swarm",		{ L_APP },
        &spl_meteor,		20,       12,
        "Your &+yswarm of &+rmeteors&n pulverizes $N&n.",
	"$n conjurers a &+yswarm of &+rmeteors&n to pulverize you!",
	"&+rMeteors&n fall from the sky, pulverizing $N&n.",
	"You pummel yourself with meteors.",
	"$n&n is struck by $s own meteors!",
        "$N&n is pounded forcefully into the ground.",
	"!Meteor Swarm!",
        SCHOOL_EVOCATION,
        MANA_AIR
        , TRUE
    },

    {   
	"chain lightning",	{ L_APP },
	&spl_chain_lightning,			25,	12,
	"Your &+Blightning bolt&n hits $N, sending violent spasms through $s body.",
	"$n&n's &+Blightning bolt&n slams into you!",
	"$n&n hits $N&n with a &+Blightning bolt&n!",
	"You zap yourself.",
	"$n&n zaps $mself with lightning!",
	"$N&n is burnt to a crisp.",
	"!Chain Lightning!",
	SCHOOL_EVOCATION,
	MANA_FIRE
        , TRUE
    }, 

    {
	"wizard eye",		{ L_APP },
	&spl_wizard_eye,			40,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Wizard Eye!",
	SCHOOL_DIVINATION,
	MANA_AIR
        , TRUE
    },
    
    {
	"relocate",		{ L_APP },
	&spl_vortex_lift,			60,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Relocate!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

    {
	"shadow walk",		{ L_APP },
	&spl_shadow_walk,			60,	21,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Shadow Walk!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },
    
    {
	"dimension door",	{ L_APP },
	&spl_dimdoor,			60,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Dimension Door!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

    {
	"migration",		{ L_APP },
	&spl_migration,			60,	17,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Migration!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

    {
	"shadow door",	{ L_APP },
	&spl_shadow_door,			60,	16,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Shadow Door!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

    {
	"shadow veil",		{ L_APP },
	&spl_shadow_veil,			60,	11,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Shadow Veil!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR,
        TRUE
    },

    {
	"spirit jump",		{ L_APP },
	&spl_spirit_jump,			60,	18,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Spirit Jump!",
	SCHOOL_SPIRITUAL,
	MANA_AIR,
        TRUE
    },
    
    {
	"mass vortex lift",	{ L_APP },
	&spl_mass_vortex_lift,	150,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Mass Vortex Lift!",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR
        , TRUE
    },

    {
	"detect good",		{ L_APP },
	&spl_detect_good,	5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"The gold in your vision disappears.",
	SCHOOL_DIVINATION,
	MANA_FIRE
        , TRUE
    },

    {
	"dispel good",		{ L_APP },
	&spl_dispel_good,			15,	12,
	"&+WYou fire a bolt of pure energy into $N&N&+W's soul.&N",
	"$n&N &+Wfires a bolt of pure energy into your soul.&N",
	"$n&N &+Wfires a bolt of pure energy into $N&N&+W's soul.&N",
	"&+WYou try to purge yourself of goodness.&N",
	"$n&N &+Wtries to purge $s body of goodness.&N",
	"The good in $N&n's soul has moved on to a higher plane.",
	"!Dispel Good!",
	SCHOOL_ABJURATION,
	MANA_FIRE
        , TRUE
    },

    {
	"holy word",		{ L_APP },
	&spl_holy_word,		15,	7,
	"&+WYou send $N &+Wreeling with your holy word.&N",
	"$n&+W sends you reeling with a holy word of power.&N",
	"$n&+W's holy word sends $N&+W reeling.&N",
	"&+rYou are engulfed in a pillar of flame!&N",
	"$n&+r is engulfed in a pillar of flame!&N",
	"$N&n's soul has moved on to a lower plane.",
	"!Holy Word!",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"unholy word",		{ L_APP },
	&spl_unholy_word,	15,	7,
	"&+rYou send $N&+r reeling with your unholy word.&N",
	"$n&+r sends you reeling with an unholy word of power.&N",
	"$n&+r's unholy word sends $N&+r reeling.&N",
	"&+rYou are engulfed in a pillar of flame!&N",
	"$n&+r is engulfed in a pillar of flame!&N",
	"$N&n's soul has moved on to a higher plane.",
	"!Unholy Word!",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"judgement",		{ L_APP },
	&spl_judgement,			15,	18,
	"&+W$N&+W has been judged by your god.&N",
	"&+W$n&+W brings down the wrath of $s god upon you.&N",
	"&+W$n&+W's god judges $N&+W unworthy.&N",
	"&+rYou are engulfed in a pillar of flame!&N",
	"$n&+r is engulfed in a pillar of flame!&N",
	"$N&n's soul is unworthy and has been destroyed.",
	"!Holy Word!",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"apocalypse",		{ L_APP },
	&spl_apocalypse,			15,	18,
	"&+rYou call the four horsemen of the apocalypse down on $N&n.&N",
	"$n&+r brings down the forces of destruction, plague, and pestilence upon you!&N",
	"$n&+r brings down the forces of destruction upon $N&.&N",
	"&+rYou are engulfed in a pillar of flame!&N",
	"$n&+r is engulfed in a pillar of flame!&N",
	"$N&n's soul has been smashed to small bits.",
	"!Unholy Word!",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
	"power word lag",	{ L_APP },
	&spl_power_word_lag,			15,	6,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Power Word Lag!",
	SCHOOL_ABJURATION,
	MANA_EARTH,
        TRUE
    },

    {
	"power word stun",	{ L_APP },
	&spl_power_word_stun,			15,	8,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Power Word Stun!",
	SCHOOL_ABJURATION,
	MANA_EARTH,
        TRUE
    },

    {
        "etherportal",          { L_APP },
        &spl_etherportal,                   100,     30,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Etherportal!",
        SCHOOL_SPIRITUAL,
        MANA_AIR,
        TRUE
    },

    {
        "moonwell",             { L_APP },
        &spl_moonwell,                   100,     30,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Moonwell!",
        SCHOOL_CONJURATION | SCHOOL_ENCHANTMENT,
        MANA_AIR,
        TRUE
    },

    {
        "wormhole",             { L_APP },
        &spl_wormhole,                   250,   36,
        "",
	"",
	"",
	"",
	"",
	"",
        "!Nexus!",
        SCHOOL_CONJURATION | SCHOOL_ENCHANTMENT,
        MANA_AIR
        , TRUE
    },

    {
	"create buffet",	{ L_APP },
	&spl_create_buffet,			33,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"!Create Buffet!",
	SCHOOL_CONJURATION,
	MANA_EARTH
        , TRUE
    },

    {
	"fireshield",		{ L_APP },
	&spl_flame_shield,	100,	24,
	"$N&n shrieks in &+Rpain&n as $e hits your &+rfireshield&n.",
	"&+rYou get &+Rburned&n as you strike $n&n's &+rfireshield&n.",
        "$n&n's &+rfireshield&n flares as $N&n strikes $m.",
	"&+rYour &+rfireshield&n hits you.&n",
	"",
        "",
	"The flaming shield around you dies out.",
	SCHOOL_EVOCATION | SCHOOL_ALTERATION,
	MANA_FIRE
        , TRUE
    },

    {
	"fireskin",		{ L_APP },
	&spl_fireskin,			100,	18,
        "",
        "",
        "",
        "",
        "",
	"",
	"",
	SCHOOL_EVOCATION | SCHOOL_ALTERATION,
	MANA_FIRE,
        TRUE
    },

    {
	"coldshield",		{ L_APP },
	&spl_frost_shield,	100,	24,
	"Your frost shield retaliates against $N&n.",
	"You shiver from the unnatural cold as you hit $n&n.",
	"$N&n shivers from the unnatural cold as $e hits $N&n.",
	"Your frost shield hits you.",
	"",
	"",
	"The frost shield around you melts and evaporates into nothingness.",
	SCHOOL_EVOCATION | SCHOOL_ALTERATION,
	MANA_WATER
        , TRUE
    },

    {
	"shockshield",		{ L_APP },
	&spl_shock_shield,	100,	60,
	"Your shock shield retaliates against $N&n.",
	"You are zapped as you hit $n&n.",
	"$N&n is zapped as $e hits $N&n.",
	"Your shock shield hits you.",
	"",
	"",
	"The torrents of cascading energy suddenly fade away.",
	SCHOOL_EVOCATION | SCHOOL_ALTERATION,
	MANA_AIR
        , TRUE
    },

    {
	"soulshield",		{ L_APP },
	&spl_soulshield,	100,	12,
	"Your aura retaliates against $N&n.",
	"You grimace in pain as you hit $n&n.",
	"$N&n grimaces in pain as $e hits $n&n.",
	"Your soulshield hits you.",
	"",
	"",
	"Your holy aura suddenly fades away.",
	SCHOOL_ALTERATION,
	MANA_AIR,
        TRUE
    },

    {
	"ethereal shield",	{ L_APP },
	&spl_ethereal_shield,			50,	60,
	"",
	"",
	"",
	"",
	"",
	"",
	"You are returned to the mundane energy continuum.",
	SCHOOL_ALTERATION,
	MANA_FIRE
        , TRUE
    },

    {
	"dust blast",		{ L_APP },
	&spl_dust_blast,	20, 12,
	"&+yYou create a blast of dust and dirt that tears into &n$N&n.",
	"$n&+y conjures a blast of dust and dirt that tears your &+rflesh.&n",
	"&+yWith a gesture &n$n&+y creates a blast of dust engulfing &n$N&n.",
	"&+yYou foolishly blast yourself with dirt and dust, how stupid!&n",
	"$n&n &+yblasts $mself with dust and dirt, what an idiot!",
	"$n&n &+ytears $N&n to shreds, ending $S life instantly.",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
	TRUE
    },

    {
	"slow poison",		{ L_APP },
	&spl_slow_poison,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel more susceptible to the effects of poison.",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
        TRUE
    },

    {
	"ice bolt",		{ L_APP }, 
	&spl_ice_bolt,		20,	12,
	"&+CYou blast $N&+C with your &+Wice bolt&N.",
	"$n&+C hurls an &+Wice bolt&n&+C straight into your chest!&n",
	"$n &+Cblasts $N&+C with a magical spear of &+Wice.&N",
	"&+CYou blast yourself with your own &+Wice bolt!&N",
	"$n &+Clooks bewildered while blasting $mself with a &+W bolt of ice.&N",
	"$N &+Cdies an icy death, shredded by &n$n's &+Wice bolt.&N",
	"",
	SCHOOL_EVOCATION,
	MANA_AIR,
	TRUE
    },
    
    {
	"fire bolt",		{ L_APP }, 
	&spl_fire_bolt,		20,	12,
	"&+rYou conjure a glowing bolt of fire and hurl it at &n$N.&n",
	"$n &+rconjures a bolt of fire and hurls it at YOU!&n",
	"$N &+rgrimaces when struck by a fire bolt thrown by &n$n.&n",
	"&+rYou feel pretty damn stupid as you burn yourself.&n",
	"$n &+rgrimaces as $e burns $mself with a bolt of fire.&n",
	"$n &+rcackles as $e&+r turns $N&+r into an &+Lextra crispy corpse.&N",
	"",
	SCHOOL_EVOCATION,
	MANA_FIRE,
        TRUE
    },
    
    {
	"acid spray",		{ L_APP }, 
	&spl_acid_spray,			20,	12,
	"&+bYou cackle insanely as you spray &+Gacid&N&+b all over &n$N!&n",
	"&+bYou scream when &n$n&+b sprays you with &+Gacid.&n",
	"$N &+bscreams as &n$n&+b sprays $M with &+Gacid.&n",
	"&+bYou curse yourself as &+Gacid&N&+b sprays into your face.&n",
	"$n &+bbegins cursing as $e sprays $mself with &+Gacid.&n",
	"$n &+bcackles as $e dissolves &n$N&+b with &+Gacid.&n",
	"",
	SCHOOL_EVOCATION,
	MANA_WATER,
	TRUE
    },
    
    {
	"pebble",		{ L_APP }, 
	&spl_pebble,		20,	14,
	"&+yYour magical &+Lpebble&+y smashes into &n$N.&n",
	"&+yYou gasp as a &+Lpebble&n&+y conjured by &n$n&+y hits you.&n",
	"$N &+ygasps as &n$n&+y hits him with a magic &+Lpebble.&N",
	"&+yYou stagger from the force of your own spell!&n",
	"$n &+ystaggers as $e is hit by $s own &+Lpebble.&n",
	"$n &+ylaughs as $e crushes the life out of &n$N&+y with a simple &+Lpebble.&n",
	"",
	SCHOOL_CONJURATION,
	MANA_EARTH,
	TRUE
    },
    
    {
	"cutting breeze",		{ L_APP }, 
	&spl_cutting_breeze,	20,	14,
	"&+WYou tear at &n$N&+W with a blast of &N&+cicy air.&n",
	"$n &+Wcreates a blast of icy air that tears your flesh.&n",
	"$N &+Wwails in pain as &n$n&+W blasts $M with &N&+cicy air.&n",
	"&+WYou tear apart your very own flesh with a blast of &N&+cicy air.&N",
	"$n &+Wspins on $s feet as $e is torn apart by $s own &n&+ccutting breeze.&n",
	"$n &+Wshreds &n$N&+W to bits, killing $M with an &+cicy breeze.&n",
	"",
	SCHOOL_CONJURATION,
	MANA_AIR,
	TRUE
    },
    
    {
	"minor blending",		{ L_APP }, 
	&spl_m_blending,		20,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"You no longer blend into the background.",
	SCHOOL_ALTERATION,
	MANA_AIR,
	TRUE
    },

    {
	"chameleons cantrip",	{ L_APP }, 
	&spl_concealment,	20,	10,
	"",
	"",
	"",
	"",
	"",
	"",
	"You appear.",
	SCHOOL_ALTERATION,
	MANA_AIR,
	TRUE
    },
    
    {
	"concealment",		{ L_APP }, 
	&spl_concealment,	20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You appear.",
	SCHOOL_ALTERATION,
	MANA_AIR,
	TRUE
    },

    {
	"aura",		{ L_APP }, 
	&spl_aura,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your vision returns to normal.",
	SCHOOL_DIVINATION,
	MANA_AIR
	, TRUE
    },
    
    {
    	"dirt cloud",		{ L_APP }, 
	&spl_dirt_cloud,	20,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"&+LYour vision returns.&N",
	SCHOOL_CONJURATION,
	MANA_EARTH
	, TRUE
    },
    
    {
	"spark",		{ L_APP }, 
	&spl_spark,		20,	14,
	"&+rYou blast &n$N&+r with flaming sparks.&N",
	"$n &+rscorches you with flaming sparks.&n",
	"$n &+rtries to set fire to &n$N&+r with flaming sparks.&n",
	"&+rYou attempt to set fire to yourself with your sparks.&N",
	"$n &+rtries to set fire to $mself with some flaming sparks.&n",
	"$n cackles as $N bursts into &+rflames&N and dies.&n",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
	TRUE
    },
    
    {
	"water bolt",		{ L_APP }, 
	&spl_water_bolt,	20,	12,
	"&+BYou blast &n$N&+B with a bolt of pure water.&N",
	"&+BA bolt of pure water sent by &n$n&+B slams into you.&n",
	"$n &+Btries to drown &n$N&+B with a bolt of water.&n",
	"&+bYou try to drown yourself with a bolt of water.&N",
	"$n &+btries to drown $mself with a bolt of water.&n",
	"$n &+Bdrowns &n$N&+B to death with a bolt of water.&n",
	"&+BThe world about you isn't as slippery anymore.&n",
	SCHOOL_CONJURATION,
	MANA_WATER,
	TRUE
    },

    {
	"water blast",		{ L_APP }, 
	&spl_water_blast,	20,	13,
	"&+BYou blast &n$N&+B with a powerful bolt of pure water.&N",
	"&+BA powerful blast of pure water sent by &n$n&+B slams into you, knocking the wind from your lungs&n",
	"$N&+B chokes as &n$n&+B tries to drown $M with a large blast of water.&n",
	"&+bYou try to drown yourself with a blast of water.&N",
	"$n &+btries to drown $mself with a blast of water.&n",
	"$n&+B's &+Bdrowns &n$N&+B with a blast of water.&n",
	"&+BThe world about you isn't as slippery anymore.&n",
	SCHOOL_CONJURATION,
	MANA_WATER,
	TRUE
    },
    
    {
	"earthen smith",	{ L_APP },
	&spl_earthen_smith,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_EARTH,
    	TRUE
    },
    
    {
	"fiery smith",	{ L_APP },
	&spl_fiery_smith,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },
    
    {
	"airy smith",	{ L_APP },
	&spl_airy_smith,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_AIR,
    	TRUE
    },
    
    {
	"aquatic smith",	{ L_APP },
	&spl_aquatic_smith,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_WATER,
        TRUE
    },
    
    {
	"hover",		{ L_APP },
	&spl_hover,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You slowly return to the earth.",
	SCHOOL_ALTERATION,
	MANA_EARTH,
    	TRUE
    },
    
    {
	"azure flame",		{ L_APP }, 
	&spl_azure_flame,			20,	12,
	"&+rYou fire a bolt of &+Bblue&n&+r flame at &n$N.&n",
	"&+rYou are slammed by a bolt of &n&+Bblue&n&+r fire sent by &n$n.&n",
	"$n &+rattempts to turn &n$N&+L to ash&n&+r with an &+Bazure&n&+r flame.&n",
	"&+rYou attempt to turn yourself to ash with your &+Bazure&N flame.&N",
	"$n &+rlooks pretty stupid as $e blasts $mself with fire.&n",
	"$n laughs as $N is turned to &+Lash.&n",
	"",
	SCHOOL_CONJURATION,
	MANA_FIRE,
	TRUE
    },
    
    {
	"gust of frost",		{ L_APP }, 
	&spl_gust_of_frost,			20,	12,
	"You send an icy blast of &+Wfrost&n at $N.&n",
	"$n tries to &+cfreeze&n you with a blast of &+Wfrost.&n",
	"$n tries to &+cfreeze&n $N with a blast of &+Wfrost.&n",
	"You freeze your fingers with a blast of &+Wfrost.&n",
	"$n looks pretty stupid as $e is engulfed in a cloud of &+Wfrost.&n",
	"$n laughs as $N is &+Cfrozen solid.&n",
	"",
	SCHOOL_CONJURATION,
	MANA_AIR,
	TRUE
    },
    
    {
    	"tide of the seas",	{ L_APP },
    	&spl_tide_seas,			20, 12,
    	"Your &+bwater blast&N pounds $N&n.",
	"$n conjures a blast of &+bwater&n to pound you!",
	"&+bWater blasts&n through the room, pounding $N&n.",
	"You drown yourself with water",
	"$n&n is engulfed by $s own &+bwater blast!&n",
    	"$N&n is drowned by the water rushing through the room.",
	"",
    	SCHOOL_CONJURATION,
    	MANA_WATER,
    	TRUE
    },
    
    {
	"blending",		{ L_APP },
	&spl_blending,		20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your magic camouflage fades.",
	SCHOOL_ILLUSION,
	MANA_AIR,
        TRUE
    },

    {
        "dismissal",           { L_APP },
        &spl_dismissal,                   20,     12,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_SUMMONING,
        MANA_EARTH,
        TRUE
    },


    {
	"summon elemental",		{ L_APP },
	&spl_summon_elemental,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_SUMMONING,
	MANA_EARTH,
        TRUE
    },


    {
	"summon fire serpent",		{ L_APP },
	&spl_summon_serpent,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_SUMMONING,
	MANA_EARTH,
        TRUE
    },


    {
	"summon nerneid",		{ L_APP },
	&spl_summon_nerneid,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_SUMMONING,
	MANA_EARTH,
        TRUE
    },


    {
	"summon pech",		{ L_APP },
	&spl_summon_pech,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_SUMMONING,
	MANA_EARTH,
        TRUE
    },


    {
	"summon slyph",		{ L_APP },
	&spl_summon_slyph,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_SUMMONING,
	MANA_EARTH,
        TRUE
    },


    {
	"summon greater elemental",		{ L_APP },
	&spl_summon_gr_elem,			20,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_SUMMONING,
	MANA_EARTH,
        TRUE
    },


    {
	"aid",		{ L_APP },
	&spl_aid,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"You feel less righteous.",
	SCHOOL_CONJURATION | SCHOOL_SUMMONING,
	MANA_AIR
        , TRUE
    },

    {
        "holy sacrifice",           { L_APP },
        &spl_holy_sacrifice,        100,    12,
        "",
        "",
        "",
        "",
        "",
        "",
        "The energy surrounding you fades and dissipates.",
        SCHOOL_ALTERATION,
        MANA_AIR,
        TRUE
    },

    {
        "battle ecstasy",           { L_APP },
        &spl_battle_ecstasy,        100,    12,
        "",
        "",
        "",
        "",
        "",
        "",
        "Your senses seem dulled as your ecstasy fades.",
        SCHOOL_ALTERATION,
        MANA_AIR,
        TRUE
    },

    {
        "mermaids kiss",           { L_APP },
        &spl_mermaids_kiss,        100,    12,
        "",
        "",
        "",
        "",
        "",
        "",
	"You are no longer so well-adapted to other environments.",
	SCHOOL_ABJURATION,
	MANA_FIRE,
        TRUE
    },

    {
        "detect undead",           { L_APP },
        &spl_detect_undead,        5,    		12,
        "",
        "",
        "",
        "",
        "",
        "",
	"Your vision seems brighter.",
	SCHOOL_DIVINATION,
	MANA_FIRE,
        TRUE
    },

    {
	"trap-sleep",		{ L_APP },
	&trp_sleep,		0,	1,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ILLUSION,
	MANA_AIR,
        FALSE
    },

    {
        "trap-fire",            { L_APP },
        &trp_fire,              0,     1,
        "You smirk as your &+rfi&+Rre&+Yba&+Rll&n explodes in $N&n's face.",
        "$n&n blasts you with a &+rfi&+Rre&+Yba&+Rll&n!  Ouch!",
        "$n&n smirks as $s &+rfi&+Rre&+Yba&+Rll&n explodes in $N&n's face.",
        "You blast yourself with a &+rfi&+Rre&+Yba&+Rll&n, melting the flesh from your bones.",
        "$n&n blasts $mself with a &+rfi&+Rre&+Yba&+Rll&n, melting the flesh from $s bones.",
        "The fireball from $n&n turns $N&n into a smoldering ash heap!",
        "",
        SCHOOL_EVOCATION,
        MANA_FIRE,
        FALSE
    },

    {
        "trap-cold",	        { L_APP },
        &trp_cold,		0,     1,
        "Your &+Ccone of cold&n &+bfreezes&n $N&n.",
        "$n&+b hits you with a &+Ccone of cold&n!",
        "$n&+b hits &n$N&+b with a &+Ccone of cold&n!",
        "&+bYou &+Cfreeze&+b yourself&n.",
        "$n&n blasts $mself with a cone of cold.",
        "$N&+W falls to the ground, covered in icicles.&n",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-acid",	        { L_APP },
        &trp_acid,		0,     1,
	"&+bYou cackle insanely as you spray &+Gacid&N&+b all over &n$N!&n",
	"&+bYou scream when &n$n&+b sprays you with &+Gacid.&n",
	"$N &+bscreams as &n$n&+b sprays $M with &+Gacid.&n",
	"&+bYou curse yourself as &+Gacid&N&+b sprays into your face.&n",
	"$n &+bbegins cursing as $e sprays $mself with &+Gacid.&n",
	"$n &+bcackles as $e dissolves &n$N&+b with &+Gacid.&n",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-bash",	        { L_APP },
        &trp_bash,		0,     1,
        "Your &+Ylig&+Whtn&+Ying&N bolt&n hits $N&n, sending violent spasms through $S body.",
        "$n&n's &+Ylig&+Whtn&+Ying bolt&n slams into you!",
        "$n&n hits $N&n with a &+Ylig&+Whtn&+Ying bolt&n!",
        "You lightning bolt yourself like the fool that you are.",
        "$n&n shoots $mself in the arse with a bolt of lightning.",
        "$N&n crumples to the ground in a sizzling, blackened heap.",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-energy",	        { L_APP },
        &trp_energy,		0,     1,
        "Your &+Ylig&+Whtn&+Ying&N bolt&n hits $N&n, sending violent spasms through $S body.",
        "$n&n's &+Ylig&+Whtn&+Ying bolt&n slams into you!",
        "$n&n hits $N&n with a &+Ylig&+Whtn&+Ying bolt&n!",
        "You lightning bolt yourself like the fool that you are.",
        "$n&n shoots $mself in the arse with a bolt of lightning.",
        "$N&n crumples to the ground in a sizzling, blackened heap.",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-harm",	        { L_APP },
        &trp_harm,		0,     1,
        "Your &+Ylig&+Whtn&+Ying&N bolt&n hits $N&n, sending violent spasms through $S body.",
        "$n&n's &+Ylig&+Whtn&+Ying bolt&n slams into you!",
        "$n&n hits $N&n with a &+Ylig&+Whtn&+Ying bolt&n!",
        "You lightning bolt yourself like the fool that you are.",
        "$n&n shoots $mself in the arse with a bolt of lightning.",
        "$N&n crumples to the ground in a sizzling, blackened heap.",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-pierce",	        { L_APP },
        &trp_pierce,		0,     1,
        "Your &+Ylig&+Whtn&+Ying&N bolt&n hits $N&n, sending violent spasms through $S body.",
        "$n&n's &+Ylig&+Whtn&+Ying bolt&n slams into you!",
        "$n&n hits $N&n with a &+Ylig&+Whtn&+Ying bolt&n!",
        "You lightning bolt yourself like the fool that you are.",
        "$n&n shoots $mself in the arse with a bolt of lightning.",
        "$N&n crumples to the ground in a sizzling, blackened heap.",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-slash",	        { L_APP },
        &trp_slash,		0,     1,
        "Your &+Ylig&+Whtn&+Ying&N bolt&n hits $N&n, sending violent spasms through $S body.",
        "$n&n's &+Ylig&+Whtn&+Ying bolt&n slams into you!",
        "$n&n hits $N&n with a &+Ylig&+Whtn&+Ying bolt&n!",
        "You lightning bolt yourself like the fool that you are.",
        "$n&n shoots $mself in the arse with a bolt of lightning.",
        "$N&n crumples to the ground in a sizzling, blackened heap.",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },


    {
        "trap-poison",	        { L_APP },
        &trp_poison,		0,     1,
	"You smirk as $N&n writhes in agony from the poison.",
	"You feel a burning sensation in your blood.",
	"$n&n has poisoned $N&n!",
	"Your poison coarses through your veins.",
	"",
	"You feel the poison in your body dissipate.",
	"",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-para",	        { L_APP },
        &trp_para,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-disease",	        { L_APP },
        &trp_disease,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-gate",	        { L_APP },
        &trp_gate,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-summon",	        { L_APP },
        &trp_summon,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-stun",	        { L_APP },
        &trp_stun,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-dispel",	        { L_APP },
        &trp_dispel,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-teleport",        { L_APP },
        &trp_teleport,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
        "trap-wither",        	{ L_APP },
        &trp_wither,		0,     1,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        SCHOOL_EVOCATION,
        MANA_WATER,
        TRUE
    },

    {
	"sense followers",		{ L_APP },
	&spl_sense_followers,			15,	0,
	"",
	"",
	"",
	"",
	"",
	"",
	"Your no longer sense your followers.",
	SCHOOL_ENCHANTMENT | SCHOOL_ALTERATION,
	MANA_ANY
        , TRUE
    },

    {
	"hellfire",	{ L_APP },
	&spl_hellfire,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },
    
    {
	"embalm",	{ L_APP },
	&spl_embalm,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },

    {
	"alacrity",	{ L_APP },
	&spl_alacrity,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },
    
    {
	"choke",	{ L_APP },
	&spl_choke,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },

    {
	"aging",	{ L_APP },
	&spl_aging,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },

    {
	"vitalize mana",	{ L_APP },
	&spl_vitalize_mana,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },

    {
	"shadow breath 2",	{ L_APP },
	&spl_shadow_breath2,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },
    
    {
	"protection from undead",	{ L_APP },
	&spl_prot_from_undead,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },

    {
	"vampiric touch",	{ L_APP },
	&spl_vampiric_touch,			50,	24,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_ENCHANTMENT,
	MANA_FIRE,
	TRUE
    },
    
};

struct	song_type	songs_table	[MAX_SONG]	=
{

    {
	"song of reserved",	{ L_APP },		"reserved",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HARP,
	MANA_INSTR_AUGMENT,
      TRUE
    },

    {
	"song of armor",	{ L_APP },		"armor",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HORN,
	MANA_INSTR_AUGMENT,
      TRUE
    },

    {
	"song of sleep",	{ L_APP },              "sleep",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_FLUTE,
	MANA_INSTR_AUGMENT,
      TRUE
    },

    {
	"song of corruption",	{ L_APP },              "corruption",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DRUMS,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of purity",	{ L_APP },              "purity",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DRUMS,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of feasting",	{ L_APP },              "feasting",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DRUMS,
	MANA_INSTR_AUGMENT,
      TRUE
    },

    {
	"song of obscurement",	{ L_APP },              "obscurement",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_MANDOLIN,
	MANA_INSTR_AUGMENT,
      TRUE
    },

    {
	"song of calming",	{ L_APP },              "calming",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HARP,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of warding",	{ L_APP },              "warding",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HORN,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of forgetfulness",	{ L_APP },      "forgetfulness",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_MANDOLIN,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of susceptibility",	{ L_APP }, "susceptibility",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_FLUTE,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of cowardice",	{ L_APP },              "cowardice",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DRUMS,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of revelation",	{ L_APP },              "revelation",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_MANDOLIN,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of slowness",	{ L_APP },              "slowness",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_MANDOLIN,
	MANA_INSTR_AUGMENT,
      TRUE
    },

    {
	"song of quagmire",	{ L_APP },              "quagmire",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_MANDOLIN,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of babble",	{ L_APP },              "babble",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HORN,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of dragons",	{ L_APP },              "dragons",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HORN,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of clumsiness",	{ L_APP },              "clumsiness",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_LYRE,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of weakling",	{ L_APP },              "weakling",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_LYRE,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of harming",	{ L_APP },              "harming",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_LYRE,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of healing",	{ L_APP },              "healing",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_LYRE,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of invisibility",	{ L_APP },              "invisibility",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_FLUTE,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of heroism",	{ L_APP },              "heroism",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DRUMS,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of nightmares",	{ L_APP },              "nightmares",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DRUMS,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of the skylark",	{ L_APP },              "skylark",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HORN,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of chaos",	{ L_APP },              "chaos",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_DRUMS,
	MANA_INSTR_AUGMENT,
      TRUE
    },

    {
	"song of idiocy",	{ L_APP },              "idiocy",
 	NULL,			5,	12,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	SCHOOL_HARP,
	MANA_INSTR_AUGMENT,
        TRUE
    },

    {
	"song of flight",	{ L_APP },              "flight",
	NULL,			15,	14,
	"",
	"",
	"",
	"",
	"",
	"",
	"Shoulders tingling, you float gently to the ground.",
	SCHOOL_HORN,
	MANA_INSTRUMENT,
        TRUE
    },


};

const             char *          lang_table      [MAX_LANG]    =
{
    "unknown",    /* 0  */
    "common",     /* 1  */
    "elven",      /* 2  */
    "dwarven",    /* 3  */
    "centaur",    /* 4  */
    "ogre",       /* 5  */
    "orcish",     /* 6  */
    "troll",      /* 7  */
    "aquatic elf",/* 8  */
    "saurial",    /* 9  */
    "thri-kreen", /* 10 */
    "unused",     /* 11 */
    "dragon",     /* 12 */
    "unused" ,    /* 13 */
    "magical",    /* 14 */
    "goblin",     /* 15 */
    "god",        /* 16 */
    "halfling",   /* 17 */
    "githyanki",  /* 18 */
    "drow",       /* 19 */
    "kobold",     /* 20 */
    "gnome",      /* 21 */
    "animal",     /* 22 */
    "duergar",    /* 23 */
    "githzerai",  /* 24 */
    "flind",      /* 25 */
    "rakshasa",   /* 26 */
    "minotaur",   /* 27 */
    "gnoll",      /* 28 */
    "barbarian"   /* 29 */
};

#if !defined( ultrix ) && !defined( apollo )
#include <memory.h>
#endif

#if defined(KEY)
#undef KEY
#endif

#define KEY( literal, field, value )                \
                if ( !str_cmp( word, literal ) )    \
                {                                   \
                    field  = value;                 \
                    fMatch = TRUE;                  \
                    break;                          \
                }

#define SKEY( string, field )                       \
                if ( !str_cmp( word, string ) )     \
                {                                   \
                    free_string( field );           \
                  field = fread_string( fp, &stat); \
                    fMatch = TRUE;                  \
                    break;                          \
                }


/* Class table.  See class files in the 'classes' directory */
struct  class_type *    class_table     [ MAX_CLASS ];

/*
 * New code for loading classes from file.
 */
bool fread_class( char *filename )
{
    FILE               *fp;
    char               *word;
    struct  class_type *c_class;
    char                buf [ MAX_STRING_LENGTH ];
    bool                fMatch;
    int                 stat;
    int                 number = -1;

    //sprintf( buf, "Loading class: %s", filename );
    //log_string( buf );

    sprintf( buf, "%s%s", CLASS_DIR, filename );
    if ( !( fp = fopen( buf, "r" ) ) )
    {
        perror( buf );
        return FALSE;
    }

    c_class = alloc_mem ( sizeof( CLASS_TYPE ) );

    for ( ; ; )
    {
	word   = feof( fp ) ? "End" : fread_word( fp, &stat );
	fMatch = FALSE;

	switch ( UPPER( word[0] ) )
	{
	case '*':
	    fMatch = TRUE;
	    fread_to_eol( fp );
	    break;

	case 'A':
            KEY( "AtrPrm", c_class->attr_prime, fread_number( fp, &stat ) );
	    break;

	case 'C':
            KEY( "Cla", number, fread_number( fp, &stat ) );

	    if ( number < 0 || number >= MAX_CLASS )
	    {
		sprintf( buf, "Fread_class: bad class  '%s'.", filename );
		bug ( buf, 0 );
		return FALSE;
	    }
	    break;

	case 'E':
	    if ( !str_cmp( word, "End" ) )
	    {
		fclose( fp );
		class_table[number] = c_class;
		return TRUE;
	    }
	    break;

	case 'H':
            KEY( "Hpmin", c_class->hp_min, fread_number( fp, &stat ) );
            KEY( "Hpmax", c_class->hp_max, fread_number( fp, &stat ) );
	    break;

	case 'M':
            KEY( "Mana", c_class->fMana, fread_number( fp, &stat ) );
	    break;

	case 'N':
            SKEY( "Nm", c_class->name );
	    break;

	case 'S':
            KEY( "SkllAdpt", c_class->skill_adept, fread_number( fp, &stat ) );

	    if ( !str_cmp( word, "Skll" ) )
	    {
		int sn;
		int value;
                char *word;

		value = fread_number( fp, &stat );
		sn    = skill_lookup( (word = fread_word( fp, &stat )) );
		if ( sn < 0 )
                {
                    sprintf( buf, "Fread_class - unknown skill: %s", word );
                    bug( buf, 0 );
                }
		else
		    skills_table[sn].skill_level[number] = value;
		fMatch = TRUE;
	    }
	    else if ( !str_cmp( word, "Spll" ) )
	    {
		int sn;
		int value;
                char *word;

		value = fread_number( fp, &stat );
		sn    = spell_lookup( (word = fread_word( fp, &stat )) );
		if ( sn < 0 )
                {
                    sprintf( buf, "Fread_class - unknown spell: %s", word );
                    bug( buf, 0 );
                }
		else
                {
                    if( value <= MAX_CIRCLE && value > 0 )
                    {
		      spells_table[sn].spell_circle[number] = value;
                    }
                    else
                    {
                      bug( "Spell in class file has level greater than MAX_CIRCLE", 0 );
                      spells_table[sn].spell_circle[number] = MAX_CIRCLE+2;
                    }
                }
		fMatch = TRUE;
	    }
	    else if ( !str_cmp( word, "Song" ) )
	    {
		int sn;
		int value;
                char *word;

		value = fread_number( fp, &stat );
		sn    = song_lookup( (word = fread_word( fp, &stat )) );
		if ( sn < 0 )
                {
                    sprintf( buf, "Fread_class - unknown song: %s", word );
                    bug( buf, 0 );
                }
		else
                {
                    if( value < MAX_LEVEL )
                    {
		      songs_table[sn].spell_circle[number] = value;
                    }
                    else
                    {
                      bug( "Song in class file has level greater than MAX_LEVEL", 0 );
                      songs_table[sn].spell_circle[number] = MAX_LEVEL;
                    }
                }
		fMatch = TRUE;
	    }

	    break;

	case 'T':
	    KEY( "Thac0", c_class->thac0_00, fread_number( fp, &stat ) );
	    KEY( "Thac47", c_class->thac0_47, fread_number( fp, &stat ) );
	    break;

	case 'W':
	    SKEY( "WhoNm", c_class->who_name );
	    KEY( "Wpn", c_class->weapon, fread_number( fp, &stat ) );
	    break;
	}

	if ( !fMatch )
	{
            bugf( "load_class_file: no match: %s", word );
	}
    }

    return FALSE;
}

/*
 * Load in all the class files.
 */ 
void load_classes( void )
{
    FILE *fpList;
    char *filename;
    char  fname     [ MAX_STRING_LENGTH ];
    char  classlist [ MAX_STRING_LENGTH ];
    int   stat;
    
    sprintf( classlist, "%s%s", CLASS_DIR, CLASS_LIST );
    if ( !( fpList = fopen( classlist, "r" ) ) )
    {
        perror( classlist );
        return;
    }

    for ( ; ; )
    {
        filename = feof( fpList ) ? "$" : fread_word( fpList, &stat );
	    strcpy( fname, filename );
        if ( fname[0] == '$' )
          break;

        if ( !fread_class( fname ) )
        {
          bugf( "Cannot load class file: %s", fname );
        }
    }
    fclose( fpList );

    return;
}


const char * size_string( int size )
{
    switch( size )
    {
      default:
        return "unknown-invalid";
        break;
      case SIZE_ANY:
        return "any";
        break;
      case SIZE_TINY:
        return "tiny";
        break;
      case SIZE_SMALL:
        return "small";
        break;
      case SIZE_PETITE:
        return "small";
        break;
      case SIZE_BIG:
        return "medium";
        break;
      case SIZE_MEDIUM:
        return "medium";
        break;
      case SIZE_LARGE:
        return "large";
        break;
      case SIZE_HUGE:
        return "huge";
        break;
      case SIZE_GIANT:
        return "giant";
        break;
      case SIZE_TITANIC:
        return "titanic";
        break;
      case SIZE_GARGANTUAN:
        return "gargantuan";
        break;
      case SIZE_NONE:
        return "none";
        break;
     }
}
