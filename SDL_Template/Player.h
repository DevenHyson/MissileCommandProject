#ifndef __PLAYER_H
#define __PLAYER_H
#include "AnimatedGLTexture.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Scoreboard.h"
#include "Turret.h"
class PlayScreen;

using namespace SDLFramework;

class Player : public GameEntity {
private:
	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;
	PlayScreen* mPlayScreen;

	bool mVisible;

	int mLives;

	Texture* mTarget;

	Vector2 mHitPoint;

	float mMoveSpeed;
	Vector2 mMoveBounds;

	Turret* mTurret1;
	Turret* mTurret2;
	Turret* mTurret3;

private:
	void HandleMovement();
	void HandleFiring();

public:
	Player(PlayScreen* playscreen);
	~Player();

	void Visible(bool visible);

	int Lives();

	void AddScore(int change);

	void Update() override;
	void Render() override;
};
#endif