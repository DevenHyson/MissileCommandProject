#ifndef __TURRET_H
#define __TURRET_H

#include "GameEntity.h"
#include "GLTexture.h"
#include "Ammo.h"
#include "Missile.h"
#include <string>
#include <vector>

using namespace SDLFramework;

class Turret : public GameEntity {
private:
	Texture* mTexture;
	Ammo* mAmmo;
	std::vector<Missile*> mMissiles;

public:
	Turret(std::string textureFilename);
	~Turret();

	void Fire(Vector2 target);
	Ammo* getAmmo() { return mAmmo; }

	void Update() override;
	void Render() override;
};

#endif
