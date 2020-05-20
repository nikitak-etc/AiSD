#include "stdafx.h"
#include <iostream>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h> 
#include <ctime>


using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int n, *arr;
	cout << "Введите кол-во элементов массива ---> ";
	cin >> n;

	arr = new int[n];
	bool suj;

	for (int i = 0; i < n; )								/*Рандомное число*/
	{
		suj = false;
		int newchsl = rand() % 20 - 10;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == newchsl)
			{
				suj = true;
				break;
			}
		}
		if (!suj)
		{
			arr[i] = newchsl;
			i++;
		}
	}

	for (int i = 0; i < n; i++)							/*Вывод массива*/
	{
		cout << arr[i] << endl;
	}
	int min, s;
	for (int i = 0; i < n - 1; i++)
	{
	 min = i;
		for (int j = i + 1; j < n; j++)
		{
			while (arr[j] < arr[min])
			{
				min = arr[i];
				min = j;
			}
		}
		s = arr[i];
		arr[i] = arr[min];
		arr[min] = s;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}