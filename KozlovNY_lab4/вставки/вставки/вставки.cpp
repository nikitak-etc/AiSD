
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
	cout << "������� ���-�� ��������� ������� ---> ";
	cin >> n;

	arr = new int[n];
	bool suj;

	for (int i = 0; i < n; )								/*��������� �����*/
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

	for (int i = 0; i < n; i++)							/*����� �������*/
	{
		cout << arr[i] << endl;
	}

	for (int i = 1; i < n; i++)
	{
		int m = arr[i];
		int j = i - 1; // ��������� ������ ����������� ��������
		while (j >= 0 && arr[j] > m) //����� �� ���� � -1 && ���������� ������ ��������
		{
			arr[j + 1] = arr[j]; //���������� �������� 
			arr[j] = m;
			j--; // ������� �� ������ ��������
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}

