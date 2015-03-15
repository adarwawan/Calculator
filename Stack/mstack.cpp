#include "stack.h"
#include <cstdio>

using namespace std;

int main() {
  stack<int> st;
  for(int i = 0; i < 10; i++) {
    st.push(i);
    printf("%d ", st.top());
  }
  printf("\n");
  while(!st.empty()) {
    printf("%d ", st.top());
  }
  printf("\n");
  return 0;
}