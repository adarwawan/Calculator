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

private:
  void ConvertToFile();
  string _filename;
  Logger _logMemory;
};

#endif