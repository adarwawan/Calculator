#ifndef __READER_H_
#define __READER_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
* @class Reader
* @author Luqman A. Siswanto (13513024)
* @version 1.0
* 
* @section Description
* @brief Kelas Reader bertugas menerima input dari user kemudian mengkategorikan input tersebut termasuk command atau ekspresi
*
**/
class Reader {
public:
  /**
  * @brief Konstruktor kelas Reader.
  **/
  Reader();
  /**
  * @brief Copy constructor kelas logger.
  * @param Reader : yang akan di-copy
  **/
  Reader(const Reader&);
  /**
  * @brief Copy constructor kelas logger.
  * @param Reader : yang akan di-copy
  **/
  Reader& operator=(const Reader&);
  /**
  * @brief Destruktor kelas logger.
  **/
  ~Reader();
  
  /**
  * @brief Membaca perintah dari user sekaligus meng-update data member isEquation.
  * @return string - string yang berhasil dibaca
  **/
  string Read();
  /**
  * @brief Mengembalikan predikat apakah sebuah string merupakan equation
  * @return bool - jika true, maka string adalah equation
  **/
  bool IsEquation();
  
private:
  /**
  * @brief Melakukan identifikasi apakah string merupakan equation
  **/
  void _UpdateIsEquation();
  string _sentence;                 // kalimat yang tepat dibaca dari user
  bool _isEquation;                 // true jika dia equation, false jika perintah
  static const string _commands[];  // list dari command yang diterima oleh program
};

#endif