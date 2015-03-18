/**
* @file Number.h
**/
#include <iostream>

#ifndef _Number_H_
#define _Number_H_

#include "Token.h"
#include "Logic.h"
#include <string>
using namespace std;
/**
* @class Number
* @author Muhammad Aodyra Khaidir (13513063)
* @version 1.0
* 
* @section Description
* @brief Kelas Number bertugas untuk mengelola operasi bilangan.
**/
class Number: public Token{
public:
  /**
  * @brief Konstruktor kelas Number.
  *
  **/
	Number();
  /**
  * @brief Konstruktor kelas Number dengan parameter.
  * @param s - String yang akan menjadi parameter Token.
  **/
	Number(string s);
  /**
  * @brief Destruktor kelas Number.
  **/
	virtual ~Number();
  /**
  * @brief operator= untuk menyamakan nilai dari Number n.
  * @param n - Number yang nilainya akan disamakan.
  * @return n' - Objek Number yang telah diassign dari n.
  **/	
  virtual Number& operator= (Number& n);
  /**
  * @brief operator* untuk mengali nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikali.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	virtual Number& operator* (const Number&) = 0;
  /**
  * @brief operator+ untuk menambahkan nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan ditambah.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	virtual Number& operator+ (const Number&) = 0;
  /**
  * @brief operator- untuk mengurangi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikurang.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	virtual Number& operator- (const Number&) = 0;
  /**
  * @brief operator/ untuk membagi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dibagi.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	virtual Number& operator/ (const Number&) = 0;
  /**
  * @brief operator% untuk modulo nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya menjadi modulator.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
	virtual Number& operator% (const Number&) = 0;
  /**
  * @brief fungsi yang merubah string menjadi integer
  * @param s - string yang nantinya akan dirubah menjadi integer.
  * @return i - integer dari string n.
  **/  
	virtual int toInt(string) = 0;
  /**
  * @brief fungsi yang merubah integer menjadi string
  * @param n - nilai yang nantinya akan dirubah menjadi string.
  * @return s - string dari integer n.
  **/
  virtual string toString(int) = 0;

  /**
  * @brief prosedur membandingkan nilai lebih kecil dengan nilai N
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 < L2.
  **/  
	Logic& operator< (const Number&);
  /**
  * @brief prosedur membandingkan nilai lebih kecil sama dengan nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 <= L2.
  **/  
	Logic& operator<= (const Number&);
  /**
  * @brief prosedur membandingkan nilai lebih dari dengan nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 > L2.
  **/  
	Logic& operator> (const Number&);
  /**
  * @brief prosedur membandingkan nilai lebih dari sama dengan _nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 >= L2.
  **/  
	Logic& operator>= (const Number&);
  /**
  * @brief prosedur membandingkan _nilai sama dengan _nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 == L2.
  **/  
	Logic& operator== (const Number&);
  /**
  * @brief prosedur membandingkan _nilai tidak sama dengan _nilai dari N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 != L2.
  **/  
	Logic& operator!= (const Number&);
  /**
  * @brief prosedur mendapatkan _nilai.
  * @return i - integer dari _nilai
  **/  
	int getNilai();
  /**
  * @brief prosedur assign _nilai
  * @param n - nilai yang nantinya akan di assign ke _nilai.
  **/
	void setNilai(int _n);
  
//protected:
	int _nilai;
};

#endif