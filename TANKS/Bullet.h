#pragma once
#include <Windows.h>
#include <GL\GL.H>
#include <GL\GLU.H>
//#include <GL\GLAUX.H>
//#include <GL\glut.h>

#include "object2d_delta.h"

class Bullet :
	public Object2D_Delta {
private:
	bool test;
public:
	Bullet(void);
	~Bullet(void);
	bool GetTest()const;
	void SetTest(bool test);
	void Displey();
};

