#pragma once
#include "opengl_page.h"
class GameOverPage :	public OpenGL_Page {
private:
	Texture backGroundTexture;
public:
	GameOverPage(void);
	GameOverPage(LPCWSTR nameFile);
	~GameOverPage(void);
	void MainCycle(void);
	void Keyboard(int key, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	void Mouse(int butom, int state, int x, int y);
};

