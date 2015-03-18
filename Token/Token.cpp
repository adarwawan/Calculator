/**
* @file Token.h
**/

#include <iostream>
#include "Token.h"

using namespace std;
  /**
  * @brief Konstruktor kelas Token dengan Parameter.
  * @param S - String yang menjadi anggota token.
  **/
Token::Token(string S) {
  _symToken = S;
  _isOperator = _IdentifyToken();
  _IdentifyPrior();
}
  /**
  * @brief Copy Konstruktor kelas Token.
  * @param T - Variabel Token masukan.
  * @return Ti - Variabel Token yang tercopy.
  **/
Token::Token(const Token& T) {
  this->_symToken = T._symToken;
  this->_isOperator = T._isOperator;
  this->_prior = T._prior;
}
  /**
  * @brief Assignment kelas Logic.
  * @param T - Variabel Token masukan.
  * @return Ti - Variabel Token yang terassign.
  **/
Token& Token::operator=(const Token& T) {
  this->_symToken = T._symToken;
  this->_isOperator = T._isOperator;
  this->_prior = T._prior;
  return *this; 
}
  /**
  * @brief Destruktor kelas Token.
  **/
Token::~Token() {
}

  
  /**
  * @brief Getter untuk mendapatkan nilai _symToken.
  * @return S - string nilai _symToken.
  **/
string Token::GetSymToken() const {
  return _symToken;
}
  /**
  * @brief Getter untuk mendapatkan nilai _isOperator.
  * @return bool - boolean nilai _isOperator.
  **/
bool Token::GetIsOperator() {
  return _isOperator;
}
/**
  * @brief Setter untuk mengubah nilai _symToken.
  * @brief [I.S] String S merupakan simbol token yang valid.
  * @brief [F.S] Simbol token akan terset dengan S.
  * @param S - nilai _symToken yang akan dimasukkan.
  **/
void Token::SetSymToken(string S) {
  _symToken = S;
  _isOperator = _IdentifyToken();
  _IdentifyPrior();
}

  /**
  * @brief Set nilai _isOperator berdasarkan _symToken.
  * @return bool - nilai _isOperator
  **/
bool Token::_IdentifyToken() {
  if ((_symToken[0] == '-') && (_symToken.length() > 1))
    return false;
  else
    return (_symToken[0] < '0' || _symToken[0] > '9') && (_symToken[0] < 'A' || _symToken[0] > 'Z') && (_symToken[0] < 'a' || _symToken[0] > 'z');
}
  /**
  * @brief Set nilai _prior berdasarkan _symToken (untuk operator).
  * @brief [I.S] Token memiliki simbol token yang valid.
  * @brief [F.S] Priority token akan terset berdasarkan simbol token.
  **/
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
    else if(_symToken == "=" || _symToken == "!=")
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
  /**
  * @brief Getter untuk mendapatkan nilai _prior.
  * @return i - integer nilai _prior.
  **/
int Token::GetPrior() {
  return _prior;
}
