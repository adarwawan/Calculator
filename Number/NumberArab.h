#include "Number.h"

#ifndef _NumberArab_H_
#define _NumberArab_H_

#include "Number.h"
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
	~NumberArab();
};

#endif