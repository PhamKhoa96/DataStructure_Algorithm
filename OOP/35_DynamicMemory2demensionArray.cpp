/*
	Mảng hai chiều cấp phát động
*/

#include <iostream>
using namespace std;

int main() {

	int a[10][10];

	int** array, array2, array3;
	float** floatArray;
	char** friends;

	array = new int* [10];
	for (size_t i = 0; i < 10; i++)
	{
		array[i] = new int[10];
	}

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}