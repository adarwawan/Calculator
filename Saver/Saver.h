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

class Saver
{
public:
  Saver();
  Saver(string S, Logger L);
  ~Saver();
  
  // getter and setter
  string GetFileName();
  Logger GetLogMemory();
  void SetFileName(string);
  void SetLogMemory(Logger);
  void ConvertToFile();
  
private:
  string _filename;
  Logger _logMemory;
  FILE* out;
};

#endif