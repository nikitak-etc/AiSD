#include "stdafx.h"
#include <iostream>
using namespace std;
class glass {
	int capacity,
		value;
public:
	glass(int);
	void full();
	void pour();
	bool hit(int N);
	friend void pour(glass&, glass&);
	friend bool Aquarius(glass&, glass&, int N, int T);
};
int main() {
	setlocale(LC_ALL, "RUS");
	glass   A(6),
		B(8);
	int N = 4;

	if (Aquarius(A, B, N, 4))
		cout << "yes";
	else
		cout << "no";

	cin.get();
	return 0;
}

glass::glass(int C) {
	capacity = C;
	value = 0;
}
void glass::full() {
	value = capacity;
}
void glass::pour() {
	value = 0;
}
bool glass::hit(int N) {
	return N == value;
}

void pour(glass& g1, glass& g2) {
	int t = g1.capacity - g1.value;
	if (t <= g2.value) {
		g1.full();
		g2.value -= t;
	}
	else {
		g1.value += g2.value;
		g2.pour();
	}
}
bool Aquarius(glass& g1, glass& g2, int N, int T) {
	glass g(0), gg(0);
	if (T<0) return 0;
	if (g1.hit(N) || g2.hit(N))
		return 1;
	//наполняю А
	g.capacity = g1.capacity;
	g.value = g1.capacity;
	if (Aquarius(g, g2, N, T - 1)) {
		cout << "Наполняю А";
		return 1;
	}
	//наполняю В
	g.capacity = g2.capacity;
	g.value = g2.capacity;
	if (Aquarius(g1, g, N, T - 1)) {
		cout << "Наполняю Б";
		return 1;
	}
	//выливаю из А
	g.capacity = g1.capacity;
	g.value = 0;
	if (Aquarius(g, g2, N, T - 1)) {
		cout << "Выливаю из А";
		return 1;
	}
	//выливаю из В
	g.capacity = g2.capacity;
	g.value = 0;
	if (Aquarius(g1, g, N, T - 1)) {
		cout << "Выливаюю из Б";
		return 1;
	}
	//переливаю из В в А
	g.capacity = g1.capacity;
	g.value = g1.value;
	gg.capacity = g2.capacity;
	gg.value = g2.value;
	pour(g, gg);
	if (Aquarius(g, gg, N, T - 1)) {
		cout << "Переливаю из Б в А";
		return 1;
	}
	//переливаю из А в В
	g.capacity = g1.capacity;
	g.value = g1.value;
	gg.capacity = g2.capacity;
	gg.value = g2.value;
	pour(gg, g);
	if (Aquarius(g, gg, N, T - 1)) {
		cout << "Переливаю из А в Б";
		return 1;
	}
	return 0;

}