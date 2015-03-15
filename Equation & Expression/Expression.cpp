#include "Expression.h"

Expression::Expression(const string& strExp , int modeExpression, int modeNumber) {
  _stringToTokens(strExp, modeNumber);
  switch(modeExpression) {
    case _PREFIX_MODE : // prefix
      break;
    case _INFIX_MODE : // infix
      _inToPrefix();
      break;
    case _POSTFIX_MODE : // postfix
      _postToPrefix();
  }
}
Expression::Expression(const Expression& E) {
  _stackToken = E._stackToken;
}
Expression::~Expression() {
}
void Expression::_stringToTokens(const string& _strEq, int modeNumber) {
/* mengubah string menjadi stack of token */
  int pos = 0, len = 0, i = 0;
  bool op = false;
  while(i < _strEq.length()) {
    if(_strEq[i] == ' ' || _strEq[i] == '\t' || _strEq[i] == '\n') {
      if(op) {
        switch(modeNumber) {
          case _ARAB_MODE :
            _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
            break;
          case _ROMAWI_MODE :
            _stackToken.push(new NumberRomawi(_strEq.substr(pos, len)));
            break;
          case _LOGIC_MODE :
            _stackToken.push(new Logic(_strEq.substr(pos, len)));
        }
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
    switch(modeNumber) {
      case _ARAB_MODE :
        _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
        break;
      case _ROMAWI_MODE :
        _stackToken.push(new NumberRomawi(_strEq.substr(pos, len)));
        break;
      case _LOGIC_MODE :
        _stackToken.push(new Logic(_strEq.substr(pos, len)));
    }
}
void Expression::_inToPrefix() {
/* mengubah ekspresi infix menjadi prefix */
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
      while(!opr.empty()) {
        if(t->GetPrior() < opr.top()->GetPrior()) {
          pre.push(opr.top());
          opr.pop();
        }
        else
          break;
      }
      opr.push(t);
    }
    else
      pre.push(t);
  }
  while(!opr.empty()) {
    pre.push(opr.top());
    opr.pop();
  }
  while(!pre.empty()) {
    _stackToken.push(pre.top());
    pre.pop();
  }
}
void Expression::_postToPrefix() {
/* mengubah ekspresi postfix menjadi prefix */
  stack<Token *> pre, stk;
  Token * flag = new Token("#");
  while(!_stackToken.empty()) {  
    if(_stackToken.top()->GetIsOperator())
      stk.push(_stackToken.top());
    else
    {
      pre.push(_stackToken.top());
      while(!stk.empty() && stk.top() == flag)
      {
        stk.pop();
        pre.push(stk.top());
        stk.pop();
      }
      stk.push(flag);
    }
    _stackToken.pop();
  }
  while(!pre.empty()) {
    _stackToken.push(pre.top());
    pre.pop();
  }
}