#include<iostream>
#include<iterator>
#include<vector>
#include<cstring>
#define pii pair<int, int>
#define vi vector<pii>
 
using namespace std;
 
const int NMAX = 1e5 + 10;
vector<pii> a[NMAX];
bool flag[NMAX];
int n, u, v, w;
 
pii dfs(int x) {
	pii r = make_pair(x, 0);
	flag[x] = true;
	for (vi::iterator it = a[x].begin(); it != a[x].end(); it++) {
		if (!flag[it->first]) {
			pii t = dfs(it->first);
			if (it->second + t.second > r.second) {
				r.first = t.first;
				r.second = it->second + t.second;
			}
		}
	}
	return r; 
}
 
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
	}
	memset(flag, false, sizeof(flag));
	pii f = dfs(1);
	memset(flag, false, sizeof(flag));
	pii s = dfs(f.first);	
	cout << s.second << endl;
	return 0;
}