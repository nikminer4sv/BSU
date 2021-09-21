#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum InitializationType {

    EXACT_INITIALIZATION = 1,
    RANDOM_INITIALIZATION = 2,

};

void Swap(int *a, int *b);
int Partition (int Array[], int Low, int High);
void QuickSort(int Array[], int Low, int High);
void PrintArray(int arr[], int size);
void ExactInitialization(int Array[], int N, int ArrayNumber);
void RandomInitialization(int Array[], int N, int ArrayNumber);
int* GetCrossingArray(int A[], int N, int B[], int M);

int main() {

    srand(time(NULL));

    int N, M, ChoiceInt;

    cout << "Choose initialization mode:\n"
            "1.Exact initialization\n"
            "2.Random initializatin\n"
            "Choice is: ";
    cin >> ChoiceInt;

    cout << "Input sizes of arrays: ";
    cin >> N >> M;

    InitializationType UserChoice = static_cast<InitializationType>(ChoiceInt);
    int *A = new int[N];
    int *B = new int[M];
    int *CrossingArray;

    switch (UserChoice) {

        case EXACT_INITIALIZATION:
            ExactInitialization(A, N, 1);
            ExactInitialization(B, M, 2);
            QuickSort(A, 0, N - 1);
            QuickSort(B, 0, M - 1);
            CrossingArray = GetCrossingArray(A, N, B, M);
            break;

        case RANDOM_INITIALIZATION:
            RandomInitialization(A, N, 1);
            RandomInitialization(B, M, 2);
            QuickSort(A, 0, N - 1);
            QuickSort(B, 0, M - 1);
            CrossingArray = GetCrossingArray(A, N, B, M);
            break;

    }

    cout << "Result of crossing is: ";

    for (int i = 1; i < CrossingArray[0] + 1; i++) 
        cout << CrossingArray[i] << " ";

}

void Swap(int *a, int *b) {

    int t = *a;
    *a = *b;
    *b = t;

}

int Partition (int Array[], int Low, int High) {

    int pivot = Array[High]; 
    int i = (Low - 1); 
 
    for (int j = Low; j <= High - 1; j++) {

        if (Array[j] <= pivot) {
            i++;  
            Swap(&Array[i], &Array[j]);
        }

    }

    Swap(&Array[i + 1], &Array[High]);
    return (i + 1);

}

void QuickSort(int Array[], int Low, int High) {

    if (Low < High) {

        int pi = Partition(Array, Low, High);

        QuickSort(Array, Low, pi - 1); 
        QuickSort(Array, pi + 1, High); 

    }

}

void PrintArray(int arr[], int size) {

    int i;

    for (i=0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
    
}

void ExactInitialization(int Array[], int N, int ArrayNumber) {

    cout << "Input " << ArrayNumber << " array elements: ";

    for (int i = 0; i < N; i++) 
        cin >> Array[i];

}

void RandomInitialization(int Array[], int N, int ArrayNumber) {

    int first, second;
    cout << "Enter the range of numbers: from ";
    cin >> first;
    cout << "to ";
    cin >> second;

    if (first > second)
    {
        int t = first;
        first = second;
        second = t;
    }
    
    cout << "Elements of " << ArrayNumber << " array are: ";

    for (int i = 0; i < N; i++){
        Array[i] = (first + rand() % (second - first));
        cout << Array[i] << " ";
    }

    cout << endl;

}

int* GetCrossingArray(int A[], int N, int B[], int M) {

    int Counter = 0;
    int MinSize;
    int MaxSize;
    int *LessArray;
    int *LargestArray;

    if (N <= M) {

        LessArray = A;
        LargestArray = B;
        MinSize = N;
        MaxSize = M;

    } else {

        LessArray = B;
        LargestArray = A;
        MinSize = M;
        MaxSize = N;

    }

    int LargestArrayIndex = 0;
    int *CrossingArrayTemp = new int[MinSize];

    for (int LessArrayIndex = 0; LessArrayIndex < MinSize; LessArrayIndex++) {

        if (LessArray[LessArrayIndex] == LargestArray[LargestArrayIndex]) {
            
            CrossingArrayTemp[Counter] = LessArray[LessArrayIndex];
            Counter++;
            LargestArrayIndex++;
        
        } else if (LessArray[LessArrayIndex] > LargestArray[LargestArrayIndex]) {

            LargestArrayIndex++;
            LessArrayIndex--;
            
            if (LargestArrayIndex == MaxSize)
                break;
            
        } 

    }

    int *CrossingArray = new int[Counter + 1];

    CrossingArray[0] = Counter;

    for (int i = 1; i < Counter + 1; i++) 
        CrossingArray[i] = CrossingArrayTemp[i - 1];

    return CrossingArray;

}
