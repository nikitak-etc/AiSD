
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

	for (int i = 1; i < n; i++)
	{
		int m = arr[i];
		int j = i - 1; // запомнили индекс предыдущего элемента
		while (j >= 0 && arr[j] > m) //чтобы не ушёл в -1 && предыдущий больше текущего
		{
			arr[j + 1] = arr[j]; //перемещаем элементы 
			arr[j] = m;
			j--; // перейти на другой эелемент
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}

