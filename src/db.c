#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include "merc.h"

#if !defined( macintosh )
extern  int     _filbuf	        args( (FILE *) );
#endif

#if !defined( ultrix ) && !defined( apollo )
#include <memory.h>
#endif

/* 
 * Globals. 
 */ 
HELP_DATA *		   help_first;
HELP_DATA *		   help_last;
SHOP_DATA *		   shop_first;
SHOP_DATA *		   shop_last;
CHAR_DATA *		   char_free;
EXTRA_DESCR_DATA * extra_descr_free;
AFFECT_DATA *	   affect_free;
OBJ_DATA *         obj_free;

char                    bug_buf                 [ MAX_INPUT_LENGTH*2 ];
CHAR_DATA *		char_list;
CHAR_DATA *             not_char_list;
char	                log_buf                 [ MAX_INPUT_LENGTH*2 ];
OBJ_DATA *		object_list;
QUEST_INDEX_DATA *      quest_first = NULL;
ROOM_INDEX_DATA *       room_index_hash[MAX_KEY_HASH];

int gsn_alcohol_tolerance;
int gsn_appraise;
int gsn_aware;
int gsn_backstab;
int gsn_bandage;
int gsn_bash;
int gsn_berserk;
int gsn_bladeflash;
int gsn_blindfighting;
int gsn_bodyslam;
int gsn_capture;
int gsn_charge;
int gsn_circle;
int gsn_disarm;
int gsn_dodge;
int gsn_drums;
int gsn_dulcimer;
int gsn_fiddle;
int gsn_flute;
int gsn_guard;
int gsn_harp;
int gsn_headbutt;
int gsn_hide;
int gsn_horn;
int gsn_instant_kill;
int gsn_listen;
int gsn_lyre;
int gsn_mandolin;
int gsn_mounted_combat;
int gsn_peek;
int gsn_pick_lock;
int gsn_pickpocket;
int gsn_pipes;
int gsn_poison;
int gsn_poison_bite;
int gsn_poison_weapon;
int gsn_quick_chant;
int gsn_scrolls;
int gsn_sneak;
int gsn_springleap;
int gsn_staves;
int gsn_steal;
int gsn_summon_mount;
int gsn_switch;
int gsn_untangle;
int gsn_wands;
int gsn_doorbash;
int gsn_dual;
int gsn_enhanced_damage;
int gsn_kick;
int gsn_parry;
int gsn_rescue;
int gsn_riposte;
int gsn_second_attack;
int gsn_singing;
int gsn_third_attack;
int gsn_throat_crush;
int gsn_throw;
int gsn_chameleon;
int gsn_heighten;
int gsn_shadow;
int gsn_shield_block;
int gsn_climb;
int gsn_fast_healing;
int gsn_fourth_attack;
int gsn_brew;
int gsn_scribe;
int gsn_dirt;
int gsn_meditate;
int gsn_safe_fall;
int gsn_swim;
int gsn_trip;
int gsn_track;
int gsn_tumble;
int gsn_unarmed;
int gsn_whirlwind;
int gsn_hit;
int gsn_slash;
int gsn_pierce;
int gsn_whip;
int gsn_explode;
int gsn_pound;
int gsn_suction;
int gsn_shot;
int gsn_mount;
int gsn_vampiric_bite;
int gsn_carve;
int gsn_layhands_timer;
int gsn_summon_mount_timer;

/*
 * Spell GSN's
 *
 * These should be in alphabetical order for easy reference.
 */
int spl_acid_arrow;
int spl_acid_blast;
int spl_agitation;
int spl_agony;
int spl_aid;
int spl_airy_starshell;
int spl_airy_water;
int spl_animate_dead;
int spl_armor;
int spl_ball_lightning;
int spl_barkskin;
int spl_battle_ecstasy;
int spl_bear;
int spl_blending;
int spl_bless;
int spl_blur;
int spl_burning_hands;
int spl_blindness;
int spl_bombard;
int spl_bonethunder;
int spl_cause_critical;
int spl_cause_light;
int spl_cause_serious;
int spl_change_self;
int spl_charm_person;
int spl_chill_touch;
int spl_cloak_of_fear;
int spl_cold_ward;
int spl_concealment;
int spl_conflaguration;
int spl_cone_of_cold;
int spl_cowardice;
int spl_create_dracolich;
int spl_creeping_doom;
int spl_cure_blind;
int spl_cure_critical;
int spl_cure_light;
int spl_cure_serious;
int spl_curse;
int spl_cure_blind;
int spl_cure_critical;
int spl_cure_light;
int spl_cure_serious;
int spl_curse;
int spl_cutting_breeze;
int spl_dazzle;
int spl_destroy_undead;
int spl_dexterity;
int spl_detect_evil;
int spl_detect_good;
int spl_detect_invis;
int spl_detect_magic;
int spl_detect_undead;
int spl_dirt_cloud;
int spl_disintegrate;
int spl_domination;
int spl_dust_blast;
int spl_earthen_grasp;
int spl_earthen_starshell;
int spl_earthen_tomb;
int spl_earthquake;
int spl_elemental_sight;
int spl_elemental_form;
int spl_elephant;
int spl_energy_drain;
int spl_enfeeblement;
int spl_enlarge;
int spl_enthrall;
int spl_fear;
int spl_feeblemind;
int spl_fiery_starshell;
int spl_fireball;
int spl_fire_bolt;
int spl_firestorm;
int spl_fire_ward;
int spl_flameburst;
int spl_flame_shield;
int spl_flamestrike;
int spl_fly;
int spl_frost_shield;
int spl_fullheal;
int spl_full_harm;
int spl_giant_strength;
int spl_gr_earthen_grasp;
int spl_gr_mending;
int spl_remove_poison;
int spl_harm;
int spl_haste;
int spl_hawk;
int spl_heal;
int spl_heal_undead;
int spl_herbal_remedy;
int spl_hex;
int spl_holy_sacrifice;
int spl_holy_word;
int spl_hypnotic_pattern;
int spl_iceball;
int spl_ice_bolt;
int spl_ice_missile;
int spl_ice_storm;
int spl_identify;
int spl_immolate;
int spl_incendiary_cloud;
int spl_incompetence;
int spl_infravision;
int spl_invis;
int spl_levitation;
int spl_lightanddark;
int spl_lightning_bolt;
int spl_lightning_curtain;
int spl_lion;
int spl_ls_herbal_remedy;
int spl_ls_mending;
int spl_magic_missile;
int spl_magnetism;
int spl_major_globe;
int spl_malison;
int spl_mass_heal;
int spl_mass_invis;
int spl_mass_vortex_lift;
int spl_mending;
int spl_mermaids_kiss;
int spl_meteor;
int spl_minor_para;
int spl_m_blending;
int spl_mirage_arcana;
int spl_misdirection;
int spl_mole;
int spl_molten;
int spl_mouse;
int spl_nightmares;
int spl_panther;
int spl_pebble;
int spl_phantasmal_killer;
int spl_plague;
int spl_poison;
int spl_polymorph;
int spl_prismatic_spray;
int spl_protect_acid;
int spl_protect_cold;
int spl_protect_fire;
int spl_protect_gas;
int spl_protect_lightning;
int spl_protect_undead;
int spl_prot_evil;
int spl_prowess;
int spl_pythonsting;
int spl_raise_skeleton;
int spl_raise_zombie;
int spl_raise_spectre;
int spl_raise_wraith;
int spl_raise_vampire;
int spl_raise_lich;
int spl_ravenflight;
int spl_recall;
int spl_reduce;
int spl_rejuvenate;
int spl_remove_poison;
int spl_resurrect;
int spl_scalding;
int spl_scathing_wind;
int spl_scorching;
int spl_shield;
int spl_shocking_grasp;
int spl_shock_shield;
int spl_shrew;
int spl_silence;
int spl_soulshield;
int spl_sleep;
int spl_slowness;
int spl_snail;
int spl_soothe;
int spl_soul_disturbance;
int spl_spark;
int spl_spirit_anguish;
int spl_spirit_armor;
int spl_summon_elemental;
int spl_stoneskin;
int spl_stonestorm;
int spl_stornogs_spheres;
int spl_sunray;
int spl_sustenance;
int spl_telekinesis;
int spl_teleport;
int spl_turn_undead;
int spl_ultra_death_ray;
int spl_unholy_word;
int spl_vacancy;
int spl_vig_critical;
int spl_vig_light;
int spl_vig_serious;
int spl_vitality;
int spl_wall_of_fire;
int spl_wall_of_ice;
int spl_wall_of_mist;
int spl_wall_of_sparks;
int spl_water_breathing;
int spl_water_blast;
int spl_water_bolt;
int spl_watery_starshell;
int spl_wierd;
int spl_wither;
int spl_wolf;
int spl_bird_prey;
int spl_darkness;
int spl_miners_intuition;
int spl_wall_iron;
int spl_wall_stone;
int spl_wall_force;
int spl_wall_illusion;
int spl_mirror_image;
int spl_shadow_monsters;
int spl_demi_shad_monster;
int spl_shades;
int spl_cloak_fear;
int spl_clone;
int spl_power_word_blind;
int spl_spook;
int spl_sunburst;
int spl_call_lightning;
int spl_gr_agony;
int spl_m_agony;
int spl_ravenous_vines;
int spl_change_sex;
int spl_color_spray;
int spl_prismatic_orb;
int spl_shadow_magic;
int spl_demi_shad_magic;
int spl_cone_silence;
int spl_continual_light;
int spl_twilight;
int spl_control_weather;
int spl_create_food;
int spl_conjure_windsaber;
int spl_celestial_sword;
int spl_create_skin;
int spl_create_spring;
int spl_create_watern;
int spl_purify_spirit;
int spl_purify;
int spl_cure_disease;
int spl_nourishment;
int spl_ls_nourishment;
int spl_gr_sustenance;
int spl_rain_maker;
int spl_destroy_cursed;
int spl_spirit_sight;
int spl_analyze_balance;
int spl_sense_life;
int spl_sense_spirit;
int spl_gr_spirit_sight;
int spl_true_seeing;
int spl_comp_lang;
int spl_detect_poison;
int spl_dispel_evil;
int spl_gleam_dawn;
int spl_gleam_dusk;
int spl_dispel_magic;
int spl_enchant_weapon;
int spl_exorcise;
int spl_faerie_fire;
int spl_faerie_fog;
int spl_reveal_true_form;
int spl_reveal_true_name;
int spl_dispel_invisible;
int spl_negate_veil;
int spl_negate_luster;
int spl_illumination;
int spl_bigby_fist;
int spl_akiaurn_word;
int spl_windsaber;
int spl_flight;
int spl_gr_ravenflight;
int spl_gate;
int spl_farsee;
int spl_know_alignment;
int spl_reveal_spirit_essence;
int spl_touch_nightshade;
int spl_locate_object;
int spl_minor_creation;
int spl_elemental_creation;
int spl_tidal_wave;
int spl_cyclone;
int spl_whirlwind;
int spl_inferno;
int spl_earthen_rain;
int spl_gr_soul_dist;
int spl_group_heal;
int spl_wellness;
int spl_pass_door;
int spl_gr_pythonsting;
int spl_call_wild;
int spl_minor_globe;
int spl_group_globe;
int spl_spirit_ward;
int spl_gr_spirit_ward;
int spl_deny_air;
int spl_deny_earth;
int spl_deny_fire;
int spl_deny_water;
int spl_protection_good;
int spl_harbor_balance;
int spl_adaptation;
int spl_recharge_item;
int spl_stamina;
int spl_gr_stamina;
int spl_remove_alignment;
int spl_preserve;
int spl_remove_curse;
int spl_negate_hex;
int spl_remove_silence;
int spl_sanctuary;
int spl_shadow_shield;
int spl_entangle;
int spl_group_stone;
int spl_hurricane;
int spl_flashfire;
int spl_mass_dispel_magic;
int spl_stonestrength;
int spl_summon;
int spl_plane_shift;
int spl_flickering_flame;
int spl_ripple;
int spl_ventriloquate;
int spl_group_recall;
int spl_acid_breath;
int spl_fire_breath;
int spl_water_breath;
int spl_frost_breath;
int spl_gas_breath;
int spl_lightning_breath;
int spl_general_purpose;
int spl_high_explosive;
int spl_adrenaline_control;
int spl_aura_sight;
int spl_awe;
int spl_ballistic_attack;
int spl_biofeedback;
int spl_cell_adjustment;
int spl_combat_mind;
int spl_complete_healing;
int spl_control_flames;
int spl_create_sound;
int spl_deathfield;
int spl_detonate;
int spl_neurofrag;
int spl_displacement;
int spl_ectoplasmic_form;
int spl_ego_whip;
int spl_energy_containment;
int spl_enhance_armor;
int spl_enhanced_strength;
int spl_flesh_armor;
int spl_inertial_barrier;
int spl_inflict_pain;
int spl_intellect_fortress;
int spl_lend_health;
int spl_transfer_wellness;
int spl_mental_barrier;
int spl_mind_thrust;
int spl_project_force;
int spl_psionic_blast;
int spl_psychic_crush;
int spl_psychic_drain;
int spl_psychic_healing;
int spl_share_strength;
int spl_thought_shield;
int spl_ultrablast;
int spl_chain_lightning;
int spl_wizard_eye;
int spl_vortex_lift;
int spl_shadow_walk;
int spl_dimdoor;
int spl_migration;
int spl_shadow_door;
int spl_shadow_veil;
int spl_spirit_jump;
int spl_dispel_good;
int spl_judgement;
int spl_apocalypse;
int spl_power_word_lag;
int spl_power_word_stun;
int spl_etherportal;
int spl_moonwell;
int spl_wormhole;
int spl_create_buffet;
int spl_fireskin;
int spl_ethereal_shield;
int spl_sense_followers;
int spl_slow_poison;
int spl_acid_spray;
int spl_aura;
int spl_earthen_smith;
int spl_fiery_smith;
int spl_airy_smith;
int spl_aquatic_smith;
int spl_hover;
int spl_azure_flame;
int spl_gust_of_frost;
int spl_tide_seas;
int spl_dismissal;
int spl_summon_serpent;
int spl_summon_nerneid;
int spl_summon_pech;
int spl_summon_slyph;
int spl_summon_gr_elem;
int spl_thirst;
int spl_tridenttides;
int spl_hellfire;
int spl_embalm;
int spl_alacrity;
int spl_embalm;
int spl_aging;
int spl_vitalize_mana;
int spl_prot_from_undead;
int spl_shadow_breath2;
int spl_choke;
int spl_vampiric_touch;

/* 
 * race GSNs
 */
int race_human;
int race_barbarian;
int race_grey_elf;
int race_rakshasa;
int race_half_elf;
int race_gnoll;
int race_drow_elf;
int race_dwarf;
int race_duergar;
int race_halfling;
int race_troll;
int race_ogre;
int race_orc;
int race_gnome;
int race_centaur;
int race_githyanki;
int race_goblin;
int race_minotaur;
int race_githzerai;
int race_illithid;
int race_thri_kreen;
int race_aquatic_elf;
int race_sahaugin;
int race_half_orc;
int race_half_dwarf;
int race_half_kobold;
int race_giant;
int race_neogi;
int race_kobold;
int race_dragon;
int race_hobgoblin;
int race_hobgoblin;
int race_humanoid;
int race_demon;
int race_god;
int race_devil;
int race_angel;
int race_faerie;
int race_vampire;
int race_werewolf;
int race_beholder;
int race_derro;
int race_golem;
int race_dracolich;
int race_dragonkin;
int race_insect;
int race_animal;
int race_herbivore;
int race_carnivore;
int race_bird;
int race_horse;
int race_primate;
int race_undead;
int race_ghost;
int race_harpy;
int race_bear;
int race_rust_monster;
int race_fire_elemental;
int race_air_elemental;
int race_water_elemental;
int race_earth_elemental;
int race_bat;
int race_plant;
int race_tree;
int race_rat;
int race_parasite;
int race_lycanthrope;
int race_arachnid;
int race_object;
int race_mist;
int race_snake;
int race_worm;
int race_fish;
int race_ixitxachitl;
int race_aboleth;
int race_hydra;
int race_reptile;
int race_boar;

// Traps
int trp_acid;
int trp_bash;
int trp_cold;
int trp_disease;
int trp_dispel;
int trp_energy;
int trp_fire;
int trp_gate;
int trp_harm;
int trp_para;
int trp_pierce;
int trp_poison;
int trp_slash;
int trp_sleep;
int trp_stun;
int trp_summon;
int trp_teleport;
int trp_wither;

/*
 * Locals.
 */
MOB_INDEX_DATA *	mob_index_hash	        [ MAX_KEY_HASH       ];
OBJ_INDEX_DATA *	obj_index_hash	        [ MAX_KEY_HASH       ];

AREA_DATA *		area_first;
AREA_DATA *		area_last;

extern char		str_empty	        [ 1                  ];

int			top_affect;
int			top_area;
int			top_ed;
int			top_exit;
int			top_help;
int			top_mob_index;
int			top_obj_index;
int			top_reset;
int			top_room;
int			top_shop;
int			top_game;
int                     top_vnum_room;
int                     top_vnum_mob;
int                     top_vnum_obj;
int                     top_quest;
int                     top_qmsg;
int                     top_qdata;
int                     top_qitem;
int                     top_event;
int                     top_memdata;
int                     top_note;
int                     top_ban;
int                     top_desc;
int                     top_social;
int                     top_vehicle;
int                     top_obj;
int                     top_char;
int                     top_pcdata;
int                     top_trap;
int                     top_crime;
int                     top_mvscript;

/*
 * Memory management.
 * Increase MAX_STRING from 1500000 if you have too.
 * Tune the others only if you understand what you're doing.
 * MAX_STRING is now in ssm.c
 */
extern int		MAX_STRING;

#define			MAX_PERM_BLOCK  131072
#define			MAX_MEM_LIST    14

void *			rgFreeList              [ MAX_MEM_LIST       ];
const int		rgSizeList              [ MAX_MEM_LIST       ]  =
{
    4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768-64
};

extern int		nAllocString;
extern int		sAllocString;
extern int		nOverFlowString;
extern int		sOverFlowString;
extern bool		Full;
int			nAllocPerm;
int			sAllocPerm;


/*
 * Semi-locals.
 */
bool			fBootDb;
FILE *			fpArea;
char			strArea			[ MAX_INPUT_LENGTH   ];

void    init_string_space ( void );
void    boot_done( );
char *  daPrompt;
char  *StripZeroPrefix(char * encstr);
/*
 * Local booting procedures.
 */
void	init_mm		  args( ( void ) );
void    load_bast_rooms(FILE *fp);
void load_bast_objects(FILE *fp);
void	load_area_file    args( ( void ) );
void load_bast_mobiles(FILE *fp);
void load_bast_resets(FILE *fp);
void	load_area         args( ( FILE *fp ) );
void	load_helps        args( ( FILE *fp ) );
void    load_recall       args( ( FILE *fp ) );
void	load_resets       args( ( FILE *fp ) );
void	load_specials     args( ( FILE *fp ) );
void    load_names        args( ( void ) );
void    save_sysdata      args( ( void ) );
void    load_down_time    args( ( void ) );
void	fix_exits         args( ( void ) );
void    load_quests       args( ( FILE *fp ) );

void    make_arti_owner   args( ( char * const owner, const int vnum ) );


/*
 * Non-Envy Loading procedures.
 * Put any new loading function in this section.
 */
void    new_load_area		args( ( FILE *fp ) );	/* OLC */
void load_bast_shops( FILE *fp );
void    load_magma_rooms         args( ( FILE *fp ) );  /* Magma rooms*/
void    load_magma_objects       args( ( FILE *fp ) );  /* Magma objs*/
void    load_magma_mobiles       args( ( FILE *fp ) );  /* Magma mobs*/
void    load_magma_resets        args( ( FILE *fp ) );  /* Magma loads*/
void    load_magma_shops         args( ( FILE *fp ) );  /* Magma shops*/
int     magma_spell_lookup       args( ( int skill ) );  /* Magma Magic items*/

void show_file_location( FILE *fp )
{
	char buf[256];
	memset(buf, 0, 256);
	fread(buf, 256, 1, fp );
	log_string(buf);
}

/*
 * Big mama top level function.
 */
void boot_db( void )
{
    int i;

    /*
     * Init some data space stuff.
     */
    init_string_space( );
	fBootDb		= TRUE;

    fprintf( stderr, "[*****] BOOT: ---------------------------[ Boot Log ]---------------------------\n" );

    /*
     * Init random number generator.
     */
    log_string( "Initializing random number generator" );
    {
		init_mm( );
    }


    /*
     * Assign gsn's for skills which have them.
     * Init skills_table class levels.
     */
    // also initialize the spells_table - Veygoth
    //
    // Assign's values for races too.
    //
    log_string( "Assigning gsn's" );
    {
	int sn;
	int c_class;

	for ( sn = 0; sn < MAX_SKILL; sn++ )
	{
	    if ( skills_table[sn].pgsn )
		*skills_table[sn].pgsn = sn;

	    for ( c_class = 0; c_class < MAX_CLASS; c_class++ )
		skills_table[sn].skill_level[c_class] = L_APP;
	}

	for ( sn = 0; sn < MAX_SPELL; sn++ )
	{
	    if ( spells_table[sn].pgsn )
		*spells_table[sn].pgsn = sn;

	    for ( c_class = 0; c_class < MAX_CLASS; c_class++ )
		spells_table[sn].spell_circle[c_class] = MAX_CIRCLE+3;
	}
        //Initialize race gsns
        for ( sn = 0; sn < MAX_RACE; sn++) {
            if ( race_table[sn].race_gsn )
                *race_table[sn].race_gsn = sn;
        }

    }

    log_string( "Loading classes" );
    load_classes( );

    /*
     * Read in all the area files.
     */
    log_string( "Reading in area files..." );
    {
	FILE      *fpList;
	char       strsave [ MAX_INPUT_LENGTH ];
	sprintf( strsave, "%s%s", AREA_DIR, AREA_LIST );

	if ( !( fpList = fopen( strsave, "r" ) ) )
	{
	    perror( AREA_LIST );
		getchar();
	    exit( 1 );
	}

	for ( ; ; )
	{
	    int stat;

	    strcpy( strArea, fread_word( fpList, &stat ) );
	    if ( strArea[0] == '$' )
            break;
        else if( strArea[0] == '*' )
        {
            // Comment, ignored.
            fread_to_eol(fpList);
            continue;
        }

	    load_area_file( );

	}
	fclose( fpList );
    }

    /*
     * Fix up exits.
     * Declare db booting over.
     * Reset all areas once.
     * Load up the notes file.
     */
    {
	log_string( "Fixing exits" );
	fix_exits( );
	fBootDb  = FALSE;
	daPrompt = str_dup( 
         "&+g<%hhp %mm %vmv>\r\n<&n%T %E&+g>&n " );
	boot_done( );

	MOBtrigger = TRUE;
    }
    
    return;
}

/*
 * Snarf an 'area' header line.
 */
void load_area_file( )
{
    int		stat;
    char	buf [ MAX_STRING_LENGTH ];

    if ( !fBootDb )
    {
        bug( "load_area_file: can't load area if not booting!", 0 );
        return;
    }

    if ( strArea[0] == '-' )
    {
	fpArea = stdin;
	strcpy ( buf, &strArea[1] );
	strcpy ( strArea, buf );
    }
    else
    {
		char strsave [ MAX_INPUT_LENGTH ]; 

		sprintf( strsave, "%s%s", AREA_DIR, strArea );

		if ( !( fpArea = fopen( strsave, "r" ) ) )
		{
			bugf("load_area_file: Could not open file %s.", strArea );
			return;
		}
    }

    for ( ; ; )
    {
	char *word;

	if ( fread_letter( fpArea ) != '#' )
	{
	    bug( "load_area_file: # not found.", 0 );
		show_file_location(fpArea);
		getchar();
	    exit( 1 );
	}

	word = fread_word( fpArea, &stat );


	if ( word[0] == '$'               )
	    break;
	else if ( !str_cmp( word, "AREA"     ) )
	    new_load_area    ( fpArea );
	else if ( !str_cmp( word, "HELPS"    ) ) 
	    load_helps   ( fpArea );
	else if ( !str_cmp( word, "RECALL"   ) )
	    load_recall  ( fpArea );
	else if ( !str_cmp( word, "MAGMAMOBS"  ) )
	    load_magma_mobiles ( fpArea );
    else if( !str_cmp( word, "BASTMOBS" ))
        load_bast_mobiles( fpArea );
	else if ( !str_cmp( word, "RESETS"   ) )
	    load_resets  ( fpArea );
    else if( !str_cmp( word, "BASTRESETS" ))
        load_bast_resets(fpArea);
	else if ( !str_cmp( word, "MAGMARESETS"   ) )
	    load_magma_resets  ( fpArea );
	else if ( !str_cmp( word, "MAGMASHOPS"    ) )
	    load_magma_shops   ( fpArea );
    else if( !str_cmp( word, "BASTSHOPS" ))
        load_bast_shops (fpArea);
	else if ( !str_cmp( word, "SPECIALS" ) )
	    load_specials( fpArea );
	else if ( !str_cmp( word, "AREADATA" ) )
	    new_load_area( fpArea );
        else if( !str_cmp( word, "MAGMAROOMS" ) )
            load_magma_rooms( fpArea );
        else if( !str_cmp( word, "BASTROOMS" ))
            load_bast_rooms(fpArea);
        else if ( !str_cmp( word, "MAGMAOBJECTS" ) )
            load_magma_objects( fpArea );
        else if( !str_cmp( word, "BASTOBJECTS" ))
            load_bast_objects( fpArea);
        else if ( !str_cmp( word, "QUESTS" ) )
            load_quests( fpArea );
	else
	{
	    bug( "Load_area: bad section name.", 0 );
        log_string(word);
		getchar();
	    exit( 1 );
	}
    }

    if ( fpArea != stdin )
	fclose( fpArea );
    fpArea = NULL;

    if ( area_last )
    {

	fprintf( stderr, "%-14s: Rooms: %5d - %-5d Objs: %5d - %-5d Mobs: %5d - %d\n",
		area_last->filename,
		area_last->low_r_vnum, area_last->hi_r_vnum,
		area_last->low_o_vnum, area_last->hi_o_vnum,
		area_last->low_m_vnum, area_last->hi_m_vnum );
    }
    else
    {
	fprintf( stderr, "(%s)\n", strArea );
    }

    return;
}



/*
 * Snarf an 'area' header line.
 */
void load_area( FILE *fp )
{
    AREA_DATA *pArea;
    char       author [ MAX_STRING_LENGTH ];
    char       range  [ MAX_STRING_LENGTH ];
    char       name   [ MAX_STRING_LENGTH ];
    char       arg1   [ MAX_STRING_LENGTH ];
    char       arg2   [ MAX_STRING_LENGTH ];
    char       buf    [ MAX_STRING_LENGTH ];
    char      *ptr;

    pArea               = alloc_perm( sizeof( *pArea ) );       /*
    pArea->reset_first  = NULL;                                  * OLC-Removed
    pArea->reset_last   = NULL;                                  */

    /*
     * Ugly hack to convert well behaved areas to new format.
     */
    temp_fread_string( fp, buf );

    while ( ( ptr = strchr( buf, '{' ) ) )
	*ptr = '"';

    while ( ( ptr = strchr( buf, '}' ) ) )
	*ptr = '"';

    ptr = &buf[0];

    ptr = one_argument( ptr, range	);
    ptr = one_argument( ptr, author	);

    strcpy( name, ptr );

    ptr = &range[0];

    ptr = one_argument( ptr, arg1	);
    ptr = one_argument( ptr, arg2	);

    if ( is_number( arg1 ) && is_number( arg2 ) )
    {
	pArea->llv		= atoi( arg1 );
	pArea->ulv		= atoi( arg2 );
    }
    else
    if ( !str_cmp( arg1, "All" ) )
    {
	pArea->llv		= 0;
	pArea->ulv		= MAX_LEVEL;
    }
    else
    {
	pArea->llv		= 0;
	pArea->ulv		= 0;
    }

    pArea->name		= str_dup( name );
    pArea->author	= str_dup( capitalize( author ) );
    pArea->resetmsg	= str_dup( "You hear the patter of little feet." );

    pArea->recall       = ROOM_VNUM_TEMPLE;
    pArea->area_flags   = AREA_LOADING;
    pArea->security     = 1;
    pArea->builders     = str_dup( "None" );
    pArea->lvnum        = 0;
    pArea->uvnum        = 0;
    pArea->vnum         = top_area;
    pArea->filename     = str_dup( strArea );
    pArea->age		= 15;
    pArea->nplayer	= 0;
    pArea->justice      = 0;
    pArea->low_r_vnum	= 0;
    pArea->hi_r_vnum	= 0;
    pArea->low_o_vnum	= 0;
    pArea->hi_o_vnum	= 0;
    pArea->low_m_vnum	= 0;
    pArea->hi_m_vnum	= 0;
    
    if ( !area_first )
	area_first = pArea;
    if (  area_last  )
    {
	area_last->next = pArea;
        REMOVE_BIT( area_last->area_flags, AREA_LOADING );
    }
    area_last	= pArea;
    pArea->next	= NULL;

    top_area++;
    return;
}



/* 
 * OLC
 * Snarf an 'area' header line.   Check this format.  MUCH better.  Add fields
 * too.
 *
 * #AREAFILE
 * Name   -Newbie School~
 * Author Locke~
 * Levels 1 54
 * Recall 3001
 * Reset You hear hitting a pencil on paper.~
 * End
 *
 * The first character of the name ( '-' or '*' ) signs, that the area
 * is taken from the original (-) or has been added by wizards (*).
 * 
 * -Sektor
 */
void fread_area( FILE *fp, AREA_DATA *pArea )
{
    char        *word;
    char        buf [ MAX_STRING_LENGTH ];
    int         i;
    int         j;
    int         error_count = 0;
    int         status;
    char        *p;
    int         tmpi;
    int         num_keys;
    int         last_key = 0;

    char	def_author [] = "Envy";
    char	def_reset  [] = "You hear the patter of little feet.";

    struct key_data key_tab [] = { 
      { "Name",     TRUE,  MAND,		{ &pArea->name,       NULL } },
      { "Author",   TRUE,  (unlong) &def_author,{ &pArea->author,     NULL } },
      { "Levels",   FALSE, 9999,		{ &pArea->llv,
						  &pArea->ulv,        NULL } },
      { "Security", FALSE, MAND,		{ &pArea->security,   NULL } },
      { "VNUMS",    FALSE, 0,		{ &pArea->lvnum,
						  &pArea->uvnum,      NULL } },
      { "VNUMs",    FALSE, 0,		{ &pArea->lvnum,
						  &pArea->uvnum,      NULL } },
      { "Builders", TRUE,  MAND,		{ &pArea->builders,   NULL } },
      { "Justice",  FALSE, 0,                   { &pArea->justice,    NULL } },
      { "Judge",    FALSE, 0,                   { &pArea->judge,      NULL } },
      { "Jail",     FALSE, 0,                   { &pArea->jail,       NULL } },
      { "Squads",   FALSE, 0,                   { &pArea->squads,     NULL } },
      { "Barracks", FALSE, 0,                   { &pArea->barracks,   NULL } },
      { "Defender", FALSE, 0,                   { &pArea->defender, &pArea->defender_num,   NULL } },
      { "Recall",   FALSE, ROOM_VNUM_TEMPLE,	{ &pArea->recall,     NULL } },
      { "Reset",    TRUE,  (unlong) &def_reset,	{ &pArea->resetmsg,   NULL } },
      { "Version",  FALSE, 1,                   { &pArea->version,    NULL } },
      { "\0",       FALSE, 0                                               } };

    pArea->squads = 5;

    for ( num_keys = 0; *key_tab [num_keys].key; )
        num_keys++;

    for ( ; !feof (fp) ; )
    {

        word = fread_word( fp, &status );

        if ( !word )
	{
            bug( "fread_area:  Error reading key.  EOF?", 0 );
            fread_to_eol( fp );
            break;
	}

                /* This little diddy searches for the keyword
                   from the last keyword found */

        for ( i = last_key;
              i < last_key + num_keys &&
                str_cmp (key_tab [i % num_keys].key, word); )
            i++;

        i = i % num_keys;

        if ( !str_cmp (key_tab [i].key, word) )
            last_key = i;
        else
            i = num_keys;

        if ( *key_tab [i].key )         /* Key entry found in key_tab */
	{
            if ( key_tab [i].string == SPECIFIED )
                bug ("Key already specified.", 0);

                        /* Entry is a string */

            else
	      if ( key_tab [i].string )
	      {
                  if ( ( p = fread_string( fp, &status ) ) && !status )
		  {
		      free_string ( *(char **)key_tab [i].ptrs [0] );
		      *(char **)key_tab [i].ptrs [0] = p;
		  }
	      }

                        /* Entry is an integer */
            else
                for ( j = 0; key_tab [i].ptrs [j]; j++ )
		{
                    tmpi = fread_number ( fp, &status );
                    if ( !status )
                        *(int *)key_tab [i].ptrs [j] = tmpi;
		}

            if ( status )
	    {
                fread_to_eol( fp );
                continue;
	    }
	    else
                key_tab [i].string = SPECIFIED;
	}
        else if( !str_cmp( word, "Racehome" ))
        {
            log_string( "Racehome data found.  Ignoring.  You should take note of this and manually add it to the MUD.");
            fread_to_eol(fp);
        }
        else if( !str_cmp( word, "Classhome" ))
        {
            log_string( "Classhome data found.  Ignoring.  You should take note of this and manually add it to the MUD.");
            fread_to_eol(fp);
        }
        else if( !str_cmp( word, "AreaFlags" ))
        {
            sprintf(buf, "AreaFlags data found.  Ignoring.  This will have to be added manually.");
            fread_to_eol(fp);
        }
        else if ( !str_cmp( word, "End" ) )
            break;
        else
		{
			sprintf( buf, "fread_area: Unknown key '%s' in file.", word );
			bug( buf, 0 );
			fread_to_eol( fp );
		}
	
    }

                /* Require all manditory fields, set defaults */

    for ( i = 0; *key_tab [i].key; i++ )
    {

        if ( key_tab [i].string == SPECIFIED ||
             key_tab [i].deflt == DEFLT )
            continue;

        if ( key_tab [i].deflt == MAND )
	{
            sprintf( buf, "Manditory field '%s' missing from file.",
                          key_tab [i].key );
            bug( buf, 0 );
            error_count++;
            continue;
	}

               /* This if/else sets default strings and numbers */

        if ( key_tab [i].string && key_tab [i].deflt )
	{
	    free_string( *(char **)key_tab [i].ptrs [0] );
            *(char **)key_tab [i].ptrs [0] =
	      str_dup( (char *)key_tab [i].deflt );
	}
        else
            for ( j = 0; key_tab [i].ptrs [j]; j++ )
	        *(int *)key_tab [i].ptrs [j] = key_tab [i].deflt;
    }

    if ( pArea->llv == 9999 )
	pArea->llv = 0;

    if ( pArea->ulv == 9999 )
	pArea->ulv = MAX_LEVEL;

    pArea->times_reset = 0;
    pArea->llifespan = 15;
    pArea->ulifespan = 15;

    return;
}

void new_load_area( FILE *fp )
{
    AREA_DATA *pArea;

    pArea		= alloc_perm( sizeof( *pArea ) );
    pArea->recall       = ROOM_VNUM_TEMPLE;
    pArea->area_flags   = AREA_LOADING;
    pArea->security     = 1;
    pArea->builders     = str_dup( "None" );
    pArea->lvnum        = 0;
    pArea->uvnum        = 0;
    pArea->vnum         = top_area;
    pArea->filename     = str_dup( strArea );
    pArea->age		= 15;
    pArea->nplayer	= 0;
    pArea->justice      = 0;
    pArea->low_r_vnum	= 0;
    pArea->hi_r_vnum	= 0;
    pArea->low_o_vnum	= 0;
    pArea->hi_o_vnum	= 0;
    pArea->low_m_vnum	= 0;
    pArea->hi_m_vnum	= 0;

    fread_area( fp, pArea );

    if ( !area_first )
	area_first = pArea;
    if (  area_last  )
    {
	area_last->next = pArea;
        REMOVE_BIT( area_last->area_flags, AREA_LOADING );
    }
    area_last	= pArea;
    pArea->next	= NULL;

    top_area++;
    return;
}


/*
 * Sets vnum range for area using OLC protection features.
 */
void assign_area_vnum( int vnum )
{
    if ( area_last->lvnum == 0 || area_last->uvnum == 0 )
        area_last->lvnum = area_last->uvnum = vnum;
    if ( vnum != URANGE( area_last->lvnum, vnum, area_last->uvnum ) )
    {
        if ( vnum < area_last->lvnum )
            area_last->lvnum = vnum;
        else
            area_last->uvnum = vnum;
    }
    return;
}



/*
 * Snarf a help section.
 */
void load_helps( FILE *fp )
{
    HELP_DATA *pHelp;
    char      *keyword;
    int        level;
    int        stat;

    for ( ; ; )
    {
        level           = fread_number( fp, &stat );
	keyword         = fread_string( fp, &stat );
	if ( keyword[0] == '$' )
	    break;

	pHelp		= alloc_perm( sizeof( *pHelp ) );

	pHelp->level	= level;
	pHelp->keyword	= keyword;
	pHelp->text	= fread_string( fp, &stat );
        pHelp->area     = area_last ? area_last : NULL;

	if ( !help_first )
	    help_first = pHelp;
	if (  help_last  )
	    help_last->next = pHelp;


	help_last	= pHelp;
	pHelp->next	= NULL;
	top_help++;
    }

    return;
}



/*
 * Snarf a recall point.
 */
void load_recall( FILE *fp )
{
    AREA_DATA *pArea;
    char       buf [ MAX_STRING_LENGTH ];
    int        stat;

    pArea         = area_last;
    pArea->recall = fread_number( fp, &stat );

    if ( pArea->recall < 1 )
    {
        sprintf( buf, "Load_recall:  %s invalid recall point", pArea->name );
	bug( buf, 0 );
	pArea->recall = ROOM_VNUM_TEMPLE;
    }

    return;

}

MOB_FUN *get_breath_type( char *name )
{
    if( !str_infix( "br_f", name ) )
        return spec_mob_lookup( "spec_breath_fire" );
    if( !str_infix( "br_a", name ) )
        return spec_mob_lookup( "spec_breath_acid" );
    if( !str_infix( "br_c", name ) )
        return spec_mob_lookup( "spec_breath_frost" );
    if( !str_infix( "br_g", name ) )
        return spec_mob_lookup( "spec_breath_gas" );
    if( !str_infix( "br_l", name ) )
        return spec_mob_lookup( "spec_breath_lightning" );
    if ( !str_infix ( "br_w", name ) )
        return spec_mob_lookup( "spec_breath_water" );
    /* THis needs to be fixed when shadow breath is addeD! */
    if ( !str_infix ( "br_s", name ) )
        return spec_mob_lookup( "spec_breath_fire" );

    return spec_mob_lookup( "spec_breath_any" );
}

/*
 * Load a Magma format mob section - Veygoth.
 */
void load_magma_mobiles( FILE *fp )
{
    MOB_INDEX_DATA *pMobIndex;
    char buf[MAX_STRING_LENGTH]; // better error messages...
    int count;
	bool duris_format = FALSE;
    MOB_INDEX_DATA *duplicateMob = NULL;

    if ( !area_last )				/* OLC */
    {
        bug( "load_magma_mobiles: no #AREA seen yet.", 0 );
		getchar();
        exit( 1 );
    }

    for ( ; ; )
    {
	    char *race;
	    char  letter;
	    int   vnum;
	    int   iHash;
	    int   stat;

	    letter = fread_letter( fp );
	    if ( letter != '#' )
	    {
	        bug( "load_magma_mobiles: # not found.", 0 );
		    show_file_location(fp);
		    getchar();
	        exit( 1 );
	    }

	    vnum = fread_number( fp, &stat );
	    if ( vnum == 0 )
	        break;

	    fBootDb = FALSE;
	    if ( (duplicateMob = get_mob_index( vnum )) )
	    {
            sprintf( buf, "load_magma_mobiles: index number %d already in use by %s in zone %s.", vnum, duplicateMob->player_name, duplicateMob->area->filename);
	        bug( buf, 0 );
		    getchar();
	        exit( 1 );
	    }
	    fBootDb = TRUE;

	    pMobIndex = alloc_perm( sizeof( *pMobIndex ) );
	    pMobIndex->vnum = vnum;

        if( vnum == 13864 )
        {
            log_string("ok");
        }

	    if ( !area_last->low_m_vnum )
	        area_last->low_m_vnum = vnum;
	    if ( vnum > area_last->hi_m_vnum )
	        area_last->hi_m_vnum = vnum;

        pMobIndex->area             = area_last;
	    pMobIndex->player_name		= fread_string( fp, &stat );
	    pMobIndex->short_descr		= fread_string( fp, &stat );
	    pMobIndex->long_descr		= fread_string( fp, &stat );
	    pMobIndex->description		= fread_string( fp, &stat );

	    pMobIndex->long_descr[0]	= UPPER( pMobIndex->long_descr[0]  );
	    pMobIndex->description[0]	= UPPER( pMobIndex->description[0] );

	    pMobIndex->act			    = fread_number( fp, &stat ) | ACT_IS_NPC;
	    pMobIndex->affected_by[0]	= fread_number( fp, &stat );
        pMobIndex->affected_by[1]   = fread_number( fp, &stat );
        pMobIndex->affected_by[2]   = fread_number( fp, &stat );
        pMobIndex->affected_by[3]   = fread_number( fp, &stat );
        // Set all other vectors to zero since this file format only has
        // two vectors - Veygoth
        if( NUM_AFFECT_VECTORS > 4 )
        {
           for( count = 2; count < NUM_AFFECT_VECTORS; count++ )
           {
                pMobIndex->affected_by[count] = 0;
           }
        }
	    pMobIndex->pShop		= NULL;
	    pMobIndex->alignment		= fread_number( fp, &stat );
	    letter				= fread_letter( fp );

	    if ( letter != 'S' )
	    {
		    // Fix for DurisEdit-format mobs, which have extra affect flags.
		    // This has been tested with durisEdit 2.99de.  YMMV.
		    pMobIndex->alignment = fread_number(fp, &stat);
		    letter = fread_letter (fp );
		    if( letter != 'S' )
		    {
			    bug( "load_magma_mobiles: vnum %d non-S.", vnum );
			    getchar();
	            exit( 1 );
		    }
		    duris_format = TRUE;
	    }

        race                            = fread_word( fp, &stat );

	    pMobIndex->race = race_key_lookup( race );
	    if ( pMobIndex->race < 0 )
	    {
	        sprintf( buf, "Load_magma_mobiles: vnum %d bad race key %s", vnum,
                         race );
            bug( buf, 0 );
	        pMobIndex->race = 0;
	    }

	    /* hometown not used */           fread_number( fp, &stat );
	    pMobIndex->c_class                = fread_number( fp, &stat );

        // This class_convert will not be necessary if we add
        // classes in the same order as they are in DE.
        // It'll make us load a lil faster - Veygoth
	    if( !duris_format )
		    pMobIndex->c_class = class_convert( pMobIndex->c_class );
	    else
		    pMobIndex->c_class = duris_class_convert( pMobIndex->c_class );

        switch( pMobIndex->c_class )
        {
            default:
                break;
            case CLASS_SHAMAN:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_shaman" );
                break;
            case CLASS_ELEMENT_AIR:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_air_ele" );
                break;
            case CLASS_ELEMENT_EARTH:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_earth_ele" );
                break;
            case CLASS_ELEMENT_FIRE:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_fire_ele" );
                break;
            case CLASS_ELEMENT_WATER:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_water_ele" );
                break;
            case CLASS_DRUID:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_druid" );
                break;
            case CLASS_RANGER:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_ranger" );
                break;
            case CLASS_HUNTER:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_hunter" );
                break;
            case CLASS_WARRIOR:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_warrior" );
                break;
            case CLASS_BARD:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_bard" );
                break;
            case CLASS_ILLUSIONIST:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_illusionist" );
                break;
            case CLASS_PALADIN:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_paladin" );
                break;
            case CLASS_ANTIPALADIN:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_antipaladin" );
                break;
            case CLASS_THIEF:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_thief" );
                break;
            case CLASS_MERCENARY:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_mercenary" );
                break;
            case CLASS_ASSASSIN:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_assassin" );
                break;
            case CLASS_CLERIC:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_cleric" );
                break;
            case CLASS_SORCERER:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_sorcerer" );
                break;
            case CLASS_PSIONICIST:
                pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_psionicist" );
                break;
        };

        // Assign race-based special functions.  Race functions take precedence over class
        // functions -- Veygoth
        if( pMobIndex->race == RACE_DRAGON )
        {
            if( !pMobIndex->spec_fun )
            {
                pMobIndex->spec_fun = get_breath_type( pMobIndex->player_name );
            }
            else
            {
                pMobIndex->spec_fun2 = pMobIndex->spec_fun;
                pMobIndex->spec_fun = get_breath_type( pMobIndex->player_name );
            }      
        }
        else if( pMobIndex->race == RACE_VAMPIRE )
        {
            if( !pMobIndex->spec_fun )
            {
              pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_vampire" );
            }
            else
            {
              pMobIndex->spec_fun2 = pMobIndex->spec_fun;
              pMobIndex->spec_fun = spec_mob_lookup( "spec_cast_vampire" );
            }      
        }

	    if( duris_format )
		    fread_number( fp, &stat ); /* Size in DurisEdit, not used in Basternae, not included in DikuEdit. */

	    pMobIndex->level		= fread_number( fp, &stat );
            /* Took number_fuzzy out of above line to store mob levels
               at a constant due to OLC resaving areas  --Stoked */

	    fread_number( fp, &stat );	/* Unused */
	    fread_number( fp, &stat );	/* Unused */
	    fread_word( fp, &stat );	/* 1d1+1 Unused */
	    fread_word( fp, &stat );	/* 1d1+1 Unused */
	    fread_word( fp, &stat );	/* 0.0.0.0 Unused */
	    fread_number( fp, &stat );	/* Unused */
	    pMobIndex->position 		= fread_number( fp, &stat );
            fread_number( fp, &stat );
	    pMobIndex->sex			= fread_number( fp, &stat );

	    // Convert positions from DE
        switch( pMobIndex->position )
        {
                default:
            	    pMobIndex->position = POS_STANDING;
		    break;
                case 4:
                    pMobIndex->position = POS_SLEEPING;
                    break;
                case 0:
                case 1:
                case 2:
                case 3:
                case 5:
            	    pMobIndex->position = POS_RESTING;
		    break;
                case 6:
            	    pMobIndex->position = POS_SITTING;
		    break;
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
            	    pMobIndex->position = POS_STANDING;
		    break;
                case 13:
            	    pMobIndex->position = POS_RECLINING;
		    break;
	    }

        letter = fread_letter( fp );
        if ( letter == '>' )
        {
          bug( "Don't use the > for mobprograms - we want them in a separate file in the mobprog directory.", 0 );
          ungetc( letter, fp );
        }
        else ungetc( letter,fp );

	    iHash = vnum % MAX_KEY_HASH;
	    pMobIndex->next = mob_index_hash[iHash];
	    mob_index_hash[iHash] = pMobIndex;
	    top_mob_index++;
        top_vnum_mob = top_vnum_mob < vnum ? vnum : top_vnum_mob;
        assign_area_vnum( vnum );
    }

    return;
}

void load_magma_objects( FILE *fp )
{
    int count;
    OBJ_INDEX_DATA *pObjIndex;
    OBJ_INDEX_DATA *duplicateObject = NULL;
    char buf[MAX_STRING_LENGTH]; // better error messages...

    if ( !area_last )
    {
        bug( "load_magma_objects: no #AREA seen yet.", 0 );
		getchar();
        exit( 1 );
    }

    for ( ; ; )
    {
	char  letter;
	int   vnum;
	int   iHash;
	int   stat;

	letter				= fread_letter( fp );
	if ( letter != '#' )
	{
	    bug( "load_magma_objects: # not found.", 0 );
		show_file_location(fp);
		getchar();
	    exit( 1 );
	}

	vnum				= fread_number( fp, &stat );
	if ( vnum == 0 )
	    break;

	fBootDb = FALSE;
	if ( (duplicateObject = get_obj_index( vnum )) )
	{
        sprintf( buf, "load_magma_objects: index number %d already in use by %s in zone %s.", vnum, duplicateObject->name, duplicateObject->area->filename);
        bug( buf, 0 );
		getchar();
	    exit( 1 );
	}
	fBootDb = TRUE;

	pObjIndex			= alloc_perm( sizeof( *pObjIndex ) );
	pObjIndex->vnum			= vnum;

    for( count = 0; count < NUM_AFFECT_VECTORS; count++ )
    {
        pObjIndex->affected_by[count] = 0;
    }

	if ( !area_last->low_o_vnum )
	    area_last->low_o_vnum       = vnum;
	if ( vnum > area_last->hi_o_vnum )
	    area_last->hi_o_vnum        = vnum;

    pObjIndex->area                 = area_last;		/* OLC */
	pObjIndex->name			= fread_string( fp, &stat );
	pObjIndex->short_descr		= fread_string( fp, &stat );
	pObjIndex->description		= fread_string( fp, &stat );
	/* Action description */	  fread_string( fp, &stat );

	pObjIndex->short_descr[0]	= LOWER( pObjIndex->short_descr[0] );
	pObjIndex->description[0]	= UPPER( pObjIndex->description[0] );

	pObjIndex->item_type		= fread_number( fp, &stat );
    pObjIndex->material             = fread_number( fp, &stat );
    if( pObjIndex->material >= MAX_MATERIAL )
    {
        sprintf( buf, "Object %d has material type beyond maximum allowable value.", vnum );
        log_string( buf );
    }
	pObjIndex->size                 = fread_number( fp, &stat );
	pObjIndex->volume               = fread_number( fp, &stat );
	pObjIndex->craftsmanship        = fread_number( fp, &stat );
	// Damage resistance bonus not used, may not be - Veygoth
	/* damage resistance bonus */     fread_number( fp, &stat );
	pObjIndex->extra_flags[0]	= fread_number( fp, &stat );
	pObjIndex->wear_flags		= fread_number( fp, &stat );
	pObjIndex->extra_flags[1]	= fread_number( fp, &stat );
    pObjIndex->anti_flags           = fread_number( fp, &stat );
    pObjIndex->anti_flags2          = fread_number( fp, &stat );
	pObjIndex->value[0]             = fread_number( fp, &stat );
	pObjIndex->value[1]             = fread_number( fp, &stat );
	pObjIndex->value[2]             = fread_number( fp, &stat );
	pObjIndex->value[3]             = fread_number( fp, &stat );
	pObjIndex->value[4]             = fread_number( fp, &stat );
	pObjIndex->value[5]             = fread_number( fp, &stat );
	pObjIndex->value[6]             = fread_number( fp, &stat );
	pObjIndex->value[7]             = fread_number( fp, &stat );
	pObjIndex->weight		= fread_number( fp, &stat );
	pObjIndex->cost			= fread_number( fp, &stat );
    pObjIndex->trap                 = NULL;
    if( pObjIndex->cost <= 1 )
        set_cost( pObjIndex );
    pObjIndex->condition            = fread_number( fp, &stat );
	if( pObjIndex->condition != 100 )
	{
		fprintf(stderr, "Warning: object %d - '%s' has a condition not equal to 100 (%d). This could be a read error.\n", 
            pObjIndex->vnum, pObjIndex->short_descr, pObjIndex->condition);
	}

        // convert area to Magma format - Veygoth
             if( pObjIndex->size == 3)
                 pObjIndex->size = 4;
        else if( pObjIndex->size == 4)
                 pObjIndex->size = 6;
        else if( pObjIndex->size == 5)
                 pObjIndex->size = 8;
        else if( pObjIndex->size == 6)
                 pObjIndex->size = 7;
        else if( pObjIndex->size == 7)
                 pObjIndex->size = 10;
        else if( pObjIndex->size == 8)
                 pObjIndex->size = 3;
        else if( pObjIndex->size == 9)
                 pObjIndex->size = 5;
        else if( pObjIndex->size == 10)
                 pObjIndex->size = 0;
        else if( pObjIndex->size == 0)
                 pObjIndex->size = 11;

        if( pObjIndex->item_type == TYPE_WEAPON && pObjIndex->value[3] == 0 )
            bug( "Object vnum %d: object type weapon with no damage type specified", vnum );
	    
	for ( ; ; )
	{
	    char letter;

	    letter = fread_letter( fp );

	    if ( letter == 'A' )
	    {
		AFFECT_DATA *paf;

		paf			= alloc_perm( sizeof( *paf ) );
		paf->skill		= -1;
		paf->spell		= -1;
		paf->song		= -1;
		paf->duration		= -1;
		paf->location		= fread_number( fp, &stat );
		paf->modifier		= fread_number( fp, &stat );
		memset(paf->bitvector, 0, (sizeof(int)*NUM_AFFECT_VECTORS));
		paf->next		= pObjIndex->affected;
		pObjIndex->affected	= paf;
		top_affect++;
	    }

	    else if ( letter == 'E' )
	    {
		EXTRA_DESCR_DATA *ed;

		ed			= alloc_perm( sizeof( *ed ) );
		ed->keyword		= fread_string( fp, &stat );
		ed->description		= fread_string( fp, &stat );
		ed->next		= pObjIndex->extra_descr;
		pObjIndex->extra_descr	= ed;
		top_ed++;
	    }

            else if( letter == 'T' )
            {
                pObjIndex->trap = alloc_perm( sizeof( TRAP_DATA ));
                top_trap++;
                pObjIndex->trap->trigger = fread_number( fp, &stat );
                pObjIndex->trap->damage = fread_number( fp, &stat );
                if( pObjIndex->trap->damage >= MAX_TRAP )
                  bug( "Trap with damage type %d greater than max.", pObjIndex->trap->damage );
                pObjIndex->trap->charges = fread_number( fp, &stat );
                pObjIndex->trap->level = fread_number( fp, &stat );
                if( pObjIndex->trap->level > 100 )
                  bug( "Trap with level %d greater than 100.", pObjIndex->trap->level );
                letter = getc( fp );
		        ungetc( letter, fp );
                if( char_is_number( letter ))
                {
                  pObjIndex->trap->percent = fread_number( fp, &stat );
                }
                else
                  pObjIndex->trap->percent = 100;
            }

	    else if( letter == '#' )
	    {
		ungetc( letter, fp );
		break;
	    }
	    else
	    {
                // Currently ignoring affect bits on objects - Veygoth
		ungetc( letter, fp );
                pObjIndex->affected_by[0] = fread_number( fp, &stat );
                pObjIndex->affected_by[1] = fread_number( fp, &stat );
                pObjIndex->affected_by[2] = fread_number( fp, &stat );
                pObjIndex->affected_by[3] = fread_number( fp, &stat );
	    }
	}

	/*
	 * Translate character strings *value[] into integers:  sn's for
	 * items with spells, or straight conversion for other items.
	 */
	switch ( pObjIndex->item_type )
	{
	default:
	    break;

	case TYPE_PILL:
	case TYPE_POTION:
	case TYPE_SCROLL:
    case TYPE_HERB:
	  pObjIndex->value[1] = magma_spell_lookup( pObjIndex->value[1] );
	  pObjIndex->value[2] = magma_spell_lookup( pObjIndex->value[2] );
	  pObjIndex->value[3] = magma_spell_lookup( pObjIndex->value[3] );
	  pObjIndex->value[4] = magma_spell_lookup( pObjIndex->value[4] );
	    break;

	case TYPE_STAFF:
	case TYPE_WAND:
          pObjIndex->value[3] = magma_spell_lookup( pObjIndex->value[3] );
	    break;
	}

	iHash			= vnum % MAX_KEY_HASH;
	pObjIndex->next		= obj_index_hash[iHash];
	obj_index_hash[iHash]	= pObjIndex;

	top_obj_index++;
        top_vnum_obj = top_vnum_obj < vnum ? vnum : top_vnum_obj;
        assign_area_vnum( vnum );
    }

    return;
}

// Veygoth - this function is supposed to reference the spell number
// used in DE to the spell used in Magma.  Currently it does not do
// anything but place an annoying message in the log file.
int magma_spell_lookup( int skill )
{
   switch ( skill )
   {
      default:
		  fprintf( stderr, "Magic item with unrecognized spell %d disabled in %s.\n", skill, area_last->filename );
          return 0;
          break;
      case -1:
      case 0:
          return 0;
          break;
      case 1:
          return spl_armor;
          break;
      case 2:
          return spl_teleport;
          break;
      case 3:
          return spl_bless;
          break;
      case 4:
          return spl_blindness;
          break;
      case 5:
          return spl_burning_hands;
          break;
      case 7:
          return spl_charm_person;
          break;
      case 8:
          return spl_chill_touch;
          break;
      case 9:
          return spl_fullheal;
          break;
      case 10:
          return spl_cone_of_cold;
          break;
      case 14:
          return spl_cure_blind;
          break;
      case 15:
          return spl_cure_critical;
          break;
      case 16:
          return spl_cure_light;
          break;
      case 17:
          return spl_curse;
          break;
      case 18:
          return spl_continual_light;
          break;
      case 19:
          return spl_detect_invis;
          break;
      case 20:
          return spl_minor_creation;
          break;
      case 21:
          return spl_flamestrike;
          break;
      case 22:
          return spl_dispel_evil;
          break;
      case 23:
          return spl_earthquake;
          break;
      case 25:
          return spl_energy_drain;
          break;
      case 26:
          return spl_fireball;
          break;
      case 27:
          return spl_harm;
          break;
      case 28:
          return spl_heal;
          break;
      case 29:
          return spl_invis;
          break;
      case 30:
          return spl_lightning_bolt;
          break;
      case 31:
          return spl_locate_object;
          break;
      case 32:
          return spl_magic_missile;
          break;
      case 33:
          return spl_poison;
          break;
      case 34:
          return spl_prot_evil;
          break;
      case 35:
          return spl_remove_curse;
          break;
      case 36:
          return spl_stoneskin;
          break;
      case 37:
          return spl_shocking_grasp;
          break;
      case 38:
          return spl_sleep;
          break;
      case 39:
          return spl_giant_strength;
          break;
      case 41:
          return spl_haste;
          break;
      case 43:
          return spl_remove_poison;
          break;
      case 44:
          return spl_sense_life;
          break;
      case 45:
          return spl_identify;
          break;
      case 47:
          return spl_firestorm;
          break;
      case 50:
          return spl_frost_breath;
          break;
      case 54:
          return spl_fear;
          break;
      case 56:
          return spl_vitality;
          break;
      case 57:
          return spl_cure_serious;
          break;
      case 61:
          return spl_minor_globe;
          break;
      case 64:
          return spl_vig_light;
          break;
      case 65:
          return spl_vig_serious;
          break;
      case 66:
          return spl_vig_critical;
          break;
      case 71:
          return spl_enfeeblement;
          break;
      case 72:
          return spl_dispel_good;
          break;
      case 73:
          return spl_dexterity;
          break;
      case 75:
          return spl_aging;
          break;
      case 76:
          return spl_cyclone;
          break;
      case 79:
          return spl_vitalize_mana;
          break;
      case 81:
          return spl_protection_good;
          break;
      case 82:
          return spl_animate_dead;
          break;
      case 83:
          return spl_levitation;
          break;
      case 84:
          return spl_fly;
          break;
      case 85:
          return spl_water_breathing;
          break;
      case 87:
          return spl_gate;
          break;
      case 90:
          return spl_detect_evil;
          break;
      case 91:
          return spl_detect_good;
          break;
      case 92:
          return spl_detect_magic;
          break;
      case 93:
          return spl_dispel_magic;
          break;
      case 95:
          return spl_mass_invis;
          break;
      case 96:
          return spl_protect_fire;
          break;
      case 97:
          return spl_protect_cold;
          break;
      case 98:
          return spl_protect_lightning;
          break;
      case 99:
          return spl_darkness;
          break;
      case 100:
          return spl_minor_para;
          break;
      case 102:
          return spl_slowness;
          break;
      case 103:
          return spl_wither;
          break;
      case 104:
          return spl_protect_gas;
          break;
      case 105:
          return spl_protect_acid;
          break;
      case 106:
          return spl_infravision;
          break;
      case 107:
          return spl_prismatic_spray;
          break;
      case 108:
          return spl_flame_shield;
          break;
      case 109:
          return spl_color_spray;
          break;
      case 110:
          return spl_incendiary_cloud;
          break;
      case 111:
          return spl_ice_storm;
          break;
      case 112:
          return spl_disintegrate;
          break;
      case 113:
          return spl_cause_light;
          break;
      case 114:
          return spl_cause_serious;
          break;
      case 115:
          return spl_cause_critical;
          break;
      case 116:
          return spl_acid_blast;
          break;
      case 124:
          return spl_sunray;
          break;
      case 126:
          return spl_feeblemind;
          break;
      case 127:
          return spl_silence;
          break;
      case 128:
          return spl_turn_undead;
          break;
      case 131:
          return spl_frost_shield;
          break;
      case 134:
          return spl_vampiric_touch;
          break;
      case 136:
          return spl_prot_from_undead;
          break;
      case 141:
          return spl_barkskin;
          break;
      case 144:
          return spl_major_globe;
          break;
      case 145:
          return spl_embalm;
          break;
      case 147:
          return spl_shadow_breath2;
          break;
      case 156:
          return spl_agitation;
          break;
      case 157:
          return spl_adrenaline_control;
          break;
      case 160:
          return spl_ballistic_attack;
          break;
      case 163:
          return spl_combat_mind;
          break;
      case 170:
          return spl_domination;
          break;
      case 172:
          return spl_ego_whip;
          break;
      case 179:
          return spl_flesh_armor;
          break;
      case 180:
          return spl_inertial_barrier;
          break;
      case 181:
          return spl_inflict_pain;
          break;
      case 186:
          return spl_plague;
          break;
      case 188:
          return spl_soulshield;
          break;
      case 190:
          return spl_mass_heal;
          break;
      case 192:
          return spl_spirit_armor;
          break;
      case 197:
          return spl_pythonsting;
          break;
      case 201:
          return spl_panther;
          break;
      case 204:
          return spl_hawk;
          break;
      case 206:
          return spl_mending;
          break;
      case 212:
          return spl_malison;
          break;
      case 214:
          return spl_gr_mending;
          break;
      case 215:
          return spl_lion;
          break;
      case 221:
          return spl_elephant;
          break;
      case 223:
          return spl_scathing_wind;
          break;
      case 228:
          return spl_sustenance;
          break;
      case 234:
          return spl_ls_mending;
          break;
      case 236:
          return spl_true_seeing;
          break;
      case 238:
          return spl_ravenflight;
          break;
      case 248:
          return spl_enlarge;
          break;
      case 249:
          return spl_reduce;
          break;
      case 254:
          return spl_iceball;
          break;
      case 263:
          return spl_blur;
          break;
      case 268:
          return spl_raise_spectre;
          break;
      case 271:
          return spl_raise_lich;
          break;
      case 275:
          return spl_cure_disease;
          break;
      case 279:
          return spl_sense_followers;
          break;
      case 286:
          return spl_stornogs_spheres;
          break;
      case 300:
          return spl_alacrity;
          break;
      case 306:
          return spl_choke;
          break;
      case 330:
          return spl_mirage_arcana;
          break;
      case 332:
          return spl_hellfire;
          break;
   }
}

/*
 * Adds a reset to a room.  OLC
 * Similar to add_reset in olc.c
 */
void new_reset( ROOM_INDEX_DATA *pR, RESET_DATA *pReset )
{
    RESET_DATA *pr;

    if ( !pR )
       return;

    pr = pR->area->reset_last;

    if ( !pr )
    {
        pR->area->reset_first = pReset;
        pR->area->reset_last  = pReset;
    }
    else
    {
        pR->area->reset_last->next = pReset;
        pR->area->reset_last       = pReset;
        pR->area->reset_last->next = NULL;
    }

    top_reset++;
    return;
}


/*
 * Snarf a reset section.
 */
void load_resets( FILE *fp )
{
        char datas[2048];
    RESET_DATA *pReset;
    int         iLastRoom = 0;
    int         iLastObj  = 0;
    int		 stat;

    if ( !area_last )
    {
		bug( "load_resets: no #AREA seen yet.", 0 );
		getchar();
		exit( 1 );
    }

    for ( ; ; )
    {
	EXIT_DATA       *pexit;
	ROOM_INDEX_DATA *pRoomIndex;
	char             letter;

	if ( ( letter = fread_letter( fp ) ) == 'S' )
	    break;

	if ( letter == '*' )
	{
	    fread_to_eol( fp );
	    continue;
	}

	pReset		= alloc_perm( sizeof( *pReset ) );
	pReset->command	= letter;
	/* if_flag */	  fread_number( fp, &stat );
	pReset->arg1	= fread_number( fp, &stat );
	pReset->arg2	= fread_number( fp, &stat );
	pReset->arg3	= ( letter == 'G' || letter == 'R' )
			    ? 0 : fread_number( fp, &stat );
			  fread_to_eol( fp );
	pReset->arg4	= 0;
	pReset->arg5	= 0;
	pReset->arg6	= 0;
	pReset->arg7	= 0;

	/*
	 * Validate parameters.
	 * We're calling the index functions for the side effect.
	 */
	switch ( letter )
	{
	default:
	    bug( "Load_resets: bad command '%c'.", letter );
                sprintf( datas, "%d, %d, %d, %d, %d, %d, %d, %d",
                    pReset->arg0,
                    pReset->arg1,
                    pReset->arg2,
                    pReset->arg3,
                    pReset->arg4,
                    pReset->arg5,
                    pReset->arg6,
                    pReset->arg7
                    );
		getchar();
	    exit( 1 );
	    break;

        case 'M':
            get_mob_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( pReset->arg3 ) ) )
            {
                new_reset( pRoomIndex, pReset );
                iLastRoom = pReset->arg3;
            }
            break;

        case 'O':
            get_obj_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( pReset->arg3 ) ) )
            {
                new_reset( pRoomIndex, pReset );
                iLastObj = pReset->arg3;
            }
            break;

        case 'P':
            get_obj_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( iLastObj ) ) )
            {
                new_reset( pRoomIndex, pReset );
            }
            break;

        case 'G':
        case 'E':
            get_obj_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( iLastRoom ) ) )
            {
                new_reset( pRoomIndex, pReset );
                iLastObj = iLastRoom;
            }
            break;

        case 'D':
            pRoomIndex = get_room_index( pReset->arg1 );

            if (   pReset->arg2 < 0
                || pReset->arg2 >= MAX_DIR
                || !pRoomIndex
                || !( pexit = pRoomIndex->exit[pReset->arg2] )
                || !IS_SET( pexit->exit_info, EX_ISDOOR ) )
            {
                bug( "Load_resets: 'D': exit in direction %d is not a door.", pReset->arg2 );
            }

            switch ( pReset->arg3 )
            {
                default:
                    bug( "Load_resets: 'D': bad 'locks': %d." , pReset->arg3);
                case 0:
                    break;
                case 1: SET_BIT( pexit->exit_info, EX_CLOSED );
                    break;
                case 2: SET_BIT( pexit->exit_info, EX_CLOSED | EX_LOCKED );
                    break;
                case 4: SET_BIT( pexit->exit_info, EX_SECRET );
                    break;
                case 5: SET_BIT( pexit->exit_info, EX_SECRET | EX_CLOSED );
                    break;
                case 6: SET_BIT( pexit->exit_info, EX_SECRET | EX_CLOSED | EX_LOCKED );
                    break;
                case 8: SET_BIT( pexit->exit_info, EX_BLOCKED );
                    break;
                case 9: SET_BIT( pexit->exit_info, EX_BLOCKED | EX_CLOSED );
                    break;
                case 10: SET_BIT( pexit->exit_info, EX_BLOCKED | EX_CLOSED | EX_LOCKED );
                    break;
                case 12: SET_BIT( pexit->exit_info, EX_BLOCKED | EX_SECRET );
                    break;
                case 13: SET_BIT( pexit->exit_info, EX_BLOCKED | EX_SECRET | EX_CLOSED );
                    break;
                case 14: SET_BIT( pexit->exit_info, EX_BLOCKED | EX_SECRET | EX_CLOSED | EX_LOCKED );
                    break;
            }
            break;

        case 'R':
            if ( pReset->arg2 < 0 || pReset->arg2 > MAX_DIR ) /* Last Door. */
            {
                bug( "load_resets: 'R': bad exit %d.", pReset->arg2 );
				getchar();
                exit( 1 );
            }

            if ( ( pRoomIndex = get_room_index( pReset->arg1 ) ) )
                new_reset( pRoomIndex, pReset );

            break;
	}
    }

    return;
}

/*
 * Load a Magma style reset section - Veygoth.
 */
void load_magma_resets( FILE *fp )
{
        char datas[2048];
    RESET_DATA *pReset;
    int         iLastRoom = 0;
    int         iLastObj  = 0;
    int		 stat;

    if ( !area_last )
    {
		bug( "load_magma_resets: no #AREA seen yet.", 0 );
		getchar();
		exit( 1 );
    }

    // Ignore all Magma area header stuff...
    fread_word( fp, &stat );
    fread_string( fp, &stat);
    fread_number( fp, &stat);    
    area_last->resetmode = fread_number( fp, &stat); // this is the area's reset mode    
    fread_number( fp, &stat);    
    area_last->llifespan = fread_number( fp, &stat) / 5; // lower range of reset time
    area_last->ulifespan = fread_number( fp, &stat) / 5;
    fread_number( fp, &stat);    

    for ( ; ; )
    {
	EXIT_DATA       *pexit;
	ROOM_INDEX_DATA *pRoomIndex;
	char             letter;

	if ( ( letter = fread_letter( fp ) ) == 'S' )
	    break;

	if ( letter == '*' )
	{
	    fread_to_eol( fp );
	    continue;
	}

	pReset		= alloc_perm( sizeof( *pReset ) );
	pReset->command	= letter;
	/* if_flag 	  fread_number( fp, &stat ); */
	pReset->arg0	= fread_number( fp, &stat );
	pReset->arg1	= fread_number( fp, &stat );
	pReset->arg2	= fread_number( fp, &stat );
	pReset->arg3	= fread_number( fp, &stat );
	pReset->arg4    = fread_number( fp, &stat );
	pReset->arg5	= fread_number( fp, &stat );
	pReset->arg6	= fread_number( fp, &stat );
	pReset->arg7	= fread_number( fp, &stat );
			  fread_to_eol( fp );

	/*
	 * Validate parameters.
	 * We're calling the index functions for the side effect.
	 */
	switch ( letter )
	{
	default:
	    bug( "Load_magma_resets: bad command '%c'.", letter );
                sprintf( datas, "%d, %d, %d, %d, %d, %d, %d, %d",
                    pReset->arg0,
                    pReset->arg1,
                    pReset->arg2,
                    pReset->arg3,
                    pReset->arg4,
                    pReset->arg5,
                    pReset->arg6,
                    pReset->arg7 );
		getchar();
	    exit( 1 );
	    break;

        case 'M':
            get_mob_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( pReset->arg3 ) ) )
            {
                new_reset( pRoomIndex, pReset );
                iLastRoom = pReset->arg3;
            }
            break;

        case 'F':
            get_mob_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( pReset->arg3 ) ) )
            {
                new_reset( pRoomIndex, pReset );
                iLastRoom = pReset->arg3;
            }
            break;

        case 'O':
            get_obj_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( pReset->arg3 ) ) )
            {
                new_reset( pRoomIndex, pReset );
                iLastObj = pReset->arg3;
            }
            break;

        case 'P':
            get_obj_index  ( pReset->arg1 );
            if ( ( pRoomIndex = get_room_index ( iLastObj ) ) )
            {
                pReset->arg5 = pRoomIndex->vnum;
                new_reset( pRoomIndex, pReset );
            }
            break;

        case 'G':
        case 'E':
            if( get_obj_index  ( pReset->arg1 ) == NULL )
            {
                bug("Object %d was not found when trying to equip a mob with it.", pReset->arg1 );
            }
            if ( ( pRoomIndex = get_room_index ( iLastRoom ) ) )
            {
                pReset->arg3 = pRoomIndex->vnum;
                new_reset( pRoomIndex, pReset );
                iLastObj = iLastRoom;
            }
            break;

        case 'D':
            pRoomIndex = get_room_index( pReset->arg1 );

            if( !pRoomIndex )
               log_string( "Nonexistant room index for door." );

            if (   pReset->arg2 < 0
                || pReset->arg2 >= MAX_DIR
                || !pRoomIndex
                || !( pexit = pRoomIndex->exit[pReset->arg2] )
                || !IS_SET( pexit->exit_info, EX_ISDOOR ) )
            {
                char buf3[300];
                memset( buf3, 0, 300 );
                sprintf( buf3, "Load_resets: exit in room %d direction %d is not a door.  Flags are %d.", pReset->arg1, pReset->arg2, pexit->exit_info );
                log_string( buf3 );
            }
            break;

        case 'R':
	    if (pReset->arg0 == 1)
	    { // If this is a ridden mob ..
                get_mob_index  ( pReset->arg1 );
                if ( ( pRoomIndex = get_room_index ( pReset->arg3 ) ) )
                {
		    pReset->command = 'M';
		    pReset->arg0    = -1;
                    new_reset( pRoomIndex, pReset );
                    iLastRoom = pReset->arg3;
//		    bug (" Ridden mob %d should be loaded.", pReset->arg1);
                }
		else
		    bug ("Ridden mob not loaded: No room %d.", pReset->arg3);
	    }
	    else
	    { // Otherwise ..
                if ( pReset->arg2 < 0 || pReset->arg2 > MAX_DIR ) /* Last Door. */
            	{
                    bug( "load_magma_resets: 'R' bad exit %d.", pReset->arg2 );
					getchar();
                    exit( 1 );
            	}
                if ( ( pRoomIndex = get_room_index( pReset->arg1 ) ) )
                    new_reset( pRoomIndex, pReset );
	    }
            break;
	}
    }

    return;
}

// Loads Magma style room sections.  Only difference from 
// new_load_rooms is that new_load_rooms automatically converts
// the sector type from Envy zones to Magma zones - Veygoth
void load_magma_rooms( FILE *fp )
{
    ROOM_INDEX_DATA *pRoomIndex;
    ROOM_INDEX_DATA *duplicateRoom = NULL;
    char buf[MAX_STRING_LENGTH];
    int iHash;

    if ( !area_last )
    {
        bug( "load_magma_rooms: no #AREA seen yet.", 0 );
		getchar();
        exit( 1 );
    }

    for ( ; ; )
    {
        char letter;
        int  vnum;
        int  door;
        int  stat;

        letter                          = fread_letter( fp );
        if ( letter != '#' )
        {
            bug( "load_magma_rooms: # not found.", 0 );
			show_file_location(fp);
			getchar();
            exit( 1 );
        }

        vnum                            = fread_number( fp, &stat );
        if ( vnum == 0 )
            break;

        fBootDb = FALSE;
        if ( (duplicateRoom = get_room_index( vnum )) )
        {
            sprintf( buf, "load_magma_rooms: index number %d already in use by %s in zone %s.", vnum, duplicateRoom->name, duplicateRoom->area->filename);
            bug( buf, 0 );
            getchar();
            exit( 1 );
        }
        fBootDb = TRUE;

        pRoomIndex                      = alloc_perm( sizeof( *pRoomIndex ) );
        pRoomIndex->people              = NULL;
        pRoomIndex->contents            = NULL;
        pRoomIndex->extra_descr         = NULL;
        pRoomIndex->area                = area_last;
        pRoomIndex->vnum                = vnum;
	if ( !area_last->low_r_vnum )
	    area_last->low_r_vnum       = vnum;
	if ( vnum > area_last->hi_r_vnum )
	    area_last->hi_r_vnum        = vnum;

        pRoomIndex->name                = fread_string( fp, &stat );
        pRoomIndex->description         = fread_string( fp, &stat );
        /* This value was originally area number, but is now used for terrain
           description generation with maps -- Veygoth  */
        pRoomIndex->extra_sector_info   = fread_number( fp, &stat );
        pRoomIndex->room_flags[0]       = fread_number( fp, &stat );
        pRoomIndex->room_flags[1]       = 0;
	pRoomIndex->orig_room_flags	= pRoomIndex->room_flags[0];      /* OLC */
        pRoomIndex->sector_type         = fread_number( fp, &stat );
        pRoomIndex->light               = 0;
        for ( door = 0; door < MAX_DIR; door++ )
            pRoomIndex->exit[door] = NULL;

        for ( ; ; )
        {
            letter = fread_letter( fp );

            if ( letter == 'S' || letter == 's' )
            {
                if ( letter == 's' )
                    bug( "Load_rooms: vnum %d has lowercase 's'", vnum );
                break;
            }

            if ( letter == 'D' )
            {
                EXIT_DATA *pexit;
                int        locks;

                door = fread_number( fp, &stat );
                if ( door < 0 || door >= MAX_DIR )
                {
                    bug( "load_magma_rooms: vnum %d has bad door number.", vnum );
					getchar();
                    exit( 1 );
                }

                pexit                   = alloc_perm( sizeof( *pexit ) );
                pexit->description      = fread_string( fp, &stat );
                pexit->keyword          = fread_string( fp, &stat );
                locks                   = fread_number( fp, &stat );
                // convert exits - Veygoth
                switch( locks )
                {
                  case 0:
                    pexit->exit_info = 0;
                    break;
                  case 1:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED;
                    break;
                  case 2:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED;
                    break;
                  case 3:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
                                       EX_BASHPROOF | EX_PICKPROOF;
                    break;
                  case 4:
                    pexit->exit_info = EX_ISDOOR | EX_SECRET;
                    break;
                  case 5:
                    pexit->exit_info = EX_SECRET | EX_ISDOOR | EX_CLOSED;
                    break;
                  case 6:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
                                       EX_SECRET;
                    break;
                  case 7:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
                                       EX_BASHPROOF | EX_PICKPROOF |
                                       EX_SECRET;
                    break;
                  case 8:
                    pexit->exit_info = EX_BLOCKED | EX_ISDOOR;
                    break;
                  case 9:
                    pexit->exit_info = EX_BLOCKED | EX_ISDOOR | EX_CLOSED;
                    break;
                  case 10:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
                                       EX_BLOCKED;
                    break;
                  case 11:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
                                       EX_BASHPROOF | EX_PICKPROOF |
                                       EX_BLOCKED;
                    break;
                  case 12:
                    pexit->exit_info = EX_ISDOOR | EX_BLOCKED | EX_SECRET;
                    break;
                  case 13:
                    pexit->exit_info = EX_SECRET | EX_ISDOOR | EX_CLOSED |
                                       EX_BLOCKED;
                    break;
                  case 14:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
                                       EX_SECRET | EX_BLOCKED;
                    break;
                  case 15:
                    pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
                                       EX_BASHPROOF | EX_PICKPROOF |
                                       EX_SECRET | EX_BLOCKED;
                    break;
                  default:
                    bug( "The MUD does not understand an exits value of %d.  Defaulting to generic closed door.", locks );
                    pexit->exit_info = EX_ISDOOR;
                    break;
                };

                pexit->key              = fread_number( fp, &stat );
                pexit->vnum             = fread_number( fp, &stat );


                pRoomIndex->exit[door]          = pexit;
                top_exit++;
            }
            else if ( letter == 'E' )
            {
                EXTRA_DESCR_DATA *ed;

                ed                      = alloc_perm( sizeof( *ed ) );
                ed->keyword             = fread_string( fp, &stat );
                ed->description         = fread_string( fp, &stat );
                ed->next                = pRoomIndex->extra_descr;
                pRoomIndex->extra_descr = ed;
                top_ed++;
            }
            // Fall chance - Veygoth
            else if ( letter == 'F' )
            {
                pRoomIndex->fall_chance  = fread_number( fp, &stat );
            }
            // Current not yet used, values discarded - Veygoth
            else if ( letter == 'C' )
            {
                pRoomIndex->current = fread_number( fp, &stat );
                pRoomIndex->current_dir = fread_number( fp, &stat );
            }
            // Mana not yet used, values discarded - Veygoth
            else if ( letter == 'M' )
            {
                fread_number( fp, &stat );
                fread_number( fp, &stat );
            }
            else
            {
                bug( "load_magma_rooms: vnum %d has flag not 'DES'.", vnum );
				getchar();
                exit( 1 );
            }
        }

        iHash                   = vnum % MAX_KEY_HASH;
        pRoomIndex->next        = room_index_hash[iHash];
        room_index_hash[iHash]  = pRoomIndex;
        top_room++;
        top_vnum_room = top_vnum_room < vnum ? vnum : top_vnum_room;
        assign_area_vnum( vnum );
    }

    return;
}

/*
 * Load a Magma format shop section - Veygoth.
 */
void load_magma_shops( FILE *fp )
{
    SHOP_DATA *pShop;
    int        keeper = 0;

    for ( ; ; )
    {
		MOB_INDEX_DATA *pMobIndex;
		int             iTrade;
		int             stat;
        char            letter;
        int             count;

        letter = fread_letter( fp );
        if( letter != '#' )
        {
            bug( "load_magma_shops: # not found before vnum", 0 );
			show_file_location(fp);
        }
        keeper = fread_number( fp, &stat );
        letter = fread_letter( fp );
        if( letter != '~' )
        {
            bug( "Load shops: ~ not found after vnum", 0 );
			show_file_location(fp);
        }
        letter                  = fread_letter( fp );
        if( letter == 'S' )
           return;
        else if( letter != 'N' )
        {
           bug( "Shop section: Letter 'N' not found after shop vnum", 0 );
        }
	if ( keeper == 0 )
	    break;
	pShop			= alloc_perm( sizeof( *pShop ) );
	pShop->keeper		= keeper;
        for( count = 0; count < MAX_SELL; count++ )
        {
           pShop->sell_item[count] = fread_number( fp, &stat );
           if( pShop->sell_item[count] == 0)
               break;
        }

	pShop->profit_sell	= fread_number( fp, &stat ) * 100;
        letter = fread_letter( fp );
        if( letter != '.' )
           bug( "Expecting decimal point in shop profit_sell value", 0);
        pShop->profit_sell       += fread_number( fp, &stat );

	pShop->profit_buy	= fread_number( fp, &stat ) * 100;
        letter = fread_letter( fp );
        if( letter != '.' )
           bug( "Expecting decimal point in shop profit_buy value", 0);
        pShop->profit_buy       += fread_number( fp, &stat );

	for ( iTrade = 0; iTrade < MAX_BUY; iTrade++ )
        {
	    pShop->buy_type[iTrade] = fread_number( fp, &stat );
            if( pShop->buy_type[iTrade] == 0 )
               break;
        }
        // discard seven message strings
        fread_string( fp, &stat );
        fread_string( fp, &stat );
        fread_string( fp, &stat );
        fread_string( fp, &stat );
        fread_string( fp, &stat );
        fread_string( fp, &stat );
        fread_string( fp, &stat );
        // discard two numbers
        fread_number( fp, &stat );
        fread_number( fp, &stat );
	/*discard*/               fread_number( fp, &stat );
        fread_number( fp, &stat );
        // room vnum of shop discarded
        fread_number( fp, &stat );
	pShop->open_hour	= fread_number( fp, &stat );
	pShop->close_hour	= fread_number( fp, &stat );
        // discard second open and close times
        fread_number( fp, &stat);
        fread_number( fp, &stat);
        // discard racist, roam, and killable flags
        fread_letter( fp );
        fread_letter( fp );
        fread_letter( fp );
        // discard open and close messages
        fread_string( fp, &stat );
        fread_string( fp, &stat );
        // discard the rest of the junk
        fread_number( fp, &stat );
        fread_number( fp, &stat );
        fread_letter( fp );
        fread_number( fp, &stat );
        fread_string( fp, &stat );
        // end of the shop
        letter = fread_letter( fp );
        if( letter != 'X')
        {
           bug( "Letter 'X' not found at end of shop section", 0 );
        }
	fread_to_eol( fp );
	pMobIndex		= get_mob_index( pShop->keeper );
	pMobIndex->pShop	= pShop;

	if ( !shop_first )
	    shop_first = pShop;
	if (  shop_last  )
	    shop_last->next = pShop;

	shop_last	= pShop;
	pShop->next	= NULL;
    pShop->area = area_last;
	top_shop++;
    }

    return;
}

// Loads a #QUESTS section.  Quest data must remain in a certain order
// (that which is created by DikuEdit) in order to load properly
// -- Veygoth
void load_quests( FILE *fp )
{
    QUEST_INDEX_DATA *quest;
    QUEST_DATA *qdata;
    QUEST_ITEM *qitem;
    TALK_DATA *message;
    bool log = FALSE;

    if ( !area_last )
    {
      bug( "load_quests: no #AREA seen yet.", 0 );
	  getchar();
      exit( 1 );
    }

    for ( ; ; )
    {
      char letter;
      int  vnum;
      int  stat;

      letter                          = fread_letter( fp );
      if ( letter != '#' )
      {
          bug( "load_quests: # not found.", 0 );
		  show_file_location(fp);
		  getchar();
          exit( 1 );
      }

      vnum                            = fread_number( fp, &stat );
      if ( vnum == 0 )
          break;

      if( log ) log_string( "Valid quest vnum found." );

      quest = create_quest( );
      quest->area = area_last;
      quest->vnum = vnum;

      for( ; ; )
      {
        letter                          = fread_letter( fp );
        
        if( letter == 'M' )
        {
           if( log ) log_string( "Message found" );
           if( !quest )
           {
              bug( "Error in load_quests:  message data seen before quest vnum.", 0 );
			  getchar();
              exit( 1 );
           }
           message = create_quest_message( );
           message->keywords = fread_string( fp, &stat );
           message->message = fread_string( fp, &stat );
           message->next = quest->messages;
           quest->messages = message;
        }
        else if( letter == 'Q' )
        {
           if( log ) log_string( "Quest data found" );
           if( !quest )
           {
              bug( "Error in load_quests:  quest data seen before quest vnum.", 0 );
			  getchar();
              exit( 1 );
           }
           qdata = create_quest_data( );
           qdata->complete = fread_string( fp, &stat );
           qdata->next = quest->quests;
           quest->quests = qdata;
        }
        else if( letter == 'R' )
        {
           if( log ) log_string( "Receive item found" );
           if( !quest )
           {
              bug( "Error in load_quests:  receive item data seen before quest vnum.", 0 );
			  getchar();
              exit( 1 );
           }
           if( !quest->quests )
           {
              bug( "Error in load_quests:  receive item data seen before quest data.", 0 );
			  getchar();
              exit( 1 );
           }
           qitem = create_quest_item( );
           letter = fread_letter( fp );
           switch( letter )
           {
             case 'I':
               qitem->type = 0;
               break;
             case 'C':
               qitem->type = 1;
               break;
             case 'E':
               qitem->type = 2;
               break;
             case 'S':
               qitem->type = 3;
               break;
             case 'P':
               // Receive a pet.
               qitem->type = 8;
               break;
             default:
                 bug( "load_quests: Quest Item data:  Invalid Give type %c!", letter );
               break;
           }
           qitem->value = fread_number( fp, &stat );
           qitem->next = quest->quests->give;
           quest->quests->give = qitem;
        }
        else if( letter == 'G' )
        {
           if( log ) log_string( "Give item found" );
           if( !quest )
           {
              bug( "Error in load_quests:  give item data seen before quest vnum.", 0 );
			  getchar();
              exit( 1 );
           }
           if( !quest->quests )
           {
              bug( "Error in load_quests:  give item data seen before quest data.", 0 );
			  getchar();
              exit( 1 );
           }
           qitem = create_quest_item( );
           letter = fread_letter( fp );
           switch( letter )
           {
             case 'I':
               qitem->type = 0;
               break;
             case 'C':
               qitem->type = 1;
               break;
             case 'T':
               qitem->type = 2;
               break;
             default:
                 bug( "load_quests: Quest Item data:  Invalid Give type %c!", letter );
               break;
           }
           qitem->value = fread_number( fp, &stat );
           qitem->next = quest->quests->receive;
           quest->quests->receive = qitem;
        }
        else if( letter == 'S' )
        {
           if( log ) log_string( "End of quest found" );
           // reset everything so we get proper error messages:
           quest = NULL;
           qdata = NULL;
           qitem = NULL;
           message = NULL;
           break;
        }
        else if( letter == 'D' )
        {
           if( log ) log_string( "Disappearance Message found" );
           if( !quest )
           {
              bug( "Error in load_quests:  disappear message seen before quest vnum.", 0 );
			  getchar();
              exit( 1 );
           }
           if( !quest->quests )
           {
              bug( "Error in load_quests:  disappear message seen before quest data.", 0 );
			  getchar();
              exit( 1 );
           }
           quest->quests->disappear = fread_string( fp, &stat );
        }
      }
    }

    return;
}


/*
 * Snarf spec proc declarations.
 */
void load_specials( FILE *fp )
{
    for ( ; ; )
    {
	MOB_INDEX_DATA *pMobIndex;
	OBJ_INDEX_DATA *pObjIndex;
	char letter;
    char * specword;
	int stat;

	switch ( letter = fread_letter( fp ) )
	{
		default:
			bug( "load_specials: letter '%c' not *OMSD.", letter );
			show_file_location(fp);
			getchar();
			exit( 1 );

		case 'S':
			return;

		case '*':
			break;

		case 'M':
			pMobIndex = get_mob_index( fread_number ( fp, &stat ) );
			if( pMobIndex->spec_fun )
			{
			   if( pMobIndex->spec_fun2 )
				   bug( "Mob being assigned a third special function. Class function negated.\r\n", 0 );
			   pMobIndex->spec_fun2 = pMobIndex->spec_fun;
			}
			specword = fread_word( fp, &stat ) ;
			pMobIndex->spec_fun = spec_mob_lookup(specword );
			if ( pMobIndex->spec_fun == 0 )
			{
				fprintf(stderr, "load_specials: 'M': vnum %d.  Special '%s' not found, cannot apply to mob in %s.\n",
                    pMobIndex->vnum, specword, pMobIndex->area->filename);
			}
			break;

		case 'D':
			pMobIndex = get_mob_index( fread_number ( fp, &stat ) );
			if( pMobIndex->death_fun )
			   bug( "Mob being assigned a third special function. Class function negated.\r\n", 0 );
			specword = fread_word( fp, &stat ) ;
			pMobIndex->death_fun = spec_mob_lookup( specword );
			if ( pMobIndex->death_fun == 0 )
			{
				fprintf(stderr, "load_specials: 'D': vnum %d.  Death function '%s' not found, cannot apply to mob in %s.\n",
                    pMobIndex->vnum, specword, pMobIndex->area->filename );
			}
			break;

		case 'O':
			pObjIndex = get_obj_index  ( fread_number( fp, &stat ) );
			specword = fread_word( fp, &stat ) ;
			pObjIndex->spec_fun = spec_obj_lookup( specword );
			if ( pObjIndex->spec_fun == 0 )
			{
				fprintf(stderr, "load_specials: 'O': vnum %d.  Object special '%s' not found, cannot apply to obj in %s.\n",
                    pObjIndex->vnum, specword, pObjIndex->area->filename);
			}
			break;
		}

		fread_to_eol( fp );
    }
}

/*
 * Translate all room exits from virtual to real.
 * Has to be done after all rooms are read in.
 * Check for bad or suspicious reverse exits.
 */
void fix_exits( void )
{
		 EXIT_DATA       *pexit;
		 EXIT_DATA       *pexit_rev;
		 ROOM_INDEX_DATA *pRoomIndex;
		 ROOM_INDEX_DATA *to_room;
//                 char             buf     [ MAX_STRING_LENGTH ];
    extern const int              rev_dir [ ];
		 int              door;
                 int              iHash;

        for( iHash = 0; iHash < MAX_KEY_HASH; iHash++ )
        {
	for ( pRoomIndex  = room_index_hash[iHash];
	      pRoomIndex;
	      pRoomIndex  = pRoomIndex->next )
	{
	    bool fexit;

	    fexit = FALSE;
	    for ( door = 0; door < MAX_DIR; door++ )
	    {
		if ( ( pexit = pRoomIndex->exit[door] ) )
		{
		    fexit = TRUE;
		    if ( pexit->vnum <= 0 )
			pexit->to_room = NULL;
		    else
			pexit->to_room = get_room_index( pexit->vnum );
		}
	    }

	}
        }

        for( iHash = 0; iHash < MAX_KEY_HASH; iHash++ )
        {
	for ( pRoomIndex  = room_index_hash[iHash];
	      pRoomIndex;
	      pRoomIndex  = pRoomIndex->next )
	{
	    for ( door = 0; door < MAX_DIR; door++ )
	    {
		if (   ( pexit     = pRoomIndex->exit[door]       )
		    && ( to_room   = pexit->to_room               )
		    && ( pexit_rev = to_room->exit[rev_dir[door]] )
		    &&   pexit_rev->to_room != pRoomIndex )
		{
/*		    sprintf( buf, "Fix_exits: %d:%d -> %d:%d -> %d.",
			    pRoomIndex->vnum, door,
			    to_room->vnum,    rev_dir[door],
			    ( !pexit_rev->to_room ) ? 0
			    :  pexit_rev->to_room->vnum );
		    bug( buf, 0 );
*/
		}
	    }
       }
       }

    return;
}

AFFECT_DATA *new_affect( void )
{
    AFFECT_DATA *paf;

    if ( !affect_free )
        return alloc_perm( sizeof( AFFECT_DATA ) );

    paf		= affect_free;
    affect_free = affect_free->next;

    return paf;
}

OBJ_DATA *new_object( void )
{
    OBJ_DATA *obj;

    if ( !obj_free )
    {
        obj	 = alloc_perm( sizeof( *obj ) );
        top_obj++;
    }
    else
    {
	obj	 = obj_free;
	obj_free = obj_free->next;
    }

    memset( obj, 0, sizeof( OBJ_DATA ) );

    obj->deleted = FALSE;

    return obj;
}

EXTRA_DESCR_DATA *new_extra_descr( void )
{
    EXTRA_DESCR_DATA *ed;

    if ( !extra_descr_free )
        return alloc_perm( sizeof( EXTRA_DESCR_DATA ) );
    
    ed		     = extra_descr_free;
    extra_descr_free = extra_descr_free->next;

    return ed;

}
	

/*
 * Create some quest index data - Veygoth
 */
QUEST_INDEX_DATA *create_quest( )
{
    QUEST_INDEX_DATA *quest;

    quest = alloc_perm( sizeof( *quest ));

    memset( quest, 0, sizeof( QUEST_INDEX_DATA ));

    quest->vnum = 0;
    quest->quests = NULL;
    quest->messages = NULL;
    quest->next = quest_first;
    quest_first = quest;
    top_quest++;

    return quest;
}

/*
 * Create some quest data - Veygoth
 */
QUEST_DATA *create_quest_data( )
{
    QUEST_DATA *qdata;

    qdata = alloc_perm( sizeof( *qdata ));

    memset( qdata, 0, sizeof( QUEST_DATA ));

    qdata->next = NULL;
    qdata->receive = NULL;
    qdata->give = NULL;
    qdata->disappear = NULL;
    qdata->complete = NULL;
    top_qdata++;

    return qdata;
}

/*
 * Create some quest message data - Veygoth
 */
TALK_DATA *create_quest_message( )
{
    TALK_DATA *message;

    message = alloc_perm( sizeof( *message ));

    memset( message, 0, sizeof( TALK_DATA ));

    message->next = NULL;
    message->keywords = NULL;
    message->message = NULL;
    top_qmsg++;

    return message;
}

/*
 * Create some quest data - Veygoth
 */
QUEST_ITEM *create_quest_item( )
{
    QUEST_ITEM *qitem;

    qitem = alloc_perm( sizeof( *qitem ));

    memset( qitem, 0, sizeof( QUEST_ITEM ));

    qitem->complete = FALSE;
    qitem->type = 0;
    qitem->value = 0;
    top_qitem++;

    return qitem;
}


/*
 * Translates mob virtual number to its mob index struct.
 * Hash table lookup.
 */
MOB_INDEX_DATA *get_mob_index( int vnum )
{
    MOB_INDEX_DATA *pMobIndex;

    if ( vnum < 0 )
        return NULL;

    for ( pMobIndex  = mob_index_hash[vnum % MAX_KEY_HASH];
	  pMobIndex;
	  pMobIndex  = pMobIndex->next )
    {
	if ( pMobIndex->vnum == vnum )
	    return pMobIndex;
    }

    if ( fBootDb )
    {
		bug( "get_mob_index: bad vnum %d.", vnum );
		getchar();
		exit( 1 );
    }

    return NULL;
}



/*
 * Translates mob virtual number to its obj index struct.
 * Hash table lookup.
 */
OBJ_INDEX_DATA *get_obj_index( int vnum )
{
    OBJ_INDEX_DATA *pObjIndex;

    if ( vnum < 0 )
        return NULL;

    for ( pObjIndex  = obj_index_hash[vnum % MAX_KEY_HASH];
	  pObjIndex;
	  pObjIndex  = pObjIndex->next )
    {
	if ( pObjIndex->vnum == vnum )
	    return pObjIndex;
    }

    if ( fBootDb )
    {
    	bug( "Get_obj_index: bad vnum %d.", vnum );
    }

    return NULL;
}



/*
 * Translates mob virtual number to its room index struct.
 * Hash table lookup.
 */
ROOM_INDEX_DATA *get_room_index( int vnum )
{
    ROOM_INDEX_DATA *pRoomIndex;

    if ( vnum < 0 )
        return NULL;

    for ( pRoomIndex = room_index_hash[vnum % MAX_KEY_HASH];
          pRoomIndex;
          pRoomIndex = pRoomIndex->next )
    {
	if ( pRoomIndex->vnum == vnum )
	    return pRoomIndex;
    }

    if ( fBootDb )
    {
		fprintf(stderr, "get_room_index: bad vnum %d.\n", vnum );
    }

    return NULL;
}



/*
 * Read a letter from a file.
 */
char fread_letter( FILE *fp )
{
    char c;

    do
    {
	c = getc( fp );
    }
    while ( isspace( c ) );

    return c;
}



/*
 * Read a number from a file.
 */
int fread_number( FILE *fp, int *status )
{
    int  c;
    bool sign;
    int  number;
    int  stat;

    do
    {
	    c = getc( fp );
    }
    while ( isspace( c ) );

    number = 0;

    sign = FALSE;
    if ( c == '+' )
    {
	    c = getc( fp );
    }
    else if ( c == '-' )
    {
	    sign = TRUE;
	    c = getc( fp );
    }

    if ( !isdigit( c ) )
    {
        *status = 1;
	    bug( "Fread_number: bad format.", 0 );
	    return 0;
    }

    while ( isdigit(c) )
    {
	    number = number * 10 + c - '0';
	    c = getc( fp );
    }

    if ( sign )
	number = 0 - number;

    if ( c == '|' )
	number += fread_number( fp, &stat );
    else if ( c != ' ' )
	ungetc( c, fp );

    return number;
}



/*
 * Read to end of line (for comments).
 */
void fread_to_eol( FILE *fp )
{
    int c;

    do
    {
	c = getc( fp );
    }
    while ( c != '\n' && c != '\r' && c != EOF );

    do
    {
	c = getc( fp );
    }
    while ( c == '\n' || c == '\r' );

    ungetc( c, fp );
    return;
}



/*
 * Read one word (into static buffer).
 */
char *fread_word( FILE *fp, int *status )
{
    static char  word [ MAX_INPUT_LENGTH ];
           char *pword;
           int   cEnd;

    *status = 0;

    do
    {
	cEnd = getc( fp );
    }
    while ( isspace( cEnd ) );

    if ( cEnd == '\'' || cEnd == '"' )
    {
	pword   = word;
    }
    else
    {
	word[0] = cEnd;
	pword   = word+1;
	cEnd    = ' ';
    }

    for ( ; pword < word + MAX_INPUT_LENGTH; pword++ )
    {
	*pword = getc( fp );
	if ( cEnd == ' ' ? isspace( *pword ) : *pword == cEnd )
	{
	    if ( cEnd == ' ' )
		ungetc( *pword, fp );
	    *pword = '\0';
	    return word;
	}
    }

    pword[-1] = '\0';

//    bug( "Fread_word: word too long.", 0 );
//    log_string( word );
//    log_string( "End of word!" );
    *status = 1;
    return NULL;
}



/*
 * Allocate some ordinary memory,
 *   with the expectation of freeing it someday.
 */
void *alloc_mem( int sMem )
{
    void *pMem;
    int iList;

    for ( iList = 0; iList < MAX_MEM_LIST; iList++ )
    {
	if ( sMem <= rgSizeList[iList] )
	    break;
    }

    if ( iList == MAX_MEM_LIST )
    {
		bug( "alloc_mem: size %d too large.", sMem );
		getchar();
		exit( 1 );
    }

    if ( !rgFreeList[iList] )
    {
	pMem		  = alloc_perm( rgSizeList[iList] );
    }
    else
    {
	pMem              = rgFreeList[iList];
	rgFreeList[iList] = * ( (void **) rgFreeList[iList] );
    }

    return pMem;
}



/*
 * Free some memory.
 * Recycle it back onto the free list for blocks of that size.
 */
void free_mem( void *pMem, int sMem )
{
    int iList;

    for ( iList = 0; iList < MAX_MEM_LIST; iList++ )
    {
	if ( sMem <= rgSizeList[iList] )
	    break;
    }

    if ( iList == MAX_MEM_LIST )
    {
		bug( "free_mem: size %d too large.", sMem );
		getchar();
		exit( 1 );
    }

    * ( (void **) pMem ) = rgFreeList[iList];
    rgFreeList[iList]  = pMem;

    return;
}

/*
 * Allocate some permanent memory.
 * Permanent memory is never freed,
 *   pointers into it may be copied safely.
 */
void *alloc_perm( int sMem )
{
           void *pMem;
    static char *pMemPerm;
    static int   iMemPerm;

    while ( sMem % sizeof( long ) != 0 )
	sMem++;
    if ( sMem > MAX_PERM_BLOCK )
    {
		bug( "alloc_perm: %d too large.", sMem );
		getchar();
		exit( 1 );
    }

    if ( !pMemPerm || iMemPerm + sMem > MAX_PERM_BLOCK )
    {
		iMemPerm = 0;
		if ( !( pMemPerm = calloc( 1, MAX_PERM_BLOCK ) ) )
		{
			perror( "alloc_perm" );
			getchar();
			exit( 1 );
		}
    }

    pMem        = pMemPerm + iMemPerm;
    iMemPerm   += sMem;
    nAllocPerm += 1;
    sAllocPerm += sMem;
    return pMem;
}

/*
 * Stick a little fuzz on a number.
 */
int number_fuzzy( int number )
{
    switch ( number_bits( 2 ) )
    {
		case 0:  number -= 1; break;
		case 3:  number += 1; break;
    }

    return UMAX( 1, number );
}



/*
 * Generate a random number.
 */
int number_range( int from, int to )
{
    int  power;
    int  number;

    if ( ( to = to - from + 1 ) <= 1 )
	return from;

    for ( power = 2; power < to; power <<= 1 )
	;

    while ( ( number = number_mm( ) & ( power - 1 ) ) >= to )
	;

    return from + number;
}

int number_bits( int width )
{
    return number_mm( ) & ( ( 1 << width ) - 1 );
}

static	int	rgiState[2+55];

void init_mm( )
{
    int *piState;
    int  iState;

    piState	= &rgiState[2];

    piState[-2]	= 55 - 55;
    piState[-1]	= 55 - 24;

    piState[0]	= ( (int) current_time ) & ( ( 1 << 30 ) - 1 );
    piState[1]	= 1;
    for ( iState = 2; iState < 55; iState++ )
    {
	piState[iState] = ( piState[iState-1] + piState[iState-2] )
			& ( ( 1 << 30 ) - 1 );
    }
    return;
}



int number_mm( void )
{
    int *piState;
    int  iState1;
    int  iState2;
    int  iRand;
;
    piState		= &rgiState[2];
    iState1	 	= piState[-2];
    iState2	 	= piState[-1];
    iRand	 	= ( piState[iState1] + piState[iState2] )
			& ( ( 1 << 30 ) - 1 );
    piState[iState1]	= iRand;
    if ( ++iState1 >= 55 )
	iState1 = 0;
    if ( ++iState2 >= 55 )
	iState2 = 0;
    piState[-2]		= iState1;
    piState[-1]		= iState2;
    return iRand >> 6;
}



/*
 * Roll some dice.
 */
int dice( int number, int size )
{
    int idice;
    int sum;

    switch ( size )
    {
		case 0: return 0;
		case 1: return number;
    }

    for ( idice = 0, sum = 0; idice < number; idice++ )
	sum += number_range( 1, size );

    return sum;
}


/*
 * Removes the tildes from a string.
 * Used for player-entered strings that go into disk files.
 */
void smash_tilde( char *str )
{
    for ( ; *str != '\0'; str++ )
    {
	if ( *str == '~' )
	    *str = '-';
    }

    return;
}



/*
 * Compare strings, case insensitive.
 * Return TRUE if different
 *   (compatibility with historical functions).
 */
bool str_cmp( const char *astr, const char *bstr )
{
    if ( !astr )
    {
	bug( "Str_cmp: null astr.", 0 );
	return TRUE;
    }

    if ( !bstr )
    {
	bug( "Str_cmp: null bstr.", 0 );
	return TRUE;
    }

    for ( ; *astr || *bstr; astr++, bstr++ )
    {
	if ( LOWER( *astr ) != LOWER( *bstr ) )
	    return TRUE;
    }

    return FALSE;
}



/*
 * Compare strings, case insensitive, for prefix matching.
 * Return TRUE if astr not a prefix of bstr
 *   (compatibility with historical functions).
 */
bool str_prefix( const char *astr, const char *bstr )
{
    if ( !astr )
    {
	bug( "Str_prefix: null astr.", 0 );
	return TRUE;
    }

    if ( !bstr )
    {
	bug( "Str_prefix: null bstr.", 0 );
	return TRUE;
    }

    for ( ; *astr; astr++, bstr++ )
    {
	if ( LOWER( *astr ) != LOWER( *bstr ) )
	    return TRUE;
    }

    return FALSE;
}



/*
 * Compare strings, case insensitive, for match anywhere.
 * Returns TRUE is astr not part of bstr.
 *   (compatibility with historical functions).
 */
bool str_infix( const char *astr, const char *bstr )
{
    char c0;
    int  sstr1;
    int  sstr2;
    int  ichar;

    if ( ( c0 = LOWER( astr[0] ) ) == '\0' )
	return FALSE;

    sstr1 = strlen( astr );
    sstr2 = strlen( bstr );

    for ( ichar = 0; ichar <= sstr2 - sstr1; ichar++ )
    {
	if ( c0 == LOWER( bstr[ichar] ) && !str_prefix( astr, bstr + ichar ) )
	    return FALSE;
    }

    return TRUE;
}



/*
 * Compare strings, case insensitive, for suffix matching.
 * Return TRUE if astr not a suffix of bstr
 *   (compatibility with historical functions).
 */
bool str_suffix( const char *astr, const char *bstr )
{
    int sstr1;
    int sstr2;

    sstr1 = strlen( astr );
    sstr2 = strlen( bstr );
    if ( sstr1 <= sstr2 && !str_cmp( astr, bstr + sstr2 - sstr1 ) )
	return FALSE;
    else
	return TRUE;
}

/*
 * Returns an initial-capped string.
 */
/* This function does not work properly and prevents
 * people from being able to log in, among other things
 * - Veygoth 12-29-99
 */
char *capitalize( const char *str )
{
    static char strcap [ MAX_STRING_LENGTH ];
    int i;
    int j;

    /* Set all non colour codes to lower case. */
    for ( j = 0; str[j] != '\0'; j++ )
    {
        if ( ( str[j] == '&' ) && ( str[j+1] == '+' || str[j+1] == '-' ) )
        {   /*  Copy the &, +/-, and the next char. */
            strcap[j] = str[j];
            strcap[j+1] = str[j+1];
            j += 2;
            if ( str[j] != '\0' )
                strcap[j] = str[j];
            else
                j--;
	}
        else
            strcap[j] = LOWER( str[j] );
    }

    strcap[j] = '\0';

    /* Set first non-colour code to upper case. */
    for ( i = 0; str[i] != '\0'; i++)
    {
        if ( str[i] == '&' && str[i+1] != '\0' ) 
	{
            if ( str[i+1] == 'n' || str[i+1] == 'N' )
                i++;
            else
            if ( str[i+1] == '+' || str[i+1] == '-' )
                i += 2;
            else
            {
                if ( str[i] != '\0' )
                    i++;
                break;
            }
        }
        else break;
    }

    strcap[i] = UPPER( strcap[i] );

    return strcap;
}

/*
 * Reports a bug.
 */
void bug( const char *str, int param )
{
    char  buf     [ MAX_STRING_LENGTH ];

    if ( fpArea )
    {
	int iLine;
	int iChar;

	if ( fpArea == stdin )
	{
	    iLine = 0;
	}
	else
	{
	    iChar = ftell( fpArea );
	    fseek( fpArea, 0, 0 );
	    for ( iLine = 0; ftell( fpArea ) < iChar; iLine++ )
	    {
		while ( getc( fpArea ) != '\n' );
	    }
	    fseek( fpArea, iChar, 0 );
	}

	sprintf( buf, "[*****] FILE: %s LINE: %d", strArea, iLine );
	log_string( buf );

    }

    strcpy( buf, "[*****] BUG: " );
    sprintf( buf + strlen( buf ), str, param );
    log_string( buf );

    fclose( fpReserve );

    /* Removed the logging to BUGS.TXT because the log files are enough info and we want BUGS.TXT readable */

    fpReserve = fopen( NULL_FILE, "r" );

    return;
}


/*
 * Reports a bug.
 */
void bugf( char * fmt, ... )
{
    char        buf [ MAX_STRING_LENGTH ];
    va_list     args;

    va_start( args, fmt );
    vsprintf( buf, fmt, args );
    va_end( args );

    bug ( buf, 0 );
    return;
}

/*
 * Writes a string to the log.
 * Do not add last_fun here, or last_fun will cease to function properly.
 */
void log_string( const char *str )
{
    fprintf( stderr, "%s\n", str );
    return;
}

// Converts the classes used in the editor to the classes used on the MUD.
//
// Though having a need for this function is kind of wasteful, it does
// allow us to translate a class in the editor to one int the game if
// we were to do something like remove rangers or assassins yet still
// wanted the mobs to have the warrior and thief abilities without
// having to rewrite the whole zone - Veygoth
int class_convert( int c_class )
{
	switch( c_class )
        {
           default:
              bug( "Invalid class %d!", c_class );
              return CLASS_NONE;
              break;
           case 0:
              return CLASS_NONE;
              break;
           case 3:
              return CLASS_PSIONICIST;
              break;
           case 2:
              return CLASS_RANGER;
              break;
           case 1:
           case 7: // Monk
              return CLASS_WARRIOR;
              break;
           case 4:
              return CLASS_PALADIN;
              break;
           case 5:
              return CLASS_ANTIPALADIN;
              break;
           case 6:
              return CLASS_CLERIC;
              break;
           case 8:
              return CLASS_DRUID;
              break;
           case 9:
              return CLASS_SHAMAN;
              break;
           case 10:
           case 11: // Necromancer
              return CLASS_SORCERER;
              break;
           case 12: // Conjurer = random elementalist
              switch( number_range( 1, 4 ))
              {
                default: return CLASS_NONE; break;
                case 1: return CLASS_ELEMENT_AIR; break;
                case 2: return CLASS_ELEMENT_EARTH; break;
                case 3: return CLASS_ELEMENT_FIRE; break;
                case 4: return CLASS_ELEMENT_WATER; break;
              }
              break;
           case 13:
              return CLASS_THIEF;
              break;
           case 14:
              return CLASS_ASSASSIN;
              break;
           case 15:
              return CLASS_MERCENARY;
              break;
           case 16:
              return CLASS_BARD;
              break;
           case 17:
              return CLASS_ILLUSIONIST;
              break;
           case 18:
              return CLASS_ELEMENT_FIRE;
              break;
           case 19:
              return CLASS_ELEMENT_EARTH;
              break;
           case 20:
              return CLASS_ELEMENT_AIR;
              break;
           case 21:
              return CLASS_ELEMENT_WATER;
              break;
           case 22:
              return CLASS_HUNTER;
              break;
		   case 23:
			  return CLASS_CHRONOMANCER;
			  break;
		   case 24:
			  return CLASS_WARLOCK;
			  break;
		   case 25:
			  return CLASS_ENSLAVER;
			  break;
        };


}

int duris_class_convert( int c_class )
{
	switch( c_class )
        {
            default:
				bug( "Invalid class %d!  This may be a multi-class mob, in which case you'll need to edit class manually.", c_class );
				return CLASS_NONE;
				break;
            case 1:
				return CLASS_WARRIOR;
				break;
            case 2:
				return CLASS_RANGER;
				break;
			case 4:
				return CLASS_PSIONICIST;
				break;
			case 8:
				return CLASS_PALADIN;
				break;
			case 16:
				return CLASS_ANTIPALADIN;
				break;
			case 32:
				return CLASS_CLERIC;
				break;
			case 64:
				return CLASS_MONK;
				break;
			case 128:
				return CLASS_DRUID;
				break;
			case 256:
				return CLASS_SHAMAN;
				break;
			case 512:
				return CLASS_SORCERER;
				break;
			case 1024:
				return CLASS_NECROMANCER;
				break;
			case 2048:
				bug( "Mob found with non-specific elementalist (conjurer) class.  Defaulting to fire elementalist.  You may need to check this.", c_class );
				return CLASS_ELEMENT_FIRE;
				break;
			case 4096:
				return CLASS_THIEF;
				break;
			case 8192:
				return CLASS_ASSASSIN;
				break;
			case 16384:
				return CLASS_MERCENARY;
				break;
			case 32768:
				return CLASS_BARD;
				break;
			case 65536:
				return CLASS_THIEF;
				break;
			case 131072:
				return CLASS_WARLOCK;
				break;
			case 262144:
				return CLASS_ENSLAVER;
				break;
			case 524288:
				return CLASS_ENCHANTER;
				break;
			case 1048576:
				return CLASS_WARRIOR;
				break;
			case 2097152:
				return CLASS_REAVER;
				break;
			case 4194304:
				return CLASS_ILLUSIONIST;
				break;
			case 8388608:
				return CLASS_BARD;
				break;
			case 16777216:
				return CLASS_ANTIPALADIN;
				break;
			case 335554432:
				return CLASS_CHRONOMANCER;
				break;
			case 67108864:
				return CLASS_PALADIN;
				break;
        };


}

/*
 * Lookup a skill by name.
 */
int skill_lookup( const char *name )
{
    int sn;

    for ( sn = 0; sn < MAX_SKILL; sn++ )
    {
	if ( !skills_table[sn].name )
	    break;
	if ( LOWER( name[0] ) == LOWER( skills_table[sn].name[0] )
	    && !str_prefix( name, skills_table[sn].name ) )
	    return sn;
    }

    return -1;
}

/*
 * Lookup a spell by name.
 */
int spell_lookup( const char *name )
{
    int sn;

    if ( !name ) 
	{
       return -1;
    }

    for ( sn = 0; sn < MAX_SPELL; sn++ )
    {
	if ( !spells_table[sn].name )
	    break;
	if ( LOWER( name[0] ) == LOWER( spells_table[sn].name[0] )
	    && !str_prefix( name, spells_table[sn].name ) )
	    return sn;
    }

    return -1;
}

/*
 * Lookup a spell by name.
 */
int song_lookup( const char *name )
{
    int sn;

    for ( sn = 0; sn < MAX_SONG; sn++ )
    {
	if ( !songs_table[sn].name )
	    break;
	if ( LOWER( name[0] ) == LOWER( songs_table[sn].name[0] )
	    && !str_prefix( name, songs_table[sn].name ) )
	    return sn;
    }

    return -1;
}
// Loads Basternae style room sections.  Only difference from 
// new_load_rooms is that new_load_rooms automatically converts
// the sector type from Envy zones to Magma zones - Veygoth

void load_bast_rooms(FILE * fp)
{
    char   buff[MAX_STRING_LENGTH] = "\0";
	ROOM_INDEX_DATA *pRoomIndex;
    ROOM_INDEX_DATA *duplicateRoom = NULL;

    int tkey = 0, tvnum = 0, tguardbit = 0;
	int iHash;

	if (!area_last)
    {
		bug("load_bast_rooms: no #AREA seen yet.", 0);
		getchar();
		exit(1);
	}

	for (;;) {
		char letter;
		int vnum;
		int door;
		int stat;

		letter = fread_letter(fp);
		if (letter != '#')
        {
			bug("load_bast_rooms: # not found.", 0);
			show_file_location(fp);
			getchar();
			exit(1);
		}

		vnum = fread_number(fp, &stat);
		if (vnum == 0)
			break;

		fBootDb = FALSE;
        if ( (duplicateRoom = get_room_index( vnum )) )
        {
            sprintf( buff, "load_bast_rooms: index number %d already in use by %s in zone %s.", vnum, duplicateRoom->name, duplicateRoom->area->filename);
            bug( buff, 0 );
            getchar();
			exit(1);
		}
		fBootDb = TRUE;

		pRoomIndex = (ROOM_INDEX_DATA *) alloc_perm(sizeof(*pRoomIndex));
		pRoomIndex->people = NULL;
		pRoomIndex->contents = NULL;
		pRoomIndex->extra_descr = NULL;
		pRoomIndex->area = area_last;
		pRoomIndex->vnum = vnum;

		if (!area_last->low_r_vnum)
			area_last->low_r_vnum = vnum;
		if (!area_last->hi_r_vnum)
			area_last->hi_r_vnum = vnum;

		if (vnum < area_last->low_r_vnum)
			area_last->low_r_vnum = vnum;
		if (vnum > area_last->hi_r_vnum)
			area_last->hi_r_vnum = vnum;


		pRoomIndex->name = fread_string(fp, &stat);
		pRoomIndex->description = fread_string(fp, &stat);
		/* This value was originally area number, but is now used for terrain
		   description generation with maps -- Veygoth  */
		pRoomIndex->sector_type = fread_number(fp, &stat);
        // Discard meaningless number.
        fread_number( fp, &stat );
		pRoomIndex->room_flags[0] = fread_number(fp, &stat);
		pRoomIndex->room_flags[1] = 0;
        pRoomIndex->orig_room_flags = pRoomIndex->room_flags[0];
		//pRoomIndex->orig_room_flags[0] = pRoomIndex->room_flags[0];	/* OLC */
		//pRoomIndex->orig_room_flags[1] = pRoomIndex->room_flags[1];	/* OLC */
        if( pRoomIndex->room_flags[1] != 0 )
        {
            bug( "nonzero orig_room_flags[1] not being kept", pRoomIndex->room_flags[1] );
        }
		pRoomIndex->extra_sector_info = fread_number(fp, &stat);
		pRoomIndex->light = 0;
		for (door = 0; door < MAX_DIR; door++)
			pRoomIndex->exit[door] = NULL;

		for (;;) {
			letter = fread_letter(fp);

			if (letter == 'S' || letter == 's') {
				if (letter == 's')
					bug("Load_rooms: vnum %d has lowercase 's'", vnum);
				break;
			}

			if (letter == 'D') {
				EXIT_DATA *pexit;
				int locks;

				door = fread_number(fp, &stat);
				if (door < 0 || door >= MAX_DIR)
				{
					bug("load_bast_rooms: vnum %d has bad door number.", vnum);
					getchar();
					exit(1);
				}

				pexit = (EXIT_DATA *) alloc_perm(sizeof(*pexit));
				pexit->description = fread_string(fp, &stat);
				pexit->keyword = fread_string(fp, &stat);
				locks = fread_number(fp, &stat);
				// convert exits - Veygoth
				switch (locks) {
					case 0:
					pexit->exit_info = 0;
					break;
					case 1:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED;
					break;
					case 2:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED;
					break;
					case 3:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
						EX_BASHPROOF | EX_PICKPROOF;
					break;
					case 4:
					pexit->exit_info = EX_ISDOOR | EX_SECRET;
					break;
					case 5:
					pexit->exit_info = EX_SECRET | EX_ISDOOR | EX_CLOSED;
					break;
					case 6:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED | EX_SECRET;
					break;
					case 7:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
						EX_BASHPROOF | EX_PICKPROOF | EX_SECRET;
					break;
					case 8:
					pexit->exit_info = EX_BLOCKED;
					break;
					case 9:
					pexit->exit_info = EX_BLOCKED | EX_ISDOOR | EX_CLOSED;
					break;
					case 10:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED | EX_BLOCKED;
					break;
					case 11:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
						EX_BASHPROOF | EX_PICKPROOF | EX_BLOCKED;
					break;
					case 12:
					pexit->exit_info = EX_ISDOOR | EX_BLOCKED | EX_SECRET;
					break;
					case 13:
					pexit->exit_info = EX_SECRET | EX_ISDOOR | EX_CLOSED | EX_BLOCKED;
					break;
					case 14:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED | EX_SECRET | EX_BLOCKED;
					break;
					case 15:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_LOCKED |
						EX_BASHPROOF | EX_PICKPROOF | EX_SECRET | EX_BLOCKED;
					break;
					case 16:
					pexit->exit_info = EX_ISDOOR | EX_CLOSED | EX_BASHPROOF | EX_PICKPROOF;
					break;
                                        case 17:
                                        bug( "Bad exit value 17", 0 );
					break;
					case 21:
					bug( "Bad exit value 21", 0 );
					break;
					default:
					bug
						("The MUD does not understand an exits value of %d.  Defaulting to generic closed door.",
						 locks);
					pexit->exit_info = EX_ISDOOR;
					break;
				};

				//temp_fread_string_to_eol(fp,buff);
				pexit->key = fread_number(fp, &stat );
				pexit->vnum = fread_number(fp, &stat );
                fread_to_eol(fp);
				sscanf(buff," %i %i %i ",&tkey,&tvnum,&tguardbit);
				//pexit->key = tkey;
				//pexit->vnum = tvnum;
				//pexit->guardbits = tguardbit;
                if( tkey != 0 )
                    bug( "nonzero tkey in load_bast_rooms is ignored", tkey );
                if( tvnum != 0 )
                    bug( "nonzero tvnum in load_bast_rooms is ignored", tvnum );
                if( tguardbit != 0 )
                    bug( "nonzero tguardbit in load_bast_rooms is ignore", tguardbit );

				//pexit->vnum = fread_number(fp, &stat);
				//pexit->vnum = fread_number(fp, &stat);

				pRoomIndex->exit[door] = pexit;
				top_exit++;
			} else if (letter == 'E') {
				EXTRA_DESCR_DATA *ed;

				ed = (EXTRA_DESCR_DATA *) alloc_perm(sizeof(*ed));
				ed->keyword = fread_string(fp, &stat);
				ed->description = fread_string(fp, &stat);
				ed->next = pRoomIndex->extra_descr;
				pRoomIndex->extra_descr = ed;
				top_ed++;
			}
			// Fall chance - Veygoth
			else if (letter == 'F') {
				pRoomIndex->fall_chance = fread_number(fp, &stat);
			}
			// Current not yet used, values discarded - Veygoth
			else if (letter == 'C') {
				pRoomIndex->current = fread_number(fp, &stat);
				pRoomIndex->current_dir = fread_number(fp, &stat);
			}
			// Mana not yet used, values discarded - Veygoth
			else if (letter == 'M') {
				fread_number(fp, &stat);
				fread_number(fp, &stat);
			}
			else 
			{
			  sprintf(buff,"load_bast_rooms: vnum %d has flag not 'DES'(%c).", vnum,letter);
			  bug(buff,0);
			  getchar();
			  exit(1);
			}
		}

		iHash = vnum % MAX_KEY_HASH;
		pRoomIndex->next = room_index_hash[iHash];
		room_index_hash[iHash] = pRoomIndex;
		top_room++;
		top_vnum_room = top_vnum_room < vnum ? vnum : top_vnum_room;
		assign_area_vnum(vnum);
	}

	return;
}
void load_bast_objects(FILE * fp)
{
	int count;
	OBJ_INDEX_DATA *pObjIndex;
    OBJ_INDEX_DATA *duplicateObject = NULL;
	char buf[MAX_STRING_LENGTH];	// better error messages...

	if (!area_last)
    {
		bug("load_bast_objects: no #AREA seen yet.", 0);
		getchar();
		exit(1);
	}

	for (;;) 
	{
		char letter;
		int vnum;
		int iHash;
		int stat;
        int y;

		letter = fread_letter(fp);
		if (letter != '#')
		{
			bug("load_bast_objects: # not found.", 0);
			show_file_location(fp);
			getchar();
			exit(1);
		}

		vnum = fread_number(fp, &stat);
		if (vnum == 0)
			break;

		fBootDb = FALSE;
		if ((duplicateObject = get_obj_index(vnum)))
        {
            sprintf( buf, "load_bast_objects: index number %d already in use by %s in zone %s.", vnum, duplicateObject->name, duplicateObject->area->filename);
            bug( buf, 0 );
			getchar();
			exit(1);
		}
		fBootDb = TRUE;

		pObjIndex = (OBJ_INDEX_DATA *) alloc_perm(sizeof(*pObjIndex));
		pObjIndex->vnum = vnum;

		for (count = 0; count < NUM_AFFECT_VECTORS; count++)
        {
			pObjIndex->affected_by[count] = 0;
		}

		if (!area_last->low_o_vnum || vnum < area_last->low_o_vnum )
			area_last->low_o_vnum = vnum;
		if (!area_last->hi_o_vnum || vnum > area_last->hi_o_vnum)
			area_last->hi_o_vnum = vnum;

		pObjIndex->area = area_last;
		pObjIndex->name = fread_string(fp, &stat);
        pObjIndex->name = StripZeroPrefix(pObjIndex->name);
		pObjIndex->short_descr = fread_string(fp, &stat);
		pObjIndex->description = fread_string(fp, &stat);
		/* Action description */ fread_string(fp, &stat);

		pObjIndex->short_descr[0] = LOWER(pObjIndex->short_descr[0]);
		pObjIndex->description[0] = UPPER(pObjIndex->description[0]);

		pObjIndex->item_type = fread_number(fp, &stat);
		pObjIndex->material = fread_number(fp, &stat);
		if (pObjIndex->material >= MAX_MATERIAL) 
		{
			sprintf(buf, "Object %d has material type beyond maximum allowable value.", vnum);
			log_string(buf);
			pObjIndex->material = MAT_UNDEFINED;
		}
		pObjIndex->size = fread_number(fp, &stat);
		pObjIndex->volume = fread_number(fp, &stat);
		pObjIndex->craftsmanship = fread_number(fp, &stat);
		// Damage resistance bonus not used, may not be - Veygoth
		pObjIndex->extra_flags[0] = fread_number(fp, &stat); // must be manually set
		pObjIndex->extra_flags[1] = fread_number(fp, &stat);
		y = fread_number(fp, &stat); // No clue what this number is for.
        if( y != 0 )
        {
			sprintf(buf, "Object %d has in %s has a value (%d) specified for the mysterious extra_flags[2] variable that doesn't exist", 
                vnum, area_last->filename, y);
            log_string(buf);
        }
		pObjIndex->wear_flags = fread_number(fp, &stat);

		pObjIndex->anti_flags = fread_number(fp, &stat);
		pObjIndex->anti_flags2 = fread_number(fp, &stat);
		pObjIndex->value[0] = fread_number(fp, &stat);
		pObjIndex->value[1] = fread_number(fp, &stat);
		pObjIndex->value[2] = fread_number(fp, &stat);
		pObjIndex->value[3] = fread_number(fp, &stat);
		pObjIndex->value[4] = fread_number(fp, &stat);
		pObjIndex->value[5] = fread_number(fp, &stat);
		pObjIndex->value[6] = fread_number(fp, &stat);
		pObjIndex->value[7] = fread_number(fp, &stat);
		pObjIndex->weight = fread_number(fp, &stat);
		pObjIndex->cost = fread_number(fp, &stat);
		pObjIndex->trap = NULL;
		pObjIndex->condition = fread_number(fp, &stat);
		if( pObjIndex->condition != 100 )
		{
			fprintf(stderr, "Warning: object %d - '%s' has a condition not equal to 100 (%d). This could be a read error.\n", 
                pObjIndex->vnum, pObjIndex->short_descr, pObjIndex->condition);
		}
		
		// Not sure whether these should be here or not.
		fread_number(fp, &stat);
		fread_number(fp, &stat);
		fread_number(fp, &stat);
		fread_number(fp, &stat);
		// End unsure.

		if (pObjIndex->condition == 0) 
		{
			sprintf(buf, "Object %d has condition of 0.  Setting to 100.", vnum);
			log_string(buf);
			pObjIndex->condition = 100;
		}
		// convert area_last to Magma format - Veygoth
		if (pObjIndex->size == 3)
			pObjIndex->size = 4;
		else if (pObjIndex->size == 4)
			pObjIndex->size = 6;
		else if (pObjIndex->size == 5)
			pObjIndex->size = 8;
		else if (pObjIndex->size == 6)
			pObjIndex->size = 7;
		else if (pObjIndex->size == 7)
			pObjIndex->size = 10;
		else if (pObjIndex->size == 8)
			pObjIndex->size = 3;
		else if (pObjIndex->size == 9)
			pObjIndex->size = 5;
		else if (pObjIndex->size == 10)
			pObjIndex->size = 0;
		else if (pObjIndex->size == 0)
			pObjIndex->size = 11;

		if (pObjIndex->item_type == TYPE_WEAPON && pObjIndex->value[3] == 0)
			bug("Object vnum %d: object type weapon with no damage type specified", vnum);

		for (;;) 
		{
			char letter;

			letter = fread_letter(fp);

			if (letter == 'A') 
			{
				AFFECT_DATA *paf;

				paf = (AFFECT_DATA *) alloc_perm(sizeof(*paf));
				paf->skill = -1;
				paf->spell = -1;
				paf->song = -1;
				paf->duration = -1;
				paf->location = fread_number(fp, &stat);
				paf->modifier = fread_number(fp, &stat);
				memset(paf->bitvector, 0, (sizeof(int)*NUM_AFFECT_VECTORS));
				paf->next = pObjIndex->affected;
				pObjIndex->affected = paf;
				top_affect++;
			}

			else if (letter == 'E') 
			{
				EXTRA_DESCR_DATA *ed;

				ed = (EXTRA_DESCR_DATA *) alloc_perm(sizeof(*ed));
				ed->keyword = fread_string(fp, &stat);
				ed->description = fread_string(fp, &stat);
				ed->next = pObjIndex->extra_descr;
				pObjIndex->extra_descr = ed;
				top_ed++;
			}

			else if (letter == 'T') 
			{
				pObjIndex->trap = (TRAP_DATA *) alloc_perm(sizeof(TRAP_DATA));
				top_trap++;
				pObjIndex->trap->trigger = fread_number(fp, &stat);
				pObjIndex->trap->damage = fread_number(fp, &stat);
				if (pObjIndex->trap->damage >= MAX_TRAP)
					bug("Trap with damage type %d greater than max.", pObjIndex->trap->damage);
				pObjIndex->trap->charges = fread_number(fp, &stat);
				pObjIndex->trap->level = fread_number(fp, &stat);
				if (pObjIndex->trap->level > 100)
					bug("Trap with level %d greater than 100.", pObjIndex->trap->level);
				letter = getc(fp);
				ungetc(letter, fp);
				if (char_is_number(letter)) 
				{
					pObjIndex->trap->percent = fread_number(fp, &stat);
				} 
				else
					pObjIndex->trap->percent = 100;
				// added this to patch buggy traps by poor zone writers
				if (pObjIndex->trap->charges < 0)
					SET_BIT(pObjIndex->trap->trigger, TRIG_GLYPH);
			}

			else 
			  if (letter == '#') 
			  {
			    ungetc(letter, fp);
			    break;
			  } 
			  else 
			  {
			    // Currently ignoring affect bits on objects - Veygoth
			    ungetc(letter, fp);
			    pObjIndex->affected_by[0] = fread_number(fp, &stat);
			    pObjIndex->affected_by[1] = fread_number(fp, &stat);
			    pObjIndex->affected_by[2] = fread_number(fp, &stat);
			    pObjIndex->affected_by[3] = fread_number(fp, &stat);
			  }
		}
		
		/*
		 * Translate character strings *value[] into integers:  sn's for
		 * items with spells, or straight conversion for other items.
		 */
		switch (pObjIndex->item_type) 
		{
			default:
			break;

			case TYPE_PILL:
			case TYPE_POTION:
			case TYPE_SCROLL:
            case TYPE_HERB:
                // NOTE: This was using bast_spell_lookup.  Changed to magma_spell_lookup. Functions may be different.
                // spells may be broken on items.
			pObjIndex->value[1] = magma_spell_lookup(pObjIndex->value[1]);
			pObjIndex->value[2] = magma_spell_lookup(pObjIndex->value[2]);
			pObjIndex->value[3] = magma_spell_lookup(pObjIndex->value[3]);
			pObjIndex->value[4] = magma_spell_lookup(pObjIndex->value[4]);
			break;

			case TYPE_STAFF:
			case TYPE_WAND:
                // NOTE: This was using bast_spell_lookup.  Changed to magma_spell_lookup. Functions may be different.
                // spells may be broken on items.
			pObjIndex->value[3] = magma_spell_lookup(pObjIndex->value[3]);
			break;
		}

		iHash = vnum % MAX_KEY_HASH;
		pObjIndex->next = obj_index_hash[iHash];
		obj_index_hash[iHash] = pObjIndex;
	
		top_obj_index++;
		top_vnum_obj = top_vnum_obj < vnum ? vnum : top_vnum_obj;
		assign_area_vnum(vnum);
                if (pObjIndex->cost <= 1 )
	          set_cost(pObjIndex);
		
	}
	

	return;
}

void load_bast_mobiles(FILE * fp)
{
  MOB_INDEX_DATA *pMobIndex;
  MOB_INDEX_DATA *duplicateMob = NULL;
  char buf[MAX_STRING_LENGTH];	// better error messages...
  int count;

  if (!area_last) 
  {
    bug("load_bast_mobiles: no #AREA seen yet.", 0);
	getchar();
    exit(1);
  }
  
  for (;;) 
  {
    char *race;
    char letter;
    int vnum;
    int iHash;
    int stat;
    
    letter = fread_letter(fp);
    if (letter != '#') 
	{
      bug("load_bast_mobiles: # not found.", 0);
	  show_file_location(fp);
	  getchar();
      exit(1);
    }
    
    vnum = fread_number(fp, &stat);
    if (vnum == 0)
      break;
    
    fBootDb = FALSE;
    if ( (duplicateMob = get_mob_index( vnum )) )
    {
        sprintf( buf, "load_bast_mobiles: index number %d already in use by %s in zone %s.", vnum, duplicateMob->player_name, duplicateMob->area->filename);
        bug( buf, 0 );
	    getchar();
        exit(1);
    }
    fBootDb = TRUE;
    
    pMobIndex = (MOB_INDEX_DATA *) alloc_perm(sizeof(*pMobIndex));
    pMobIndex->vnum = vnum;

		if (!area_last->low_m_vnum || vnum < area_last->low_m_vnum )
			area_last->low_m_vnum = vnum;
		if (!area_last->hi_m_vnum || vnum > area_last->hi_m_vnum)
			area_last->hi_m_vnum = vnum;
    
    pMobIndex->area = area_last;
    pMobIndex->player_name = fread_string(fp, &stat);
    pMobIndex->short_descr = fread_string(fp, &stat);
    pMobIndex->long_descr = fread_string(fp, &stat);
    pMobIndex->description = fread_string(fp, &stat);
    
    pMobIndex->long_descr[0] = UPPER(pMobIndex->long_descr[0]);
    pMobIndex->description[0] = UPPER(pMobIndex->description[0]);
    
    pMobIndex->act = fread_number(fp, &stat) | ACT_IS_NPC;
    pMobIndex->affected_by[0] = fread_number(fp, &stat);
    pMobIndex->affected_by[1] = fread_number(fp, &stat);
    pMobIndex->affected_by[2] = fread_number(fp, &stat);
    pMobIndex->affected_by[3] = fread_number(fp, &stat);
    // Set all other vectors to zero since this file format only has
    // two vectors - Veygoth
    if (NUM_AFFECT_VECTORS > 4) {
      for (count = 2; count < NUM_AFFECT_VECTORS; count++) {
	pMobIndex->affected_by[count] = 0;
      }
    }
    pMobIndex->pShop = NULL;
    pMobIndex->alignment = fread_number(fp, &stat);
    letter = fread_letter(fp);
    
    if (letter != 'S') 
	{
      bug("load_bast_mobiles: vnum %d non-S.", vnum);
	  getchar();
      exit(1);
    }
    
    race = fread_word(fp, &stat);
    
    pMobIndex->race = race_key_lookup(race);
    if (pMobIndex->race < 0) {
      sprintf(buf, "Load_bast_mobiles: vnum %d bad race key %s", vnum, race);
      bug(buf, 0);
      pMobIndex->race = 0;
    }
    
    /* hometown not used */
    fread_number(fp, &stat);
    
    pMobIndex->c_class = fread_number(fp, &stat);
    // This class_convert will not be necessary if we add
    // classes in the same order as they are in DE.
    // It'll make us load a lil faster
    pMobIndex->c_class = class_convert(pMobIndex->c_class);
    // TODO: Re-enable this.
    //add_spec_class(pMobIndex, pMobIndex->c_class);
    /* Asign special abilities to guild golems andjustice guards
     */
    if (is_name("_guildguard_", pMobIndex->player_name)) {
      //SET_BIT(pMobIndex->affected_by[AFF_WARD_UNDEAD.group], AFF_WARD_UNDEAD.vector);
    	//pMobIndex->act |= ACT_GUARDIAN;
        bug( "Mob is flagged guild guard, but flag does not exist.", pMobIndex->vnum );

    }

	/* This section sets up multiclass bit values */
    //if (is_name("_multiclass_", pMobIndex->player_name))
    //{
    //  int c_class;
    //  for (c_class = 1; c_class < MAX_CLASS; c_class++)
    //  {
    //    sprintf(buf, "_%s_", class_table[c_class]->name);
    //    buf[1] = LOWER(buf[1]);
    //    if (is_name(buf, pMobIndex->player_name))
    //    {
    //      add_spec_class(pMobIndex, c_class);
    //    }
    //  }
      // TODO: Make this stuff work again.
      // Special cases for Elementalist keywords since they have spaces in the class title - Veygoth
 //     if( is_name( "_air_elementalist_", pMobIndex->player_name ))
 //     {
 //         add_spec_class( pMobIndex, CLASS_ELEMENT_AIR );
 //     }
 //     if( is_name( "_earth_elementalist_", pMobIndex->player_name ))
 //     {
 //         add_spec_class( pMobIndex, CLASS_ELEMENT_EARTH );
 //     }
 //     if( is_name( "_fire_elementalist_", pMobIndex->player_name ))
 //     {
 //         add_spec_class( pMobIndex, CLASS_ELEMENT_FIRE );
 //     }
 //     if( is_name( "_water_elementalist_", pMobIndex->player_name ))
 //     {
 //         add_spec_class( pMobIndex, CLASS_ELEMENT_WATER );
 //     }
 //   }           //end of multiclass
 //   
	//	// Assign race-based special functions.  Race functions take precedence over class
	//	// functions -- Veygoth
 //   if (pMobIndex->race == RACE_DRAGON) {
 //     add_spec_fun(pMobIndex, "spec_breath_any");
 //     if (pMobIndex->spec_fun)
	//pMobIndex->spec_fun = get_breath_type(pMobIndex->player_name);
 //   } else if (pMobIndex->race == RACE_VAMPIRE) {
 //     add_spec_fun(pMobIndex, "spec_cast_vampire");
 //   } else if (pMobIndex->race == RACE_HYDRA) {
 //     add_spec_fun(pMobIndex, "spec_hydra");
 //   }
 //   
 //   // give elite guards dispel_wall
 //   if (is_name("elite", pMobIndex->player_name)
	//&& is_name("guard", pMobIndex->player_name)) {
 //     add_spec_fun(pMobIndex, "spec_dispel_wall");
 //   }
 //   
    pMobIndex->level = fread_number(fp, &stat);
    /* Took number_fuzzy out of above line to store mob levels
       at a constant due to OLC resaving areas  --Stoked */
    
    fread_number(fp, &stat);	/* Unused */
    fread_number(fp, &stat);	/* Unused */
    fread_word(fp, &stat);	/* 1d1+1 Unused */
    fread_word(fp, &stat);	/* 1d1+1 Unused */
    fread_word(fp, &stat);	/* 0.0.0.0 Unused */
    fread_number(fp, &stat);	/* Unused */
    pMobIndex->position = fread_number(fp, &stat);
    fread_number(fp, &stat);
    pMobIndex->sex = fread_number(fp, &stat);
    
    // Convert positions from DE
    switch (pMobIndex->position) {
    case 4:
      pMobIndex->position = POS_SLEEPING;
      break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
      pMobIndex->position = POS_RESTING;
      break;
    case 6:
      pMobIndex->position = POS_SITTING;
      break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
      pMobIndex->position = POS_STANDING;
      break;
    case 13:
      pMobIndex->position = POS_RECLINING;
      break;
    default:
      pMobIndex->position = POS_STANDING;
      break;
    }
    
    letter = fread_letter(fp);
    if (letter == '>') {
      bug
	("Don't use the > for mobprograms - we want them in a separate file in the mobprog directory.",
	 0);
      ungetc(letter, fp);
    } else
      ungetc(letter, fp);
    
    iHash = vnum % MAX_KEY_HASH;
    pMobIndex->next = mob_index_hash[iHash];
    mob_index_hash[iHash] = pMobIndex;
    top_mob_index++;
    top_vnum_mob = top_vnum_mob < vnum ? vnum : top_vnum_mob;
    assign_area_vnum(vnum);
  }
  
  return;
}
void load_bast_resets(FILE *fp)
{
    char datas[2048];
	RESET_DATA *pReset;
	int iLastRoom = 0;
	int iLastObj = 0;
    int iLastMob = 0;
	int stat;

	if (!area_last) 
	{
		bug("load_bast_resets: no #AREA seen yet.", 0);
		getchar();
		exit(1);
	}

    // Ignore all Magma area header stuff...
    fread_word( fp, &stat );
    fread_string( fp, &stat);
    fread_number( fp, &stat);    
    area_last->resetmode = fread_number( fp, &stat); // this is the area's reset mode    
    fread_number( fp, &stat);    
    area_last->llifespan = fread_number( fp, &stat) / 5; // lower range of reset time
    area_last->ulifespan = fread_number( fp, &stat) / 5;
    fread_number( fp, &stat);    

	for (;;) {
		EXIT_DATA *pexit = NULL;
		ROOM_INDEX_DATA *pRoomIndex;
		char letter;

		if ((letter = fread_letter(fp)) == 'S')
			break;

		if (letter == '*') {
			fread_to_eol(fp);
			continue;
		}

		pReset = (RESET_DATA *) alloc_perm(sizeof(*pReset));
		pReset->command = letter;
		/* if_flag */ fread_number(fp, &stat);
		pReset->arg1 = fread_number(fp, &stat);
		pReset->arg2 = fread_number(fp, &stat);
		pReset->arg3 = (letter == 'G' || letter == 'R')
			? 0 : fread_number(fp, &stat);
		fread_to_eol(fp);
		pReset->arg4 = 100;
		pReset->arg5 = 0;
		pReset->arg6 = 0;
		pReset->arg7 = 0;

		/*
		 * Validate parameters.
		 * We're calling the index functions for the side effect.
		 */
		switch (letter) {
			default:
	            bug( "Load_bast_resets: bad command '%c'.", letter );
                sprintf( datas, "%d, %d, %d, %d, %d, %d, %d, %d",
                    pReset->arg0,
                    pReset->arg1,
                    pReset->arg2,
                    pReset->arg3,
                    pReset->arg4,
                    pReset->arg5,
                    pReset->arg6,
                    pReset->arg7);
                bug( datas, 0 );
				getchar();
	            exit( 1 );

			break;

			case 'M':
			get_mob_index(pReset->arg1);
			if ((pRoomIndex = get_room_index(pReset->arg3))) {
				new_reset(pRoomIndex, pReset);
				iLastRoom = pReset->arg3;
                iLastMob = pReset->arg1;
			}
			break;

			case 'O':
				get_obj_index(pReset->arg1);
				if ((pRoomIndex = get_room_index(pReset->arg3))) 
				{
					new_reset(pRoomIndex, pReset);
					iLastObj = pReset->arg3;
				}
				break;

			case 'F':
				get_mob_index  ( pReset->arg1 );
				if ( ( pRoomIndex = get_room_index ( pReset->arg3 ) ) )
				{
					new_reset( pRoomIndex, pReset );
					iLastRoom = pReset->arg3;
				}
				break;

			case 'P':
				get_obj_index(pReset->arg1);
				if ((pRoomIndex = get_room_index(iLastObj)))
				{
					pReset->arg5 = pRoomIndex->vnum;
					new_reset(pRoomIndex, pReset);
				}
				break;

			case 'G':
				get_obj_index(pReset->arg1);
				if ((pRoomIndex = get_room_index(iLastRoom)))
				{
					pReset->arg3 = pRoomIndex->vnum;
					pReset->arg5 = iLastMob;
					new_reset(pRoomIndex, pReset);
					iLastObj = iLastRoom;
				}
				break;

			case 'E':
				get_obj_index(pReset->arg1);
				if ((pRoomIndex = get_room_index(iLastRoom)))
				{
					pReset->arg4 = pRoomIndex->vnum;
					pReset->arg5 = iLastMob;
					new_reset(pRoomIndex, pReset);
					iLastObj = iLastRoom;
				}
				break;

			case 'D':
				pRoomIndex = get_room_index(pReset->arg1);

				if (pReset->arg2 < 0
					|| pReset->arg2 >= MAX_DIR
					|| !pRoomIndex
					|| !(pexit = pRoomIndex->exit[pReset->arg2]) || !IS_SET(pexit->exit_info, EX_ISDOOR)) 
				{
					bug("Load_bast_resets: 'D': exit %d not door.", pReset->arg2);
				}

			switch (pReset->arg3)
			{
				default:
				bug("Load_bast_resets: 'D': bad 'locks': %d.", pReset->arg3);
				case 0:
				break;
				case 1:
				SET_BIT(pexit->exit_info, EX_CLOSED);
				break;
				case 2:
				SET_BIT(pexit->exit_info, EX_CLOSED | EX_LOCKED);
				break;
				case 4:
				SET_BIT(pexit->exit_info, EX_SECRET);
				break;
				case 5:
				SET_BIT(pexit->exit_info, EX_SECRET | EX_CLOSED);
				break;
				case 6:
				SET_BIT(pexit->exit_info, EX_SECRET | EX_CLOSED | EX_LOCKED);
				break;
				case 8:
				SET_BIT(pexit->exit_info, EX_BLOCKED);
				break;
				case 9:
				SET_BIT(pexit->exit_info, EX_BLOCKED | EX_CLOSED);
				break;
				case 10:
				SET_BIT(pexit->exit_info, EX_BLOCKED | EX_CLOSED | EX_LOCKED);
				break;
				case 12:
				SET_BIT(pexit->exit_info, EX_BLOCKED | EX_SECRET);
				break;
				case 13:
				SET_BIT(pexit->exit_info, EX_BLOCKED | EX_SECRET | EX_CLOSED);
				break;
				case 14:
				SET_BIT(pexit->exit_info, EX_BLOCKED | EX_SECRET | EX_CLOSED | EX_LOCKED);
				break;
				case 16:
                    bug( "Bad exit value ", pReset->arg3 );
                    break;
				case 17:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info, /*EX_BARROW |*/ EX_CLOSED);
				break;
				case 18:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_CLOSED | EX_LOCKED);
				break;
				case 20:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_SECRET);
				break;
				case 21:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_SECRET | EX_CLOSED);
				break;
				case 22:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_SECRET | EX_CLOSED | EX_LOCKED);
				break;
				case 24:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_BLOCKED);
				break;
				case 25:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_BLOCKED | EX_CLOSED);
				break;
				case 26:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_BLOCKED | EX_CLOSED | EX_LOCKED);
				break;
				case 28:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/EX_BLOCKED | EX_SECRET);
				break;
				case 29:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_BLOCKED | EX_SECRET | EX_CLOSED);
				break;
				case 30:
                    bug( "Bad exit value ", pReset->arg3 );
				SET_BIT(pexit->exit_info,  /*EX_BARROW |*/ EX_BLOCKED | EX_SECRET | EX_CLOSED | EX_LOCKED);
			}
			break;

			case 'R':
				if (pReset->arg2 < 0 || pReset->arg2 > MAX_DIR)
				{	/* Last Door. */
					bug("load_bast_resets: 'R': bad exit %d.", pReset->arg2);
					getchar();
					exit(1);
				}

				if ((pRoomIndex = get_room_index(pReset->arg1)))
				{
					pReset->arg3 = pRoomIndex->vnum;			
					new_reset(pRoomIndex, pReset);
				}

				break;
		}
	}

	return;
}
void load_bast_shops(FILE * fp)
{
	SHOP_DATA *pShop;
	int keeper = 0;

	for (;;) 
	{
		MOB_INDEX_DATA *pMobIndex;
		int iTrade;
		int stat;
		char letter;
		int count;

		letter = fread_letter(fp);
		if (letter != '#') 
		{
			bug("load_bast_shops: # not found before vnum", 0);
			show_file_location(fp);
		}
		keeper = fread_number(fp, &stat);
		letter = fread_letter(fp);
		if (letter != '~') 
		{
			bug("load_bast_shops: ~ not found after vnum", 0);
			show_file_location(fp);
		}
		letter = fread_letter(fp);
		if (letter == 'S')
			return;
		else if (letter != 'N') 
		{
			bug("load_bast_shops: Letter 'N' not found after shop vnum", 0);
			show_file_location(fp);
		}
		if (keeper == 0)
			break;
		pShop = (SHOP_DATA *) alloc_perm(sizeof(*pShop));
		pShop->keeper = keeper;
		pShop->area = area_last;

		for (count = 0; count < MAX_SELL; count++) {
			pShop->sell_item[count] = fread_number(fp, &stat);
			if (pShop->sell_item[count] == 0)
				break;
		}

		pShop->profit_sell = fread_number(fp, &stat) * 100;
		letter = fread_letter(fp);
		if (letter != '.')
			bug("Expecting decimal point in shop profit_sell value", 0);
		pShop->profit_sell += fread_number(fp, &stat);

		pShop->profit_buy = fread_number(fp, &stat) * 100;
		letter = fread_letter(fp);
		if (letter != '.')
			bug("Expecting decimal point in shop profit_buy value", 0);
		pShop->profit_buy += fread_number(fp, &stat);

		for (iTrade = 0; iTrade < MAX_BUY; iTrade++) {
			pShop->buy_type[iTrade] = fread_number(fp, &stat);
			if (pShop->buy_type[iTrade] == 0)
				break;
		}
		// discard seven message strings
		fread_string(fp, &stat);
		fread_string(fp, &stat);
		fread_string(fp, &stat);
		fread_string(fp, &stat);
		fread_string(fp, &stat);
		fread_string(fp, &stat);
		fread_string(fp, &stat);
		// discard two numbers
		fread_number(fp, &stat);
		fread_number(fp, &stat);
		/*discard */ fread_number(fp, &stat);
		fread_number(fp, &stat);
		// room vnum of shop discarded
		fread_number(fp, &stat);
		pShop->open_hour = fread_number(fp, &stat);
		pShop->close_hour = fread_number(fp, &stat);
		// discard second open and close times
		fread_number(fp, &stat);
		fread_number(fp, &stat);
		// discard racist, roam, and killable flags
		fread_letter(fp);
		fread_letter(fp);
		fread_letter(fp);
		// discard open and close messages
		fread_string(fp, &stat);
		fread_string(fp, &stat);
		// discard the rest of the junk
		fread_number(fp, &stat);
		fread_number(fp, &stat);
		fread_letter(fp);
		fread_number(fp, &stat);
		fread_string(fp, &stat);
		// end of the shop
		letter = fread_letter(fp);
		if (letter != 'X') {
			bug("Letter 'X' not found at end of shop section", 0);
		}
		fread_to_eol(fp);
		pMobIndex = get_mob_index(pShop->keeper);
		pMobIndex->pShop = pShop;

		if (!shop_first)
			shop_first = pShop;
		if (shop_last)
			shop_last->next = pShop;

		shop_last = pShop;
		pShop->next = NULL;
		top_shop++;
	}

	return;
}

char *StripZeroPrefix(char *encstr)
{
    if( encstr == NULL )
        return NULL;
    // Careful -- we can't replace & with &amp; recursively because it results in an
    // infinite expansion.
    encstr = strrepl(encstr, "0\r\n", "" );
    return encstr;
}
