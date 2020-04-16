#include <iostream>

using namespace std;

int mod(string x, int div)
{
	int aux = 0;

	for (int i = 0; i < x.size(); i++) aux = (aux * 10 + (int) x[i] - '0') % div;

	return aux;
}

int main() {
	string x;
	long div;

	cin >> x >> div;
	cout << mod(x, div) << endl;

	return 0;
}
