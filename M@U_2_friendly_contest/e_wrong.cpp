#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, x;
	cin >> n;
	map<long long, int> cont;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cont[x]++;
	}

	vector<int> vec;

	for (auto& it : cont) {
		vec.push_back(it.second);
	}

	sort(vec.begin(), vec.end());

	// for (auto& it : vec) {
	// 	cout << it << " ";
	// }

	if (vec.size() == 1) {
		cout << vec[0] << endl;
		return 0;
	}
	int maximum = 0;
	int j = vec.size() - 2;
	do {
		long long init = vec[j + 1] - (vec[j + 1] % 2);
		long long sum = init;
		float last = init;
		for (int i = j; i >= 0; i--) {
			if (vec[i] >= last / 2.0) {
				sum += last / 2.0;
				last = last / 2.0;
			} else {
				break;
			}
		}
		if (sum > maximum) maximum = sum;
	} while (vec[j + 1] == vec[j--]);

	cout << maximum << endl;

	return 0;
}