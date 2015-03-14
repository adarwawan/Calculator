#include "Expression.h"

Expression::Expression(const string& strExp , int modeExpression) {
  _stringToTokens(strExp);
  switch(modeExpression) {
    case 0 : // prefix
      break;
    case 1 : // infix
      _inToPrefix();
      break;
    case 2 : // postfix
      _postToPrefix();
  }
}
Expression::Expression(const Expression& E) {
  _stackToken = E._stackToken;
}
Expression::~Expression() {
}
void Expression::_stringToTokens(const string& _strEq) {
/* mengubah string menjadi stack of token */
  int pos = 0, len = 0, i = 0;
  bool op = false;
  while(i < _strEq.length()) {
    if(_strEq[i] == ' ' || _strEq[i] == '\t' || _strEq[i] == '\n') {
      if(op) {
        _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
        op = false;
      }
    }
     else {
      if(!op) {
        pos = i; len = 0;
        op = true;
      }
      len++;
    }
    i++;
  }
  if(op)
    _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
}
void Expression::_inToPrefix() {
/* mengubah ekspresi infix menjadi prefix */
  stack<Token *> pre, opr;
  while(!_stackToken.empty()) {
    Token * t = _stackToken.top();
    _stackToken.pop();
    if(t->GetIsOperator()) {
      if(!opr.empty())
      {
        if(t->GetPrior() < opr.top()->GetPrior())
          pre.push(t);
        else
          opr.push(t);
      }
      else
        opr.push(t);
      while(!opr.empty()) {
        if(t->GetPrior() < opr.top()->GetPrior()) {
          pre.push(opr.top());
          opr.pop();
        }
        else
          break;
      }
    }
    else
      pre.push(t);
  }
  _stackToken = pre;
}
void Expression::_postToPrefix() {
/* mengubah ekspresi postfix menjadi prefix */
  stack<Token *> pre;
  while(!_stackToken.empty()) {
    pre.push(_stackToken.top());
    _stackToken.pop();
  }
  _stackToken = pre;
}