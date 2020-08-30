#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	int array[n];

	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	int cont = 0, zero = 0;
	int i = 0, k = 0;
	while (i < n) {
		bool find = false;
		for (k = min(zero + r - 1, n - 1); k >= zero - r + 1 && k >= 0; k--) {
			if (array[k] == 1) {
				i = k + r;
				zero = k + r;
				find = true;
				break;
			}
		}
		if (!find) {
			cout << -1 << endl;
			return 0;
		}
		cont++;
	}

	// for(int i = 0; i < n; i++){
	// 	cout << array[i] << " ";
	// }
	//cout << endl;

	cout << cont << endl;
	return 0;
}
