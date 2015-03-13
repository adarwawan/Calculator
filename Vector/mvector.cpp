#include <cstdio>
#include "vector.h"

using namespace std;

int main() {
  vector<int> a;
  for(int i = 0; i < 20; i++) {
    a.push_back(i);
  }
  vector<int> b = a;
  b[0] = 3;
  printf("B nol %d\n", b[0]);
  a = b;
  //sort(b.begin(), b.end());
  for(int i = 0; i < a.size(); i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("b size() %d\n", b.size());
  b.clear();
  printf("Apakah b kosong? %d\n", b.empty());
  return 0;
}
