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

		Vector2 vectorToTurret1;
		Vector2 vectorToTurret2;
		Vector2 vectorToTurret3;

		vectorToTurret1 = Position() - mTurret1->Position();
		vectorToTurret2 = Position() - mTurret2->Position();
		vectorToTurret3 = Position() - mTurret3->Position();

		float distanceToTurret1 = vectorToTurret1.Magnitude();
		float distanceToTurret2 = vectorToTurret2.Magnitude();
		float distanceToTurret3 = vectorToTurret3.Magnitude();

		//TURRET 1 IS MID TURRET
		//TURRET 2 IS LEFT TURRET
		//TURRET 3 IS RIGHT TURREt

		if (distanceToTurret1 < distanceToTurret2 && distanceToTurret1 < distanceToTurret3) {
			if (mTurret1->getAmmo()->HasAmmo()) {
				mTurret1->Fire(Position());
			} 
			else if (mTurret2->getAmmo()->HasAmmo()){
				mTurret2->Fire(Position());
			}
			else if (mTurret3->getAmmo()->HasAmmo()) {
				mTurret3->Fire(Position());
			}
		}
		else if (distanceToTurret2 < distanceToTurret1 && distanceToTurret2 < distanceToTurret3) {
			if (mTurret2->getAmmo()->HasAmmo()) {
				mTurret2->Fire(Position());
			}
			else if (mTurret1->getAmmo()->HasAmmo()) {
				mTurret1->Fire(Position());
			}
			else if (mTurret3->getAmmo()->HasAmmo()) {
				mTurret3->Fire(Position());
			}
		}
		else if (distanceToTurret3 < distanceToTurret1 && distanceToTurret3 < distanceToTurret2) {
			if (mTurret3->getAmmo()->HasAmmo()) {
				mTurret3->Fire(Position());
			}
			else if (mTurret1->getAmmo()->HasAmmo()) {
				mTurret1->Fire(Position());
			}
			else if (mTurret2->getAmmo()->HasAmmo()) {
				mTurret2->Fire(Position());
			}
		}
		else {
			if (mTurret1->getAmmo()->HasAmmo()) {
				mTurret1->Fire(Position());
			}
		}
	}
}

Player::Player(PlayScreen* playscreen) {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();
	mPlayScreen = playscreen;

	mVisible = false;

	mLives = 6;
	
	mTarget = new GLTexture("Target.png", 0, 0, 130, 130);
	mTarget->Scale(Vector2(0.3f, 0.3f));
	mTarget->Parent(this);
	mTarget->Position(Vec2_Zero);

	mMoveBounds = Vector2(0.0f, 900.0f);

	mTurret1 = new Turret(mPlayScreen, "AnitAir1.png");
	mTurret1->Parent(this->Parent());
	mTurret1->Position(972, 980);
	mTurret2 = new Turret(mPlayScreen, "SideAntiAir.png");
	mTurret2->Parent(this->Parent());
	mTurret2->Position(100, 980);
	mTurret3 = new Turret(mPlayScreen, "SideAntiAir2.png");
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