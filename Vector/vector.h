#ifndef __OWN_VECTOR_H_
#define __OWN_VECTOR_H_

#include <algorithm>
#include <cassert>

template <class T>
class vector {
public:
  vector();
  vector(const vector<T>&);
  vector<T>& operator= (vector<T>);
  ~vector();
  
  // capacity
  int size();
  int max_size();
  void resize(int);
  int capacity();
  bool empty();
  
  // element access
  T& operator[](int);
  T& at(int);
  T& front();
  T& back();
  
  // modifiers
  void push_back(T);
  void pop_back();
  void swap(vector<T>&);
  void clear();
  
private:
  static const int _defaultSize;
  T* _tab;
  int _maxSize;
  int _size;
};



template <class T>
const int vector<T>::_defaultSize = 100;

template <class T>
vector<T>::vector() {
  _tab = new T[_defaultSize];
  _maxSize = _defaultSize;
  _size = 0;
}

template <class T>
vector<T>::vector(const vector<T>& v) {
  _tab = new T[v._maxSize];
  _maxSize = v._maxSize;
  _size = v._size;
}

template <class T>
vector<T>& vector<T>::operator=(vector<T> v) {
  delete[] _tab;
  _tab = new T[v._maxSize];
  _maxSize = v._maxSize;
  _size = v._size;
  for(int i = 0; i < _maxSize; i++) {
    _tab[i] = v._tab[i];
  }
}

template <class T>
vector<T>::~vector() {
  delete[] _tab;
}

template <class T>
int vector<T>::size() {
  return _size;
}

template <class T>
int vector<T>::max_size() {
  return _maxSize;
}

template <class T>
void vector<T>::resize(int n) {
  int block = n / _defaultSize + 1;
  delete[] _tab;
  _tab = new T[block * _defaultSize];
}

template <class T>
int vector<T>::capacity() {
  return _maxSize;
}

template <class T>
bool vector<T>::empty() {
  return _size == 0;
}

template <class T>
T& vector<T>::operator[](int i) {
  assert(0 <= i && i < _size);
  return _tab[i];
}

template <class T>
T& vector<T>::at(int i) {
  assert(0 <= i && i < _size);
  return _tab[i];
}

template <class T>
T& vector<T>::front() {
  return _tab[0];
}

template <class T>
T& vector<T>::back() {
  return _tab[_size - 1];
}

template <class T>
void vector<T>::push_back(T e) {
  if(_size == _maxSize) {
    T* newTab = new T[_maxSize + _defaultSize];
    for(int i = 0; i < _maxSize; i++) {
      newTab[i] = _tab[i];
    }
    _maxSize += _defaultSize;
    delete[] _tab;
    _tab = newTab;
  }
  _tab[_size] = e;
  _size++;
}

template <class T>
void vector<T>::pop_back() {
  assert(_size > 0);
  _size--;
}

template <class T>
void vector<T>::swap(vector<T>& v) {
  swap(v._tab, this._tab);
  swap(v._maxSize, this._maxSize);
  swap(v._size, this._size);
}

template <class T>
void vector<T>::clear() {
  _size = 0;
}


#endif