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
	// ����� ������� �������� ����
	void Start() {
		t1 = clock();
	}

	// ������ true, ���� �� ���������� Start() ������� interval ���� � ����������
	// ������ false, ���� �� ���������� Start() �� �� ������� interval ���� � ����������
	bool TimePassed(long interval) {
		if(clock() - t1 >= interval) return true;
		else return false;
	}
};

