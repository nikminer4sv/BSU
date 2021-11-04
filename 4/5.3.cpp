#include <iostream>
#include <time.h>

using namespace std;

void Input(int* N, int* M);
void Sort(int **, int , int );
void Output(int **, int , int );

int main() {

	srand(time(NULL));

	system("cls");

	int Cols, Rows;
	int **Matrix;

	Input(&Rows, &Cols);

	Matrix = new int*[Rows];

	for (int i = 0; i < Rows; i++)
		Matrix[i] = new int[Cols];

	Sort(Matrix, Rows, Cols);

	Output(Matrix, Rows, Cols);

}

void Input(int* Rows, int* Cols) {

	cout << "Enter the number of rows and cols\n";

	cin >> *Rows >> *Cols;

}

void Sort(int **Matrix, int Rows, int Cols) {

	cout << "Matrix : \n";

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			Matrix[i][j] = rand() % 100 + 1;
			cout << Matrix[i][j] << " ";

		}

		cout << endl;
	}

	cout << endl;
	
	for (int i = 0; i < Cols; i++) {

		if (Matrix[Rows - 1][i] > Matrix[Rows - 2][i]) {

			int temp = Matrix[Rows - 2][i];
			Matrix[Rows - 2][i] = Matrix[Rows - 1][i];
			Matrix[Rows - 1][i] = temp;

		}
		
	}

}

void Output(int **Matrix, int Rows, int Cols) {

	cout << "After sort : \n";

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++)
			cout << Matrix[i][j] << " ";

		cout << endl;
	}

}
