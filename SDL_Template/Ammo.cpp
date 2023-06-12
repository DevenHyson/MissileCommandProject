#include "Ammo.h"

Ammo::Ammo() {
	mAmmo = 10;

	for (int i = 0; i < mAmmo; i++) {
		mTextures[i] = new GLTexture("MissileAmmo.png", 0, 0, 23, 9);
		mTextures[i]->Parent(this);
	}

	mTextures[0]->Position(0, 55);
	mTextures[1]->Position(-12, 65);
	mTextures[2]->Position(13, 65); 
	mTextures[3]->Position(-24, 75);
	mTextures[4]->Position(1, 75); 
	mTextures[5]->Position(26, 75); 
	mTextures[6]->Position(-36, 85);
	mTextures[7]->Position(-11, 85); 
	mTextures[8]->Position(13, 85); 
	mTextures[9]->Position(39, 85);
}

Ammo::~Ammo() {

}

void Ammo::UseAmmo() {
	mAmmo--;
}

void Ammo::ReloadAmmo() {
	mAmmo = 10;
}

void Ammo::Update() {

}

void Ammo::Render() {
	for (int i = 0; i < mAmmo; i++) {
		mTextures[i]->Render();
	}
}