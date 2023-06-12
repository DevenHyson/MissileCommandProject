#include "Turret.h"

Turret::Turret(std::string textureFilename) {
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
	for (auto m : mMissiles) {
		m->Update();
	}

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
	mMissiles.push_back(new Missile(Position(), target, true));
}