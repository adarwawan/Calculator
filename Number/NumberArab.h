#include "Number.h"

#ifndef _NumberArab_H_
#define _NumberArab_H_

class NumberArab: public Number{
public:
	NumberArab();
	NumberArab(string s);
	Number& operator* (const Number&);
	Number& operator+ (const Number&);
	Number& operator- (const Number&);
	Number& operator/ (const Number&);
	Number& operator% (const Number&);
	NumberArab& operator= (const NumberArab&);
	bool operator< (const Number&);
	bool operator== (const Number&);
	int toInt(string s);
	~NumberArab();
} 

#endif