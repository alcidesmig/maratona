#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main() {
	string x;
	int n;

	cin >> x;
	cin >> n;
	pair<int, int> queries[n];
	for(int i = 0; i < n; i++) {
		cin >> queries[i].first >> queries[i].second;
	}

	int matriz[x.size()] = {0};
	matriz[0] = (x[0] == x[1] ? 1 : 0);
	for(int i = 1; i < x.size(); i++) {
		matriz[i] = matriz[i-1] + (x[i] == x[i+1] ? 1 : 0);
	}
	for(int i = 0; i < n; i++) {
		int aux = queries[i].first - 2 >= 0 ? matriz[queries[i].first -2] : 0;
		int aux_2 = queries[i].second - 2 >= 0 ? matriz[queries[i].second -2] : 0;
		cout << aux_2 - aux << endl;
	}

	return 0;
}