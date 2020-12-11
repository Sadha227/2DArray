#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


int** formMatrix(int n, int m);
void printMatrix(int** matrix, int n, int m);
void fillMatrix(int** matrix, int n, int m);
void deletMatrix(int** matrix, int n, int m);
void chanderRowCoulmn(int** matrix, int n, int m, int k);
int getRowNumWithMaxAvg(int** matrix, int n, int m);

    //task #11
int main()
{
	srand(time(NULL));
	int size1 = 5;
	int index = 2; //номер стри/столбца для замены
	int** matrix1 = formMatrix(size1, size1);
	fillMatrix(matrix1, size1, size1);
	cout << "Initial matrix: " << endl;
    printMatrix(matrix1, size1, size1);
	chanderRowCoulmn(matrix1, size1, size1, index);
	cout << "Matrix after xhange " << index + 1 << "row coulumn" << endl;
	printMatrix(matrix1, size1, size1);
	deletMatrix(matrix1, size1, size1);


	//task #10 - нфйти номер строки для которой сруднуу арифметическое элементов строки наибольшее
	int size2 = 3;
	int** matrix2 = formMatrix(size1, size1);
	fillMatrix(matrix1, size2, size1);
	cout << "Matrix: " << endl;
	printMatrix(matrix1, size2, size2);
	int index1 = getRowNumWithMaxAvg(matrix2, size2, size2);
	cout << "Row index with max average: " << index1 + 1 << endl;

	return 0;
}

int** formMatrix(int n, int m)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	return arr;
}

void printMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
}

void fillMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 101;
		}
	}
}

void deletMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		delete matrix[i];
	}
}

void chanderRowCoulmn(int** matrix, int n, int m, int k)
{
	for (int i = 0; i < n; i++)
	{
		int tmp = matrix[k][i];
		matrix[k][i] = matrix[i][k];
		matrix[i][k] = tmp;
	}
	/*
	for (int i = 0; i < n; i++)
	{
		if (i != k)
		{
		int tmp = matrix[k][i];
		matrix[k][i] = matrix[i][k];
		matrix[i][k] = tmp;

		}
	}*/
}

int getRowNumWithMaxAvg(int** matrix, int n, int m)
{
	int rowIndex = 0;
	double max = -9999;
	for (int i = 0; i < n; i++)
	{
	    int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += matrix[i][j];
		}
		double avg = sum / m;
		if (avg > max)
		{
			max = avg;
			rowIndex = i;
		}
	}
	return rowIndex;
}
