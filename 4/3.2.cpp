#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int MaximumInSquare(int a, int b, vector<vector<int>> Matrix) {

    int Maximum = 0;
    int Min = a;
    int Max = b;

    if (a >= b)
    {
        Min = b;
        Max = a;
    }
    
    for (int i = Min ; i <= Max; i++)
        for (int j = Min; j <= Max; j++)
            if (Matrix[i][j] > Maximum)  
                Maximum = Matrix[i][j];

    return Maximum;

}

int main(){

    srand(time(NULL));

    int Rows = 5, Cols = 5;

    vector<vector<int>> Matrix(Rows, vector<int>(Cols));
    
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            Matrix[i][j] = rand() % 100 + 1;

    for (int i = 0; i < Rows; i++) {

        for (int j = 0; j < Cols; j++) {
            cout << Matrix[i][j] << " ";
        }

        cout << endl;

    }

    cout << "--------------------------------------------------\n";

    int Maximum = 0;

    vector<vector<int>> AnotherMatrix(Rows, vector<int>(Cols, Maximum));

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            AnotherMatrix[i][j] = MaximumInSquare(i, j, Matrix);
            cout << AnotherMatrix[i][j] << " ";
        }

        cout << endl;

    }

}
