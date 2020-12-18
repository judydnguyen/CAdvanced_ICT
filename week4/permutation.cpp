#include<iostream>
using namespace std;
const int N = 100;
int M;
int x[N];
int n;
int T;
bool appear[N];
int cnt;
bool check(int v, int k) {
    if (k < n)
    return true;
    return T + v == M;

}
void solution() {
    cnt ++;
    cout << "solution " << cnt << " : ";
    for(int i = 1; i<= n ; i++) {
        cout << x[i] << " ";
        
    }
    cout << endl;
}


void TRY(int k) {
    cout << k << endl;
    for (int v = 1; v<= n; v++) {
        if(!appear[v]) {
            
            x[k] = v;
            appear[v] = true;
            if(k == n) solution();
            
            else {
                TRY(k+1);
            }
            appear[v] = false;
        }
    } 
}

int main() {
    cnt = 0;
    n = 4;
    for(int i = 0; i<n; i++)
    appear[i] = false;
    TRY(1);

}