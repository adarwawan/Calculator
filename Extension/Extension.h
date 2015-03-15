#ifndef __EXTENSION_H
#define __EXTENSION_H

class Extension {
public:
  Extension();
  ~Extension();
  static const int Prefix;
  static const int Infix;
  static const int Postfix;
  
  static const int NumberMode;
  static const int LogicMode;
  
  static const int ArabMode;
  static const int RomawiMode;
  
  static const int defaultExpressionMode;  // prefix, infix, postfix
  static const int defaultEquationMode;    // bilangan / logika
  static const int defaultNumberMode;      // arab / romawi

private:

};

#endif