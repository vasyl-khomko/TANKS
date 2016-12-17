#include "Animation.h"


Animation::Animation(void)
{
}

Animation::Animation(LPCWSTR nameFile, Geometry::Size2i sizeSpriteSheet, int numSpriteSheetX, int numSpriteSheetY) {
	this->kader = 0;
	this->sizeSpriteSheet = sizeSpriteSheet;
	this->numSpriteSheetX = numSpriteSheetX;
	this->numSpriteSheetY = numSpriteSheetY;
	texture.FromFile(nameFile);

}


Animation::~Animation(void) {

}

void Animation::SetObject2D(Object2D object2D) {
	this->object2D = object2D;
}


void Animation::Displey(void) {
	int num = numSpriteSheetX * numSpriteSheetY;
	int x = (kader % num) % numSpriteSheetX;
	int y = numSpriteSheetY - (kader % num) / numSpriteSheetX;
	Point2d pMin((double)x / (double)numSpriteSheetX, (double)y / (double)numSpriteSheetY);
	Point2d pMax((double)(x+1) / (double)numSpriteSheetX, (double)(y+1) / (double)numSpriteSheetY);
	//cout<<" kader = "<<kader % num<<"\t";
	//cout<<" (x;y) = "<<x<<"; "<<y<<"\t";
	//cout<<" pMin = "<<pMin.x<<"; "<<pMin.y<<"\t";
	//cout<<" pMax = "<<pMax.x<<"; "<<pMax.y<<endl;
	glPushMatrix();
	glTranslated(object2D.GetX(),object2D.GetY(),0);
	glEnable(GL_TEXTURE_2D);
		glColor3d(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture.Get());
		glBegin(GL_QUADS);
			glTexCoord2d(pMin.x, pMin.y); glVertex3d(-(int)object2D.GetWidth()/1, -(int)object2D.GetHeight()/1, 0);
			glTexCoord2d(pMin.x, pMax.y); glVertex3d(-(int)object2D.GetWidth()/1, object2D.GetHeight()/1, 0);
			glTexCoord2d(pMax.x, pMax.y); glVertex3d( object2D.GetWidth()/1, object2D.GetHeight()/1, 0);
			glTexCoord2d(pMax.x, pMin.y); glVertex3d( object2D.GetWidth()/1, -(int)object2D.GetHeight()/1, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
}

void Animation::NextKader(void) {
	kader++;
}

bool Animation::IsEnd(void) {
	if(kader > numSpriteSheetX*numSpriteSheetY) return true;
	else return false;
}
