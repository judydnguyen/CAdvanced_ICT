#include<iostream>
using namespace std;
const int N = 100;
int M;
int x[N];
int n;
int T;

// arr of n elements with sum equal to M.

bool check(int v, int k) {
    if (k < n)
    return true;
    return T + v == M;

}
void solution() {
    // cnt ++;
    cout << "solution " << ": ";
    for(int i = 1; i<= n ; i++) {
        cout << x[i] << " ";
        
    }
    cout << endl;
}


void TRY(int k) {
    for (int v = 1; v<= M - T -n + k; v++) {
        if(check(v,k)) {
            x[k] = v;
            T = T + v;
            if(k == n) solution();
            else {
                TRY(k+1);
            }
            T = T-v;
        }
    } 
}

int main() {
    T = 0;
    n = 3;
    M = 5;
    TRY(1);

}