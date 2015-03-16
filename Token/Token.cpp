#include <iostream>
#include "Token.h"

using namespace std;

/* Constructor of Token */
Token::Token(string S) {
  _symToken = S;
  _isOperator = _IdentifyToken();
  _IdentifyPrior();
}

/* Copy Constructor of Token */
Token::Token(const Token& T) {
  this->_symToken = T._symToken;
  this->_isOperator = T._isOperator;
  this->_prior = T._prior;
}

/* Assignment of Token */
Token& Token::operator=(const Token& T) {
  this->_symToken = T._symToken;
  this->_isOperator = T._isOperator;
  this->_prior = T._prior;
  return *this; 
}

/* Destructor of Token */
Token::~Token() {
}

/* Getter and Setter */
string Token::GetSymToken() const {
  return _symToken;
}

bool Token::GetIsOperator() {
  return _isOperator;
}

void Token::SetSymToken(string S) {
  _symToken = S;
  _isOperator = _IdentifyToken();
  _IdentifyPrior();
}

/* Other Method */
bool Token::_IdentifyToken() {
  if ((_symToken[0] == '-') && (_symToken.length() > 1))
    return false;
  else
    return (_symToken[0] < '0' || _symToken[0] > '9') && (_symToken[0] < 'A' || _symToken[0] > 'Z') && (_symToken[0] < 'a' || _symToken[0] > 'z');
}
void Token::_IdentifyPrior() {
  if(_isOperator) {
    /* Prioritas operator relatif berdasarkan http://en.wikipedia.org/wiki/Order_of_operations */
    /* operator number to number */
    if(_symToken == "*" || _symToken == "/" || _symToken == "%")
      _prior = 10;
    else if(_symToken == "+" || _symToken == "-")
      _prior = 9;
    /* operator number to logic */
    else if(_symToken == "<" || _symToken == "<=" || _symToken == ">" || _symToken == ">=")
      _prior = 8;
    else if(_symToken == "==" || _symToken == "!=")
      _prior = 7;
    /* operator logic to logic */
    else if(_symToken == "~")
      _prior = 6;
    else if(_symToken == "&")
      _prior = 5;
    else if(_symToken == "^")
      _prior = 4;
    else if(_symToken == "|")
      _prior = 3;
    else
      _prior = 2;
  }
  else
    if(_symToken == "TRUE" || _symToken == "FALSE" || _symToken == "true" || _symToken == "false") // a logic
      _prior = 0;
    else // a number
      _prior = 1;
}
int Token::GetPrior() {
  return _prior;
}
