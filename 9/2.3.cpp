#include <iostream>
#include <math.h>//библиотека 

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int b, c, d;// a - наше число
	int x0, x1, x2, x3, x4, x5;
	//bool change0, change1, change2, change3, change4, change5;// переменные типа bool могут быть только true или false(ложь или правда)

	cout << "Все трехзначные сверхпростые числа:" << endl;

	for (int a = 100; a < 1000; a++)//число от 100 до 999
	{
		int x = a;
		bool change = true;

		//наше число = 100*b + 10*c + d

		b = x % 10;// последняя цифра числа . Например: 123 % 10 = 3 (остаток от деления на 100)
		x /= 10;// две первые цифры . Например: 123 / 10 = 12
		c = x % 10;//последняя цифра предыдущей переменной . Например : 12 % 10 = 2
		x /= 10;// 12 / 10 = 1 (первая цифра новой перменной )
		d = x % 10;// последняя цифра . Например : 1 % 10 = 1

		x0 = (b * 100 + c * 10 + d);//нулевая перестановка числа (123) = 123
		x1 = (b * 100 + d * 10 + c);//первая перестановка числа (123) = 132
		x2 = (c * 100 + d * 10 + b);//вторая перестановка числа (123) = 231
		x3 = (c * 100 + b * 10 + d);//третья перестановка числа (123) = 213
		x4 = (d * 100 + c * 10 + b);//четвёртая перестановка числа (123) = 321
		x5 = (d * 100 + b * 10 + c);//пятая перестановка числа (123) = 312

		//где k(n) - делитель ; n - номер перестановки

		for (int k = 2; k < x0 / 2; k++)
		{
			if (x0 % k == 0)
			{
				change = false;
				continue;
			}
			
		}
		for (int k = 2; k < x1 / 2; k++)
		{
			if (x1 % k == 0)//если наше число делиться на какоe-то число k(n) (< x(n)) без остатка , то это число нам автоматически не подходит 
			{
				change = false;
				continue;
			}

		}
		for (int k = 2; k < x2 / 2; k++)
		{
			if (x2 % k == 0)
			{
				change = false;
				continue;
			}
		}
		for (int k = 2; k < x3 / 2; k++)
		{
			if (x3 % k == 0)
			{
				change = false;
				continue;
			}
		}
		for (int k = 2; k < x4 / 2; k++)
		{
			if (x4 % k == 0)
			{
				change = false;
				continue;
			}
		}
		for (int k = 2; k < x5 / 2; k++)
		{
			if (x5 % k == 0)
			{
				change = false;
				continue;
			}
		}
		if (change == true)
			cout << a << endl;

	}
	return 0;
}

