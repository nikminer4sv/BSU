#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){

    srand(time(NULL));

    int RowsAndCols;
	cin >> RowsAndCols;

    vector<vector<int>> Matrix(RowsAndCols, vector<int>(RowsAndCols));
    
    for (int i = 0; i < RowsAndCols; i++)
        for (int j = 0; j < RowsAndCols - i; j++)
            Matrix[i][j] = rand() % 2 + 1;

    for (int i = 0; i < RowsAndCols; i++) {
        for (int j = 0; j < RowsAndCols; j++) {
            cout << Matrix[i][j] << " ";
        }

        cout << endl;

    }

	cout << "--------------------------------------------------\n";

	vector<vector<int>> AnotherMatrix(RowsAndCols, vector<int>(RowsAndCols));
    
    for (int i = 0; i < RowsAndCols; i++)
        for (int j = 0; j < RowsAndCols; j++)
			for (int k = 0; k < RowsAndCols; k++)
            	AnotherMatrix[i][j] += Matrix[k][j] * Matrix[i][k];

	for (int i = 0; i < RowsAndCols; i++) {
        for (int j = 0; j < RowsAndCols; j++) {
            cout << AnotherMatrix[i][j] << " ";
        }

        cout << endl;

    }

}
