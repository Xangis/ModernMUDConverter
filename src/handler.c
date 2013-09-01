
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merc.h"

/*
 * See if a string is one of the names of an object.
 * New is_name sent in by Alander.
 */
bool is_name( const char *str, char *namelist )
{
    char name [MAX_INPUT_LENGTH * 4];

    for ( ; ; )
    {
	namelist = one_argument( namelist, name );
	if ( name[0] == '\0' )
	    return FALSE;
	if ( !str_cmp( str, name ) )
	    return TRUE;
    }
}

/*
 * Return weight of an object, including weight of contents.
 */
int get_obj_weight( OBJ_DATA *obj )
{
    int weight;

    weight = obj->weight;
    for ( obj = obj->contains; obj; obj = obj->next_content )
    {
	if ( obj->deleted )
	    continue;
	weight += get_obj_weight( obj );
    }

    return weight;
}

void end_of_game( void )
{
    return;
}

int race_lookup( const char *race )
{
    int index;

    for ( index = 0; index < MAX_RACE; index++ )
        if ( !str_prefix( race, race_table[index].name ) )
	    return index;

    return -1;
}

int size_lookup( const char *size )
{
    int index;
    for ( index = 0; index < MAX_SIZE; index++ )
        if ( !str_prefix( size, size_string(index) ) )
	    return index;
    
    return -1;
}

int race_key_lookup( const char *race )
{
    int index;

    for ( index = 0; index < MAX_RACE; index++ )
        if ( !str_cmp( race, race_table[index].key ) )
	    return index;

    return -1;

}

const	int	rev_dir		[ ]		=
{
    2, 3, 0, 1, 5, 4, 9, 8, 7, 6
};

void set_cost( OBJ_INDEX_DATA *obj )
{
        int multiplier;
        int value;

        // find the value multiplier based on what the object is made of
        // expensive materials yield expensive objects
        switch( obj->material )
        {
           default:
              bug( "Unrecognized material type %d.  Setting to default.", obj->material );
              multiplier = 100;
              break;
           case MAT_UNDEFINED:
              multiplier = 100;
              break;
           case MAT_NONSUBSTANTIAL:
              multiplier = 100;
              break;
           case MAT_FLESH:
              multiplier = 30;
              break;
           case MAT_CLOTH:
              multiplier = 60;
              break;
           case MAT_BARK:
              multiplier = 20;
              break;
           case MAT_SOFTWOOD:
              multiplier = 50;
              break;
           case MAT_HARDWOOD:
              multiplier = 70;
              break;
           case MAT_GLASS:
              multiplier = 130;
              break;
           case MAT_CRYSTAL:
              multiplier = 140;
              break;
           case MAT_CERAMIC:
              multiplier = 65;
              break;
           case MAT_BONE:
              multiplier = 35;
              break;
           case MAT_STONE:
              multiplier = 80;
              break;
           case MAT_HIDE:
              multiplier = 60;
              break;
           case MAT_LEATHER:
              multiplier = 80;
              break;
           case MAT_CUREDLEATHER:
              multiplier = 85;
              break;
           case MAT_IRON:
              multiplier = 100;
              break;
           case MAT_STEEL:
              multiplier = 110;
              break;
           case MAT_BRASS:
              multiplier = 95;
              break;
           case MAT_MITHRIL:
              multiplier = 150;
              break;
           case MAT_ADAMANTIUM:
              multiplier = 200;
              break;
           case MAT_BRONZE:
              multiplier = 90;
              break;
           case MAT_COPPER:
              multiplier = 50;
              break;
           case MAT_SILVER:
              multiplier = 100;
              break;
           case MAT_ELECTRUM:
              multiplier = 150;
              break;
           case MAT_GOLD:
              multiplier = 250;
              break;
           case MAT_PLATINUM:
              multiplier = 500;
              break;
           case MAT_GEM:
              multiplier = 750;
              break;
           case MAT_DIAMOND:
              multiplier = 1000;
              break;
           case MAT_PAPER:
              multiplier = 35;
              break;
           case MAT_PARCHMENT:
              multiplier = 25;
              break;
           case MAT_LEAVES:
              multiplier = 20;
              break;
           case MAT_RUBY:
              multiplier = 800;
              break;
           case MAT_EMERALD:
              multiplier = 900;
              break;
           case MAT_SAPPHIRE:
              multiplier = 950;
              break;
           case MAT_IVORY:
              multiplier = 300;
              break;
           case MAT_DRAGONSCALE:
              multiplier = 220;
              break;
           case MAT_OBSIDIAN:
              multiplier = 130;
              break;
           case MAT_GRANITE:
              multiplier = 88;
              break;
           case MAT_MARBLE:
              multiplier = 83;
              break;
           case MAT_LIMESTONE:
              multiplier = 68;
              break;
           case MAT_LIQUID:
              multiplier = 100;
              break;
           case MAT_BAMBOO:
              multiplier = 30;
              break;
           case MAT_REEDS:
              multiplier = 28;
              break;
           case MAT_HEMP:
              multiplier = 42;
              break;
           case MAT_GLASSTEEL:
              multiplier = 125;
              break;
           case MAT_EGGSHELL:
              multiplier = 15;
              break;
           case MAT_CHITINOUS:
              multiplier = 22;
              break;
           case MAT_REPTILESCALE:
              multiplier = 82;
              break;
           case MAT_GENERICFOOD:
              multiplier = 100;
              break;
           case MAT_RUBBER:
              multiplier = 80;
              break;
           case MAT_WAX:
              multiplier = 45;
              break;
           case MAT_FEATHER:
              multiplier = 38;
              break;
           case MAT_PEARL:
              multiplier = 550;
              break;
           case MAT_SILK:
              multiplier = 205;
              break;
           case MAT_SPIDERSILK:
              multiplier = 235;
              break;
           case MAT_JADE:
              multiplier = 920;
              break;
           case MAT_LEAD:
              multiplier = 60;
        }

       if( obj->craftsmanship != 0 )
       {
           multiplier = (obj->craftsmanship * multiplier) / CRAFT_AVERAGE;
       }

       // Value is in copper pieces for base value
       switch( obj->item_type )
       {
           default:
             value = 10;
             break;
           case TYPE_ARMOR:
             value = obj->value[0] * obj->value[0] * 6 + 10;
             break;
           case TYPE_WEAPON:
             value = (obj->value[1] * obj->value[2] * 2) * 50;
             break;
           case TYPE_STAFF:
           case TYPE_SCROLL:
           case TYPE_WAND:
           case TYPE_POTION:
             value = 10000;
             break;
           case TYPE_FOOD:
             value = 20;
             break;
           case TYPE_LIGHT:
             value = 10;
             break;
           case TYPE_DRINK_CON:
             value = 18;
             break;
           case TYPE_PEN:
             value = 80;
             break;
           case TYPE_CONTAINER:
             value = 50;
             break;
           case TYPE_SCABBARD:
             value = 40;
             break;
           case TYPE_TOTEM:
             value = 90;
             break;
           case TYPE_SPELLBOOK:
             value = (3 * obj->value[2]) + 10;
             break;
           case TYPE_TREASURE:
             value = 100;
             break;
           case TYPE_CLOTHING:
             value = 11;
             break;
           case TYPE_TRASH:
             value = 1;
             break;
           case TYPE_BOAT:
             value = 100;
             break;
           case TYPE_SHIP:
             value = 1000;
             break;
           case TYPE_INSTRUMENT:
             value = 100;
             break;
       }

       // Just to make it _slightly_ less monotonous
       multiplier = number_fuzzy( multiplier );

       obj->cost = (( value * multiplier ) / 100);

       if( obj->condition != 0 )
          obj->cost = ( obj->cost * obj->condition ) / 100;

       if( obj->cost == 0 )
         obj->cost = 1;
}

