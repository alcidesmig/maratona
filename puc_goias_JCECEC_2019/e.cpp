#include <iostream>
#include <string>

using namespace std;

int main() {
	string x, y;
	while(getline(cin, x)) {
		y = "";
		for(int i = 0; i < x.size() - 1; i++) {
			if(x[i] == ' ')
				if(x[i + 1] == ',' || x[i + 1] == '.')
					continue;
			y += x[i];
		}
		y += x[x.size() - 1];
		cout << y << endl;
	}
	return 0;
}
