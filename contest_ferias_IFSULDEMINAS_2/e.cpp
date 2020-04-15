#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, value, it = 0, non_zero = 0, digits[1000], multiply;
	string value_str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		it = non_zero = 0;
		multiply = 0;

		cin >> value_str;

		while (it < value_str.size()) {
			digits[it] = (int) ((value_str[it]) - '0');
			it++;
		}

		sort(digits, digits + it);

		while (digits[non_zero++] == 0);

		if (digits[0] == 0) {
			digits[0] = digits[non_zero - 1];
			digits[non_zero - 1] = 0;
		}

		for (int j = 0; j < it; j++) {
			cout << digits[j];
		}
		cout << endl;
	}


	return 0;
}
