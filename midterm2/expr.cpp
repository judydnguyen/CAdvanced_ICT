#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
#define max_num 35

int x[max_num];
int a[max_num][max_num];
int dfs(int i, int sum)
{
    if(a[])
    return dfs(i-1, sum-x[i]) + dfs(i-1, sum+ x[i]);
}
int main() {
    int N,b;
    cin >> N >> b;
    for(int i = 1; i<= N; i++)
    cin >> x[i];
    a[2][x[1]+x[2]] = 1;
    a[2][x[1]-x[2]] = 1;

    // cout << a[N][b];
    int last1, last2;
    last1 = x[1] + x[2];
    last2 = x[1] - x[2];
    for(int i = 3; i<= N; i++) {
        for(int k = 0; k<= 130; k++) {
            a[i][k] = a[i-1][k+x[i]] + a[i-1][k-x[i]];
        }       
    }

    
    cout << a[N][b];
}