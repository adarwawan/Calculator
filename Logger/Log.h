#ifndef __LOG_H_
#define __LOG_H_

#include <string>

using namespace std;

class Log {
public:
  Log();
  Log(int, string);
  Log(const Log&);
  Log& operator=(const Log&);
  ~Log();
  
  int GetID();
  string GetSentence();
  void SetID(int);
  void SetSentence(string);
private:
  int _id;
  string _sentence;
};

#endif