#include <iostream>
#include "Token.h"

using namespace std;

int main() {
  string Operator = "*";
  string Angka = "123";

  Token TO(Operator);
  Token TA(Angka);

  cout << TO.GetSymToken() << " " << TO.GetIsOperator() << endl;
  cout << TA.GetSymToken() << " " << TA.GetIsOperator() << endl;

  Token T1 = TO;
  T1.SetSymToken("13");
  cout << T1.GetSymToken() << " " << T1.GetIsOperator() << endl;

  return 0;
}
