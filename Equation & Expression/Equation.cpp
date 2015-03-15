#include "Equation.h"

using namespace std;
Equation::Equation(string strEqin, int modeExpress, int modeNumber) : Expression(strEqin, modeExpress, modeNumber) {
  _strEq = strEqin;
  _modeNumber = modeNumber;
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
string Equation::GetResult() {
  if(_result.length() < 1) {
    switch (_modeNumber) {
      case _ARAB_MODE:
      case _ROMAWI_MODE:
        SolveMathematical();
        break;
      case _LOGIC_MODE:
        SolveLogical();
    }
  }
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
      opn1 = CalculateNumber(opn1, opr, opn2);
      cout << opn1->GetSymToken() << endl;
      res.push(opn1);
    }
    else
      res.push((Number *)opr);
  }
  
  /*  <--- Exception jika res.empty() */
  _stackToken.push((Token *)res.top());
  _result = res.top()->GetSymToken();
}
void Equation::SolveLogical() {
  Logic * opn1, * opn2;
  Token * opr;
  stack<Logic *> res;
  while(!_stackToken.empty()) {
    opr = (Token *)_stackToken.top(); _stackToken.pop();
    if(opr->GetIsOperator()) {
      // <---- Exception jika res.empty() 
      opn1 = res.top(); res.pop();
      
      if(opr->GetSymToken()[0] == '~') {// kasus operator unary negasi (~)
        (*opn1) = ~(*opn1);
        res.push(opn1);
        continue;
      }
      
      //  <--- Exception jika res.empty()
      opn2 = res.top(); res.pop();
      cout << opn1-> GetSymToken() << " " << opr->GetSymToken() << " " << opn2->GetSymToken() << " = ";
      opn1 = CalculateLogic(opn1, opr, opn2);
      cout << opn1->GetSymToken() << endl;
      res.push(opn1);
    }
    else
      res.push((Logic *)opr);
  }
  
  /*  <--- Exception jika res.empty() */
  _stackToken.push((Token *)res.top());
  _result = res.top()->GetSymToken();
}
Number* Equation::CalculateNumber(Number * opn1, Token * opr, Number * opn2) {
  Number * ret;
  switch(_modeNumber) {
  case _ARAB_MODE :
    ret = new NumberArab();
    break;
  case _ROMAWI_MODE :
  default :
    ret = new NumberRomawi();
  }
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
    case '%' :
      /* <--- Exception jika opn2 nol */
      (*ret) = (*opn1) % (*opn2);
      break;
      
  }
  /* Exception jika nilai diluar batas */
  return ret;
}

Logic * Equation::CalculateLogic(Logic * opn1, Token * opr, Logic * opn2) {
  Logic * ret = new Logic();
  switch ((opr->GetSymToken())[0]) {
    case '&' :
      (*ret) = (*opn1) & (*opn2);
      break;
    case '|' :
      (*ret) = (*opn1) | (*opn2);
      break;
    case '^' :
      (*ret) = (*opn1) ^ (*opn2);
      break;
      
  }
  /* Exception jika nilai diluar batas */
  return ret;
}