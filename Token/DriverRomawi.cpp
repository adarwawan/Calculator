#include <iostream>
#include "NumberRomawi.h"

using namespace std;

int main(){
	NumberRomawi N1("X");
	NumberRomawi N2("IX");

	cout << N1.toString((N1 * N2).getNilai()) << endl;
	cout << N1.toString((N1 + N2).getNilai()) << endl;
	cout << N1.toString((N1 - N2).getNilai()) << endl;
	cout << N1.toString((N1 / N2).getNilai()) << endl;
	cout << N1.toString((N1 % N2).getNilai()) << endl;
	
	return 0;
}