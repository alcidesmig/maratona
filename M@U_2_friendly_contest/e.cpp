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
	for (int j = vec.back() % 2 == 0 ? vec.back() : vec.back() - 1; j > 0; j--) {
		int init = vec.size() - 1;
		int now = j, sum = j;
		while (now % 2 == 0 && init > 0) {
			now = now / 2;
			if (vec[--init] >= now) {
				sum += now;
			} else {
				break;
			}
		}
		if (sum > maximum) maximum = sum;
	}
	if (vec.back() > maximum) maximum = vec.back();
	cout << maximum << endl;

	return 0;
}
