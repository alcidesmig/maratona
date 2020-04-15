#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int fat(int x) {
	if (x == 1 || x == 0) return 1;
	return x * fat(x - 1);
}

long long calc(long long len) {
	return (len - 1) * pow(10, len - 2);
}

int char2int(char x) {
	return (int) x - 48;
}

long long f(string x, int value) {
	if (x.size() == 1)
		return (char2int(x[0]) >= value);

	int len = x.size();

	long long partial = char2int(x[0]) * calc(len);
	if (char2int(x[0]) == value) {
		x.erase(0, 1);
		partial += stoi(x) + 1;
		return partial + f(x, value);
	} if (char2int(x[0]) > value) {
		return partial + pow(10, len - 1) + f(x.erase(0, 1), value);
	} else { // (char2int(x[0]) < value)
		return partial + f(x.erase(0, 1), value);
	}
}

int main() {
	string x;

	cin >> x;
	string y = x;

	long long v_7 = f(x, 7), v_1 = f(x, 1);
	
	cout << v_1 + v_7 << endl;

	return 0;
}
