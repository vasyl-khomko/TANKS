#include "Tank.h"

Tank::Tank(void) {

}

Tank::Tank(int x, int y, int forms) {
	SetX(x);	SetY(y);	SetWidth(16);	SetHeight(16);
	
	if(forms == 1) {
		SetDelta(0);		SetAlpha(0);
		SetForms(forms);	SetLife(4);
		texture.FromFile(L"Textures\\Tanks\\1.bmp");
	}

	if(forms == 2) {
		SetDelta(0);		SetAlpha(0);
		SetForms(forms);	SetLife(4);
		texture.FromFile(L"Textures\\Tanks\\1.bmp");
	}

	if(forms == 3) {
		SetDelta(1);		SetAlpha(180);
		SetForms(forms);	SetLife(2);
		texture.FromFile(L"Textures\\Tanks\\3.bmp");
	}
}


Tank::~Tank(void) {

}

void Tank::Init(int x, int y, int forms) {
	cout<<" Tank::Init(int x, int y, int forms) "<<endl;
	SetX(x);	SetY(y);	SetWidth(16);	SetHeight(16);
	
	if(forms == 1) {
		SetDelta(0);		SetAlpha(0);
		SetForms(forms);	SetLife(4);
		bullets[0].SetDelta(4);
		texture.FromFile(L"Textures\\Tanks\\1.bmp");
	}

	if(forms == 2) {
		SetDelta(0);		SetAlpha(0);
		SetForms(forms);	SetLife(4);
		bullets[0].SetDelta(3);
		texture.FromFile(L"Textures\\Tanks\\1.bmp");
	}

	if(forms == 3) {
		SetDelta(1);		SetAlpha(180);
		SetForms(forms);	SetLife(2);
		texture.FromFile(L"Textures\\Tanks\\3.bmp");
	}
	if(forms == 4) {
		SetDelta(2);		SetAlpha(180);
		SetForms(forms);	SetLife(4);
		bullets[0].SetDelta(3);
		texture.FromFile(L"Textures\\Tanks\\4.bmp");
	}
	cout<<" END Tank::Init(int x, int y, int forms) "<<endl;
}

void Tank::Shot(void) {
	if(bullets[0].GetTest() == true) {
		bullets[0].SetX( GetX() );	
		bullets[0].SetY( GetY() );
		bullets[0].SetAlpha( GetAlpha() );
	}
}

int Tank::GetForms(void) {
	return forms;	
}

int Tank::GetLife(void) {
	return life;	
}

Bullet* Tank::GetBullets(void) {
	return bullets;	
}

Texture& Tank::GetTexture(void) {
	return texture;
}

void Tank::SetForms(int forms) {
	this->forms = forms;	
}

void Tank::SetLife(int life) {
	this->life = life;		
}

void Tank::SetBullets(Bullet bullets[2]){
	this->bullets[0] = bullets[0];	
	this->bullets[1] = bullets[1];
}
void Tank::Displey(void) {
	glColor3d(1,1,1);
	glPushMatrix();
		glTranslated(GetX(), GetY(), 0);
		glRotated(GetAlpha(), 0,0,1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture.Get());
		glBegin(GL_QUADS);
			glTexCoord2d(0,0); glVertex3d(-16/2,-16/2, 0);
			glTexCoord2d(0,1); glVertex3d(-16/2, 16/2, 0);
			glTexCoord2d(1,1); glVertex3d( 16/2, 16/2, 0);
			glTexCoord2d(1,0); glVertex3d( 16/2,-16/2, 0);
			glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	if(bullets[0].GetTest() == true) bullets[0].Displey();
	if(bullets[1].GetTest() == true) bullets[1].Displey();
}