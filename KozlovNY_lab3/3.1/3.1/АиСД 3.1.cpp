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
	cout << "������� ���-�� ��������� ������� ---> ";
	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i++)								
	{
		arr[i] = 1+rand() % 7;
	}

	for (int i = 0; i < n; i++)							/*����� �������*/
	{
		cout << arr[i] << endl;
	}

		int minchsl = arr[0];
		int minchsl1 = arr[0];
		int maxchsl = arr[0];
		int maxchsl1 = arr[0];
		int ind=0;
		int indprom = 0;

	for (int i = 1; i < n; i++)              //���� ����� ��������� ����� 1
	{
		if ((arr[i]) < (minchsl))
		{
			minchsl = arr[i];
			ind = i;
			maxchsl = arr[ind + 1];
		}
	}
	for (int j = ind; j < n; j++)				// ���� ����� ������� ����� 2 ����� ������ ����������
	{
		if ((arr[j]) >(maxchsl))
		{
			maxchsl = arr[j];
		}
	}
	cout << "����������� ��������� ---> " << minchsl << endl;
	cout << "������������ ��������� ����� ����������� ---> " << maxchsl << endl;
	cout << "������� 1 ---> " << maxchsl - minchsl << endl;

	for (int i = 1; i < ind; i++)					//���� ����� ��������� ����� ����� �����  1
	{
		if ((arr[i]) < (minchsl1))
		{
			minchsl1 = arr[i];
			indprom = i;
			maxchsl1 = arr[indprom + 1];
		}
	}
	for (int j = indprom; j < ind; j++)					//���� ����� ������� ����� ����� �����  2
	{
		if ((arr[j]) >(maxchsl1))
		{
			maxchsl1 = arr[j];
			indprom = j;
		}
	}
	cout << "����������� ��������� 2 ---> " << minchsl1 << endl;
	cout << "������������ ��������� ����� ����������� 2 ---> " << maxchsl1 << endl;
	cout << "������� 2 ---> " << maxchsl1 - minchsl1 << endl;

	if (maxchsl1 - minchsl1 >= maxchsl - minchsl)
	{
		cout << "��������� ������� ---> " << maxchsl1 - minchsl1 << endl;
	}
	else
	{
		cout << "��������� �������  ---> " << maxchsl - minchsl << endl;
	}

	system("pause");
	return 0;
}