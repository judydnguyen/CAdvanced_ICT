#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#define MAX 10000000
using namespace std;
typedef unsigned long long ull;
int n, m;
int comb[MAX];
int prev_comb[MAX];
void input() {
    cin >> n >> m;
    for(int i = 1; i<= n ; i++) {
        comb[i] = 1;
    }
    for(int i = 1; i<= m; i++) {
        cin >> prev_comb[i];
    }
}

void solve() {
    int j = m;
    while(prev_comb[j] == n - m + j)
    j -= 1;
    if(j >=1) {
    prev_comb[j] += 1;
    for(int k = j+1; k<= m ; k++) {
        prev_comb[k] = prev_comb[j] + k - j;
    }

    for(int i = 1; i<= m; i++) {
        cout << prev_comb[i] << " ";
        
    }
    cout << endl;
    }
    else {
        cout << -1 << endl;
        return;
    }

}

int main() {
    input();
    solve();
}