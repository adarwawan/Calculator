/**
* @file NumberRomawi.h
**/
#include "Number.h"

#ifndef _NumberRomawi_H_
#define _NumberRomawi_H_

#include "Number.h"
#include <string>
using namespace std;
/**
* @class NumberRomawi
* @author Muhammad Aodyra Khaidir (13513063)
* @version 1.0
* 
* @section Description
* @brief Kelas Number bertugas untuk mengelola operasi bilangan romawi.
**/
class NumberRomawi: public Number{
public:
  /**
  * @brief Konstruktor kelas NumberRomawi.
  *
  **/
	NumberRomawi();
  /**
  * @brief Konstruktor kelas Number dengan parameter.
  * @param s - String yang akan menjadi parameter Number.
  **/
	NumberRomawi(string s);
  /**
  * @brief Konstruktor kelas Number dengan parameter.
  * @param _n - integer yang akan di assign ke _nilai
  **/
	NumberRomawi(int _n);
  /**
  * @brief operator* untuk mengali nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikali.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	Number& operator* (const Number&);
  /**
  * @brief operator+ untuk menambahkan nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan ditambah.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	Number& operator+ (const Number&);
  /**
  * @brief operator- untuk mengurangi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikurang.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	Number& operator- (const Number&);
  /**
  * @brief operator/ untuk membagi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dibagi.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	Number& operator/ (const Number&);
  /**
  * @brief operator% untuk modulo nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya menjadi modulator.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	Number& operator% (const Number&);
  /**
  * @brief fungsi yang merubah string menjadi integer
  * @param s - string yang nantinya akan dirubah menjadi integer.
  * @return i - integer dari string n.
  **/  
	int toInt(string s);
  /**
  * @brief fungsi yang merubah integer menjadi string
  * @param n - nilai yang nantinya akan dirubah menjadi string.
  * @return s - string dari integer n.
  **/
  string toString(int n);
  /**
  * @brief Destruktor kelas NumberRomawi.
  **/
	~NumberRomawi();
};

#endif