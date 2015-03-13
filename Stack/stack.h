#include <cstdlib>
#include <cassert>

template< class T >
class list {
  public:
    list();
    list(T _tval);
    list(T _tval, list<T> * _tnext);
    list(list<T>& );
    ~list();
    list<T> * GetNext();
    void SetNext(list<T> * _tnext);
    T& GetVal();
    void SetVal(T _tval);
  private:
    list<T> * _next;
    T _val;
};


template< class T >
class stack {
  public:
    stack();
    stack(stack<T>& );
    ~stack();
    stack<T>& operator=(stack<T>& );
    
    bool empty();
    int size();
    T& top();
    void push(T);
    void pop();
    
  private:
    list<T> * _top;
    int _size;
};

/***** Implementasi class list *****/
template< class T >
list<T>::list() {
  _next = NULL;
}
template< class T >
list<T>::list(T _tval) {
  _val = _tval;
  _next = NULL;
}
template< class T >
list<T>::list(T _tval, list<T> * _tnext) {
  _val = _tval;
  _next = _tnext;
}
template< class T >
list<T>::list(list<T>& li) {
  _val = li._val;
  _next = li._next;
}
template< class T >
list<T>::~list() {
}
template< class T >
list<T> * list<T>::GetNext() {
  return _next;
}
template< class T >
void list<T>::SetNext(list<T> * _tnext) {
  _next = _tnext;
}
template< class T >
T& list<T>::GetVal() {
  return _val;
}
template< class T >
void list<T>::SetVal(T _tval) {
  _val = _tval;
}

/***** implementasi class stack *****/
template< class T >
stack<T>::stack() {
  _size = 0;
  _top = NULL;
}
template< class T >
stack<T>::stack(stack<T>& S) {
  _size = S._size;
  list<T> * src_temp = S._top;
  if(src_temp != NULL) {
    list<T> * des_temp;
    des_temp = new list<T>(* src_temp);
    _top = des_temp;
    src_temp = src_temp->GetNext();
    while(src_temp != NULL) {
      des_temp->SetNext(new list<T>(* src_temp));
      des_temp = des_temp->GetNext();
      src_temp = src_temp->GetNext();
    }
  }
}
template< class T >
stack<T>::~stack() {
  /* Delete last stack */
  list<T> * del_temp;
  while(_top != NULL) {
    del_temp = _top;
    _top = _top->GetNext();
    delete del_temp;
  }  
}
template< class T >
stack<T>& stack<T>::operator=(stack<T>& S) {
  /* Delete last stack */
  list<T> * del_temp;
  while(_top != NULL) {
    del_temp = _top;
    _top = _top->GetNext();
    delete del_temp;
  }
  /* Copy from stack S */
  _size = S._size;
  list<T> * src_temp = S._top;
  if(src_temp != NULL) {
    list<T> * des_temp;
    des_temp = new list<T>(* src_temp);
    _top = des_temp;
    src_temp = src_temp->GetNext();
    while(src_temp != NULL) {
      des_temp->SetNext(new list<T>(* src_temp));
      des_temp = des_temp->GetNext();
      src_temp = src_temp->GetNext();
    }
  }
  return S;
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
  return _top->GetVal();
}
template< class T >
void stack<T>::push(T _new) {
  _top = new list<T>(_new, _top);
  _size++;
}
template< class T >
void stack<T>::pop() {
  assert(_top != NULL);
  list<T> * delTop = _top;
  _top = _top->GetNext();
  delete delTop;
  _size--;
}
