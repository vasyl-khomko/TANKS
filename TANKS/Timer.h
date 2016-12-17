#pragma once
#include <time.h>
class Timer {
private:
	clock_t t1;
	clock_t t2;
public:

	Timer(void) {
		Start();
	}

	~Timer(void)
	{
	}
	// Зчитує поточне значення часу
	void Start() {
		t1 = clock();
	}

	// Поветає true, якщо від останнього Start() пройшов interval часу у мілісекундах
	// Поветає false, якщо від останнього Start() ще не пройшов interval часу у мілісекундах
	bool TimePassed(long interval) {
		if(clock() - t1 >= interval) return true;
		else return false;
	}
};

