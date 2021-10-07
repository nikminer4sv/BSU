#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Gorner(int i, double x, double Result) {

    if (i >= 1) {

        Result = i + Result * x * x;
        i -= 2;
        Gorner(i, x, Result);

    } else {

        return Result;

    }

}

int main() {

    int n;
    cin >> n;

    for (float x = 1; x <= 5; x += 0.5f) {

        int i = 1;
        double Operand = 0;
        double Result = 10;
        double Variable = x;
        
        do {

            Operand = i * Variable;
            Result += Operand;
            i += 2;
            Variable *= x * x;

        } while (i <= (2 * n - 1));

        cout << setw(9) << Result << " ";

        i = 2 * n - 1;
        Result = 0;

        Result = 10 + x * Gorner(i, x, Result);

        cout << setw(9) << Result << endl;
    }

}
