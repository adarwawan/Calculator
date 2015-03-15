#ifndef Token_H
#define Token_H

#include <iostream>
using namespace std;

class Token {
public :
  Token(string S); /* Constructor of Token */
  Token(const Token& T); /* Copy Constructor of Token */
  Token& operator=(const Token& T); /* Assignment of Token */
  ~Token(); /* Destructor of Token */
  
  /* Getter and Setter */
  string GetSymToken() const;
  bool GetIsOperator();
  void SetSymToken(string S);
  int GetPrior();

private :
  bool _IdentifyToken();
  void _IdentifyPrior();
  string _symToken;
  bool _isOperator;
  int _prior;
};

#endif
