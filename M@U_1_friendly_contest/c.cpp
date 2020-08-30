#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;

	list<int> x;

	int most_left = 0;
	int most_right = 0;
	map<int, int> shelf;

	char c;
	int y;
	cin >> c >> y;

	shelf[y] = 0;

	x.push_back(y);
	for (int i = 0; i < q - 1; i++) {
		cin >> c >> y;
		if (c == 'L') {
			shelf[y] = most_left--;
		} else if (c == 'R') {
			shelf[y] = most_right++;
		} else if (c == '?') {
			int dist_right = most_right - shelf[y];
			int dist_left = shelf[y] - (most_left);
			int ret = min(dist_left, dist_right);
			cout << ret << endl;
		}
	}

}