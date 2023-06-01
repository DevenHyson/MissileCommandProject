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
	bool CheckCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

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
};
#endif
