#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double y;
    for (float x = -2; x < (2 + 0.1); x += 0.2f) {

        long long Delit = 1;
        double Delim = 1;
        int Counter = 1;
        double Result = 0;
        short Sight = -1;
        double const p = 1e-6;

        double OperandTemp;

        y = exp(-x) - 1;

        if (x < -0.1 || x > 0.1)
        {
            do {

            double Operand;
            Delim *= x;
            Delit *= Counter;
            Operand = Sight * (double(Delim / Delit));
            Sight = -Sight;
            Counter++;
            Result += Operand;
            OperandTemp = Operand;

            } while (abs(OperandTemp) > p);
        }else
        {
            x = 0;
            y = 0;
        }
        cout  << "x = " << setw(9) <<  x << setw(12) << y << setw(12) << Result << endl;
    }
}
