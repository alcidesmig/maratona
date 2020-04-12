// Utiliza a fórmula de Kamenetsky para retornar o número
// de digitos de um fatorial

#include <iostream>
#include <math.h>

#define ll long long

using namespace std;


ll fact(int x)
{
	if (x < 2) return 1;

	// Kamenetsky
	long long aux = ((x * log10(x / M_E) + log10(2 * M_PI * x) / 2.0));
	
	return floor(aux) + 1;
}


int main() {
	int x;
	cin >> x;
	cout << fact(x) << endl;
	return 0;
}
