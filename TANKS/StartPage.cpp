#include "StartPage.h"
using namespace Tanks;

//OpenGL_Page OpenGL_Page::page;


StartPage::StartPage(void) {
	cout<<" StartPage::StartPage(void) "<<endl;
	index = 0;
	backGroundTexture.FromFile(L"Textures\\StartPage\\BackGround.bmp");
	buttonTextures[0].FromFile(L"Textures\\StartPage\\ButtonContinue.bmp");
	buttonTextures[1].FromFile(L"Textures\\StartPage\\ButtonNewGame.bmp");
	buttonTextures[2].FromFile(L"Textures\\StartPage\\ButtonSaveGame.bmp");
	buttonTextures[3].FromFile(L"Textures\\StartPage\\ButtonLoadGame.bmp");
	buttonTextures[4].FromFile(L"Textures\\StartPage\\ButtonOptions.bmp");
	buttonTextures[5].FromFile(L"Textures\\StartPage\\ButtonDeveloper.bmp");
	buttonTextures[6].FromFile(L"Textures\\StartPage\\ButtonQuit.bmp");
	textHelo = new OpenGL_Text(L"Textures\\text.bmp","heloword",Size2i(32,32));
	cout<<" END StartPage::StartPage(void) "<<endl;
}

StartPage::StartPage(const StartPage& startPage) {
	cout<<" StartPage(const StartPage& startPage)"<<endl;
	index = 0;
	backGroundTexture.FromFile(L"Textures\\StartPage\\BackGround.bmp");
	buttonTextures[0].FromFile(L"Textures\\StartPage\\ButtonNewGame.bmp");
	buttonTextures[1].FromFile(L"Textures\\StartPage\\ButtonOptions.bmp");
	buttonTextures[2].FromFile(L"Textures\\StartPage\\ButtonQuit.bmp");
	cout<<" END StartPage(const StartPage& startPage)"<<endl;
}

StartPage::~StartPage(void) {

}

Tanks::StartPage StartPage::operator = (StartPage& startPage) {
	cout<<" StartPage::operator = (StartPage& startPage)  "<<endl;
	if(this == &startPage)	return *this;
	index = startPage.index;
	backGroundTexture.FromFile(L"Textures\\StartPage\\BackGround.bmp");
	buttonTextures[0].FromFile(L"Textures\\StartPage\\ButtonNewGame.bmp");
	buttonTextures[1].FromFile(L"Textures\\StartPage\\ButtonOptions.bmp");
	buttonTextures[2].FromFile(L"Textures\\StartPage\\ButtonQuit.bmp");
	return *this;

}


Texture& StartPage::BackGroundTexture(void) {
	return  backGroundTexture;
}

Texture& StartPage::ButtonTexture(int index) {
	return buttonTextures[index];
}

void StartPage::MainCycle(void) {
	//cout<<" StartPage::MainCycle(void)  "<<endl;
	glPushMatrix();
		glTranslated(0*8, 36*8, 0);
		textHelo->Displey();
		glPopMatrix();

		glEnable(GL_TEXTURE_2D);
		glColor3d(1,1,1);
		glBindTexture(GL_TEXTURE_2D, backGroundTexture.Get());
		glBegin(GL_QUADS);
			glTexCoord2d(0,0); glVertex3d(0,0, 0);
			glTexCoord2d(0,1); glVertex3d(0, 320, 0);
			glTexCoord2d(1,1); glVertex3d(320,320, 0);
			glTexCoord2d(1,0); glVertex3d(320,0, 0);
		glEnd();

	for (int i = 0; i < 7; i++) {
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
		glPushMatrix();
			glTranslated(20*8, 38*8 - i*48, -1);
			glEnable(GL_TEXTURE_2D);
			glColor3d(1,1,1);
			glBindTexture(GL_TEXTURE_2D, buttonTextures[i].Get());
			if(index == i) glColor3d(1,1,0);
			glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(-64,-16, 0);
				glTexCoord2d(0,1); glVertex3d(-64, 16, 0);
				glTexCoord2d(1,1); glVertex3d( 64, 16, 0);
				glTexCoord2d(1,0); glVertex3d( 64,-16, 0);
			glEnd();
		glPopMatrix();
	}

}

void StartPage::Keyboard(int key, int x, int y) {
	printf("start page key = %u \n", key);
	switch(key) {
	case GLFW_KEY_UP:		index--;	break;
	case GLFW_KEY_DOWN:		index++;	break;
	case GLFW_KEY_ESCAPE:	exit(0);	break;
	case GLFW_KEY_ENTER: {
		if(index == 0) {
			page = gamePage;
		}
		if(index == 1) {
			delete gamePage;
			gamePage = new GamePage();
			page = gamePage;
		}
		if(index == 2) {
			page = saveGamePage;
		}
		if(index == 3) {

		}
		if(index == 4) {

		}
		if(index == 5) {

		}
		if(index == 6) {

		}
	}	break;	// Enter

	default: break;
	}
}

void StartPage::KeyboardUp(unsigned char c, int x, int y) {

}

void StartPage::Mouse(int butom, int state, int x, int y) {
	cout<<" Mouse butom = "<<butom<<"; state = "<<state<<"; x= "<<x<<"; y = "<<y<<endl;
}

