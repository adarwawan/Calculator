#ifndef __EQUATION_H_
#define __EQUATION_H_

#include "Expression.h"
#include "EquationException.h"

class Equation : public Expression {
public:
  Equation();
  Equation(string strEqin, int modeExpress, int modeEquation, int modeNumber);
  Equation(const Equation&);
  virtual ~Equation();
  Equation& operator=(const Equation&);
  
  string GetResult();
  void SolveMathematical();
  void SolveLogical();
  Number * CalculateNumber(Number * opn1, Token * opr, Number * opn2);
  Logic * CalculateLogic(Logic * opn1, Token * opr, Logic * opn2);
  Logic * CalculateNumberToLogic(Number * opn1, Token * opr, Number * opn2);
  
private:
  string _strEq;
  string _result;
  int _modeEquation;
  int _modeNumber;
};

#endif