#include "VictoryPage.h"


VictoryPage::VictoryPage(void) {

}

VictoryPage::VictoryPage(LPCWSTR nameFile) {
	backGroundTexture.FromFile(nameFile);
}

VictoryPage::~VictoryPage(void)
{
}

void VictoryPage::MainCycle(void) {
	glEnable(GL_TEXTURE_2D);
		glColor3d(1,1,1);
		glBindTexture(GL_TEXTURE_2D, backGroundTexture.Get());
		glBegin(GL_QUADS);
			glTexCoord2d(0,0); glVertex3d(0,0, 0);
			glTexCoord2d(0,1); glVertex3d(0, 320, 0);
			glTexCoord2d(1,1); glVertex3d(320,320, 0);
			glTexCoord2d(1,0); glVertex3d(320,0, 0);
		glEnd();
}

void VictoryPage::Keyboard(int key, int x, int y) {
	page = gamePage;
}

void VictoryPage::KeyboardUp(unsigned char c, int x, int y) {

}

void VictoryPage::Mouse(int butom, int state, int x, int y) {

}

