#ifndef __TURRET_H
#define __TURRET_H

#include "GameEntity.h"
#include "GLTexture.h"
#include "Ammo.h"
#include "Missile.h"
#include <string>
#include <vector>
class PlayScreen;

using namespace SDLFramework;

class Turret : public GameEntity {
private:
	PlayScreen* mPlayScreen;
	Texture* mTexture;
	Ammo* mAmmo;
	std::vector<Missile*> mMissiles;
	std::vector<Missile*> mMissilesToBeDeleted;
	

public:
	Turret(PlayScreen* playscreen, std::string textureFilename);
	~Turret();

	void Fire(Vector2 target);
	Ammo* getAmmo() { return mAmmo; }

	void Update() override;
	void Render() override;
};

#endif
