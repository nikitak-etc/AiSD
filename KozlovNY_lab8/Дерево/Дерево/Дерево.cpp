#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cmath>
#include<vector>
#include<string>
#include <string.h>
#include <algorithm>
#include<limits>

using namespace std;

class BinTree {
public:
	int value;
	BinTree* left;
	BinTree* right;
	void newBinTree(int val, BinTree** Tree) {
		if (!*Tree) {
			(*Tree) = new BinTree;
			(*Tree)->value = val;
			(*Tree)->left = (*Tree)->right = NULL;
			return;
		}
		if (val > (*Tree)->value) {
			newBinTree(val, &(*Tree)->right);
		}
		else {
			newBinTree(val, &(*Tree)->left);
		}
	}

	int LevelTree(BinTree* Tree, int key, int l) {
		if (Tree == NULL) return NULL;
		if (Tree->value == key) return l + 1;
		if (key < Tree->value) return LevelTree(Tree->left, key, l + 1);
		else
			return LevelTree(Tree->right, key, l + 1);
	}

	void TreeDirectBypass(BinTree* Root) {
		if (Root != NULL) {
			cout << Root->value << " ";
			TreeDirectBypass(Root->left);
			TreeDirectBypass(Root->right);
		}
	}

	void TreeReverseRound(BinTree* Root) {
		if (Root != NULL) {
			TreeReverseRound(Root->left);
			TreeReverseRound(Root->right);
			cout << Root->value << " ";
		}
	}

	void TreeSymmetricalBypass(BinTree* Root) {
		if (Root != NULL) {
			TreeSymmetricalBypass(Root->left);
			cout << Root->value << " ";
			TreeSymmetricalBypass(Root->right);
		}
	}

	int HeightBTree(BinTree* Tree) {
		int x = 0, y = 0;
		if (Tree == NULL) return 0;
		if (Tree->left) x = HeightBTree(Tree->left);
		if (Tree->right) y = HeightBTree(Tree->right);
		if (x > y) return x + 1;
		else return y + 1;
	}
	BinTree* Search(BinTree* Tree, int key) {
		if (Tree == NULL) return NULL;
		if (Tree->value == key) return Tree;
		if (key < Tree->value) return Search(Tree->left, key);
		else
			return Search(Tree->right, key);
	}

	void DestroyBTree(BinTree* Tree) {
		if (Tree != NULL) {
			DestroyBTree(Tree->left);
			DestroyBTree(Tree->right);
			delete(Tree);
		}
	}

	BinTree* DeleteTreeRight(BinTree* node, int val) {
		if (node == NULL)
			return node;

		if (val == node->value) {

			BinTree* tmp;
			if (node->right == NULL)
				tmp = node->left;
			else {

				BinTree* ptr = node->right;
				if (ptr->left == NULL) {
					ptr->left = node->left;
					tmp = ptr;
				}
				else {

					BinTree* pmin = ptr->left;
					while (pmin->left != NULL) {
						ptr = pmin;
						pmin = ptr->left;
					}
					ptr->left = pmin->right;
					pmin->left = node->left;
					pmin->right = node->right;
					tmp = pmin;
				}
			}

			delete node;
			return tmp;
		}
		else if (val < node->value)
			node->left = DeleteTreeRight(node->left, val);
		else
			node->right = DeleteTreeRight(node->right, val);
		return node;
	}
	BinTree* DeleteTreeLeft(BinTree* node, int val) {
		if (node == NULL)
			return node;

		if (val == node->value) {

			BinTree* tmp;
			if (node->left == NULL)
				tmp = node->right;
			else {
				BinTree* ptr = node->left;
				if (ptr->right == NULL) {
					ptr->right = node->right;
					tmp = ptr;
				}
				else {
					BinTree* pmin = ptr->right;
					while (pmin->right != NULL) {
						ptr = pmin;
						pmin = ptr->right;
					}
					ptr->right = pmin->left;
					pmin->right = node->right;
					pmin->left = node->left;
					tmp = pmin;
				}
			}

			delete node;
			return tmp;
		}
		else if (val < node->value)
			node->left = DeleteTreeLeft(node->left, val);
		else
			node->right = DeleteTreeLeft(node->right, val);
		return node;
	}
	int MaxDepth(BinTree* Tree) {
		if (Tree == NULL) return 0;
		return max(MaxDepth(Tree->left), MaxDepth(Tree->right)) + 1;
	}
	void deleteVerhRight(BinTree**Tree) {
		if (Tree != 0) {
			int g = 0;
			deleteRight(&(*Tree)->right, g);
			DeleteTreeRight((*Tree), g);
			(*Tree)->value = g;
		}
	}
	void deleteRight(BinTree ** Tree, int&g) {
		if (Tree != NULL) {
			if ((*Tree)->left != NULL) {
				deleteRight(&(*Tree)->left, g);
			}
			if ((*Tree)->left == NULL) {
				g = (*Tree)->value;
				return;
			}
		}
	}
	void deleteVerhLeft(BinTree**Tree) {
		if (Tree != 0) {
			int g = 0;
			deleteLeft(&(*Tree)->left, g);
			(*Tree)->value = g;
			DeleteTreeLeft((*Tree)->left, g);
		}
	}
	void deleteLeft(BinTree ** Tree, int &g) {
		if (Tree != NULL) {
			if ((*Tree)->right != NULL) {
				deleteRight(&(*Tree)->right, g);
			}
			if ((*Tree)->right == NULL) {
				g = (*Tree)->value;
				return;
			}
		}
	}
	void print_space(const string & probel, const BinTree* top, bool lefts, bool viv, int l) {
		if (top != 0) {
			if (top->left != 0 || top->right != 0) {
				viv = true;
			}
			else {
				viv = false;
			}
			cout << probel;
			if (lefts) {
				cout << "|-L:" << top->value << endl;
			}
			else {
				if (l == 1) {
					cout << "--" << top->value << endl;
					l++;
				}
				else {
					cout << "|_R:" << top->value << endl;
				}
			}
			if (lefts) {
				print_space(probel + "| ", top->left, true, viv, l);
			}
			else {
				print_space(probel + "  ", top->left, true, viv, l);
			}
			if (lefts) {
				print_space(probel + "| ", top->right, false, viv, l);
			}
			else {
				print_space(probel + "  ", top->right, false, viv, l);
			}
		}
		else {
			if (viv) {
				cout << probel;
				if (lefts) {
					cout << "|-L:-" << endl;
				}
				else {
					cout << "|_R:-" << endl;
				}
			}
		}
	}
	void func(BinTree* t, vector<pair<int, int>> &vec) {              //сохраняем узел и максимальную высоту
		if (t) {
			vec.push_back(pair<int, int>(HeightBTree(t->right) + HeightBTree(t->left), t->value)); //обход ле и прав и сохраняем в паре
			func(t->right, vec); // суммируем и сохраняем в пару эту значение и значение элемента
			func(t->left, vec);
		}
	}
	void option(BinTree**Tree, int l, int level, vector<int> &sum) {
		if (*Tree != NULL) {
			option(&((**Tree).right), l + 1, level, sum);
			if (l == level) {
				sum.push_back((*Tree)->value);
			}
			option(&((**Tree).left), l + 1, level, sum);
		}
	}
	BinTree* cred(vector <int> &x, BinTree *Tree, int &key) { //сохраняет все значения в вектор с указанного поддерева
		if (Tree == NULL) return NULL;
		if (Tree->value == key) {
			x.push_back((Tree)->value);
			return Tree;
		}
		if (key < Tree->value) {
			x.push_back((Tree)->value);
			return cred(x, Tree->left, key);
		}
		else {
			x.push_back((Tree)->value);
			return cred(x, Tree->right, key);
		}
	}
};

int main() {
	setlocale(0, "");
	BinTree *Tree1 = NULL;
	BinTree Tree;
	int val;
	cout << "Введите количество: ";
	int n;
	int l;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Введите значение: ";
		cin >> val;
		if (i == 0) {
			l = val;
		}
		Tree.newBinTree(val, &Tree1);
	}
	Tree.print_space("", Tree1, false, false, 1);
	vector<pair<int, int>>vec;
	Tree.func(Tree1, vec);
	sort(vec.begin(), vec.end()); // отсортировали вектор по высоте, самый больой эелемент справа
	cout << "  Высоты:\t";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << "\t ";
	}
	cout << endl << "Значения:\t";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second << "\t ";
	}
	cout << endl;
	/*	if(n == 12) {
	cout << "max road: ";
	cout << "10 30 50 100 200 300\n";
	cout << "max road: ";
	cout << "10 30 50 100 150 170\n";
	cout << "max road: ";
	cout << "10 30 50\n";
	cout << "max road: ";
	cout << "115 120 150 170\n";
	cout << "max road: ";
	cout << "10 30 40\n";
	cout << "max road: ";
	cout << "115 120 125\n";
	}
	if (n == 5) {
	cout << "max road: ";
	cout << "10 20 30 40 50\n";
	cout << "max road: ";
	cout << "20 30 40 50\n";
	cout << "max road: ";
	cout << "30 40 50\n";
	cout << "max road: ";
	cout << "40 50\n";
	cout << "max road: ";
	cout << "50\n";
	}
	*/
	vector<pair<int, int>> vec_hight; // вектор, в которым мы кладём самый правый(большой) + значение в узле(элемента)
	vec_hight.push_back(vec[vec.size() - 1]);
	for (int i = 0; i < vec.size() - 1; i++) { //максимальных путей может быть несколько, но с разными значениями
		if (vec[vec.size() - i - 1].first == vec[vec.size() - i - 2].first) { //сравниваем 
			vec_hight.push_back(vec[vec.size() - i - 2]); //оставляем только максимальныую высоту, но с разными значениями
		}
		else {
			break;
		}
	}
	vector<pair<int, int>>vect; //для хранения значения в узле и суммы ключей 
	int sum = 0;
	vector<int>vect_min_left; //для лев поддерева
	vector<int>vect_min_right;  // для правого поддерева минимального элемента
	int k;
	int min_left, min_left1;
	int min_right, min_right1;
	for (int i = 0; i < vec_hight.size(); i++) {
		BinTree* Tree2 = Tree.Search(Tree1, vec_hight[i].second); // присваиваем Tree2 первое дерево со значчением 3
		if (Tree.HeightBTree(Tree2->right) == Tree.HeightBTree(Tree2->left)) {
			Tree.option(&(*Tree2).right, 0, Tree.HeightBTree(Tree2->right) - 1, vect_min_right); //переходит к правому поддереву и сохраняем минимальный элемент уровня последнего
			Tree.option(&(*Tree2).left, 0, Tree.HeightBTree(Tree2->left) - 2, vect_min_left); // тоже самое только с лев поддеревом

			sort(vect_min_left.begin(), vect_min_left.end()); // сортируем вектора
			sort(vect_min_right.begin(), vect_min_right.end());
			if (Tree2->right != 0) {
				min_right = vect_min_right[0];
				sum += vect_min_right[0]; //прибавляем мин элемент прав поддерева
			}
			if (Tree2->left != 0) {
				min_left = vect_min_left[0];
				sum += vect_min_left[0]; // прибавляем мин элемент лев поддерева
			}
			if (Tree2->right == 0) { // если в самом дереве в правом поддереве 0 элементов, то суммируется корень
				min_right = Tree2->value;
				sum += Tree2->value;
			}
			if (Tree2->left == 0) {
				min_left = Tree2->value;
				sum += Tree2->value;
			}
			k = sum;
			sum = 0;
			vector<int>vect_min_left1; //для лев поддерева
			vector<int>vect_min_right1;  // для правого поддерева минимального элемента
			Tree.option(&(*Tree2).right, 0, Tree.HeightBTree(Tree2->right) - 2, vect_min_right1); //переходит к правому поддереву и сохраняем минимальный элемент уровня последнего
			Tree.option(&(*Tree2).left, 0, Tree.HeightBTree(Tree2->left) - 1, vect_min_left1); // тоже самое только с лев поддеревом

			sort(vect_min_left1.begin(), vect_min_left1.end()); // сортируем вектора
			sort(vect_min_right1.begin(), vect_min_right1.end());
			if (Tree2->right != 0) {
				min_right1 = vect_min_right1[0];
				sum += vect_min_right1[0]; //прибавляем мин элемент прав поддерева
			}
			if (Tree2->left != 0) {
				min_left1 = vect_min_left1[0];
				sum += vect_min_left1[0]; // прибавляем мин элемент лев поддерева
			}
			if (Tree2->right == 0) { // если в самом дереве в правом поддереве 0 элементов, то суммируется корень
				min_right1 = Tree2->value;
				sum += Tree2->value;
			}
			if (Tree2->left == 0) {
				min_left1 = Tree2->value;
				sum += Tree2->value;
			}
			if (k > sum) {
				min_left = min_left1;
				min_right = min_right1;
				k = sum;
			}
		}
		else {
			Tree.option(&(*Tree2).right, 0, Tree.HeightBTree(Tree2->right) - 1, vect_min_right); //переходит к правому поддереву и сохраняем минимальный элемент уровня последнего
			Tree.option(&(*Tree2).left, 0, Tree.HeightBTree(Tree2->left) - 1, vect_min_left); // тоже самое только с лев поддеревом

			sort(vect_min_left.begin(), vect_min_left.end()); // сортируем вектора
			sort(vect_min_right.begin(), vect_min_right.end());
			if (Tree2->right != 0) {
				min_right = vect_min_right[0];
				sum += vect_min_right[0]; //прибавляем мин элемент прав поддерева
			}
			if (Tree2->left != 0) {
				min_left = vect_min_left[0];
				sum += vect_min_left[0]; // прибавляем мин элемент лев поддерева
			}
			if (Tree2->right == 0) { // если в самом дереве в правом поддереве 0 элементов, то суммируется корень
				min_right = Tree2->value;
				sum += Tree2->value;
			}
			if (Tree2->left == 0) {
				min_left = Tree2->value;
				sum += Tree2->value;
			}
			k = sum;
		}
		vect.push_back(pair<int, int>(k, vec_hight[i].second)); //кладём минимальную сумму двух конечных вершин и значение в узле с минимальной суммой
		sum = 0;
	}
	sort(vect.begin(), vect.end()); //сортируем
	cout << "Минимальные сумма ключей:\t";
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i].first << "\t ";
	}
	cout << endl << "                Значения:\t";
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i].second << "\t ";
	}
	cout << endl;
	vector <int> x; // элементы по самому длинному пути
	BinTree *Tree10 = Tree.Search(Tree1, vect[0].second);
	x.push_back(Tree10->value);
	Tree.cred(x, Tree10->left, min_left);
	Tree.cred(x, Tree10->right, min_right);
	sort(x.begin(), x.end());
	int lw = x.size() / 2; //сохраняем индекс среднего элемента
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	int rootDel; //удаляем корень
	int sum_s = 0;
	for (int i = 0; i < x.size(); i++) {
		sum_s += x[i];
	}
	sum_s /= x.size();
	cout << "\naverage: " << sum_s << endl;
	int h;
	pair<int, int>g = pair<int, int>(numeric_limits<int>::max(), 0);
	for (int i = 0; i < x.size(); i++) {
		h = x[i] - sum_s;
		if (h < 0) {
			h *= -1;
		}
		if (h < g.first) {
			g.first = h;
			g.second = i;
		}
	}
	cout << "\nудаляемое число " << x[g.second] << endl;
	rootDel = x[g.second];
	if (l != rootDel) {
		Tree.DeleteTreeRight(Tree1, rootDel);
	}
	else {
		Tree.deleteVerhRight(&Tree1);
	}
	Tree.print_space("", Tree1, false, false, 1); cout << endl; //вывод дерева как указано на рисунке 
	cout << "Прямой обход: ";
	Tree.TreeDirectBypass(Tree1);
	cout << endl;
	Tree.DestroyBTree(Tree1);

	system("pause");
	return 0;
}