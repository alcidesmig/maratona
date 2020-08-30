#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	int x, y, z, w;

	for (int i = 0; i < t; i++) {
		cin >> x >> y >> z >> w;
		int total = x / y;
		int remove = (w / y) - (z / y);
		if (z % y == 0) remove++;
		cout << total - remove << endl;
	}

}
