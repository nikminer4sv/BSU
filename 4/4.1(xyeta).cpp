#include <iostream>

using namespace std;

int main() {

    char *Array = new char[255];
    gets(Array);

    int Size = 0;
    while (Array[Size] != '\0') {

        Size++;

    }
    
    for (int i = 0; i < Size; i++) {

        int NumberOfRepeatingSymbols = 0;
        
        for (int j = i + 1; j < Size; j++) {

            if (Array[i] == Array[j]) {

                NumberOfRepeatingSymbols++;
                for (int k = j; k < Size; k++) {

                    Array[k] = Array[k + 1];

                }
            }
        }

        for (int k = i; k < Size; k++) {

            Array[k] = Array[k + NumberOfRepeatingSymbols];

        }
    }

    cout << Array;
    
}
