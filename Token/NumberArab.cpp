#include "NumberArab.h"

using namespace std;
  /**
  * @brief Konstruktor kelas NumberArab.
  *
  **/
NumberArab::NumberArab() {
	_nilai = 0;
}
  /**
  * @brief Konstruktor kelas NumberArab dengan parameter.
  * @param s - String yang akan menjadi parameter Number
  **/
NumberArab::NumberArab(string s): Number(s){
	_nilai = toInt(s);
}
  /**
  * @brief Konstruktor kelas NumberArab dengan parameter.
  * @param _n - integer yang akan di assign ke _nilai
  **/
NumberArab::NumberArab(int _n): Number(toString(_n)){
	_nilai = _n;
}
   /**
  * @brief Destruktor kelas NumberArab.
  **/
NumberArab::~NumberArab(){

}
  /**
  * @brief operator* untuk mengali nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikali.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberArab::operator* (const Number& N){
	Number& N1 = *(new NumberArab(_nilai * N._nilai));
	return N1;
}
  /**
  * @brief operator+ untuk menambahkan nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan ditambah.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberArab::operator+ (const Number& N){
	Number& N1 = *(new NumberArab(_nilai + N._nilai));
	return N1;
}
  /**
  * @brief operator- untuk mengurangi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikurang.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberArab::operator- (const Number& N){
	Number& N1 = *(new NumberArab(_nilai - N._nilai));
	return N1;
}
  /**
  * @brief operator/ untuk membagi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dibagi.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberArab::operator/ (const Number& N){
	Number& N1 = *(new NumberArab(_nilai / N._nilai));
	return N1;
}
  /**
  * @brief operator% untuk modulo nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya menjadi modulator.
  **/
Number& NumberArab::operator% (const Number& N){
  /* Sesuai Euclidean Definition nilai modulo selalu lebih besar atau sama dengan nol */
	Number& N1 = *(new NumberArab(((_nilai % N._nilai)+N._nilai) % N._nilai));
	return N1;
}
  /**
  * @brief fungsi yang merubah string menjadi integer
  * @param s - string yang nantinya akan dirubah menjadi integer.
  * @return i - integer dari string n.
  **/  
int NumberArab::toInt(string s){
	int nilai = 0, i = 0;
  if(s[0] == '-')
    i++;
  for(; i<s.length(); i++)
    nilai = nilai*10 + s[i] - '0';
  if(s[0] == '-')
    nilai *= -1;
	return nilai;
}
  /**
  * @brief fungsi yang merubah integer menjadi string
  * @param n - nilai yang nantinya akan dirubah menjadi string.
  * @return s - string dari integer n.
  **/
string NumberArab::toString(int n) {
  string ret;
  int x = n;
  if(x < 0) {
    ret.push_back('-');
    x *= -1;
  }
  if(x < 10) {
    ret.push_back('0'+x);
    return ret;
  }
  stack<char> temp;
  while(x>0) {
    temp.push((x % 10)+'0');
    x /= 10;
  }
  while(!temp.empty()) {
    ret.push_back(temp.top());
    temp.pop();
  }
  return ret;
}