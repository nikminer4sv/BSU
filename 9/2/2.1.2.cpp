//Верно ли, что первые n цифр дробной части заданного положительного вещественного числа различны ?

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	double Number;//число
	int n, temp;//temp - следующее число (Number*10 - целая часть )
	cout << "Верно ли, что первые n цифр дробной части заданного положительного вещественного числа различны?" << endl;

	cin >> Number;//дробное число 
	cin >> n;//количество цифр для проверки 

	Number = Number - (int)Number;

	bool flag = false;

	for (int i = 1; i < n + 1; i++) {

		double temp = Number;

		for (int p = 0; p < i - 1; p++) {
			temp = temp * 10 - int(temp * 10);
		}

		temp = int(temp * 10);

		for (int j = i + 1; j < n + 1; j++) {

			double temp2 = Number;

			for (int p = 0; p < j - 1; p++) {
				temp2 = temp2 * 10 - int(temp2 * 10);
			}

			temp2 = int(temp2 * 10);

			if (temp == temp2) {
				flag = true;
				break;
			}

		}

		if (flag)
			break;

	}

	if (flag = false)
		cout << "Different(верно , они различны)" << endl;
	else
		cout << "Not different(не верно , они не различны )" << endl;

	system("pause");


}
