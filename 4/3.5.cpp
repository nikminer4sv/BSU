#include <iostream>

using namespace std;

int FromSquareToTriangleIndex(int MatrixOrder, int Index) {

    int XIndex = Index % MatrixOrder;
    int YIndex = Index / MatrixOrder;

    return Index - (YIndex - 1) * (YIndex) / 2;
    
}

bool IsZero(int MatrixOrder, int Index) {

    int XIndex = Index % MatrixOrder;
    int YIndex = Index / MatrixOrder;

    if (XIndex < MatrixOrder - YIndex)
        return false;
    else
        return true;

}

int* ToSquare(int *Matrix, int MatrixOrder) {

    int *ResultingMatrix = new int[MatrixOrder * MatrixOrder];
    int MatrixSize = (MatrixOrder + 1) * MatrixOrder / 2;

    for (int i = 0; i < MatrixOrder; i++) {

        for (int j = 0; j < MatrixOrder; j++) {
       
            int ElementValue = 0;

            for (int t = 0; t < MatrixOrder; t++) {

                int Element1 = (IsZero(MatrixOrder, i * MatrixOrder + t)) ? 0 : Matrix[FromSquareToTriangleIndex(MatrixOrder, i * MatrixOrder + t)];
                int Element2 = (IsZero(MatrixOrder, t * MatrixOrder + j)) ? 0 : Matrix[FromSquareToTriangleIndex(MatrixOrder, t * MatrixOrder + j)];

                ElementValue += Element1 * Element2;

            }

            ResultingMatrix[i * MatrixOrder + j] = ElementValue;

        }

    }

    return ResultingMatrix;

}

int main() {

    srand(time(NULL));

    cout << "Please, enter the order of the matrix: ";

    int MatrixOrder;
    cin >> MatrixOrder;

    int MatrixSize = (MatrixOrder + 1) * MatrixOrder / 2;

    int *Matrix = new int[MatrixSize];

    for (int i = 0; i < MatrixSize; i++) 
        //Matrix[i] = i + 1;
        Matrix[i] = rand() % 10 + 1;

    int ElementIndex = 0;

    for (int i = 0; i < MatrixOrder; i++) {

        for (int j = 0; j < MatrixOrder - i; j++)
            cout << Matrix[ElementIndex++] << " ";

        for (int j = MatrixOrder - i; j < MatrixOrder; j++)
            cout << "0 ";

        cout << endl;

    }

    cout << "\nSquare \n";

    int *Result = ToSquare(Matrix, MatrixOrder);

    for (int i = 0; i < MatrixOrder; i++) {

        for (int j = 0; j < MatrixOrder;j++)
            cout << Result[i * MatrixOrder + j] << " ";

        cout << endl;
    }

    cout << "\nT \n";

    for (int i = 0; i < MatrixOrder; i++) {

        for (int j = 0; j < MatrixOrder; j++) {

            cout << Result[j * MatrixOrder + i] << " ";

        }

        cout << endl;

    }

}
