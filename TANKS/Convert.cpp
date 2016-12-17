#include "Convert.h"


Convert::Convert(void)
{
}


Convert::~Convert(void)
{
}
string GhyloToSym(int a){
	if(a == 0)return "0";
	if(a == 1)return "1";
	if(a == 2)return "2";
	if(a == 3)return "3";
	if(a == 4)return "4";
	if(a == 5)return "5";
	if(a == 6)return "6";
	if(a == 7)return "7";
	if(a == 8)return "8";
	if(a == 9)return "9";
	return "_";
}

string Convert::IntToString(int value) {
	string st;
	string st2;
	int rem;
	while(value != 0 ) {
		rem = value%10;
		value = value/10;
		st +=  GhyloToSym(rem);
	}
	for(int i = st.size()-1; i >= 0; i--) {
		st2 += st[i];
	}
	return st2;
}

