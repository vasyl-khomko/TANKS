#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <GLFW\glfw3.h>

#include "OpenGL_Page.h"
#include "Convert.h"
#include "Object2D.h"
#include "Tank.h"
#include "Map.h"
#include "List.h"
#include "ListTanks.h"
#include "Animation.h"
#include "Timer.h"

using namespace std;

namespace Tanks {

class GameZone :
	public Object2D {
private:
	int time;
	Size2ui block;
	ListTanks* listTanks;
	List<Animation> listAnimation;
	Timer* timerAddTank;
	Map* map;
	GLFWwindow* window;
public:
	bool victory;
	bool defeat;
	bool key[256];
	GameZone(void);
	GameZone(string catalogue, int livel = 1);
	~GameZone(void);
	void Key(void);
	bool ConfinesZone(Object2D object2D);
	bool OB2DD_On_Map(Object2D_Delta object2D_d, bool test);
	bool OB2DD_On_OB2DD(Object2D_Delta OB2DD,Object2D OB2D, bool test);

	void AddNextTank(void);
	void XY(void);
	void UpdateAnimation(void);
	void Displey(void);
};

}