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
	// Повертає кількість танків гравців
	int NumTanksMain(void);
	// Повертає кількість танків ворогів
	int NumTanksEnemy(void);
	// Повертає кількість всіх танків
	int NumTanksAll(void);
	// Встановлює значення delta для танка з вказаним індексом
	void SetDelta(int delta, int indexTank);
	// Встановлює значення alpha для танка з вказаним індексом
	void SetAlpha(int alpha, int indexTank);
	// Повертає посилання на танка з вказаним номером
	Tank& operator [] (int i);
	// Видаляє елемент з позиції index
	void Remove(int index);
	// Добавляє до списку наступний танк
	void AddNext(void);

	void FromFile(string nameFile);

};

