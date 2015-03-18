/**
* @file Equation.h
**/

#ifndef __EQUATION_H_
#define __EQUATION_H_

#include "Expression.h"
#include "EquationException.h"

/**
* @class Equation
* @author Wiwit Rifa'i (13513073)
* @version 1.0
* 
* @section Description
* @brief Kelas Equation bertanggung jawab dalam perhutingan hasil ekspresi matematika ataupun logika dalam bentuk prefix. Kelas Equation merupakan inheritent dari kelas Expression.
**/

class Equation : public Expression {
public:
  /**
  * @brief Konstruktor kelas Equation.
  **/
  Equation();
  /**
  * @brief Konstruktor kelas Equation dengan parameter.
  * @param int strEqin - String yang merepresentasikan ekspresi matematika atau logika yang akan dikelola.
  * @param int modeExpress - kode integer yang menentukan apakah ekspresi dalam string tersebut dalam bentuk prefix, infix, ataupun postfix.
  * @param int modeEquation - kode integer yang menentukan jenis operasi yang digunakan yaitu operais pada bilangan ataukah logika.
  * @param int modeNumber - kode integer yang menentukan jenis operan bilangan yang digunakan yaitu bilangan arab ataupun bilangan romawi.
  **/
  Equation(string strEqin, int modeExpress, int modeEquation, int modeNumber);
  /** 
  * @brief Copy Constructor kelas Equation
  **/
  Equation(const Equation&);
  /** 
  * @brief Destructor kelas Equation
  **/
  virtual ~Equation();
  /** 
  * @brief operator assignment kelas Equation
  **/
  Equation& operator=(const Equation&);
  /**
  * @brief Getter hasil perhitungan dari ekspresi
  * @return string _result - string yang merepresentasikan hasil dari perhitungan
  **/
  string GetResult();
  /**
  * @brief Menghitung hasil ekspresi matematika yang ada dalam stack<token * > _stackToken.
  **/
  void SolveMathematical();
  /**
  * @brief Menghitung hasil ekspresi logika yang ada dalam stack<token * > _stackToken.
  **/
  void SolveLogical();
  /**
  * @brief Menghitung operasi bilangan yaitu untuk operator (+), (-), (*), dan (/).
  * @param Number * opn1 - pointer pada operan bilangan pertama
  * @param Token * opr - pointer pada operator bilangan
  * @param Number * opn2 - pointer pada operan bilangan kedua
  * @return Number * ret - pointer pada bilangan hasil dari operasi
  **/
  Number * CalculateNumber(Number * opn1, Token * opr, Number * opn2);
  /**
  * @brief Menghitung operasi logika yaitu untuk operator (&), (|), dan (^).
  * @param Logic * opn1 - pointer pada operan logika pertama
  * @param Token * opr - pointer pada operator logika
  * @param Logic * opn2 - pointer pada operan logika kedua
  * @return Logic * ret - pointer pada hasil logika dari operasi
  **/
  Logic * CalculateLogic(Logic * opn1, Token * opr, Logic * opn2);
  /**
  * @brief Menghitung operasi relasional pada bilangan yaitu untuk operator (<), (<=), (>), (>=), (=) dan (!=).
  * @param Number * opn1 - pointer pada operan bilangan pertama
  * @param Token * opr - pointer pada operator relasional
  * @param Number * opn2 - pointer pada operan bilangan kedua
  * @return Logic * ret - pointer pada hasil logika dari operasi
  **/
  Logic * CalculateNumberToLogic(Number * opn1, Token * opr, Number * opn2);
  
private:
  string _strEq; // _strEq adalah string yang merepresentasikan ekspresi awal
  string _result; // _result adalah string yang merepresentasikan hasil dari ekpresi
  int _modeEquation; // _modeEquation adalah kode yang merepresentasikan mode operasi yang digunakan logika ataukah bilangan
  int _modeNumber; // _modeNumber adalah kode yang merepresentasikan mode operan bilangan yang digunakan yaitu bilangan arab atau romawi
};

#endif