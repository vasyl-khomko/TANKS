#pragma once
#include <iostream>
#include <string>

#include "GeometryTypes.h"
#include "OpenGL_Text.h"

using namespace std;
using namespace Geometry;

class OpenGL_Label {
private:
	OpenGL_Text* text;
	Point2i position;
	Size2i size;
public:
	OpenGL_Label(void);
	OpenGL_Label(string text, Point2i position, Size2i size);
	~OpenGL_Label(void);
	void Displey(void);
};

