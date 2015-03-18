#include "EquationException.h"

int EquationException::_num_ex = 0;

const int EquationException::OutOfBoundRomawi     = 0; // nilai romawi diluar batas [1..3999]
const int EquationException::DivideByZero         = 1; // pembagian dengan nol
const int EquationException::ModuloByNonPositif   = 2; // Modulo dengan bilangan yang tak positif
const int EquationException::UndefinedOperator    = 3; // operator yang tidak diperbolehkan
const int EquationException::IllegalUsingOperator = 4; // penggunaan operator yang tidak sesuai
const int EquationException::EmptyEquation        = 5; // Jika mencoba menyelesaikan Equation kosong


string EquationException::_message[] = {string("Angka Romawi hanya diperbolehkan pada batas nilai[1..3999]"),
                                        string("Tidak diijinkan pembagian dengan nol"),
                                        string("Tidak diijinkan operasi modulo oleh bilangan non positif"),
                                        string("Operator yang digunakan tidak terdefinisi"),
                                        string("Penggunaan operator tidak sesuai"),
                                        string("Equation kosong, tidak ada yang diselesaikan")
                                       };
//ctor
EquationException::EquationException(int id): _msg_id(id) {
  _num_ex++;
}

EquationException::EquationException(const EquationException& s):_msg_id(s._msg_id) {
}

EquationException::~EquationException() {
}
  
EquationException& EquationException::operator=(const EquationException&) {
  return *this;
}

int EquationException::getNumOfException() {
  return _num_ex;
}

const int EquationException::getID() {
  return _msg_id;
}

//method getMessage
string EquationException::getMessage() {
  return _message[_msg_id];
}
