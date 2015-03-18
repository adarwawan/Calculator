#include "Saver.h"

using namespace std;
/**
  * @brief Konstruktor kelas saver.
  *
  **/
Saver::Saver() {
  _filename = "";
}
/**
  * @brief Konstruktor kelas saver dengan parameter.
  * @param S - String yang akan menjadi nama file.
  * @param L - Logger berisi instruksi (ekspresi dan perintah) yang disimpan.
  **/
Saver::Saver(string S, Logger L) : _logMemory(L) {
  _filename = S;
}
/**
  * @brief Copy Konstruktor kelas saver.
  * @param S - Objek Saver.
  **/
Saver::Saver(const Saver& S) {
    this->_filename = S._filename;
    this->_logMemory = S._logMemory;
  }
  /**
  * @brief Assignment kelas saver.
  * @param S - Objek Saver.
  * @return S' - Objek Saver yang telah diassign dari S.
  **/
Saver& Saver::operator=(const Saver& S) {
  Saver temp;
  temp._filename = S._filename;
  temp._logMemory = S._logMemory;
}
/**
  * @brief Destruktor kelas saver.
  **/
Saver::~Saver() {

}
/**
  * @brief Getter untuk mendapatkan nama file.
  * @return S - string nama file.
  **/
string Saver::GetFileName() {
  return _filename;
}
/**
  * @brief Getter untuk mendapatkan variabel logger.
  * @return L - variabel logger.
  **/
Logger Saver::GetLogMemory() {
  return _logMemory;
}
/**
  * @brief Setter untuk mengubah nama file.
  * @param S - nama file.
  **/
void Saver::SetFileName(string filename) {
  _filename = filename;
}
/**
  * @brief Setter untuk mengubah Logger.
  * @param L - Logger.
  **/
void Saver::SetLogMemory(Logger logMemory) {
  _logMemory = logMemory;
}
/**
  * @brief Prosedur program membuat file eksternal.
  **/ 
void Saver::ConvertToFile() {
  out = fopen(_filename.c_str(),"w");

  /* Pencatat Waktu */
  time_t ltime; /* calendar time */
  ltime=time(NULL); /* get current cal time */
  fprintf(out, "%s",asctime( localtime(&ltime) ) );

  /* Memasukkan Ekspresi dan Command */
  int ptEq = _logMemory.GetSizeEquations() - 1;
  int ptCom = (int) _logMemory.GetSizeCommands() - 1;
  int index = 0;
  while(ptEq >= 0 || ptCom >= 0) {
    ++index;
    if(ptEq >= 0 && ptCom >= 0) {
      if(_logMemory.GetEquation(ptEq).GetID() > _logMemory.GetCommand(ptCom).GetID()) {
        fprintf(out, "> Perintah terakhir (equation) %2d : %s\n", index,
          _logMemory.GetEquation(ptEq).GetSentence().c_str());
        ptEq--;
      } else {
        fprintf(out, "> Perintah terakhir (command) %3d : %s\n", index,
          _logMemory.GetCommand(ptCom).GetSentence().c_str());
        ptCom--;
      }
    } else if(ptEq >= 0) {
      fprintf(out, "> Perintah terakhir (equation) %2d : %s\n", index,
        _logMemory.GetEquation(ptEq).GetSentence().c_str());
      ptEq--;
    } else {
      assert(ptCom >= 0);
      fprintf(out, "> Perintah terakhir (command) %3d : %s\n", index,
        _logMemory.GetCommand(ptCom).GetSentence().c_str());
      ptCom--;
    }
  }
  fclose (out);
  printf("Penulisan di %s berhasil.\n", _filename.c_str());
}
