#pragma once
#include <Windows.h>
#include <GL\GL.H>
#include <GL\GLU.H>
//#include <GL\GLAUX.H>
//#include <GL\glut.h>
#include <GLFW\glfw3native.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <fstream>
#include <SOIL.h>

#include "GeometryTypes.h"
#include "stb_image.h"
	
using namespace std;
class Texture {
private:
	unsigned int texture;
public:
	Texture(void) {

	}
	unsigned int& Get(void) {
		return texture;
	}

	~Texture(void) {

	}
	// Створює текстуру із графічного файлу
	// nameFile - ім'я файлу
	Texture FromFile(LPCWSTR nameFile) {
		int w;
		int h;
		int comp;
		char fileName[100];
		wcstombs(fileName, nameFile, 100);

		ifstream fin;
		fin.open(fileName);
		if (fin) {
			fprintf(stdout, "File already exists '%s'\n", fileName);
		} else {
			fprintf(stderr, "File not exists '%s'\n", fileName);
		}

		unsigned char* image = SOIL_load_image(fileName, &w, &h, 0, SOIL_LOAD_RGB);
		if (image == nullptr)
			throw(std::string("Failed to load texture"));

		int size = sizeof(image);

		for (int i = 0; i < h / 2; i++) {
			int* line = new int[w*3];
			memcpy(line, &image[i*w*3], w*3);
			memcpy(&image[i*w*3], &image[(h-1)*w*3-i*w*3], w*3);
			memcpy(&image[(h-1)*w*3 - i*w*3], line, w*3);
			delete line;
		}
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//glEnable(GL_DEPTH_TEST);
		//glEnable(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		//glGenerat
		SOIL_free_image_data(image);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);
		return *this;
	}

};

