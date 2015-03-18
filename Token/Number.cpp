#include "Number.h"

  /**
  * @brief Konstruktor kelas Number.
  *
  **/
Number::Number(): Token("0"){
}
  /**
  * @brief Konstruktor kelas Number dengan parameter.
  * @param S - String yang akan menjadi nama file.
  **/
Number::Number(string s): Token(s) {
}
  /**
  * @brief Destruktor kelas Number.
  **/
Number::~Number() {
}
  /**
  * @brief operator= untuk menyamakan nilai dari Number n.
  * @param n - Number yang nilainya akan disamakan.
  * @return n' - Objek Number yang telah diassign dari n.
  **/	
Number& Number::operator= (Number& n) {
  _nilai = n._nilai;
  this->SetSymToken(n.GetSymToken());
}
  /**
  * @brief prosedur membandingkan nilai lebih kecil dengan nilai N
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 < L2.
  **/  
Logic& Number::operator< (const Number& N) {
 Logic& L = *(new Logic(_nilai < N._nilai));
 return L;
}
  /**
  * @brief prosedur membandingkan nilai lebih kecil sama dengan nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 <= L2.
  **/  
Logic& Number::operator<= (const Number& N) {
 Logic& L = *(new Logic(_nilai <= N._nilai));
 return L;
}
  /**
  * @brief prosedur membandingkan nilai lebih dari dengan nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 > L2.
  **/  
Logic& Number::operator> (const Number& N) {
 Logic& L = *(new Logic(_nilai > N._nilai));
 return L;
}
  /**
  * @brief prosedur membandingkan nilai lebih dari sama dengan _nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 >= L2.
  **/  
Logic& Number::operator>= (const Number& N) {
 Logic& L = *(new Logic(_nilai >= N._nilai));
 return L;
}
  /**
  * @brief prosedur membandingkan _nilai sama dengan _nilai N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 == L2.
  **/  
Logic& Number::operator== (const Number& N) {
 Logic& L = *(new Logic(_nilai == N._nilai));
 return L;
}
  /**
  * @brief prosedur membandingkan _nilai tidak sama dengan _nilai dari N.
  * @param N - Number yang nilainya akan dibandingkan.
  * @return L' = L1 != L2.
  **/  
Logic& Number::operator!= (const Number& N) {
 Logic& L = *(new Logic(_nilai != N._nilai));
 return L;
}
  /**
  * @brief prosedur mendapatkan _nilai.
  * @return i - integer dari _nilai
  **/  
int Number::getNilai(){
  return _nilai;
}
  /**
  * @brief prosedur assign _nilai
  * @param n - nilai yang nantinya akan di assign ke _nilai.
  **/
void Number::setNilai(int _n){
  _nilai = _n;
}