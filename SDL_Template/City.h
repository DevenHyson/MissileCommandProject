#ifndef __CITY_H
#define __CITY_H

#include "GLTexture.h"
#include "PhysEntity.h"

class City : public PhysEntity {
private:
	bool mDestroyed;
	Texture* mCity;
	Texture* mCityDestroyed;

public:
	void Destroyed(bool value) { mDestroyed = value; }
	bool Destroyed() { return mDestroyed; }

	City(Vector2 position);
	~City();

	// Inherited from PhysEntity
	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

	void Render() override;
};

#endif
