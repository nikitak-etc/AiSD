// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
using namespace std;

//переменные
typedef int T;//тип элементов
typedef int hashTableIndex;//индекс в хеш-таблице
int hashTableSize;//размер
T* hashTable;//массив - хеш-таблица
bool* used;//массив - занято или нет
int c = 2;//константы c,d для квадратичного опробования
int d = 3;
int cot = 0;//использовал для проверки
int bot = 0;//использовал для проверки
clock_t  startedFirstHundred;//переменные для подсчета времени
clock_t  endedFirstHundred;  
clock_t  start;              
clock_t  max = -2;           
clock_t  startFind;          
clock_t  timeOfFind;         
							 


							 //функции

							 //хеш-функция размещения величины - остаток от деления
hashTableIndex myhash(T data) {
	return (data % hashTableSize);
}
//функция поиска местоположения и вставки величины в таблицу
void insertData(T data) {
	hashTableIndex bucket;
	int j = 0;
metka:
	bucket = myhash(data) + c * j + d * j * j;
point:
	if (used[bucket] == 0) {
		hashTable[bucket] = data;
		used[bucket] = 1;
		bot++;
	}
	else {
		j++;
		if (myhash(data) + c * j + d * j * j > hashTableSize) {
			bucket = (myhash(data) + c * j + d * j * j) % hashTableSize;
			j = 0;
			goto point;
		}
		goto metka;
	}
}
//функция поиска величины, равной data
int findData(T data) {
	hashTableIndex bucket;
	int k = 0;
metka:
	bucket = myhash(data) + c * k + d * k * k;
point:
	if (hashTable[bucket] == data) {
		//cot++;
		return bucket;
	}
	else if (used[bucket] == false) {
		return -5;
	}
	else if (hashTable[bucket] != data) {
		k++;
		if (myhash(data) + c * k + d * k * k > hashTableSize) {
			bucket = (myhash(data) + c * k + d * k * k) % hashTableSize;
			k = 0;
			goto point;
		}
		goto metka;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	//srand(time(0));
	int i, *arr, maxnum;
	cout << "Введите количество элементов : ";
	cin >> maxnum;
	cout << "Введите размер хеш-таблицы : ";
	cin >> hashTableSize;
	arr = new int[maxnum];//массив с рандомными числами
	hashTable = new T[hashTableSize];//хеш-таблица
	used = new bool[hashTableSize];//массив, где буду проверять заполнена ли ячейка
	for (i = 0; i < hashTableSize; i++) {
		hashTable[i] = 0;
		used[i] = false;
	}									//заполнил нулями


	for (i = 0; i < maxnum; i++)    arr[i] = rand()*rand();				//генерация массива
	//заполнение хеш-таблицы элементами массива
	for (i = 0; i < maxnum; i++) {
		start = clock();
		if (i == 100) {
			startedFirstHundred = clock();
			cout << "Время заполнения первой сотни = " << (((float)(startedFirstHundred - start)) / CLOCKS_PER_SEC) << endl;
		}
		if (maxnum - 100 == i) endedFirstHundred = clock();
		insertData(arr[i]);
	}
	//cout << " ASDASD _--------_ " << bot << endl;
	cout << "Время заполнения последней сотни = " << (((float)(clock() - endedFirstHundred)) / CLOCKS_PER_SEC) << endl;


	//поиск элементов массива по хеш-таблице
	for (i = maxnum - 1; i >= 0; i--) {
		startFind = clock();
		bool x = findData(arr[i]);
		timeOfFind = clock() - startFind;
		if (timeOfFind > max)   max = timeOfFind;
	}
	cout << "Поиск(max) - время - " << (max) << endl;
	//cout << " ASDASD _--------_ " << cot << endl;

	cout << "Вывожу в txt файлы" << endl;
	ofstream out("List.txt");
	for (i = 0; i < maxnum; i++) {
		out << arr[i];
		if (i < maxnum - 1) out << "\t";
	}
	out.close();
	//сохранение хеш-таблицы в файл HashTable.txt
	out.open("HashTable.txt");
	for (i = 0; i < hashTableSize; i++) {
		out << i << "  :  " << hashTable[i] << endl;
	}
	out.close();
	cout << "Вывел в txt файлы" << endl;
	cout << endl;

	while (true) {
		cout << "Хотите осуществить поиск определенного элемента? 1 - да 2 - нет" << endl;
		int variable;
		cin >> variable;
		if (variable != 1) break;
		cout << "Введите число для поиска его в нашей хеш-таблице" << endl;
		long long int findNumber; cin >> findNumber;
		if (findData(findNumber) != -5) {
			cout << "findData(" << findNumber << ") нашло на позиции [" << findData(findNumber) << "]" << endl;
		}
		else cout << "findData(" << findNumber << ") не нашло" << endl;
		cout << endl;
	}

	//если работать с большими числами то это
	//заполнение в файлы будет долго длиться
	//стоит закомментить
	// вывод элементов массива в файл List.txt
	//вывожу перед поиском ручным, чтобы пользовательно 
	//мог открыть файл и удостовериться в правильности подсчетов

	//ofstream out("List.txt");
	//for (i = 0; i < maxnum; i++) {
	//    out << arr[i];
	//    if (i < maxnum - 1) out << "\t";
	//}
	//out.close();
	////сохранение хеш-таблицы в файл HashTable.txt
	//out.open("HashTable.txt");
	//for (i = 0; i < hashTableSize; i++) {
	//    out << i << "  :  " << hashTable[i] << endl;
	//}
	//out.close();

	return 0;
}
