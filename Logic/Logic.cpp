#include <iostream>
#include "Logic.h"

using namespace std;

/* Constructor */
Logic::Logic(int i) {
  _logic = i;
}

/* Copy Constructor */
Logic::Logic(const Logic& L) {
  this->_logic = L._logic;
}

/* Assignment */
Logic& Logic::operator=(const Logic& L) {
  this->_logic = L._logic;

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
Logic& Logic::operator~() {
  this->_logic = !(_logic);

  return *this;
}

Logic& Logic::operator&(const Logic& L) {
  this->_logic = _logic && L._logic;

  return *this;
}

Logic& Logic::operator|(const Logic& L) {
  this->_logic = _logic || L._logic;

  return *this;
}

Logic& Logic::operator^(const Logic& L) {
  this->_logic = !(_logic) != !(L._logic);

  return *this;
}
