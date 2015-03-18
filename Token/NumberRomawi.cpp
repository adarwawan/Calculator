#include "NumberRomawi.h"

using namespace std;
  /**
  * @brief Konstruktor kelas NumberRomawi.
  *
  **/
NumberRomawi::NumberRomawi() : Number("X") {
	_nilai = 1;
}
  /**
  * @brief Konstruktor kelas Number dengan parameter.
  * @param s - String yang akan menjadi parameter Number.
  **/
NumberRomawi::NumberRomawi(string s): Number(s){
	_nilai = toInt(s);
}
  /**
  * @brief Konstruktor kelas Number dengan parameter.
  * @param _n - integer yang akan di assign ke _nilai
  **/
NumberRomawi::NumberRomawi(int _n) : Number(toString(_n)) {
	_nilai = _n;
}
  /**
  * @brief Destruktor kelas NumberRomawi.
  **/
NumberRomawi::~NumberRomawi(){

}
  /**
  * @brief operator* untuk mengali nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikali.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberRomawi::operator* (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai * N._nilai));
	return N1;
}
  /**
  * @brief operator+ untuk menambahkan nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan ditambah.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberRomawi::operator+ (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai + N._nilai));
	return N1;
}
  /**
  * @brief operator- untuk mengurangi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dikurang.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberRomawi::operator- (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai - N._nilai));
	return N1;
}
  /**
  * @brief operator/ untuk membagi nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya akan dibagi.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberRomawi::operator/ (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai / N._nilai));
	return N1;
}
  /**
  * @brief operator% untuk modulo nilai objek dengan nilai dari Number n.
  * @param n - Number yang nilainya menjadi modulator.
  * @return n' - Objek Number yang telah diassign dari n.
  **/
Number& NumberRomawi::operator% (const Number& N){
  /* Sesuai Euclidean Definition nilai modulo selalu lebih besar atau sama dengan nol */
	Number& N1 = *(new NumberRomawi(((_nilai % N._nilai)+N._nilai) % N._nilai));
	return N1;
}
  /**
  * @brief fungsi yang merubah string menjadi integer
  * @param s - string yang nantinya akan dirubah menjadi integer.
  * @return i - integer dari string n.
  **/    
int NumberRomawi::toInt(string s){
	int satuan = 0;
	int puluhan = 0;
	int ratusan = 0;
	int ribuan = 0;
	for (int i = 0; i <= s.length() - 1; i++){
		if (s[i] == 'I'){
			if(i<s.length() - 1 && (s[i+1] == 'X' || s[i+1] == 'V')){
			
			}
			else satuan++;
		}
		if (s[i] == 'V'){
			if (s[i-1] == 'I') satuan += 4;
			else satuan += 5;
		}
		if (s[i] == 'X'){
			if(s[i-1] == 'I') puluhan+=9;
			else if(i<s.length() - 1 && (s[i+1] == 'L' || s[i+1] == 'C')){
			
			}
			else puluhan+=10;
		}
		if (s[i] == 'L'){
			if(s[i-1] == 'X') puluhan+=40;
			else puluhan+=50;
		}
		if (s[i] == 'C'){
			if(s[i-1] == 'X') ratusan+=90;
			else if(i<s.length() - 1 && (s[i+1] == 'D' || s[i+1] == 'M')){
			
			}
			else ratusan+=100;
		}
		if (s[i] == 'D'){
			if(s[i-1] == 'C') ratusan += 400;
			else ratusan += 500;
		}
		if (s[i] == 'M'){
			if(s[i-1] == 'C') ribuan+=900;
			else ribuan+=1000;
		}
	}
	int nilai = ribuan + ratusan + puluhan + satuan;
	return nilai;
}
  /**
  * @brief fungsi yang merubah integer menjadi string
  * @param n - nilai yang nantinya akan dirubah menjadi string.
  * @return s - string dari integer n.
  **/
string NumberRomawi::toString(int n) {
  char rom[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M', '#', '#'};
  string ret;
  int x = n, y, z = 1000;
  for(int i = 6; i>=0; i -= 2) {
    y = x/z;
    x %= z;
    z /= 10;
    switch(y) {
      case 3 : ret.push_back(rom[i]);
      case 2 : ret.push_back(rom[i]);
      case 1 : ret.push_back(rom[i]);
               break;
      case 4 : ret.push_back(rom[i]);
      case 5 : ret.push_back(rom[i+1]);
               break;
      case 6 : ret.push_back(rom[i+1]);
               ret.push_back(rom[i]);
               break;
      case 7 : ret.push_back(rom[i+1]);
               ret.push_back(rom[i]);
               ret.push_back(rom[i]);
               break;
      case 8 : ret.push_back(rom[i+1]);
               ret.push_back(rom[i]);
               ret.push_back(rom[i]);
               ret.push_back(rom[i]);
               break;
      case 9 : ret.push_back(rom[i]);
               ret.push_back(rom[i+2]);
    }
  }
  return ret;
}