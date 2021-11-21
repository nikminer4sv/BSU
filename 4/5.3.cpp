#include<iostream>
#include<ctime>

using namespace std;

void sort_array(int** array, int row, int column)
{
	int variable = 0;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (array[row - 1][i] < array[row - 1][j])
			{
				for (int k = 0; k < row; k++)
				{
					variable = array[k][i];
					array[k][i] = array[k][j];
					array[k][j] = variable;
				}	
			}
		}
	}
}

void fill_array(int** array, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			array[i][j] = rand();
		}
	}
}

void print_array(int** array, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}


int main()
{
	int row;
	cout << "Enter the row: ";
	cin >> row;

	int column;
	cout << "Enter the column: ";
	cin >> column;

	int** array = new int* [row];

	for (int i = 0; i < row; i++)
	{
		array[i] = new int[column];
	}

	
	fill_array(array, row, column);
	print_array(array, row, column);
	cout << endl;
	sort_array(array, row, column);
	print_array(array, row, column);

	for (int i = 0; i < row; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	return 0;
}
