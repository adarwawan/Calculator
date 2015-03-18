#ifndef __EXTENSION_H
#define __EXTENSION_H

/**
* @class Extension
* @author Luqman A. Siswanto (13513024)
* @version 1.0
* 
* @section Description
* @brief Kelas Extension berisi konstanta yang dibutuhkan dalam program
**/
class Extension {
public:
  /**
  * @brief Konstruktor kelas Extension.
  **/
  Extension();
  /**
  * @brief Desktruktor kelas Extension.
  **/
  ~Extension();
  static const int Prefix;                // konstanta mode prefiks
  static const int Infix;                 // konstanta mode infiks
  static const int Postfix;               // konstanta mode postfiks
  
  static const int NumberMode;            // konstanta mode bilangan
  static const int LogicMode;             // konstanta mode logika
  
  static const int ArabMode;              // konstanta mode bilangan arab
  static const int RomawiMode;            // konstanta mode bilangan romawi
  
  static const int defaultExpressionMode; // prefix, infix, postfix
  static const int defaultEquationMode;   // bilangan / logika
  static const int defaultNumberMode;     // arab / romawi

private:

};

#endif  // __EXTENSION_H