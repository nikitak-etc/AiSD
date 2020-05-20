#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

void quicksort(int *mas, int first, int last, int & Obmen, int &Sravn)
{
	int mid;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		Sravn++;
		while (mas[f]<mid) f++;
		while (mas[l]>mid) l--;
		if (mas[f] >= mas[l]) //перестановка элементов
		{
			swap(mas[f], mas[l]);
			Obmen++;
			f++;
			l--;
		}
	} while (f<l);
	if (first<l) quicksort(mas, first, l, Obmen, Sravn);
	if (f<last) quicksort(mas, f, last, Obmen, Sravn);
}

int main() {
	SetConsoleOutputCP(1251);

	const int size = 10000;
	int Arr[size], Obmen = 0, Sravn = 0;

	for (int i = 0; i < size; i++) {
		//Arr[i] = i + 1;
		//Arr[i] = size - i;
		Arr[i] = rand() % 100000 + 1;
		cout << Arr[i] << " ";
	}
	cout << endl;

	unsigned int start_time = clock();
	/////////////////////////////////////////////////////////////////////////////////////
	int first = 0;
	int last = size - 1;
	quicksort(Arr, first, last, Obmen, Sravn);
	/////////////////////////////////////////////////////////////////////////////////////
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}

	cout << endl << "Сравнений: " << Sravn << endl << "Обменов: " << Obmen << endl << "Время: " << search_time << endl;

	system("pause");
	return 0;
}