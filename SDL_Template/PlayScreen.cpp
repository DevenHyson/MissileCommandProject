#include "PlayScreen.h"



PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	SDL_ShowCursor(SDL_DISABLE);
	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	mPlayer->Active(true);

	mMissile = new Missile();

	mBuildings = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	mBuildings->Parent(this);

	//Floor, long green surface

	mGround = new GLTexture("Ground.png", 0, 0, 1920, 1080);
	mGround->Parent(mBuildings);
	mGround->Position(0, -135);

	//Cities

	mBuilding1 = new GLTexture("Building1.png", 0, 150, 1920, 1080);
	mBuilding1->Parent(mBuildings);
	mBuilding1->Position(-300, 220);
	mBuilding1->Scale(Vector2(0.6f, 0.2f));

	mBuilding2 = new GLTexture("Building1.png", 0, 150, 1920, 1080);
	mBuilding2->Parent(mBuildings);
	mBuilding2->Position(-50, 220);
	mBuilding2->Scale(Vector2(0.6f, 0.2f));

	mBuilding3 = new GLTexture("Building1.png", 0, 150, 1920, 1080);
	mBuilding3->Parent(mBuildings);
	mBuilding3->Position(200, 220);
	mBuilding3->Scale(Vector2(0.6f, 0.2f));

	mBuilding4 = new GLTexture("Building1.png", 0, 150, 1920, 1080);
	mBuilding4->Parent(mBuildings);
	mBuilding4->Position(625, 220);
	mBuilding4->Scale(Vector2(0.6f, 0.2f));

	mBuilding5 = new GLTexture("Building1.png", 0, 150, 1920, 1080);
	mBuilding5->Parent(mBuildings);
	mBuilding5->Position(875, 220);
	mBuilding5->Scale(Vector2(0.6f, 0.2f));

	mBuilding6 = new GLTexture("Building1.png", 0, 150, 1920, 1080);
	mBuilding6->Parent(mBuildings);
	mBuilding6->Position(1125, 220);
	mBuilding6->Scale(Vector2(0.6f, 0.2f));





	//Josh Square



	/*mJoshSquare = new GLTexture("Hill.png", 0, 150, 100, 100);
	mJoshSquare->Parent(this);
	mJoshSquare->Position(400, 400);
	mJoshSquare->Scale(Vector2(1.0f, 1.0f));*/











	//Hill Sprites, for some reason they won't work named what they actually are. These are the green plates under the batteries

	mAntiAir1 = new GLTexture("Hill.png", 0, 0, 126, 215);
	mAntiAir1->Parent(mBuildings);
	mAntiAir1->Position(-860, 280);
	mAntiAir1->Scale(Vector2(0.6f, 0.2f));

	mAntiAir2 = new GLTexture("Hill.png", 0, 0, 126, 215);
	mAntiAir2->Parent(mBuildings);
	mAntiAir2->Position(13, 280);
	mAntiAir2->Scale(Vector2(0.6f, 0.2f));

	mAntiAir3 = new GLTexture("Hill.png", 0, 0, 126, 215);
	mAntiAir3->Parent(mBuildings);
	mAntiAir3->Position(880, 280);
	mAntiAir3->Scale(Vector2(0.6f, 0.2f));

	//Anti Air Sprites, for some reason they won't work named what they actually are.

	mHill1 = new GLTexture("AnitAir1.png", 0, 100, 1920, 1080);
	mHill1->Parent(mBuildings);
	mHill1->Position(90, 360);
	mHill1->Scale(Vector2(1.0f, 1.0f));

	mHill2 = new GLTexture("SideAntiAir.png", 0, 100, 1920, 1080);
	mHill2->Parent(mBuildings);
	mHill2->Position(-782, 360);
	mHill2->Scale(Vector2(1.0f, 1.0f));

	mHill3 = new GLTexture("SideAntiAir2.png", 0, 100, 1920, 1080);
	mHill3->Parent(mBuildings);
	mHill3->Position(957, 360);
	mHill3->Scale(Vector2(1.0f, 1.0f));

	//Battery Ammo
	//
	//Left Battery

	mLMissileAmmo1 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo1->Parent(this);
	mLMissileAmmo1->Position(100, 1035);
	mLMissileAmmo1->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo2 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo2->Parent(this);
	mLMissileAmmo2->Position(88, 1045);
	mLMissileAmmo2->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo3 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo3->Parent(this);
	mLMissileAmmo3->Position(113, 1045);
	mLMissileAmmo3->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo4 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo4->Parent(this);
	mLMissileAmmo4->Position(76, 1055);
	mLMissileAmmo4->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo5 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo5->Parent(this);
	mLMissileAmmo5->Position(101, 1055);
	mLMissileAmmo5->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo6 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo6->Parent(this);
	mLMissileAmmo6->Position(126, 1055);
	mLMissileAmmo6->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo7 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo7->Parent(this);
	mLMissileAmmo7->Position(64, 1065);
	mLMissileAmmo7->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo8 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo8->Parent(this);
	mLMissileAmmo8->Position(89, 1065);
	mLMissileAmmo8->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo9 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo9->Parent(this);
	mLMissileAmmo9->Position(113, 1065);
	mLMissileAmmo9->Scale(Vector2(1.0f, 1.0f));
	mLMissileAmmo10 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mLMissileAmmo10->Parent(this);
	mLMissileAmmo10->Position(139, 1065);
	mLMissileAmmo10->Scale(Vector2(1.0f, 1.0f));

	//Right Battery

	mRMissileAmmo1 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo1->Parent(this);
	mRMissileAmmo1->Position(1845, 1035);
	mRMissileAmmo1->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo2 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo2->Parent(this);
	mRMissileAmmo2->Position(1833, 1045);
	mRMissileAmmo2->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo3 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo3->Parent(this);
	mRMissileAmmo3->Position(1858, 1045);
	mRMissileAmmo3->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo4 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo4->Parent(this);
	mRMissileAmmo4->Position(1821, 1055);
	mRMissileAmmo4->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo5 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo5->Parent(this);
	mRMissileAmmo5->Position(1846, 1055);
	mRMissileAmmo5->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo6 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo6->Parent(this);
	mRMissileAmmo6->Position(1871, 1055);
	mRMissileAmmo6->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo7 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo7->Parent(this);
	mRMissileAmmo7->Position(1809, 1065);
	mRMissileAmmo7->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo8 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo8->Parent(this);
	mRMissileAmmo8->Position(1834, 1065);
	mRMissileAmmo8->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo9 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo9->Parent(this);
	mRMissileAmmo9->Position(1859, 1065);
	mRMissileAmmo9->Scale(Vector2(1.0f, 1.0f));
	mRMissileAmmo10 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mRMissileAmmo10->Parent(this);
	mRMissileAmmo10->Position(1884, 1065);
	mRMissileAmmo10->Scale(Vector2(1.0f, 1.0f));

	//Middle Battery

	mMidMissileAmmo1 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo1->Parent(this);
	mMidMissileAmmo1->Position(975, 1035);
	mMidMissileAmmo1->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo2 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo2->Parent(this);
	mMidMissileAmmo2->Position(963, 1045);
	mMidMissileAmmo2->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo3 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo3->Parent(this);
	mMidMissileAmmo3->Position(988, 1045);
	mMidMissileAmmo3->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo4 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo4->Parent(this);
	mMidMissileAmmo4->Position(951, 1055);
	mMidMissileAmmo4->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo5 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo5->Parent(this);
	mMidMissileAmmo5->Position(976, 1055);
	mMidMissileAmmo5->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo6 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo6->Parent(this);
	mMidMissileAmmo6->Position(1001, 1055);
	mMidMissileAmmo6->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo7 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo7->Parent(this);
	mMidMissileAmmo7->Position(939, 1065);
	mMidMissileAmmo7->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo8 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo8->Parent(this);
	mMidMissileAmmo8->Position(964, 1065);
	mMidMissileAmmo8->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo9 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo9->Parent(this);
	mMidMissileAmmo9->Position(989, 1065);
	mMidMissileAmmo9->Scale(Vector2(1.0f, 1.0f));
	mMidMissileAmmo10 = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
	mMidMissileAmmo10->Parent(this);
	mMidMissileAmmo10->Position(1014, 1065);
	mMidMissileAmmo10->Scale(Vector2(1.0f, 1.0f));





	//Game Scores
	mRoundScore = new GLTexture("0", "emulogic.ttf", 36, { 200, 0, 0 });
	mRoundScore->Parent(this);
	mRoundScore->Position(975, 100);
	mRoundScore->Scale(Vector2(1.0f, 1.0f));

	mGameScore = new GLTexture("0", "emulogic.ttf", 36, { 200, 0, 0 });
	mGameScore->Parent(this);
	mGameScore->Position(575, 100);
	mGameScore->Scale(Vector2(1.0f, 1.0f));



}

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mPlayer;
	mPlayer = nullptr;
	delete mBuilding1;
	mBuilding1 = nullptr;
	delete mBuilding2;
	mBuilding2 = nullptr;
	delete mBuilding3;
	mBuilding3 = nullptr;
	delete mBuilding4;
	mBuilding4 = nullptr;
	delete mBuilding5;
	mBuilding5 = nullptr;
	delete mBuilding6;
	mBuilding6 = nullptr;


	delete mAntiAir1;
	mAntiAir1 = nullptr;
	delete mAntiAir2;
	mAntiAir2 = nullptr;
	delete mAntiAir3;
	mAntiAir3 = nullptr;

	delete mGround;
	mGround = nullptr;

	delete mHill1;
	mHill1 = nullptr;
	delete mHill2;
	mHill2 = nullptr;
	delete mHill3;
	mHill3 = nullptr;


	//JoshSquare

	delete mJoshSquare;
	mJoshSquare = nullptr;


	delete mLMissileAmmo1;
	mLMissileAmmo1 = nullptr;
	delete mLMissileAmmo2;
	mLMissileAmmo2 = nullptr;
	delete mLMissileAmmo3;
	mLMissileAmmo3 = nullptr;
	delete mLMissileAmmo4;
	mLMissileAmmo4 = nullptr;
	delete mLMissileAmmo5;
	mLMissileAmmo5 = nullptr;
	delete mLMissileAmmo6;
	mLMissileAmmo6 = nullptr;
	delete mLMissileAmmo7;
	mLMissileAmmo7 = nullptr;
	delete mLMissileAmmo8;
	mLMissileAmmo8 = nullptr;
	delete mLMissileAmmo9;
	mLMissileAmmo9 = nullptr;
	delete mLMissileAmmo10;
	mLMissileAmmo10 = nullptr;

	delete mRMissileAmmo1;
	mRMissileAmmo1 = nullptr;
	delete mRMissileAmmo2;
	mRMissileAmmo2 = nullptr;
	delete mRMissileAmmo3;
	mRMissileAmmo3 = nullptr;
	delete mRMissileAmmo4;
	mRMissileAmmo4 = nullptr;
	delete mRMissileAmmo5;
	mRMissileAmmo5 = nullptr;
	delete mRMissileAmmo6;
	mRMissileAmmo6 = nullptr;
	delete mRMissileAmmo7;
	mRMissileAmmo7 = nullptr;
	delete mRMissileAmmo8;
	mRMissileAmmo8 = nullptr;
	delete mRMissileAmmo9;
	mRMissileAmmo9 = nullptr;
	delete mRMissileAmmo10;
	mRMissileAmmo10 = nullptr;

	delete mMidMissileAmmo1;
	mMidMissileAmmo1 = nullptr;
	delete mMidMissileAmmo2;
	mMidMissileAmmo2 = nullptr;
	delete mMidMissileAmmo3;
	mMidMissileAmmo3 = nullptr;
	delete mMidMissileAmmo4;
	mMidMissileAmmo4 = nullptr;
	delete mMidMissileAmmo5;
	mMidMissileAmmo5 = nullptr;
	delete mMidMissileAmmo6;
	mMidMissileAmmo6 = nullptr;
	delete mMidMissileAmmo7;
	mMidMissileAmmo7 = nullptr;
	delete mMidMissileAmmo8;
	mMidMissileAmmo8 = nullptr;
	delete mMidMissileAmmo9;
	mMidMissileAmmo9 = nullptr;
	delete mMidMissileAmmo10;
	mMidMissileAmmo10 = nullptr;


	delete mRoundScore;
	mRoundScore = nullptr;
	delete mGameScore;
	mGameScore = nullptr;

}

void PlayScreen::Update() {
	mPlayer->Update();
	mMissile->Update();
}

void PlayScreen::Render() {
	mPlayer->Render();
	mBuilding1->Render();
	mBuilding2->Render();
	mBuilding3->Render();
	mBuilding4->Render();
	mBuilding5->Render();
	mBuilding6->Render();

	mAntiAir1->Render();
	mAntiAir2->Render();
	mAntiAir3->Render();


	mGround->Render();

	mHill1->Render();
	mHill2->Render();
	mHill3->Render();

	mLMissileAmmo1->Render();
	mLMissileAmmo2->Render();
	mLMissileAmmo3->Render();
	mLMissileAmmo4->Render();
	mLMissileAmmo5->Render();
	mLMissileAmmo6->Render();
	mLMissileAmmo7->Render();
	mLMissileAmmo8->Render();
	mLMissileAmmo9->Render();
	mLMissileAmmo10->Render();

	mRMissileAmmo1->Render();
	mRMissileAmmo2->Render();
	mRMissileAmmo3->Render();
	mRMissileAmmo4->Render();
	mRMissileAmmo5->Render();
	mRMissileAmmo6->Render();
	mRMissileAmmo7->Render();
	mRMissileAmmo8->Render();
	mRMissileAmmo9->Render();
	mRMissileAmmo10->Render();

	mMidMissileAmmo1->Render();
	mMidMissileAmmo2->Render();
	mMidMissileAmmo3->Render();
	mMidMissileAmmo4->Render();
	mMidMissileAmmo5->Render();
	mMidMissileAmmo6->Render();
	mMidMissileAmmo7->Render();
	mMidMissileAmmo8->Render();
	mMidMissileAmmo9->Render();
	mMidMissileAmmo10->Render();

	mRoundScore->Render();
	mGameScore->Render();


	//Josh Square

	//mJoshSquare->Render();
	mMissile->Render();
}
