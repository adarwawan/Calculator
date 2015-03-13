#include "Reader.h"

const string Reader::_commands[] = {"Save",
                                    "Redo",
                                    "Undo",
                                    "Set",
                                    "Reset",
                                    "Show",
                                    "View",
                                    "Help"};

Reader::Reader() {
  _sentence = "Cinta memang buta, tapi hatiku yang lihat";
  _isEquation = false;
}

Reader::Reader(const Reader& r) {
  _sentence = r._sentence;
  _isEquation = r._isEquation;
}

Reader& Reader::operator=(const Reader& r) {
  _sentence = r._sentence;
  _isEquation = r._isEquation;
  return *this;
}

Reader::~Reader() {
  _sentence.clear();
}

void Reader::Read() {
  getline(cin, _sentence);
  _UpdateIsEquation();
}

string Reader::GetSentence() {
  return _sentence;
}

bool Reader::IsEquation() {
  return _isEquation;
}

void Reader::_UpdateIsEquation() {
  stringstream ss(_sentence);
  string firstWord;
  ss >> firstWord;
  int size = sizeof(_commands) / sizeof(*_commands);
  for(int i = 0; i < size; i++) {
    if(firstWord == _commands[i]) {
      _isEquation = false;
      return;
    }
  }
  _isEquation = true;
}
