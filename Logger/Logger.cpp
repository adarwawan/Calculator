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

Logger::~Logger() {
  _commands.clear();
  _equations.clear();
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

void Logger::UndoEquation(int n) {
  _sizeEquations = max(_sizeEquations - n, 0);
}

void Logger::RedoEquation(int n) {
  _sizeEquations = min(_sizeEquations + n, (int) _equations.size());
}

void Logger::ShowMem(int n) {
  int ptEq = _sizeEquations - 1;
  int ptCom = (int) _commands.size() - 1;
  int index = 0;
  while(n > 0 && (ptEq >= 0 || ptCom >= 0)) {
    ++index;
    if(ptEq >= 0 && ptCom >= 0) {
      if(_equations[ptEq].GetID() > _commands[ptCom].GetID()) {
        printf("> Perintah terakhir %4d : %s\n", index,
          _equations[ptEq].GetSentence().c_str());
      } else {
        printf("> Perintah terakhir %4d : %s\n", index,
          _commands[ptCom].GetSentence().c_str());
      }
    } else if(ptEq >= 0) {
      printf("> Perintah terakhir %4d : %s\n", index,
        _equations[ptEq].GetSentence().c_str());
    } else {
      assert(ptCom >= 0);
      printf("> Perintah terakhir %4d : %s\n", index,
        _commands[ptCom].GetSentence().c_str());
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
        printf("> Perintah terakhir %4d : %s\n", index,
          _equations[ptEq].GetSentence().c_str());
      } else {
        printf("> Perintah terakhir %4d : %s\n", index,
          _commands[ptCom].GetSentence().c_str());
      }
    } else if(ptEq >= 0) {
      printf("> Perintah terakhir %4d : %s\n", index,
        _equations[ptEq].GetSentence().c_str());
    } else {
      assert(ptCom >= 0);
      printf("> Perintah terakhir %4d : %s\n", index,
        _commands[ptCom].GetSentence().c_str());
    }
  }
}

int main() {
  return 0;
}

