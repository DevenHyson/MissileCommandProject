#ifndef __MISSILE_H
#define __MISSILE_H
#include "Texture.h"
#include "AudioManager.h"
#include "Timer.h"
#include "PhysEntity.h"
#include "Random.h"

using namespace SDLFramework;

class Missile : public PhysEntity {
private:
	Timer* mTimer;
	AudioManager* mAudio;
	Random* mRandom;

	bool mVisible;
	bool mWasHit;

	Texture* mTexture;

	Vector2 mSpawn;			// start point
	Vector2 mVelocity;
	Vector2 mTarget;		// end point

	float mMoveSpeed;
	Vector2 mMoveBounds;
	int mTargetCity;
	


public:
	Missile();
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

};
#endif
