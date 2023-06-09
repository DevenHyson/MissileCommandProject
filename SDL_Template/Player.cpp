#include "Player.h"

void Player::HandleMovement() {
	Vector2 pos;

	pos = mInput->MousePosition();

	if (pos.y > mMoveBounds.y) {
		pos.y = mMoveBounds.y;
	}

	Position(pos);

	//Position with nothing in () returns the position
	//Position with something in () sets the position	
}

void Player::HandleFiring() {
	if (mInput->MouseButtonPressed(InputManager::MouseButton::Left)) {
		mTurret1->Fire(Position());
	}
}

Player::Player() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mVisible = false;

	mLives = 6;
	
	mTarget = new GLTexture("Target.png", 0, 0, 130, 130);
	mTarget->Scale(Vector2(0.3f, 0.3f));
	mTarget->Parent(this);
	mTarget->Position(Vec2_Zero);

	mMoveBounds = Vector2(0.0f, 900.0f);

	mTurret1 = new Turret("AnitAir1.png");
	mTurret1->Parent(this->Parent());
	mTurret1->Position(972, 980);
	mTurret2 = new Turret("SideAntiAir.png");
	mTurret2->Parent(this->Parent());
	mTurret2->Position(100, 980);
	mTurret3 = new Turret("SideAntiAir2.png");
	mTurret3->Parent(this->Parent());
	mTurret3->Position(1840, 980);

	Visible(true);
}

Player::~Player() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mTarget;
	mTarget = nullptr;
}

void Player::Visible(bool visible) {
	mVisible = visible;
}

int Player::Lives() {
	return mLives;
}

void Player::Update() {

	if (Active()) {
		HandleMovement();
		HandleFiring();
	}
	mTurret1->Update();
	mTurret2->Update();
	mTurret3->Update();

}

void Player::Render() {
	mTarget->Render();
	mTurret1->Render();
	mTurret2->Render();
	mTurret3->Render();
}