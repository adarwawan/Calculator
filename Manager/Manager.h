#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "../Reader/Reader.h"
#include "../Equation/Equation.h"
#include "../Equation/Expression.h"
#include "../Saver/Saver.h"
#include "../Logger/Logger.h"
#include "../Extension/Extension.h"
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>

class Manager {
public:
  Manager();
  Manager(const Manager&);
  Manager& operator=(const Manager&);
  ~Manager();
  
  void ExecuteExpression(string);
  void ExecuteCommand(string);
  
  void Redo(int);
  void Undo(int);
  
  void SetExpressionMode(int);
  void SetEquationMode(int);
  void SetNumberMode(int);
  
  void ResetSetting();
  void ShowMem(int);
  void ShowMemAll();
  void Help();
  void ViewSetting();
  
private:
  int _expressionMode;
  int _equationMode;
  int _numberMode;
  Reader* _reader;
  Saver* _saver;
  Logger* _logger;
};

#endif