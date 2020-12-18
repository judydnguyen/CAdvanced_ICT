#include<iostream>
using namespace std;
const long INF = 100000000000;
const int N = 100;
#define ll long long

ll tsp(int v) {
    bool appear[MAX];
    x[MAX];
    ull f;
    ull tt;
    ull min_tt = 1e10;
    TRY_tsp(1);
    
}
void solution_tsp() {
    if(f + dis[x[k]][0] < min_tt)
    min_tt =  f + dis[x[k]][0];
}
void TRY_tsp(int k) {
    for(int i = 1; i<= cnt[v]; i++) {
        if(!appear[i]) {
            appear[i] = true;
            f += dis[x[k-1]][ass[v][i]];
            if(k==cnt[v]) solution_tsp();
            else {
                TRY_tsp(k+1);
            }
        }
    }
}
    for(int v = 1; v<= n ; v++) 
    if(!appear[v]) {
        x[k] = v;
        appear[v] = true;
        f = f + c[x[k-1]][x[k]];
        if(k == n) solution();
        else {
            if(f+ c_min*(n-k+1) < min_f)
            TRY(k+1);
        }
        appear[v] = false;
        f = f - c[x[k-1]][x[k]];
    }
}

void solution() {
    if(f+c[x[n]][x[1]] < min_f) {
        min_f = f + c[x[n]][x[1]];
    }
}
 
void input() {
    cin >> n >> m;
    c_min = INF;
 
    for(int i =1; i<= n; i++) {
        for(int j = 1; j <=n; j++)
        c[i][j] = INF;
 
    }
 
    for (int k = 1; k<= m ; k++) {
        int i, j;
        ll w;
        cin >> i >> j >> w;
        c[i][j] = w;
        c_min = w < c_min ? w: c_min;
    }
}
 
void TRY(int k) {
    for(int v = 1; v<= n ; v++) 
    if(!appear[v]) {
        x[k] = v;
        appear[v] = true;
        f = f + c[x[k-1]][x[k]];
        if(k == n) solution();
        else {
            if(f+ c_min*(n-k+1) < min_f)
            TRY(k+1);
        }
        appear[v] = false;
        f = f - c[x[k-1]][x[k]];
    }
}
 
void solve() {
    for(int v = 1; v <= n; v++) appear[v] = false;
    f = 0;
    x[1] = 1;
    appear[1] = true;
    min_f = INF;
    TRY(2);
    cout << min_f << endl;
}