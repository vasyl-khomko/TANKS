#pragma once
#include "opengl_page.h"
class VictoryPage :
	public OpenGL_Page {
	Texture backGroundTexture;
public:
	int level;
	VictoryPage(void);
	VictoryPage(LPCWSTR nameFile);
	~VictoryPage(void);
	void MainCycle(void);
	void Keyboard(int key, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	void Mouse(int butom, int state, int x, int y);
};

