#include<iostream>
using namespace std;
const long INF = 100000000;
const int N = 100;
#define ll long long
int x[N+1][2];
int w_min;
int n,b;
int cnt = 0;
ll v = 0;
ll w = 0;
ll max_v; // minimal distance.
bool appear[N];

void solution() {
    if(v > max_v) {
        max_v = v;
    }
}

void input() {
    cin >> n >> b;
    w_min = INF;

    for(int i =1; i<= n; i++) {
        {
        // x[i][0] = INF; // weight
        // x[i][1] = 0; // value
        int w;
        cin >> w >> x[i][1];
        x[i][0] = w;
        w_min = w < w_min ? w : w_min;
        }

    }
}

void TRY(int k) {
    for(int i = 1; i <= n; i++) {
        if(!appear[i]) {
            appear[i] = true;
            v = v + x[i][1];
            w = w + x[i][0];
            if(w <= b) {
                if(k == cnt){
                    solution();
                }
                else {
                    if(w + w_min*(cnt-k+1) < b)
                    TRY(k+1);
                }
            }
            appear[i] = false;
            v = v - x[i][1];
            w = w - x[i][0];

        }
    }
}

void solve() {
    int max_n = b/w_min;
    for(int k = 1; k <= n; k++) appear[k] = false;
    v = 0;
    
        w = 0;
        TRY(1);
    cout << max_v << endl;
}

int main() {
    input();
    solve();
}