#include "Equation.h"

using namespace std;

Equation::Equation() {
  _modeEquation = Extension::defaultEquationMode;
  _modeNumber = Extension::defaultNumberMode;
  _result = "";
}

Equation::Equation(string strEqin, int modeExpress, int modeEquation, int modeNumber) : Expression(strEqin, modeExpress, modeEquation, modeNumber) {
  _strEq = strEqin;
  _modeEquation = modeEquation;
  _modeNumber = modeNumber;
}

Equation::Equation(const Equation& E) : Expression(E){
  _strEq = E._strEq;
  _result = E._result;
  _modeEquation = E._modeEquation;
  _modeNumber = E._modeNumber;
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
    if(_modeEquation == Extension::NumberMode) {
      SolveMathematical();
    } else if(_modeEquation == Extension::LogicMode) {
      SolveLogical();
    } else {
      assert(false);
    }
  }
  return _result;
}

void Equation::SolveMathematical() {
  Number * opn1, * opn2;
  Token * opr;
  stack<Number *> res;
  if(_stackToken.empty()) {
    throw(EquationException(EquationException::EmptyEquation));
  }
  while(!_stackToken.empty()) {
    opr = (Token *)_stackToken.top(); _stackToken.pop();
    if(opr->GetIsOperator()) {
      if(res.empty())
        throw(EquationException(EquationException::IllegalUsingOperator));
      opn1 = res.top(); res.pop();
      if(res.empty())
        throw(EquationException(EquationException::IllegalUsingOperator));
      opn2 = res.top(); res.pop();
      cout << opn1-> GetSymToken() << " " << opr->GetSymToken() << " " << opn2->GetSymToken() << " = ";
      opn1 = CalculateNumber(opn1, opr, opn2);
      cout << opn1->GetSymToken() << endl;
      res.push(opn1);
    }
    else
      res.push((Number *)opr);
  }
  
  if(res.size() != 1)
    throw(EquationException(EquationException::IllegalUsingOperator));
  _stackToken.push((Token *)res.top());
  _result = res.top()->GetSymToken();
}

void Equation::SolveLogical() {
  Logic * opn1, * opn2;
  Token * opr;
  stack<Logic *> res;
  if(_stackToken.empty()) {
    throw(EquationException(EquationException::EmptyEquation));
  }
  while(!_stackToken.empty()) {
    opr = (Token *)_stackToken.top(); _stackToken.pop();
    if(opr->GetIsOperator()) {
      if(res.empty())
        throw(EquationException(EquationException::IllegalUsingOperator));
      opn1 = res.top(); res.pop();
      
      if(opr->GetSymToken()[0] == '~') {// kasus operator unary negasi (~)
        (*opn1) = ~(*opn1);
        res.push(opn1);
        continue;
      }
      
      if(res.empty())
        throw(EquationException(EquationException::IllegalUsingOperator));
      opn2 = res.top(); res.pop();
      cout << opn1-> GetSymToken() << " " << opr->GetSymToken() << " " << opn2->GetSymToken() << " = ";
      opn1 = CalculateLogic(opn1, opr, opn2);
      cout << opn1->GetSymToken() << endl;
      res.push(opn1);
    }
    else
      res.push((Logic *)opr);
  }
  
  if(res.size() != 1)
    throw(EquationException(EquationException::IllegalUsingOperator));
  _stackToken.push((Token *)res.top());
  _result = res.top()->GetSymToken();
}
Number* Equation::CalculateNumber(Number * opn1, Token * opr, Number * opn2) {
  Number * ret;
  if(_modeNumber == Extension::ArabMode) {
    ret = new NumberArab();
  } else if(_modeNumber == Extension::RomawiMode) {
    ret = new NumberRomawi();
  } else {
    assert(false);
  }
  switch ((opr->GetSymToken())[0]) {
    case '*' :
      (*ret) = (*opn1) * (*opn2);
      break;
    case '/' :
      if(opn2->getNilai() == 0)
        throw(EquationException(EquationException::DivideByZero));
      (*ret) = (*opn1) / (*opn2);
      break;
    case '+' :
      (*ret) = (*opn1) + (*opn2);
      break;
    case '-' :
      (*ret) = (*opn1) - (*opn2);
      break;
    case '%' :
      if(opn2->getNilai() <= 0)
        throw(EquationException(EquationException::ModuloByNonPositif));
      (*ret) = (*opn1) % (*opn2);
      break;
    default :
      throw(EquationException(EquationException::UndefinedOperator));
  }
  if(_modeNumber == Extension::RomawiMode && (ret->getNilai() < 1 || ret->getNilai() > 3999))
    throw(EquationException(EquationException::OutOfBoundRomawi));
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
    default:
      throw(EquationException(EquationException::UndefinedOperator));
  }
  return ret;
}