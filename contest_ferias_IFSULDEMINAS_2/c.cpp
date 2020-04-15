#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<int> vet[], int v, int checked[], int * cont, int family[], int set_family) {
	checked[v] = 1;
	family[v] = set_family;
	(*(cont))++;
	for (int i = 0; i < vet[v].size(); i++) {
		if (!checked[vet[v][i]]) {
			dfs(vet, vet[v][i], checked, cont, family, set_family);
		}
	}
}

vector<int> connections(vector<int> vet[], int family[], int n) {
	int x = 0;
	int checked[n] = {0};
	vector<int> qtd;
	for (int i = 0; i < n; i++) {
		if (!checked[i]) {
			x = 0;
			dfs(vet, i, checked, &x, family, qtd.size());
			qtd.push_back(x);
		}
	}
	return qtd;
}

void add(vector<int> vet[], int u, int v) {
	vet[u].push_back(v); vet[v].push_back(u);
}

int main() {
	int n, m, a, b, x, count = 0, X, died;

	cin >> n >> m;

	vector<int> vet[n];

	int family[n] = { -1};

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		add(vet, a - 1, b - 1);
	}
	vector<int> conn = connections(vet, family, n);

	cin >> X;

	vector<int> deads;
	int dead = 0;

	for (int i = 0; i < X; i++) {
		dead = false;
		cin >> died;
		for (int j = 0; j < deads.size(); j++) {
			if (deads[j] == died)
				dead = true;
		}
		if (!dead) {
			deads.push_back(died);
			conn[family[died - 1]]--;
		}
	}

	sort(conn.begin(), conn.end());


	conn.erase(remove(conn.begin(), conn.end(), 0), conn.end());
	conn.shrink_to_fit();

	cout << "Quantidade de familias: " << conn.size() << "\n";
	cout << "Numero de habitantes em cada: ";

	for (int i = 0; i < conn.size(); i++) {
		if (i == conn.size() - 1 && conn.size() != 1) cout << " e ";
		else if (i != 0) cout << ", ";
		cout << conn[i];
	}

	if (conn.size() == 0) cout << "0";

	cout << endl;

	return 0;
}
