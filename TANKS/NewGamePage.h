#pragma once
#include "OpenGL_Page.h"
#include "GameZone.h"
using namespace Tanks;
class NewGamePage: public OpenGL_Page {
private:

public:
	NewGamePage(void);
	~NewGamePage(void);
	void MainCycle(void);
	void Keyboard(int key, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	void Mouse(int butom, int state, int x, int y);
};

