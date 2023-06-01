#include "Missile.h"
#include "BoxCollider.h"
#include "PhysicsManager.h"
#include "GLTexture.h"


Missile::Missile() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mRandom = Random::Instance();

	mVisible = false;
	mWasHit = false;

	mTexture = new GLTexture("Hill.png", 0, 150, 100, 100);
	//mTexture->Scale(Vector2(0.3f, 0.3f));
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);

	mMoveSpeed = 300.0f;
	mMoveBounds = Vector2(0.0f, 1920.0f);

	// set random spawn point
	mSpawn.y = 0.0f;
	mSpawn.x = (float)(mRandom->RandomInt() % Graphics::Instance()->SCREEN_WIDTH);

	Position(mSpawn);

	// set random target point (6 cities, 3 turrets)
	switch (mRandom->RandomRange(1, 6)) {
	case 1:
		mTarget = Vector2(262, 1028);
		break;
	case 2:
		mTarget = Vector2(517, 1028);
		break;
	case 3:
		mTarget = Vector2(765, 1028);
		break;
	case 4:
		mTarget = Vector2(1191, 1028);
		break;
	case 5:
		mTarget = Vector2(1441, 1028);
		break;
	case 6:
		mTarget = Vector2(1692, 1028);
		break;
	default:
		std::cout << "ERROR: We should never get here.  Missile.cpp (line 51)" << std::endl;
		break;
	}

	// calculate velocity of missile based on startpoint, endpoint, and movespeed (*round)
	mVelocity = mTarget - mSpawn;

	/*AddCollider(new BoxCollider(Vector2(16.0f, 67.0f)));
	AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(18.0f, 10.0f));
	AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(-18.0f, 10.0f));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);*/

	Visible(true);
}

Missile::~Missile() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mTexture;
	mTexture = nullptr;
}

void Missile::Visible(bool visible) {
	mVisible = visible;
}

bool Missile::IgnoreCollisions()
{
	return !mVisible;
}

void Missile::Hit(PhysEntity* other) {

}

bool Missile::WasHit() {
	return mWasHit;
}

void Missile::Update() {

	// figure out what targetVector is based on start and end point

	Translate(mVelocity.Normalized() * mMoveSpeed * mTimer->DeltaTime(), World);

	Vector2 pos = Position(Local);

	Position(pos);

	// Check collision
	// Remove from list
	// Spawn new missile?
}

void Missile::Render() {

	if (mVisible) {
		mTexture->Render();
	}

	//PhysEntity::Render();
}