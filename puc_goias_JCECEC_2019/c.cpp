#include <iostream>
#include <string>

using namespace std;

bool palindromo(const string &s) {
	if (*s.cbegin() == *(s.cend() - 1)) {
		if (s.size() == 1 || s.size() == 2) return true;
		return palindromo(s.substr(1, s.size() - 2));
	}
	return false;
}

bool in(string & x, string & y) {
	if (x == y) return true;
	int size_x = x.size();
	for (int i = 0; i < y.size() - size_x + 1; i++) {
		if (x == y.substr(i, size_x)) {
			return true;
		}
	}
	return false;
}

int main() {


	int n, m, cont, current_size;
	bool flag;

	while (cin >> n >> m) {
		flag = true;
		cont = 0;
		string s, V[m], current;
		cin >> s;
		s = s.substr(0, n);
		for (int i = 0; i < m; ++i) {
			cin >> V[i];
		}
		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; j < s.size() - i + 1; j++) {
				// Pega substring atual
				current = s.substr(i, j);
				flag = true;
				// Se for palíndromo
				if (palindromo(current)) {
					current_size = current.size();
					for (int k = 0; k < m; k++) {
						if (current_size < V[k].size()) {
							// Se não couber V[k] dentro, pula para k+1
							continue;
						}
						// E tiver V[k] dentro, marca como falso
						if (in(V[k], current)) {
							flag = false;
							break;
						}

					}
					// Se chegar flag = true, não existe
					// V[k] dentro de current
					if (flag) {
						cont++;
					}
				}
			}
		}

		cout << cont << endl;

		cont = 0;
	}
	return 0;
}
