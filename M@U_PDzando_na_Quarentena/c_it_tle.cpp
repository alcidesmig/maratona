#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

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
	if(n < 0 || (n-a<0 && n-b < 0 && n-c < 0)) {
		return -1;
	}
	cont++;
	return max_3(cut_(n - a, a, b, c, cont), cut_(n - b, a, b, c, cont), cut_(n - c, a, b, c, cont));
	
}

int main() {
	int n, a, b, c;

	cin >> n >> a >> b >> c;

	int x = cut_(n, a, b, c, 0);

	cout << x << endl;
	return 0;
}
