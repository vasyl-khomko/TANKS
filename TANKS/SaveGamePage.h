#pragma once
#include "opengl_page.h"
#include "OpenGL_Label.h"
class SaveGamePage :	public OpenGL_Page {
private:
	OpenGL_Label* labels[4];
	OpenGL_Text* textHelo;
public:
	SaveGamePage(void);
	~SaveGamePage(void);
	void MainCycle(void);
	void Keyboard(int key, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	void Mouse(int butom, int state, int x, int y);
};

