#pragma once
#include "opengl_page.h"
#include "NewGamePage.h"
#include "GamePage.h"
#include "Tree.h"

namespace Tanks {

class StartPage :
	public OpenGL_Page {
private:
	Texture backGroundTexture;
	Texture buttonTextures[7];
	OpenGL_Text* textHelo;
public:
	int index;
	StartPage(void);
	StartPage(const StartPage& startPage);
	~StartPage(void);
	StartPage operator = (StartPage& startPage);
	Texture& BackGroundTexture(void);
	Texture& ButtonTexture(int index);
	void MainCycle(void);
	void Keyboard(int key, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	void Mouse(int butom, int state, int x, int y);
};
}


