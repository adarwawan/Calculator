#include "Logger.h"

Logger::Logger() {
  _commands.clear();
  _equations.clear();
  _sizeEquations = 0;
}

Logger::Logger(vector<Log> commands, vector<Log> equations) {
  _commands = commands;
  _equations = equations;
  _sizeEquations = equations.size();
}

Logger::Logger(vector<Log> commands, vector<Log> equations, int sizeEquations) {
  _commands = commands;
  _equations = equations;
  _sizeEquations = sizeEquations;
}

Logger::Logger(const Logger& logger) {
  _commands = logger._commands;
  _equations = logger._equations;
  _sizeEquations = logger._sizeEquations;
}

Logger& Logger::operator=(const Logger& logger) {
  _commands = logger._commands;
  _equations = logger._equations;
  _sizeEquations = logger._sizeEquations;
  return *this;
}

Logger::~Logger() {
  _commands.clear();
  _equations.clear();
}

Log Logger::GetCommand(int i) {
  assert(0 <= i && i < _commands.size());
  return _commands[i];
}

Log Logger::GetEquation(int i) {
  assert(0 <= i && i < _sizeEquations);
  return _equations[i];
}

int Logger::GetSizeCommands() {
  return _commands.size();
}

int Logger::GetSizeEquations() {
  return _sizeEquations;
}

void Logger::Clear() {
  _commands.clear();
  _equations.clear();
  _sizeEquations = 0;
}

void Logger::ClearCommands() {
  _commands.clear();
}

void Logger::ClearEquations() {
  _equations.clear();
  _sizeEquations = 0;
}

void Logger::AddCommand(Log log) {
  _commands.push_back(log);
}

void Logger::AddEquation(Log log) {
  assert(_sizeEquations <= _equations.size());
  if(_sizeEquations == _equations.size()) {
    _equations.push_back(log);
  } else {
    _equations[_sizeEquations] = log;
  }
  _sizeEquations++;
}

int Logger::UndoEquation(int n) {
  int tobe = max(_sizeEquations - n, 0);
  _sizeEquations = tobe;
  return n - tobe;
}

int Logger::RedoEquation(int n) {
  int tobe = min(_sizeEquations + n, (int) _equations.size());
  _sizeEquations = tobe;
  return tobe - n;
}

void Logger::ShowMem(int n) {
  int ptEq = _sizeEquations - 1;
  int ptCom = (int) _commands.size() - 1;
  int index = 0;
  while(n > 0 && (ptEq >= 0 || ptCom >= 0)) {
    ++index;
    if(ptEq >= 0 && ptCom >= 0) {
      if(_equations[ptEq].GetID() > _commands[ptCom].GetID()) {
        printf("> Perintah terakhir (equation) %2d : %s\n", index,
          _equations[ptEq].GetSentence().c_str());
          ptEq--;
      } else {
        printf("> Perintah terakhir (command) %3d : %s\n", index,
          _commands[ptCom].GetSentence().c_str());
        ptCom--;
      }
    } else if(ptEq >= 0) {
      printf("> Perintah terakhir (equation) %2d : %s\n", index,
        _equations[ptEq].GetSentence().c_str());
      ptEq--;
    } else {
      assert(ptCom >= 0);
      printf("> Perintah terakhir (command) %3d : %s\n", index,
        _commands[ptCom].GetSentence().c_str());
      ptCom--;
    }
    n--;
  }
}

void Logger::ShowMemAll() {
  int ptEq = _sizeEquations - 1;
  int ptCom = (int) _commands.size() - 1;
  int index = 0;
  while(ptEq >= 0 || ptCom >= 0) {
    ++index;
    if(ptEq >= 0 && ptCom >= 0) {
      if(_equations[ptEq].GetID() > _commands[ptCom].GetID()) {
        printf("> Perintah terakhir (equation) %2d : %s\n", index,
          _equations[ptEq].GetSentence().c_str());
        ptEq--;
      } else {
        printf("> Perintah terakhir (command) %3d : %s\n", index,
          _commands[ptCom].GetSentence().c_str());
        ptCom--;
      }
    } else if(ptEq >= 0) {
      printf("> Perintah terakhir (equation) %2d : %s\n", index,
        _equations[ptEq].GetSentence().c_str());
      ptEq--;
    } else {
      assert(ptCom >= 0);
      printf("> Perintah terakhir (command) %3d : %s\n", index,
        _commands[ptCom].GetSentence().c_str());
      ptCom--;
    }
  }
}

