#include "Object2D.h"

Object2D::Object2D(void){

}
Object2D::Object2D(Point2i position, Size2ui size) {
	this->position = position;
	this->size = size;
}

Object2D::Object2D(int x, int y, unsigned int width, unsigned int height) {
	this->position.x = x;
	this->position.y = y;
	this->size.width = width;
	this->size.height = height;
}

Object2D::~Object2D(void){

}
//  ������� x-���������� ������� ��'����
int Object2D::GetX(void)const {
	return position.x;
}

//  ������� y-���������� ������� ��'����
int Object2D::GetY(void)const {
	return position.y;
}

//  ������� ������� ��'����
Point2i Object2D::GetPos(void)const {
	return position;
}

//  ������� ������ ��'����
unsigned int Object2D::GetWidth(void)const {
	return size.width;
}

//  ������� ������ ��'����
unsigned int Object2D::GetHeight(void)const {
	return size.height;
}

//  ������� ����� ��'����
Size2ui Object2D::GetSize(void)const {
	return size;
}

void Object2D::SetX(int x) {
	position.x = x;
}

void Object2D::SetY(int y) {
	position.y = y;
}

void Object2D::SetPos(Point2i position) {
	this->position = position;
}

void Object2D::SetWidth(unsigned int width) {
	size.width = width;
}

//  ������� ������ ��'����
void Object2D::SetHeight(unsigned int height) {
	size.height = height;
}

//  ������� ����� ��'����
void Object2D::SetSize(Size2ui size) {
	this->size = size;
}
