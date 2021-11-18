/*Составить программу вычисления значений функции в точках хi [х0; хn], хi = х0 + iх, i = 0, 1, …,
воспользовавшись формулами разложения элементарных функций в ряд Тейлора 
с точностью  = 10–6.Вывести на экран необходимое количество слагаемых в каждом случае.
Сравнить результаты со значениями функции в этих точках, вычисленных с помощью встроенных функций системы программирования.*/

#include <cmath>
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");// русский язык

	double e = 1e-6, x0 = -0.6, xn = 0.8, dx = 0.1;//double - вещественные числа (числа с плавающей точкой)

	cout << setw(5) << "x" << setw(12) << "y" << setw(12) << "Sum" << setw(5) << "n" << endl;
	for (double x = x0; x <= xn; x += dx)//цикл начинается с х0= -0.6 и работает до того момента ,когда xn =0/8
	{
		

		double y = (1.0 / pow((1 + x), 3)) - 1;

		

		double Slg = 0.0, Sum = 0.0;//обьявление переменных вещественного типа 
		int p = 2, i = 1;

		double px = -x;
		do
		{
			Slg = px * p * (p + 1) / 2;
			Sum += Slg;
			px *= -x;
			p++;
			i++;
		} while (fabs(Slg) > e);

		
		

		double df = fabs(y - Sum);//переменная разности y и Sum 

		/*if (df <= 1e-6)//если разность больше 10 в минус 6 ,то 
			cout << "";
		else
			cout << "\tНе ";
			*/
		

		cout << setw(5) << x << setw(12) << y << setw(12) << Sum << setw(5) << i + 1 << endl;
	}
	return 0;
}
