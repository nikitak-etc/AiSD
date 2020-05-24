// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
using namespace std;

//����������
typedef int T;//��� ���������
typedef int hashTableIndex;//������ � ���-�������
int hashTableSize;//������
T* hashTable;//������ - ���-�������
bool* used;//������ - ������ ��� ���
int c = 2;//��������� c,d ��� ������������� �����������
int d = 3;
int cot = 0;//����������� ��� ��������
int bot = 0;//����������� ��� ��������
clock_t  startedFirstHundred;//���������� ��� �������� �������
clock_t  endedFirstHundred;  
clock_t  start;              
clock_t  max = -2;           
clock_t  startFind;          
clock_t  timeOfFind;         
							 


							 //�������

							 //���-������� ���������� �������� - ������� �� �������
hashTableIndex myhash(T data) {
	return (data % hashTableSize);
}
//������� ������ �������������� � ������� �������� � �������
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
//������� ������ ��������, ������ data
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
	cout << "������� ���������� ��������� : ";
	cin >> maxnum;
	cout << "������� ������ ���-������� : ";
	cin >> hashTableSize;
	arr = new int[maxnum];//������ � ���������� �������
	hashTable = new T[hashTableSize];//���-�������
	used = new bool[hashTableSize];//������, ��� ���� ��������� ��������� �� ������
	for (i = 0; i < hashTableSize; i++) {
		hashTable[i] = 0;
		used[i] = false;
	}									//�������� ������


	for (i = 0; i < maxnum; i++)    arr[i] = rand()*rand();				//��������� �������
	//���������� ���-������� ���������� �������
	for (i = 0; i < maxnum; i++) {
		start = clock();
		if (i == 100) {
			startedFirstHundred = clock();
			cout << "����� ���������� ������ ����� = " << (((float)(startedFirstHundred - start)) / CLOCKS_PER_SEC) << endl;
		}
		if (maxnum - 100 == i) endedFirstHundred = clock();
		insertData(arr[i]);
	}
	//cout << " ASDASD _--------_ " << bot << endl;
	cout << "����� ���������� ��������� ����� = " << (((float)(clock() - endedFirstHundred)) / CLOCKS_PER_SEC) << endl;


	//����� ��������� ������� �� ���-�������
	for (i = maxnum - 1; i >= 0; i--) {
		startFind = clock();
		bool x = findData(arr[i]);
		timeOfFind = clock() - startFind;
		if (timeOfFind > max)   max = timeOfFind;
	}
	cout << "�����(max) - ����� - " << (max) << endl;
	//cout << " ASDASD _--------_ " << cot << endl;

	cout << "������ � txt �����" << endl;
	ofstream out("List.txt");
	for (i = 0; i < maxnum; i++) {
		out << arr[i];
		if (i < maxnum - 1) out << "\t";
	}
	out.close();
	//���������� ���-������� � ���� HashTable.txt
	out.open("HashTable.txt");
	for (i = 0; i < hashTableSize; i++) {
		out << i << "  :  " << hashTable[i] << endl;
	}
	out.close();
	cout << "����� � txt �����" << endl;
	cout << endl;

	while (true) {
		cout << "������ ����������� ����� ������������� ��������? 1 - �� 2 - ���" << endl;
		int variable;
		cin >> variable;
		if (variable != 1) break;
		cout << "������� ����� ��� ������ ��� � ����� ���-�������" << endl;
		long long int findNumber; cin >> findNumber;
		if (findData(findNumber) != -5) {
			cout << "findData(" << findNumber << ") ����� �� ������� [" << findData(findNumber) << "]" << endl;
		}
		else cout << "findData(" << findNumber << ") �� �����" << endl;
		cout << endl;
	}

	//���� �������� � �������� ������� �� ���
	//���������� � ����� ����� ����� �������
	//����� ������������
	// ����� ��������� ������� � ���� List.txt
	//������ ����� ������� ������, ����� �������������� 
	//��� ������� ���� � �������������� � ������������ ���������

	//ofstream out("List.txt");
	//for (i = 0; i < maxnum; i++) {
	//    out << arr[i];
	//    if (i < maxnum - 1) out << "\t";
	//}
	//out.close();
	////���������� ���-������� � ���� HashTable.txt
	//out.open("HashTable.txt");
	//for (i = 0; i < hashTableSize; i++) {
	//    out << i << "  :  " << hashTable[i] << endl;
	//}
	//out.close();

	return 0;
}
