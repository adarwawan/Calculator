#include "Log.h"

Log::Log() {
  _id = 0;
  _sentence = "";
}

Log::Log(int id, string sentence) {
  _id = id;
  _sentence = sentence;
}

Log::Log(const Log& log) {
  _id = log._id;
  _sentence = log._sentence;
}

Log& Log::operator=(const Log& log) {
  _id = log._id;
  _sentence = log._sentence;  
}

Log::~Log() {
  _sentence.clear();
}

int Log::GetID() {
  return _id;
}

string Log::GetSentence() {
  return _sentence;
}

void Log::SetID(int id) {
  _id = id;
}

void Log::SetSentence(string sentence) {
  _sentence = sentence;
}