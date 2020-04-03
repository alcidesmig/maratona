#include <iostream>

using namespace std;

int main() {
	int n, s, last_num = 0;
	pair<int, int> m[100*100];
	int backup=2, backup_pos = 1;
	int x = 48, y = 50;
	int x_orig = 49, y_orig = 49;
	bool cancelaFirst = false;
	int comeca_for = 2;
	int  cont_vezes = 0;
	int pos = 1;
	int cont = 2;
	while(cin >> n >> s) {
		int amount = 50 - (n/2 + 1);
		
		if(s <= last_num) {
			cout << m[s].first-amount << " " << m[s].second-amount << endl;
			continue;
		}
		
		for (int i = comeca_for; i < 2*100*100+3; i+= 2) {
			for (int j = 0; j < i; ++j) {
				if(!cancelaFirst)	{
					m[pos].first = x;
					m[pos].second = y;
				}
				pos++;
				x++;
				cancelaFirst = false;
			}
			for (int j = 0; j < i; ++j) {
				m[pos].first = x;
				m[pos++].second = y;
				y--;
			}
			for (int j = 0; j < i; ++j) {
				m[pos].first = x;
				m[pos++].second = y;
				x--;
			}
			for (int j = 0; j < i; ++j) {
				m[pos].first = x;
				y++;
			}
			m[pos].first = x;
			m[pos].second = y;
			int pos_max = pos;
	
			x = x_orig - cont;
			y = y_orig + cont++;
			pos = (i+1) * (i+1);
			cancelaFirst = true;
			if(pos_max >= n*n) {
				m[1].first = 49;
				m[1].second = 49;
				comeca_for = i + 2;
				last_num = n*n;
				cout << m[s].first-amount << " " << m[s].second-amount << endl;
				break;
			}
		}
	}
	
	return 0;
}
/*
73 74 75 78 77 78 79 80 81
72 43 44 45 46 47 48 49 50
71 42 21 22 23 24 25 26 51
70 41 20 07 08 09 10 27 52
69 40 19 06 01 02 11 28 53
68 39 18 05 04 03 12 29 54
67 38 17 16 15 14 13 30 55
66 37 36 35 34 33 32 31 56
65 64 63 62 61 60 59 58 57
*/
