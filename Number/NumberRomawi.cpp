#include "NumberRomawi.h"

using namespace std;

NumberRomawi::NumberRomawi() : Number("X") {
	_nilai = 1;
}

NumberRomawi::NumberRomawi(string s): Number(s){
	_nilai = toInt(s);
}

NumberRomawi::NumberRomawi(int _n) : Number(toString(_n)) {
	_nilai = _n;
}

NumberRomawi::~NumberRomawi(){

}

Number& NumberRomawi::operator* (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai * N._nilai));
	return N1;
}

Number& NumberRomawi::operator+ (const Number& N){
  /* Sesuai Euclidean Definition nilai modulo selalu lebih besar atau sama dengan nol */
	Number& N1 = *(new NumberRomawi(((_nilai % N._nilai)+N._nilai) % N._nilai));
	return N1;
}

Number& NumberRomawi::operator- (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai - N._nilai));
	return N1;
}

Number& NumberRomawi::operator/ (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai / N._nilai));
	return N1;
}

Number& NumberRomawi::operator% (const Number& N){
	Number& N1 = *(new NumberRomawi(_nilai % N._nilai));
	return N1;
}

bool NumberRomawi::operator< (const Number& N){
	return (_nilai < N._nilai);
}

bool NumberRomawi::operator== (const Number& N){
	return (_nilai == N._nilai);
}

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
      case 9 : ret.push_back(rom[i+2]);
               ret.push_back(rom[i]);
    }
  }
  return ret;
}