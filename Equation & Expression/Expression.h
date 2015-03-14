#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <string>
#include "../Stack/stack.h"
#include "../Token/Token.h"
#include "../Number/NumberArab.h"
#include "../Number/NumberRomawi.h"

class Expression {
public:
  Expression(const string& strExp , int modeExpression);
  Expression(const Expression&);
  virtual ~Expression();
private:
  void _stringToTokens(const string& );
  void _inToPostfix();
  void _postToPrefix();
protected:
  stack<Token *> _stackToken;
};

#endif