#include <iostream>
#include <cmath>

using namespace std;

long long Factorial(int x) {
    long long sum = 1;
    if (x > 0)
    {
        for (int i = 1; i <= x; i++)
        {
            sum *= i;
        }
    }
    return sum;
}

int main()
{
    int x0 = -2, xn = 2;
    double dx = 0.2, xi = x0, y;
    for (int i = 1; xi <= xn; i++)
    {
        cout << xi << " ";
        y = exp(-xi) - 1;
        cout << y << endl;
        xi = (x0 + i * dx);
    }

    cout << "\n\n----------------------------------------------\n\n\n";

    for (float x = -2; x <= 2.2; x += 0.2f) {

        int FactorialCounter = 1;
        double Result = 0;
        short Sight = -1;

        double OperandTemp;

        if (x < -0.1 || x > 0.1)
        {
            do {

            double Operand;
            Operand = Sight * (double(pow(x, FactorialCounter) / Factorial(FactorialCounter)));
            Sight *= -1;
            FactorialCounter++;
            Result += Operand;
            OperandTemp = Operand;

            } while (abs(OperandTemp) > pow(10, -6));
        } else
        {
            x = 0;
            Result = 0;
        }
        cout << x << " " << Result << endl;
    }
}