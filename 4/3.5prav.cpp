#include <iostream>
#include <ctime>

using namespace std;

int FromSquareToTriangleIndex(int MatrixOrder, int Index) {   //перевод номер элемента в квадратной матрице в номер в треугольной

    int XIndex = Index % MatrixOrder;   //столбец элемента
    int YIndex = Index / MatrixOrder;   //строка элемента

    return YIndex * (YIndex + 1) / 2 + XIndex;
    
}

bool IsZero(int MatrixOrder, int Index) {   //проверяет должен ли быть элемент с данным номером нулём

    int XIndex = Index % MatrixOrder;   //столбец элемента
    int YIndex = Index / MatrixOrder;   //строка элемента

    if (XIndex > YIndex)
        return true;
    else
        return false;

}

int* ToSquare(int *Matrix, int MatrixOrder) {   //создание квадратной матрицы через возведение в квадрат треугольной

    int MatrixSize = (MatrixOrder + 1) * MatrixOrder / 2;   //размер изначальной матрицы
    int *ResultingMatrix = new int[MatrixSize];   //создание массива 
    
    for (int i = 0; i < MatrixOrder; i++) {

        for (int j = 0; j < MatrixOrder; j++) {
       
            int ElementValue = 0;

            for (int t = 0; t < MatrixOrder; t++) {

                int Element1 = (IsZero(MatrixOrder, i * MatrixOrder + t)) ? 0 : Matrix[FromSquareToTriangleIndex(MatrixOrder, i * MatrixOrder + t)];   //присвает значение из данной строки
                int Element2 = (IsZero(MatrixOrder, t * MatrixOrder + j)) ? 0 : Matrix[FromSquareToTriangleIndex(MatrixOrder, t * MatrixOrder + j)];   //присвает значение из данноого столбца

                ElementValue += Element1 * Element2;

            }

            ResultingMatrix[FromSquareToTriangleIndex(MatrixOrder, i * MatrixOrder + j)] = ElementValue;   //присваивание элементу матрицы его значения

        }

    }

    return ResultingMatrix;

}

int main() {

    srand(time(NULL));

    cout << "Please, enter the order of the matrix: ";

    int MatrixOrder;
    cin >> MatrixOrder;   //ввод порядка матрицы

    int MatrixSize = (MatrixOrder + 1) * MatrixOrder / 2;   //размер одномерного массива

    int *Matrix = new int[MatrixSize];   //создание массива

    for (int i = 0; i < MatrixSize; i++)    //заполнение случайными значениями
        Matrix[i] = rand() % 10 + 1;

    int ElementIndex = 0;

    for (int i = 0; i < MatrixOrder; i++) {   //вывод массива в виде матрицы

        for (int j = 0; j <= i; j++)
            cout << Matrix[ElementIndex++] << "\t";

        //for (int j = 1; j < MatrixOrder - i; j++)
        //   cout << "0\t";

        cout << endl;

    }

    cout << "\nSquare \n";

    int *Result = ToSquare(Matrix, MatrixOrder);   //создание массива квадрата изначальной матрицы

    ElementIndex = 0;

    for (int i = 0; i < MatrixOrder; i++) {   //вывод матрицы

        for (int j = 0; j <= i; j++)
            cout << Result[ElementIndex++] << "\t";

        // for (int j = 1; j < MatrixOrder - i; j++)
        //     cout << "0\t";

        cout << endl;

    }

    cout << "\nTranspon \n";

    int first = -1, second = 1, thirt = 0;
    ElementIndex = 0;

    int *Transpon = new int[MatrixSize];

    for (int i = 0; i < MatrixOrder; i++) {   //заполнение транспонированной матрицы

        first += second;
        second++;
        thirt = first;

        for (int j = i; j < MatrixOrder; j++) {

            Transpon[ElementIndex++] = Result[thirt];
            thirt += j + 1;
            
        }

    }

    ElementIndex = 0;

    for (int i = 0; i < MatrixOrder; i++) {   //вывод транспонированной матрицы

        for (int j = 0; j < i; j++) {

            cout << "\t";
            
        }

        for (int j = i; j < MatrixOrder; j++) {

            cout << Transpon[ElementIndex++] << "\t";
            
        }

        cout << endl;

    }

}
