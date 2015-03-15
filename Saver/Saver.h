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
  
private:
  void ConvertToFile();
  string _filename;
  Logger _logMemory;
};

#endif