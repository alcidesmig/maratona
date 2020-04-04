#include <iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n && n != 0) {
		int netos[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			cin >> netos[i];
		}
		int maior = 1, menor = netos[0] + netos[2 * n - 1];
		for (int i = 0; i < n; i++) {
			// Como já está ordenado, faz o balanceamento pegando dos extremos
			int value = netos[i] + netos[2 * n - (i + 1)];
			// E verifica se é maior ou menor que os já registrados
			if (value < menor) menor = value;
			if (value > maior) maior = value;
		}
		cout << maior << " " << menor << endl;
	}
	return 0;
}
