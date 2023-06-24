#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	if (mGameOver == false) {
		
		mTimer = Timer::Instance();
		mAudio = AudioManager::Instance();
		mRandom = Random::Instance();
		mInput = InputManager::Instance();

		SDL_ShowCursor(SDL_DISABLE);

		mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);


		delete mPlayer;
		mPlayer = new Player(this);
		mPlayer->Parent(this);
		mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
		mPlayer->Active(true);

		mScoreBoard = new Scoreboard();
		mScoreBoard->Parent(this);
		mScoreBoard->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.02f);
		mScoreBoard->Score(mGAMESCORE);

		//Floor, long green surface
		mBuildings = new GameEntity();
		mBuildings->Parent(this);
		mBuildings->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);

		mGround = new GLTexture("Ground.png", 0, 0, 1920, 1080);
		mGround->Parent(mBuildings);
		mGround->Position(0, -135);

		//Cities

		mCities.push_back(new City(Vector2(262, 1020)));
		mCities.push_back(new City(Vector2(517, 1020)));
		mCities.push_back(new City(Vector2(765, 1020)));
		mCities.push_back(new City(Vector2(1191, 1020)));
		mCities.push_back(new City(Vector2(1441, 1020)));
		mCities.push_back(new City(Vector2(1692, 1020)));

		//Hill Sprites, for some reason they won't work named what they actually are. These are the green plates under the batteries

		mHill1 = new GLTexture("Hill.png", 0, 0, 126, 215);
		mHill1->Parent(mBuildings);
		mHill1->Position(-860, 280);
		mHill1->Scale(Vector2(0.6f, 0.2f));

		mHill2 = new GLTexture("Hill.png", 0, 0, 126, 215);
		mHill2->Parent(mBuildings);
		mHill2->Position(13, 280);
		mHill2->Scale(Vector2(0.6f, 0.2f));

		mHill3 = new GLTexture("Hill.png", 0, 0, 126, 215);
		mHill3->Parent(mBuildings);
		mHill3->Position(880, 280);
		mHill3->Scale(Vector2(0.6f, 0.2f));
		
		mGameOverText = new GLTexture("GAME OVER", "emulogic.TTF", 80, { 0, 255, 0 });
		mGameOverText->Position(Graphics::SCREEN_WIDTH * 0.490f, Graphics::SCREEN_HEIGHT * 0.3f);
		mGameOverText->Parent(this);

		mInformationText1 = new GLTexture("*Careful it's loud*", "emulogic.TTF", 10, { 0, 255, 0 });
		mInformationText1->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.1f);
		mInformationText1->Parent(this);

		mInformationText2 = new GLTexture("City Rebuild every 1,000 points (points stack)", "emulogic.TTF", 10, { 0, 255, 0 });
		mInformationText2->Position(Graphics::SCREEN_WIDTH * 0.125f, Graphics::SCREEN_HEIGHT * 0.15f);
		mInformationText2->Parent(this);

		mInformationText3 = new GLTexture("Ammo Refill every 2,000 points", "emulogic.TTF", 10, { 0, 255, 0 });
		mInformationText3->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.2f);
		mInformationText3->Parent(this);


		//Game Scores

		mMissileTimer = 0;
		mMissileTimeDelay = 2;

		mGameOver = false;
	}
	
	
}
	

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mPlayer;
	mPlayer = nullptr;
	
	// delete cities

	delete mGround;
	mGround = nullptr;

	delete mHill1;
	mHill1 = nullptr;
	delete mHill2;
	mHill2 = nullptr;
	delete mHill3;
	mHill3 = nullptr;

	delete mGameOverText;
	mGameOverText = nullptr;
	delete mInformationText1;
	mInformationText1 = nullptr;
	delete mInformationText2;
	mInformationText2 = nullptr;
	delete mInformationText3;
	mInformationText3 = nullptr;

	delete mScoreBoard;
	mScoreBoard = nullptr;

}

void PlayScreen::Update() {
	if (mGameOver == false) {
		mPlayer->Update();
		mScoreBoard->Update();
		if (mGameStart) {
			mAudio->PlaySFX("SFX/GameStart.mp3");
			mAudio->PlaySFX("SFX/GameStart.mp3");
			mAudio->PlaySFX("SFX/GameStart.mp3");
			mGameStart = false;
		}
		

		if (mGAMESCORE % 2000 == 0 && mGAMESCORE != mCheckingScore) {
			mCheckingScore = mGAMESCORE;
			std::cout << "Detected Multiple" << std::endl;
			mPlayer->ReloadAmmo();
			mAudio->PlaySFX("SFX/Reload.wav");
			mAudio->PlaySFX("SFX/Reload.wav");
			mAudio->PlaySFX("SFX/Reload.wav");
			mAudio->PlaySFX("SFX/Reload.wav");
			mAudio->PlaySFX("SFX/Reload.wav");
			mAudio->PlaySFX("SFX/Reload.wav");
			mAudio->PlaySFX("SFX/Reload.wav");
			mAudio->PlaySFX("SFX/Reload.wav");
		}

		if (mGAMESCORE % 1000 == 0 && mGAMESCORE != mCheckingScore) {
			mCheckingScore = mGAMESCORE;
			mReviveToken += 1;

			if (mCities[0]->Destroyed() && mReviveToken >= 1) {
				mReviveToken -= 1;
				mCities[0]->Destroyed(false);
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
			}
			if (mCities[1]->Destroyed() && mReviveToken >= 1) {
				mReviveToken -= 1;
				mCities[1]->Destroyed(false);
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
			}
			if (mCities[2]->Destroyed() && mReviveToken >= 1) {
				mReviveToken -= 1;
				mCities[2]->Destroyed(false);
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
			}
			if (mCities[3]->Destroyed() && mReviveToken >= 1) {
				mReviveToken -= 1;
				mCities[3]->Destroyed(false);
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
			}
			if (mCities[4]->Destroyed() && mReviveToken >= 1) {
				mReviveToken -= 1;
				mCities[4]->Destroyed(false);
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
			}
			if (mCities[5]->Destroyed() && mReviveToken >= 1) {
				mReviveToken -= 1;
				mCities[5]->Destroyed(false);
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
				mAudio->PlaySFX("SFX/CityRebuild.mp3");
			}
		}

		mMissileTimer += mTimer->DeltaTime();

		if (mMissileTimer >= mMissileTimeDelay) {
			spawnMissile();
			mMissileTimer = 0;
		}
		for (auto m : mMissilesToBeDeleted) {
			delete m;
		}
		mMissilesToBeDeleted.clear();
	}
	for (auto it = mMissiles.begin(); it != mMissiles.end();) {

		(*it)->Update();

		if (CheckCollision((*it)->Position().x, (*it)->Position().y, 38, 15, (*it)->Target().x, (*it)->Target().y, 204, 225)) {
			mMissilesToBeDeleted.push_back(*it);
			it = mMissiles.erase(it);
			std::cout << "missile deleted" << std::endl;
		}
		else if ((*it)->WasHit()) {
			mMissilesToBeDeleted.push_back(*it);
			it = mMissiles.erase(it);
			std::cout << "missile deleted" << std::endl;
		}
		else {
			++it;
		}
	}
	
}

void PlayScreen::Render() {
	
	
	
	for (auto m : mMissiles) {
		m->Render();
	}

	for (auto c : mCities) {
		c->Render();
	}

	mGround->Render();

	mHill1->Render();
	mHill2->Render();
	mHill3->Render();

	if (mCities[0]->Destroyed() &&
		mCities[1]->Destroyed() &&
		mCities[2]->Destroyed() &&
		mCities[3]->Destroyed() &&
		mCities[4]->Destroyed() &&
		mCities[5]->Destroyed()) {
		mGameOverText->Render();
		mGameOver = true;
		std::cout << "GAME OVER DUDE!" << std::endl;
		if (mEnd == false) {
			mAudio->PlaySFX("SFX/GameOver.wav");
			mEnd = true;
		}
	}


	mPlayer->Render();
	
	mScoreBoard->Render();
	
	mInformationText1->Render();
	mInformationText2->Render();
	mInformationText3->Render();
}

void PlayScreen::spawnMissile() {
	if (mGameOver == false) {
		mMissiles.push_back(new Missile(this));
	}
}

bool PlayScreen::CheckCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
	float obj1_left = x1;
	float obj1_right = x1 + w1;
	float obj1_top = y1;
	float obj1_bottom = y1 + h1;

	float obj2_left = x2;
	float obj2_right = x2 + w2;
	float obj2_top = y2;
	float obj2_bottom = y2 + h2;
	return obj1_right > obj2_left && obj1_left < obj2_right&& obj1_bottom > obj2_top && obj1_top < obj2_bottom;
}

void PlayScreen::addScore(int value) {
	mGAMESCORE += value;
	mScoreBoard->Score(mGAMESCORE);
}