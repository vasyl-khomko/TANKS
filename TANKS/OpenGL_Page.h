#pragma once
#include <Windows.h>
#include <GL\GL.H>
#include <GL\GLU.H>
#include <GLFW\glfw3.h>
//#include <GL\GLAUX.H>
//#include <GL\glut.h>
#include <stdio.h>

#include "Texture.h"
#include "OpenGL_Text.h"

class OpenGL_Page {
public:
	static OpenGL_Page* newGamePage;
	static OpenGL_Page* gamePage;
	static OpenGL_Page* startPage;
	static OpenGL_Page* victoryPage;
	static OpenGL_Page* gameOverPage;
	static OpenGL_Page* saveGamePage; 
	static OpenGL_Page* page;
	static GLFWwindow* window;

	~OpenGL_Page(void) { }

	virtual void MainCycle(void) = 0;
	virtual void Keyboard(int key, int x, int y) = 0;
	virtual void KeyboardUp(unsigned char c, int x, int y) = 0;
	virtual void Mouse(int butom, int state, int x, int y) = 0;

	static void SetPage(OpenGL_Page* _page) {
		page = _page;
	}
};

