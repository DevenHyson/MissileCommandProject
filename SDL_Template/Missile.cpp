#include "Missile.h"
#include "BoxCollider.h"
#include "PhysicsManager.h"
#include "GLTexture.h"

Missile::Missile(Vector2 spawnpoint, Vector2 target, bool friendly) {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mRandom = Random::Instance();

	mVisible = false;
	mWasHit = false;
	mFriendly = friendly;

	if (mFriendly) {
		mTexture = new GLTexture("PlayerMissile.png");
		mSpawn = spawnpoint;
		mTarget = target;
	}
	else {
		mTexture = new GLTexture("EnemyMissile.png");

		// set random spawn point
		mSpawn.y = 0.0f;
		mSpawn.x = (float)(mRandom->RandomInt() % Graphics::Instance()->SCREEN_WIDTH);

		// set random target point (6 cities, 3 turrets)
		switch (mRandom->RandomRange(1, 6)) {
		case 1:
			mTarget = Vector2(262, 1028);
			mTargetCity = 1;
			break;
		case 2:
			mTarget = Vector2(517, 1028);
			mTargetCity = 2;
			break;
		case 3:
			mTarget = Vector2(765, 1028);
			mTargetCity = 3;
			break;
		case 4:
			mTarget = Vector2(1191, 1028);
			mTargetCity = 4;
			break;
		case 5:
			mTarget = Vector2(1441, 1028);
			mTargetCity = 5;
			break;
		case 6:
			mTarget = Vector2(1692, 1028);
			mTargetCity = 6;
			break;
		default:
			std::cout << "ERROR: We should never get here.  Missile.cpp (line 51)" << std::endl;
			break;
		}
	}
	
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);

	mMoveSpeed = 300.0f;

	Position(mSpawn);

	// calculate velocity of missile based on startpoint, endpoint, and movespeed (*round)
	mVelocity = mTarget - mSpawn;

	Rotate(mVelocity.ToAngle());

	AddCollider(new BoxCollider(Vector2(mTexture->ScaledDimensions().x, mTexture->ScaledDimensions().y)));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::HostileProjectiles);

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
	if (Position().x != mTarget.x && Position().y != mTarget.y){
		Translate(mVelocity.Normalized() * mMoveSpeed * mTimer->DeltaTime(), World);
	}

	//this->Scale(Vector2(Scale().x * 1.05, Scale().y * 1.05));

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

	PhysEntity::Render();
}