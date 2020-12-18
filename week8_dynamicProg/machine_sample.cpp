#include<iostream>
#include<algorithm>
#include<cmath>

#define MAXLENGTH 2000006
using namespace std;
int n, ans;
int L[MAXLENGTH], R[MAXLENGTH];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i< MAXLENGTH ;i++) {
        L[i] = 0; R[i] = 0;
    }
    for(int i = 0; i< n; i++) {
        int s, t;
        cin >> s >> t;
        R[s] = max(R[s], t-s);
        L[t] = max(L[t], t-s);
    }

    for(int i = 1; i<MAXLENGTH ; i++) L[i] = max(L[i], L[i-1]);
    for(int i = MAXLENGTH - 2; i>=0; i--) R[i] = max(R[i], R[i+1]);
    ans = -1;
    for(int i = 0; i< MAXLENGTH - 1; i++) ans = max(ans, L[i] + R[i+1]);
    cout << ans;

}