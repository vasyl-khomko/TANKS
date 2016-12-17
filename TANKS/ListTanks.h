#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "List.h"
#include "Tank.h"

using namespace std;
class ListTanks {
private:
	int numTanksMain;
	int numTanksEnemy;
	int numTanksEnemyMax;
	int indexNextTank;
	List<int> listIndexTanks;
	Tank* tanks;
public:
	ListTanks(void);
	ListTanks(string nameFile);
	~ListTanks(void);
	// ������� ������� ����� �������
	int NumTanksMain(void);
	// ������� ������� ����� ������
	int NumTanksEnemy(void);
	// ������� ������� ��� �����
	int NumTanksAll(void);
	// ���������� �������� delta ��� ����� � �������� ��������
	void SetDelta(int delta, int indexTank);
	// ���������� �������� alpha ��� ����� � �������� ��������
	void SetAlpha(int alpha, int indexTank);
	// ������� ��������� �� ����� � �������� �������
	Tank& operator [] (int i);
	// ������� ������� � ������� index
	void Remove(int index);
	// �������� �� ������ ��������� ����
	void AddNext(void);

	void FromFile(string nameFile);

};

