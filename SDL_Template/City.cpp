#include "City.h"
#include "PhysicsManager.h"
#include "BoxCollider.h"

City::City(Vector2 position) {
	Position(position);
	mDestroyed = false;

	mCity = new GLTexture("City.png");
	mCity->Parent(this);
	mCity->Position(Vec2_Zero);
	mCity->Scale(Vector2(0.5, 0.25));

	mCityDestroyed = new GLTexture("CityDestroyed.png");
	mCityDestroyed->Parent(this);
	mCityDestroyed->Position(10, -20);
	mCityDestroyed->Scale(Vector2(0.5, 0.50));

	AddCollider(new BoxCollider(Vector2(mCity->ScaledDimensions().x, mCity->ScaledDimensions().y)));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);
}

City::~City() {

}

void City::Render() {
	if (mDestroyed) {
		mCityDestroyed->Render();
	}
	else {
		mCity->Render();
	}

	PhysEntity::Render();
}

bool City::IgnoreCollisions() {
	return false;
}

void City::Hit(PhysEntity* other) {
	// code goes here for when city is hit
	mDestroyed = true;
	std::cout << "HIT!" << std::endl;
}

