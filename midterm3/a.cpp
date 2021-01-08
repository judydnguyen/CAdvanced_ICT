#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1005;
int N;
int A[MAX][MAX];
int flag = 0;
int check() {
 for(int i = 1; i<= N; i++) {
        for(int j = 1; j<=N; j++) {
            if(j != i && A[i][j] == 0)
            return 0;
        }
    }
    return 1;
}
int main() {
    // input
    cin >> N;
    for(int i = 1; i<= N; i++)
    for(int j = 1; j<= N; j++) {
        cin >> A[i][j];
    }
    cout << check() << endl;
    
}