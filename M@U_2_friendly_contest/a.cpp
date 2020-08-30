#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t, a, b, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> k;
		if (k % 2 != 0) {
			cout << ((k / 2) + 1) * a - k / 2 * b << endl;
		} else {
			cout << (k / 2) * a - k / 2 * b << endl;
		}
	}
	return 0;
}