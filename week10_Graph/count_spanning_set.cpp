#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;
int N, M;
int b[MAX]; // start node
int e[MAX]; // end node
int c[MAX]; // cost corresponding
int ET[MAX];
int nET;
int x[MAX];
// disjoint set 
int ans = 0;
int r[MAX]; // rank of set v
int p[MAX]; // parent of v
long long rs;
// k : number of edged had.
void link(int x, int y) {
    if(r[x] > r[y]) p[y] = x;
    else {
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] + 1;
    }
}

void makeSet(int x) {
    p[x] = x;
    r[x] = 0;
}
int findSet(int x) {
    if( x != p[x])
    p[x] = findSet(p[x]);
    return p[x];
}

bool checkNoCycle(int k, int v) {
    // selected edges are (b[x[1]], e[x[1]]), ... (b[x[k-1]], e[x[k-1]])
    // check if edge (b[v], e[v]) can be added without  creating cycle
    for(int v = 1; v<= N; v++) makeSet(v);
    for(int i = 1; i<= k-1; i++) {
        int r1 = findSet(b[x[i]]);
        int r2 = findSet(e[x[i]]);
        link(r1, r2);
    }
    return findSet(b[v]) != findSet(e[v]);
}

void TRY(int k) {
    for(int v=x[k-1]+1; v<= M; v++) {
        if(checkNoCycle(k,v)) {
            x[k] = v;
            if(k == N-1) ans++;
            else TRY(k+1);
        }
    }
}

void INPUT() {
    int tmp1, tmp2;
    
    cin >> N >> M;
    for(int i = 1; i<= M; i++) {
        cin >> tmp1 >> tmp2;
        b[i] = tmp1;
        e[i] = tmp2;
    }
    // TRY(1);
}

int main() {
    INPUT();
    TRY(1);
    cout << ans << endl;
}