#pragma once
#include <Windows.h>
#include <GL\GL.H>
#include <GL\GLU.H>
//#include <GL\GLAUX.H>
//#include <GL\glut.h>

#include <iostream>
#include <string>

#include "Texture.h"
#include "GeometryTypes.h"

using namespace std;
using namespace Geometry;

class OpenGL_Text {
private:
	Texture texture;
	string text;
	Size2i size;
public:
	OpenGL_Text(void);
	OpenGL_Text(LPCWSTR nameFile, string text, Size2i size);
	~OpenGL_Text(void);
	void SetText(string text);
	void FromFile(LPCWSTR nameFile, string text, Size2i size);
	void Displey(void);
};

