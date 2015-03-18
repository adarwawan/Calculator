#include "Logic.h"
#include <iostream>

using namespace std;

int main() {
  Logic L1("FALSE");
  Logic L2(0);

  L1 = L1 & L2; cout << L1.GetLogic() << endl;
  L1 = L1 | L2; cout << L1.GetLogic() << endl;
  L1 = L1 ^ L2; cout << L1.GetLogic() << endl;

  return 0;
}