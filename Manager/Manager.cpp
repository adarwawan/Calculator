#include "Manager.h"

Manager::Manager() {
  _expressionMode = Extension::defaultExpressionMode;
  _equationMode = Extension::defaultEquationMode;
  _numberMode = Extension::defaultNumberMode;
  
  string buffer;
  int id = 0;
  do {
    id++;
    printf("> ");
    buffer = _reader.Read();
    if(_reader.IsEquation()) {
      Equation solver(buffer, _expressionMode);
      if(_equationMode == Extension::NumberMode) {
        solver.SolveMathematical();
      } else if(_equationMode == Extension::LogicMode) {
        solver.SolveLogical();
      } else {
        assert(false);
      }
      printf("%d\n", solver.GetResult());
      _logger.AddEquation(Log(id, buffer));
    } else {
      // do command here                          <-- DIR KERJAIN INI ea,
      // jangan lupa command kita lower case semua. ex : show mem all
      _logger.AddCommand(Log(id, buffer));
    }
  } while(buffer != "exit");
  printf("Bye bye");
}

Manager::Manager(const Manager& man) {
  this->_expressionMode = man._expressionMode;
  this->_equationMode = man._equationMode;
  this->_numberMode = man._numberMode;
  this->_reader = man._reader;
  this->_saver = man._saver;
  this->_logger = man._logger;
}

Manager& Manager::operator=(const Manager& man) {
  this->_expressionMode = man._expressionMode;
  this->_equationMode = man._equationMode;
  this->_numberMode = man._numberMode;
  this->_reader = man._reader;
  this->_saver = man._saver;
  this->_logger = man._logger;
  return *this;
}

Manager::~Manager() {

}

void Manager::Redo(int n) {
  _logger.RedoEquation(n);
}

void Manager::Undo(int n) {
  _logger.UndoEquation(n);
}

void Manager::SetExpressionMode(int expressionMode) {
  _expressionMode = expressionMode;
  printf("Set expression mode success.\n\n");
}

void Manager::SetEquationMode(int equationMode) {
  _equationMode = equationMode;
  printf("Set equation mode success.\n\n");
}

void Manager::SetNumberMode(int numberMode) {
  _numberMode = numberMode;
  printf("Set number mode success.\n\n");
}

void Manager::ResetSetting() {
  _expressionMode = Extension::defaultExpressionMode;
  _equationMode = Extension::defaultEquationMode;
  _numberMode = Extension::defaultNumberMode;
  printf("Reset setting to default success.\n\n");
}

void Manager::ShowMem(int n) {
  _logger.ShowMem(n);
}

void Manager::ShowMemAll() {
  _logger.ShowMemAll();
}

void Manager::Help() {
  // show what command we are offering here
  // list command yang ditawarkan ada di doc RencanaKelasImplementasi, udah gw update
}

void Manager::ViewSetting() {
  // belum selesai
  printf("Setting expression : \n");
  printf("Setting equation   : \n");
  printf("Setting number     : \n");
}

