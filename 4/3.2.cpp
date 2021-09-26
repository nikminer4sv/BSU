#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

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
    for (int i = 1; i < Rows - 1; i++)
        for (int j = 1; j < Cols - 1; j++)
            if (Matrix[i][j] > Maximum)  
                Maximum = Matrix[i][j];

    vector<vector<int>> AnotherMatrix(Rows, vector<int>(Cols, Maximum));

    for (int i = 0; i < Rows; i++) {

        for (int j = 0; j < Cols; j++) {
            cout << AnotherMatrix[i][j] << " ";
        }

        cout << endl;

    }

}
