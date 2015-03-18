/**
* @file Token.h
**/
#ifndef Token_H
#define Token_H

#include <iostream>
using namespace std;
/**
* @class Token
* @author Ahmad Darmawan (13513096)
* @version 1.0
* 
* @brief Kelas Token menyimpan operator dan operan.
**/
class Token {
public :
  /**
  * @brief Konstruktor kelas Token dengan Parameter.
  * @param S - String yang menjadi anggota token.
  **/
  Token(string S);
  /**
  * @brief Copy Konstruktor kelas Token.
  * @param T - Variabel Token masukan.
  * @return Ti - Variabel Token yang tercopy.
  **/
  Token(const Token& T);
  /**
  * @brief Assignment kelas Logic.
  * @param T - Variabel Token masukan.
  * @return Ti - Variabel Token yang terassign.
  **/
  Token& operator=(const Token& T);
  /**
  * @brief Destruktor kelas Token.
  **/
  ~Token();
  
  /**
  * @brief Getter untuk mendapatkan nilai _symToken.
  * @return S - string nilai _symToken.
  **/
  string GetSymToken() const;
  /**
  * @brief Getter untuk mendapatkan nilai _isOperator.
  * @return bool - boolean nilai _isOperator.
  **/
  bool GetIsOperator();
  /**
  * @brief Setter untuk mengubah nilai _symToken.
  * @param S - nilai _symToken yang akan dimasukkan.
  **/
  void SetSymToken(string S);
  /**
  * @brief Getter untuk mendapatkan nilai _prior.
  * @return i - integer nilai _prior.
  **/
  int GetPrior();

private :
  /**
  * @brief Set nilai _isOperator berdasarkan _symToken.
  * @return bool - nilai _isOperator
  **/
  bool _IdentifyToken();
  /**
  * @brief Set nilai _prior berdasarkan _symToken (untuk operator).
  * @return int - nilai _prior.
  **/
  void _IdentifyPrior();
  string _symToken; // Simbol Token.
  bool _isOperator; // Nilai 1 jika token merupakan operator.
  int _prior; // Nilai sesuai prioritas operator.
};

#endif
