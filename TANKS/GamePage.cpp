#include "GamePage.h"


GamePage::GamePage(void) {
	cout<<" GamePage::GamePage(void) "<<endl;
	level = 1;
	maxLevel = 2;
	gameZone = new Tanks::GameZone("Data\\Levels\\", level);
	timerUpdate = new Timer();
	timerAnimation = new Timer();
	timerAddNextTank = new Timer();
	animation = new Animation(L"Textures\\explosion.bmp", Size2i(64,64),4,4);
	animation->SetObject2D(Object2D(0,0,64,64));
	cout<<" END GamePage::GamePage(void) "<<endl;
}

GamePage::~GamePage(void) {
	delete timerUpdate;
	delete timerAnimation;
}

void GamePage::MainCycle(void) {
	gameZone->Key();
	if(timerUpdate->TimePassed(20)) {
		gameZone->XY();

		timerUpdate->Start();
	}
	if(timerAnimation->TimePassed(40)) {
		gameZone->UpdateAnimation();
		animation->NextKader();

		timerAnimation->Start();
	}
	if(timerAddNextTank->TimePassed(2000)) {
		gameZone->AddNextTank();

		timerAddNextTank->Start();
	}
	//animation->Displey();
	gameZone->Displey();
	

	if(gameZone->victory == true) {
		delete gameZone;
		if(level >= maxLevel) {
			gameZone = new Tanks::GameZone("Data\\Levels\\");
			page = startPage;
		}
		else {
			gameZone = new Tanks::GameZone("Data\\Levels\\",++level);
			page = victoryPage;
		}
	}
	if(gameZone->defeat == true) {
		delete gameZone;
		gameZone = new Tanks::GameZone("Data\\Levels\\");
		page = gameOverPage;
	}
}

void GamePage::Keyboard(int key, int x, int y) {
	//printf("key: %i ", c);
	switch(key){
	case 246:{	gameZone->key[key] = true;	}	break;	
	case 179:{ 	gameZone->key[key] = true;	}	break;
	case 226:{  gameZone->key[key] = true;	}	break;
	case 244:{ 	gameZone->key[key] = true;	}	break;
	case 231:{	gameZone->key[key] = true;	}	break;
	case 230:{ 	gameZone->key[key] = true;	}	break;
	case 186:{  gameZone->key[key] = true;	}	break;
	case 228:{ 	gameZone->key[key] = true;	}	break;
	case  13:{ 	gameZone->key[key] = true;	}	break;
	case  32:{ 	gameZone->key[key] = true;	}	break;
	case  27:{  page = startPage;}	break;

	default: break;
	}
}

void GamePage::KeyboardUp(unsigned char c, int x, int y) {
	switch(c){
	case 246:{	gameZone->key[c] = false;	}	break;	
	case 179:{ 	gameZone->key[c] = false;	}	break;
	case 226:{  gameZone->key[c] = false;	}	break;
	case 244:{ 	gameZone->key[c] = false;	}	break;
	case 231:{	gameZone->key[c] = false;	}	break;	
	case 230:{ 	gameZone->key[c] = false;	}	break;
	case 186:{  gameZone->key[c] = false;	}	break;
	case 228:{ 	gameZone->key[c] = false;	}	break;
	case  13:{ 	gameZone->key[c] = false;	}	break;
	case  32:{ 	gameZone->key[c] = false;	}	break;

	default: break;
	}
}

void GamePage::Mouse(int butom, int state, int x, int y) {

}

