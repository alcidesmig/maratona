#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	double x[3];
	double y[3];

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

		double area_triang = abs((x[0] * y[1] + y[0] * x[2] + x[1] * y[2] -
		                          y[0] * x[1] - y[1] * x[2] - y[2] * x[0]) * 0.5);

		printf("%.3lf\n", area_triang);
	}
	return 0;
}

