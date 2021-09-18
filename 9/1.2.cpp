#include<iostream>
#include<cmath>
using namespace std;

int main()
{

	setlocale(LC_ALL, "ru");

	int R;
	double x;
	double y;

	cout<<"Введите R :  " << endl;
	cin >> R;
	cout << "Введите x :  " << endl;
	cin >> x;
	cout << "Введите y :  " << endl;
	cin >> y;
	

	if (x>0 && y>0 )//Первая четверть 
	{
		if (x * x + y * y <= R *R )
		{
			cout<<"Точка не принадлежит области заданных значений" << endl;
		}
		else
		{
			cout << "Точка принадлежит области заданных значений" << endl;
		}
	}
	if (x<=0 && y<=0)//Третья четверть
	{
		if ( abs(x + y) <= 2*R)
		{
			
			cout<<"Точка принадлежит области заданных значений " << endl;

		}
		else
		{
			cout << "Точка не принадлежит области заданных значений" << endl;
		}
		
	}



	return 0;
}
