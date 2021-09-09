#include <iostream>
#include <cmath>

using namespace std;

double Equation(float x, int s, int t)
{
    float y = atan(pow(x, 1.0 / t)) / (pow(x, 2) + s * sin(log10(x)));
    return y;
}

int main()
{
    float x;
    int s, t;
    system("cls");
    cin >> x >> s >> t;
    if (x > 0 && t > 0 && (pow(x, 2) + s * sin(log10(x))) != 0)
    {
        cout << Equation(x, s, t);
    }
}
