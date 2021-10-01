#include <iostream>

using namespace std;

int main() {

    int Size = 0, i = 0;
    cin >> Size;

    char C[Size];
    cin >> C;

    for (int j = 0; j < Size; j++) {

        int a = 0;
        for (int k = j + 1; k < Size; k++) {

            if (C[j] == C[k]) {

                C[k] = ' ';
                a++;

            }
        }

        if (a) {

            C[j] = ' ';

        }
    }

    for (int i = 0; i < Size; ++i) {

        if (C[i] == ' ') {
            
            for (int j = 0; j < Size; j++) {

                C[j] = C[j + 1];

            }
            
            i--;

        }
    }

    cout << C;
    
}
