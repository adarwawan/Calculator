#include <iostream>

#ifndef _Number_H_
#define _Number_H_

#include "Token.h"
#include "Logic.h"
#include <string>
using namespace std;

class Number: public Token{
public:
	Number();
	Number(string s);
	virtual ~Number();
  virtual Number& operator= (Number& n);
  
	virtual Number& operator* (const Number&) = 0;
	virtual Number& operator+ (const Number&) = 0;
	virtual Number& operator- (const Number&) = 0;
	virtual Number& operator/ (const Number&) = 0;
	virtual Number& operator% (const Number&) = 0;
  
	virtual int toInt(string) = 0;
  virtual string toString(int) = 0;
  
	Logic& operator< (const Number&);
	Logic& operator<= (const Number&);
	Logic& operator> (const Number&);
	Logic& operator>= (const Number&);
	Logic& operator== (const Number&);
	Logic& operator!= (const Number&);
  
	int getNilai();
	void setNilai(int _n);
  
//protected:
	int _nilai;
};

#endif