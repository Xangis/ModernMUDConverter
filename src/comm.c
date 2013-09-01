
#if   defined( WIN32 )
char version_str [] = "Basternae/Magma to ModernMUD Area Converter Windows 32 Bit Version";
// Needed so we can use Sleep();
#include "Windows.h"
#endif

#include <sys/types.h>
#include <sys/timeb.h> /*for _ftime(), uses _timeb struct*/
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include "merc.h"

#if defined( unix ) || defined( AmigaTCP ) || defined( WIN32 )
#include <signal.h>
#endif

FILE *		    fpReserve;		/* Reserved file handle		*/
bool		    merc_down;		/* Shutdown                     */
bool		    wizlock;		/* Game is wizlocked		*/
int                 numlock = 0;        /* Game is numlocked at <level> */
char		    str_boot_time [ MAX_INPUT_LENGTH ];
time_t		    current_time;	/* Time of this pulse		*/

#if defined( unix ) || defined( AmigaTCP ) || defined( WIN32 )
void	game_loop_unix		args( ( ) );
#endif

int main( int argc, char **argv )
{
#if defined( unix ) || defined( AmigaTCP ) || defined( WIN32 )
#endif

    /*
     * Reserve one channel for our use.
     */
    if ( !( fpReserve = fopen( NULL_FILE, "r" ) ) )
    {
		perror( NULL_FILE );
		getchar();
		exit( 1 );
    }

#if defined( unix ) || defined( AmigaTCP ) || defined( WIN32 )
    boot_db( );
    sprintf( log_buf, "The Magma Mud database has loaded successfully." );
    log_string( log_buf );
    game_loop_unix( );
#endif
    log_string( "Areas have been converted.  Close application now." );
    while(1);

    /*
     * That's all, folks.
     */
    log_string( "Normal termination of program." );
	getchar();
    exit( 0 );
    return 0;
}

char *strrepl(char *orgstr, char *oldstr, char *newstr)
{
    char xbuf [ MAX_STRING_LENGTH * 8 ];
    char org2 [MAX_STRING_LENGTH * 8 ];
    int i;
    char* loc;

    strcpy( org2, orgstr );

    xbuf[0] = '\0';
    strcpy( xbuf, org2 );
    loc = strstr( org2, oldstr );
    while ( loc != NULL )
    {
        i = strlen( org2 ) - strlen( strstr( org2, oldstr ) );
        xbuf[i] = '\0';
        strcat( xbuf, newstr );
        strcat( xbuf, &org2[i+strlen( oldstr )] );
        strcpy( org2, xbuf );
        loc = strstr( org2, oldstr );
    }

    return str_dup( xbuf );
}

const char* GetApplyName( int number )
{
    switch( number )
    {
    case 0:
        return "none";
        break;
    case 1:
        return "strength";
        break;
    case 2:
        return "dexterity";
        break;
    case 3:
        return "intelligence";
        break;
    case 4:
        return "wisdom";
        break;
    case 5:
        return "constitution";
        break;
    case 6:
        // No mod-sex affects allowed.
        return "none";
        break;
    case 7:
        // No mod-char-class affects allowed.
        return "none";
        break;
    case 8:
        // No mod-level affects allowed.
        return "none";
        break;
    case 9:
        return "age";
        break;
    case 10:
        return "weight";
        break;
    case 11:
        return "height";
        break;
    case 12:
        return "mana";
        break;
    case 13:
        return "hitpoints";
        break;
    case 14:
        return "move";
        break;
    case 15:
        // No gold affects allowed.
        return "none";
        break;
    case 16:
        // No experience affects allowed.
        return "none";
        break;
    case 17:
        return "ac";
        break;
    case 18:
        return "hitroll";
        break;
    case 19:
        return "damroll";
        break;
    case 20:
        return "save_paralysis";
        break;
    case 21:
        return "save_poison";
        break;
    case 22:
        return "save_petrification";
        break;
    case 23:
        return "save_breath";
        break;
    case 24:
        return "save_spell";
        break;
    case 25:
        return "fire_protection";
        break;
    case 26:
        return "agility";
        break;
    case 27:
        return "power";
        break;
    case 28:
        return "charisma";
        break;
    case 30:
        return "luck";
        break;
    case 31:
        return "max_strength";
        break;
    case 32:
        return "max_dexterity";
        break;
    case 33:
        return "max_intelligence";
        break;
    case 34:
        return "max_wisdom";
        break;
    case 35:
        return "max_constitution";
        break;
    case 36:
        return "max_agility";
        break;
    case 37:
        return "max_power";
        break;
    case 38:
        return "max_charisma";
        break;
    case 40:
        return "max_luck";
        break;
    case 41:
        return "race_strength";
        break;
    case 42:
        return "race_dexterity";
        break;
    case 43:
        return "race_intelligence";
        break;
    case 44:
        return "race_wisdom";
        break;
    case 45:
        return "race_constitution";
        break;
    case 46:
        return "race_agility";
        break;
    case 47:
        return "race_power";
        break;
    case 48:
        return "race_charisma";
        break;
    case 50:
        return "race_luck";
        break;
    case 51:
        return "curse";
        break;
    default:
        log_string("Unrecognized affect modifier location ignored: " );
        return "none";
        break;
    }
}

int ConvertRaceNumber( int number )
{
	if( number < 20 )
	return number;

	switch( number )
	{
	case 20:
		return 28;
	case 21:
		return 22;
	case 22:
		return 21;
	case 23:
		return 24;
	case 24:
		return 25;
	case 25:
		return 26;
	case 26:
		return 27;
	case 27:
		return 29;
	case 28:
		return 20;
	case 29:
		return 30;
	case 30:
		return 32;
	case 31:
		return 33;
	case 32:
		return 34;
	case 33:
		return 35;
	case 34:
		return 36;
	case 35:
		return 37;
	case 36:
		return 38;
	case 37:
		return 39;
	case 38:
		return 40;
	case 39:
		return 41;
	case 40:
		return 42;
	case 41:
		return 44;
	case 42:
		return 45;
	case 43:
		return 46;
	case 44:
		return 63;
	case 45:
		return 64;
	case 46:
		return 65;
	case 47:
		return 66;
	case 48:
		return 67;
	case 49:
		return 68;
	case 50:
		return 69;
	case 51:
		return 47;
	case 52:
		return 48;
	case 53:
		return 49;
	case 54:
		return 70;
	case 55:
		return 50;
	case 56:
		return 51;
	case 57:
		return 52;
	case 58:
		return 53;
	case 59:
		return 54;
	case 60:
		return 71;
	case 61:
		return 72;
	case 62:
		return 73;
	case 63:
		return 74;
	case 64:
		return 75;
	case 65:
		return 55;
	case 66:
		return 76;
	case 67:
		return 56;
	case 68:
		return 57;
	case 69:
		return 77;
	case 70:
		return 78;
	case 71:
		return 79;
	case 72:
		return 58;
	case 73:
		return 59;
	case 74:
		return 60;
	case 75:
		return 61;
	}

	return number;
}

char *QuestTypeString(int type)
{
	switch(type)
	{
	case 0:
		return "item";
	case 1:
		return "money";
	case 2:
		return "skill";
	case 3:
		return "experience";
    case 4:
		return "spell";
    case 5:
		return "spellcast";
    case 6:
		return "transfermobs";
    case 7:
		return "createmob";
    case 8:
		return "createpet";
    case 9:
		return "transferplayer";
    case 10:
		return "transfergroup";
    case 11:
		return "song";
    case 12:
		return "faction";
	}
	return "none";
}

char *GetTerrainType(int type)
{
	switch(type)
	{
	case SECT_INSIDE:
		return "inside";
	case SECT_CITY:
		return "city";
	case SECT_FIELD:
		return "field";
	case SECT_FOREST:
		return "forest";
	case SECT_HILLS:
		return "hills";
	case SECT_MOUNTAIN:
		return "mountain";
	case SECT_DESERT:
		return "desert";
	case SECT_ARCTIC:
		return "arctic";
	case SECT_SWAMP:
		return "swamp";
	case SECT_WATER_SWIM:
		return "swimmable_water";
	case SECT_WATER_NOSWIM:
		return "unswimmable_water";
	case SECT_AIR:
		return "air";
	case SECT_UNDERWATER:
		return "underwater_no_ground";
	case SECT_UNDERWATER_GROUND:
		return "underwater_has_ground";
	case SECT_OCEAN:
		return "ocean";
	case SECT_ROAD:
		return "road";
	case SECT_PLANE_FIRE:
		return "plane_of_fire";
	case SECT_UNDERG_WILD:
		return "underground_wild";
	case SECT_UNDERG_CITY:
		return "underground_city";
	case SECT_UNDERG_INSIDE:
		return "underground_indoors";
	case SECT_UNDERG_WATER:
		return "underground_swimmable_water";
	case SECT_UNDERG_WATER_NOSWIM:
		return "underground_unswimmable_water";
	case SECT_UNDERG_NOGROUND:
		return "underground_no_ground";
	case SECT_PLANE_AIR:
		return "plane_of_air";
	case SECT_PLANE_WATER:
		return "plane_of_water";
	case SECT_PLANE_EARTH:
		return "plane_of_earth";
	case SECT_PLANE_ETHEREAL:
		return "plane_ethereal";
	case SECT_PLANE_ASTRAL:
		return "plane_astral";
	case SECT_UNDERG_IMPASSABLE:
		return "undergound_impassable";
	case SECT_UNDERG_OCEAN:
		return "underground_ocean";
	default:
		bug( "Unrecognized terrain type %d.", type );
		return "none";
	}
}

char *GetItemType(int type)
{
	switch(type)
	{
	case TYPE_LIGHT:
		return "light";
	case TYPE_SCROLL:
		return "scroll";
	case TYPE_WAND:
		return "wand";
	case TYPE_STAFF:
		return "staff";
	case TYPE_WEAPON:
		return "weapon";
	case TYPE_RANGED_WEAPON:
		return "ranged_weapon";
	case TYPE_MISSILEWEAP:
		return "missile_weapon";
	case TYPE_TREASURE:
		return "treasure";
	case TYPE_ARMOR:
		return "armor";
	case TYPE_POTION:
		return "potion";
	case TYPE_CLOTHING:
		return "clothing";
	case 23:
	case TYPE_OTHER:
		return "other";
	case TYPE_TRASH:
		return "trash";
	case TYPE_TRAP:
		return "trap";
	case TYPE_CONTAINER:
		return "container";
	case TYPE_NOTE:
		return "note";
	case TYPE_DRINK_CON:
		return "drink_container";
	case TYPE_KEY:
		return "key";
	case TYPE_FOOD:
		return "food";
	case TYPE_MONEY:
		return "money";
	case TYPE_PEN:
		return "pen";
	case TYPE_BOAT:
		return "boat";
	case TYPE_BATTERY:
		return "battery";
	case TYPE_TELEPORT:
		return "teleport";
	case TYPE_TIMER:
		return "timer";
	case TYPE_VEHICLE:
		return "vehicle";
	case TYPE_SHIP:
		return "ship";
	case TYPE_SWITCH:
		return "switch_trigger";
	case TYPE_QUIVER:
		return "quiver";
	case TYPE_LOCKPICK:
		return "lockpick";
	case TYPE_INSTRUMENT:
		return "instrument";
	case TYPE_SPELLBOOK:
		return "spellbook";
	case TYPE_TOTEM:
		return "totem";
	case TYPE_STORAGECHEST:
		return "storage_chest";
	case TYPE_SCABBARD:
		return "scabbard";
	case TYPE_SHIELD:
		return "shield";
	case TYPE_CORPSE_NPC:
		return "npc_corpse";
	case TYPE_CORPSE_PC:
		return "pc_corpse";
	case TYPE_PORTAL:
		return "portal";
	case TYPE_PILL:
		return "pill";
	case TYPE_HERB:
		return "herb";
	case TYPE_MESSAGE_BOARD:
		return "message_board";
	case TYPE_PIPE:
		return "pipe";
	case TYPE_WANTED_LIST:
		return "wanted_list";
	case TYPE_WALL:
		return "wall";
	case TYPE_AMMO:
		return "ammunition";
	case TYPE_ROPE:
		return "rope";
	default:
		bug( "Unrecognized item type %d.", type );
		return "none";
	}
}

char *GetMaterialName(int type)
{
	switch( type )
	{
	case 0:
		return "undefined";
	case 1:
		return "nonsubstantial";
	case 2:
		return "flesh";
	case 3:
		return "cloth";
	case 4:
		return "bark";
	case 5:
		return "softwood";
	case 6:
		return "hardwood";
	case 7:
		return "glass";
	case 8:
		return "crystal";
	case 9:
		return "ceramic";
	case 10:
		return "bone";
	case 11:
		return "stone";
	case 12:
		return "hide";
	case 13:
		return "leather";
	case 14:
		return "cured_leather";
	case 15:
		return "iron";
	case 16:
		return "steel";
	case 17:
		return "brass";
	case 18:
		return "mithril";
	case 19:
		return "adamantium";
	case 20:
		return "bronze";
	case 21:
		return "copper";
	case 22:
		return "silver";
	case 23:
		return "electrum";
	case 24:
		return "gold";
	case 25:
		return "platinum";
	case 26:
		return "gem";
	case 27:
		return "diamond";
	case 28:
		return "paper";
	case 29:
		return "parchment";
	case 30:
		return "leaves";
	case 31:
		return "ruby";
	case 32:
		return "emerald";
	case 33:
		return "sapphire";
	case 34:
		return "ivory";
	case 35:
		return "dragonscale";
	case 36:
		return "obsidian";
	case 37:
		return "granite";
	case 38:
		return "marble";
	case 39:
		return "limestone";
	case 40:
		return "liquid";
	case 41:
		return "bamboo";
	case 42:
		return "reeds";
	case 43:
		return "hemp";
	case 44:
		return "glassteel";
	case 45:
		return "eggshell";
	case 46:
		return "chitinous";
	case 47:
		return "reptilescale";
	case 48:
		return "generic_food";
	case 49:
		return "rubber";
	case 50:
		return "feather";
	case 51:
		return "wax";
	case 52:
		return "pearl";
	case 53:
		return "silk";
	case 54:
		return "spidersilk";
	case 55:
		return "jade";
	case 56:
		return "lead";
	default:
		bug( "Unrecognized material type %d.", type );
		return "none";
	}
}

char *GetCraftsmanship(int type)
{
	switch(type)
	{
	case CRAFT_TERRIBLE:
		return "terrible";
	case CRAFT_EXT_POOR:
		return "extremely_poor";
	case CRAFT_VERY_POOR:
		return "very_poor";
	case CRAFT_FAIRLY_POOR:
		return "fairly_poor";
	case CRAFT_WELL_BELOW_AVE:
		return "well_below_average";
	case CRAFT_BELOW_AVE:
		return "below_average";
	case CRAFT_SLIGHT_BELOW_AVE:
		return "slightly_below_average";
	case CRAFT_AVERAGE:
		return "average";
	case CRAFT_SLIGHT_ABOVE_AVE:
		return "slightly_above_average";
	case CRAFT_ABOVE_AVE:
		return "above_average";
	case CRAFT_WELL_ABOVE_AVE:
		return "well_above_average";
	case CRAFT_EXCELLENT:
		return "excellent";
	case CRAFT_SKILLED_ARTISAN:
		return "skilled_artisan";
	case CRAFT_GIFTED_ARTISAN:
		return "gifted_artisan";
	case CRAFT_MASTER_ARTISAN:
		return "master_artisan";
	case CRAFT_ONEOFAKIND:
		return "one_of_a_kind";
	default:
		bug( "Unrecognized craftsmanship %d.", type );
		return "average";
	}
}

char* PositionString(int type)
{
	switch(type)
	{
	case POS_DEAD:
		return "dead";
	case POS_MORTAL:
		return "mortally_wounded";
	case POS_INCAP:
		return "incapacitated";
	case POS_UNCONSCIOUS:
		return "unconscious";
	case POS_STUNNED:
		return "stunned";
	case POS_SLEEPING:
		return "sleeping";
	case POS_RECLINING:
		return "reclining";
	case POS_RESTING:
		return "resting";
	case POS_SITTING:
		return "sitting";
	case POS_KNEELING:
		return "kneeling";
	case POS_FIGHTING:
		return "fighting";
	case POS_STANDING:
		return "standing";
	default:
		bug( "Unrecognized position %d.", type );
		return "standing";
	}
}

char *GetExitFlags(int type)
{
	switch( type )
	{
	case 0:
		return "none";
	case EX_ISDOOR:
		return "is_door";
	case EX_ISDOOR|EX_CLOSED:
		return "is_door closed";
	case EX_CLOSED:
		return "closed";
	case EX_ISDOOR|EX_LOCKED:
		return "is_door locked";
	case EX_ISDOOR|EX_LOCKED|EX_SECRET|EX_CLOSED:
		return "is_door locked closed secret";
	case EX_ISDOOR|EX_CLOSED|EX_SECRET:
		return "is_door closed secret";
    case EX_ISDOOR|EX_SECRET:
        return "is_door secret";
    case EX_ISDOOR|EX_BLOCKED:
        return "is_door blocked";
	case EX_ISDOOR|EX_CLOSED|EX_LOCKED:
		return "is_door closed locked";
	case EX_ISDOOR|EX_CLOSED|EX_LOCKED|EX_BASHPROOF|EX_PICKPROOF:
		return "is_door closed locked bashproof pickproof";
	case EX_LOCKED:
		return "locked";
        break;
    case EX_CLOSED|EX_ISDOOR|EX_SECRET|EX_BLOCKED:
        return "is_door closed secret blocked";
        break;
    case EX_CLOSED|EX_ISDOOR|EX_LOCKED|EX_BASHPROOF|EX_PICKPROOF|EX_SECRET:
        return "is_door closed locked secret bashproof pickproof";
        break;
    case EX_CLOSED|EX_ISDOOR|EX_LOCKED|EX_BASHPROOF|EX_PICKPROOF|EX_SECRET|EX_BLOCKED:
        return "is_door closed locked secret bashproof pickproof blocked";
        break;
	default:
		bug( "Bad exit flags %d.", type );
	}
	return "none";
}

// Removes all ANSI codes.  Used for keyword cleanup.
char *RemoveANSICodes(char *encstr)
{
    if( encstr == NULL )
        return NULL;

    encstr = strrepl(encstr, "&n", "");
    encstr = strrepl(encstr, "&N", "");
    encstr = strrepl(encstr, "&+r", "");
    encstr = strrepl(encstr, "&+y", "");
    encstr = strrepl(encstr, "&+g", "");
    encstr = strrepl(encstr, "&+m", "");
    encstr = strrepl(encstr, "&+w", "");
    encstr = strrepl(encstr, "&+b", "");
    encstr = strrepl(encstr, "&+c", "");
    encstr = strrepl(encstr, "&+l", "");
    encstr = strrepl(encstr, "&+R", "");
    encstr = strrepl(encstr, "&+Y", "");
    encstr = strrepl(encstr, "&+G", "");
    encstr = strrepl(encstr, "&+M", "");
    encstr = strrepl(encstr, "&+W", "");
    encstr = strrepl(encstr, "&+B", "");
    encstr = strrepl(encstr, "&+C", "");
    encstr = strrepl(encstr, "&+L", "");

    return encstr;
}

char *XMLEncodeString(char *encstr)
{
    if( encstr == NULL )
        return "";
    // Careful -- we can't replace & with &amp; recursively because it results in an
    // infinite expansion.
    encstr = strrepl(encstr, "&n", "&amp;n");
    encstr = strrepl(encstr, "&N", "&amp;N");
    encstr = strrepl(encstr, "&+", "&amp;+");
    encstr = strrepl(encstr, "&-", "&amp;-");
    encstr = strrepl(encstr, "& ", "&amp;+");
    encstr = strrepl(encstr, "<", "&lt;");
    encstr = strrepl(encstr, ">", "&gt;");
    encstr = strrepl(encstr, "\r", "" );
    encstr = strrepl(encstr, "\n", " " );
    // Two shots with the space replacer should work well.
    encstr = strrepl(encstr, "  ", " " );
    encstr = strrepl(encstr, "  ", " " );
    return encstr;
}

#if defined( unix ) || defined( AmigaTCP ) || defined( WIN32 )
void game_loop_unix(  )
{
    /* Main loop */
    AREA_DATA *area;
    FILE *fp;
    char filename[1024];
    RESET_DATA *reset;
    ROOM_INDEX_DATA *room;
    OBJ_INDEX_DATA *obj;
    SHOP_DATA *shop;
    MOB_INDEX_DATA *mob;
    QUEST_INDEX_DATA *quest;
    int count;
    int hash;
    AFFECT_DATA * aff = NULL;
	for( area = area_first; area; area = area->next )
    {
        sprintf( filename, "%s%s.xml", AREA_DIR, area->filename );
        log_string( "Saving area: " );
        log_string( filename );
        if( !(fp = fopen( filename, "w" ) ))
        {
            break;
        }
        fprintf( fp, "<?xml version=\"1.0\"?>\n" );
        fprintf( fp, "<Area xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">\n" );
		fprintf( fp, "<Repops>\n");
		fprintf( fp, "</Repops>\n");
		fprintf( fp, "<Resets>\n" );
        for( reset = area->reset_first; reset; reset = reset->next )
        {
            fprintf( fp, "<Reset>\n" );
            fprintf( fp, "<Command>%d</Command>", reset->command );
            fprintf( fp, "<Arg0>%d</Arg0>\n", reset->arg0 );
            fprintf( fp, "<Arg1>%d</Arg1>\n", reset->arg1 );
            fprintf( fp, "<Arg2>%d</Arg2>\n", reset->arg2 );
            fprintf( fp, "<Arg3>%d</Arg3>\n", reset->arg3 );
            fprintf( fp, "<Arg4>%d</Arg4>\n", reset->arg4 );
            fprintf( fp, "<Arg5>%d</Arg5>\n", reset->arg5 );
            fprintf( fp, "<Arg6>%d</Arg6>\n", reset->arg6 );
            fprintf( fp, "<Arg7>%d</Arg7>\n", reset->arg7 );
            fprintf( fp, "</Reset>\n" );
        }
        fprintf( fp, "</Resets>\n" );
        fprintf( fp, "<Rooms>\n");
        for( hash = 0; hash < MAX_KEY_HASH; hash++ )
        {
            for( room = room_index_hash[hash]; room; room = room->next )
            {
                if( room->area != area )
                {
                    continue;
                }
                fprintf( fp, "<RoomTemplate>\n" );
                fprintf( fp, "<Title>%s</Title>\n", XMLEncodeString(room->name) );
                fprintf( fp, "<Description>%s</Description>\n", XMLEncodeString(room->description) );
                fprintf( fp, "<IndexNumber>%d</IndexNumber>\n", room->vnum );
                fprintf( fp, "<Current>%d</Current>\n", room->current );
                fprintf( fp, "<CurrentDirection>%d</CurrentDirection>\n", room->current_dir );
                fprintf( fp, "<FallChance>%d</FallChance>\n", room->fall_chance );
                fprintf( fp, "<TerrainType>%s</TerrainType>\n", GetTerrainType(room->sector_type) );
                fprintf( fp, "<WorldmapTerrainType>%d</WorldmapTerrainType>\n", room->extra_sector_info );
                fprintf( fp, "<CurrentRoomFlags>\n" );
                fprintf( fp, "<int>%d</int>\n", room->room_flags[0] );
                fprintf( fp, "<int>%d</int>\n", room->room_flags[1] );
                fprintf( fp, "</CurrentRoomFlags>\n" );
                fprintf( fp, "<BaseRoomFlags>\n" );
                fprintf( fp, "<int>%d</int>\n",room->room_flags[0] );
                fprintf( fp, "<int>%d</int>\n",room->room_flags[1] );
                fprintf( fp, "</BaseRoomFlags>\n" );
                fprintf( fp, "<ExitData>\n" );
                for( count = 0; count < MAX_DIR; count ++ )
                {
                    if( room->exit[count] == 0 )
                    {
                        fprintf( fp, "<Exit xsi:nil=\"true\" />\n" );
                    }
                    else
                    {
                        fprintf( fp, "<Exit>\n<IndexNumber>%d</IndexNumber>\n", room->exit[count]->vnum );
                        fprintf( fp, "<ExitFlags>%s</ExitFlags>\n", GetExitFlags(room->exit[count]->exit_info ));
                        fprintf( fp, "<Key>%d</Key>\n", room->exit[count]->key );
                        fprintf( fp, "<Keyword>%s</Keyword>\n", RemoveANSICodes( room->exit[count]->keyword ));
                        fprintf( fp, "<Description>%s</Description>\n</Exit>\n", XMLEncodeString(room->exit[count]->description) );
                    }
                }
                fprintf( fp, "</ExitData>\n" );
                fprintf( fp, "</RoomTemplate>\n" );
            }
        }
        fprintf( fp, "</Rooms>\n");
        fprintf( fp, "<Objects>\n");
        for( hash = 0; hash < MAX_KEY_HASH; hash++ )
        {
            for( obj = obj_index_hash[hash]; obj; obj = obj->next )
            {
                if( obj->area != area )
                {
                    continue;
                }
                fprintf( fp, "<ObjTemplate>\n" );
                fprintf( fp, "<Name>%s</Name>\n", XMLEncodeString(obj->name) );
                fprintf( fp, "<ShortDescription>%s</ShortDescription>\n", XMLEncodeString(obj->short_descr) );
                fprintf( fp, "<FullDescription>%s</FullDescription>\n", XMLEncodeString(obj->description) );
                fprintf( fp, "<IndexNumber>%d</IndexNumber>\n", obj->vnum );
                fprintf( fp, "<ItemType>%s</ItemType>\n", GetItemType(obj->item_type) );
                fprintf( fp, "<WearFlags>\n" );
                fprintf( fp, "<int>%d</int>\n", obj->wear_flags );
                fprintf( fp, "</WearFlags>\n" );
                fprintf( fp, "<UseFlags>\n" );
                fprintf( fp, "<int>%d</int>\n", obj->anti_flags );
                fprintf( fp, "<int>%d</int>\n", obj->anti_flags2 );
                fprintf( fp, "</UseFlags>\n" );
                fprintf( fp, "<Material>%s</Material>\n", GetMaterialName(obj->material ));
                fprintf( fp, "<Size>%s</Size>\n", size_string(obj->size) );
                fprintf( fp, "<Volume>%d</Volume>\n", obj->volume );
                fprintf( fp, "<CraftsmanshipLevel>%s</CraftsmanshipLevel>\n", GetCraftsmanship(obj->craftsmanship) );
                fprintf( fp, "<Scarcity>10000</Scarcity>\n" );
                fprintf( fp, "<Weight>%d</Weight>\n", obj->weight );
                fprintf( fp, "<Condition>%d</Condition>\n", obj->condition );
                fprintf( fp, "<MaxNumber>0</MaxNumber>\n" );
                fprintf( fp, "<Level>%d</Level>\n", obj->level );
                fprintf( fp, "<Cost>%d</Cost>\n", obj->cost );
                fprintf( fp, "<ExtraFlags>\n" );
                fprintf( fp, "<int>%d</int>\n", obj->extra_flags[0] );
                fprintf( fp, "<int>%d</int>\n", obj->extra_flags[1] );
                fprintf( fp, "</ExtraFlags>\n" );
                fprintf( fp, "<AffectedBy>\n" );
                for( count = 0; count < 5; count++ )
                {
                    fprintf( fp, "<int>%d</int>\n", obj->affected_by[count] );
                }
                fprintf( fp, "</AffectedBy>\n" );
                fprintf( fp, "<Values>\n" );
                for( count = 0; count < 8; count++ )
                {
                    fprintf( fp, "<int>%d</int>\n", obj->value[count] );
                }
                fprintf( fp, "</Values>\n" );
                // Store Spells
                if( obj->item_type == TYPE_PILL || obj->item_type == TYPE_POTION || obj->item_type == TYPE_SCROLL || obj->item_type == TYPE_HERB )
                {
                    fprintf( fp, "<SpellEffects>\n");
                    if( obj->value[1] > 0 )
                    {
                        fprintf( fp, "<SpellEntry>\n");
                        fprintf( fp, "<Name>%s</Name>\n", spells_table[obj->value[1]].name);
                        fprintf( fp, "<Circle>%d</Circle>\n", 12);
                        fprintf( fp, "</SpellEntry>\n");
                    }
                    if( obj->value[2] > 0 )
                    {
                        fprintf( fp, "<SpellEntry>\n");
                        fprintf( fp, "<Name>%s</Name>\n", spells_table[obj->value[2]].name);
                        fprintf( fp, "<Circle>%d</Circle>\n", 12);
                        fprintf( fp, "</SpellEntry>\n");
                    }
                    if( obj->value[3] > 0 )
                    {
                        fprintf( fp, "<SpellEntry>\n");
                        fprintf( fp, "<Name>%s</Name>\n", spells_table[obj->value[3]].name);
                        fprintf( fp, "<Circle>%d</Circle>\n", 12);
                        fprintf( fp, "</SpellEntry>\n");
                    }
                    if( obj->value[4] > 0 )
                    {
                        fprintf( fp, "<SpellEntry>\n");
                        fprintf( fp, "<Name>%s</Name>\n", spells_table[obj->value[4]].name);
                        fprintf( fp, "<Circle>%d</Circle>\n", 12);
                        fprintf( fp, "</SpellEntry>\n");
                    }
                    fprintf( fp, "</SpellEffects>\n");
                }
                else if( obj->item_type == TYPE_WAND || obj->item_type == TYPE_STAFF )
                {
                    fprintf( fp, "<SpellEffects>\n");
                    if( obj->value[3] > 0 )
                    {
                        fprintf( fp, "<SpellEntry>\n");
                        fprintf( fp, "<Name>%s</Name>\n", spells_table[obj->value[3]].name);
                        fprintf( fp, "<Circle>%d</Circle>\n", 12);
                        fprintf( fp, "</SpellEntry>\n");
                    }
                    fprintf( fp, "</SpellEffects>\n");
                }
                // Here we collapse all affects down into a single affect.  Since we know that object affects can only have modifiers
                // when created in DikuEdit, we can take liberties by only using the info from the first item.
                if( obj->affected != NULL )
                {
                    fprintf( fp, "<Affected>\n" );
                    fprintf( fp, "<Affect>\n<Duration>%d</Duration>\n<Level>%d</Level>\n<Modifiers>\n", obj->affected->duration, obj->affected->level);
                    for( aff = obj->affected; aff != NULL; aff = aff->next )
                    {
                        fprintf( fp, "<AffectApplyType>\n<Location>%s</Location>\n<Amount>%d</Amount>\n</AffectApplyType>\n",
                            GetApplyName(aff->location), aff->modifier );
                    }
                    fprintf( fp, "</Modifiers>\n</Affect>\n</Affected>\n" );
                }
                else
                {
                    fprintf( fp, "<Affected />\n" );
                }
                fprintf( fp, "</ObjTemplate>\n" );
            }
        }
        fprintf( fp, "</Objects>\n");
        fprintf( fp, "<Mobs>\n");
        for( hash = 0; hash < MAX_KEY_HASH; hash++ )
        {
            for( mob = mob_index_hash[hash]; mob; mob = mob->next )
            {
                if( mob->area != area )
                {
                    continue;
                }
                fprintf( fp, "<MobTemplate>\n" );
                fprintf( fp, "<PlayerName>%s</PlayerName>\n", XMLEncodeString(mob->player_name) );
                fprintf( fp, "<ShortDescription>%s</ShortDescription>\n", XMLEncodeString(mob->short_descr) );
                fprintf( fp, "<FullDescription>%s</FullDescription>\n", XMLEncodeString(mob->description) );
                fprintf( fp, "<Description>%s</Description>\n", XMLEncodeString(mob->long_descr) );
                fprintf( fp, "<IndexNumber>%d</IndexNumber>\n", mob->vnum );
                fprintf( fp, "<Level>%d</Level>\n", mob->level );
                fprintf( fp, "<NumberKilled>0</NumberKilled>\n" );
                switch( mob->sex )
                {
                case SEX_NEUTRAL:
                    fprintf( fp, "<Gender>neutral</Gender>\n" );
                    break;
                case SEX_MALE:
                    fprintf( fp, "<Gender>male</Gender>\n" );
                    break;
                case SEX_FEMALE:
                    fprintf( fp, "<Gender>female</Gender>\n" );
                    break;
                }
                fprintf( fp, "<ClassName>none</ClassName>\n" ); // TODO: Fix this.
                fprintf( fp, "<ActionFlags>\n" );
                fprintf( fp, "<int>%d</int>\n", mob->act );
                fprintf( fp, "<int>%d</int>\n", 0 );
                fprintf( fp, "</ActionFlags>\n" );
                fprintf( fp, "<Alignment>%d</Alignment>\n", mob->alignment );
                fprintf( fp, "<Race>%d</Race>\n", ConvertRaceNumber( mob->race ));
                fprintf( fp, "<DefaultPosition>%d</DefaultPosition>\n", mob->position );
                fprintf( fp, "<Resistant>none</Resistant>\n" );
                fprintf( fp, "<Immune>none</Immune>\n" );
                fprintf( fp, "<Susceptible>none</Susceptible>\n" );
                fprintf( fp, "<Vulnerable>none</Vulnerable>\n" );
                fprintf( fp, "<AffectedBy>\n" );
                for( count = 0; count < 5; count++ )
                {
                    fprintf( fp, "<int>%d</int>\n", mob->affected_by[count] );
                }
                fprintf( fp, "</AffectedBy>\n" );
                fprintf( fp, "</MobTemplate>\n" );
            }
        }
        fprintf( fp, "</Mobs>\n");
        fprintf( fp, "<Shops>\n");
        for( shop = shop_first; shop; shop = shop->next )
        {
            if( shop->area != area )
            {
                continue;
            }
            fprintf( fp, "<Shop>\n" );
            fprintf( fp, "<Keeper>%d</Keeper>\n", shop->keeper );
            fprintf( fp, "<OpenHour>%d</OpenHour>\n", shop->open_hour );
            fprintf( fp, "<CloseHour>%d</CloseHour>\n", shop->close_hour );
            fprintf( fp, "<PercentBuy>%d</PercentBuy>\n", shop->profit_buy );
            fprintf( fp, "<PercentSell>%d</PercentSell>\n", shop->profit_sell );
            fprintf( fp, "<BuyTypes>\n" );            
            for( count = 0; count < MAX_BUY; count++ )
            {
                if( shop->buy_type[count] != 0 )
                {
                    fprintf( fp, "<int>%d</int>\n", shop->buy_type[count] );            
                }
            }
            fprintf( fp, "</BuyTypes>\n" );            
            fprintf( fp, "<ItemsForSale>\n" );            
            for( count = 0; count < MAX_SELL; count++ )
            {
                if( shop->sell_item[count] != 0 )
                {
                    fprintf( fp, "<int>%d</int>\n", shop->sell_item[count] );            
                }
            }
            fprintf( fp, "</ItemsForSale>\n" );            
            fprintf( fp, "</Shop>\n" );            
        }
        //
        fprintf( fp, "</Shops>\n");
        fprintf( fp, "<Quests>\n");
        for( quest = quest_first; quest; quest = quest->next )
        {
            QUEST_DATA *qdata;
            TALK_DATA *talk;
            QUEST_ITEM *item;
            if( quest->area != area )
            {
                continue;
            }
            fprintf( fp, "<QuestTemplate>\n" );
            fprintf( fp, "<IndexNumber>%d</IndexNumber>\n", quest->vnum );
            fprintf( fp, "<Quests>\n" );
            for(qdata = quest->quests;qdata;qdata = qdata->next)
            {
                fprintf( fp, "<QuestData>\n" );
                fprintf( fp, "<Disappear>%s</Disappear>\n", XMLEncodeString(qdata->disappear) );
                fprintf( fp, "<Complete>%s</Complete>\n", XMLEncodeString(qdata->complete) );
                fprintf( fp, "<Give>" );
                for( item = qdata->give; item; item = item->next )
                {
                    fprintf( fp, "<QuestItem>\n" );
                    fprintf( fp, "<Type>%s</Type>\n", QuestTypeString(item->type) );
                    fprintf( fp, "<Value>%d</Value>\n", item->value );
                    fprintf( fp, "</QuestItem>\n" );
                }
                fprintf( fp, "</Give>" );
                fprintf( fp, "<Receive>" );
                for( item = qdata->receive; item; item = item->next )
                {
                    fprintf( fp, "<QuestItem>\n" );
                    fprintf( fp, "<Type>%s</Type>\n", QuestTypeString(item->type) );
                    fprintf( fp, "<Value>%d</Value>\n", item->value );
                    fprintf( fp, "</QuestItem>\n" );
                }
                fprintf( fp, "</Receive>" );
                fprintf( fp, "</QuestData>\n" );
            }
            fprintf( fp, "</Quests>\n" );
            fprintf( fp, "<Messages>\n" );
            for(talk = quest->messages;talk;talk = talk->next)
            {
                fprintf( fp, "<TalkData>\n" );
                fprintf( fp, "<Keywords>%s</Keywords>\n", XMLEncodeString(talk->keywords) );
                fprintf( fp, "<Message>%s</Message>\n", XMLEncodeString(talk->message) );
                fprintf( fp, "</TalkData>\n" );
            }
            fprintf( fp, "</Messages>\n");
            fprintf( fp, "</QuestTemplate>\n" );
        }
        fprintf( fp, "</Quests>\n");
        fprintf( fp, "<Version>1</Version>\n" );
        fprintf( fp, "<Name>%s</Name>\n", XMLEncodeString(area->name) );
        fprintf( fp, "<DefenderTemplateNumber>%d</DefenderTemplateNumber>\n", area->defender );
        fprintf( fp, "<DefendersPerSquad>%d</DefendersPerSquad>\n", area->defender_num );
        fprintf( fp, "<DefendersDispatched>%d</DefendersDispatched>\n", area->defender_num );
        fprintf( fp, "<BarracksRoom>%d</BarracksRoom>\n", area->barracks );
        fprintf( fp, "<JudgeRoom>%d</JudgeRoom>\n", area->judge );
        fprintf( fp, "<JailRoom>%d</JailRoom>\n", area->jail );
        fprintf( fp, "<DefenderSquads>%d</DefenderSquads>\n", area->squads );
        fprintf( fp, "<Recall>%d</Recall>\n", area->recall );
        fprintf( fp, "<JusticeType>none</JusticeType>\n", area->justice );
        fprintf( fp, "<Filename>%s</Filename>\n", filename );
        fprintf( fp, "<Builders>%s</Builders>\n", area->builders );
        fprintf( fp, "<Security>%d</Security>\n", area->security );
        fprintf( fp, "<AreaFlags>%d</AreaFlags>\n", area->area_flags );
        fprintf( fp, "<Author>%s</Author>\n", area->author );
        fprintf( fp, "<ResetMessage>%s</ResetMessage>\n", XMLEncodeString(area->resetmsg) );
        if( area->resetmode == 1 )
        {
            fprintf( fp, "<AreaResetMode>empty_of_players</AreaResetMode>\n" );
        }
        else
        {
            fprintf( fp, "<AreaResetMode>normal</AreaResetMode>\n" );
        }
        fprintf( fp, "<GuildId>0</GuildId>\n" );
        fprintf( fp, "<MinutesBetweenResets>%d</MinutesBetweenResets>\n", area->llifespan );
        fprintf( fp, "<MinRecommendedLevel>%d</MinRecommendedLevel>\n", area->llv );
        fprintf( fp, "<MaxRecommendedLevel>%d</MaxRecommendedLevel>\n", area->ulv );
        fprintf( fp, "</Area>\n" );
        fclose(fp);
    }
    return;
}
#endif
