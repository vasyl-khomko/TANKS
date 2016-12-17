#pragma once
#include "StartPage.h"

class Script {
private:
	Tanks::StartPage p;
public:
	Script(void);
	~Script(void);
	OpenGL_Page* GetPage(void);
};

