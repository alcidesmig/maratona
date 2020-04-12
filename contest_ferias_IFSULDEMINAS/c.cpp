#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int sete = 0, q = 0, j = 0, k = 0, a = 0;
		string x;
		cin >> x;
		for (auto c : x) {
			if(c == '7') {
				sete++;
			}
			else if(c == 'Q' && q < sete) {
				q++;
			}
			else if(c == 'J' && j < q) {
				j++;
			}
			else if(c == 'K' && k < j) {
				k++;
			}
			else if(c == 'A' && a < k) {
				a++;
			}
		}
		cout << x.size() - a * 5 << endl;
	}
}
