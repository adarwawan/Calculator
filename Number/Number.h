#include <iostream>

#ifndef _Number_H_
#define _Number_H_

using namespace std;

class Number: public Token{
public:
	Number(){
		_isOperator = false;
	}
	virtual Number operator* (const Number&) = 0;
	virtual Number operator+ (const Number&) = 0;
	virtual Number operator- (const Number&) = 0;
	virtual Number operator/ (const Number&) = 0;
	virtual Number operator% (const Number&) = 0;
	virtual bool operator< (const Number&) = 0;
	virtual bool operator== (const Number&) = 0;
	virtual int toInt() = 0;
	int getNilai(){
		return _nilai;
	}
	void setNilai(int _n){
		_nilai = _n;
	}
	virtual ~Number();
protected:
	int _nilai;
}

#endif