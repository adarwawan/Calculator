#include "Reader.h"
#include <cstdio>

using namespace std;

int main() {
  Reader r;
  while(r.GetSentence() != "1") {
    r.Read();
    printf("Apakah dia Equation? %d\n", r.IsEquation());
  }
  return 0;
}
