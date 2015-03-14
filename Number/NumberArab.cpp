#include "NumberArab.h"

using namespace std;

NumberArab::NumberArab() {
	_name = 0;
}

NumberArab::NumberArab(string s): Number(s){
	_name = toInt(s);
}

NumberArab::NumberArab(int _n){
	_nilai = _n;
}

NumberArab::~NumberArab(){

}

Number& NumberArab::operator* (const Number& N){
	Number& N1 = *(new NumberArab(_nilai * N._nilai));
	return N1;
}

Number& NumberArab::operator+ (const Number& N){
	Number& N1 = *(new NumberArab(_nilai + N._nilai));
	return N1;
}

Number& NumberArab::operator- (const Number& N){
	Number& N1 = *(new NumberArab(_nilai - N._nilai));
	return N1;
}

Number& NumberArab::operator/ (const Number& N){
	Number& N1 = *(new NumberArab(_nilai / N._nilai));
	return N1;
}

Number& NumberArab::operator% (const Number& N){
	Number& N1 = *(new NumberArab(_nilai % N._nilai));
	return N1;
}

NumberArab& NumberArab::operator= (const NumberArab& N){
	_nilai = N._nilai;
	return *this;
}

bool NumberArab::operator< (const Number& N){
	if(_nilai < N._nilai){
		return true;
	}
	else{
		return false;
	}
}

bool NumberArab::operator== (const Number&){
	if(_nilai == N._nilai){
		return true;
	}
	else{
		return false;
	}
}

int NumberArab::toInt(string s){
	int nilai = stoi(s);
	return nilai;
}