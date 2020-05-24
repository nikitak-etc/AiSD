#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class DHeap
{
private:
	int d;
	int currentSize;
	int size;
	int *array;
public:
	DHeap(int vmestimost, int Kids)							//���������� - ������������ ��������� (����������� � ���������� �����)
	{
		currentSize = 0;
		d = Kids;//3
		size = vmestimost + 1;
		array = new int[vmestimost + 1];
		for (int i = 0; i < vmestimost + 1; i++)
			array[i] = -1;
	}


	bool isEmpty()											//�������� �� �������
	{
		return currentSize == 0;
	}

	bool isFull()
	{
		return currentSize == size;
	}

	void makeEmpty()
	{
		currentSize = 0;
	}

	int parent(int i)
	{
		return (i - 1) / d;
	}

	int Child(int i, int k)
	{
		return d * i + k;
	}

	void Vstavka(int x)
	{
		if (isFull())
		{
			cout << "�������������" << endl;
			return;
		}
		int hole = currentSize;
		currentSize++;
		array[hole] = x;
		percolateUp(hole);
	}

	void deleteMin()
	{
		if (isEmpty())											//�������� �� �������
		{
			cout << "������" << endl;
		}
		Delete(0);
	}

	int Delete(int hole)										//��������
	{
		if (isEmpty())											//�������� �� �������
		{
			cout << "������" << endl;
			return 0;
		}
		int keyItem = array[hole];
		array[hole] = array[currentSize - 1];
		currentSize--;
		percolateDown(hole);
		return keyItem;
	}

	/*int Deletemax() {
	int k = currentSize - parent(currentSize);
	int naib = currentSize;
	for (int o = 0; o < k + 1; o++) {
	if (array[naib] < array[currentSize - o])naib = currentSize - o;
	}
	Delete(naib);
	return array[naib];
	}*/
	void buildHeap()
	{
		for (int i = currentSize - 1; i >= 0; i--)
			percolateDown(i);
	}

	void percolateDown(int hole)								//�������� ��������� �������� ����
	{
		int child;
		int tmp = array[hole];
		for (; Child(hole, 1) < currentSize; hole = child)
		{
			child = smallestChild(hole);
			if (array[child] < tmp)
				array[hole] = array[child];
			else
				break;
		}
		array[hole] = tmp;
	}

	int smallestChild(int hole)
	{
		int bestChildYet = Child(hole, 1);
		int k = 2;
		int candidateChild = Child(hole, k);
		while ((k <= d) && (candidateChild < currentSize))
		{
			if (array[candidateChild] < array[bestChildYet])
				bestChildYet = candidateChild;
			k++;
			candidateChild = Child(hole, k);
		}
		return bestChildYet;
	}

	void percolateUp(int hole)
	{
		int tmp = array[hole];
		for (; hole > 0 && tmp < array[parent(hole)]; hole = parent(hole))
			array[hole] = array[parent(hole)];
		array[hole] = tmp;
	}

	void printHeap()
	{
		cout << "\n  ���� = ";
		for (int i = 0; i < currentSize; i++)
			cout << array[i] << "   ";
		cout << endl;
	}
	void printHeap(const std::string & probel, int n, bool lefts)//�����
	{
		if (n < currentSize)
		{
			cout << probel;

			if (array[n] != -1)
				cout << "|_:" << array[n] << std::endl;
			else
				cout << "|_:-" << endl;
			for (int i = 1; i < this->d; i++) {
				if (lefts)
				{
					printHeap(probel + "|   ", this->Child(n, i), true);
				}
				else {
					printHeap(probel + "    ", this->Child(n, i), true);
				}
			}
			if (lefts) {
				printHeap(probel + "|   ", this->Child(n, d), false);
			}
			else  printHeap(probel + "    ", this->Child(n, d), false);
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "������� ���������� ���������: ";
	int size, num, choice, val;
	cin >> size;
	DHeap kycha(size, 3);													//d=3;
	for (int i = 0; i < size; i++)
	{
		cout << "������� �������: ";
		cin >> num;
		kycha.Vstavka(num);
	}
	cout << endl << "-------------------------" << endl;
	kycha.printHeap("", 0, false);
	while (1)
	{
		cout << "�������� - ������� �������� (1)" << endl;
		cout << "������� - ������� ������ (2)" << endl;
		cout << "����� - ������� ������ (3)" << endl;
		cin >> choice;
		if (choice == 3)													//����� �� ���������
		{
			cout << "�� ��������!" << endl;
			system("pause");
			return 0;
		}
		switch (choice)
		{
		case 1:
			cout << "������� ����������� ������� : ";						//�������
			cin >> val;
			kycha.Vstavka(val);
			break;
		case 2:
			kycha.Delete(0);												//��������
			break;
		}
		cout << endl << "-------------------------" << endl;
		kycha.printHeap("", 0, false);
	}
	return 0;
}