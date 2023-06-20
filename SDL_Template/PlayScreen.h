#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Player.h"
#include "Missile.h"
#include "Random.h"
#include "Scoreboard.h"
#include "City.h"
#include <vector>

class PlayScreen : public GameEntity {
private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInput;
	Random* mRandom;

	Player* mPlayer;

	std::vector<Missile*> mMissiles;
	std::vector<Missile*> mMissilesToBeDeleted;

	Texture* mGround;

	std::vector<City*> mCities;

	Texture* mHill1;
	Texture* mHill2;
	Texture* mHill3;

	// Game Scores
	
	GameEntity* mBuildings;

	// Missile Timer

	float mMissileTimer;
	float mMissileTimeDelay;

	bool CheckCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

	int mROUNDSCORE = 0;
	int mGAMESCORE = 0;

	Scoreboard* mScoreBoard1;
	Scoreboard* mScoreBoard2;

	int CityCheck = 0;

public:

	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;


	void spawnMissile();

};
#endif