#ifndef __CITY_H
#define __CITY_H
#include "Texture.h"


class City : public GameEntity {
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