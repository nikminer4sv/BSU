#include <iostream>
#include <time.h>
#include "SimpleSort.cpp"
#include "BinarySort.cpp"

enum InitializationType {

    DESCENDING_INITIALIZATION = 1,
	ASCENDING_INITIALIZATION = 2,
    RANDOM_INITIALIZATION = 3,

};

void DescendingInitialization(int Array[], int N);
void AscendingInitialization(int Array[], int N);
void RandomInitialization(int Array[], int N);

int main() {
	
	srand(time(NULL));

    int N, M, ChoiceInt;

    cout << "Choose initialization mode:\n"
            "1.Descending initialization\n"
			"2.Ascending initialization\n"
            "3.Random initializatin\n"
            "Choice is: ";
    cin >> ChoiceInt;

    cout << "Input size of array: ";
    cin >> N;

	InitializationType UserChoice = static_cast<InitializationType>(ChoiceInt);

	int Array[N];

	switch (UserChoice) {

        case DESCENDING_INITIALIZATION:
			DescendingInitialization(Array, N);
            SimpleSort(Array, N);
			BinarySort(Array, N);
            break;

		case ASCENDING_INITIALIZATION:
			AscendingInitialization(Array, N);
            SimpleSort(Array, N);
			BinarySort(Array, N);
            break;

        case RANDOM_INITIALIZATION:
			RandomInitialization(Array, N);
            SimpleSort(Array, N);
			BinarySort(Array, N);
            break;

    }

}

void DescendingInitialization(int Array[], int N) {

	int Number = N * 10;

    for (int i = 0; i < N; i++){
        Array[i] = Number - (rand() % 10 + 1);
		Number = Array[i];
        cout << Array[i] << " ";
    }

    cout << endl;

}

void AscendingInitialization(int Array[], int N) {

    int Number = 0;

    for (int i = 0; i < N; i++){
        Array[i] = Number + (rand() % 10 + 1);
		Number = Array[i];
        cout << Array[i] << " ";
    }

    cout << endl;

}

void RandomInitialization(int Array[], int N) {

    for (int i = 0; i < N; i++){
        Array[i] = rand() % (10 * N) + 1;
        cout << Array[i] << " ";
    }

    cout << endl;

}