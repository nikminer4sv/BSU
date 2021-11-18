#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int x1, x2, x3, x4, y1, y2, y3, y4;

	cout<<"Введите (x1,y1): " << endl;
	cin >> x1 >> y1;
	cout << "Введите (x2,y2): " << endl;
	cin >> x2 >> y2;
	cout << "Введите (x3,y3): " << endl;
	cin >> x3 >> y3;
	cout << "Введите (x4,y4): " << endl;
	cin >> x4 >> y4;
	
	//min1 = x1 < x2 ? x1 : x2;


	if (min(x1, x2) > min(x3, x4) && max(x1, x2) < max(x3,x4) && min(y1, y2) > min(y3, y4) && max(y1, y2) < max(y3, y4))
	{
		cout<<"Прямоугольник 1 лежит внутри прямоугольника 2 " << endl;
	}
	else if (min(x1, x2) < min(x3, x4) && max(x1, x2) > max(x3, x4) && min(y1, y2) < min(y3, y4) && max(y1, y2) > max(y3, y4))
	{
		cout << "Прямоугольник 2 лежит внутри  прямоугольника 1 " << endl;
	}
	else
	{
		cout<<"Прямоугольник 1 и прямоугольник 2 не лежат в плоскостях друг друга " << endl;
	}

	//min(x1, x2) > min(x3, x4) && max(x1, x2) < max(x3, x4) && min(y1, y2) > min(y3, y4) && max(y1, y2) < max(y3, y4) ? cout << "Прямоугольник 1 лежит в плоскости прямоугольника 2 " << endl : min(x1, x2) < min(x3, x4) && max(x1, x2) > max(x3, x4) && min(y1, y2) < min(y3, y4) && max(y1, y2) > max(y3, y4) ? cout << "Прямоугольник 2 лежит в плоскости прямоугольника 1 " << endl : cout << "Прямоугольник 1 и прямоугольник 2 не лежат в плоскостях друг друга " << endl;

	return 0;
}

