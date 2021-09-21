#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (float x = 1; x < (5 + 0.25); x += 0.5f) {

        int i = 1;
        double Operand = 0;
        long long Result = 10;
        double Variable = x;
        
        do {
            //cout << "x : " << x;
            Operand = i * Variable;
            //cout << " Operand : " << Operand;
            Result += Operand;
            //cout << " Result : " << Result;
            i += 2;
            //cout << " i : " << i;
            Variable *= x * x;
            //cout << " Variable : " << Variable << endl;
        } while (i <= (2 * n - 1));

        cout << Result << endl;

    }

}
