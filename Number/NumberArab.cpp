#include "NumberArab.h"

using namespace std;

NumberArab::NumberArab(){
	_name = 0;
}

NumberArab::NumberArab(string s){
	_name = toInt(s);
}

Number& NumberArab::operator* (const Number& N){
	Point N1;
	N1._nilai(_nilai*N._nilai);
	return N1;
}

Number& NumberArab::operator+ (const Number& N){
	Point N1;
	N1._nilai(_nilai + N._nilai);
	return N1;
}

Number& NumberArab::operator- (const Number& N){
	Point N1;
	N1._nilai(_nilai - N._nilai);
	return N1;
}

Number& NumberArab::operator% (const Number&){
	Point N1;
	N1._nilai(_nilai % N._nilai);
	return N1;
}

Number& NumberArab::operator/ (const Number& N){
	Point N1;
	N1._nilai(_nilai / N._nilai);
	return N1;
}

Number& NumberArab::operator= (const Number&){
	Point N1;
	N1._nilai = N._nilai;
	return N1;
}

bool NumberArab::operator< (const Number& N){
	if(_nilai< N._nilai){
		return true;
	}
	else{
		return false;
	}
}

bool NumberArab::operator== (const Number&){
	if(_nilai== N._nilai){
		return true;
	}
	else{
		return false;
	}
}

int NumberArab::toInt(string s){
	int nilai  = stoi(s);
	return nilai;
}