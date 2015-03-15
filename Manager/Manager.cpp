#include "Manager.h"

Manager::Manager() {
  _expressionMode = Extension::defaultExpressionMode;
  _equationMode = Extension::defaultEquationMode;
  _numberMode = Extension::defaultNumberMode;
  _reader = new Reader();
  _saver = new Saver();
  _logger = new Logger();
  
  printf("Type 'help' to show documentation.\n\n");
  string buffer;
  int id = 0, n;
  do {
    id++;
    printf("> ");
    buffer = _reader->Read();
    if(_reader->IsEquation()) {
      ExecuteExpression(buffer);
      _logger->AddEquation(Log(id, buffer));
    } else {
      ExecuteCommand(buffer);
      _logger->AddCommand(Log(id, buffer));
    }
  } while(buffer != "exit");
  printf("Bye bye\n");
}

Manager::Manager(const Manager& man) {
  this->_expressionMode = man._expressionMode;
  this->_equationMode = man._equationMode;
  this->_numberMode = man._numberMode;
  this->_reader = new Reader(*man._reader);
  this->_saver = new Saver(*man._saver);
  this->_logger = new Logger(*man._logger);
}

Manager& Manager::operator=(const Manager& man) {
  delete _reader;
  delete _saver;
  delete _logger;
  this->_expressionMode = man._expressionMode;
  this->_equationMode = man._equationMode;
  this->_numberMode = man._numberMode;
  this->_reader = new Reader(*man._reader);
  this->_saver = new Saver(*man._saver);
  this->_logger = new Logger(*man._logger);
  return *this;
}

Manager::~Manager() {
  delete _reader;
  delete _saver;
  delete _logger;
}

void Manager::ExecuteExpression(string buffer) {
  Equation solver(buffer, _expressionMode, _equationMode, _numberMode);
  if(_equationMode == Extension::NumberMode) {
    solver.SolveMathematical();
  } else if(_equationMode == Extension::LogicMode) {
    solver.SolveLogical();
  } else {
    assert(false);
  }
  printf("%s\n", solver.GetResult().c_str());
}

void Manager::ExecuteCommand(string buffer) {
  stringstream ss(buffer);
  string temp, word;
  int n;
  ss >> word;
  if(word == "save") {
    printf("Nama file : ");
    getline(cin, word);
    _saver->SetFileName(word);
    _saver->SetLogMemory(Logger(*_logger));
    _saver->ConvertToFile();
  } else if(word == "redo") {
    ss >> n;
    Redo(n);
  } else if(word == "undo") {
    ss >> n;
    Undo(n);
  } else if(word == "set") {
    ss >> word;
    if(word == "infiks") SetExpressionMode(Extension::Infix);
    else if(word == "prefiks") SetExpressionMode(Extension::Prefix);
    else if(word == "postfiks") SetExpressionMode(Extension::Postfix);
        
    else if(word == "bilangan") SetEquationMode(Extension::NumberMode); 
    else if(word == "logika") SetEquationMode(Extension::LogicMode); 
        
    else if(word == "romawi") SetNumberMode(Extension::RomawiMode);
    else if(word == "arab") SetNumberMode(Extension::ArabMode);
        
    else printf("Setting gagal.\n");
  } else if(word == "reset") {
    ResetSetting();
  } else if(word == "show") {
    ss >> temp >> word;
    n = atoi(word.c_str());
    if(word == "all") ShowMemAll();
    else if(n >= 0) ShowMem(n);
    else {
      printf("Pembacaan histori gagal.\n");
    }
  } else if(word == "help") {
    Help();
  } else if(word == "view") {
    ViewSetting();
  } else if(word == "exit") {
    assert(true);
  } else {
    printf("Command tidak ada\n");
  }
}

void Manager::Redo(int n) {
  int redo = _logger->RedoEquation(n);
  if(redo == 0) {
    printf("Redo tidak dapat dilakukan.\n");
  } else {
    printf("%d ekspresi berhasil di Redo.\n", redo);
  }
}

void Manager::Undo(int n) {
  int undo = _logger->UndoEquation(n);
  if(undo == 0) {
    printf("Undo tidak dapat dilakukan.\n");
  } else {
    printf("%d ekspresi berhasil di Undo.\n", undo);
  }
}

void Manager::SetExpressionMode(int expressionMode) {
  _expressionMode = expressionMode;
  printf("Set expression mode success.\n");
}

void Manager::SetEquationMode(int equationMode) {
  _equationMode = equationMode;
  printf("Set equation mode success.\n");
}

void Manager::SetNumberMode(int numberMode) {
  _numberMode = numberMode;
  printf("Set number mode success.\n");
}

void Manager::ResetSetting() {
  _expressionMode = Extension::defaultExpressionMode;
  _equationMode = Extension::defaultEquationMode;
  _numberMode = Extension::defaultNumberMode;
  printf("Reset setting to default success.\n");
}

void Manager::ShowMem(int n) {
  _logger->ShowMem(n);
}

void Manager::ShowMemAll() {
  _logger->ShowMemAll();
}

void Manager::Help() {
  // show what command we are offering here
  // list command yang ditawarkan ada di doc RencanaKelasImplementasi, udah gw update
  printf("\n");
  printf(" Berikut adalah command yang disediakan di program ini.\n\n");
  printf(" save          : Untuk menyimpan operasi yang pernah dilakukan dalam file");
  printf("                 eksternal. File eksternal akan diminta selanjutnya\n\n");
  printf(" undo <n>      : Menghapus n buah ekspresi terakhir, <n> adalah bilangan cacah\n\n");
  printf(" redo <n>      : Mengulang n perintah terakhir\n\n");
  printf(" set           \n");
  printf("    prefiks    : Mengubah setting ekspresi menjadi prefiks\n");
  printf("    infiks     : Mengubah setting ekspresi menjadi infiks\n");
  printf("    postfiks   : Mengubah setting ekspresi menjadi postfiks\n");
  printf("    bilangan   : Mengubah setting equation menjadi bilangan\n");
  printf("    logika     : Mengubah setting equation menjadi logika\n");
  printf("    arab       : Mengubah setting bilangan menjadi bilangan arab\n");
  printf("    romawi     : Mengubah setting bilangan menjadi romawi\n\n");
  printf(" reset         : Mengembalikan setting ke mode default\n\n");
  
  printf(" Klik apapun KECUALI [Enter] untuk melanjutkan "); while(!kbhit());
  system("cls");
  printf("\n\n");
  
  printf(" show mem <n>  : Menampilkan ekspresi atau perintah terakhir sebanyak n"); printf("                 <n> adalah bilangan cacah\n\n");
  printf(" show mem all  : Menampilkan seluruh ekspresi atau perintah yang");
  printf("                 pernah dilakukan\n\n");
  printf(" view          : Menampilkan mode setting saat ini\n\n");
  printf(" exit          : Keluar dari command\n\n");
  
  printf(" DEFAULT MODE  :\n");
  printf("           Expression mode   : infiks\n");
  printf("           Equation mode     : bilangan\n");
  printf("           Number mode       : arab\n\n");
  printf(" Setting berada dalam default mode ketika awal run program\n\n");
}

void Manager::ViewSetting() {
  // belum selesai
  printf("Setting expression : ");
  if(_expressionMode == Extension::Prefix) {
    printf("prefiks");
  } else if(_expressionMode == Extension::Infix) {
    printf("infiks");
  } else if(_expressionMode == Extension::Postfix) {
    printf("postfiks");
  } else {
    assert(false);
  }
  printf("\n");
  
  printf("Setting equation   : ");
  if(_equationMode == Extension::NumberMode) {
    printf("bilangan");
  } else if(_equationMode == Extension::LogicMode) {
    printf("logika");
  } else {
    assert(false);
  }
  printf("\n");
  
  printf("Setting number     : ");
  if(_numberMode == Extension::ArabMode) {
    printf("arab");
  } else if(_numberMode == Extension::RomawiMode) {
    printf("romawi");
  } else {
    assert(false);
  }
  printf("\n");
}

