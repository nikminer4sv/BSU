/*Поле шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит 8: первое – номер вертикали,
второе – номер горизонтали.
Заданы натуральные числа k, l, m, n. 
Определить, бьет ли одна фигура другую.
Если же фигуры не угрожают друг другу,
выяснить, возможен ли ход какой-либо фигуры, 
после которого одна из фигур бьет другую.

9. На поле (k, l) стоит ферзь, на поле (m, n) – слон.

*/

#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");


	int QueenX, QueenY, SlonX, SlonY;

	cout<<"Введите координаты Ферзя : " << endl<<endl;

	cout << "Введите QueenX (координата ферзя по оси ОХ): " << endl << endl;
	cin >> QueenX;
	cout << "Введите QueenY (координата ферзя по оси ОY): " << endl << endl;
	cin >> QueenY;
	cout << endl;

	cout << "Введите координаты Слона : " << endl<<endl;

	cout << "Введите SlonX (координата слона по оси ОХ): " << endl<<endl;
	cin >> SlonX;
	cout << "Введите SlonY (координата слона по оси ОY): " << endl << endl;
	cin >> SlonY;
	cout << endl;

	if (QueenX <= 8 && QueenY <= 8 && SlonX <=8 && SlonY <= 8)
	{
		if (QueenX == SlonX)
		{
			cout<<"Ферзь бьёт Слона по вертикали  " << endl<<endl;
		}
		/*else
		{
			cout << "Ферзь не бъет по вертикали " << endl<<endl;
		}*/

		if (QueenY == SlonY)
		{
			cout << "Ферзь бьёт Слона по горизонтали  " << endl<<endl;
		}

		/*else
		{
			cout << "Ферзь не бъет по горизонтали" << endl<<endl;
		}*/
		
		if (abs(SlonX - QueenX) == abs(SlonY - QueenY))
		{
			cout<<"Ферзь бьёт Слона по диагонали" << endl << endl;
			
		}
		if(QueenX != SlonX && QueenY != SlonY && abs(SlonX - QueenX) != abs(SlonY - QueenY))
		{
			cout<<"С первого хода фигуры не угражают друг другу" << endl << endl;
		}
		

		cout << "За два хода ферзь сможет попасть в любую точку нашей доски!" << endl<<endl;
	}

	else
	{
		
		cout<<"Одни из ваших координаты больше 8 по вертикали или горизонтали " << endl << endl;
		cout << "В следующий раз введите от 1 до 8" << endl;
	}

	/*if (QueenX == SlonX || QueenY == SlonX)
	{
		cout << "Ферзь бьёт слона на первом ходу " << endl;
	}
	else
	{
		cout << "Ферзь бьёт слона на следующем ходу " << endl;
	}

	if (abs(SlonX - QueenX) == abs(SlonY - QueenY))
	{
		cout<<"Слон бьёт Ферзя на первом ходу" << endl;
	}
	else
	{
		cout<<"Слон не бьёт Ферзя на первом ходу" << endl;
	}*/

	return 0;
}
