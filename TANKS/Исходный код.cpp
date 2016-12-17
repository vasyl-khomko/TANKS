// OpenGL Project

#include <Windows.h>
#include <GL\glew.h>
#include <GL\GL.H>
#include <GL\GLU.H>
//#include <GL\GLAUX.H>
//#include <GL\glut.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <GLFW\glfw3.h>
#include <direct.h>

#include "List.h"
#include "GameZone.h"
#include "StartPage.h"
#include "NewGamePage.h"
#include "VictoryPage.h"
#include "GameOverPage.h"
#include "SaveGamePage.h"
#include "Tree.h"
int time1 = 0, time2 = 0;

//====================================================================================================================
//================= Page =============================================================================================
//====================================================================================================================

GLFWwindow* OpenGL_Page::window;
OpenGL_Page* OpenGL_Page::page;
OpenGL_Page* OpenGL_Page::gamePage;
OpenGL_Page* OpenGL_Page::startPage;
OpenGL_Page* OpenGL_Page::newGamePage;
OpenGL_Page* OpenGL_Page::victoryPage;
OpenGL_Page* OpenGL_Page::gameOverPage;
OpenGL_Page* OpenGL_Page::saveGamePage;

const unsigned int deltaTimeXY = 20;


const int poleSizeX = 40;
const int poleSizeY = 40;
const int blocSize = 8;


//	Прототипи функцій
int RandomInt100(void);
void Special(int x, int y, int d) {
	cout<<" special "<<endl;
}


void Mouse(int butom, int state, int x, int y) {
	OpenGL_Page::page->Mouse(butom, state, x, y);
}

void Keyboard(unsigned char c, int x, int y) {
	cout << "Keyboard: " << c << endl;
	OpenGL_Page::page->Keyboard(c, x, y);
}

void KeyboardUp(unsigned char c, int x, int y) {
	OpenGL_Page::page->KeyboardUp(c,x,y);
}

void MainCycle(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	//if(OpenGL_Page::startPage == true) startPage.Displey();
	//if(OpenGL_Page::newGamePage == true) newGamePage.Displey();
	//gameZone.Displey();
	OpenGL_Page::page->MainCycle();

}

void Resize(int width,int height)
{
   glFlush();
   glViewport(0,0,width,height);
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   glOrtho(0,40*blocSize, 0,40*blocSize, 10,-2);   
   gluLookAt( 0,0,5, 0,0,0, 0,1,0 );
   glMatrixMode( GL_MODELVIEW );
}    
// перехід вікна у активний стан
void Entry(int state) {
	cout<<" Entry state = "<<state<<endl;
}

void OverlayDisplay(void) {
	cout<<" OverlayDisplay ";
}

void Visibility(int state) {
	cout<<" Visibility state = "<<state<<endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	printf("keyCallback key = %u \n", key);
	if (action == 1) {
		OpenGL_Page::page->Keyboard(key, 0, 0);
	}
	else if (action == 0) {
		OpenGL_Page::page->KeyboardUp(key, 0, 0);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
int main(int iArgc, char** cppArgv) {
	char* buffer;

	// Get the current working directory:   
	if ((buffer = _getcwd(NULL, 0)) == NULL)
		perror("_getcwd error");
	else {
		printf("%s \nLength: %d\n", buffer, strnlen(buffer, 1000));
		free(buffer);
	}

	setlocale(LC_ALL, "Ukrainian");

	// Initialise GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(40 * blocSize * 2, 40 * blocSize * 2, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyCallback);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 40 * blocSize, 0, 40 * blocSize, 10, -2);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	//glMatrixMode(GL_MODELVIEW);
	// Enable depth test
	//glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	//glDepthFunc(GL_LESS);

	OpenGL_Page::window = window;
	OpenGL_Page::startPage = new Tanks::StartPage();
	OpenGL_Page::newGamePage = new NewGamePage();
	OpenGL_Page::victoryPage = new VictoryPage(L"Textures\\VictoryPage.bmp");
	OpenGL_Page::gameOverPage = new GameOverPage(L"Textures\\GameOverPage.bmp");
	OpenGL_Page::saveGamePage = new SaveGamePage();
	OpenGL_Page::gamePage = new GamePage();
	OpenGL_Page::page = OpenGL_Page::startPage;

	Texture texture = Texture();
	texture.FromFile(L"Textures\\Tanks\\1.bmp");

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		// Check and call events
		glfwPollEvents();

		// Rendering commands here
		glClear(GL_COLOR_BUFFER_BIT);

		MainCycle();

		// Swap the buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

int RandomInt100() {
	return (123*clock())%100;
}




