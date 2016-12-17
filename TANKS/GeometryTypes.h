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

// ��������� ��� ��������� ������ ���� unsigned int
struct Size2ui {
	// ������
	unsigned int width;
	// ������
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

// ��������� ��� ��������� ������ ���� int
struct Size2i {
	// ������
	int width;
	// ������
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