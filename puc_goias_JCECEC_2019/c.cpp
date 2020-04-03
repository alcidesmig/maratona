#include <iostream>
#include <string>

using namespace std;

bool palindromo(const string &s) {
	if(*s.cbegin() == *(s.cend()-1)) {
		if(s.size() == 1 || s.size() == 2) return true;
		return palindromo(s.substr(1, s.size() - 2));
	}
	return false;
}

bool in(string & x, string & y) {
	if(x == y) return true;
	int size_x = x.size();
	for(int i = 0; i < y.size() - size_x + 1; i++) {
		// cout << "entrou for " << i << " " << size_x << " " << y << endl;
		if(x == y.substr(i, size_x)){
			return true;
		}
		// cout << "saiu for" << endl;
	}	
	return false;
}

int main() {


	int n, m, cont, current_size;
	bool flag;
	
	while(cin >> n >> m) {
		flag = true;
		cont = 0;
		string s, V[m];
		cin >> s;
		s = s.substr(0, n);
		for (int i = 0; i < m; ++i) {
		 	cin >> V[i];
		}
		for (int i = 0; i < s.size(); i++) {
			// cout << "I: " << i << " " << s.size() << endl;
			for(int j = 1; j < s.size() - i + 1; j++) {
				string current = s.substr(i, j);
				// cout << "Current: " << current << endl;
				flag = true;
				if(palindromo(current)) {
					// cout << "Palindromo! " << current << endl;
					current_size = current.size();
					for (int k = 0; k < m; k++) {
						if(current_size < V[k].size()) {
							// cout << "Current_size < vi_size: " << current << " - " << V[k] << endl;
							continue;
						}
						// cout << "entrou " << V[k] << "-" << current << endl;
						if(in(V[k], current)) {
							flag = false;
							break;
						}
						// cout << "passou" << endl;
					}
					if(flag) {
						cont++;
						// cout << "Adicionado! -> " << current << endl;
					}
				}
			}
		}

		cout << cont << endl;
		
		cont = 0;
	}
	return 0;
}