/**
* @file Expression.cpp
**/

#include "Expression.h"

Expression::Expression() {

}

Expression::Expression(const string& strExp , int modeExpression, int modeEquation, int modeNumber) {
  _stringToTokens(strExp, modeEquation, modeNumber);
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
  Token * t;
  while(!_stackToken.empty()) {
    t = _stackToken.top();
    _stackToken.pop();
    delete t;
  }
}
Expression& Expression::operator=(const Expression& E) {
  _stackToken = E._stackToken;
  return *this;
}

void Expression::_stringToTokens(const string& _strEq, int modeEquation, int modeNumber) {
/* mengubah string menjadi stack of token */
  int pos = 0, len = 0, i = 0;
  bool op = false;
  while(i < _strEq.length()) {
    if(_strEq[i] == ' ' || _strEq[i] == '\t' || _strEq[i] == '\n' || _strEq[i] == '~') {
      if(op) {
        if(modeEquation == Extension::NumberMode) {
          if(modeNumber == Extension::ArabMode)
            _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
          else if(modeNumber == Extension::RomawiMode)
            _stackToken.push(new NumberRomawi(_strEq.substr(pos, len)));
          else
            assert(false);
        }
        else {
          if(modeEquation == Extension::LogicMode)
          {
            bool isLogic = false;
            char LogicCheck[] = {'T', 't', 'F', 'f', '&', '^', '|'};
            for(int i = 0; i<7 && !isLogic; i++)
              isLogic = (_strEq[pos] == LogicCheck[i]);
            if(isLogic)
              _stackToken.push(new Logic(_strEq.substr(pos, len)));
            else 
              if(modeNumber == Extension::ArabMode)
                _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
              else if(modeNumber == Extension::RomawiMode)
                _stackToken.push(new NumberRomawi(_strEq.substr(pos, len)));
              else
                assert(false);
          }
          else
            assert(false);
        }
        op = false;
      }
      if(_strEq[i] == '~')
        _stackToken.push(new Logic("~"));
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
  if(op) {
    if(modeEquation == Extension::NumberMode) {
      if(modeNumber == Extension::ArabMode)
        _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
      else if(modeNumber == Extension::RomawiMode)
        _stackToken.push(new NumberRomawi(_strEq.substr(pos, len)));
      else
        assert(false);
    }
    else {
      if(modeEquation == Extension::LogicMode)
      {
        bool isLogic = false;
        char LogicCheck[] = {'T', 't', 'F', 'f', '~', '&', '^', '|'};
        for(int i = 0; i<8 && !isLogic; i++)
          isLogic = (_strEq[pos] == LogicCheck[i]);
        if(isLogic)
          _stackToken.push(new Logic(_strEq.substr(pos, len)));
        else 
          if(modeNumber == Extension::ArabMode)
            _stackToken.push(new NumberArab(_strEq.substr(pos, len)));
          else if(modeNumber == Extension::RomawiMode)
            _stackToken.push(new NumberRomawi(_strEq.substr(pos, len)));
          else
            assert(false);
      }
      else
        assert(false);
    }
  }
}
void Expression::_inToPostfix() {
/* mengubah ekspresi infix menjadi prefix */
  stack<Token *> pre, opr;
  string stemp = "#";
  while(!_stackToken.empty()) {
    Token * t = _stackToken.top();
    _stackToken.pop();
    if(t->GetIsOperator()) {
      if(t->GetSymToken()[0] == '~') {
        char c = stemp[0];
        if((c < '0' || c > '9') && (c != '-' || stemp.size()<=1) && (c != '(') && ((c < 'a') || (c > 'z')) && ((c < 'A') || (c > 'Z')) && (c != '~'))
          throw(EquationException(EquationException::IllegalUsingOperator));
      }
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
    stemp = t->GetSymToken();
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