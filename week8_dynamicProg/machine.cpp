#include<iostream>
#include<algorithm>
#include<cmath>

#define MAXLENGTH 2000006
using namespace std;
int n;
int p[MAXLENGTH][4];
int S[MAXLENGTH];
int ans;
bool isOverlap(int i, int j) {
    if(p[i][1] < p[j][0] ||  p[j][1] < p[i][0])
    return false;
    return true;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        // cin >> p[i][0] >> p[i][1];
        // p[n][2] = p[i][1] - p[i][0];
        scanf("%d %d", &p[i][0], &p[i][1]);
        p[i][2] = p[i][1] - p[i][0];
    }
    // while(n) {
    //     cin >> p[n][0] >> p[n][1];
    //     p[n][2] = p[n][1] - p[n][0];
    //     n--;
   
    //  cout << p[1][2] << endl;
    S[1] = p[1][2];
    ans = S[1];
    // for(int i = 2; i<= n; i++) {
    //     cout << p[i][2] << endl;
    // }
    for(int i = 1; i<= n; i++) {
        // cout << p[i][2] << endl;
        S[i] = p[i][2];
        for(int j = i+1; j<= n; j++) {
            if(!isOverlap(i,j) && S[i] < p[i][2] + p[j][2]) {
                S[i] = p[i][2] + p[j][2];
            }
        }
        ans = max(S[i], ans);
    }
    cout << ans << endl;

}