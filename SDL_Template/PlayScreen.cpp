#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mRandom = Random::Instance();
	mInput = InputManager::Instance();

	SDL_ShowCursor(SDL_DISABLE);

	delete mPlayer;
	mPlayer = new Player(this);
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	mPlayer->Active(true);

	mScoreBoard = new Scoreboard();
	mScoreBoard->Parent(this);
	mScoreBoard->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.02f);
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

	


	//Game Scores

	mMissileTimer = 0;
	mMissileTimeDelay = 2;
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

	delete mScoreBoard;
	mScoreBoard = nullptr;

}

void PlayScreen::Update() {
	mPlayer->Update();
	mScoreBoard->Update();

	if (mGAMESCORE % 500 == 0 && mGAMESCORE != mCheckingScore) {
		mCheckingScore = mGAMESCORE;
		std::cout << "Detected Multiple" << std::endl;
		
	}

	if (mInput->KeyDown(SDL_SCANCODE_U)) {
		mGAMESCORE += 1000;
		std::cout << "Clicked U" << std::endl;
		std::cout << mGAMESCORE << std::endl;
		mScoreBoard->Score(mGAMESCORE);

	}

	mMissileTimer += mTimer->DeltaTime();

	if (mMissileTimer >= mMissileTimeDelay) {
		spawnMissile();
		mMissileTimer = 0;
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

	for (auto m : mMissilesToBeDeleted) {
		delete m;
	}

	mMissilesToBeDeleted.clear();
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

	mPlayer->Render();

	mScoreBoard->Render();
}

void PlayScreen::spawnMissile() {
	mMissiles.push_back(new Missile(this));
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