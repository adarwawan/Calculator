#include "Equation.h"

using namespace std;
Equation::Equation(string strEqin, int modeExpress) : Expression(strEqin, modeExpress) {
  _strEq = strEqin;
}

Equation::Equation(const Equation& E) : Expression(E){
  _strEq = E._strEq;
  _stackToken = E._stackToken;
}

Equation::~Equation() {
}

Equation& Equation::operator=(const Equation& E) {
  _strEq = E._strEq;
  _stackToken = E._stackToken;
}  
int Equation::GetResult() {
  return _result;
}
void Equation::SolveMathematical() {
  Number * opn1, * opn2;
  Token * opr;
  stack<Number *> res;
  while(!_stackToken.empty()) {
    opr = (Token *)_stackToken.top(); _stackToken.pop();
    if(opr->GetIsOperator()) {
      // <---- Exception jika res.empty() 
      opn1 = res.top(); res.pop();
      //  <--- Exception jika res.empty()
      opn2 = res.top(); res.pop();
      cout << opn1-> GetSymToken() << " " << opr->GetSymToken() << " " << opn2->GetSymToken() << " = ";
      opn1 = Calculate(opn1, opr, opn2);
      cout << opn1->getNilai() << endl;
      res.push(opn1);
    }
    else
      res.push((Number *)opr);
  }
  
  /*
  while(!_stackToken.empty()) {
    Token *t = _stackToken.top();
    if(!(t->GetIsOperator())) {
      Number * n = (Number *)t;
      cout << t->getNilai() << " \t ";
    }
    cout << t->GetSymToken() << endl;
    _stackToken.pop();
  }
  */
  /*  <--- Exception jika res.empty() */
  _stackToken.push((Token *)res.top());
  _result = res.top()->getNilai();
}
void Equation::SolveLogical() {
  Number * opn1, * opn2;
  Token * opr;
  stack<Number *> res;
  while(!_stackToken.empty()) {
    opr = (Token *)_stackToken.top(); _stackToken.pop();
    if(opr->GetIsOperator()) {
      /* <---- Exception jika res.empty() */
      opn1 = res.top(); res.pop();
      /*  <--- Exception jika res.empty() */
      opn2 = res.top(); res.pop();
      opn1 = Calculate(opn1, opr, opn2);
      res.push(opn1);
    }
    else
      res.push((Number *)opr);
  }
  /*  <--- Exception jika res.empty() */
  _stackToken.push((Token *)res.top());
  _result = res.top()->getNilai();
}
Number* Equation::Calculate(Number * opn1, Token * opr, Number * opn2) {
  Number * ret = new NumberArab();
  switch ((opr->GetSymToken())[0]) {
    case '*' :
      (*ret) = (*opn1) * (*opn2);
      break;
    case '/' :
      /* <--- Exception jika opn2 nol */
      (*ret) = (*opn1) / (*opn2);
      break;
    case '+' :
      (*ret) = (*opn1) + (*opn2);
      break;
    case '-' :
      (*ret) = (*opn1) - (*opn2);
      break;
  }
  /* Exception jika nilai diluar batas */
  return ret;
}