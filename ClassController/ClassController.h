#ifndef __ClassController_H_
#define __ClassController_H_

#include "../Reader/Reader.h"
#include "../Equation/Equation.h"
#include "../Equation/Expression.h"
#include "../Saver/Saver.h"
#include "../Logger/Logger.h"
#include "../Extension/Extension.h"
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <conio.h>

/**
* @class Saver
* @author Luqman A. Siswanto (13513024)
* @version 1.0
* 
* @section Description
* @brief Kelas ClassController bertugas untuk mengatur kehidupan dan kematian kelas-kelas lain.
**/
class ClassController {
public:
  /**
  * @brief Konstruktor kelas ClassController.
  *
  **/
  ClassController();
  /**
  * @brief Copy Constructor kelas ClassController dengan parameter.
  * @param ClassController yang akan di-copy.
  **/
  ClassController(const ClassController&);
  /**
  * @brief Operator assignment kelas ClassController.
  **/
  ClassController& operator=(const ClassController&);
  /**
  * @brief Destruktor kelas ClassController.
  **/
  ~ClassController();
  /**
  * @brief Mengeksekusi ekspresi yang dimasukkan oleh user.
  * @param string - masukan string ekspresi yang akan dieksekusi.
  **/
  void ExecuteExpression(string&);
  /**
  * @brief Mengeksekusi command yang dimasukkan oleh user.
  * @param string - masukan string command yang akan dieksekusi.
  **/
  void ExecuteCommand(string);
  /**
  * @brief Mengembalikan perintah yang telah dimasukkan user.
  * @param int - banyak perintah.
  **/
  void Undo(int);
  /**
  * @brief Mengembalikan perintah yang telah di-undo user.
  * @param int - banyak perintah.
  **/
  void Redo(int);
  
  /**
  * @brief Mengubah mode ekspresi (prefiks - infiks - postfiks)
  * @param int - nomor setting (ada di kelas Extension).
  **/
  void SetExpressionMode(int);
  /**
  * @brief Mengubah mode equation (bilangan - logika)
  * @param int - nomor setting (ada di kelas Extension).
  **/
  void SetEquationMode(int);
  /**
  * @brief Mengubah mode number (romawi - arab)
  * @param int - nomor setting (ada di kelas Extension).
  **/
  void SetNumberMode(int);
  
  /**
  * @brief Mengembalikan setting ke mode default.
  **/
  void ResetSetting();
  /**
  * @brief Menampilkan n perintah terakhir yang dimasukkan user.
  * @param n - int. Banyak perintah.
  **/
  void ShowMem(int);
  /**
  * @brief Menampilkan semua perintah yang dimasukkan user.
  **/
  void ShowMemAll();
  /**
  * @brief Menampilkan 'help' yang berisi daftar command yang berlaku dalam program.
  **/
  void Help();
  /**
  * @brief Menampilkan mode setting terkini
  **/
  void ViewSetting();
  
private:
  int _expressionMode;  // mode ekspresi saat ini
  int _equationMode;    // mode equation saat ini
  int _numberMode;      // mode bilangan saat ini
  Reader* _reader;      // pembaca
  Saver* _saver;        // penyimpan file
  Logger* _logger;      // penyimpan perintah yang pernah dimasukkan user
};

#endif  // __ClassController_H_
