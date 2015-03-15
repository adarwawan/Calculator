#ifndef __EQUATION_H_
#define __EQUATION_H_

#include "Expression.h"

class Equation : public Expression {
public:
  Equation(string strEqin, int modeExpress);
  Equation(const Equation&);
  virtual ~Equation();
  Equation& operator=(const Equation&);
  
  int GetResult();
  void SolveMathematical();
  void SolveLogical();
  Number * Calculate(Number * opn1, Token * opr, Number * opn2);
  
private:
  string _strEq;
  int _result;
};

#endif