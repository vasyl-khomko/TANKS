#pragma once
#include <stdio.h>
#include "Texture.h"
#include "GeometryTypes.h"
using namespace Geometry;
// ����� ����������� ��'��� � 2D �������
class Object2D {
	Point2i position;
	Size2ui size;
public:
	Object2D(void);
	Object2D(Point2i position, Size2ui size);
	Object2D(int x, int y, unsigned int width, unsigned int height);
	~Object2D(void);
	//  ������� x-���������� ������� ��'����
	int GetX(void)const;
	//  ������� y-���������� ������� ��'����
	int GetY(void)const;
	//  ������� ������� ��'����
	Point2i GetPos(void)const;
	//  ������� ������ ��'����
	unsigned int GetWidth(void)const;
	//  ������� ������ ��'����
	unsigned int GetHeight(void)const;
	//  ������� ����� ��'����
	Size2ui GetSize(void)const;
	void SetX(int x);
	void SetY(int y);
	void SetPos(Point2i position);
	void SetWidth(unsigned int width);
	//  ������� ������ ��'����
	void SetHeight(unsigned int height);
	//  ������� ����� ��'����
	void SetSize(Size2ui size);
};

