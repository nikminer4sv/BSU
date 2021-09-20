#include <iostream>
#include <cmath>

using namespace std;

int main() {

	unsigned short x, z;
	signed char x1, x2, x3;

	cout << "Enter value: ";
	cin >> x;
	
    x1 = (x & 1 == 1);
    x2 = (x & 8 == 8);
    x3 = (x & 8192 == 8192);

	int i = 15;
	int j = 0;
	int value = 0;

    cout << endl;
	cout << "V dvoichnoy: " << endl;
	while (j < 16)
	{
		value = pow(2, i);
		if (x & value)
		{
			cout << "1 ";
		}
		else
			cout << "0 ";
		j++;
		i--;
	}
    j = 0;
	i = 15;

	cout << endl;

	z = x ^ 130;

	cout << endl;
	cout << "Bity: " << endl;
	cout << (int)(x1) << " " << (int)(x2) << " " << (int)(x3) << endl;
	cout << endl;

	cout << "Do inv.: " << endl;
	cout << x << endl << endl;
	cout << "Posle inv.: " << endl;
	cout << z << endl;
	cout << endl;
	cout << "V dvoichnoy: " << endl;
	while (j < 16)
	{
		value = pow(2, i);
		if (z & value)
		{
			cout << "1 ";
		}
		else
			cout << "0 ";
		j++;
		i--;
	}
	cout << endl;
	return 0;
}
