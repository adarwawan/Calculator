#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <string>
#include "../Stack/stack.h"
#include "../Token/Token.h"
#include "../Number/NumberArab.h"
#include "../Number/NumberRomawi.h"
#include "../Logic/Logic.h"

#define _PREFIX_MODE 0
#define _INFIX_MODE 1
#define _POSTFIX_MODE 2
#define _ARAB_MODE 0
#define _ROMAWI_MODE 1
#define _LOGIC_MODE 2


class Expression {
public:
  Expression(const string& strExp , int modeExpression, int modeNumber);
  Expression(const Expression&);
  virtual ~Expression();
private:
  void _stringToTokens(const string& , int);
  void _inToPrefix();
  void _postToPrefix();
protected:
  stack<Token *> _stackToken;
};

#endif