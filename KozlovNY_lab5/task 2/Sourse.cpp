#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include <random>

using namespace std;

int files = 0, compares = 0;

class file {
private:
	string path;
	ifstream in;
	ofstream out;
public:
	file(string path) {
		this->path = path;
	}
	bool start_write(bool trunc) {
		if (trunc)
			out.open(path, ios::trunc);
		else out.open(path);
		files += 2;
		compares++;
		if (!out.is_open())
			return false;

		return true;
	}
	void end_write() {
		files++;
		out.close();
	}
	void write(int n) {
		files++;
		out << n;
	}
	void write(string n) {
		files++;
		out << n;
	}
	bool start_read(bool trunc) {
		if (trunc)
			in.open(path, ios::trunc);
		else in.open(path);
		files += 2;
		compares++;
		if (!in.is_open())
			return false;

		return true;
	}
	void end_read() {
		files++;
		in.close();
	}
	int read() {
		string s;
		in >> s;
		files++;
		return stoi(s);
	}
	void skip() //пропуск символа
	{
		string s;
		in >> s;
		files++;
	}

	bool is_end() {
		compares++;
		files++;
		return in.eof();
	}

	bool delete_last_symbol() {

		in.open(path);
		files += 2;
		if (!in.is_open())
			return false;

		string s;
		getline(in, s);
		files++;
		in.close();

		compares++;
		if (s.length() != 0) {
			s.erase(s.end() - 1);
			files++;
			out.open(path);
			files += 2;
			compares++;
			if (!out.is_open())
				return false;

			out << s;
			files += 2;
			out.close();
		}
		return true;
	}

	bool is_empty() {
		ifstream i;
		files++;
		i.open(path, ios::binary | ios::ate);
		int n = i.tellg();
		files += 2;
		i.close();
		compares++;
		if (n == 0)return true;
		else return false;
	}
};

bool access1 = true, access2 = true, access3 = true;
int count_elements = 1;

int compare(int number1, int number2, int number3) {
	compares++;
	if (!access1) {
		compares++;
		if (!access2)
			return 3;

		compares++;
		if (!access3)
			return 2;
		compares++;
		if (number2 <= number3)
			return 2;

		return 3;
	}
	compares++;
	if (!access2) {
		compares++;
		if (!access1)return 3;
		compares++;
		if (!access3)return 1;
		compares++;
		if (number1 <= number3)return 1;
		return 3;
	}
	compares++;
	if (!access3) {
		compares++;
		if (!access1)return 2;
		compares++;
		if (!access2)return 1;
		compares++;
		if (number1 <= number2)return 1;
		return 2;

	}
	else {
		compares++;
		if (number1 <= number2 && number1 <= number2)return 1;
		compares++;
		if (number2 <= number1 && number2 <= number3)return 2;
		return 3;
	}
}


void read_number(file& f, file& f1) {
	f1.write(f.read());
	f1.write(" ");
	files += 2;
}
//files 3
int main() {
	setlocale(LC_ALL, "rus");
	double stime;
	
	int count = 0, k = 0, i = 0;
	cout << "Количество элементов: ";
	cin >> count;

	file f("f.txt"), f1("f1.txt"), f2("f2.txt"), f3("f3.txt"),
		g1("g1.txt"), g2("g2.txt"), g3("g3.txt");
	do {
		cout << "По возрастанию - 1 По убыванию - 2 Рандом - 3" << endl;
		cin >> k;
	} while (k != 1 && k != 2 && k != 3);
	
	if (!f.start_write(true)) {
		cout << " Error1: " << GetLastError() << endl;
		system("pause");
		return -1;
	}
	if (k == 1) {
		for (i = 0; i < count - 1; i++) {
			f.write(i);
			f.write(" ");
		}
		f.write(i);
	}
	else if (k == 2) {
		for (i = count - 1; i > 0; i--) {
			f.write(i);
			f.write(" ");
		}
		f.write(i);
	}
	else {
		mt19937 gen(time(0));
		uniform_int_distribution<> uid(-10000, 10000);

		for (i = 0; i < count - 1; i++) {
			f.write(uid(gen));
			f.write(" ");
		}
		f.write(uid(gen));
	}
	f.end_write();

	stime = clock();

	if (!f.start_read(false)) {
		cout << " Error f: " << GetLastError() << endl;
		system("pause");
		return -1;
	}
	if (!f1.start_write(true)) {
		cout << "error write f1: " << GetLastError() << endl;
		system("pause");
		return -2;
	}
	if (!f2.start_write(true)) {
		cout << "error write f2: " << GetLastError() << endl;
		system("pause");
		return -2;
	}
	if (!f3.start_write(true)) {
		cout << "error write f3: " << GetLastError() << endl;
		system("pause");
		return -2;
	}
	compares += 4;
	int attempt = 1;
	compares++;
	while (!f.is_end()) {
		compares++;
		if (attempt == 1) {
			read_number(f, f1);
			attempt++;
		}
		else if (attempt == 2) {
			compares++;
			read_number(f, f2);
			attempt++;
		}	
		else if (attempt == 3) {
			compares += 2;
			read_number(f, f3);
			attempt = 1;
		}
	}


	f1.end_write();
	f2.end_write();
	f3.end_write();
	f.end_read();


	if (!f1.delete_last_symbol()) {
		cout << "Error delete1: " << GetLastError() << endl;
		system("pause");
		return -1;
	}
	if (!f2.delete_last_symbol()) {
		cout << "Error delete2: " << GetLastError() << endl;
		system("pause");
		return -1;
	}
	if (!f3.delete_last_symbol()) {
		cout << "Error delete3: " << GetLastError() << endl;
		system("pause");
		return -1;
	}
	compares += 3;

	int min;
	int result = 0;

	int index1 = 0, index2 = 0, index3 = 0;
	int number1 = 0, number2 = 0, number3 = 0;
	while (true) {

		attempt = 1;

		if (!g1.start_write(true)) {
			cout << "error write: " << GetLastError() << endl;
			system("pause");
			return -2;
		}
		if (!g2.start_write(true)) {
			cout << "error write: " << GetLastError() << endl;
			system("pause");
			return -2;
		}
		if (!g3.start_write(true)) {
			cout << "error write: " << GetLastError() << endl;
			system("pause");
			return -2;
		}
		if (!f1.start_read(false)) {
			cout << "error read: " << GetLastError() << endl;
			system("pause");
			return -3;
		}
		if (!f2.start_read(false)) {
			cout << "error read: " << GetLastError() << endl;
			system("pause");
			return -3;
		}
		if (!f3.start_read(false)) {
			cout << "error read: " << GetLastError() << endl;
			system("pause");
			return -3;
		}
		compares += 6;

		compares += 3;
		while (!f1.is_end() || !f2.is_end() || !f3.is_end()) {

			index1 = index2 = index3 = 0;
			access1 = access2 = access3 = true;
			compares++;
			if (f3.is_empty()) {
				access3 = false;
				f3.skip();
			}
			compares++;
			if (f2.is_empty()) {
				access2 = false;
				f2.skip();
			}
			compares+=2;
			if (!f1.is_end() && access1)
			{
				number1 = f1.read();
				index1++;
			}
			else if (f1.is_end()) access1 = false;
			compares += 2;
			if (!f2.is_end() && access2)
			{
				number2 = f2.read();
				index2++;
			}
			else if (f2.is_end()) access2 = false;
			compares += 2;
			if (!f3.is_end() && access3)
			{
				number3 = f3.read();
				index3++;
			}
			else if (f3.is_end()) access3 = false;			
			compares ++;
			if (attempt == 1) {
				compares += 2;
				while (access1 || access2 || access3) {
					min = compare(number1, number2, number3);
					if (min == 1) {
						compares++;
						g1.write(number1);
						if (index1 == count_elements || f1.is_end()) access1 = false;
						compares += 2;
						if (access1 && !f1.is_end()) {
							compares += 2;
							number1 = f1.read();
							index1++;
						}						
						else if (f1.is_end()) access1 = false;
						compares++;
					}
					else if (min == 2) {
						compares++;
						g1.write(number2);
						compares++;
						if (index2 == count_elements || f2.is_end()) access2 = false;
						compares++;
						if (access2 && !f2.is_end()) {
							compares+=2;
							number2 = f2.read();
							index2++;
						}
						else if (f2.is_end()) access2 = false;
						compares++;
					}
					else {
						compares++;
						g1.write(number3);
						compares++;
						if (index3 == count_elements || f3.is_end()) access3 = false;
						compares+=2;
						if (access3 && !f3.is_end()) {
							compares++;
							number3 = f3.read();
							index3++;
						}
						else if (f3.is_end()) access3 = false;
						compares++;
					}
					g1.write(" ");
				}
				attempt++;
			}
			else if (attempt == 2) {
				compares++;
				while (access1 || access2 || access3) {
					compares++;
					min = compare(number1, number2, number3);
					compares++;
					if (min == 1) {
						compares++;
						g2.write(number1);
						compares++;
						if (index1 == count_elements || f1.is_end()) access1 = false;
						compares+=2;
						if (access1 && !f1.is_end()) {
							number1 = f1.read();
							index1++;
						}
						else if (f1.is_end()) access1 = false;
						compares++;
					}
					else if (min == 2) {
						compares++;
						g2.write(number2);
						compares++;
						if (index2 == count_elements || f2.is_end()) access2 = false;
						compares += 2;
						if (access2 && !f2.is_end()) {
							number2 = f2.read();
							index2++;
						}
						else if (f2.is_end()) access2 = false;
						compares++;
					}
					else {
						compares++;
						g2.write(number3);
						compares++;
						if (index3 == count_elements || f3.is_end()) access3 = false;
						compares += 2;
						if (access3 && !f3.is_end()) {
							number3 = f3.read();
							index3++;
						}
						else if (f3.is_end()) access3 = false;
						compares++;
					}
					g2.write(" ");
				}
				attempt++;
			}
			else {
				compares++;
				while (access1 || access2 || access3) {
					compares++;
					min = compare(number1, number2, number3);
					if (min == 1) {
						compares++;
						g3.write(number1);
						compares++;
						if (index1 == count_elements || f1.is_end()) access1 = false;
						compares += 2;
						if (access1 && !f1.is_end()) {
							number1 = f1.read();
							index1++;
						}
						else if (f1.is_end()) access1 = false;
						compares++;
					}
					else if (min == 2) {
						compares++;
						g3.write(number2);
						if (index2 == count_elements || f2.is_end()) access2 = false;
						compares += 2;
						if (access2 && !f2.is_end()) {
							number2 = f2.read();
							index2++;
						}
						else if (f2.is_end()) access2 = false;
						compares++;
					}
					else {
						compares++;
						g3.write(number3);
						compares++;
						if (index3 == count_elements || f3.is_end()) access3 = false;
						compares += 2;
						if (access3 && !f3.is_end()) {
							number3 = f3.read();
							index3++;
						}
						else if (f3.is_end()) access3 = false;
						compares++;
					}
					compares++;
					g3.write(" ");
				}
				attempt = 1;
			}
			compares += 2;
		}

		g1.end_write();
		g2.end_write();
		g3.end_write();
		f1.end_read();
		f2.end_read();
		f3.end_read();

		compares++;
		if (g2.is_empty() && g3.is_empty()) {
			compares++;
			result = 2;
			break;
		}

		if (!g1.delete_last_symbol()) {
			cout << "Error delete g1: " << GetLastError() << endl;
			system("pause");
			return -1;
		}
		if (!g2.delete_last_symbol()) {
			cout << "Error delete g2: " << GetLastError() << endl;
			system("pause");
			return -1;
		}
		if (!g3.delete_last_symbol()) {
			cout << "Error delete g3: " << GetLastError() << endl;
			system("pause");
			return -1;
		}
		compares = +3;

		if (!f1.start_write(true)) {
			cout << "error write f1: " << GetLastError() << endl;
			system("pause");
			return -2;
		}
		if (!f2.start_write(true)) {
			cout << "error write f2: " << GetLastError() << endl;
			system("pause");
			return -2;
		}
		if (!f3.start_write(true)) {
			cout << "error write f3: " << GetLastError() << endl;
			system("pause");
			return -2;
		}
		if (!g1.start_read(false)) {
			cout << "error read: " << GetLastError() << endl;
			system("pause");
			return -3;
		}
		if (!g2.start_read(false)) {
			cout << "error read: " << GetLastError() << endl;
			system("pause");
			return -3;
		}
		if (!g3.start_read(false)) {
			cout << "error read: " << GetLastError() << endl;
			system("pause");
			return -3;
		}
		compares += 6;

		count_elements *= 3;
		attempt = 1;
		compares += 2;
		while (!g1.is_end() || !g2.is_end() || !g3.is_end()) {
			
			index1 = index2 = index3 = 0;
			access1 = access2 = access3 = true;
			if (g3.is_empty()) {
				access3 = false;
				g3.skip();
			}
			if (g2.is_empty()) {
				access2 = false;
				g2.skip();
			}
			compares+=2;
			compares++;
			if (!g1.is_end() && access1)
			{
				compares++;
				number1 = g1.read();
				index1++;
			}
			else if (g1.is_end()) access1 = false;
			compares++;
			if (!g2.is_end() && access2)
			{
				compares++;
				number2 = g2.read();
				index2++;
			}
			else if (g2.is_end()) access2 = false;
			compares++;
			if (!g3.is_end() && access3)
			{
				compares++;
				number3 = g3.read();
				index3++;
			}
			else if (g3.is_end()) access3 = false;
			compares++;
			if (attempt == 1) {
				compares++;
				while (access1 || access2 || access3) {
					min = compare(number1, number2, number3);
					compares++;
					if (min == 1) {
						compares++;
						f1.write(number1);
						if (index1 == count_elements || g1.is_end()) access1 = false;
						compares += 2;
						if (access1 && !g1.is_end()) {
							compares++;
							number1 = g1.read();
							index1++;
						}
						else if (g1.is_end()) access1 = false;
						compares++;
					}
					else if (min == 2) {
						compares++;
						f1.write(number2);
						if (index2 == count_elements || g2.is_end()) access2 = false;
						compares += 2;
						compares += 2;
						if (access2 && !g2.is_end()) {
							number2 = g2.read();
							index2++;
						}
						else if (g2.is_end()) access2 = false;
					}
					else {
						compares++;
						f1.write(number3);
						if (index3 == count_elements || g3.is_end()) access3 = false;
						compares += 2;
						if (access3 && !g3.is_end()) {
							compares++;
							number3 = g3.read();
							index3++;
						}
						else if (g3.is_end()) access3 = false;
					}

					f1.write(" ");
					compares++;
				}
				attempt++;
			}
			else if (attempt == 2) {
				compares++;
				while (access1 || access2 || access3) {
					min = compare(number1, number2, number3);
					compares++;
					if (min == 1) {
						compares++;
						f2.write(number1);
						if (index1 == count_elements || g1.is_end()) access1 = false;
						compares += 2;
						compares++;
						if (access1 && !g1.is_end()) {
							compares++;
							number1 = g1.read();
							index1++;
						}
						else if (g1.is_end()) access1 = false;
						compares++;
					}
					else if (min == 2) {
						compares++;
						f2.write(number2);
						if (index2 == count_elements || g2.is_end()) access2 = false;
						compares += 2;
						if (access2 && !g2.is_end()) {
							compares++;
							number2 = g2.read();
							index2++;
						}
						else if (g2.is_end()) access2 = false;
						compares++;
					}
					else {
						compares++;
						f2.write(number3);
						if (index3 == count_elements || g3.is_end()) access3 = false;
						compares += 2;
						if (access3 && !g3.is_end()) {
							number3 = g3.read();
							index3++;
						}
						else if (g3.is_end()) access3 = false;
						compares++;
					}
					compares++;
					f2.write(" ");
				}
				attempt++;
			}
			else {
				compares++;
				while (access1 || access2 || access3) {
					compares++;
					min = compare(number1, number2, number3);
					if (min == 1) {
						compares++;
						f3.write(number1);
						if (index1 == count_elements || g1.is_end()) access1 = false;
						compares += 2;
						if (access1 && !g1.is_end()) {
							compares++;
							number1 = g1.read();
							index1++;
						}
						else if (g1.is_end()) access1 = false;
						compares++;
					}
					else if (min == 2) {
						compares++;
						f3.write(number2);
						if (index2 == count_elements || g2.is_end()) access2 = false;
						compares += 2;
						if (access2 && !g2.is_end()) {
							compares++;
							number2 = g2.read();
							index2++;
						}
						else if (g2.is_end()) access2 = false;
						compares++;
					}
					else {
						compares++;
						f3.write(number3);
						if (index3 == count_elements || g3.is_end()) access3 = false;
						compares += 2;
						if (access3 && !g3.is_end()) {
							compares++;
							number3 = g3.read();
							index3++;
						}
						else if (g3.is_end()) access3 = false;
						compares++;
					}
					compares++;
					f3.write(" ");
				}
				attempt = 1;
			}
			compares++;
		}

		count_elements *= 3;

		f1.end_write();
		f2.end_write();
		f3.end_write();
		g1.end_read();
		g2.end_read();
		g3.end_read();

		compares ++;
		if (f3.is_empty() && f2.is_empty()) {
			compares++;
			result = 1;
			break;
		}

		if (!f1.delete_last_symbol()) {
			cout << "Error delete g1: " << GetLastError() << endl;
			system("pause");
			return -1;
		}
		if (!f2.delete_last_symbol()) {
			cout << "Error delete g2: " << GetLastError() << endl;
			system("pause");
			return -1;
		}
		if (!f3.delete_last_symbol()) {
			cout << "Error delete g3: " << GetLastError() << endl;
			system("pause");
			return -1;
		}
		compares += 3;
	}
	stime = clock() - stime;
	if (result == 1)
		cout << "Отсортированный массив в файле f1" << endl;
	else cout << "Отсортированный массив в файле g1" << endl;
	stime = stime / CLOCKS_PER_SEC * 1000;
	cout << "TIME: " << stime << endl;
	cout << "Сравнений: " << compares << endl;
	cout << "Обращений к файлам: " << files << endl;
	
	system("pause");
	return 0;
}