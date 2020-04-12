#include <iostream>

using namespace std;

int main() {
	int x;
	string y;
	cin >> x;
	bool contem[4] = {false};
	for (int i = 0; i < x; i++) {
		contem[0] = false;
		contem[1] = false;
		contem[2] = false;
		contem[3] = false;
		cin >> y;
		for (int j = 0; j < y.size(); j++) {
			if (y[j] == 'Q') {
				contem[0] = 1;
			}
			else if (contem[0] && y[j] == 'J') {
				contem[1] = 1;
			}
			else if (contem[1] && y[j] == 'K') {
				contem[2] = 1;
			}
			else if (contem[2] && y[j] == 'A') {
				contem[3] = 1;
			}

		}
		cout << ((contem[0] && contem[1] && contem[2] && contem[3]) ? "Agora vai" : "Agora apertou sem abracar") << endl;
	}
}
