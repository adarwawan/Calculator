#ifndef __LOG_H_
#define __LOG_H_

#include <string>

using namespace std;

/**
* @class Log
* @author Luqman A. Siswanto (13513024)
* @version 1.0
* 
* @section Description
* @brief Kelas Log adalah abstract data type untuk log command 
**/
class Log {
public:
  /**
  * @brief Konstruktor kelas Log.
  **/
  Log();
  /**
  * @brief Konstruktor kelas Log dengan parameter.
  * @param int - ID.
  * @param string - command pada log yang akan disimpan
  **/
  Log(int, string);
  /**
  * @brief Copy Constructor kelas Log.
  * @param Log yang akan di-copy.
  **/
  Log(const Log&);
  /**
  * @brief Operator assignment kelas Log.
  * @param Log yang akan di-copy.
  **/
  Log& operator=(const Log&);
  /**
  * @brief Destruktor kelas Log.
  **/
  ~Log();
  
  /**
  * @brief Getter untuk ID.
  * @return int - ID pada log.
  **/
  int GetID();
  /**
  * @brief Getter untuk kalimat log.
  * @return string - sentence.
  **/
  string GetSentence();
  /**
  * @brief Setter untuk ID.
  * @param int - ID log.
  **/
  void SetID(int);
  /**
  * @brief Setter untuk sentence.
  * @param string - sentence.
  **/
  void SetSentence(string);
private:
  int _id;            // id log, dipastikan tiap log memiliki ID yang unik dan terurut menaik berdasarkan eksekusi
  string _sentence;   // kalimat yang berisi perintah
};

#endif