/**
* @file Saver.h
**/

#ifndef Saver_H
#define Saver_H

#include <ctime>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include "Logger.h"

using namespace std;
/**
* @class Saver
* @author Ahmad Darmawan (13513096)
* @version 1.0
* 
* @brief Kelas Saver bertugas untuk mengelola penyimpanan instruksi ke dalam file eksternal.
**/
class Saver
{
public:
  /**
  * @brief Konstruktor kelas saver.
  *
  **/
  Saver();
  /**
  * @brief Konstruktor kelas saver dengan parameter.
  * @param S - String yang akan menjadi nama file.
  * @param L - Logger berisi instruksi (ekspresi dan perintah) yang disimpan.
  **/
  Saver(string S, Logger L);
  /**
  * @brief Copy Konstruktor kelas saver.
  * @param S - Objek Saver.
  **/
  Saver(const Saver& S);
  /**
  * @brief Assignment kelas saver.
  * @param S - Objek Saver.
  * @return S' - Objek Saver yang telah diassign dari S.
  **/
  Saver& operator=(const Saver& S);
  /**
  * @brief Destruktor kelas saver.
  **/
  ~Saver();

  /**
  * @brief Getter untuk mendapatkan nama file.
  * @return S - string nama file.
  **/
  string GetFileName(); 
  /**
  * @brief Getter untuk mendapatkan variabel logger.
  * @return L - variabel logger.
  **/
  Logger GetLogMemory();
  /**
  * @brief Setter untuk mengubah nama file.
  * @param S - nama file.
  **/
  void SetFileName(string);
  /**
  * @brief Setter untuk mengubah Logger.
  * @param L - Logger.
  **/
  void SetLogMemory(Logger);
  /**
  * @brief Prosedur program membuat file eksternal.
  **/   
  void ConvertToFile();
  
private:
  string _filename; //  _filename adalah nama file.
  Logger _logMemory; //  _logMemory adalah variabel logger.
  FILE* out; // out adalah variabel output file stream.
};

#endif