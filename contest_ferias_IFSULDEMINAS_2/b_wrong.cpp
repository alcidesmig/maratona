#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
typedef struct {
	int value;
	int qtd;
} data;

void swap(data * x, int a, int b) {
	data aux = x[a];
	x[a] = x[b];
	x[b] = aux;
}

bool diff(int a, int b) {
	return abs(a - b) == 2;
}

// 7333333335

int main() {
	int n, value, it = 0, non_zero = 0, x[10001], multiply;
	string value_str;
	it = 0;

	cin >> value_str;

	while (it < value_str.size()) {
		x[it] = (int) ((value_str[it]) - '0');
		it++;
	}

	data y[it];
	int aux = 0;
	int i = 0;
	while (aux < it) {
		y[i].value = x[aux];
		y[i].qtd = 0;
		int current = aux;
		while (x[current] == x[aux]) {
			y[i].qtd++;
			aux++;
		}
		i++;
	}

	int index_max = i;

	for (i = 0; i < index_max; i++) {
		//	if (y[i].value == 7)

		for (int j = i; j < index_max - 1; j++) {
			if (y[j].value > y[j + 1].value) {
				if (diff(y[j].value, y[j + 1].value)) {
					swap(y, j, j + 1);
				}
			}
			if (j + 2 < it && y[j].value > y[j + 1].value &&
			        !diff(y[j].value, y[j + 1].value) &&
			        diff(y[j + 1].value, y[j + 2].value)) {
				swap(y, j + 1, j + 2);
				swap(y, j, j + 1);
			}
			//	if (y[j].value == 5) {
			//		for(int k =j; k > i; k--) {
			//			swap(y, k, k-1);
			//		}
			//	}

		}
	}

	for (int j = 0; j < index_max; j++) {
		for (int k = 0; k < y[j].qtd; k++) cout << y[j].value;
	}
	cout << endl;

	return 0;
}
