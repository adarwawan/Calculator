#ifndef _NumberArab_H_
#define _NumberArab_H_

#include "Number.h"
#include "../Stack/stack.h"
#include <string>
using namespace std;

class NumberArab: public Number{
public:
	NumberArab();
	NumberArab(string s);
	NumberArab(int _n);
	Number& operator* (const Number&);
	Number& operator+ (const Number&);
	Number& operator- (const Number&);
	Number& operator/ (const Number&);
	Number& operator% (const Number&);
	bool operator< (const Number&);
	bool operator== (const Number&);
	int toInt(string s);
  string toString(int n);
	~NumberArab();
};

#endif