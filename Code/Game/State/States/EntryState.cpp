#include "EntryState.h"

EntryState::EntryState(Display* display)
{
	mDisplayPtr = display;
}

void EntryState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("EntryState pushed");
	if(from != nullptr)
	{
		GLOG_INFO("Entry has been called from an exising state, are you sure you wanted to do that?");
	}

	stateBallPtr->mDisplayPtr = mDisplayPtr;
	stateBallPtr->mDisplayPtr->showWindow();

	hash_t texHash;

	texHash = TextureMap::requestTexture("player_idle.bmp");
	mDisplayPtr->setTexture(TILE_PLAYER,texHash);
	texHash =TextureMap::requestTexture("player_up.bmp");
	stateBallPtr->mDisplayPtr->setTexture(TILE_PLAYER_UP, texHash);
	texHash =TextureMap::requestTexture("player_down.bmp");
	stateBallPtr->mDisplayPtr->setTexture(TILE_PLAYER_DOWN, texHash);

	texHash =TextureMap::requestTexture("seeker_active1.bmp");
	stateBallPtr->mDisplayPtr->setTexture(TILE_SEEKER, texHash);
	texHash =TextureMap::requestTexture("seeker_active2.bmp");
	stateBallPtr->mDisplayPtr->setTexture(TILE_SEEKER_ACTIVE, texHash);

	texHash =TextureMap::requestTexture("boss.bmp");
	stateBallPtr->mDisplayPtr->setTexture(TILE_BOSS, texHash);

	texHash =TextureMap::requestTexture("CIRC_TEXTURE.bmp");
	stateBallPtr->mDisplayPtr->setTexture(TILE_CIRC, texHash);


	texHash = TextureMap::requestTexture("A.bmp");
	mDisplayPtr->setTexture('A',texHash);
	texHash = TextureMap::requestTexture("B.bmp");
	mDisplayPtr->setTexture('B',texHash);
	texHash = TextureMap::requestTexture("C.bmp");
	mDisplayPtr->setTexture('C',texHash);
	texHash = TextureMap::requestTexture("D.bmp");
	mDisplayPtr->setTexture('D',texHash);
	texHash = TextureMap::requestTexture("E.bmp");
	mDisplayPtr->setTexture('E',texHash);
	texHash = TextureMap::requestTexture("F.bmp");
	mDisplayPtr->setTexture('F',texHash);
	texHash = TextureMap::requestTexture("G.bmp");
	mDisplayPtr->setTexture('G',texHash);
	texHash = TextureMap::requestTexture("H.bmp");
	mDisplayPtr->setTexture('H',texHash);
	texHash = TextureMap::requestTexture("I.bmp");
	mDisplayPtr->setTexture('I',texHash);
	texHash = TextureMap::requestTexture("J.bmp");
	mDisplayPtr->setTexture('J',texHash);
	texHash = TextureMap::requestTexture("L.bmp");
	mDisplayPtr->setTexture('L',texHash);
	texHash = TextureMap::requestTexture("K.bmp");
	mDisplayPtr->setTexture('K',texHash);
	texHash = TextureMap::requestTexture("M.bmp");
	mDisplayPtr->setTexture('M',texHash);
	texHash = TextureMap::requestTexture("N.bmp");
	mDisplayPtr->setTexture('N',texHash);
	texHash = TextureMap::requestTexture("L.bmp");
	mDisplayPtr->setTexture('L',texHash);
	texHash = TextureMap::requestTexture("O.bmp");
	mDisplayPtr->setTexture('O',texHash);
	texHash = TextureMap::requestTexture("P.bmp");
	mDisplayPtr->setTexture('P',texHash);
	texHash = TextureMap::requestTexture("Q.bmp");
	mDisplayPtr->setTexture('Q',texHash);
	texHash = TextureMap::requestTexture("R.bmp");
	mDisplayPtr->setTexture('R',texHash);
	texHash = TextureMap::requestTexture("S.bmp");
	mDisplayPtr->setTexture('S',texHash);
	texHash = TextureMap::requestTexture("T.bmp");
	mDisplayPtr->setTexture('T',texHash);
	texHash = TextureMap::requestTexture("V.bmp");
	mDisplayPtr->setTexture('U',texHash);
	texHash = TextureMap::requestTexture("V.bmp");
	mDisplayPtr->setTexture('V',texHash);
	texHash = TextureMap::requestTexture("W.bmp");
	mDisplayPtr->setTexture('W',texHash);
	texHash = TextureMap::requestTexture("X.bmp");
	mDisplayPtr->setTexture('X',texHash);
	texHash = TextureMap::requestTexture("Y.bmp");
	mDisplayPtr->setTexture('Y',texHash);
	texHash = TextureMap::requestTexture("Z.bmp");
	mDisplayPtr->setTexture('Z',texHash);

	texHash = TextureMap::requestTexture("GT.bmp");
	mDisplayPtr->setTexture('>',texHash);
	texHash = TextureMap::requestTexture("LT.bmp");
	mDisplayPtr->setTexture('<',texHash);

	texHash =TextureMap::requestTexture("BLANK_TEXTURE.bmp");
	stateBallPtr->mDisplayPtr->setTexture(' ', texHash);
}

void EntryState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("EntryState popped");
	stack->push(new MainMenuState());
}

void EntryState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	stack->pop();
}


