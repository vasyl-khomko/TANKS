#include "OpenGL_Label.h"


OpenGL_Label::OpenGL_Label(void) {

}

OpenGL_Label::OpenGL_Label(string text, Point2i position, Size2i size) {
	this->text = new OpenGL_Text(L"Textures\\text.bmp",text, Size2i(size.height, size.height));
	this->position = position;
	this->size = size;
}


OpenGL_Label::~OpenGL_Label(void) {
	delete text;
}

void OpenGL_Label::Displey(void) {
	glPushMatrix();
		glTranslated(position.x,position.y,1);
		text->Displey();
	glPopMatrix();
}

