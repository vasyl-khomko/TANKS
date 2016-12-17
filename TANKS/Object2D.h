#pragma once
#include <stdio.h>
#include "Texture.h"
#include "GeometryTypes.h"
using namespace Geometry;
// Описує прямокутний об'єкт у 2D просторі
class Object2D {
	Point2i position;
	Size2ui size;
public:
	Object2D(void);
	Object2D(Point2i position, Size2ui size);
	Object2D(int x, int y, unsigned int width, unsigned int height);
	~Object2D(void);
	//  Поветрає x-координату позиції об'єкта
	int GetX(void)const;
	//  Поветрає y-координату позиції об'єкта
	int GetY(void)const;
	//  Поветрає позицію об'єкта
	Point2i GetPos(void)const;
	//  Поветрає ширину об'єкта
	unsigned int GetWidth(void)const;
	//  Поветрає висоту об'єкта
	unsigned int GetHeight(void)const;
	//  Поветрає розмір об'єкта
	Size2ui GetSize(void)const;
	void SetX(int x);
	void SetY(int y);
	void SetPos(Point2i position);
	void SetWidth(unsigned int width);
	//  Поветрає висоту об'єкта
	void SetHeight(unsigned int height);
	//  Поветрає розмір об'єкта
	void SetSize(Size2ui size);
};

