/**
* @file EquationException.h
**/

#ifndef __EQUATION_EXCEPTION_H_
#define __EQUATION_EXCEPTION_H_

#include <string>
using namespace std;

/**
* @class EquationException
* @author Wiwit Rifa'i (13513073)
* @version 1.0
* 
* @section Description
* @brief kelas EquationException merupakan kelas mengurusi exception pada equation.
**/
class EquationException {
public:
  //ctor
  /**
  * @brief Konstruktor kelas EquationException.
  * @param int - menyatakan jenis error yang terjadi.
  **/
  EquationException(int);
  /**
  * @brief Copy Constructor kelas EquationException.
  * @param const EquationException& - reference objek yang akan di copy;
  **/
  EquationException(const EquationException&);
  /**
  * @brief Destruktor kelas EquationException.
  **/
  ~EquationException();
  /**
  * @brief Operator assignment kelas EquationException.
  * @param EquationException& - reference objek yang akan di-copy.
  **/
  EquationException& operator=(const EquationException&);
  /**
  * @brief konstanta yang menandakan nilai romawi diluar batas [1..3999]
  **/
  const static int OutOfBoundRomawi; 
  /**
  * @brief konstanta yang menandakan pembagian dengan nol.
  **/  
  const static int DivideByZero;
  /**
  * @brief konstanta yang menandakan modulo dengan bilangan yang tak positif.
  **/  
  const static int ModuloByNonPositif;
  /**
  * @brief konstanta yang menandakan operator yang tidak diperbolehkan.
  **/  
  const static int UndefinedOperator;
  /**
  * @brief konstanta yang menandakan penggunaan operator yang tidak sesuai.
  **/  
  const static int IllegalUsingOperator;
  /**
  * @brief konstanta yang menandakan program mencoba menyelesaikan Equation kosong.
  **/  
  const static int EmptyEquation;
  
  //method
  /**
  * @brief Getter banyaknya exception yang telah terjadi.
  **/  
  static int getNumOfException();
  /**
  * @brief Getter nilai ID kesalahan.
  **/  
  const int getID();
  /**
  * @brief Getter pesan kesalahan.
  **/
  string getMessage();
  
private:
  static int _num_ex;       // banyaknya exception yang telah terjadi.
  static string _message[]; // pesan kesalahan.
  const int _msg_id;        // ID pesan kesalahan.
};

#endif