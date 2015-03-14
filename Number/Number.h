#include <iostream>

#ifndef _Number_H_
#define _Number_H_

#include "Token.h"
#include <string>
using namespace std;

class Number: public Token{
public:
	Number(): Token(string("0")){
		//_isOperator = false;
	}
	Number(string s): Token(s){
		//_isOperator = false;
	}
	virtual Number& operator* (const Number&) = 0;
	virtual Number& operator+ (const Number&) = 0;
	virtual Number& operator- (const Number&) = 0;
	virtual Number& operator/ (const Number&) = 0;
	virtual Number& operator% (const Number&) = 0;
	virtual bool operator< (const Number&) = 0;
	virtual bool operator== (const Number&) = 0;
  virtual Number& operator= (Number& n) {
    _nilai = n._nilai;
    this->SetSymToken(n.GetSymToken());
  }
	virtual int toInt(string) = 0;
	int getNilai(){
		return _nilai;
	}
	void setNilai(int _n){
		_nilai = _n;
	}
	virtual ~Number(){
	}
//protected:
	int _nilai;
};

#endif