#include "Number.h"


Number::Number(): Token("0"){
}
Number::Number(string s): Token(s) {
}
Number::~Number() {
}
Number& Number::operator= (Number& n) {
  _nilai = n._nilai;
  this->SetSymToken(n.GetSymToken());
}


Logic& Number::operator< (const Number& N) {
 Logic& L = *(new Logic(_nilai < N._nilai));
 return L;
}
Logic& Number::operator<= (const Number& N) {
 Logic& L = *(new Logic(_nilai <= N._nilai));
 return L;
}
Logic& Number::operator> (const Number& N) {
 Logic& L = *(new Logic(_nilai > N._nilai));
 return L;
}
Logic& Number::operator>= (const Number& N) {
 Logic& L = *(new Logic(_nilai >= N._nilai));
 return L;
}
Logic& Number::operator== (const Number& N) {
 Logic& L = *(new Logic(_nilai == N._nilai));
 return L;
}
Logic& Number::operator!= (const Number& N) {
 Logic& L = *(new Logic(_nilai != N._nilai));
 return L;
}


int Number::getNilai(){
  return _nilai;
}
void Number::setNilai(int _n){
  _nilai = _n;
}