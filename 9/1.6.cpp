#include <iostream>

using namespace std;

int main() {

	signed int Number;
	int Bit1, Bit2, Bit3;
	cin >> Number;

	Bit1 = (Number >> 0) & 1;
	Bit2 = (Number >> 3) & 1;
	Bit3 = (Number >> 15) & 1;

	cout << Bit1 << " " << Bit2 << " " << Bit3 << endl;

	for (int i = 31; i > -1; i--)
        	cout << ((Number >> i) & 1);

	cout << endl;

	Number = Number ^ 1 << 1;
	Number = Number ^ 1 << 7;

	for (int i = 31; i > -1; i--) 
		cout << ((Number >> i) & 1);

}

