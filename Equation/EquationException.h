#ifndef __EQUATION_EXCEPTION_H_
#define __EQUATION_EXCEPTION_H_

#include <string>

using namespace std;

class EquationException {
public:
  const static int OutOfBoundRomawi; // nilai romawi diluar batas [1..3000]
  const static int DivideByZero; // pembagian dengan nol
  const static int ModuloByNonPositif; // Modulo dengan bilangan yang tak positif
  const static int UndefinedOperator; // operator yang tidak diperbolehkan
  const static int IllegalUsingOperator; // penggunaan operator yang tidak sesuai
  const static int EmptyEquation; // Jika mencoba menyelesaikan Equation kosong
  
  //ctor
  EquationException(int);
  EquationException(const EquationException&);
  
  //method
  static int getNumOfException();
  const int getID();
  string getMessage();
  
private:
  static int _num_ex;
  static string _message[];
  const int _msg_id;
};

#endif