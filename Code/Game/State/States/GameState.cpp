#include "GameState.h"

inline static auto blankGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
	                   };

inline static auto bomberGroup =
	                   std::vector{
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_SEEKER,
		                   SHIP_SEEKER,
		                   SHIP_SEEKER,
		                   SHIP_SEEKER,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
	                   };

inline static auto singleGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
	                   };

inline static auto doubleGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
	                   };

inline static auto tripleGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
	                   };

inline static auto wingGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
	                   };

inline static auto seekGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_SEEKER,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
	                   };

inline static auto wideSeekGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_SEEKER,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_SEEKER,
		                   SHIP_NONE,
		                   SHIP_NONE,
	                   };


void GameState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	/////////////
	/// SETUP ///
	/////////////
	GLOG_INFO("GameState pushed");
	stateBallPtr->mDisplayPtr->showWindow();
	mLevel  = {};
	mCamera = {};
	mLevel = Level::create(70,50);
	mCamera.init(70,40);
	mCamera.mScrollEnabled = true;
	stateBallPtr->mLevel     = mLevel;
	stateBallPtr->mCameraPtr = &mCamera;
	stateBallPtr->repack();

	mLevel->mTileMap[0] = TILE_CIRC;
	mLevel->mTileMap[1] = TILE_CIRC;
	mLevel->mTileMap[2] = TILE_CIRC;
	memset(mLevel->mOverMap,' ',mLevel->mWidth * mLevel->mHeight);
	memset(mLevel->mCharMap,' ',mLevel->mWidth * mLevel->mHeight);

	auto* es = new EntityUpdateState();
	es->addEntity( new Player(stateBallPtr));
	auto spawner = new ShipSpawnerEntity();
	es->addEntity(spawner);
	stack->push(es);

	/////////////
	/// WAVES ///
	/////////////

	auto* wav = new ShipWave();
	wav->mShipsToSpawn = blankGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = singleGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = wideSeekGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = wideSeekGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

}

void GameState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("GameState popped");
}

void GameState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{

}
