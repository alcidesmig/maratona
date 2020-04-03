#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long long n, m, s, x, y, h, soma_a = 0, soma_b = 0;
	bool relation;
	cin >> n >> m >> s;
	long long x0 = 0, y0 = 0, x1 = n, y1 = m;
	for(int i = 0; i < s; i++) {
		cin >> x >> y >> h;
		relation = !((y - y0) * (x1 - x0) - (x - x0) * (y1 - y0) < 0);
		if(relation) soma_a += h;
		else soma_b += h;
	}
	cout << soma_a << " " << soma_b << endl;
	return 0;
}
