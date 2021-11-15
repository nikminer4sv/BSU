#include <iostream>
#include <iomanip>

using namespace std;

double Function1(double x, int &Counter) {

    Counter = 1;
    long long Delit = 1;
    double Delim = x / 2;
    double Result = 0;
    short Sight = -1;
    double const p = 1e-6;
    double OperandTemp;

    do {

        double Operand;
        Delim *= (x / 2) * (x / 2);
        Delit *= Counter * (Counter + 1);
        Operand = Sight * (double(Delim / Delit));
        Sight = -Sight;
        Counter++;
        Result += Operand;
        OperandTemp = Operand;

    } while (abs(OperandTemp) > p);

    return Result;

}

void Function2(double x, double *Result2) {

    int Counter = 1;
    long long Delit = 1;
    double Delim = x / 2;
    short Sight = -1;
    double const p = 1e-6;
    double OperandTemp;

    do {

        double Operand;
        Delim *= (x / 2) * (x / 2);
        Delit *= Counter * (Counter + 1);
        Operand = Sight * (double(Delim / Delit));
        Sight = -Sight;
        Counter++;
        *Result2 += Operand;
        OperandTemp = Operand;

    } while (abs(OperandTemp) > p);

}

void Function3(double x, double &Result3) {

    int Counter = 1;
    long long Delit = 1;
    double Delim = x / 2;
    short Sight = -1;
    double const p = 1e-6;
    double OperandTemp;

    do {

        double Operand;
        Delim *= (x / 2) * (x / 2);
        Delit *= Counter * (Counter + 1);
        Operand = Sight * (double(Delim / Delit));
        Sight = -Sight;
        Counter++;
        Result3 += Operand;
        OperandTemp = Operand;

    } while (abs(OperandTemp) > p);

}

int main() {
		double x, Result2 = 0, Result3 = 0;
		cin >> x;

        int Counter;
		double Result1 = Function1(x, Counter);
        Function2(x, &Result2);
        Function3(x, Result3);

        cout  << "x = " 
        << setw(1) << x << "\n"
        << setw(11) << Result1 << "\n"
        << setw(11) << Result2 << "\n"
        << setw(11) << Result3 << "\n"
        << Counter << endl;
}
