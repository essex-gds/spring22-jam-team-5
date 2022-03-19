#include "TestState.h"

static Sprite* s;

void TestState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("TestState pushed");
	stateBallPtr->mDisplayPtr->showWindow();

	mLevel  = {};
	mCamera = {};

	Level* l = Level::create(70,40);
	mCamera.init(70,40);

	mCamera.mScrollEnabled = true;

	stateBallPtr->mLevel     = l;
	stateBallPtr->mCameraPtr = &mCamera;
	stateBallPtr->repack();

	memset(l->mOverMap,' ',l->mWidth * l->mHeight);
	memset(l->mCharMap,' ',l->mWidth * l->mHeight);

	s = (Sprite*) malloc(sizeof(Sprite));

	s->mTileIndex = 3;
	s->mWidth =  96;
	s->mHeight = 96;
	s->mX = 0;
	s->mY = 0;

	stateBallPtr->mDisplayPtr->addSprite(s);

	SpriteTransitionState* stPtr = new SpriteTransitionState(s,300,300,0.5f, [stack](Sprite* m)
	{
		SpriteTransitionState* stPtr2 = new SpriteTransitionState(s,300,0,0.5f, nullptr);
		stack->push(stPtr2);
	});

	stack->push(stPtr);

	std::vector<NString*>* choices = new std::vector<NString*>();
	NString* test = NString::create(    " LIBERATION");
	choices->push_back( NString::create(" PLAY   ") );
	choices->push_back( NString::create(" OPTION ") );
	choices->push_back( NString::create(" OPTION ") );
	choices->push_back( NString::create(" EXIT   ") );


	EntityUpdateState* es = new EntityUpdateState();

	stack->push(es);


	TextChoiceState* pp =  new TextChoiceState(0, 0, test, *choices,
						   0, [es,stateBallPtr, stack](int8_t i, int8_t d){
			printf("%d %d\n",i, d);

			SpriteTransitionState* stPtr = new SpriteTransitionState(s,300,300,0.5f, [stack](Sprite* m)
			{
				SpriteTransitionState* stPtr2 = new SpriteTransitionState(s,300,0,0.5f, nullptr);
				stack->push(stPtr2);
			});

			if( i == 0 && d == 1 )
			{
				stack->push(stPtr);
			}

			if(i == 1 && d == 1)
			{

			}

			if(i == 2)
			{

				Entity* e = new Player(stateBallPtr->mDisplayPtr);

				es->addEntity(e);

			}

			if(i == 3)
			{
				::exit(0);
			}
	});

	stack->push(pp);
}

void TestState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("TestState popped");
}

void TestState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{

}
