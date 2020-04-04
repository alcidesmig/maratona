#include <stdio.h>

int main() {
	int h, m;
	// Formata de acordo com o exigido pelo exercício
	while (scanf("%d %d", &h, &m) != EOF)
		printf("%02d:%02d\n", (h / 30), (m / 6));
	return 0;
}