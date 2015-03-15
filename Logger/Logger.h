#ifndef __LOGGER_H_
#define __LOGGER_H_

#include "Log.h"
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

// semua dalam vector commands dijamin valid (tidak ada operasi undo/redo)
// isi vector equations belum tentu valid karena bisa jadi hasil undo
class Logger {
public:
  Logger();
  Logger(vector<Log>, vector<Log>);
  Logger(vector<Log>, vector<Log>, int);
  Logger(const Logger&);
  Logger& operator=(const Logger&);
  ~Logger();
  
  // getter and setter
  Log GetCommand(int);
  Log GetEquation(int);
  int GetSizeCommands();
  int GetSizeEquations();
  
  void Clear();
  void ClearCommands();
  void ClearEquations();

  void AddCommand(Log);
  void AddEquation(Log);
  
  void UndoEquation(int);
  void RedoEquation(int);
  void ShowMem(int);
  void ShowMemAll();
  
private:
  vector<Log> _commands;      // ID command dan equation dijamin unique
  vector<Log> _equations;
  int _sizeEquations;         // menandakan banyak Log equation yang valid
                              // setelah operasi redo dan undo
};

#endif