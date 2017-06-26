#ifndef merc_h
#define merc_h 1

#define args( list )			list
#define DECLARE_MOB_FUN( fun )		MOB_FUN   fun
#define DECLARE_OBJ_FUN( fun )		OBJ_FUN   fun

#if	!defined( FALSE )
#define FALSE	 0
#endif

#if	!defined( TRUE )
#define TRUE	 1
#endif

#if	defined( _AIX )
#if	!defined( const )
#define const
#endif
typedef int				unlong;
typedef int				bool;
#define unix
#else
typedef unsigned long			unlong;
typedef unsigned char			bool;
#endif


/*
 * Ok here we define strdup so it can no longer be confused
 * with str_dup.
 */
#define strdup  STRDUP_ERROR__USE_STR_DUP!
/* Defined in ssm.c */

char *	str_dup		args( ( const char *str ) );


/*
 * Bit defines, so you don't have to recalculate/think up
 * all the bitvalues every time
 */
#define		BV00			(1 <<  0)	/*          1 */
#define		BV01			(1 <<  1)	/*          2 */
#define		BV02			(1 <<  2)	/*          4 */
#define		BV03			(1 <<  3)	/*          8 */
#define		BV04			(1 <<  4)	/*         16 */
#define		BV05			(1 <<  5)	/*         32 */
#define		BV06			(1 <<  6)	/*         64 */
#define		BV07			(1 <<  7)	/*        128 */
#define		BV08			(1 <<  8)	/*        256 */
#define		BV09			(1 <<  9)	/*        512 */
#define		BV10			(1 << 10)	/*       1024 */
#define		BV11			(1 << 11)	/*       2048 */
#define		BV12			(1 << 12)	/*       4096 */
#define		BV13			(1 << 13)	/*       8192 */
#define		BV14			(1 << 14)	/*      16384 */
#define		BV15			(1 << 15)	/*      32768 */
#define		BV16			(1 << 16)	/*      65536 */
#define		BV17			(1 << 17)	/*     131072 */
#define		BV18			(1 << 18)	/*     262144 */
#define		BV19			(1 << 19)	/*     524288 */
#define		BV20			(1 << 20)	/*    1048576 */
#define		BV21			(1 << 21)	/*    2097152 */
#define		BV22			(1 << 22)	/*    4194304 */
#define		BV23			(1 << 23)	/*    8388608 */
#define		BV24			(1 << 24)	/*   16777216 */
#define		BV25			(1 << 25)	/*   33554432 */
#define		BV26			(1 << 26)	/*   67108864 */
#define		BV27			(1 << 27)	/*  134217728 */
#define		BV28			(1 << 28)	/*  268435456 */
#define		BV29			(1 << 29)	/*  536870912 */
#define		BV30			(1 << 30)	/* 1073741824 */
#define         BV31 _ERROR_DO_NOT_TRY_TO_USE_THE_SIGN_BIT_ON_A_SIGNED_INTEGER_

/*
 * Structure types.
 */
typedef struct affect_data AFFECT_DATA;
typedef struct bitvect_data BITVECT_DATA;
typedef struct area_data AREA_DATA;
typedef struct char_data CHAR_DATA;
typedef struct exit_data EXIT_DATA;
typedef struct extra_descr_data EXTRA_DESCR_DATA;
typedef struct help_data HELP_DATA;
typedef struct mob_index_data MOB_INDEX_DATA;
typedef struct obj_data OBJ_DATA;
typedef struct obj_index_data OBJ_INDEX_DATA;
typedef struct reset_data RESET_DATA;
typedef struct room_index_data ROOM_INDEX_DATA;
typedef struct shop_data SHOP_DATA;
typedef struct class_type CLASS_TYPE;
typedef struct trap_data TRAP_DATA;
typedef struct quest_data QUEST_DATA;
typedef struct quest_index_data QUEST_INDEX_DATA;
typedef struct quest_item QUEST_ITEM;
typedef struct talk_data TALK_DATA;
typedef struct coin_data COIN_DATA;
typedef struct extended_terrain EXTENDED_TERRAIN;

/*
 * Function types.
 */
typedef bool MOB_FUN                    args( ( CHAR_DATA *ch, int cmd ) );
typedef bool OBJ_FUN                    args( ( OBJ_DATA *obj,
					       CHAR_DATA *keeper, bool hit ) );

/*
 * String and memory management parameters.
 */
#define	MAX_KEY_HASH		 32771 // 32771 is a prime number.  32767 was not.
#define MAX_STRING_LENGTH	 4096
#define MAX_INPUT_LENGTH	  299

#define	MAX_WORD_HASH		   27	/* The latin alphabet has 26 letters */


/*
 * Game parameters.
 * Increase the max'es if you add more of something.
 * Adjust the pulse numbers to suit yourself.
 */
#define MAX_CHUNKS                1024			/* Used in ssm.c */

#define MAX_SKILL		   96
#define MAX_SPELL                 431
#define MAX_SONG                   28
#define MAX_CLASS		   22
#define MAX_RACE                   78
#define MAX_COIN_RACE              40 // Last race to carry coins
#define MAX_PC_RACE                20
#define MAX_LEVEL		   65
#define MAX_MOB_LEVEL              65
#define MAX_CIRCLE                 12 // Number of spell circles
#define BASE_SPELL_ADEPT           80
#define BASE_SKILL_ADEPT           25
#define MAX_SKILL_ADEPT            95
#define MAX_SPELL_ADEPT            99
#define MAX_BASE_ATTRIBUTE         100
#define L_DIR		           MAX_LEVEL // = Overlord
#define L_SEN		          ( L_DIR - 1 ) // = Implementor
#define L_JUN	        	  ( L_SEN - 1 ) // = Greater God
#define L_APP                     ( L_JUN - 1 ) // = Lesser God

#define MAX_MORTAL_LEVEL          56
#define NUM_AFFECT_VECTORS        5
#define NUM_ITEM_EXTRA_VECTORS    2
#define NUM_ROOM_FLAGS            2


// Defines for struct data types.  Useful when passing (void *) pointers
#define TYPE_CHAR_DATA       1
#define TYPE_OBJ_DATA        2
#define TYPE_AFFECT_DATA     3
#define TYPE_ROOM_INDEX_DATA 4

/*
 * Player character key data struct
 * Stuff for new error trapping of corrupt pfiles.
 */
struct  key_data
{
    char	    key[12];	/* Increase if you make a key > 11 chars */
    int		    string;	/* TRUE for string, FALSE for int        */
    unlong	    deflt;	/* Default value or pointer              */
    void *	    ptrs[11];	/* Increase if you have > 9 parms/line   */
};

#define MAND		3344556	/* Magic # for manditory field           */
#define SPECIFIED	3344557 /* Key was used already.                 */
#define DEFLT		3344558 /* Use default from fread_char_obj       */


/*
 * Race structures
 */
struct  race_type
{
	char * name;
	char * colorname; // added by Veygoth
	char * key;
	int race_abilities;
	int size;
	int height;
	int weight;
	int base_align;
	int str_mod;
	int int_mod;
	int wis_mod;
	int dex_mod;
	int con_mod;
	int agi_mod;
	int cha_mod;
	int pow_mod;
	int luk_mod;
	int hp_gain;
	int mana_gain;
	int move_gain;
	int thirst_mod;
	int hunger_mod;
	char * dmg_message;
	char * walk_message;
	char * hate;
	int parts;
	int resistant;
	int immune;
	int susceptible;
	int language;
	int racewar_side;
	int base_age;
	int max_age;
	int *race_gsn;
};

#define RACE_HUMAN	0
#define RACE_BARBARIAN	1
#define RACE_GREYELF    2
#define RACE_RAKSHASA   3
#define RACE_HALFELF	4
#define RACE_GNOLL      5
#define RACE_DROW       6
#define RACE_DWARF	7
#define RACE_DUERGAR	8
#define RACE_HALFLING	9
#define RACE_TROLL	10
#define RACE_OGRE	11
#define RACE_ORC	12
#define RACE_GNOME	13
#define RACE_CENTAUR	14
#define RACE_GITHYANKI  15
#define RACE_GOBLIN     16
#define RACE_MINOTAUR   17
#define RACE_GITHZERAI  18
#define RACE_THRIKREEN  19
#define RACE_HALFORC    20
#define RACE_NEOGI      21
// Non-player races
#define RACE_SAHAUGIN   22
#define RACE_UMBERHULK  23
#define RACE_HALFDWARF  24
#define RACE_HALFKOBOLD 25
#define RACE_GIANT      26
#define RACE_ILLITHID	27
#define RACE_AQUATICELF 28
#define RACE_KOBOLD     29
#define RACE_HOBGOBLIN  30
#define RACE_WEMIC      31
#define RACE_HUMANOID   32
// Monsters
#define RACE_DEMON      33
#define RACE_GOD        34
#define RACE_DEVIL      35
#define RACE_ANGEL      36
#define RACE_FAERIE     37
#define RACE_VAMPIRE    38
#define RACE_WEREWOLF   39
#define RACE_DRAGON     40
#define RACE_BEHOLDER   41
#define RACE_DERRO      42
#define RACE_SLAAD      43
#define RACE_GOLEM      44
#define RACE_DRACOLICH  45
#define RACE_DRAGONKIN  46
#define RACE_UNDEAD     47
#define RACE_GHOST      48
#define RACE_HARPY      49
#define RACE_RUSTMONSTER 50
#define RACE_FIRE_ELE   51
#define RACE_AIR_ELE    52
#define RACE_WATER_ELE  53
#define RACE_EARTH_ELE  54
#define RACE_LYCANTHROPE 55
#define RACE_OBJECT     56
#define RACE_MIST       57
#define RACE_IXITXACHITL 58
#define RACE_ABOLETH    59
#define RACE_HYDRA      60
// Animals
#define RACE_REPTILE    61
#define RACE_BOAR       62
#define RACE_INSECT     63
#define RACE_ANIMAL     64
#define RACE_HERBIVORE  65
#define RACE_CARNIVORE  66
#define RACE_BIRD       67
#define RACE_HORSE      68
#define RACE_PRIMATE    69
#define RACE_BEAR       70
#define RACE_BAT        71
#define RACE_PLANT      72
#define RACE_TREE       73
#define RACE_RAT        74
#define RACE_PARASITE   75
#define RACE_ARACHNID   76
#define RACE_SNAKE      77
#define RACE_WORM       78
#define RACE_FISH       79
#define RACE_SHADOW_ELE 80
#define RACE_DARKHUMAN  81

#define RACEWAR_NONE     0
#define RACEWAR_GOOD     1
#define RACEWAR_EVIL     2
#define RACEWAR_NEUTRAL  3
#define MAX_RACEWAR_SIDE 4

#define RACE_RANGE_ANY    0
#define RACE_RANGE_PLAYER 1
#define RACE_RANGE_ANIMAL 2
#define RACE_RANGE_HUMANOID 3
#define RACE_RANGE_SLUG   4

/* Race size defines by Maniac */
#define SIZE_ANY		      0 
#define SIZE_TINY		      1 
#define SIZE_SMALL		      2  
#define SIZE_PETITE		      3 // (small-medium)
#define SIZE_MEDIUM		      4 // (straight medium - humans)
#define SIZE_BIG		      5 // (medium-large)
#define SIZE_LARGE		      6 
#define SIZE_HUGE		      7 
#define SIZE_GIANT                    8 
#define SIZE_TITANIC		      9
#define SIZE_GARGANTUAN		      10 
#define SIZE_NONE                     11 // insubstantial
#define MAX_SIZE		      11 // maximum size value

/* Race ability bits */
#define RACE_NO_ABILITIES	      0
#define RACE_PC_AVAIL		   BV00
#define RACE_WATERBREATH	   BV01
#define RACE_FLY		   BV02
#define RACE_SWIM		   BV03
#define RACE_WATERWALK		   BV04
#define RACE_PASSDOOR		   BV05
#define RACE_INFRAVISION	   BV06
#define RACE_DETECT_ALIGN	   BV07
#define RACE_DETECT_INVIS	   BV08
#define RACE_DETECT_HIDDEN	   BV09
#define RACE_EXTRA_ARMS		   BV10 // Thrikreen and the like - extra attacks
#define RACE_FAERIE_FIRE 	   BV11
#define RACE_WEAPON_WIELD	   BV12
#define RACE_MUTE                  BV13 
#define RACE_BODYSLAM              BV14
#define RACE_CHARGE                BV15
#define RACE_ULTRAVISION           BV16
#define RACE_DOORBASH              BV17
#define RACE_SHRUG                 BV18
#define RACE_ODSNEAK               BV19  // Not Implemented
#define RACE_UDSNEAK               BV20  // Not Implemented
#define RACE_STRENGTH              BV21  // Not Implemented
#define RACE_STEAL                 BV22  // Not Implemented
#define RACE_ENLARGE               BV23
#define RACE_INVIS                 BV24
#define RACE_SUMMON_HOARDE         BV25  // Not Implemented
#define RACE_SHIFT_PRIME           BV26  // Not Implemented
#define RACE_SHIFT_ASTRAL          BV27  // Not Implemented
#define RACE_LEVITATE              BV28  // Not Implemented
#define RACE_BITE                  BV29  // Not Implemented
#define RACE_EXTRA_STRONG_WIELD    BV30  // allows a strong race to wield a twohander primary
                                         // and a shield or onehander secondary

/* Language bits */
// Keep in mind that these are stored in pfiles as a number, so it's a bad idea
// to delete or change anything that already exists - Veygoth
#define LANG_UNKNOWN                  0  /* Anything else                    */
#define LANG_COMMON		      1  /* Human base language              */
#define LANG_ELVEN		      2  /* Elven base language              */
#define LANG_DWARVEN		      3  /* Dwarven base language            */
#define LANG_CENTAUR                  4
#define LANG_OGRE		      5  /* Ogre base language               */
#define LANG_ORC                      6  /* Orc base language                */
#define LANG_TROLL                    7  /* Troll base language              */
#define LANG_AQUA_ELF                 8
#define LANG_SAURIAL                  9
#define LANG_THRI_KREEN              10
#define LANG_DRAGON		     12  /* Large reptiles, Dragons          */
#define LANG_MAGICAL		     14  /* Spells maybe?  Magical creatures */
#define LANG_GOBLIN		     15  /* Goblin base language             */
#define LANG_GOD                     16
#define LANG_HALFLING		     17  /* Halfling base language           */
#define LANG_GITHYANKI		     18  /* Gith Language                    */
#define LANG_DROW		     19  /* Drow base language               */
#define LANG_KOBOLD		     20  /* Kobold base language             */
#define LANG_GNOME		     21  /* Gnome base language              */
#define LANG_ANIMAL		     22  /* Animal language                  */
#define LANG_DUERGAR		     23
#define LANG_GITHZERAI               24
#define LANG_FLIND                   25
#define LANG_RAKSHASA                26
#define LANG_MINOTAUR                27
#define LANG_GNOLL                   28
#define LANG_BARBARIAN               29
#define MAX_LANG                     30

#define MAX_NOUN                     32
#define MAX_VERB                     6
#define NO_DOBJ                      0
#define DOBJ_ANY                     1
#define DOBJ_ANIMATE                 2
#define NO_IOBJ                      0
#define IOBJ_ANY                     1
#define IOBJ_ANIMATE                 2

/* Special function defines
 *
 */
#define PROC_NORMAL                  0
#define PROC_DEATH                   1

/* Innate abilities
 * Used for innate timers
 */
#define INNATE_STRENGTH              1
#define INNATE_INVIS                 2
#define INNATE_FAERIE_FIRE           3
#define INNATE_ENLARGE               4
#define INNATE_LEVITATE              5
#define INNATE_DARKNESS              6
#define INNATE_LIGHT                 7
#define INNATE_REMOVE_POISON         8
#define INNATE_BATTLE_ROAR           9
#define INNATE_CHAMELEON             10
#define INNATE_SHIFT_ASTRAL          11
#define INNATE_SHIFT_PRIME           12

/*
 * Poison types
 */
#define POISON_NONE                  0
#define POISON_DAMAGE                1
#define POISON_ATTRIBUTES            2
#define POISON_DAMAGE_MAJOR          3
#define POISON_MINOR_PARA            4
#define POISON_MINOR_PARA_LONG       5
#define POISON_MAJOR_PARA            6
#define POISON_MAJOR_PARA_LONG       7
#define POISON_PERM_CON              8
#define POISON_PERM_HP               9
#define POISON_NEAR_DEATH           10

/*
 * Help table types.
 */
struct	help_data
{
    HELP_DATA * 	next;
    int 	        level;
    char *      	keyword;
    char *      	text;
    AREA_DATA *		area;
};

/*
 * Shop types.
 */
#define MAX_BUY		 10 // Max number of item types shop will buy
#define MAX_SELL         20 // Max number of items shop can sell.

struct	shop_data
{
    SHOP_DATA *	next;			/* Next shop in list		*/
    AREA_DATA * area;
    int 	keeper;			/* Vnum of shop keeper mob	*/
    int 	buy_type [ MAX_BUY ];	/* Item types shop will buy	*/
    int         sell_item[ MAX_SELL ];  /* Items that shop is selling   */
    int 	profit_buy;		/* Cost multiplier for buying	*/
    int 	profit_sell;		/* Cost multiplier for selling	*/
    int 	open_hour;		/* First opening hour		*/
    int 	close_hour;		/* First closing hour		*/
};

#define CLASS_NONE	    0
#define CLASS_WARRIOR       1
#define CLASS_SORCERER      2
#define CLASS_PSIONICIST    3
#define CLASS_CLERIC        4
#define CLASS_THIEF         5
#define CLASS_ASSASSIN      6
#define CLASS_MERCENARY     7
#define CLASS_PALADIN       8
#define CLASS_ANTIPALADIN   9
#define CLASS_RANGER        10
#define CLASS_ELEMENT_EARTH 11
#define CLASS_ELEMENT_AIR   12
#define CLASS_ELEMENT_FIRE  13
#define CLASS_ELEMENT_WATER 14
#define CLASS_SHAMAN        15
#define CLASS_DRUID         16
#define CLASS_BARD          17
#define CLASS_HUNTER        18
#define CLASS_ILLUSIONIST   19
#define CLASS_MONK          20
#define CLASS_MYSTIC        21
#define CLASS_NECROMANCER   22
#define CLASS_CHRONOMANCER  23
#define CLASS_WARLOCK       24
#define CLASS_ENSLAVER      25
#define CLASS_REAVER        26
#define CLASS_ENCHANTER     27
			
/*
 * Per-class stuff.
 */
struct	class_type
{
    char *	name;			/* Full class name		*/
    char *	who_name;		/* Three-letter name for 'who'	*/
    int 	attr_prime;		/* Prime attribute		*/
    int 	weapon;			/* First weapon			*/
    int 	skill_adept;		/* Maximum skill level		*/
    int 	thac0_00;		/* Thac0 for level  0		*/
    int 	thac0_47;		/* Thac0 for level 47		*/
    int  	hp_min;			/* Min hp gained on leveling	*/
    int	        hp_max;			/* Max hp gained on leveling	*/
    bool	fMana;			/* Class gains mana on level	*/
};

/*
 * An affect.
 */
struct	affect_data
{
    AFFECT_DATA *	next;
    int 		skill;
    int                 spell;
    int                 song;
    int 		duration;
    int 		location;
    int 		modifier;
    int			bitvector[NUM_AFFECT_VECTORS];
    int			level;
    bool                deleted;
};

struct bitvect_data
{
    const int group;
    const int vector;
};

/*
 * Resistant Immune Susceptible flags.
 */
#define RIS_NONE		      0
#define RIS_FIRE		   BV00
#define RIS_COLD		   BV01
#define RIS_ELECTRICITY		   BV02
#define RIS_ENERGY		   BV03
#define RIS_ACID		   BV04
#define RIS_POISON		   BV05
#define RIS_CHARM		   BV06
#define RIS_MENTAL		   BV07
#define RIS_WHITE_MANA		   BV08
#define RIS_BLACK_MANA		   BV09
#define RIS_DISEASE		   BV10
#define RIS_DROWNING		   BV11
#define RIS_LIGHT		   BV12
#define RIS_SOUND		   BV13
#define RIS_MAGIC		   BV14
#define RIS_NONMAGIC		   BV15
#define RIS_SILVER		   BV16
#define RIS_IRON		   BV17
#define RIS_WOOD		   BV18
#define RIS_WEAPON		   BV19
#define RIS_BASH		   BV20
#define RIS_PIERCE		   BV21
#define RIS_SLASH		   BV22
#define RIS_GAS                    BV23


/*
 * Damage types.
 */
#define DAM_NONE                      0		/*  weapon damage types */
#define DAM_BASH		      1
#define DAM_PIERCE		      2
#define DAM_SLASH		      3

#define DAM_OTHER		   1000		/* magical damage types */
#define DAM_FIRE		   1001
#define DAM_COLD		   1002
#define DAM_ELECTRICITY		   1003
#define DAM_ACID		   1004
#define DAM_POISON		   1005
#define DAM_CHARM		   1006
#define DAM_MENTAL                 1007
#define DAM_ENERGY                 1008
#define DAM_WHITE_MANA		   1009
#define DAM_BLACK_MANA		   1010
#define DAM_DISEASE                1011
#define DAM_DROWNING               1012
#define DAM_LIGHT                  1013
#define DAM_SOUND		   1014
#define DAM_HARM		   1015
#define DAM_DISINTEGRATION         1016
#define DAM_GAS                    1017
#define DAM_ASPHYXIATION           1018
#define DAM_WIND                   1019
#define DAM_CRUSHING               1020
#define DAM_EARTH                  1021 // When it damn well *has* to be elemental earth damage
#define DAM_WATER                  1022 // When it damn well *has* to be elemental water damage

/*
 * Return values for check_ris().
 */
#define IS_NORMAL               0
#define IS_RESISTANT            1
#define IS_IMMUNE               2
#define IS_SUSCEPTIBLE          3



/*
 * Types of attacks.
 * Must be non-overlapping with spell/skill types,
 * but may be arbitrary beyond that.
 */
#define TYPE_UNDEFINED               -1
#define TYPE_HIT                     1000

/*
 * School flags, used to define skill realm, to be implemented.
 */
#define SCHOOL_NONE                   0		/* no school realm required  */
#define SCHOOL_ABJURATION          BV00		/* abjuration magics	     */
#define SCHOOL_ALTERATION          BV01		/* alteration magics	     */
#define SCHOOL_CONJURATION         BV02		/* conjuration magics	     */
#define SCHOOL_SUMMONING           BV03		/* summoning magics	     */
#define SCHOOL_ILLUSION            BV04		/* illusionist magics	     */
#define SCHOOL_PHANTASM            BV05		/* phantasm projection realm */
#define SCHOOL_INVOCATION          BV06		/* invocation magics         */
#define SCHOOL_EVOCATION           BV07		/* evocative magics	     */
#define SCHOOL_ENCHANTMENT         BV08		/* enchantment magics	     */
#define SCHOOL_CHARM               BV09		/* charm skills		     */
#define SCHOOL_DIVINATION          BV10		/* divinatory arts	     */
#define SCHOOL_NECROMANCY          BV11		/* necromantic skills	     */
#define SCHOOL_OFFENSIVE           BV13		/* offensive martial arts    */
#define SCHOOL_DEFENSIVE           BV14		/* defensive martial arts    */
#define SCHOOL_STEALTH             BV15		/* stealth related skills    */
#define SCHOOL_SURVIVAL            BV16		/* wilderness suvival skills */
/*
 * Shaman school flags added by Veygoth
 * These will be used to determine the type of totem needed to cast them.
 */
#define SCHOOL_ELEMENTAL	   BV17
#define SCHOOL_SPIRITUAL	   BV18
#define SCHOOL_ANIMAL		   BV19
/*
 * Bard flags added by Veygoth.  These will determine whether a spell
 * is primarily of a particular instrument.  Those that can take more than
 * one instrument type will have them specified here.  The mana type will
 * be the primary (most powerful) instrument.  All others will be about
 * 50% as effective
 */
#define SCHOOL_HORN                BV20
#define SCHOOL_FLUTE               BV21
#define SCHOOL_MANDOLIN            BV22
#define SCHOOL_LYRE                BV23
#define SCHOOL_DRUMS               BV24
#define SCHOOL_HARP                BV25
#define SCHOOL_PIPES               BV26
#define SCHOOL_FIDDLE              BV27
#define SCHOOL_DULCIMER            BV28

/*
 * Mana types.
 */
#define MANA_ANY                     -1
#define MANA_NONE                     0
#define MANA_EARTH                 BV00
#define MANA_AIR                   BV01
#define MANA_FIRE                  BV02
#define MANA_WATER                 BV03
// Bard mana types
#define MANA_HORN                BV11
#define MANA_FLUTE               BV12
#define MANA_MANDOLIN            BV13
#define MANA_LYRE                BV14
#define MANA_DRUMS               BV15
#define MANA_HARP                BV16
#define MANA_PIPES               BV17
#define MANA_FIDDLE              BV18
#define MANA_DULCIMER            BV19
#define MANA_INSTRUMENT          BV20 // Instrument required (voice not necessary unless flagged)
#define MANA_VOICE               BV21 // Voice requireed
#define MANA_DANCE               BV22 // Dance required
#define MANA_INSTR_AUGMENT       BV23 // Augmented by instrument
#define MANA_DANCE_AUGMENT       BV24 // Augmented by dance
#define MANA_VOICE_AUGMENT       BV25 // Augmented by voice

/*
 * ACT bits for mobs.
 * Used in #MOBILES.
 */
#define ACT_IS_NPC		   BV03		/* Auto set for mobs	*/

/* 
 * Body parts.
 */
#define PART_NONE		      0
#define PART_HEAD		   BV00
#define PART_ARMS		   BV01
#define PART_LEGS		   BV02
#define PART_HEART		   BV03
#define PART_BRAINS		   BV04
#define PART_GUTS		   BV05
#define PART_HANDS		   BV06
#define PART_FEET		   BV07
#define PART_FINGERS		   BV08
#define PART_EAR		   BV09
#define PART_EYE		   BV10
#define PART_LONG_TONGUE	   BV11
#define PART_EYESTALKS		   BV12
#define PART_TENTACLES		   BV13
#define PART_FINS		   BV14
#define PART_WINGS		   BV15
#define PART_TAIL		   BV16
/*
 * Body parts used in combat.
 */
#define PART_CLAWS		   BV17
#define PART_FANGS		   BV18
#define PART_HORNS		   BV19
#define PART_SCALES		   BV20
#define PART_TUSKS		   BV21
// Plants
#define PART_BARK                  BV22
#define PART_LEAVES                BV23
#define PART_BRANCHES              BV24
#define PART_TRUNK                 BV25
// Trophies
#define PART_SCALP                 BV26
#define PART_CRANIAL_CHITIN        BV27

/*
 * Sex.
 * Used in #MOBILES.
 */
#define SEX_NEUTRAL		      0
#define SEX_MALE		      1
#define SEX_FEMALE		      2

/*
 * Item types.
 * Used in #OBJECTS.
 */
#define TYPE_LIGHT                    1
#define TYPE_SCROLL                   2
#define TYPE_WAND                     3
#define TYPE_STAFF                    4
#define TYPE_WEAPON                   5
#define TYPE_RANGED_WEAPON            6 // was 31
#define TYPE_MISSILEWEAP              7
#define TYPE_TREASURE                 8
#define TYPE_ARMOR                    9
#define TYPE_POTION                  10
#define TYPE_CLOTHING		     11 // not armor
#define TYPE_OTHER                   12
#define TYPE_TRASH                   13
#define TYPE_TRAP                    14
#define TYPE_CONTAINER               15
#define TYPE_NOTE                    16
#define TYPE_DRINK_CON               17
#define TYPE_KEY                     18
#define TYPE_FOOD                    19
#define TYPE_MONEY                   20
#define TYPE_PEN                     21 // includes quill
#define TYPE_BOAT                    22
//#define TYPE_BOOK                    23 Was in DE for a long time but never used
#define TYPE_BATTERY                 24  // don't think this will be used.
#define TYPE_TELEPORT                25
#define TYPE_TIMER                   26
#define TYPE_VEHICLE                 27
#define TYPE_SHIP                    28
#define TYPE_SWITCH                  29
#define TYPE_QUIVER	             30
#define TYPE_LOCKPICK                31
#define TYPE_INSTRUMENT              32
#define TYPE_SPELLBOOK               33
#define TYPE_TOTEM                   34
#define TYPE_STORAGECHEST            35
#define TYPE_SCABBARD                36
#define TYPE_SHIELD                  37
#define TYPE_CORPSE_NPC              38 // was 23
#define TYPE_CORPSE_PC               39 // was 24
#define TYPE_PORTAL                  40
#define TYPE_PILL                    41 // was 26 
#define TYPE_HERB                    42 // Sniktiorg's smokeables, use like potion but smoked
#define TYPE_MESSAGE_BOARD           43
#define TYPE_PIPE                    44 // Sniktiorg's smokeables
#define TYPE_WANTED_LIST             45
#define TYPE_WALL                    46
// 47 unused
#define TYPE_AMMO                    48 // was 32
// 49 unused
#define TYPE_ROPE                    50 // For mercs to capture with.
#define MAX_ITEM_TYPE                51

#define MAT_UNDEFINED              0
#define MAT_NONSUBSTANTIAL         1
#define MAT_FLESH                  2
#define MAT_CLOTH                  3
#define MAT_BARK                   4
#define MAT_SOFTWOOD               5
#define MAT_HARDWOOD               6
#define MAT_GLASS                  7
#define MAT_CRYSTAL                8
#define MAT_CERAMIC                9
#define MAT_BONE                   10
#define MAT_STONE                  11
#define MAT_HIDE                   12
#define MAT_LEATHER                13
#define MAT_CUREDLEATHER           14
#define MAT_IRON                   15
#define MAT_STEEL                  16
#define MAT_BRASS                  17
#define MAT_MITHRIL                18
#define MAT_ADAMANTIUM             19
#define MAT_BRONZE                 20
#define MAT_COPPER                 21
#define MAT_SILVER                 22
#define MAT_ELECTRUM               23
#define MAT_GOLD                   24
#define MAT_PLATINUM               25
#define MAT_GEM                    26
#define MAT_DIAMOND                27
#define MAT_PAPER                  28
#define MAT_PARCHMENT              29
#define MAT_LEAVES                 30
#define MAT_RUBY                   31
#define MAT_EMERALD                32
#define MAT_SAPPHIRE               33
#define MAT_IVORY                  34
#define MAT_DRAGONSCALE            35
#define MAT_OBSIDIAN               36
#define MAT_GRANITE                37
#define MAT_MARBLE                 38
#define MAT_LIMESTONE              39
#define MAT_LIQUID                 40
#define MAT_BAMBOO                 41
#define MAT_REEDS                  42
#define MAT_HEMP                   43
#define MAT_GLASSTEEL              44
#define MAT_EGGSHELL               45
#define MAT_CHITINOUS              46
#define MAT_REPTILESCALE           47
#define MAT_GENERICFOOD            48
#define MAT_RUBBER                 49
#define MAT_FEATHER                50
#define MAT_WAX                    51
#define MAT_PEARL                  52
#define MAT_SILK                   53
#define MAT_SPIDERSILK             54
#define MAT_JADE                   55
#define MAT_LEAD                   56
#define MAX_MATERIAL               56

// craftsmanship values - Veygoth
#define CRAFT_TERRIBLE		0
#define CRAFT_EXT_POOR          1
#define CRAFT_VERY_POOR         2
#define CRAFT_FAIRLY_POOR       3
#define CRAFT_WELL_BELOW_AVE    4
#define CRAFT_BELOW_AVE         5
#define CRAFT_SLIGHT_BELOW_AVE  6
#define CRAFT_AVERAGE           7
#define CRAFT_SLIGHT_ABOVE_AVE  8
#define CRAFT_ABOVE_AVE         9
#define CRAFT_WELL_ABOVE_AVE    10
#define CRAFT_EXCELLENT         11
#define CRAFT_SKILLED_ARTISAN   12
#define CRAFT_GIFTED_ARTISAN	13
#define CRAFT_MASTER_ARTISAN    14
#define CRAFT_ONEOFAKIND        15

/*
 * Well known room virtual numbers.
 * Defined in #ROOMS.
 */
#define ROOM_VNUM_TEMPLE	200

/*
 * Directions.
 * Used in #ROOMS.
 */
#define DIR_NORTH		      0
#define DIR_EAST		      1
#define DIR_SOUTH		      2
#define DIR_WEST		      3
#define DIR_UP			      4
#define DIR_DOWN		      5
#define DIR_NORTHWEST                 6
#define DIR_SOUTHWEST                 7
#define DIR_NORTHEAST                 8
#define DIR_SOUTHEAST                 9
#define MAX_DIR			     10


/*
 * Exit flags.
 * Used in #ROOMS.
 */
#define EX_ISDOOR		   BV00
#define EX_CLOSED		   BV01
#define EX_LOCKED		   BV02
// bv3 = rsclosed
// bv4 = rslocked
// bv5 = pickable
#define EX_SECRET                  BV06 // 64
#define EX_BLOCKED                 BV07 // 128
#define EX_PICKPROOF		       BV08 // 256
#define EX_WALLED                  BV09 // 512
#define EX_SPIKED                  BV10 // 1024
#define EX_ILLUSION                BV11 // 2048
#define EX_BASHED                  BV12 // 4096
#define EX_BASHPROOF               BV13 // 8192
#define EX_PASSPROOF               BV14 // 16384
#define EX_TRAPPED                 BV15 // 32768
#define EX_EAT_KEY                 BV16 // 65536 Destroys the key
#define EX_JAMMED                  BV17 // 131072

struct trap_data
{
	int trigger;
	int damage;
	int charges;
	int level;
	int percent;
};

// Trap types
#define TRAP_SLEEP	0
#define TRAP_TELEPORT   1
#define TRAP_FIRE       2
#define TRAP_COLD       3
#define TRAP_ACID       4
#define TRAP_ENERGY     5
#define TRAP_BLUNT      6
#define TRAP_PIERCING   7
#define TRAP_SLASHING   8
#define TRAP_DISPEL     9
#define TRAP_GATE       10
#define TRAP_SUMMON     11
#define TRAP_WITHER     12
#define TRAP_HARM       13
#define TRAP_POISON     14
#define TRAP_PARALYSIS  15
#define TRAP_STUN       16
#define TRAP_DISEASE    17
#define MAX_TRAP        18

// Trap triggers
#define TRIG_MOVE	BV00
#define TRIG_GETPUT	BV01
#define TRIG_FULLROOM   BV02
#define TRIG_NORTH      BV03
#define TRIG_EAST	BV04
#define TRIG_SOUTH	BV05
#define TRIG_WEST	BV06
#define TRIG_UP		BV07
#define TRIG_DOWN	BV08
#define TRIG_OPEN	BV09
#define TRIG_UNLIMITED  BV10
#define TRIG_GLYPH      BV11
#define TRIG_WEAR       BV12
#define TRIG_UNEQUIP    BV13
#define TRIG_STEAL      BV14
#define TRIG_ENCHANT    BV15
#define TRIG_UNCURSE    BV16

/*
 * Sector types.
 * Used in #ROOMS.
 */
#define SECT_INSIDE		      0
#define SECT_CITY		      1
#define SECT_FIELD		      2
#define SECT_FOREST		      3
#define SECT_HILLS		      4
#define SECT_MOUNTAIN		      5
#define SECT_WATER_SWIM		      6
#define SECT_WATER_NOSWIM	      7
#define SECT_AIR		      8 // Was SECT_UNDERWATER
#define SECT_UNDERWATER  	      9 // Was SECT_AIR
#define SECT_UNDERWATER_GROUND       10 // Was SECT_DESERT
#define SECT_PLANE_FIRE              11 // Was SECT_ICELAND
#define SECT_OCEAN                   12
#define SECT_UNDERG_WILD             13
#define SECT_UNDERG_CITY             14
#define SECT_UNDERG_INSIDE           15
#define SECT_UNDERG_WATER            16
#define SECT_UNDERG_WATER_NOSWIM     17
#define SECT_UNDERG_NOGROUND         18
#define SECT_PLANE_AIR               19
#define SECT_PLANE_WATER             20
#define SECT_PLANE_EARTH             21
#define SECT_PLANE_ETHEREAL          22
#define SECT_PLANE_ASTRAL            23
#define SECT_DESERT                  24
#define SECT_ARCTIC                  25
#define SECT_SWAMP                   26
#define SECT_ROAD                    27
#define SECT_UNDERG_IMPASSABLE       28
#define SECT_UNDERG_OCEAN            29
#define SECT_MAX		     30

struct extended_terrain
{
	int  extended_sector;
	char *room_title;
	char *room_description;
	int  main_sector; // Actual base terrain type
	char *map_char;  // Ansi displayed for that sector
    int visibility;  // Standard range of squares a player can see (radius)
};

#define MAX_EXTENDED_TERRAIN 155
#define EXT_ZONEMARKER        45

/*
* Positions.
*/
#define POS_DEAD 0
#define POS_MORTAL 1
#define POS_INCAP 2
#define POS_UNCONSCIOUS 3
#define POS_STUNNED 4
#define POS_SLEEPING 5
#define POS_RECLINING 6
#define POS_RESTING 7
#define POS_SITTING 8
#define POS_KNEELING 9
#define POS_FIGHTING 10
#define POS_STANDING 11

/*
* ACT bits for players.
*/
#define PLR_AUTOEXIT BV00
#define PLR_SHOUT BV01
#define PLR_CAMPING BV02
#define PLR_IS_NPC BV03 /* Don't EVER set. */
#define PLR_MEMORIZING BV04
#define PLR_MEDITATING BV05
#define PLR_BLANK BV06
#define PLR_BRIEF BV07
#define PLR_VICIOUS BV08
#define PLR_COMBINE BV09
#define PLR_PROMPT BV10
#define PLR_TELNET_GA BV11
#define PLR_HOLYLIGHT BV12
#define PLR_WIZINVIS BV13
#define PLR_WIZBIT BV14
#define PLR_SILENCE BV15
#define PLR_NO_EMOTE BV16
#define PLR_MOVED BV17
#define PLR_TELL BV18
#define PLR_LOG BV19
#define PLR_DENY BV20
#define PLR_FREEZE BV21
#define PLR_COLOR_CON BV22 // players see multicolored con messages
#define PLR_MAP BV23
#define PLR_CAST_TICK BV24
#define PLR_AFK BV25
#define PLR_COLOUR BV26
#define PLR_JUST_DIED BV27 // Just died flag, gives a player a few seconds of safe time after login
#define PLR_PAGER BV28
#define PLR_MOUNTABLE BV29 /* Can be mounted */
#define PLR_FOG BV30

/*
 * Prototype for a mob.
 * This is the in-memory version of #MOBILES.
 */
struct	mob_index_data
{
	MOB_INDEX_DATA * next;
	MOB_FUN * spec_fun;
	MOB_FUN * spec_fun2;
	MOB_FUN * death_fun;
	SHOP_DATA * pShop;
	AREA_DATA * area;
	char * player_name;
	char * short_descr;
	char * long_descr;
	char * description;
	int vnum;
	int count;
	int killed;
	int sex;
	int c_class;
	int level;
	int act;
	int affected_by[NUM_AFFECT_VECTORS];
	int alignment;
	int race;
	int position;
	int progtypes;
	int resistant;
	int immune;
	int susceptible;
};

struct quest_index_data
{
    int vnum; // vnum of mobile quest is attached to
    QUEST_DATA *quests; // the individual quests associated with each mob
    TALK_DATA *messages; // talk data associated with a mob
    QUEST_INDEX_DATA *next;
    AREA_DATA *area;
};

struct quest_data
{
    QUEST_DATA   *next;
    QUEST_ITEM   *receive;
    QUEST_ITEM   *give;
    char         *disappear;
    char         *complete;
};

struct talk_data
{
    TALK_DATA *next;
    char   *keywords;
    char   *message;
};

struct quest_item
{
    bool   complete;
    int    type;
    int    value;
    QUEST_ITEM *next;
};

struct coin_data
{
    int copper;
    int silver;
    int gold;
    int platinum;
};

struct	char_data
{
	CHAR_DATA * next;
	CHAR_DATA * next_in_room;
	CHAR_DATA * master;
	CHAR_DATA * group_leader;
	CHAR_DATA * fighting;
	CHAR_DATA * reply;
	CHAR_DATA * riding;
	CHAR_DATA * rider;
	CHAR_DATA * next_in_group;
	MOB_FUN * spec_fun;
	MOB_FUN * spec_fun2;
	MOB_INDEX_DATA * pIndexData;
	AFFECT_DATA * affected;
	OBJ_DATA * carrying;
	ROOM_INDEX_DATA * in_room;
	ROOM_INDEX_DATA * was_in_room;
	char * name;
	char * short_descr;
	char * long_descr;
	char * description;
	int sex;
	int c_class;
	int race;
	int level;
	int trust;
	int size;
	int played;
	int cast_spl;
	int cast_time;
	int perm_str;
	int perm_int;
	int perm_wis;
	int perm_dex;
	int perm_con;
	int perm_agi;
	int perm_cha;
	int perm_pow;
	int perm_luk;
	int mod_str;
	int mod_int;
	int mod_wis;
	int mod_dex;
	int mod_con;
	int mod_agi;
	int mod_cha;
	int mod_pow;
	int mod_luk;
	time_t logon;
	time_t save_time;
	time_t last_note;
	int timer;
	int wait;
	int hit;
	int max_hit;
	int mana;
	int max_mana;
	int move;
	int max_move;
	COIN_DATA money;
	int exp;
	int act;
	int affected_by[NUM_AFFECT_VECTORS];
	int position;
	int carry_weight;
	int carry_number;
	int saving_throw[5]; // added by Veygoth
	int alignment;
	int hitroll;
	int damroll;
	int armor;
	int wimpy;
	int deaf;
	bool deleted;
	int mpactnum;
	int resistant;
	int immune;
	int susceptible;
	int fly_level;
	int load_room_vnum;
};

#define LIQ_WATER        0
#define LIQ_MAX		29

struct	liq_type
{
    char               *liq_name;
    char               *liq_color;
    int                 liq_affect [ 3 ];
};

struct	extra_descr_data
{
	EXTRA_DESCR_DATA *next; /* Next in list */
	char *keyword; /* Keyword in look/examine */
	char *description; /* What to see */
	bool deleted;
};

struct	obj_index_data
{
	OBJ_INDEX_DATA * next;
	OBJ_FUN * spec_fun;
	EXTRA_DESCR_DATA * extra_descr;
	AFFECT_DATA * affected;
	TRAP_DATA * trap;
	char * name;
	char * short_descr;
	char * description;
	int vnum;
	int item_type;
	int extra_flags[NUM_ITEM_EXTRA_VECTORS];
	int affected_by[NUM_AFFECT_VECTORS];
	int wear_flags;
	int anti_flags;
	int anti_flags2;
	int material;
	int size;
	int volume;
	int craftsmanship;
	int count;
	int weight;
	int cost; /* Unused */
	int level;
	int progtypes;
	int condition;
	int value [ 8 ];
	AREA_DATA * area; /* OLC */
};

struct	obj_data
{
	OBJ_DATA * next;
	OBJ_DATA * next_content;
	OBJ_DATA * contains;
	OBJ_DATA * in_obj;
	OBJ_FUN * spec_fun;
	CHAR_DATA * carried_by;
	EXTRA_DESCR_DATA * extra_descr;
	AFFECT_DATA * affected;
	OBJ_INDEX_DATA * pIndexData;
	ROOM_INDEX_DATA * in_room;
	TRAP_DATA * trap;
	char * name;
	char * short_descr;
	char * description;
	int item_type;
	int extra_flags[NUM_ITEM_EXTRA_VECTORS];
	int affected_by[NUM_AFFECT_VECTORS];
	int wear_flags;
	int anti_flags;
	int anti_flags2;
	int material;
	int size;
	int volume;
	int craftsmanship;
	int wear_loc;
	int weight;
	int cost;
	int level;
	int timer;
	int value [ 8 ];
	int condition;
	bool deleted;
	int fly_level;
};

struct	exit_data
{
	ROOM_INDEX_DATA * to_room;
	int vnum;
	int exit_info;
	int key;
	char * keyword;
	char * description;
	EXIT_DATA *next;
};

/*
 * Reset commands:
 *   '*': comment
 *   'M': read a mobile 
 *   'O': read an object
 *   'P': put object in object
 *   'G': give object to mobile
 *   'E': equip object to mobile
 *   'D': set state of door
 *   'R': randomize room exits
 *   'S': stop (end of list)
 */

struct	reset_data
{
	RESET_DATA * next;
	char command;
	int arg0;
	int arg1;
	int arg2;
	int arg3;
	int arg4;
	int arg5;
	int arg6;
	int arg7;
};

struct	area_data
{
	AREA_DATA * next;
	RESET_DATA * reset_first;
	RESET_DATA * reset_last;
	char * name;
	int defender; // vnum of defending mobs for invasion
	int defender_num; // number of defenders that spawn
	int barracks; // vnum of room where guards spawn, if not given guards will spawn in judge room
	int judge; // vnum of room in which judge presides
	int jail; // vnum of room in which jail is
	int squads; // number of guard squads that cna be dispatched
	int dispatched;
	int recall;
	int version;
	int age;
	int nplayer;
	int justice;
	char * filename; /* OLC */
	char * builders; /* OLC Listing of builders */
	int security; /* OLC Value 0-infinity */
	int lvnum; /* OLC Lower vnum */
	int uvnum; /* OLC Upper vnum */
	int vnum; /* OLC Area vnum */
	int area_flags; /* OLC */
	int low_r_vnum;
	int hi_r_vnum;
	int low_o_vnum;
	int hi_o_vnum;
	int low_m_vnum;
	int hi_m_vnum;
	int llv;
	int ulv;
	char * author;
	char * resetmsg;
	int times_reset;
	int resetmode;
	int llifespan;
	int ulifespan;
};

/*
 * Room type.
 */
struct	room_index_data
{
	ROOM_INDEX_DATA * next;
	CHAR_DATA * people;
	OBJ_DATA * contents;
	EXTRA_DESCR_DATA * extra_descr;
	AREA_DATA * area;
	EXIT_DATA * exit [ MAX_DIR ];
	char * name;
	char * description;
	int vnum;
	int room_flags[NUM_ROOM_FLAGS];
	int orig_room_flags; /* OLC */
	int light;
	int current;
	int current_dir;
	int fall_chance;
	int sector_type;
	int extra_sector_info; // Worldmap sector info
	RESET_DATA * reset_first; /* OLC */
	RESET_DATA * reset_last; /* OLC */
};

struct	skill_type
{
	char * name; /* Name of skill */
	int skill_level [ MAX_CLASS ]; /* Level needed by class */
	int * pgsn; /* Pointer to associated gsn */
	int beats; /* Waiting time after use */
	char * noun_damage; /* Damage message */
	char * msg_off; /* Wear off message */
};

// May expand to include more damage messages - Veygoth.
struct	spell_type
{
	char * name; /* Name of skill */
	int spell_circle[ MAX_CLASS ]; /* Circle needed by class */
	int * pgsn; /* Pointer to associated gsn */
	int min_mana; /* Minimum mana used */
	int beats; /* Waiting time after use */
	char * msg_damage; /* Damage message */
	char * msg_damage_vict; /* Damage message to victim */
	char * msg_damage_room; /* Damage message to room */
	char * msg_damage_self; /* Damage message target self */
	char * msg_damage_self_rm; /* Room dmg msg, self = target*/
	char * msg_kill; /* Kill Message */
	char * msg_off; /* Wear off message */
	int realms; /* Skill realm requirements
	(Instrument required for bards) */
	int mana_type; /* Mana type (for spells)
	Instrument type (for bards) */
	bool can_scribe; /* Can the spell be scribed? */
};

struct	song_type
{
	const char * fullname; /* Name of skill */
	int spell_circle[ MAX_CLASS ]; /* Circle needed by class */
	const char * name; /* Name of skill */
	int * pgsn; /* Pointer to associated gsn */
	int min_mana; /* Minimum mana used */
	int beats; /* Waiting time after use */
	const char * msg_damage; /* Damage message */
	const char * msg_damage_vict; /* Damage message to victim */
	const char * msg_damage_room; /* Damage message to room */
	const char * msg_damage_self; /* Damage message target self */
	const char * msg_damage_self_rm; /* Room dmg msg, self = target*/
	const char * msg_kill; /* Kill Message */
	const char * msg_off; /* Wear off message */
	int realms; /* Skill realm requirements
	(Instrument required for bards) */
	int mana_type; /* Mana type (for spells)
	Instrument type (for bards) */
	bool can_scribe; /* Can the spell be scribed? */
};

bool    MOBtrigger;

extern int gsn_aware;
extern int gsn_appraise;
extern int gsn_alcohol_tolerance;
extern int gsn_backstab;
extern int gsn_bandage;
extern int gsn_bash;
extern int gsn_berserk;
extern int gsn_bladeflash;
extern int gsn_blindfighting;
extern int gsn_bodyslam; 
extern int gsn_charge;
extern int gsn_circle;
extern int gsn_disarm;
extern int gsn_dodge;
extern int gsn_drums;
extern int gsn_dulcimer;
extern int gsn_fiddle;
extern int gsn_flute;
extern int gsn_guard;
extern int gsn_headbutt;
extern int gsn_harp;
extern int gsn_hide;
extern int gsn_horn; 
extern int gsn_instant_kill;
extern int gsn_listen;
extern int gsn_lyre;
extern int gsn_mandolin;
extern int gsn_mounted_combat;
extern int gsn_peek;
extern int gsn_pick_lock;
extern int gsn_pickpocket;
extern int gsn_pipes;
extern int gsn_poison;
extern int gsn_poison_bite;
extern int gsn_poison_weapon;
extern int gsn_quick_chant;
extern int gsn_scrolls;
extern int gsn_summon_mount;
extern int gsn_capture;
extern int gsn_sneak;
extern int gsn_staves;
extern int gsn_steal;
extern int gsn_switch;
extern int gsn_untangle;
extern int gsn_wands;
extern int gsn_doorbash;
extern int gsn_dual;
extern int gsn_enhanced_damage;
extern int gsn_kick;
extern int gsn_parry;
extern int gsn_rescue;
extern int gsn_riposte;
extern int gsn_second_attack;
extern int gsn_singing;
extern int gsn_springleap;
extern int gsn_third_attack;
extern int gsn_throat_crush;
extern int gsn_throw;
extern int gsn_chameleon;
extern int gsn_heighten;
extern int gsn_shadow;
extern int gsn_shield_block;
extern int gsn_fast_healing;
extern int gsn_fourth_attack;
extern int gsn_brew;
extern int gsn_scribe;
extern int gsn_dirt;
extern int gsn_meditate;
extern int gsn_swim;
extern int gsn_track;
extern int gsn_trip;
extern int gsn_unarmed;
extern int gsn_whirlwind;
extern int gsn_mount;
extern int gsn_safe_fall;
extern int gsn_climb;
extern int gsn_tumble;

extern int gsn_hit;
extern int gsn_slash;
extern int gsn_pierce;
extern int gsn_whip;
extern int gsn_explode;
extern int gsn_pound;
extern int gsn_suction;
extern int gsn_shot;
extern int gsn_vampiric_bite;
extern int gsn_carve;
extern int gsn_layhands_timer;

extern int spl_acid_arrow;
extern int spl_acid_blast;
extern int spl_agitation;
extern int spl_agony;
extern int spl_aid;
extern int spl_airy_starshell;
extern int spl_airy_water;
extern int spl_animate_dead;
extern int spl_armor;
extern int spl_barkskin;
extern int spl_battle_ecstasy;
extern int spl_bear;
extern int spl_blending;
extern int spl_bless;
extern int spl_blur;
extern int spl_burning_hands;
extern int spl_blindness;
extern int spl_bombard;
extern int spl_burning_hands;
extern int spl_cause_critical;
extern int spl_cause_light;
extern int spl_cause_serious;
extern int spl_change_self;
extern int spl_charm_person;
extern int spl_chill_touch;
extern int spl_cloak_of_fear;
extern int spl_cold_ward;
extern int spl_cone_of_cold;
extern int spl_concealment;
extern int spl_conflaguration;
extern int spl_cowardice;
extern int spl_create_dracolich;
extern int spl_creeping_doom;
extern int spl_cure_blind;
extern int spl_cure_critical;
extern int spl_cure_light;
extern int spl_cutting_breeze;
extern int spl_ball_lightning;
extern int spl_cure_serious;
extern int spl_curse;
extern int spl_dazzle;
extern int spl_destroy_undead;
extern int spl_detect_evil;
extern int spl_detect_good;
extern int spl_detect_invis;
extern int spl_detect_magic;
extern int spl_detect_undead;
extern int spl_dexterity;
extern int spl_dirt_cloud;
extern int spl_disintegrate;
extern int spl_domination;
extern int spl_dust_blast;
extern int spl_earthen_grasp;
extern int spl_earthen_starshell;
extern int spl_earthen_tomb;
extern int spl_elemental_form;
extern int spl_fiery_starshell;
extern int spl_earthquake;
extern int spl_elemental_sight;
extern int spl_elephant;
extern int spl_enfeeblement;
extern int spl_enlarge;
extern int spl_enthrall;
extern int spl_energy_drain;
extern int spl_fear;
extern int spl_feeblemind;
extern int spl_fiery_starshell;
extern int spl_fireball;
extern int spl_fire_bolt;
extern int spl_fire_ward;
extern int spl_firestorm;
extern int spl_flameburst;
extern int spl_flame_shield;
extern int spl_flamestrike;
extern int spl_fly;
extern int spl_frost_shield;
extern int spl_fullheal;
extern int spl_full_harm;
extern int spl_giant_strength;
extern int spl_gr_earthen_grasp;
extern int spl_gr_mending;
extern int spl_harm;
extern int spl_haste;
extern int spl_hawk;
extern int spl_heal;
extern int spl_herbal_remedy;
extern int spl_hex;
extern int spl_holy_sacrifice;
extern int spl_hypnotic_pattern;
extern int spl_remove_poison;
extern int spl_resurrect;
extern int spl_heal_undead;
extern int spl_holy_word;
extern int spl_ice_bolt;
extern int spl_ice_missile;
extern int spl_identify;
extern int spl_immolate;
extern int spl_incendiary_cloud;
extern int spl_incompetence;
extern int spl_iceball;
extern int spl_ice_storm;
extern int spl_infravision;
extern int spl_invis;
extern int spl_levitation;
extern int spl_lightanddark;
extern int spl_lightning_bolt;
extern int spl_lightning_curtain;
extern int spl_ls_herbal_remedy;
extern int spl_ls_mending;
extern int spl_lion;
extern int spl_magic_missile;
extern int spl_magnetism;
extern int spl_major_globe;
extern int spl_malison;
extern int spl_mass_heal;
extern int spl_mass_invis;
extern int spl_mass_vortex_lift;
extern int spl_mending;
extern int spl_mermaids_kiss;
extern int spl_meteor;
extern int spl_minor_para;
extern int spl_m_blending;
extern int spl_mirage_arcana;
extern int spl_misdirection;
extern int spl_mole;
extern int spl_molten;
extern int spl_mouse;
extern int spl_nightmares;
extern int spl_panther;
extern int spl_pebble;
extern int spl_phantasmal_killer;
extern int spl_plague;
extern int spl_poison;
extern int spl_polymorph;
extern int spl_prismatic_spray;
extern int spl_protect_acid;
extern int spl_protect_cold;
extern int spl_protect_fire;
extern int spl_protect_gas;
extern int spl_protect_lightning;
extern int spl_protect_undead;
extern int spl_prot_evil;
extern int spl_prowess;
extern int spl_pythonsting;
extern int spl_raise_skeleton;
extern int spl_raise_spectre;
extern int spl_raise_vampire;
extern int spl_raise_wraith;
extern int spl_raise_lich;
extern int spl_raise_zombie;
extern int spl_ravenflight;
extern int spl_recall;
extern int spl_reduce;
extern int spl_rejuvenate;
extern int spl_scalding;
extern int spl_scathing_wind;
extern int spl_scorching;
extern int spl_shield;
extern int spl_shocking_grasp;
extern int spl_shock_shield;
extern int spl_shrew;
extern int spl_silence; 
extern int spl_sleep;
extern int spl_slowness;
extern int spl_snail;
extern int spl_soothe;
extern int spl_soul_disturbance;
extern int spl_soulshield;
extern int spl_spark;
extern int spl_spirit_anguish;
extern int spl_spirit_armor;
extern int spl_stoneskin;
extern int spl_stonestorm;
extern int spl_stornogs_spheres;
extern int spl_sunray;
extern int spl_sustenance;
extern int spl_telekinesis;
extern int spl_teleport;
extern int spl_turn_undead;
extern int spl_unholy_word;
extern int spl_vacancy;
extern int spl_vig_critical;
extern int spl_vig_light;
extern int spl_vig_serious;
extern int spl_vitality;
extern int spl_wall_of_fire;
extern int spl_wall_of_ice;
extern int spl_wall_of_mist;
extern int spl_wall_of_sparks;
extern int spl_water_breathing;
extern int spl_water_blast;
extern int spl_water_bolt;
extern int spl_watery_starshell;
extern int spl_wierd;
extern int spl_wither;
extern int spl_wolf;
extern int spl_ultra_death_ray;
extern int spl_cutting_breeze;
extern int spl_summon_elemental;
extern int spl_bonethunder;
// Traps
extern int trp_acid;
extern int trp_bash;
extern int trp_cold;
extern int trp_disease;
extern int trp_dispel;
extern int trp_energy;
extern int trp_fire;
extern int trp_gate;
extern int trp_harm;
extern int trp_para;
extern int trp_pierce;
extern int trp_poison;
extern int trp_slash;
extern int trp_sleep;
extern int trp_stun;
extern int trp_summon;
extern int trp_teleport;
extern int trp_wither;

extern int spl_tridenttides;
extern int spl_bird_prey;
extern int spl_darkness;
extern int spl_miners_intuition;
extern int spl_wall_iron;
extern int spl_wall_stone;
extern int spl_wall_force;
extern int spl_wall_illusion;
extern int spl_mirror_image;
extern int spl_shadow_monsters;
extern int spl_demi_shad_monster;
extern int spl_shades;
extern int spl_cloak_fear;
extern int spl_clone;
extern int spl_power_word_blind;
extern int spl_spook;
extern int spl_sunburst;
extern int spl_call_lightning;
extern int spl_gr_agony;
extern int spl_m_agony;
extern int spl_ravenous_vines;
extern int spl_change_sex;
extern int spl_color_spray;
extern int spl_prismatic_orb;
extern int spl_shadow_magic;
extern int spl_demi_shad_magic;
extern int spl_cone_silence;
extern int spl_continual_light;
extern int spl_twilight;
extern int spl_control_weather;
extern int spl_create_food;
extern int spl_conjure_windsaber;
extern int spl_celestial_sword;
extern int spl_create_skin;
extern int spl_create_spring;
extern int spl_create_watern;
extern int spl_purify_spirit;
extern int spl_purify;
extern int spl_cure_disease;
extern int spl_nourishment;
extern int spl_ls_nourishment;
extern int spl_gr_sustenance;
extern int spl_rain_maker;
extern int spl_destroy_cursed;
extern int spl_spirit_sight;
extern int spl_analyze_balance;
extern int spl_sense_life;
extern int spl_sense_spirit;
extern int spl_gr_spirit_sight;
extern int spl_true_seeing;
extern int spl_comp_lang;
extern int spl_detect_poison;
extern int spl_dispel_evil;
extern int spl_gleam_dawn;
extern int spl_gleam_dusk;
extern int spl_dispel_magic;
extern int spl_enchant_weapon;
extern int spl_exorcise;
extern int spl_faerie_fire;
extern int spl_faerie_fog;
extern int spl_reveal_true_form;
extern int spl_reveal_true_name;
extern int spl_dispel_invisible;
extern int spl_negate_veil;
extern int spl_negate_luster;
extern int spl_illumination;
extern int spl_bigby_fist;
extern int spl_akiaurn_word;
extern int spl_windsaber;
extern int spl_flight;
extern int spl_gr_ravenflight;
extern int spl_gate;
extern int spl_farsee;
extern int spl_know_alignment;
extern int spl_reveal_spirit_essence;
extern int spl_touch_nightshade;
extern int spl_locate_object;
extern int spl_minor_creation;
extern int spl_elemental_creation;
extern int spl_tidal_wave;
extern int spl_cyclone;
extern int spl_whirlwind;
extern int spl_inferno;
extern int spl_earthen_rain;
extern int spl_gr_soul_dist;
extern int spl_group_heal;
extern int spl_wellness;
extern int spl_pass_door;
extern int spl_gr_pythonsting;
extern int spl_call_wild;
extern int spl_minor_globe;
extern int spl_group_globe;
extern int spl_spirit_ward;
extern int spl_gr_spirit_ward;
extern int spl_deny_air;
extern int spl_deny_earth;
extern int spl_deny_fire;
extern int spl_deny_water;
extern int spl_protection_good;
extern int spl_harbor_balance;
extern int spl_adaptation;
extern int spl_recharge_item;
extern int spl_stamina;
extern int spl_gr_stamina;
extern int spl_remove_alignment;
extern int spl_preserve;
extern int spl_remove_curse;
extern int spl_negate_hex;
extern int spl_remove_silence;
extern int spl_sanctuary;
extern int spl_shadow_shield;
extern int spl_entangle;
extern int spl_thirst;
extern int spl_group_stone;
extern int spl_hurricane;
extern int spl_flashfire;
extern int spl_mass_dispel_magic;
extern int spl_stonestrength;
extern int spl_summon;
extern int spl_plane_shift;
extern int spl_flickering_flame;
extern int spl_ripple;
extern int spl_ventriloquate;
extern int spl_group_recall;
extern int spl_acid_breath;
extern int spl_fire_breath;
extern int spl_water_breath;
extern int spl_frost_breath;
extern int spl_gas_breath;
extern int spl_lightning_breath;
extern int spl_general_purpose;
extern int spl_high_explosive;
extern int spl_adrenaline_control;
extern int spl_aura_sight;
extern int spl_awe;
extern int spl_ballistic_attack;
extern int spl_biofeedback;
extern int spl_cell_adjustment;
extern int spl_combat_mind;
extern int spl_complete_healing;
extern int spl_control_flames;
extern int spl_create_sound;
extern int spl_deathfield;
extern int spl_detonate;
extern int spl_neurofrag;
extern int spl_displacement;
extern int spl_ectoplasmic_form;
extern int spl_ego_whip;
extern int spl_energy_containment;
extern int spl_enhance_armor;
extern int spl_enhanced_strength;
extern int spl_flesh_armor;
extern int spl_inertial_barrier;
extern int spl_inflict_pain;
extern int spl_intellect_fortress;
extern int spl_lend_health;
extern int spl_transfer_wellness;
extern int spl_mental_barrier;
extern int spl_mind_thrust;
extern int spl_project_force;
extern int spl_psionic_blast;
extern int spl_psychic_crush;
extern int spl_psychic_drain;
extern int spl_psychic_healing;
extern int spl_share_strength;
extern int spl_thought_shield;
extern int spl_ultrablast;
extern int spl_chain_lightning;
extern int spl_wizard_eye;
extern int spl_vortex_lift;
extern int spl_shadow_walk;
extern int spl_dimdoor;
extern int spl_migration;
extern int spl_shadow_door;
extern int spl_shadow_veil;
extern int spl_spirit_jump;
extern int spl_dispel_good;
extern int spl_judgement;
extern int spl_apocalypse;
extern int spl_power_word_lag;
extern int spl_power_word_stun;
extern int spl_etherportal;
extern int spl_moonwell;
extern int spl_wormhole;
extern int spl_create_buffet;
extern int spl_fireskin;
extern int spl_ethereal_shield;
extern int spl_sense_followers;
extern int spl_slow_poison;
extern int spl_acid_spray;
extern int spl_aura;
extern int spl_earthen_smith;
extern int spl_fiery_smith;
extern int spl_airy_smith;
extern int spl_aquatic_smith;
extern int spl_hover;
extern int spl_azure_flame;
extern int spl_gust_of_frost;
extern int spl_tide_seas;
extern int spl_dismissal;
extern int spl_summon_serpent;
extern int spl_summon_nerneid;
extern int spl_summon_pech;
extern int spl_summon_slyph;
extern int spl_summon_gr_elem;
extern int spl_hellfire;
extern int spl_embalm;
extern int spl_alacrity;
extern int spl_embalm;
extern int spl_aging;
extern int spl_vitalize_mana;
extern int spl_prot_from_undead;
extern int spl_shadow_breath2;
extern int spl_choke;
extern int spl_vampiric_touch;

extern int race_human;
extern int race_barbarian;
extern int race_grey_elf;
extern int race_rakshasa;
extern int race_half_elf;
extern int race_gnoll;
extern int race_drow_elf;
extern int race_dwarf;
extern int race_duergar;
extern int race_halfling;
extern int race_troll;
extern int race_ogre;
extern int race_orc;
extern int race_gnome;
extern int race_centaur;
extern int race_githyanki;
extern int race_goblin;
extern int race_minotaur;
extern int race_githzerai;
extern int race_illithid;
extern int race_thri_kreen;
extern int race_aquatic_elf;
extern int race_sahaugin;
extern int race_half_orc;
extern int race_half_dwarf;
extern int race_half_kobold;
extern int race_giant;
extern int race_neogi;
extern int race_kobold;
extern int race_dragon;
extern int race_hobgoblin;
extern int race_hobgoblin;
extern int race_humanoid;
extern int race_demon;
extern int race_god;
extern int race_devil;
extern int race_angel;
extern int race_faerie;
extern int race_vampire;
extern int race_werewolf;
extern int race_beholder;
extern int race_derro;
extern int race_golem;
extern int race_dracolich;
extern int race_dragonkin;
extern int race_insect;
extern int race_animal;
extern int race_herbivore;
extern int race_carnivore;
extern int race_bird;
extern int race_horse;
extern int race_primate;
extern int race_undead;
extern int race_ghost;
extern int race_harpy;
extern int race_bear;
extern int race_rust_monster;
extern int race_fire_elemental;
extern int race_air_elemental;
extern int race_water_elemental;
extern int race_earth_elemental;
extern int race_bat;
extern int race_plant;
extern int race_tree;
extern int race_rat;
extern int race_parasite;
extern int race_lycanthrope;
extern int race_arachnid;
extern int race_object;
extern int race_mist;
extern int race_snake;
extern int race_worm;
extern int race_fish;
extern int race_ixitxachitl;
extern int race_aboleth;
extern int race_hydra;
extern int race_reptile;
extern int race_boar;

/*
 * Utility macros.
 */
#define UMIN( a, b )		( ( a ) < ( b ) ? ( a ) : ( b ) )
#define UMAX( a, b )		( ( a ) > ( b ) ? ( a ) : ( b ) )
#define URANGE( a, b, c )	( ( b ) < ( a ) ? ( a )                       \
				                : ( ( b ) > ( c ) ? ( c )     \
						                  : ( b ) ) )
#define LOWER( c )		( ( c ) >= 'A' && ( c ) <= 'Z'                \
				                ? ( c ) + 'a' - 'A' : ( c ) )
#define UPPER( c )		( ( c ) >= 'a' && ( c ) <= 'z'                \
				                ? ( c ) + 'A' - 'a' : ( c ) )
#define IS_SET( flag, bit )	( ( flag ) &   ( bit ) )
#define SET_BIT( var, bit )     ( ( var )  |=  ( bit ) )
#define REMOVE_BIT( var, bit )  ( ( var )  &= ~( bit ) )
#define TOGGLE_BIT( var, bit )  ( ( var )  ^=  ( bit ) )

extern struct class_type * class_table [ MAX_CLASS ];
extern struct skill_type skills_table [ MAX_SKILL ];
extern struct spell_type spells_table [ MAX_SPELL ];
extern struct song_type songs_table [ MAX_SONG ];
extern const struct race_type race_table [ MAX_RACE ];
extern const char * lang_table [ MAX_LANG ];

/*
 * Global variables.
 */
extern HELP_DATA * help_first;
extern SHOP_DATA * shop_first;
extern QUEST_INDEX_DATA * quest_first;
extern CHAR_DATA * char_list;
extern OBJ_DATA * object_list;

extern AFFECT_DATA * affect_free;
extern CHAR_DATA * char_free;
extern EXTRA_DESCR_DATA * extra_descr_free;
extern OBJ_DATA * obj_free;
extern char bug_buf [ ];
extern time_t current_time;
extern FILE * fpReserve;
extern char log_buf [ ];
extern int top_note;
extern int top_event;
extern int top_desc;
extern int top_social;
extern int top_obj;
extern int top_char;
extern int top_pcdata;
extern int top_mvscript;

/*
 * Data files used by the server.
 *
 * AREA_LIST contains a list of areas to boot.
 * All files are read in completely at bootup.
 * Most output files (bug, idea, typo, shutdown) are append-only.
 *
 * The NULL_FILE is held open so that we have a stream handle in reserve,
 *   so players can go ahead and telnet to all the other descriptors.
 * Then we close it whenever we need to open a file (e.g. a save file).
 */
#if defined( unix ) || defined( linux )
#define PLAYER_DIR	"../player/"	/* Player files			*/
#define BACKUP_DIR	"../backup/"	/* Backup player files		*/
#define SYSTEM_DIR	"../sys/"	/* System directory		*/
#define CLASS_DIR	"../classes/"	/* New class loading scheme	*/
#define NULL_FILE	"/dev/null"	/* To reserve one stream	*/
#define AREA_DIR	"../area/"	/* Area files			*/
#define CLAN_DIR	"../clans/"	/* Clan files              	*/
#define MOB_DIR		"../mobprogs/"	/* MOBProg files		*/
#define OBJ_DIR         "../objprogs/"  /* OBJProg files                */
#endif

#if defined( WIN32 )
#define SYSTEM_DIR	"..\\sys\\"	/* System directory		*/
#define CLASS_DIR	"..\\classes\\"	/* New class loading scheme	*/
#define NULL_FILE	"nul"		/* To reserve one stream	*/
#define AREA_DIR	"..\\area\\"	/* Area files			*/
#define MOB_DIR		"..\\mobprogs\\"/* MOBProg files		*/
#define OBJ_DIR         "..\\objprogs\\"/* OBJProg files                */
#endif

#define AREA_LIST	 "AREA.LST"	/* List of areas		*/

#define CLASS_LIST	 "CLASS.LST"	/* List of classes		*/
#define CLANS_LIST	 "CLANS.LST"	/* List of clans		*/
#define BUG_FILE	 "BUGS.TXT"	/* For 'bug' and bug( )		*/

#define CD	CHAR_DATA
#define MID	MOB_INDEX_DATA
#define OD	OBJ_DATA
#define AD	AFFECT_DATA
#define ED	EXTRA_DESCR_DATA
#define OID	OBJ_INDEX_DATA
#define RID	ROOM_INDEX_DATA
#define MF	MOB_FUN
#define OF	OBJ_FUN
#define QID     QUEST_INDEX_DATA
#define QD      QUEST_DATA
#define QI      QUEST_ITEM
#define TD      TALK_DATA

/* comm.c */
const char* GetApplyName( int number );
char *strrepl(char *orgstr, char *oldstr, char *newstr);

/* const.c */
const char * size_string( int size );
void         load_classes( void );

/* db.c */
void	boot_db		args( ( void ) );
AD *	new_affect	args( ( void ) );
OD *	new_object	args( ( void ) );
ED *	new_extra_descr args( ( void ) );
QID *   create_quest    args( ( void ) );
QD  *   create_quest_data       args( ( void ) );
TD  *   create_quest_message    args( ( void ) );
QI  *   create_quest_item       args( ( void ) );
MID *	get_mob_index	args( ( int vnum ) );
OID *	get_obj_index	args( ( int vnum ) );
RID *	get_room_index	args( ( int vnum ) );
char	fread_letter	args( ( FILE *fp ) );
int	fread_number	args( ( FILE *fp, int *status ) );
char *	fread_string	args( ( FILE *fp, int *status ) );
void	fread_to_eol	args( ( FILE *fp ) );
char *	fread_word	args( ( FILE *fp, int *status ) );
void *	alloc_mem	args( ( int sMem ) );
void *	alloc_perm	args( ( int sMem ) );
void	free_mem	args( ( void *pMem, int sMem ) );
void	free_string	args( ( char *pstr ) );
int	number_fuzzy	args( ( int number ) );
int	number_range	args( ( int from, int to ) );
int	number_bits	args( ( int width ) );
int	number_mm	args( ( void ) );
int	dice		args( ( int number, int size ) );
void	smash_tilde	args( ( char *str ) );
bool	str_cmp		args( ( const char *astr, const char *bstr ) );
bool	str_prefix	args( ( const char *astr, const char *bstr ) );
bool	str_infix	args( ( const char *astr, const char *bstr ) );
bool	str_suffix	args( ( const char *astr, const char *bstr ) );
char *	capitalize	args( ( const char *str ) );
void	bug		args( ( const char *str, int param ) );
void	log_string	args( ( const char *str ) );

void	bugf		args( ( char *fmt, ... ) );
void	temp_fread_string	args( ( FILE *fp, char *str ) );
void	save_sysdata	args( ( void ) );
int     class_convert   args( ( int c_class ) );
int     duris_class_convert args( ( int c_class ) );

/* handler.c */
int     get_curr_race   args( ( CHAR_DATA *ch ) );
int     get_orig_race   args( ( CHAR_DATA *ch ) );
int     get_max_hit     args( ( CHAR_DATA *ch ) );
bool	is_name		args( ( const char *str, char *namelist ) );
bool    fill_coin_data  args( ( COIN_DATA *dest, char *argument, COIN_DATA *src ) );
int     get_sector      args( ( ROOM_INDEX_DATA *room ) );
CD   *  get_char        args( ( CHAR_DATA *ch ) );
void    end_of_game     args( ( void ) );
int	size_lookup	args( ( const char *size ) ); /* get size by name*/
int     race_lookup     args( ( const char *race ) );
int     race_key_lookup args( ( const char *race ) );
void    set_cost        args( ( OBJ_INDEX_DATA *obj ) );

/* interp.c */
bool	is_number	args( ( char *arg ) );
bool    char_is_number   args( ( char arg ) );
char *	one_argument	args( ( char *argument, char *arg_first ) );

int	skill_lookup	args( ( const char *name ) );
int	spell_lookup	args( ( const char *name ) );
int	song_lookup	args( ( const char *name ) );

/* progs.c */
#ifdef DUNNO_STRSTR
char *  strstr                  args ( (const char *s1, const char *s2 ) );
#endif

#undef	CD
#undef	MID
#undef	OD
#undef	OID
#undef	RID
#undef	MF
#undef	OF
#undef	SID
#undef	GF
#undef	CLD
#undef  EVD
#undef  VD

/*
 * This structure is used in spec_*.c to lookup spec funs and
 * also in olc_act.c to display listings of spec funs.
 */
struct spec_mob_type
{
    char *	spec_name;
    MOB_FUN *	spec_fun;
};

struct spec_obj_type
{
    char *	spec_name;
    OBJ_FUN *	spec_fun;
};

/* This structure is used in bit.c to lookup flags and stats */
struct flag_type
{
    char *	name;
    int		bit;
    bool	settable;
};

// This structure is used in bit.c to lookup flags and stats
// for bitvector-based values.
struct bitvector_flag_type
{
    char *	name;
    const BITVECT_DATA * bit;
    bool	settable;
};

/*
 * Area flags.
 */
#define AREA_NONE	     	      0
#define AREA_CHANGED		   BV00		/* Area has been modified    */
#define AREA_ADDED		   BV01		/* Area has been added to    */
#define AREA_LOADING		   BV02		/* Used for counting in db.c */
#define AREA_VERBOSE		   BV03

#define NO_FLAG			    -99		/* Must not be used in flags or stats */

/*
 * Global Constants
 */
extern  const   int			rev_dir         [ ];
extern  const   struct  spec_mob_type	spec_mob_table	[ ];
extern  const   struct  spec_obj_type	spec_obj_table	[ ];

/*
 * Global variables
 */
extern          AREA_DATA *             area_first;
extern          AREA_DATA *             area_last;
extern          SHOP_DATA *             shop_last;

extern          int                     top_affect;
extern          int                     top_area;
extern          int                     top_ed;
extern          int                     top_exit;
extern          int                     top_help;
extern          int                     top_mob_index;
extern          int                     top_obj_index;
extern          int                     top_reset;
extern          int                     top_room;
extern          int                     top_shop;

extern          int                     top_vnum_mob;
extern          int                     top_vnum_obj;
extern          int                     top_vnum_room;

extern          char                    str_empty       [1];

extern		MOB_INDEX_DATA    *	mob_index_hash	[ MAX_KEY_HASH ];
extern		OBJ_INDEX_DATA    *	obj_index_hash	[ MAX_KEY_HASH ];
extern		ROOM_INDEX_DATA   *	room_index_hash [ MAX_KEY_HASH ];

/* spec_mob.c */
MOB_FUN * spec_mob_lookup( const char *name );
OBJ_FUN *spec_obj_lookup( const char *name );

#endif
