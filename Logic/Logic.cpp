#include <iostream>
#include "Logic.h"

using namespace std;

/* Constructor */
Logic::Logic() : Token(toString(0)) {
  _logic = 0;
}

/* Constructor */
Logic::Logic(string s) : Token(s) {
  _logic = toInt(s);
}

/* Constructor */
Logic::Logic(int i) : Token(toString(i)) {
  _logic = i;
}

/* Copy Constructor */
Logic::Logic(const Logic& L) : Token(toString(L._logic)) {
  this->_logic = L._logic;
}

/* Assignment */
Logic& Logic::operator=(const Logic& L) {
  this->_logic = L._logic;
  this->SetSymToken(L.GetSymToken());
  return *this;
}

/* Destructor */
Logic::~Logic() {

}

/* Getter and Setter */
int Logic::GetLogic() {
  return _logic;
}

void Logic::SetLogic(int i) {
  _logic = i;
}

/* Method */
Logic Logic::operator~() {
  return *(new Logic(!_logic));
}

Logic Logic::operator&(const Logic& L) {
  return *(new Logic(_logic && L._logic));
}

Logic Logic::operator|(const Logic& L) {
  return *(new Logic(_logic || L._logic));
}

Logic Logic::operator^(const Logic& L) {
  return *(new Logic(!(_logic) != !(L._logic)));
}

int Logic::toInt(string s) {
  if(s == "False" || s == "0")
    return 0;
  return 1;
}

string Logic::toString(int n) {
  string ret;
  if(n)
    ret = string("True");
  else
    ret = string("False");
  return ret;
}