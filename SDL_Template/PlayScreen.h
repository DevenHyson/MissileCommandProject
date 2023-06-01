#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Player.h"

class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	Player * mPlayer;

	Texture* mGround;

	Texture* mBuilding1;
	Texture* mBuilding2;
	Texture* mBuilding3;
	Texture* mBuilding4;
	Texture* mBuilding5;
	Texture* mBuilding6;




	Texture* mJoshSquare;




	Texture* mHill1;
	Texture* mHill2;
	Texture* mHill3;

	Texture* mAntiAir1;
	Texture* mAntiAir2;
	Texture* mAntiAir3;

	//Anti Air Ammo

	//Left Battery
	Texture* mLMissileAmmo1;
	Texture* mLMissileAmmo2;
	Texture* mLMissileAmmo3;
	Texture* mLMissileAmmo4;
	Texture* mLMissileAmmo5;
	Texture* mLMissileAmmo6;
	Texture* mLMissileAmmo7;
	Texture* mLMissileAmmo8;
	Texture* mLMissileAmmo9;
	Texture* mLMissileAmmo10;

	//Right Battery
	Texture* mRMissileAmmo1;
	Texture* mRMissileAmmo2;
	Texture* mRMissileAmmo3;
	Texture* mRMissileAmmo4;
	Texture* mRMissileAmmo5;
	Texture* mRMissileAmmo6;
	Texture* mRMissileAmmo7;
	Texture* mRMissileAmmo8;
	Texture* mRMissileAmmo9;
	Texture* mRMissileAmmo10;

	//Middle Battery
	Texture* mMidMissileAmmo1;
	Texture* mMidMissileAmmo2;
	Texture* mMidMissileAmmo3;
	Texture* mMidMissileAmmo4;
	Texture* mMidMissileAmmo5;
	Texture* mMidMissileAmmo6;
	Texture* mMidMissileAmmo7;
	Texture* mMidMissileAmmo8;
	Texture* mMidMissileAmmo9;
	Texture* mMidMissileAmmo10;

	// Game Scores
	Texture* mRoundScore;
	Texture* mGameScore;
	int mROUNDSCORE;
	int mGAMESCORE;


	GameEntity* mBuildings;

	Texture* mMissile;


public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};
#endif