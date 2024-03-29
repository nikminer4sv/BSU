#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    float a, b, c, t1 = 0, t2 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    cin >> a >> b >> c;
    if (!a && !b) {
        if (!c)
        {
            cout << "Корней бесконечно много";
        }
        else
        {
            cout << "Корней нет";
        }
    }
    else if (!a) {
        if ((b > 0 && c > 0) || (b < 0 && c < 0))
        {
            cout << "Корней нет";
        }
        else
        {
            x1 = sqrt(-c / b);
            cout << x1 << endl;
            x2 = -sqrt(-c / b);
            cout << x2 << endl;
        }
    }
    else if (!b) {
        if ((a > 0 && c > 0) || (a < 0 && c < 0))
        {
            cout << "Корней нет";
        }
        else
        {
            t1 = sqrt(-c / a);
            x1 = sqrt(t1);
            cout << x1 << endl;
            x2 = -sqrt(t1);
            cout << x2 << endl;
        }
    }
    else
    {
        float D = b * b - 4 * a * c;
        if (D > 0)
        {
            t1 = (-b + sqrt(D)) / (2 * a);
            t2 = (-b - sqrt(D)) / (2 * a);
        }
        else if (D == 0)
        {
            t1 = -b / (2 * a);
        }
        else if (D < 0)
        {
            cout << "Korney net" << endl;
        }
        if (t1 > 0)
        {
            x1 = sqrt(t1);
            cout << x1 << endl;
            x2 = -sqrt(t1);
            cout << x2 << endl;
        }
        if (t2 > 0)
        {
            x3 = sqrt(t2);
            cout << x3 << endl;
            x4 = -sqrt(t2);
            cout << x4 << endl;
        }
    }
}
