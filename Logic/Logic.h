#ifndef Logic_H
#define Logic_H

#include <iostream>
#include "../Token/Token.h"

using namespace std;

class Logic : public Token {
public:
  Logic(); /* Constructor */
  Logic(string s); /* Constructor */
  Logic(int i); /* Constructor */
  Logic(const Logic& L); /* Copy Constructor */
  Logic& operator=(const Logic& L); /* Assignment */
  ~Logic(); /* Destructor */

  /* Getter and Setter */
  int GetLogic();
  void SetLogic(int i);

  /* Method */
  Logic operator~();
  Logic operator&(const Logic& L);
  Logic operator|(const Logic& L);
  Logic operator^(const Logic& L);
  int toInt(string);
  string toString(int);

private:
  int _logic;
};

#endif
