#include "ListTanks.h"


ListTanks::ListTanks(void) {
	numTanksMain  = 2;
	numTanksEnemy = 0;
	numTanksEnemyMax = 20;
	indexNextTank = numTanksMain;
	listIndexTanks.InsertBack(0);
	listIndexTanks.InsertBack(1);

}

ListTanks::ListTanks(string nameFile) {
	numTanksMain  = 2;
	numTanksEnemy = 1;
	numTanksEnemyMax = 20;
	indexNextTank = numTanksMain + numTanksEnemy;
	listIndexTanks.InsertBack(0);
	listIndexTanks.InsertBack(1);
	listIndexTanks.InsertBack(2);

	FromFile(nameFile);
}

ListTanks::~ListTanks(void) {

}

int ListTanks::NumTanksMain(void) {
	return numTanksMain;
}


int ListTanks::NumTanksEnemy(void) {
	return numTanksEnemy;
}

int ListTanks::NumTanksAll(void) {
	return numTanksMain + numTanksEnemy;
}

void ListTanks::SetDelta(int delta, int indexTank) {
	tanks[indexTank].SetDelta(delta);
}


void ListTanks::SetAlpha(int alpha, int indexTank) {
	tanks[indexTank].SetAlpha(alpha);
}


Tank& ListTanks::operator [] (int i) {	
	return tanks[listIndexTanks.Data(i)];
}

void ListTanks::Remove(int index) {
	cout<<" listIndexTanks.Size() = "<<listIndexTanks.Size()<<endl;
	for (int i = 0; i < listIndexTanks.Size(); i++) {
		cout<<listIndexTanks.Data(i)<<" ";
	}
	listIndexTanks.DeleteIndex(index);
	cout<<" listIndexTanks.Size() = "<<listIndexTanks.Size()<<endl;
	for (int i = 0; i < listIndexTanks.Size(); i++) {
		cout<<listIndexTanks.Data(i)<<" ";
	}
	if(index == 0)	numTanksMain--;
	if(index == 1) {
		if(numTanksMain == 2)	numTanksMain--;
		else					numTanksEnemy--;
	}
	if(index > 1)	numTanksEnemy--;
}


void ListTanks::AddNext(void) {
	cout<<" ListTanks::AddNext(void) "<<endl;
	if(indexNextTank < numTanksEnemyMax) {
		listIndexTanks.InsertBack(indexNextTank);
		numTanksEnemy++;
		indexNextTank++;
	}
	cout<<" numTanksEnemy = "<<numTanksEnemy<<endl;
	cout<<" END ListTanks::AddNext(void) "<<endl;
}

void ListTanks::FromFile(string nameFile) {
	cout<<" ListTanks::FromFile(string nameFile) "<<endl;
	tanks = new Tank[22]();
	fstream file(nameFile);
	if(!file) {
		cout<<" Eror: Imput file \""<<nameFile<<"\""<<endl;
		return;
	}
	tanks[0].Init(16*8, 8*1, 1);
	tanks[1].Init(24*8, 8*1, 2);
	for (int i = numTanksMain; i < numTanksEnemyMax + 2; i++) {
		int forms;
		file>>forms;
		if(i%3 == 0) 	tanks[i].Init( 1*8, 39*8,forms);
		if(i%3 == 1)	tanks[i].Init(20*8, 39*8,forms);
		if(i%3 == 2)	tanks[i].Init(39*8, 39*8,forms);
	}
	cout<<" END ListTanks::FromFile(string nameFile) "<<endl;
}


