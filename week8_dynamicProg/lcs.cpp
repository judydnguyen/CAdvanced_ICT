#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#define MAXLENGTH 10004
using namespace std;
int c[MAXLENGTH][MAXLENGTH];
int s1[MAXLENGTH];
int s2[MAXLENGTH];
int n, m;
int ret;
char trace[MAXLENGTH][MAXLENGTH];
int main() {
    cin >> n >> m;
    for(int i = 1; i<= n; i++) {
        cin >> s1[i];
    }
    for(int i = 1; i<= m; i++) {
        cin >> s2[i];
    }
    // finished input data
    // trace[n,m] = 0;
    // trace[]
    for(int i = n; i>= 1; i--) {
        // trace[i][m] = 0;
        for(int j = m; j>=1; j--) {
            // trace[n][j] = 0;
            if(s1[i] == s2[j]) {
                // cout << i << " , " << j << endl;
                c[i][j] = c[i+1][j+1] + 1;
                // trace[i] = s1[i];
                trace[i][j] = 'D'; //diagonal
                
            }
            else {
                if(c[i+1][j] >= c[i][j+1]) {
                    trace[i][j] = 'W';
                }
                else {
                    trace[i][j] = 'R';
                }
                c[i][j] = max(c[i+1][j], c[i][j+1]);

            }
            if(ret < c[i][j]) {
                ret = c[i][j];
            }
        }
    }
    // for(int i = n; i>= 1; i--) {
    //     for(int j = m; j>=1; j--) {
    //         cout << c[i][j] << endl;
    //     }
    // }
    cout << ret << endl;
    // cout << "trace: " << trace[7][9] << endl;
    int k = 1, l = 1;
    while(k<= n && l <=m) {
        // cout << k << " , " << l << endl;
        if(trace[k][l] == 'D') {
            // cout << s1[k] << " ";
            k+=1; l+=1;
        }
        else if(trace[k][l] == 'W') {
            k+=1;
        }
        else {
            l+=1;
        }
    }
}