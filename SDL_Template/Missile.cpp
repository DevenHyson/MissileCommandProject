#include "Missile.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "PhysicsManager.h"
#include "GLTexture.h"

Missile::Missile(Vector2 spawnpoint, Vector2 target, bool friendly) {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mRandom = Random::Instance();

	mVisible = false;
	mWasHit = false;
	mFriendly = friendly;
	mExplodeFinished = false;
	mTag = "Missile";

	if (mFriendly) {
		mTexture = new GLTexture("PlayerMissile.png");
		mSpawn = spawnpoint;
		mTarget = target;

		AddCollider(new CircleCollider(mTexture->ScaledDimensions().x * 0.5));

		mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::FriendlyProjectiles);
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

		AddCollider(new CircleCollider(mTexture->ScaledDimensions().x * 0.5));

		mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::HostileProjectiles);
	}
	
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);

	mMoveSpeed = 300.0f;

	Position(mSpawn);

	// calculate velocity of missile based on startpoint, endpoint, and movespeed (*round)
	mVelocity = mTarget - mSpawn;

	Rotate(mVelocity.ToAngle());

	mSize = 1.0;
	mMaxSize = 5.0;
	mReachedTarget = false;

	//AddCollider(new BoxCollider(Vector2(mTexture->ScaledDimensions().x, mTexture->ScaledDimensions().y)));

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
	if (mFriendly) {
		return !mReachedTarget;
	}
	else {
		return false;
	}
}

void Missile::Hit(PhysEntity* other) {
	mWasHit = true;
	// check for collision here

	if (other->GetTag() == "Missile") {
		std::cout << "HIT!!!" << std::endl;
	}
}

bool Missile::WasHit() {
	return mWasHit;
}

void Missile::Update() {

	// Player missiles
	if (mFriendly) {
		if (!mReachedTarget) {
			if (Position().y > mTarget.y) {
				Translate(mVelocity.Normalized() * mMoveSpeed * mTimer->DeltaTime(), World);
			}
			else {
				Visible(false);			// switch texture to explosion
				mReachedTarget = true;
			}
		}
		else {	// ASPLODE TIME
			if (mSize < mMaxSize) {
				mSize = mSize * (1 + (1.5 * mTimer->DeltaTime()));
				//std::cout << "Size: " << mSize << std::endl;
				Scale(Vector2(mSize, mSize));
				//std::cout << "Collider size: " << mColliders[0]->Scale().x << std::endl;
				ChangeCollider(new CircleCollider(mTexture->ScaledDimensions().x * 0.5));
			}
			else if (!mExplodeFinished) {
				mExplodeFinished = true;
			}
		}
	}

	else  // Enemy Missiles
	{
		if (!mWasHit) {
			// figure out what targetVector is based on start and end point
	
			if (Position().x != mTarget.x && Position().y != mTarget.y) {
				Translate(mVelocity.Normalized() * mMoveSpeed * mTimer->DeltaTime(), World);
			}

			

			//this->Scale(Vector2(Scale().x * 1.05, Scale().y * 1.05));

			Vector2 pos = Position(Local);

			Position(pos);

			// Check collision
			/*if (Position() == mTarget) {

			}*/

			// Remove from list

		}
		else {
			Visible(false);
		}
	}
}

void Missile::Render() {

	if (mVisible) {
		mTexture->Render();
	}

	PhysEntity::Render();
}

bool Missile::GetExplodeFinished() {
	return mExplodeFinished;
}