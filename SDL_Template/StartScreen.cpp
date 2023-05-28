#include "StartScreen.h"
#include "Player.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	// top bar entities
	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	mPlayerOne = new GLTexture("1UP", "emulogic.ttf", 32, { 200, 0, 0 });
	mHiScore = new GLTexture("HI SCORE", "emulogic.ttf", 32, { 200, 0, 0 });
	mTopScore = new Scoreboard();

	mTopBar->Parent(this);
	mPlayerOne->Parent(mTopBar);
	mHiScore->Parent(mTopBar);
	mTopScore->Parent(mTopBar);

	mPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);
	mHiScore->Position(-30.0f, 0.0f);


	mTopScore->Position(Graphics::SCREEN_WIDTH * 0.05f, 40.0f);

	mTopScore->Score(645987);


	// bottom bar entities
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	mNamco = new GLTexture("namcot", "namco__.ttf", 36, { 200, 0, 0 });
	mBackground = new GLTexture("title.png", 0, 0, 1920, 1080);


	mBottomBar->Parent(this);
	mNamco->Parent(mBottomBar);
	mBackground->Parent(mBottomBar);


	mNamco->Position(0.0f, 90.0f);
	mBackground->Position(0.0f, -210.0f);

}


StartScreen::~StartScreen() {
	// top bar entities
	delete mTopBar;
	mTopBar = nullptr;
	delete mPlayerOne;
	mPlayerOne = nullptr;

	delete mHiScore;
	mHiScore = nullptr;

	delete mTopScore;
	mTopScore = nullptr;



	// bottom bar entities
	delete mBottomBar;
	mBottomBar = nullptr;
	delete mNamco;
	mNamco = nullptr;
	delete mBackground;
	mBackground = nullptr;

	mTimer = nullptr;
	mInput = nullptr;
}



void StartScreen::Update() {



}

void StartScreen::Render() {
	mHiScore->Render();
	mTopScore->Render();
	mNamco->Render();
	mBackground->Render();


}