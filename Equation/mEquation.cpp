#include "Equation.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  
  int modeSelect;
  int modeEquation, modeNumber;
  string str;
  cout << "Pilih jenis angka yang akan digunakan : " << endl;
  cout << "0  Bilangan Arab\n1  Bilangan Romawi\n\t-> ";
  cin >> modeSelect;
  if(modeSelect)
    modeNumber = Extension::RomawiMode;
  else
    modeNumber = Extension::ArabMode;
  cout << "Pilih jenis perhitungan yang akan dilakukan : " << endl;
  cout << "0  Operasi Numerik\n1  Operasi Logika\n\t-> ";
  cin >> modeSelect;
  if(modeSelect)
    modeEquation = Extension::LogicMode;
  else
    modeNumber = Extension::NumberMode;
  getline(cin, str);
  
  cout << "Masukan prefix :\n";
  getline(cin, str);
  try {
    Equation pre(str, Extension::Prefix, modeEquation, modeNumber);
    cout << "  hasil = " << pre.GetResult() << endl;
  } catch (EquationException& e) {
    cout << e.getMessage() << endl;
  }
  cout << "Masukan infix :\n";
  getline(cin, str);
  try {
    Equation in(str, Extension::Infix, modeEquation, modeNumber);
    cout << "  hasil = " << in.GetResult() << endl;
  } catch (EquationException& e) {
    cout << e.getMessage() << endl;
  }
  cout << "Masukan postfix :\n";
  getline(cin, str);
  try {
    Equation post(str, Extension::Postfix, modeEquation, modeNumber);
    cout << "  hasil = " << post.GetResult() << endl;
  } catch (EquationException& e) {
    cout << e.getMessage() << endl;
  }
    cout << "\nBanyaknya exception = "  << EquationException::getNumOfException() << endl;
  
  return 0;
}