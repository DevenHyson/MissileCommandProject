#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "AnimatedGLTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {

private:
	Timer* mTimer;
	InputManager* mInput;

	// Top Bar Entities
	GameEntity* mTopBar;
	Texture* mPlayerOne;
	Texture* mHiScore;
	Texture* mTarget;
	Texture* mBackground;
	Scoreboard* mTopScore;


	// Bottom Bar Entities
	GameEntity* mBottomBar;
	Texture* mNamco;


	// stars
	//BackgroundStars* mStars;

public:
	StartScreen();
	~StartScreen();


	void Update() override;
	void Render() override;
};
#endif