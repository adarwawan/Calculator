#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <string>
#include "stack.h"
#include "Token.h"
#include "NumberArab.h"
#include "NumberRomawi.h"

class Expression {
public:
  Expression(const string& strExp , int modeExpression);
  Expression(const Expression&);
  virtual ~Expression();
private:
  void _stringToTokens(const string& );
  void _inToPrefix();
  void _postToPrefix();
protected:
  stack<Token *> _stackToken;
};

#endif