#include "OpenGL_Text.h"


OpenGL_Text::OpenGL_Text(void)
{
}

OpenGL_Text::OpenGL_Text(LPCWSTR nameFile, string text, Size2i size) {
	texture.FromFile(nameFile);
	this->text = text;
	this->size = size;
}


OpenGL_Text::~OpenGL_Text(void)
{
}

void OpenGL_Text::SetText(string text) {

}

void OpenGL_Text::FromFile(LPCWSTR nameFile, string text, Size2i size) {
	texture.FromFile(nameFile);
	this->text = text;
	this->size = size;

}

void OpenGL_Text::Displey(void) {
	for (int i = 0; i < (int)text.size(); i++) {
		int index = text[i] - 97;
		int x = (index % 8);
		int y = 3 - index / 8 ;
		Point2d pMin((double)x / (double)8,		(double)y / (double)4);
		Point2d pMax((double)(x+1) / (double)8, (double)(y+1) / (double)4);
		glPushMatrix();
		glTranslated(i * size.width,0,0);
		glEnable(GL_TEXTURE_2D);
			glColor3d((i%2)*0.5,1,1);
			glBindTexture(GL_TEXTURE_2D, texture.Get());
			glBegin(GL_QUADS);
				glTexCoord2d(pMin.x, pMin.y); glVertex3d(0,			0,			0);
				glTexCoord2d(pMin.x, pMax.y); glVertex3d(0,			size.height,0);
				glTexCoord2d(pMax.x, pMax.y); glVertex3d(size.width,size.height,0);
				glTexCoord2d(pMax.x, pMin.y); glVertex3d(size.width,0,			0);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
	}
	/*glEnable(GL_TEXTURE_2D);
		glColor3d(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture.Get());
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex3d(0,	0,	1);
			glTexCoord2d(0, 1); glVertex3d(0,	64,	1);
			glTexCoord2d(1, 1); glVertex3d(128,	64,	1);
			glTexCoord2d(1, 0); glVertex3d(128,	0,	1);
		glEnd();
		glDisable(GL_TEXTURE_2D);*/
}
