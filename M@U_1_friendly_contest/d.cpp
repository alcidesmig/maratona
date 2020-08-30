#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int sizes[n];
	for (int i = 0; i < n; i++) cin >> sizes[i];
	int cont = 0;
	int remain = k;
	int free = m;
	for (int i = n - 1; i >= 0; i--) {
		if (sizes[i] <= remain) {
			remain -= sizes[i];
			cont++;
		} else {
			if (!(--free)) break;
			remain = k - sizes[i];
			cont++;
		}
	}
	cout << cont << endl;

	return 0;
}