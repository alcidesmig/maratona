#include <iostream>
#include <math.h>

using namespace std;

double dist(const int & x_at, const int & y_at, const int & xf, const int & yf) {
	return sqrt(pow(xf - x_at, 2) + pow(yf - y_at, 2));
}

int main() {
	int n, k, xf, yf, x_at = 0, y_at = 0, trap = 0, cont = 0;
	double aux;
	char c;
	bool farsa_encontrada = false;

	cin >> n >> k >> xf >> yf;

	aux = dist(x_at, y_at, xf, yf);
	if (aux < k)
		while (cont++ < n) {
			cin >> c;
			switch (c) {
			case 'C':
				x_at++;
				break;
			case 'B':
				x_at--;
				break;
			case 'D':
				y_at++;
				break;
			case 'E':
				y_at--;
				break;
			}

			if ((aux = dist(x_at, y_at, xf, yf)) == 0) {
				cout << "Sucesso" << endl;
				return 0;
			}

			if (!farsa_encontrada) trap++;
			if (aux > k) farsa_encontrada = true;
		}
	cout << "Trap " << (trap == 0 ? 1 : trap) << endl;
	return 0;
}