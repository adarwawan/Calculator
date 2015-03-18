/**
* @file Logic.cpp
**/
#include <iostream>
#include "Logic.h"

using namespace std;

/**
  * @brief Konstruktor kelas Logic.
  *
  **/
Logic::Logic() : Token(toString(0)) {
  _logic = 0;
}
/**
  * @brief Konstruktor kelas Logic dengan parameter string.
  * @param S - String berisi nilai logika (TRUE atau FALSE).
  **/
Logic::Logic(string s) : Token(s) {
  _logic = toInt(s);
}
  /**
  * @brief Konstruktor kelas Logic dengan parameter integer.
  * @param i - Integer berisi nilai logika (0 atau 1).
  **/
Logic::Logic(int i) : Token(toString(i)) {
  _logic = i;
}
  /**
  * @brief Copy Konstruktor kelas Logic.
  * @param L - Variabel Logic masukan.
  * @return Li - Variabel Logic yang tercopy.
  **/
Logic::Logic(const Logic& L) : Token(toString(L._logic)) {
  this->_logic = L._logic;
}
  /**
  * @brief Assignment kelas Logic.
  * @param L - Variabel Logic masukan.
  * @return Li - Variabel Logic yang terassign.
  **/
Logic& Logic::operator=(const Logic& L) {
  this->_logic = L._logic;
  this->SetSymToken(L.GetSymToken());
  return *this;
}
 /**
  * @brief Destruktor kelas Logic.
  **/
Logic::~Logic() {

}
  /**
  * @brief Getter untuk mendapatkan nilai logic.
  * @return i - integer nilai logic (0 atau 1).
  **/
int Logic::GetLogic() {
  return _logic;
}
  /**
  * @brief Setter untuk mengubah nilai logic.
  * @param S - nilai logic yang akan dimasukkan.
  **/
void Logic::SetLogic(int i) {
  _logic = i;
}

  /**
  * @brief Melakukan proses "not" pada nilai logika (~L).
  * @param L - Objek Logika awal.
  * @return ~L - Objek Logika akhir.
  **/
Logic& Logic::operator~() {
  return *(new Logic(!_logic));
}
  /**
  * @brief Melakukan proses "and" pada nilai logika (L1 & L2).
  * @param L1 - Objek Logika pertama.
  * @param L2 - Objek Logika kedua.
  * @return L' = L1 & L2.
  **/
Logic& Logic::operator&(const Logic& L) {
  return *(new Logic(_logic && L._logic));
}
  /**
  * @brief Melakukan proses "or" pada nilai logika (L1 | L2).
  * @param L1 - Objek Logika pertama.
  * @param L2 - Objek Logika kedua.
  * @return L' = L1 | L2.
  **/
Logic& Logic::operator|(const Logic& L) {
  return *(new Logic(_logic || L._logic));
}
/**
  * @brief Melakukan proses "xor" pada nilai logika (L1 ^ L2).
  * @param L1 - Objek Logika pertama.
  * @param L2 - Objek Logika kedua.
  * @return L' = L1 ^ L2.
  **/
Logic& Logic::operator^(const Logic& L) {
  return *(new Logic(_logic ^ L._logic));
}
  /**
  * @brief Mengubah nilai logika dalam bentuk string (TRUE atau FALSE) menjadi bentuk integer (1 & 0).
  * @param S - nilai logika dalam string.
  * @return i - nilai logika dalam integer.
  **/
int Logic::toInt(string s) {
  if(s == "FALSE" || s == "false")
    return 0;
  return 1;
}
  /**
  * @brief Mengubah nilai logika dalam bentuk bentuk integer (1 & 0) menjadi string (TRUE atau FALSE).
  * @param i - nilai logika dalam integer.
  * @return S - nilai logika dalam string.
  **/
string Logic::toString(int n) {
  string ret;
  if(n)
    ret = string("TRUE");
  else
    ret = string("FALSE");
  return ret;
}