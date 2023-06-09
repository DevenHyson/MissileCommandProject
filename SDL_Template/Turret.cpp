#include "Turret.h"

Turret::Turret(std::string textureFilename) {
	mTexture = new GLTexture(textureFilename);
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);
}

Turret::~Turret() {

}

void Turret::Update() {
	for (auto m : mMissiles) {
		m->Update();
	}
}

void Turret::Render() {
	mTexture->Render();

	for (auto m : mMissiles) {
		m->Render();
	}
}

void Turret::Fire(Vector2 target) {
	mMissiles.push_back(new Missile(Position(), target, true));
}