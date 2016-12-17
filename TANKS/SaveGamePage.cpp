#include "SaveGamePage.h"


SaveGamePage::SaveGamePage(void) {
	labels[0] = new OpenGL_Label("wasyl",Point2i(20*8,30*8),Size2i(16*5, 16));
	labels[1] = new OpenGL_Label("taras",Point2i(20*8,28*8),Size2i(16*5, 16));
	labels[2] = new OpenGL_Label("homko",Point2i(20*8,26*8),Size2i(16*5, 16));
	labels[3] = new OpenGL_Label("hanna",Point2i(20*8,24*8),Size2i(16*5, 16));
}


SaveGamePage::~SaveGamePage(void) {
	for (int i = 0; i < 4; i++) {
		delete labels[i];
	}
}

void SaveGamePage::MainCycle(void) {
	for (int i = 0; i < 4; i++) {
		labels[i]->Displey();
	}
}

void SaveGamePage::Keyboard(int key, int x, int y) {
	page = startPage;
}

void SaveGamePage::KeyboardUp(unsigned char c, int x, int y) {

}

void SaveGamePage::Mouse(int butom, int state, int x, int y) {

}

