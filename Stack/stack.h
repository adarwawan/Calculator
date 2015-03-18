/**
* @file stack.h
**/

#ifndef __STACK_H__
#define __STACK_H__

#include <cstdlib>
#include <cassert>

/**
* @class stack
* @author Wiwit Rifa'i (13513073)
* @version 1.0
* 
* @section Description
* @brief kelas stack adalah implementasi vector yang ekuivalen stack STL C++
**/
template< class T >
class stack {
  public:
    /**
    * @brief Konstruktor kelas stack.
    **/
    stack();
    /**
    * @brief Copy constructor kelas stack.
    * @param stack : yang akan di-copy.
    **/
    stack(const stack<T>& );
    /**
    * @brief Destruktor kelas stack.
    **/
    ~stack();
    /**
    * @brief Operator assignment kelas stack.
    * @param stack : yang akan di-copy.
    **/
    stack<T>& operator=(const stack<T>& );
    /**
    * @brief Mengembalikan predikat apakah stack kosong.
    * @return bool : predikat kosong stack. 
    **/
    bool empty();
    /**
    * @brief Mengembalikan ukuran stack.
    * @return int - ukuran stack.
    **/
    int size();
    /**
    * @brief Mengembalikan elemen teratas stack
    * @return reference class T : elemen teratas
    **/
    T& top();    
    /**
    * @brief Menambahkan item pada paling atas stack
    * @param class T : item yang akan ditambahkan
    **/
    void push(const T&);
    /**
    * @brief Menghapus item pada paling atas stack
    * @brief I. S. stack tidak kosong.
    **/
    void pop();
    
  private:
    /**
    * @class Stack_Elmt
    * @brief kelas Stack_Elmt bertanggung jawab pada satu buah elemen stack.
    * @brief kelas Stack_Elmt merupakan inner class dari kelas stack dan hanya bisa dipakai oleh stack.
    **/    
    class Stack_Elmt {
    public :
      /**
      * @brief Konstruktor kelas Stack_Elmt.
      * @param Stack_Elmt * _tnext - berisi address elemen selanjutnya ( default = NULL ).
      **/
      Stack_Elmt(Stack_Elmt * _tnext = NULL);
      /**
      * @brief Konstruktor kelas Stack_Elmt dengan parameter.
      * @param T _tval - nilai elemen yang akan diisi.
      * @param Stack_Elmt * _tnext - berisi address elemen selanjutnya ( default = NULL ).
      **/
      Stack_Elmt(const T& _tval, Stack_Elmt * _tnext = NULL);
      /**
      * @brief Copy Constructor kelas stack
      * @param Stack_Elmt& - yang akan di copy.
      **/
      Stack_Elmt(const Stack_Elmt& );
      /**
      * @brief Destruktor kelas stack
      **/
      ~Stack_Elmt();
      /**
      * @brief Operator assignment kelas stack
      * @param Stack_Elmt& - yang akan di copy.
      **/
      Stack_Elmt& operator=(const Stack_Elmt& li);

      Stack_Elmt * _next;   // address elemen berikutnya
      T _val;               // nilai elemen yang disimpan
    };
    
    Stack_Elmt * _top;
    int _size;
};


/***** Implementasi class Stack_Elmt *****/
template< class T >
stack<T>::Stack_Elmt::Stack_Elmt(Stack_Elmt * _tnext) {
  _next = NULL;
}
template< class T >
stack<T>::Stack_Elmt::Stack_Elmt(const T& _tval, Stack_Elmt * _tnext) {
  _val = _tval;
  _next = _tnext;
}
template< class T >
stack<T>::Stack_Elmt::Stack_Elmt(const Stack_Elmt& li) {
  _val = li._val;
  _next = li._next;
}
template< class T >
stack<T>::Stack_Elmt::~Stack_Elmt() {
}
template< class T >
typename stack<T>::Stack_Elmt& stack<T>::Stack_Elmt::operator=(const stack<T>::Stack_Elmt& li) {
  _val = li._val;
  _next = li._next;
  return *this;
}

/***** implementasi class stack *****/
template< class T >
stack<T>::stack() {
  _size = 0;
  _top = NULL;
}
template< class T >
stack<T>::stack(const stack<T>& S) {
  _size = S._size;
  Stack_Elmt * src_temp = S._top;
  if(src_temp != NULL) {
    Stack_Elmt * des_temp;
    des_temp = new Stack_Elmt(* src_temp);
    _top = des_temp;
    src_temp = src_temp->_next;
    while(src_temp != NULL) {
      des_temp->_next = new Stack_Elmt(* src_temp);
      des_temp = des_temp->_next;
      src_temp = src_temp->_next;
    }
  }
}
template< class T >
stack<T>::~stack() {
  /* Delete last stack */
  Stack_Elmt * del_temp;
  while(_top != NULL) {
    del_temp = _top;
    _top = _top->_next;
    delete del_temp;
  }
}
template< class T >
stack<T>& stack<T>::operator=(const stack<T>& S) {
  /* Delete last stack */
  Stack_Elmt * del_temp;
  while(_top != NULL) {
    del_temp = _top;
    _top = _top->_next;
    delete del_temp;
  }
  /* Copy from stack S */
  _size = S._size;
  Stack_Elmt * src_temp = S._top;
  if(src_temp != NULL) {
    Stack_Elmt * des_temp;
    des_temp = new Stack_Elmt(* src_temp);
    _top = des_temp;
    src_temp = src_temp->_next;
    while(src_temp != NULL) {
      des_temp->_next = new Stack_Elmt(* src_temp);
      des_temp = des_temp->_next;
      src_temp = src_temp->_next;
    }
  }
  return *this;
}
template< class T >
bool stack<T>::empty() {
  return _size == 0;
}
template< class T >
int stack<T>::size() {
  return _size;
}
template< class T >
T& stack<T>::top() {
  return _top->_val;
}
template< class T >
void stack<T>::push(const T& _new) {
  _top = new Stack_Elmt(_new, _top);
  _size++;
}
template< class T >
void stack<T>::pop() {
  assert(_top != NULL);
  Stack_Elmt * delTop = _top;
  _top = _top->_next;
  delete delTop;
  _size--;
}

#endif
