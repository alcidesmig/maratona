#include <bits/stdc++.h>

using namespace std;



int main() {
	int n;

	cin >> n;

	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int q;
	cin >> q;
	pair<int, int> queries[q];

	for (int i = 0; i < q; i++) {
		cin >> queries[i].first >> queries[i].second;
	}

	int pd[n][n] = {0};

	for (int i = 0; i < n; i++) {
		pd[0][i] = b[i];
		printf("%3d ", pd[0][i]);
	}
	cout << endl;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			pd[i][j] = pd[i - 1][j] ^ pd[i - 1][j + 1];
			printf("%3d ", pd[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < q; i++) {
		int qt = queries[i].second - queries[i].first;
		int last = 0;
		if (qt == 0) {
			cout << pd[0][queries[i].first - 1] << endl;
			continue;
		}
		for (int l = 0; l < qt; l++) {
			for (int k = queries[i].first - 1; k < queries[i].second - 1 - l; k++) {
				int z = pd[l + 1][k];
				//cout << z << endl;
				if (z > last) last = z;
			}
		}

		cout << last << endl;
	}


	return 0;
}