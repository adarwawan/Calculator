/**
* @file Expression.h
**/

#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include "EquationException.h"
#include <string>
#include <cassert>
#include "../Stack/stack.h"
#include "../Token/Logic.h"
#include "../Token/Token.h"
#include "../Token/NumberArab.h"
#include "../Token/NumberRomawi.h"
#include "../Extension/Extension.h"

/**
* @class Expression
* @author Wiwit Rifa'i (13513073)
* @version 1.0
* 
* @section Description
* @brief Kelas Expression bertanggung jawab dalam mengolah ekspresi matematika atau logika seperti mengubah string menjadi ekspresi matematika dan mengubah bentuk infix atau postfix menjadi prefix agar bisa dihitung di class Equation.
**/
class Expression {
public:
  /**
  * @brief Konstruktor kelas Expression.
  **/
  Expression();
  /**
  * @brief Konstruktor kelas Expression dengan parameter.
  * @param string strExp - String yang merepresentasikan ekspresi matematika atau logika yang akan dikelola.
  * @param int modeExpression - kode integer yang menentukan apakah ekspresi dalam string tersebut dalam bentuk prefix, infix, ataupun postfix.
  * @param int modeEquation - kode integer yang menentukan jenis operasi yang digunakan yaitu operasi pada bilangan ataukah logika.
  * @param int modeNumber - kode integer yang menentukan jenis operan bilangan yang digunakan yaitu bilangan arab ataupun bilangan romawi.
  **/
  Expression(const string& strExp , int modeExpression, int modeEquation, int modeNumber);
  /**
  * @brief Copy Constructor kelas Expression.
  **/
  Expression(const Expression&);
  /**
  * @brief Destruktor kelas Expression.
  **/
  virtual ~Expression();
  /** 
  * @brief Operator assignment kelas Expression.
  **/
  Expression& operator=(const Expression&);
private:
  /** 
  * @brief Mengubah string ekspresi dan mengubahnya menjadi token-token yang disimpan dalam stack.
  * @param string strEq - string ekspresi yang akan diubah menjadi token-token yang addressnya disimpan dalam stack.
  * @param int modeEquation - kode integer yang menentukan jenis operasi yang digunakan yaitu operasi pada bilangan ataukah logika.
  * @param int modeNumber - kode integer yang menentukan jenis operan bilangan yang digunakan yaitu bilangan arab ataupun bilangan romawi.
  **/
  void _stringToTokens(const string& , int , int );
  /**
  * @brief Mengubah keterurutan token-token pada stack _stackToken dari ekspresi infix menjadi ekspresi prefix.
  **/
  void _inToPostfix();
  /**
  * @brief Mengubah keterurutan token-token pada stack _stackToken dari ekspresi postfix menjadi ekspresi prefix.
  **/
  void _postToPrefix();
protected:
  stack<Token *> _stackToken; // _stackToken menyimpan address dari token-token yang merepresentasikan suatu ekspresi matematika
};

#endif
