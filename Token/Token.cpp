#include <iostream>
#include "Token.h"

using namespace std;

/* Constructor of Token */
Token::Token(string S) {
  _symToken = S;
  _isOperator = _IdentifyToken();
}

/* Copy Constructor of Token */
Token::Token(const Token& T) {
  this->_symToken = T._symToken;
  this->_isOperator = T._isOperator;
}

/* Assignment of Token */
Token& Token::operator=(const Token& T) {
  this->_symToken = T._symToken;
  this->_isOperator = T._isOperator;

  return *this; 
}

/* Destructor of Token */
Token::~Token() {

}

/* Getter and Setter */
string Token::GetSymToken() {
  return _symToken;
}

bool Token::GetIsOperator() {
  return _isOperator;
}

void Token::SetSymToken(string S) {
  _symToken = S;
  _isOperator = _IdentifyToken();
}

/* Other Method */
bool Token::_IdentifyToken() {
  for (int i = 0; i < 10; ++i)
  {
    if (_symToken[0] == '0' + i) {
      return false;
    }
  }
  return true;
}
