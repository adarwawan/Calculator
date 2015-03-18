#ifndef __OWN_VECTOR_H_
#define __OWN_VECTOR_H_

#include <algorithm>
#include <cassert>

/**
* @class vector
* @author Luqman A. Siswanto (13513024)
* @version 1.0
* 
* @section Description
* @brief Vector adalah implementasi vector yang ekuivalen vector STL C++
*
**/
template <class T>
class vector {
public:
  /**
  * @brief Konstruktor kelas vector.
  **/
  vector();
  /**
  * @brief Copy constructor kelas vector.
  * @param vector : yang akan di-copy
  **/
  vector(const vector<T>&);
  /**
  * @brief Operator assignment kelas vector.
  * @param vector : yang akan di-copy
  **/
  vector<T>& operator= (vector<T>);
  /**
  * @brief Operator assignment kelas vector.
  * @param vector : yang akan di-copy
  **/
  ~vector();
  
  /**
  * @brief Mengembalikan ukuran vector.
  * @return int - ukuran vector
  **/
  int size();
  /**
  * @brief Mengembalikan ukuran maksimal vector saat ini sebelum alokasi kembali.
  * @return int - ukuran max vector
  **/
  int max_size();
  /**
  * @brief Mengubah ukuran vector
  * @param ukuran vector tujuan
  **/
  void resize(int);
  /**
  * @brief Mengembalikan ukuran maksimal vector saat ini sebelum alokasi kembali.
  * @return int - ukuran max vector
  **/
  int capacity();
  /**
  * @brief Mengembalikan predikat apakah vector kosong.
  * @return bool : predikat kosong vector 
  **/
  bool empty();
  
  // element access
  /**
  * @brief Mengembalikan isi kontainer pada indeks tertentu
  * @param int - indeks vector
  * @return reference class T : item pada indeks tertentu
  **/
  T& operator[](int);
  /**
  * @brief Mengembalikan isi kontainer pada indeks tertentu
  * @param int - indeks vector
  * @return reference class T : item pada indeks tertentu
  **/
  T& at(int);
  /**
  * @brief Mengembalikan isi kontainer paling awal
  * @return reference class T : item pada indeks terawal
  **/
  T& front();
  /**
  * @brief Mengembalikan isi kontainer paling akhir
  * @return reference class T : item pada indeks paling belakang
  **/
  T& back();
  
  // modifiers
  /**
  * @brief Memasukkan item pada akhir kontainer
  * @brief Bila vector penuh, maka mengalokasikan memori tambahan sebesar default Size
  * @param class T : item yang akan dimasukkan
  **/
  void push_back(T);
  /**
  * @brief Melepaskan item paling belakang vector
  * @brief I. S. vector tidak kosong
  **/
  void pop_back();
  /**
  * @brief Menukar kontainer vector beserta atributnya dengan vector lain
  * @param vector : vector yang akan ditukar dengan object this
  **/
  void swap(vector<T>&);
  /**
  * @brief Mengkosongkan isi vector
  **/
  void clear();
  
private:
  static const int _defaultSize;  // konstanta ukuran default vector
  T* _tab;                        // kontainer berupa array of class T 
  int _maxSize;                   // ukuran maksimal vector saat ini
  int _size;                      // ukuran vector sekarang yang terisi
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
  _size = 0;
  _maxSize = block * _defaultSize;
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