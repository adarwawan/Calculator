#include "Saver.h"

using namespace std;

Saver::Saver() {
  _filename = "";
}

Saver::Saver(string S, Logger L) : _logMemory(L) {
  _filename = S;
}

Saver::~Saver() {

}

string Saver::GetFileName() {
  return _filename;
}

Logger Saver::GetLogMemory() {
  return _logMemory;
}

void Saver::SetFileName(string filename) {
  _filename = filename;
}

void Saver::SetLogMemory(Logger logMemory) {
  _logMemory = logMemory;
}

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
