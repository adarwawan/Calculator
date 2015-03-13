#ifndef Token_H
#define Token_H

#include <iostream>
using namespace std;

class Token {
public :
  Token(string S); /* Constructor of Token */
  Token::Token(const Token& T); /* Copy Constructor of Token */
  Token& Token::operator=(const Token& T); /* Assignment of Token */
  ~Token(); /* Destructor of Token */
  
  /* Getter and Setter */
  string GetSymToken();
  bool GetIsOperator();
  void SetSymToken(string S);

private :
  bool _IdentifyToken();
  string _symToken;
  bool _isOperator;
};

#endif
