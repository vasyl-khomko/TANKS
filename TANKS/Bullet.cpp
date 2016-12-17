#include "Bullet.h"

Bullet::Bullet(void) {
	SetWidth(6);
	SetHeight(6);
	SetDelta(2);
}

Bullet::~Bullet(void) {

}

bool Bullet::GetTest(void)const {
	return test;	
}

void Bullet::SetTest(bool _test) {
	test = _test;	
}

void Bullet::Displey(void) {
	glColor3d(1,1,1);
	glPushMatrix();
		glTranslated(GetX(), GetY(), 0);
		glBegin(GL_POLYGON);
			glVertex3d(0, 0, 0);
			glVertex3d(0, GetHeight(), 0);
			glVertex3d(GetWidth(), GetHeight(), 0);
			glVertex3d(GetWidth(), 0, 0);
		glEnd();
	glPopMatrix();
}