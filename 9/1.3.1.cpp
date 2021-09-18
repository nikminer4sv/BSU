/*	Даны вещественные x1, x2, x3, x4. 
	Поменять значения переменных так,
	чтобы x1 > x2  >  x3 <  x4 .
*/
/*с использованием оператора if */


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;

	cout << "Введите переменную x1 :";
	cin >> x1;
	cout << "Введите переменную x2 :";
	cin >> x2;
	cout << "Введите переменную x3 :";
	cin >> x3;
	cout << "Введите переменную x4 :";
	cin >> x4;

	if (x2 < x3) swap(x2, x3);//swap меняет значение x2 и x3
	if (x3 > x4) swap(x3, x4);
	if (x1 < x2) swap(x1, x2);

	cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
	return 0;
}
