#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int max_length = 1003;
int x[max_length];
int appear[max_length];
int N;
int res;
int main() {
    cin >> N;
    int tmp;
    if(N == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i<=N ; i++) {
        cin >> tmp;
        x[i] = tmp;
        appear[tmp] = 1;
    }
    for(int i = 1; i< N; i++) {
        for(int j= i+1; j<= N; j++)
        {
            if(x[i] < x[j])
            res +=1;
        }
    }

    cout << res << endl;


}