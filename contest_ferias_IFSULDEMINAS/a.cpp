#include <iostream>

using namespace std;

int main() {
	int x;
	string y;
	cin >> x;
	bool contem[4] = {false};
	for(int i = 0; i < x; i++) {
		contem[0] = false;
		contem[1] = false;
		contem[2] = false;
		contem[3] = false;
		cin >> y;
		for(int j = 0; j < y.size(); j++) {
			if(y[j] == 'A'){
				contem[0] = 1;
			}
			else if(y[j] == 'Q'){
				contem[1] = 1;
			}
			else if(y[j] == 'J'){
				contem[2] = 1;
			}
			else if(y[j] == 'K'){
				contem[3] = 1;
			}

		}
		cout << ((contem[0] && contem[1] && contem[2] && contem[3]) ? "Aaah muleke" : "Ooo raca viu") << endl;
	}
}
