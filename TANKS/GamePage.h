#pragma once
#include "opengl_page.h"
#include "GameZone.h"
#include "Timer.h"
#include "Animation.h"

using namespace Tanks;

class GamePage :	public OpenGL_Page {
private:
	int level;
	int maxLevel;
	GameZone* gameZone;
	Timer* timerUpdate;
	Timer* timerAnimation;
	Timer* timerAddNextTank;
	Animation* animation;
	List<Animation> listAnimation;
public:
	GamePage(void);
	~GamePage(void);
	GameZone& GameZone(void);
	void MainCycle(void);
	void Keyboard(int key, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	void Mouse(int butom, int state, int x, int y);

};

