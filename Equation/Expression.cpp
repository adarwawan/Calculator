#include "Expression.h"

Expression::Expression(const string& strExp , int modeExpression) {
  _stringToTokens(strExp);
  if(modeExpression == Extension::Prefix) {
    assert(true);
  } else if(modeExpression == Extension::Infix) {
    _inToPostfix();
  } else if(modeExpression == Extension::Postfix){
    _postToPrefix();
  } else {
    assert(false);
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
void Expression::_inToPostfix() {
/* mengubah ekspresi infix menjadi postfix */
  stack<Token *> pre, opr;
  while(!_stackToken.empty()) {
    Token * t = _stackToken.top();
    _stackToken.pop();
    if(t->GetIsOperator()) {
      if((t->GetSymToken())[0] == ')') {
        opr.push(t);
        continue;
      }
      else if((t->GetSymToken())[0] == '(') {
        while(!opr.empty())
          if((opr.top()->GetSymToken())[0] == ')') {
            opr.pop();
            break;
          }
          else {
            pre.push(opr.top());
            opr.pop();
          }
        continue;
      }
      if(!opr.empty())
      {
        if(t->GetPrior() < opr.top()->GetPrior()) {
          pre.push(opr.top());
          opr.pop();
        }
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
  while(!opr.empty()) {
    pre.push(opr.top());
    opr.pop();
  }
  _stackToken = pre;
  while(!pre.empty()) {
    cout << pre.top()->GetSymToken() << endl;
    pre.pop();
  }
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