#ifndef Logic_H
#define Logic_H

#include <iostream>

using namespace std;

class Logic {
public:
  Logic(int i); /* Constructor */
  Logic(const Logic& L); /* Copy Constructor */
  Logic& operator=(const Logic& L); /* Assignment */
  ~Logic(); /* Destructor */

  /* Getter and Setter */
  int GetLogic();
  void SetLogic(int i);

  /* Method */
  Logic& operator~();
  Logic& operator&(const Logic& L);
  Logic& operator|(const Logic& L);
  Logic& operator^(const Logic& L);

private:
  int _logic;
};

#endif
