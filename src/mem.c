
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merc.h"

HELP_DATA *		help_last;
extern	int		top_reset;
extern	int		top_area;
extern	int		top_exit;
extern	int		top_ed;
extern	int		top_room;

RESET_DATA *new_reset_data( void )
{
    RESET_DATA *pReset;

	pReset = alloc_perm( sizeof( *pReset ) );
	top_reset++;

    pReset->next	= NULL;
    pReset->command	= 'X';
    pReset->arg1	= 0;
    pReset->arg2	= 0;
    pReset->arg3	= 0;

    return pReset;
}

AREA_DATA *new_area( void )
{
    AREA_DATA *pArea;
    char       buf[ MAX_INPUT_LENGTH ];

	pArea = alloc_perm( sizeof( *pArea ) );
	top_area++;

    pArea->next		= NULL;
    pArea->name		= str_dup( "New area" );
    pArea->recall	= ROOM_VNUM_TEMPLE;
    pArea->area_flags	= AREA_ADDED;
    pArea->security	= 1;
    pArea->builders	= str_dup( "None" );
    pArea->lvnum	= 0;
    pArea->uvnum	= 0;
    pArea->age		= 0;
    pArea->nplayer	= 0;
    pArea->vnum		= top_area - 1;

    sprintf( buf, "area%d.are", pArea->vnum );
    pArea->filename 	= str_dup( buf );

    return pArea;
}

ROOM_INDEX_DATA *new_room_index( void )
{
    ROOM_INDEX_DATA *pRoom;
    int              door;

	pRoom = alloc_perm( sizeof( *pRoom ) );
	top_room++;

    pRoom->next		= NULL;
    pRoom->people	= NULL;
    pRoom->contents	= NULL;
    pRoom->extra_descr	= NULL;
    pRoom->area		= NULL;

    for ( door = 0; door < MAX_DIR; door++ )
	pRoom->exit[door] = NULL;

    pRoom->name		= &str_empty[0];
    pRoom->description	= &str_empty[0];
    pRoom->vnum		= 0;
    pRoom->room_flags[0]= 0;
    pRoom->room_flags[1]= 0;
    pRoom->light	= 0;
    pRoom->sector_type	= 0;

    return pRoom;
}

SHOP_DATA *new_shop( void )
{
    SHOP_DATA *pShop;
    int        buy;

	pShop = alloc_perm( sizeof( *pShop ) );
	top_shop++;

    pShop->next = NULL;
    pShop->keeper = 0;

    for ( buy = 0; buy < MAX_BUY; buy++ )
	pShop->buy_type[buy] = 0;
    for ( buy = 0; buy < MAX_SELL; buy++ )
	pShop->sell_item[buy] = 0;

    pShop->profit_buy	= 100;
    pShop->profit_sell	= 100;
    pShop->open_hour	= 0;
    pShop->close_hour	= 23;

    return pShop;
}

OBJ_INDEX_DATA *new_obj_index( void )
{
    OBJ_INDEX_DATA *pObj;
    int             value;
    int             count;

	pObj = alloc_perm( sizeof( *pObj ) );
	top_obj_index++;

    pObj->next		= NULL;
    pObj->extra_descr	= NULL;
    pObj->affected	= NULL;
    pObj->area		= NULL;
    pObj->name		= str_dup( "no name" );
    pObj->short_descr	= str_dup( "(no short description)" );
    pObj->description	= str_dup( "(no description)" );
    pObj->vnum		= 0;
    pObj->item_type	= TYPE_TRASH;
    for( count = 0; count < NUM_ITEM_EXTRA_VECTORS; count++)
      pObj->extra_flags[count] = 0;
    pObj->wear_flags	= 0;
    pObj->count		= 0;
    pObj->weight	= 0;
    pObj->cost		= 0;

    for ( value = 0; value < 5; value++ )
	pObj->value[value] = 0;

    return pObj;
}

MOB_INDEX_DATA *new_mob_index( void )
{
    MOB_INDEX_DATA *pMob;
    int count;

	pMob = alloc_perm( sizeof( *pMob ) );
	top_mob_index++;

    pMob->next		= NULL;
    pMob->spec_fun	= NULL;
    pMob->pShop		= NULL;
    pMob->area		= NULL;
    pMob->player_name	= str_dup( "no name" );
    pMob->short_descr	= str_dup( "(no short description)" );
    pMob->long_descr	= str_dup( "(no long description)\r\n" );
    pMob->description	= &str_empty[0];
    pMob->vnum		= 0;
    pMob->count		= 0;
    pMob->killed	= 0;
    pMob->sex		= 0;
    pMob->level		= 0;
    pMob->act		= ACT_IS_NPC;
    for( count = 0; count < NUM_AFFECT_VECTORS; count++ )
    {
       pMob->affected_by[count]	= 0;
    }
    pMob->alignment	= 0;

    return pMob;
}

