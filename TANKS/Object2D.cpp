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
//  Поветрає x-координату позиції об'єкта
int Object2D::GetX(void)const {
	return position.x;
}

//  Поветрає y-координату позиції об'єкта
int Object2D::GetY(void)const {
	return position.y;
}

//  Поветрає позицію об'єкта
Point2i Object2D::GetPos(void)const {
	return position;
}

//  Поветрає ширину об'єкта
unsigned int Object2D::GetWidth(void)const {
	return size.width;
}

//  Поветрає висоту об'єкта
unsigned int Object2D::GetHeight(void)const {
	return size.height;
}

//  Поветрає розмір об'єкта
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

//  Поветрає висоту об'єкта
void Object2D::SetHeight(unsigned int height) {
	size.height = height;
}

//  Поветрає розмір об'єкта
void Object2D::SetSize(Size2ui size) {
	this->size = size;
}
