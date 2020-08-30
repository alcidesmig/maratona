#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	pair<long long, int> array[n], array_sum[n];
	long long sum_all = 0;
	for (int i = 0; i < n; i++) {
		cin >> array[i].first;
		array[i].second = i;
		sum_all += array[i].first;
	}
	for (int i = 0; i < n; i++) {
		array_sum[i].first = sum_all - array[i].first;
		array_sum[i].second = i;
	}
	sort(array, array + n);

	list<int> good;

	int cont = 0;
	for (int i = 0; i < n; i++) {
		long long bigger = array[n - 1].first;
		if (array[n - 1].second == i) {
			bigger = array[n - 2].first;
		}
		if (array_sum[i].first - bigger == bigger)  {
			cont++;
			good.push_back(i);
		}
	}
	cout << cont << endl;
	if (cont) {
		for (auto const& x : good) {
			cout << x + 1 << " ";
		}
	}
	return 0;
}