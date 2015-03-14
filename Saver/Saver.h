#ifndef Saver_H
#define Saver_H

#include <ctime>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include "logger.h"

using namespace std;

class Saver
{
public:
  Saver(String S, Logger L);
  ~Saver();

private:
  void ConvertToFile();
  String _filename;
  Logger _logMemory;
};

#endif