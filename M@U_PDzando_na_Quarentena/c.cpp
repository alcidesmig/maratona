#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

/*
int max_2(int a, int b) {
	return a > b ? a : b;
}

int max_3(int a, int b, int c) {
	return max_2(max_2(a, b), c);
}

int cut_(int n, int a, int b, int c, int cont) {
	if (n == 0) {
		return cont;
	}
	if (n < 0 || (n - a < 0 && n - b < 0 && n - c < 0)) {
		return -1;
	}
	cont++;
	return max_3(cut_(n - a, a, b, c, cont), cut_(n - b, a, b, c, cont), cut_(n - c, a, b, c, cont));
}
*/

int cut(int n, int a, int b, int c, int * m) {
	if (a <= n) m[a] = 1;
	if (b <= n) m[b] = 1;
	if (c <= n) m[c] = 1;
	for (int i = 1; i <= n; i++) {
		//	if(i != n && (i == a || i == b || i == c)) continue;
		int x, y, z;
		x = y = z = -1;
		if (i - a >= 0) {
			x = m[i - a];
		}
		if (i - b >= 0) {
			y = m[i - b];
		}
		if (i - c >= 0) {
			z = m[i - c];
		}
		if(!(x == y && y == z && z == -1)) {
			m[i] = max(max(x, y), z) + 1;
		} else {
			m[i] = -1;
		}
	}
	/*for (int i = 1; i <= n; i++) {
		cout << i << ",";
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
		cout << m[i] << ",";
	}*/
	//cout << endl;
	return m[n];
}

int main() {
	int n, a, b, c;

	cin >> n >> a >> b >> c;

	int m[n + 1] = {0};
	int x = cut(n, a, b, c, m);

	cout << x << endl;
	return 0;
}
