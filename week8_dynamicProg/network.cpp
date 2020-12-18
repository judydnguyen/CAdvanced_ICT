#include<iostream>
#include<algorithm>
#include<cmath>

#define MAXLENGTH 100006
using namespace std;
int x[MAXLENGTH];
int cost[MAXLENGTH][MAXLENGTH];
int n, k, m;
int main() {
    cin >> n >> k;
    cin >> m;
    int x1, x2;
    while(m) {
        // int x1, x2;
        cin >> x1 >> x2 >> cost[x1][x2];
    }
    
}