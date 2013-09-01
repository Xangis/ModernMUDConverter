
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merc.h"

DECLARE_MOB_FUN( spec_breath_any );
DECLARE_MOB_FUN( spec_breath_acid );
DECLARE_MOB_FUN( spec_breath_fire );
DECLARE_MOB_FUN( spec_breath_frost );
DECLARE_MOB_FUN( spec_breath_gas );
DECLARE_MOB_FUN( spec_breath_water );
DECLARE_MOB_FUN( spec_breath_lightning );
DECLARE_MOB_FUN( spec_cast_adept );
DECLARE_MOB_FUN( spec_cast_cleric );
DECLARE_MOB_FUN( spec_cast_druid );
DECLARE_MOB_FUN( spec_cast_shaman );
DECLARE_MOB_FUN( spec_cast_ghost );
DECLARE_MOB_FUN( spec_cast_judge );
DECLARE_MOB_FUN( spec_cast_conjurer );
DECLARE_MOB_FUN( spec_cast_necromancer );
DECLARE_MOB_FUN( spec_cast_sorcerer );
DECLARE_MOB_FUN( spec_cast_psionicist );
DECLARE_MOB_FUN( spec_cast_vampire );
DECLARE_MOB_FUN( spec_cast_undead );
DECLARE_MOB_FUN( spec_cast_illusionist );
DECLARE_MOB_FUN( spec_cast_earth_ele );
DECLARE_MOB_FUN( spec_cast_air_ele );
DECLARE_MOB_FUN( spec_cast_fire_ele );
DECLARE_MOB_FUN( spec_cast_water_ele );
DECLARE_MOB_FUN( spec_cast_ranger );
DECLARE_MOB_FUN( spec_cast_antipaladin );
DECLARE_MOB_FUN( spec_cast_paladin );
DECLARE_MOB_FUN( spec_cast_hunter );
DECLARE_MOB_FUN( spec_warrior );
DECLARE_MOB_FUN( spec_earth_elemental );
DECLARE_MOB_FUN( spec_air_elemental );
DECLARE_MOB_FUN( spec_fire_elemental );
DECLARE_MOB_FUN( spec_water_elemental );
DECLARE_MOB_FUN( spec_monk );
DECLARE_MOB_FUN( spec_executioner );
DECLARE_MOB_FUN( spec_fido );
DECLARE_MOB_FUN( spec_guard );
DECLARE_MOB_FUN( spec_janitor );
DECLARE_MOB_FUN( spec_mayor );
DECLARE_MOB_FUN( spec_poison );
DECLARE_MOB_FUN( spec_repairman );
DECLARE_MOB_FUN( spec_thief );
DECLARE_MOB_FUN( spec_assassin );
DECLARE_MOB_FUN( spec_mercenary );
DECLARE_MOB_FUN( spec_bard );
DECLARE_MOB_FUN( spec_justice_guard );
DECLARE_MOB_FUN( spec_justice_tracker );
DECLARE_MOB_FUN( spec_lost_girl );
DECLARE_MOB_FUN( spec_grumbar_shout );
DECLARE_MOB_FUN( death_proc_generic );
DECLARE_MOB_FUN( spec_xorn );
DECLARE_MOB_FUN( spec_lil_critter );

MOB_FUN *spec_mob_lookup( const char *name )
{
    int cmd;

    for ( cmd = 0; *spec_mob_table[cmd].spec_name; cmd++ )
	if ( !str_cmp( name, spec_mob_table[cmd].spec_name ) )
	    return spec_mob_table[cmd].spec_fun;

    return NULL;
}

const struct spec_mob_type spec_mob_table[ ] =
{
	{ "spec_breath_any", spec_breath_any },
	{ "spec_breath_acid", spec_breath_acid },
	{ "spec_breath_fire", spec_breath_fire },
	{ "spec_breath_frost", spec_breath_frost },
	{ "spec_breath_gas", spec_breath_gas },
	{ "spec_breath_water", spec_breath_water },
	{ "spec_breath_lightning", spec_breath_lightning },
	{ "spec_cast_adept", spec_cast_adept },
	{ "spec_cast_cleric", spec_cast_cleric },
	{ "spec_cast_druid", spec_cast_druid },
	{ "spec_cast_shaman", spec_cast_shaman },
	{ "spec_cast_ghost", spec_cast_ghost },
	{ "spec_cast_judge", spec_cast_judge },
	{ "spec_cast_air_ele", spec_cast_air_ele },
	{ "spec_cast_earth_ele", spec_cast_earth_ele },
	{ "spec_cast_fire_ele", spec_cast_fire_ele },
	{ "spec_cast_water_ele", spec_cast_water_ele },
	{ "spec_cast_ranger", spec_cast_ranger },
	{ "spec_cast_hunter", spec_cast_hunter },
	{ "spec_cast_paladin", spec_cast_paladin },
	{ "spec_cast_antipaladin", spec_cast_antipaladin },
	{ "spec_cast_illusionist", spec_cast_illusionist },
	{ "spec_cast_conjurer", spec_cast_conjurer },
	{ "spec_cast_necromancer", spec_cast_necromancer },
	{ "spec_cast_sorcerer", spec_cast_sorcerer },
	{ "spec_cast_psionicist", spec_cast_psionicist },
	{ "spec_cast_vampire", spec_cast_vampire },
	{ "spec_cast_undead", spec_cast_undead },
	{ "spec_executioner", spec_executioner },
	{ "spec_fido", spec_fido },
	{ "spec_guard", spec_guard },
	{ "spec_janitor", spec_janitor },
	{ "spec_mayor", spec_mayor },
	{ "spec_poison", spec_poison },
	{ "spec_repairman", spec_repairman },
	{ "spec_thief", spec_thief },
	{ "spec_assassin", spec_assassin },
	{ "spec_mercenary", spec_mercenary },
	{ "spec_warrior", spec_warrior },
	{ "spec_earth_elemental", spec_earth_elemental },
	{ "spec_air_elemental", spec_air_elemental },
	{ "spec_fire_elemental", spec_fire_elemental },
	{ "spec_water_elemental", spec_water_elemental },
	{ "spec_monk", spec_monk },
	{ "spec_bard", spec_bard },
	{ "spec_justice_guard", spec_justice_guard },
	{ "spec_justice_tracker", spec_justice_tracker },
	{ "spec_lost_girl", spec_lost_girl },
	{ "spec_grumbar_shout", spec_grumbar_shout },
	{ "spec_xorn", spec_xorn },
	{ "spec_lil_critter", spec_lil_critter },
	{ "", 0 }
};  

bool spec_breath_any( CHAR_DATA *ch, int cmd )
{
    return 0;
}

bool spec_breath_acid( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_breath_fire( CHAR_DATA *ch, int cmd )
{
    return 0;
}

bool spec_breath_frost( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_breath_water( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_breath_gas( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_breath_lightning( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_adept( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_cleric( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_druid( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_shaman( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_judge( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_conjurer( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_necromancer( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_sorcerer( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_air_ele( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_earth_ele( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_fire_ele( CHAR_DATA *ch, int cmd )
{
 	return 0;
}

bool spec_cast_water_ele( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_ranger( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_hunter( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_paladin( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_antipaladin( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_illusionist( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_assassin( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_warrior( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_fire_elemental( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_earth_elemental( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_air_elemental( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_water_elemental( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_monk( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_mercenary( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_bard( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_undead( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_vampire( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_executioner( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_fido( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_guard( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_janitor( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_mayor( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_poison( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_thief( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_psionicist( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_cast_ghost( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_repairman( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_justice_guard( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_justice_tracker( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_lost_girl( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_grumbar_shout( CHAR_DATA *ch, int cmd )
{
	return 0;
}

bool spec_xorn( CHAR_DATA *ch, int cmd ) 
{
	return 0;
}

bool spec_lil_critter( CHAR_DATA *ch , int cmd ) 
{
	return 0;
}

DECLARE_OBJ_FUN( spec_giggle );
DECLARE_OBJ_FUN( spec_soul_moan );
DECLARE_OBJ_FUN( spec_hum );
DECLARE_OBJ_FUN( spec_haste );
DECLARE_OBJ_FUN( spec_stoneskin );
DECLARE_OBJ_FUN( spec_sneak );
DECLARE_OBJ_FUN( spec_hide );
DECLARE_OBJ_FUN( spec_invisibility );
DECLARE_OBJ_FUN( spec_wp_lightning );
DECLARE_OBJ_FUN( spec_wp_chill );
DECLARE_OBJ_FUN( spec_wp_burn );
DECLARE_OBJ_FUN( spec_wp_fireball );
DECLARE_OBJ_FUN( spec_wp_harm );
DECLARE_OBJ_FUN( spec_wp_magic_missile );
DECLARE_OBJ_FUN( spec_wp_cutting_breeze );
DECLARE_OBJ_FUN( spec_wp_wither );
DECLARE_OBJ_FUN( spec_sundial );
DECLARE_OBJ_FUN( spec_ski );
DECLARE_OBJ_FUN( spec_inferno );
DECLARE_OBJ_FUN( spec_autumndecay );
DECLARE_OBJ_FUN( spec_celestial );
DECLARE_OBJ_FUN( spec_windsabre );
DECLARE_OBJ_FUN( spec_hornofplenty );
DECLARE_OBJ_FUN( spec_ghoulbane );
DECLARE_OBJ_FUN( spec_wp_bonethunder );
DECLARE_OBJ_FUN( spec_lightanddark );
DECLARE_OBJ_FUN( spec_trident );
DECLARE_OBJ_FUN( spec_hammer );

OBJ_FUN *spec_obj_lookup( const char *name )
{
    int cmd;

    for ( cmd = 0; *spec_obj_table[cmd].spec_name; cmd++ )
	if ( !str_cmp( name, spec_obj_table[cmd].spec_name ) )
	    return spec_obj_table[cmd].spec_fun;

    return 0;
}

const struct spec_obj_type spec_obj_table[ ] =
{
	{ "spec_giggle", spec_giggle },
	{ "spec_soul_moan", spec_soul_moan },
	{ "spec_hum", spec_hum },
	{ "spec_haste", spec_haste },
	{ "spec_stoneskin", spec_stoneskin },
	{ "spec_sneak", spec_sneak },
	{ "spec_hide", spec_hide },
	{ "spec_invisibility", spec_invisibility },
	{ "spec_wp_lightning", spec_wp_lightning },
	{ "spec_wp_chill", spec_wp_chill },
	{ "spec_wp_burn", spec_wp_burn },
	{ "spec_wp_fireball", spec_wp_fireball },
	{ "spec_wp_harm", spec_wp_harm },
	{ "spec_wp_magic_missile", spec_wp_magic_missile },
	{ "spec_wp_cutting_breeze", spec_wp_cutting_breeze },
	{ "spec_wp_wither", spec_wp_wither },
	{ "spec_sundial", spec_sundial },
	{ "spec_ski", spec_ski },
	{ "spec_inferno", spec_inferno },
	{ "spec_autumndecay", spec_autumndecay },
	{ "spec_celestial", spec_celestial },
	{ "spec_windsabre", spec_windsabre },
	{ "spec_hornofplenty", spec_hornofplenty },
	{ "spec_ghoulbane", spec_ghoulbane },
	{ "spec_wp_bonethunder", spec_wp_bonethunder },
	{ "spec_lightanddark", spec_lightanddark },
	{ "spec_hammer", spec_hammer },
	{ "", 0 }
};  

/*
 * Special procedures for objects.
 */
bool spec_giggle( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_hum( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}


bool spec_soul_moan( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_haste( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_sneak( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_hide( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_invisibility( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_stoneskin( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_chill( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_burn( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_fireball( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_lightning( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_harm( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;

}

bool spec_wp_destroy_undead( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_magic_missile( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_cutting_breeze( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_wither( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_sundial( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_ski( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_autumndecay( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_celestial( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_windsabre( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_hornofplenty( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_ghoulbane( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_wp_bonethunder( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_inferno( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )
{
	return 0;
}

bool spec_lightanddark( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )  
{
	return 0;
}

bool spec_trident( OBJ_DATA *obj, CHAR_DATA *keeper, bool hit )  
{
	return 0;
}

bool spec_hammer(  OBJ_DATA *obj, CHAR_DATA *keeper, bool hit ) 
{
	return 0;
}
