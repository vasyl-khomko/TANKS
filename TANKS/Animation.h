#pragma once
#include "Object2D.h"
#include "Texture.h"
#include "GeometryTypes.h"

using namespace Geometry;

class Animation {
	Texture texture;
	Object2D object2D;
	Size2i sizeSpriteSheet;
	int numSpriteSheetX;
	int numSpriteSheetY;
	int kader;
public:
	Animation(void);
	//nameFile - ��� ����� � ����� ����������� ��������� ���� �� SpriteSheet
	//sizeSpriteSheet - ����� SpriteSheet
	//numSpriteSheetX - ������� �� X
	//numSpriteSheetY - ������� �� Y
	Animation(LPCWSTR nameFile, Size2i sizeSpriteSheet, int numSpriteSheetX, int numSpriteSheetY);
	~Animation(void);
	void SetObject2D(Object2D object2D);
	void Displey(void);
	void NextKader(void);
	bool IsEnd(void);
};

