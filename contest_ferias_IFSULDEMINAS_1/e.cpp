#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int c[n];
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	int dispo = n - 2;

	int maior = 0;
	int i = 0, j = n - 1;
	int bills = c[0], majin = c[n - 1];
	while (dispo != 1 && i < j) {
		if (bills == majin) {
			if (bills > maior)
				maior = bills;
			bills += c[++i];
			majin += c[--j];
			dispo -= 2;
		}
		if (bills < majin) {
			bills += c[++i];
			dispo--;
		}
		if (majin < bills) {
			majin += c[--j];
			dispo--;
		}
	}
	cout << maior << endl;
	return 0;
}


