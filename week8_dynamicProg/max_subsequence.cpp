#include<iostream>
#include<algorithm>
#include<cmath>

#define MAXLENGTH 1000006
using namespace std;

int n;
int ans;
int x[MAXLENGTH];
int S[MAXLENGTH];
int sub_seq[MAXLENGTH];
int main() {
    cin >> n;
    for(int i = 1; i<= n; i++)  {
        cin >> x[i];
    }

    // finished input
    S[1] = x[1];
    ans = S[1];
    
    for(int i = 2; i<=n; i++) {
        S[i] = x[i];
        if(S[i-1] > 0) {
            S[i] += S[i-1];
        }
        // for(int j = 1; j <= i-1; j++) {
        //     if(x[j] > 0) {
        //         // if(S[i] < S[j]+1) {
        //             S[i] += x[j];

        //         }
        //     }
        
        ans = max(ans, S[i]);
    }

    cout << ans << endl;

}