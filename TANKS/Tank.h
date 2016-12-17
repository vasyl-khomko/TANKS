#pragma once
#include "object2d_delta.h"
#include "Bullet.h"

class Tank :
	public Object2D_Delta {
private:
	int forms;
	int life;
	Bullet bullets[2];
	Texture texture;
public:
	Tank(void);
	Tank(int x, int y, int forms);
	~Tank(void);
	void Init(int x, int y, int forms);
	void Shot(void);
	int GetForms(void);
	int GetLife(void);
	Bullet* GetBullets(void);
	Texture& GetTexture(void);
	void SetForms(int forms);
	void SetLife(int life);
	void SetBullets(Bullet bullets[2]);
	void Displey(void);
};

