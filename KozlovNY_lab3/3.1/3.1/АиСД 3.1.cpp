#include "stdafx.h"
#include <iostream>
#include <windows.h>
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

	for (int i = 0; i < n; i++)								
	{
		arr[i] = 1+rand() % 7;
	}

	for (int i = 0; i < n; i++)							/*Вывод массива*/
	{
		cout << arr[i] << endl;
	}

		int minchsl = arr[0];
		int minchsl1 = arr[0];
		int maxchsl = arr[0];
		int maxchsl1 = arr[0];
		int ind=0;
		int indprom = 0;

	for (int i = 1; i < n; i++)              //Ищем самое маленькое число 1
	{
		if ((arr[i]) < (minchsl))
		{
			minchsl = arr[i];
			ind = i;
			maxchsl = arr[ind + 1];
		}
	}
	for (int j = ind; j < n; j++)				// Ищем самое большое число 2 после самого маленького
	{
		if ((arr[j]) >(maxchsl))
		{
			maxchsl = arr[j];
		}
	}
	cout << "Минимальная стоимость ---> " << minchsl << endl;
	cout << "Максимальная стоимость после минимальной ---> " << maxchsl << endl;
	cout << "Прибыль 1 ---> " << maxchsl - minchsl << endl;

	for (int i = 1; i < ind; i++)					//Ищем самое маленькое число посде числа  1
	{
		if ((arr[i]) < (minchsl1))
		{
			minchsl1 = arr[i];
			indprom = i;
			maxchsl1 = arr[indprom + 1];
		}
	}
	for (int j = indprom; j < ind; j++)					//Ищем самое большое число посде числа  2
	{
		if ((arr[j]) >(maxchsl1))
		{
			maxchsl1 = arr[j];
			indprom = j;
		}
	}
	cout << "Минимальная стоимость 2 ---> " << minchsl1 << endl;
	cout << "Максимальная стоимость после минимальной 2 ---> " << maxchsl1 << endl;
	cout << "Прибыль 2 ---> " << maxchsl1 - minchsl1 << endl;

	if (maxchsl1 - minchsl1 >= maxchsl - minchsl)
	{
		cout << "Наилучшая прибыль ---> " << maxchsl1 - minchsl1 << endl;
	}
	else
	{
		cout << "Наилучшая прибыль  ---> " << maxchsl - minchsl << endl;
	}

	system("pause");
	return 0;
}