/**
* @file Logic.h
**/
#ifndef Logic_H
#define Logic_H

#include <iostream>
#include "Token.h"

using namespace std;
/**
* @class Logic
* @author Ahmad Darmawan (13513096)
* @version 1.0
* 
* @brief Kelas Logic mengatur perhitungan operasi logika (~, &, ^, |)
**/
class Logic : public Token {
public:
  /**
  * @brief Konstruktor kelas Logic.
  *
  **/
  Logic();
  /**
  * @brief Konstruktor kelas Logic dengan parameter string.
  * @param S - String berisi nilai logika (TRUE atau FALSE).
  **/
  Logic(string s);
  /**
  * @brief Konstruktor kelas Logic dengan parameter integer.
  * @param i - Integer berisi nilai logika (0 atau 1).
  **/
  Logic(int i);
  /**
  * @brief Copy Konstruktor kelas Logic.
  * @param L - Variabel Logic masukan.
  * @return Li - Variabel Logic yang tercopy.
  **/
  Logic(const Logic& L); 
  /**
  * @brief Assignment kelas Logic.
  * @param L - Variabel Logic masukan.
  * @return Li - Variabel Logic yang terassign.
  **/
  Logic& operator=(const Logic& L);
  /**
  * @brief Destruktor kelas Logic.
  **/
  ~Logic();

  /**
  * @brief Getter untuk mendapatkan nilai logic.
  * @return i - integer nilai logic (0 atau 1).
  **/
  int GetLogic();
  /**
  * @brief Setter untuk mengubah nilai logic.
  * @param S - nilai logic yang akan dimasukkan.
  **/
  void SetLogic(int i);

  /**
  * @brief Melakukan proses "not" pada nilai logika (~L).
  * @param L - Objek Logika awal.
  * @return ~L - Objek Logika akhir.
  **/
  Logic& operator~();
  /**
  * @brief Melakukan proses "and" pada nilai logika (L1 & L2).
  * @param L1 - Objek Logika pertama.
  * @param L2 - Objek Logika kedua.
  * @return L' = L1 & L2.
  **/
  Logic& operator&(const Logic& L);
  /**
  * @brief Melakukan proses "or" pada nilai logika (L1 | L2).
  * @param L1 - Objek Logika pertama.
  * @param L2 - Objek Logika kedua.
  * @return L' = L1 | L2.
  **/
  Logic& operator|(const Logic& L);
  /**
  * @brief Melakukan proses "xor" pada nilai logika (L1 ^ L2).
  * @param L1 - Objek Logika pertama.
  * @param L2 - Objek Logika kedua.
  * @return L' = L1 ^ L2.
  **/
  Logic& operator^(const Logic& L);
  /**
  * @brief Mengubah nilai logika dalam bentuk string (TRUE atau FALSE) menjadi bentuk integer (1 & 0).
  * @param S - nilai logika dalam string.
  * @return i - nilai logika dalam integer.
  **/
  int toInt(string);
  /**
  * @brief Mengubah nilai logika dalam bentuk bentuk integer (1 & 0) menjadi string (TRUE atau FALSE).
  * @param i - nilai logika dalam integer.
  * @return S - nilai logika dalam string.
  **/
  string toString(int);

private:
  int _logic; // nilai logika dalam integer (0 dan 1).
};

#endif
