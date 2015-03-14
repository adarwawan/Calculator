#include "NumberArab.h"

using namespace std;

NumberArab::NumberArab() {
	_nilai = 0;
}

NumberArab::NumberArab(string s): Number(s){
	_nilai = toInt(s);
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

bool NumberArab::operator< (const Number& N){
	return (_nilai < N._nilai);
}

bool NumberArab::operator== (const Number& N){
	return (_nilai == N._nilai);
}

int NumberArab::toInt(string s){
	int nilai = 0, i = 0;
  if(s[0] == '-')
    i++;
  for(; i<s.length(); i++)
    nilai = nilai*10 + s[i] - '0';
  if(s[0] == '-')
    nilai *= -1;
	return nilai;
}