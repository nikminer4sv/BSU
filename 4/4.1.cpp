#include <iostream>

using namespace std;

int main() {

    char Array[255] = {'\0'};
    int Size = 0;
    cin.getline(Array, 255);

    while (Array[Size] != '\0') 
        Size++;

    for (int i = 0; i < Size; i++) {
        
        bool a = false;

        for (int j = 0; j < Size; j++) {

            for (int k = j + 1; k < Size; k++) {

                if (Array[j] == Array[k]) {

                    for (int l = k; l < Size; l++) {

                        Array[l] = Array[l + 1];

                        a = true;

                    }

                    //cout << Array << endl;

                    Size--;

                }

            }

            if(a) {

                for (int l = j; l < Size; l++) {

                    Array[l] = Array[l + 1];

                }

                Size--;

                break;

            }

        }

    }

    cout << Array;
    
}
