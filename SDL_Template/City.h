#ifndef __CITY_H
#define __CITY_H
#include "AnimatedGLTexture.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "PhysEntity.h"


class City : public PhysEntity {
private:
	bool mDestroyed;
	Texture* mCity;
	Texture* mCityDestroyed;


public:

	void Destroyed(bool value) { mDestroyed = value; }

	bool Destroyed() { return mDestroyed; }



	City();
	~City();

	void Render() override;
	};
#endif
