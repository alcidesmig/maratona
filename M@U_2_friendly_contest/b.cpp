#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int data[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	int cont = 0;
	for (int i = 1; i < n - 1; i++) {
		if (data[i] == 0) {
			if (data[i + 1] == 1 && data[i - 1] == 1) {
				data[i + 1] = 0;
				cont++;
			}
		}
	}
	cout << cont << endl;

	return 0;
}