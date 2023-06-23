#include "Turret.h"

Turret::Turret(PlayScreen* playscreen, std::string textureFilename) {
	mPlayScreen = playscreen;
	mTexture = new GLTexture(textureFilename);
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);

	mAmmo = new Ammo();
	mAmmo->Parent(this);
	mAmmo->Position(Vec2_Zero);
}

Turret::~Turret() {

}

void Turret::Update() {
	for (auto it = mMissiles.begin(); it != mMissiles.end();) {

		(*it)->Update();

		if ((*it)->GetExplodeFinished()) {
			mMissilesToBeDeleted.push_back(*it);
			it = mMissiles.erase(it);
		}
		else {
			++it;
		}
	}

	for (auto m : mMissilesToBeDeleted) {
		delete m;
	}

	mMissilesToBeDeleted.clear();

	mAmmo->Update();
}

void Turret::Render() {
	mTexture->Render();

	for (auto m : mMissiles) {
		m->Render();
	}

	mAmmo->Render();
}

void Turret::Fire(Vector2 target) {
	mAmmo->UseAmmo();
	mMissiles.push_back(new Missile(mPlayScreen, Position(), target, true));
}

void Turret::ReloadAmmo() {
	mAmmo->ReloadAmmo();
}