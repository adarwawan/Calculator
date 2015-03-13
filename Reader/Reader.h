#ifndef __READER_H_
#define __READER_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Reader {
public:
  Reader();
  Reader(const Reader&);
  Reader& operator=(const Reader&);
  ~Reader();
  
  // membaca perintah dari user sekaligus meng-update data member isEquation
  void Read();
  string GetSentence();
  bool IsEquation();
  
private:
  void _UpdateIsEquation();
  string _sentence;
  bool _isEquation;      // true jika dia equation, false jika perintah
  static const string _commands[];
};

#endif