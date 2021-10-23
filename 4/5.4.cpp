#include <iostream>
#include "Delete.cpp"

using namespace std;

int main() {

	system("cls");

	char Array[255] = {'\0'};
    int Size = 0;
    gets(Array);

    while (Array[Size] != '\0') 
        Size++;

	for (int i = 0; i < Size; i++) {

		int length = 1;

		if (Array[i] == Array[i + length]) {

			while (Array[i] = Array[i + length]) {

				length++;

			}

			Delete(Array, i, length);
			
		}	

	}

	cout << Array;

}