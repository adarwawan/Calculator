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
#include "../Logger/Logger.h"

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
  * [I.S] string S dan Logger L terdefinisi.
  * [F.S] Elemen Saver telah terassign dengan string S dan Logger L.
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
  * @brief [I.S] String terdefinisi yang dapat dijadikan nama file.
  * @brief [F.S] _filename terassign dengan parameter string.
  * @param S - nama file.
  **/
  void SetFileName(string);
  /**
  * @brief Setter untuk mengubah Logger.
  * @brief [I.S] Logger terdefinisi.
  * @brief [F.S] _logMemory terassign dengan parameter Logger.
  * @param L - Logger.
  **/
  void SetLogMemory(Logger);
  /**
  * @brief Prosedur program membuat file eksternal.
  * @brief [I.S] String _filename dan Logger _logMemory terdefinisi.
  * @brief [F.S] Tercipta file eksternal bernama _filename dengan masukan dari _logMemory.
  **/   
  void ConvertToFile();
  
private:
  string _filename; //  _filename adalah nama file.
  Logger _logMemory; //  _logMemory adalah variabel logger.
  FILE* out; // out adalah variabel output file stream.
};

#endif