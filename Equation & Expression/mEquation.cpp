#include "Equation.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cout << "Masukan prefix :\n";
  getline(cin, str);
  Equation pre(str, 0);
  pre.SolveMathematical();
  cout << "  hasil = " << pre.GetResult() << endl;
  cout << "Masukan infix :\n";
  getline(cin, str);
  Equation in(str, 1);
  in.SolveMathematical();
  cout << "  hasil = " << in.GetResult() << endl;
  cout << "Masukan postfix :\n";
  getline(cin, str);
  Equation post(str, 2);
  post.SolveMathematical();
  cout << "  hasil = " << post.GetResult() << endl;
  return 0;
}