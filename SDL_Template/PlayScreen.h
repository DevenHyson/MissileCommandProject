#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Player.h"
#include "Missile.h"
#include "Random.h"
#include "City.h"
#include <vector>
#include "Texture.h"

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

	GLTexture* mGameOverText;
	GLTexture* mInformationText1;
	GLTexture* mInformationText2;
	GLTexture* mInformationText3;

	// Game Scores
	
	GameEntity* mBuildings;
	GameEntity* mBottomBar;

	// Missile Timer

	float mMissileTimer;
	float mMissileTimeDelay;

	bool CheckCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

	int mGAMESCORE = 0;
	int mReviveToken;
	bool mEnd = false;
	bool mGameStart = true;



	Scoreboard* mScoreBoard;
	int mCheckingScore;

	int CityCheck = 0;
	bool mGameOver = false;

public:

	void addScore(int value);
	bool getScore() { return mGAMESCORE; }
	

	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;


	void spawnMissile();

};
#endif