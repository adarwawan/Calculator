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
}

Reader::~Reader() {
  _sentence.clear();
}

void Reader::Read() {
  getline(cin, _sentence);
  _UpdateIsEquation();
}

void Reader::_UpdateIsEquation() {
  stringstream ss(_sentence);
  string firstWord;
  ss >> firstWord;
  for(int i = 0; i < )
}

int main() {
  return 0;
}