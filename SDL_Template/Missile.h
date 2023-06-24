#ifndef __MISSILE_H
#define __MISSILE_H
#include "Texture.h"
#include "AudioManager.h"
#include "Timer.h"
#include "PhysEntity.h"
#include "Random.h"
#include "Scoreboard.h"
class PlayScreen;

using namespace SDLFramework;

class Missile : public PhysEntity {
private:
	Timer* mTimer;
	AudioManager* mAudio;
	Random* mRandom;
	PlayScreen* mPlayScreen;

	bool mFriendly;
	bool mVisible;
	bool mWasHit;
	bool mExplodeFinished;

	Texture* mTexture;
	Texture* mExplosionTexture;

	Vector2 mSpawn;			// start point
	Vector2 mVelocity;
	Vector2 mTarget;		// end point

	float mSize;
	float mMaxSize;

	bool mReachedTarget;
	int mDebounce = 0;

	float mMoveSpeed;
	int mTargetCity;
	
public:
	Missile(PlayScreen* playscreen, Vector2 spawnpoint=Vec2_Zero, Vector2 target=Vec2_Zero, bool friendly = false);
	~Missile();

	void Visible(bool visible);

	// Inherited from PhysEntity
	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

	bool WasHit();

	void Update() override;
	void Render() override;

	Vector2 Target() {
		return mTarget;
	}

	int TargetCity() {
		return mTargetCity;
	}

	bool GetExplodeFinished();

	void ExplosionComplete() {
		std::cout << "Explosion Complete!" << std::endl;
	}
};
#endif
