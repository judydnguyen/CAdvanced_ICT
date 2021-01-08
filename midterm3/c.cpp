#include <bits/stdc++.h>

using namespace std;

const int NMAX = 64;

int N, M, K, Q;
vector<int> a[NMAX];
int w1[NMAX][NMAX], w2[NMAX][NMAX];

int path[NMAX];
int length;
bool flag[NMAX];
int W1, W2, min_w1;
int res;
int res_path[NMAX];

bool check(int v, int w1, int w2) {	
	if (flag[v]) return false;
	if (W2 + w2 > Q) return false;
	
	if ((W1 + w1 + (K - length) * min_w1) >= res) return false;
	
	return true;
}

void save_sol() {
	res = min(res, W1);
//	for (int i = 0; i <= K; i++) {
//		res_path[i] = path[i];
//	}
}

void _try(int k) {
	path[length] = k;
	if (length > 0) {
		W1 += w1[k][path[length-1]];
		W2 += w2[k][path[length-1]];
	}
	flag[k] = true;
	length += 1;
	
	if (length == (K + 1)) {
		save_sol();
	} else {
		//branch
		for (int i = 0; i < a[k].size(); i++) {
			int v = a[k][i];
			if (check(v, w1[k][v], w2[k][v])) {
				_try(v);
			}
		}
	}
	
	// backtrack
	flag[k] = false;
	length -= 1;
	if (length > 0) {
		W1 -= w1[k][path[length-1]];
		W2 -= w2[k][path[length-1]];
	}
}

int main() {
	cin >> N >> M >> K >> Q;
	
	int u, v, x, y;
	
	min_w1 = 100;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				w1[i][j] = w2[i][j] = 0;
			} else {
				w1[i][j] = w1[j][i] = w2[i][j] = w2[j][i] = 1000000;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> x >> y;
		a[u].push_back(v);
		a[v].push_back(u);
		w1[u][v] = w1[v][u] = x;
		w2[u][v] = w2[v][u] = y;
		min_w1 = min(min_w1, x);
	}
	
	length = 0;
	memset(flag, false, sizeof(flag));
	W1 = 0;
	W2 = 0;
	res = 1000000;
	
	for (int i = 1; i <= N; i++) {
		_try(i);
	}
	
	cout << res << endl;
//	for (int i = 0; i <= K; i++) {
//		cout << path[i] << ' ';
//	}
	
	return 0;
}