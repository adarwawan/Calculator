#include <iostream>
#include "NumberArab.h"

using namespace std;

int main(){
	NumberArab N1(5);
	NumberArab N2(4);
	
	cout << N1.toString((N1 * N2).getNilai()) << endl;
	cout << N1.toString((N1 + N2).getNilai()) << endl;
	cout << N1.toString((N1 - N2).getNilai()) << endl;
	cout << N1.toString((N1 / N2).getNilai()) << endl;
	cout << N1.toString((N1 % N2).getNilai()) << endl;
	
	return 0;
}