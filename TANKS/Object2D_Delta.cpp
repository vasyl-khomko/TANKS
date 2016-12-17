#include "Object2D_Delta.h"

int Object2D_Delta::ToInt(double value) {
	double delta = 0.2;
	if((int(value + delta))/value > 0.8 && (int(value + delta))/value < 1.2) {
		//cout<<" ### int(value + delta)"<<endl;
		return int(value + delta);
	}
	
	if((int(value - delta))/value > 0.8 && (int(value - delta))/value < 1.2) {
		//cout<<" ### int(value - delta)"<<endl;
		return int(value - delta);
	}
	//cout<<" ### int(value)"<<endl;
	return int(value);
}

Object2D_Delta::Object2D_Delta(void) {

}

Object2D_Delta::~Object2D_Delta(void) {

}

int Object2D_Delta::GetDelta(void)const {
	return delta;
}

double Object2D_Delta::GetAlpha(void)const {
	return alpha;
}

void Object2D_Delta::SetDelta(int delta) {
	this->delta = delta;
}

void Object2D_Delta::SetAlpha(double alpha) {
	this->alpha = alpha;
}

void Object2D_Delta::NewWay(void) {
	alpha = ((int)alpha + 90) % 360;
}


void Object2D_Delta::NextPos(void) {
	SetX(GetX() - (delta*ToInt(sin(PI*alpha/180))));
	SetY(GetY() + (delta*ToInt(cos(PI*alpha/180))));
}

void Object2D_Delta::PrevPos(void) {
	SetX(GetX() + (delta*ToInt(sin(PI*alpha/180))));
	SetY(GetY() - (delta*ToInt(cos(PI*alpha/180))));
}
