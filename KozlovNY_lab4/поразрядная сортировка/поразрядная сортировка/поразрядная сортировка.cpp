#include "stdafx.h"
#include <iostream>

using namespace std;

void bitSort(size_t* M, size_t a, size_t b, size_t bit)
{
	if (bit == 0 || a >= b) return;
	int i = a, j = b;
	do
	{
		while (!(M[i] & bit) && i <= j)     // пока M[i]!=1
			i++;
		while (M[j] & bit && i <= j)        // пока M[j]!=0
			j--;
		if (i<j)
		{
			swap(M[i], M[j]);
			i++;
			j--;
		}
	} while (i<j);
	bitSort(M, a, j, bit >> 1);
	bitSort(M, i, b, bit >> 1);
}

int main()
{
	const int n = 8;
	size_t M[n] = { 129,3,255,4,5,7,250,9 };
	bitSort(M, 0, n - 1, 256);
	for (int i = 0; i < n; i++)							/*Вывод массива*/
	{
		cout << M[i] << endl;
	}

	system("pause");
	return 0;
}

