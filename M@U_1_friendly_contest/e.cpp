#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

int main() {
	string aux_a, aux_b;
	int n, m;

	cin >> n >> m;
	cin >> aux_a >> aux_b;
	long long a[n], b[m], sum[m];
	b[0] = aux_b[0] == '0' ? 0 : 1;
	for (int i = 1; i < aux_b.size(); i++) {
		b[i] = b[i - 1] + (aux_b[i] == '0' ? 0 : 1);
	}

	long long power = 1;
	long long result = 0;
	for (int i = aux_a.size() - 1; i >= 0 ; i--) {
		if (aux_a[i] == '1') {
			result += (power * (m - n + i >= 0 ? b[m - n + i] : 0)) % mod;
		}
		cout << m - n + i << " " << endl;

		power = (power * 2) % mod;
	}

	cout << result << endl;
	return 0;
}

