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

inline static auto highGroup =
	                   std::vector{
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
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_STANDARD,
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

inline static auto runnerGroup =
	                   std::vector{
		                   SHIP_RUNNER,
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
		                   SHIP_RUNNER,
	                   };

inline static auto topGroup =
	                   std::vector{
		                   SHIP_RUNNER,
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


inline static auto bottomGroup =
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
		                   SHIP_RUNNER,
	                   };

inline static auto bossGroup =
	                   std::vector{
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_NONE,
		                   SHIP_BOSS,
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

inline static auto endGroup =
	                   std::vector{
		                   SHIP_END,
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


void GameState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	initAudio();
	playMusic("../../../Assets/tune.wav",100);
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


	wav = new ShipWave();
	wav->mShipsToSpawn = singleGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = topGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = wideSeekGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = bomberGroup;
	wav->mTimeToNextWave = 10;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = wingGroup;
	wav->mTimeToNextWave = 8;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = bossGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);


	wav = new ShipWave();
	wav->mShipsToSpawn = runnerGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = runnerGroup;
	wav->mTimeToNextWave = 8;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = doubleGroup;
	wav->mTimeToNextWave = 8;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = seekGroup;
	wav->mTimeToNextWave = 8;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = highGroup;
	wav->mTimeToNextWave = 8;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = highGroup;
	wav->mTimeToNextWave = 8;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = wingGroup;
	wav->mTimeToNextWave = 12;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = runnerGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = topGroup;
	wav->mTimeToNextWave = 1;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = seekGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = wingGroup;
	wav->mTimeToNextWave = 1;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = bottomGroup;
	wav->mTimeToNextWave = 14;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = wideSeekGroup;
	wav->mTimeToNextWave = 7;
	spawner->addWave(wav);

	wav = new ShipWave();
	wav->mShipsToSpawn = tripleGroup;
	wav->mTimeToNextWave = 1;
	spawner->addWave(wav);




	wav = new ShipWave();
	wav->mShipsToSpawn = endGroup;
	wav->mTimeToNextWave = 4;
	spawner->addWave(wav);

}

void GameState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("GameState popped");
}

void GameState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	if (sGameOver)
	{
		mCamera.mX    = 0;
		mCamera.mY    = 0;
		mCamera.mSubX = 0;
		auto* message = NString::create("YOU LOSE");
		auto* opts    = new std::vector<NString*>();
		opts->push_back(NString::create(" ? "));
		opts->push_back(NString::create(" IN WAR THERE IS NO PLAY AGAIN "));

		auto* menu = new TextChoiceState(0, 0, message, *opts, 0, [opts, stack](auto i, auto dir)
		{
			if (i == 1)
			{
				::exit(0);
			}
		});

		stack->push(menu);
	}

	if (sGameWin)
	{
		mCamera.mX    = 0;
		mCamera.mY    = 0;
		mCamera.mSubX = 0;
		auto* message = NString::create("YOU WON");
		auto* opts    = new std::vector<NString*>();
		opts->push_back(NString::create(" YAY "));
		opts->push_back(NString::create(" BYE! "));

		auto* menu = new TextChoiceState(0, 0, message, *opts, 0, [opts, stack](auto i, auto dir)
		{
			if (i == 1)
			{
				::exit(0);
			}
		});

		stack->push(menu);
	}
}
