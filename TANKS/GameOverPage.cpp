#include "GameOverPage.h"


GameOverPage::GameOverPage(void)
{
}

GameOverPage::GameOverPage(LPCWSTR nameFile) {
	backGroundTexture.FromFile(nameFile);
}

GameOverPage::~GameOverPage(void)
{
}

void GameOverPage::MainCycle(void) {
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

void GameOverPage::Keyboard(int key, int x, int y) {
	page = startPage;
}

void GameOverPage::KeyboardUp(unsigned char c, int x, int y) {

}

void GameOverPage::Mouse(int butom, int state, int x, int y) {

}
