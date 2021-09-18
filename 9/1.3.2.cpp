/*	
	Даны вещественные x1, x2, x3, x4. 
	Поменять значения переменных так, 
	чтобы x1 > x2  >  x3 <  x4 .
*/

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	double x1, x2, x3, x4, a;

	cout << "Введите переменную x1 : ";
	cin >> x1;
	cout << "Введите переменную x2 : ";
	cin >> x2;
	cout << "Введите переменную x3 : ";
	cin >> x3;
	cout << "Введите переменную x4 : ";
	cin >> x4;

	x1 < x2 ? a = x1, x1 = x2, x2 = a : true;
	x2 < x3 ? a = x2, x2 = x3, x3 = a : true;
	x3 > x4 ? a = x3, x3 = x4, x4 = a : true;
	x1 < x4 ? a = x1, x1 = x4, x4 = a : true;

	cout << x1 << " > " << x2 << " > " << x3 << " < " << x4 << endl;



	return 0;
}
