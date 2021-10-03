#include <iostream>
#include <iomanip>

using namespace std;

int main() {
		double x;

		cin >> x;

		int Counter = 1;
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

        cout  << "x = " << setw(1) << x << setw(12) << Result << setw(3) << Counter << endl;
}
