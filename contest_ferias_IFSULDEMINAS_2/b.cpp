#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

void swap(int * x, int a, int b) {
	int aux = x[a];
	x[a] = x[b];
	x[b] = aux;
}

int main() {
	int cont_5, i = 0, it = 0, x[10001], y[10001], atual = 0;
	string value_str;

	cin >> value_str;

	while (it < value_str.size()) {
		x[it] = (int) ((value_str[it]) - '0');
		it++;
	}

	for (i = 0; i < it; i++) {
		if (x[i] == 5) cont_5++;
		else y[atual++] = x[i];
	}
	for (i = 0; i < atual; i++) {
		if (y[i] == 7) break;
		cout << y[i];
	}
	for (int j = 0; j < cont_5; j++) {
		cout << 5;
	}
	for (int j = i; j < atual; j++) {
		cout << y[j];
	}

	cout << endl;

	return 0;
}
