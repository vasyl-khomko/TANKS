#pragma once
#include <Windows.h>
#include <GL\GL.H>
#include <GL\GLU.H>
//#include <GL\GLAUX.H>
//#include <GL\glut.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Texture.h"
#include "GeometryTypes.h"

using namespace Geometry;
using namespace std;
class Map {
private:
	Size2ui block;
	Size2ui size;
	int matrix[40][40];
	Texture blockTextures[8];
	Texture baseTexture;
public:
	Map(void);
	Map(string nameFile);
	~Map(void);
	Size2ui GetSize(void);
	int GetElement(unsigned int x, unsigned int y);
	Texture& BlockTexture(int index);
	Texture& BaseTexture(void);
	void SetElement(int element, unsigned int x, unsigned int y);
	void SetMatrix(int matrix[40][40]);
	void FromFile(string nameFile);
	void Displey(void);
};

