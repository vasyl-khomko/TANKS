#pragma once
#define PI 3.14
namespace Geometry {
struct Point2i {
	int x;
	int y;
	Point2i() {
		x = 0;
		y = 0;
	}
	Point2i(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

struct Point2d {
	double x;
	double y;
	Point2d() {
		x = 0;
		y = 0;
	}
	Point2d(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

// Структура для зберігання розміру типу unsigned int
struct Size2ui {
	// Ширина
	unsigned int width;
	// Висота
	unsigned int height;
	Size2ui() {
		width = 0;
		height = 0;
	}
	Size2ui(unsigned int width, unsigned int height) {
		this->width = width;
		this->height = height;
	}
};

// Структура для зберігання розміру типу int
struct Size2i {
	// Ширина
	int width;
	// Висота
	int height;
	Size2i() {
		width = 0;
		height = 0;
	}
	Size2i(int width, int height) {
		this->width = width;
		this->height = height;
	}
};
}