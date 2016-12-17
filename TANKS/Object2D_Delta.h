#pragma once

#include "object2d.h"
#include <math.h>

class Object2D_Delta : public Object2D {
private:
	int delta;
	double alpha;
	int ToInt(double value);
public:
	Object2D_Delta(void);
	~Object2D_Delta(void);
	int GetDelta(void)const;
	double GetAlpha(void)const;
	void SetDelta(int delta);
	void SetAlpha(double alpha);
	void NewWay(void);
	void NextPos(void);
	void PrevPos(void);
};

