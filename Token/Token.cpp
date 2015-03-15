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
    return (_symToken[0] < '0' || _symToken[0] > '9') && (_symToken[0] < 'A' || _symToken[0] > 'Z');
}
void Token::_IdentifyPrior() {
  if(_isOperator) {
    switch(_symToken[0]) {
      /* operator number */
      case '*':
        _prior = 6; break;
      case '/':
        _prior = 5; break;
      case '+':
        _prior = 4; break;
      case '-':
        _prior = 3; break;
      case '%':
        _prior = 2; break;
      default :
        _prior = 1;
    }
  }
  else
    _prior = 0;
}
int Token::GetPrior() {
  return _prior;
}
