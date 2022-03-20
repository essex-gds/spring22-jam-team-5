#ifndef BAWL_TILEMAPENUM_H
#define BAWL_TILEMAPENUM_H

// use this for values that will never change ( IE not part of a level )
enum tileMap
{
	TILE_DEFAULT = 0,
	TILE_PLAYER  = 1,
	TILE_PLAYER_UP,
	TILE_PLAYER_DOWN,
	TILE_SEEKER,
	TILE_SEEKER_ACTIVE,
	TILE_CIRC,
	/* RESERVED RANGE     */
	TILE_A = 'A',
	TILE_B,
	TILE_C,
	TILE_D,
	TILE_E,
	TILE_F,
	TILE_G,
	TILE_H,
	TILE_I,
	TILE_J,
	TILE_K,
	TILE_L,
	TILE_M,
	TILE_N,
	TILE_O,
	TILE_P,
	TILE_Q,
	TILE_R,
	TILE_S,
	TILE_T,
	TILE_U,
	TILE_V,
	TILE_W,
	TILE_X,
	TILE_Y,
	TILE_Z = 'Z'
	/* END RESERVED RANGE */
};

#endif // BAWL_TILEMAPENUM_H
