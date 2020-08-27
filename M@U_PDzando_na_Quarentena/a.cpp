#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(int argc, char ** argv) {
	//int n = atoi(argv[1]);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int mat[n][4];
	memset(mat, sizeof(mat), 0);
	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[0][2] = 1;
	mat[0][3] = 0;

	int a, b, c, d;

	for (int i = 1; i < n - 1; i++) {
		a = 0;
		b = 0;
		c = 0;
		d = 0;

		a += mat[i - 1][1];
		a %= 1000000007;
		a += mat[i - 1][2];
		a %= 1000000007;
		a += mat[i - 1][3];
		a %= 1000000007;
		mat[i][0] = a;

		b += mat[i - 1][0];
		b %= 1000000007;
		b += mat[i - 1][2];
		b %= 1000000007;
		b += mat[i - 1][3];
		b %= 1000000007;
		mat[i][1] = b;

		c += mat[i - 1][0];
		c %= 1000000007;
		c += mat[i - 1][1];
		c %= 1000000007;
		c += mat[i - 1][3];
		c %= 1000000007;
		mat[i][2] = c;

		d += mat[i - 1][0];
		d %= 1000000007;
		d += mat[i - 1][1];
		d %= 1000000007;
		d += mat[i - 1][2];
		d %= 1000000007;
		mat[i][3] = d;

	}

	n -= 2;
	int sol = 0;

	sol += mat[n][0];
	sol %= 1000000007;
	sol += mat[n][1];
	sol %= 1000000007;
	sol += mat[n][2];
	sol %= 1000000007;

	cout << sol << endl;

	return 0;
}