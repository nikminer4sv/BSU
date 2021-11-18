// 3.1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <cstdlib>//Генерация псевдослучайных чисел
#include <ctime>
using namespace std;

enum {
	INIT = 1,
	RAND = 2,
	INPUT = 3,
};

void max_sum(const int A[], int n) {
	int sum = 0, max = 0, j = 0, i = 0;
	for (int g = 0; g < n; g++) {
		for (int k = g; k < n; k++) {
			sum = sum + A[k];
			if (max < sum) {
				max = sum;
				i = g;
				j = k;
			}
		}
		sum = 0;
	}
	cout << "T(" << i + 1 << "," << j + 1 << ")" << endl;
	cout << endl << "Максимальная сумма отрезка равна: " << max << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i = 0, choice;
	cout << "Укажите желаемый тип инициализации. Введите '1' для задания во время описания," << endl; 
	cout << "'2' для присвоения рандомных значений, '3' для ввода собственных значений" << endl;
	cin >> choice;
	if (choice == INIT) 
	{
		int const n = 6;
		int A[n] = { 1, 2, 3, 4, 5, -1 };
		while (i < n)
		{
			cout << A[i] << " ";
			i++;
		}
		cout << endl;
		max_sum(A, 6);
	}
	else if (choice == RAND) 
	{
		cout << "Введите колличество элементов n: " << endl;
		cin >> n;
		if (n <= 0)
			cout << "Переменная n не может быть <=0 \n";
		int A[100];
		cout << "{ ";
		while (i < n) {
			srand(time(0) + i);
			A[i] = rand() % 100 + 1;
			cout << A[i] << ' ';
			i++;
		}
		cout << '}' << endl;
		max_sum(A, n);
	}
	else if (choice == INPUT) 
	{
		cout << "Введите колличество элементов n: " << endl;
		cin >> n;
		if (n <= 0)
			cout << "Переменная n не может быть <=0 \n";
		int A[100];
		cout << "Введите элементы массива:\n";
		while (i < n) {
			cin >> A[i];
			i++;
		}
		max_sum(A, n);
	}
	system("pause");
	return 0;
}

