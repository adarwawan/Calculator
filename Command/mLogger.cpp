#include "Log.h"
#include "Logger.h"
#include <iostream>

using namespace std;

int main() {
  Logger logger;
  for(int i = 0; i < 10; i++) {
    string str;
    cin >> str;
    if(i % 2) logger.AddCommand(Log(i + 1, str));
    else logger.AddEquation(Log(i + 1, str));
  }
  logger.ShowMemAll();
  int n;
  printf("Masukkan angka : "); cin >> n;
  logger.ShowMem(n);
  
  logger.UndoEquation(4);
  printf("Abis Undo 4 : \n");
  logger.ShowMemAll();
  
  printf("Masukkan redo : "); cin >> n;
  logger.RedoEquation(n);
  logger.ShowMemAll();
  
  return 0;
}