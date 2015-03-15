#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <string>
#include <cassert>
#include "../Stack/stack.h"
#include "../Token/Token.h"
#include "../Number/NumberArab.h"
#include "../Number/NumberRomawi.h"
#include "../Extension/Extension.h"
#include "../Logic/Logic.h"

class Expression {
public:
  Expression();
  Expression(const string& strExp , int modeExpression, int modeEquation, int modeNumber);
  Expression(const Expression&);
  virtual ~Expression();
private:
  void _stringToTokens(const string& , int , int );
  void _inToPostfix();
  void _postToPrefix();
protected:
  stack<Token *> _stackToken;
};

#endif