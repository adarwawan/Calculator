#include "Equation.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  
  int modeOperan;
  string str;
  cout << "Pilih jenis perhitungan yang akan dilakukan : " << endl;
  cout << "0  Bilangan Arab\n1  Bilangan Romawi\n2  Operasi logika\n\t-> ";
  cin >> modeOperan;
  int modeEquation, modeNumber;
  switch(modeOperan) {
    case 0 :
      modeEquation = Extension::NumberMode;
      modeNumber = Extension::ArabMode;
      break;
    case 1 : 
      modeEquation = Extension::NumberMode;
      modeNumber = Extension::RomawiMode;
      break;
    case 2 :
      modeEquation = Extension::LogicMode;
      break;
  }
  getline(cin, str);
  
  cout << "Masukan prefix :\n";
  getline(cin, str);
  Equation pre(str, Extension::Prefix, modeEquation, modeNumber);
  cout << "  hasil = " << pre.GetResult() << endl;
  
  cout << "Masukan infix :\n";
  getline(cin, str);
  Equation in(str, Extension::Infix, modeEquation, modeNumber);
  cout << "  hasil = " << in.GetResult() << endl;
  
  cout << "Masukan postfix :\n";
  getline(cin, str);
  Equation post(str, Extension::Postfix, modeEquation, modeNumber);
  cout << "  hasil = " << post.GetResult() << endl;
  
  return 0;
}