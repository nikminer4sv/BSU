#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int RowsAndCols, k = 0;
	cin >> RowsAndCols;

    vector<vector<int>> Matrix(RowsAndCols, vector<int>(RowsAndCols));
    
    for (int i = 0; i < RowsAndCols; i++)
        for (int j = 0; j < RowsAndCols - i; j++) {

            Matrix[i][j] = k + 1;
            k = Matrix[i][j];

        }

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

    for (int i = 0; i < RowsAndCols; i++)
        for (int j = i; j < RowsAndCols; j++)
            swap(AnotherMatrix[i][j],AnotherMatrix[j][i]);

	for (int i = 0; i < RowsAndCols; i++) {

        for (int j = 0; j < RowsAndCols; j++) {

            cout << AnotherMatrix[i][j] << " ";

        }

        cout << endl;

    }

}
