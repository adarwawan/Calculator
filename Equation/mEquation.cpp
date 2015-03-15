#include "Equation.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  int modeOperan;
  string str;
  cout << "Pilih jenis perhitungan yang akan dilakukan : " << endl;
  cout << "0  Bilangan Arab\n1  Bilangan Romawi\n2 Operasi logika\n\t-> ";
  cin >> modeOperan;
  getline(cin, str);
  
  cout << "Masukan prefix :\n";
  getline(cin, str);
  Equation pre(str, 0, modeOperan);
  cout << "  hasil = " << pre.GetResult() << endl;
  
  cout << "Masukan infix :\n";
  getline(cin, str);
  Equation in(str, 1, modeOperan);
  cout << "  hasil = " << in.GetResult() << endl;
  
  cout << "Masukan postfix :\n";
  getline(cin, str);
  Equation post(str, 2, modeOperan);
  cout << "  hasil = " << post.GetResult() << endl;
  return 0;
}