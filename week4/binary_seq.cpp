#include<iostream>
using namespace std;
const int N = 100;
int x[N];
int n;
int cnt;
bool check(int v, int k) {
    return true;
}

void solution() {
    cnt ++;
    cout << "solution " << cnt <<": ";
    for(int i = 1; i<= n ; i++) {
        cout << x[i] << " ";
        
    }
    cout << cnt << endl;
}

void TRY(int k) {
    for(int v = 0; v<= 1; v++) {
        if(check(v,k)) {
            x[k] =  v;
            if(k == n) solution();
            else {
                TRY(k+1);
            }
        }
    }
}

int main() {
    n = 10;
    cnt = 0;
    TRY(1);
}