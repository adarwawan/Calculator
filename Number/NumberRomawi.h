#include "Number.h"

#ifndef _NumberRomawi_H_
#define _NumberRomawi_H_
using namespace std;

class NumberRomawi: public Number{
public:
	NumberRomawi();
	NumberRomawi(string s);
	Number operator* (const Number&);
	Number operator+ (const Number&);
	Number operator- (const Number&);
	Number operator/ (const Number&);
	Number operator% (const Number&);
	bool operator< (const Number&);
	bool operator== (const Number&);
	int toInt(string s);
	~NumberRomawi();
} 

#endif