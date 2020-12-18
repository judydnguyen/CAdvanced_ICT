#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXLENGTH 505
const int big_e = 1e9+7;
using namespace std;
int N, M;
int a[MAXLENGTH];
int x[MAXLENGTH][MAXLENGTH];

int main() {
    cin >> N >> M;
    for(int i = 1; i<= N; i++) {
        cin >> a[i];
    }

    x[0][0] = 1;
    for(int i = 1; i<= N; i++) {
        for(int j = 1; j<= M; j++) {
            int sum = 0;
            int cnt = 1;
            while(j - cnt*a[i] > i - 2) { // at least i - 1 shops assigned to i -1 branch.
                sum =  sum % big_e + (x[i-1][j - cnt*a[i]]) % big_e;
                cnt += 1;
            }
            x[i][j] = sum;  
        }
    }
    cout << x[N][M]  << endl;
}
