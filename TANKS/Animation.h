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
	//nameFile - імя файла в якому знаходиться графічний файл із SpriteSheet
	//sizeSpriteSheet - розмір SpriteSheet
	//numSpriteSheetX - кількість по X
	//numSpriteSheetY - кількість по Y
	Animation(LPCWSTR nameFile, Size2i sizeSpriteSheet, int numSpriteSheetX, int numSpriteSheetY);
	~Animation(void);
	void SetObject2D(Object2D object2D);
	void Displey(void);
	void NextKader(void);
	bool IsEnd(void);
};

