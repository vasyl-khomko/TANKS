#include "GameZone.h"

using namespace Tanks;

GameZone::GameZone(void) {
	victory = false;
	defeat = false;
	block.width = 8;
	block.height = 8;
	SetSize(Size2ui(5*block.width, 5*block.height));
	listTanks = new ListTanks();
	for(int i = 0; i < 256; i++) {
		key[i] = false;
	}
}

GameZone::GameZone(string catalogue,int level) {
	cout<<" GameZone::GameZone(string catalogue,int level)"<<endl;
	catalogue += Convert::IntToString(level);
	catalogue += "\\";

	victory = false;
	defeat = false;
	block.width = 8;
	block.height = 8;
	SetSize(Size2ui(40*block.width, 40*block.height));
	cout<<" 1"<<endl;
	listTanks = new ListTanks(catalogue + "tanks.txt");
	cout<< " 1-2"<<endl;
	map = new Map(catalogue + "map.txt");
	cout<<"2 "<<endl;
	for(int i = 0; i < 256; i++) {
		key[i] = false;
	}
	cout<<" END GameZone::GameZone(string catalogue,int level) "<<endl;
}

GameZone::~GameZone(void) {

}

void GameZone::Key(void) {
	if(glfwGetKey(OpenGL_Page::window, GLFW_KEY_UP) == GLFW_PRESS) {
		listTanks->SetDelta(1,0);
		listTanks->SetAlpha(0,0);
	}
	if(glfwGetKey(OpenGL_Page::window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		listTanks->SetDelta(1,0);
		listTanks->SetAlpha(180,0);;
	}
	if(glfwGetKey(OpenGL_Page::window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		listTanks->SetDelta(1,0);
		listTanks->SetAlpha(270,0);
	}
	if(glfwGetKey(OpenGL_Page::window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		listTanks->SetDelta(1,0);
		listTanks->SetAlpha(90,0);
	}
	if(key[231] == true) {
		listTanks->SetDelta(1,1);
		listTanks->SetAlpha(0,1);
	}
	if(key[230] == true) {
		listTanks->SetDelta(1,1);
		listTanks->SetAlpha(180,1);
	}
	if(key[186] == true) {
		listTanks->SetDelta(1,1);
		listTanks->SetAlpha(270,1);
	}
	if(key[228] == true){
		listTanks->SetDelta(1,1);
		listTanks->SetAlpha(90,1);
	}
	if(key[32] == true){
		if((*listTanks)[0].GetBullets()[0].GetTest() == false) {
				(*listTanks)[0].GetBullets()[0].SetTest(true);
				(*listTanks)[0].Shot();
		}
	}
	if(key[13] == true){
		if((*listTanks)[1].GetBullets()[0].GetTest() == false) {
				(*listTanks)[1].GetBullets()[0].SetTest(true);
				(*listTanks)[1].Shot();
		}
	}
}

bool GameZone::ConfinesZone(Object2D object2D) {
	if(object2D.GetX() - (int)object2D.GetWidth()/2		< 0				)	return true;
	if(object2D.GetX() + (int)object2D.GetWidth()/2		> (int)GetWidth())	return true;
	if(object2D.GetY() - (int)object2D.GetHeight()/2	< 0				)	return true;
	if(object2D.GetY() + (int)object2D.GetHeight()/2	> (int)GetHeight())	return true;
	return false;
}

bool GameZone::OB2DD_On_Map(Object2D_Delta object2D_d, bool test){	
	//printf(" way = %c \n",object2D_d.GetAlpha());
	//printf(" delta = %f \n",object2D_d.GetDelta());
	//printf(" index = %i \n",(int)(object2D_d.GetWidth()/object2D_d.GetDelta()) );
	unsigned int indexX, indexY;
	if(object2D_d.GetAlpha() == 0) {
		for(unsigned int i = 0; i < object2D_d.GetWidth(); i++) {
			indexX = (object2D_d.GetX()-object2D_d.GetWidth()/2+i)/block.width;
			indexY = (object2D_d.GetY()+object2D_d.GetHeight()/2-1)/block.height;
			if(	map->GetElement(indexX, indexY) == 1){
				if(test == true)	map->SetElement(0, indexX, indexY);
				return true;
			}
			if(	map->GetElement(indexX, indexY) == 2) {
				//if(test == true)	map.SetElement(0, indexX, indexY);
				return true;
			}
		}
	}
	if(object2D_d.GetAlpha() == 180){
		for(unsigned int i = 0; i < object2D_d.GetWidth(); i++){
			indexX = (object2D_d.GetX()-object2D_d.GetWidth()/2+i)/block.width;
			indexY = (object2D_d.GetY()-object2D_d.GetHeight()/2)/block.height;
			if(	map->GetElement(indexX, indexY) == 1){
				if(test == true)	map->SetElement(0, indexX, indexY);
				return true;
			}
			if(	map->GetElement(indexX, indexY) == 2){
				//if(test == true)	map.SetElement(0, indexX, indexY);
				return true;
			}
		}
	}
	if(object2D_d.GetAlpha() == 270) {
		for(unsigned int i = 0; i < object2D_d.GetHeight(); i++) {
			indexX = (object2D_d.GetX()+object2D_d.GetWidth()/2-1)/block.width;
			indexY = (object2D_d.GetY()-object2D_d.GetHeight()/2+i)/block.height;
			if(	map->GetElement(indexX, indexY) == 1){
				if(test == true)	map->SetElement(0, indexX, indexY);
				return true;
			}
			if(	map->GetElement(indexX, indexY) == 2){
				//if(test == true)	map.SetElement(0, indexX, indexY);
				return true;
			}
		}
	}
	if(object2D_d.GetAlpha() == 90) {
		for(unsigned int i = 0; i < object2D_d.GetHeight(); i++) {
			indexX = (int)(object2D_d.GetX()-object2D_d.GetWidth()/2)/block.width;
			indexY = (int)(object2D_d.GetY()-object2D_d.GetHeight()/2+i)/block.height;
			if(	map->GetElement(indexX, indexY) == 1){
				if(test == true)	map->SetElement(0, indexX, indexY);
				return true;
			}
			if(	map->GetElement(indexX, indexY) == 2){
				//if(test == true)	map.SetElement(0, indexX, indexY);
				return true;
			}
			}
	}
	return false;
}
bool GameZone::OB2DD_On_OB2DD(Object2D_Delta OB2DD,Object2D OB2D, bool test) {	
	if(OB2DD.GetAlpha() == 0) {
		if(OB2DD.GetY() + OB2DD.GetHeight()/2 > OB2D.GetY() - OB2D.GetHeight()/2)
			if(OB2DD.GetY() + OB2DD.GetHeight()/2 < OB2D.GetY() + OB2D.GetHeight()/2)
				if(OB2DD.GetX() + OB2DD.GetWidth()/2 > OB2D.GetX() - OB2D.GetWidth()/2)
					if(OB2DD.GetX() - OB2DD.GetWidth()/2 < OB2D.GetX() + OB2D.GetWidth()/2)	return true;
	}
	if(OB2DD.GetAlpha() == 180){
		if(OB2DD.GetY() - OB2DD.GetHeight()/2 < OB2D.GetY() + OB2D.GetHeight()/2)
			if(OB2DD.GetY() - OB2DD.GetHeight()/2 > OB2D.GetY() - OB2D.GetHeight()/2)
				if(OB2DD.GetX() + OB2DD.GetWidth()/2 > OB2D.GetX() - OB2D.GetWidth()/2)
					if(OB2DD.GetX() - OB2DD.GetWidth()/2 < OB2D.GetX() + OB2D.GetWidth()/2)	return true;
	}
	if(OB2DD.GetAlpha() == 270){
		if(OB2DD.GetX() + OB2DD.GetWidth()/2 > OB2D.GetX() - OB2D.GetWidth()/2)
			if(OB2DD.GetX() + OB2DD.GetWidth()/2 < OB2D.GetX() + OB2D.GetWidth()/2)
				if(OB2DD.GetY() + OB2DD.GetHeight()/2 > OB2D.GetY() - OB2D.GetHeight()/2)
					if(OB2DD.GetY() - OB2DD.GetHeight()/2 < OB2D.GetY() + OB2D.GetHeight()/2)	return true;
	}
	if(OB2DD.GetAlpha() == 90){
		if(OB2DD.GetX() - OB2DD.GetWidth()/2 < OB2D.GetX() + OB2D.GetWidth()/2)
			if(OB2DD.GetX() - OB2DD.GetWidth()/2 > OB2D.GetX() - OB2D.GetWidth()/2)
				if(OB2DD.GetY() + OB2DD.GetHeight()/2 > OB2D.GetY() - OB2D.GetHeight()/2)
					if(OB2DD.GetY() - OB2DD.GetHeight()/2 < OB2D.GetY() + OB2D.GetHeight()/2)	return true;
	}
	return false;
}

void GameZone::XY(){
	//cout<<" ### Обрахунок наступних координат танків і патронів "<<endl;

	// Обрахунок наступних координат танків і патронів
	for(int i = 0; i < listTanks->NumTanksAll(); i++) {
		(*listTanks)[i].NextPos();
		if((*listTanks)[i].GetBullets()[0].GetTest() == true)
			(*listTanks)[i].GetBullets()[0].NextPos();
		else {
			if(i >= listTanks->NumTanksMain()){
				(*listTanks)[i].GetBullets()[0].SetTest(true);
				(*listTanks)[i].Shot();
			}
		}
	}	
	// Перевірка на вихід за межі карти танків і патронів
	for(int i = 0; i < listTanks->NumTanksAll(); i++) {
		if(ConfinesZone((*listTanks)[i]) == true) {
			(*listTanks)[i].PrevPos();	
			if(i >= listTanks->NumTanksMain())	(*listTanks)[i].NewWay();
		}
		if(ConfinesZone((*listTanks)[i].GetBullets()[0]) == true) {
			(*listTanks)[i].GetBullets()[0].SetTest(false);
		}
	}
	// Перевірка виїзду танків на обєкти карти і патронів на обєкти карти
	for(int i = 0; i < listTanks->NumTanksAll(); i++) {
		if(OB2DD_On_Map((*listTanks)[i], false) == true) {
			(*listTanks)[i].PrevPos();	
			if(i >= listTanks->NumTanksMain())	(*listTanks)[i].NewWay();
		}
		if(OB2DD_On_Map( (*listTanks)[i].GetBullets()[0], true) == true) {
			(*listTanks)[i].GetBullets()[0].SetTest(false);
		}
	}
	// Перевірка зіштовхування танків
	for(int i = 0; i < listTanks->NumTanksAll(); i++) {
		for(int j = 0; j < listTanks->NumTanksAll(); j++) {		
			if(OB2DD_On_OB2DD((*listTanks)[i], (*listTanks)[j], true) == true) {
				(*listTanks)[i].PrevPos();	
				if(i >= listTanks->NumTanksMain())	(*listTanks)[i].NewWay();
			}
		}
	}
	// Перевірка влучання 
	for(int i = 0; i < listTanks->NumTanksMain(); i++) {
		for(int j = listTanks->NumTanksMain(); j < listTanks->NumTanksAll(); j++) {
			if((*listTanks)[i].GetBullets()[0].GetTest() == true){
				if(OB2DD_On_OB2DD((*listTanks)[i].GetBullets()[0] , (*listTanks)[j], true) == true) {
					(*listTanks)[i].GetBullets()[0].SetTest(false);
					(*listTanks)[j].SetLife((*listTanks)[j].GetLife() - 1);
					if((*listTanks)[j].GetLife() == 0) {
						cout<<" 1 (*listTanks)["<<j<<"].GetLife() == 0 "<<endl;
						Animation* tmp = new Animation(L"Textures\\explosion.bmp", Size2i(64,64),4,4);
						tmp->SetObject2D((*listTanks)[j]);
						listAnimation.InsertBack(*tmp);
	
						listTanks->Remove(j);
					}
				}
			}
		}
	}
	if(listTanks->NumTanksEnemy() == 0) {
		victory = true;
		return;
	}

	for(int i = listTanks->NumTanksMain(); i < listTanks->NumTanksAll(); i++) {
		for(int j = 0; j < listTanks->NumTanksMain(); j++) {
			if(OB2DD_On_OB2DD((*listTanks)[i].GetBullets()[0], (*listTanks)[j], true) == true) {
				(*listTanks)[i].GetBullets()[0].SetTest(false);
				(*listTanks)[j].SetLife((*listTanks)[j].GetLife() - 1);
				if((*listTanks)[j].GetLife() == 0) {
					Animation* tmp = new Animation(L"Textures\\explosion.bmp", Size2i(64,64),4,4);
					tmp->SetObject2D((*listTanks)[j]);
					listAnimation.InsertBack(*tmp);
					cout<<" ==================================== "<<endl;
					cout<<" (*listTanks)["<<j<<"].GetLife() == 0 "<<endl;
					cout<<" ==================================== "<<endl;
					listTanks->Remove(j);
				}
			}
		}
	}
	if(listTanks->NumTanksMain() == 0) {
		defeat = true;
		return;
	}
	listTanks->SetDelta(0,0);
	listTanks->SetDelta(0,1);
}

void GameZone::AddNextTank(void) {
	listTanks->AddNext();
}


void GameZone::UpdateAnimation(void) {
	for (int i = 0; i < listAnimation.Size(); i++){
		listAnimation.Data(i).NextKader();
		if(listAnimation.Data(i).IsEnd()) {	
			listAnimation.DeleteIndex(i);
		}
	}
}


void GameZone::Displey(void) {
	for(int i = 0; i < listTanks->NumTanksAll(); i++) {
		(*listTanks)[i].Displey();
	}
	map->Displey();
	for (int i = 0; i < listAnimation.Size(); i++){
		listAnimation.Data(i).Displey();
	}
}
