#ifndef __LOGGER_H_
#define __LOGGER_H_

#include "Log.h"
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

/**
* @class Logger
* @author Luqman A. Siswanto (13513024)
* @version 1.0
* 
* @section Description
* @brief Kelas Log adalah abstract data type untuk log command
*
* @section Rule
* @brief Semua dalam vector commands dijamin valid (tidak ada operasi undo/redo)
* @brief Seluruh isi vector equations belum tentu valid karena bisa jadi hasil undo
**/
class Logger {
public:
  /**
  * @brief Konstruktor kelas logger.
  **/
  Logger();
  /**
  * @brief Konstruktor kelas logger dengan parameter.
  * @param vector<Log> - commands
  * @param vector<Log> - equations
  **/
  Logger(vector<Log>, vector<Log>);
  /**
  * @brief Konstruktor kelas logger dengan parameter.
  * @param vector<Log> - commands
  * @param vector<Log> - equations
  * @param int - ukuran equations yang valid
  **/
  Logger(vector<Log>, vector<Log>, int);
  /**
  * @brief Copy constructor kelas logger.
  * @param Logger - logger yang akan di-copy
  **/
  Logger(const Logger&);
  /**
  * @brief Operator assignment kelas Logger.
  * @param Logger - logger yang akan di-copy
  **/
  Logger& operator=(const Logger&);
  /**
  * @brief Destruktor kelas Logger.
  **/
  ~Logger();
  
  /**
  * @brief Getter Log Commands dengan indeks tertentu.
  * @param int - indeks
  * @return Log - Log Command dengan indeks tertentu
  **/
  Log GetCommand(int);
  /**
  * @brief Getter Log Equations dengan indeks tertentu.
  * @param int - indeks
  * @return Log - Log Equation dengan indeks tertentu
  **/
  Log GetEquation(int);
  /**
  * @brief Getter ukuran commands yang valid.
  * @return int - commands size
  **/
  int GetSizeCommands();
  /**
  * @brief Getter ukuran equations yang valid.
  * @return int - equations size
  **/
  int GetSizeEquations();
  
  /**
  * @brief Menghilangkan seluruh commands dan equations di memori.
  **/
  void Clear();
  /**
  * @brief Menghilangkan commands di memori.
  **/
  void ClearCommands();
  /**
  * @brief Menghilangkan commands di equations.
  **/
  void ClearEquations();
  
  /**
  * @brief Menambahkan log pada list of commands.
  * @param Log - yang akan ditambah
  **/
  void AddCommand(Log);
  /**
  * @brief Menambahkan log pada list of equations.
  * @param Log - yang akan ditambah
  **/
  void AddEquation(Log);
  
  /**
  * @brief Membatalkan equation yang telah ditambah
  * @param int - berapa item undo yang diminta
  * @return int - berapa item undo yang berhasil dilakukan
  **/
  int UndoEquation(int);
  /**
  * @brief Melakukan kembali equation yang telah di-undo
  * @param int - berapa item redo yang diminta
  * @return int - berapa item redo yang berhasil dilakukan
  **/
  int RedoEquation(int);
  /**
  * @brief Menampilkan memori kembali ke layar
  * @param int - berapa item yang akan ditampilkan ke layar
  **/
  void ShowMem(int);
  /**
  * @brief Menampilkan semua memori kembali ke layar
  **/
  void ShowMemAll();
  
private:
  vector<Log> _commands;      // ID command dan equation dijamin unique
  vector<Log> _equations;
  int _sizeEquations;         // menandakan banyak Log equation yang valid
                              // setelah operasi redo dan undo
};

#endif