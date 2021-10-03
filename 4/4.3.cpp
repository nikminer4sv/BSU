#include <iostream>
#include <vector>

using namespace std;

int GetArraySize(char Array[]);
void ChangeSeparatorToVoid(char Array[], int ArraySize);
int GetLastWordLength(char Array[], int ArraySize);
void WordsInLengthLikeLast(char Array[], int ArraySize, int LastWordLength);

int main() {   

    char *Array = new char[255];
    gets(Array); 

    int ArraySize = GetArraySize(Array);

    ChangeSeparatorToVoid(Array, ArraySize);

    int LastWordLength = GetLastWordLength(Array, ArraySize);

    WordsInLengthLikeLast(Array, ArraySize, LastWordLength);
 
    cout << Array;

}

int GetArraySize(char Array[]) {

    int Size = 0;

    while (Array[Size] != '\0')
        Size += 1;

    return Size;

}

void ChangeSeparatorToVoid(char Array[], int ArraySize) {

    for (int i = 0; i < ArraySize; i++) {

        if (Array[i] == ' ' || Array[i] == '?' || 
            Array[i] == ',' || Array[i] == '.' || 
            Array[i] == ':' || Array[i] == ';' || 
            Array[i] == '!' || Array[i] == '-' || 
            Array[i] == '(' || Array[i] == ')') { 

            Array[i] = ' ';

        }

    }

}

int GetLastWordLength(char Array[], int ArraySize) {

    int LastWordLength = 0, k = ArraySize - 1;

    while (Array[k] == ' ') {

            k--;

    }

    for (int i = k; i > -1; i--) {

        if (Array[i] == ' ')
            break;

        LastWordLength += 1;

    }

    return LastWordLength;

}

void WordsInLengthLikeLast(char Array[], int ArraySize, int LastWordLength) {

    int ArrayIndex = 0;
    int EntryIndex = 0;
    int CurrentWordLength = 0;

    for (int i = 0; i < ArraySize + 1; i++) {

        if (Array[i] != ' ' && Array[i] != '\0') {

            if (CurrentWordLength == 0) {
                EntryIndex = i;
            }

            CurrentWordLength += 1;

        } else {

            if (CurrentWordLength == LastWordLength) {

                for (int j = EntryIndex; j < EntryIndex + LastWordLength; j++) {

                    Array[ArrayIndex] = Array[j];
                    ArrayIndex += 1;

                }

                Array[ArrayIndex] = ' ';
                ArrayIndex += 1;

            }

            CurrentWordLength = 0;

        }

    }

    Array[ArrayIndex] = '\0';

}
