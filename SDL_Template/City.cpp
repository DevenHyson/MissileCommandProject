#include "City.h"

City::City() {
	//load textures
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
}