#ifndef __AMMO_H
#define __AMMO_H

#include "GameEntity.h"
#include "GLTexture.h"

using namespace SDLFramework;

class Ammo : public GameEntity {
private:
	Texture* mTextures[10];
	int mAmmo;

public:
	Ammo();
	~Ammo();

	bool HasAmmo() {
		return mAmmo > 0;
	}
	
	void UseAmmo();
	void ReloadAmmo();

	void Update() override;
	void Render() override;
};

#endif
