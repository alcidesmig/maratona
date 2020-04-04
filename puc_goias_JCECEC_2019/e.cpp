#include <iostream>
#include <string>

using namespace std;

int main() {
	string x, y;
	while (getline(cin, x)) {
		y = "";
		for (int i = 0; i < x.size() - 1; i++) {
			// Se tiver espaço
			if (x[i] == ' ') 
				// Seguido de vírgula ou ponto
				if (x[i + 1] == ',' || x[i + 1] == '.')
					// Não adiciona
					continue;
			// Se não, adiciona
			y += x[i];
		}
		y += x[x.size() - 1];
		cout << y << endl;
	}
	return 0;
}
