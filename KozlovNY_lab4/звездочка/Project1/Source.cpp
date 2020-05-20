#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string.h>


using namespace std;

void InsertionSort(int* Mas, int first, int last)
{
	int i, j, tmp;
	for (i = first; i <= last; ++i)
	{
		tmp = Mas[i];
		for (j = i - 1; j >= first && tmp < Mas[j]; --j)
		{
			Mas[j + 1] = Mas[j];
		}
		Mas[j + 1] = tmp;
	}
}

void Merge(int* Mas, int first, int middle, int last)
{
	int* p = new int[middle - first + 1];
	int* p1 = new int[last - middle];
	memcpy(p, Mas + first, sizeof(int)*(middle - first + 1));
	memcpy(p1, Mas + middle + 1, sizeof(int)*(last - middle));
	int n, m, k;
	for (n = 0, m = 0, k = 0; n < (middle - first + 1) && m < (last - middle); ++k)
	{
		Mas[first + k] = (p[n] < p1[m] ? p[n++] : p1[m++]);
	}
	memcpy(Mas + first + k, p1 + m, sizeof(int)*(last - middle - m));
	memcpy(Mas + first + k, p + n, sizeof(int)*(middle - first + 1 - n));
	delete[] p; p = 0;
	delete[] p1; p1 = 0;
}

void MergeSort(int* Mas, int first, int last)
{
	if (20 >= last - first)
	{
		InsertionSort(Mas, first, last);
	}
	else
	{
		int mInd = (first + last) / 2;
		MergeSort(Mas, first, mInd);
		MergeSort(Mas, mInd + 1, last);
		Merge(Mas, first, mInd, last);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int const siz = 10;
	int* Mas = new int[siz];
	cout << "Текущий массив задан рандомно: " << endl;
	for (int i = 0; i < siz; ++i)
	{
		Mas[i] = rand() % 100 - 50;
		cout << setw(4) << Mas[i];
	}
	MergeSort(Mas, 0, siz - 1);
	cout << endl;
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < siz; ++i)
	{
		cout << setw(4) << Mas[i];
	}
	cout << endl;
	delete[] Mas; 
	Mas = 0;
	system("pause");
	return 0;
}