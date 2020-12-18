#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#define MAXLENGTH 10004
using namespace std;
int n;
int ans;
int max_i; // index of sub problem selected
int x[MAXLENGTH];
int S[MAXLENGTH];
int trace[MAXLENGTH];
int main() {
    cin >> n;
    for(int i = 1; i<= n; i++)  {
        cin >> x[i];
    }

    // finished input
    S[1] = 1;
    ans = S[1];
    // max_i = 1;
    for(int i = 2; i<=n; i++) {
        S[i] = 1;
        // trace[i] = -1; // no smaller subproblem
        for(int j = 1; j <= i-1; j++) {
            if(x[j] < x[i]) {
                if(S[i] < S[j]+1) {
                    S[i] = S[j] + 1;
                    // trace[i] = j;
                }
            }
        }
        if (ans < S[i]) {
            // max_i = i;
            ans = S[i];
        }
        ans = max(ans, S[i]);
    }

    // cout << max_i << ", ";
    // int m = max_i;
    // stack<int> s;
    // s.push(max_i);
    // while(trace[m]  != -1) {
    //     cout << trace[m] << ", ";
    //     m = trace[m];
    //     s.push(m);
    // }
    // cout << endl;
    // while(! s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    cout << ans << endl;

}