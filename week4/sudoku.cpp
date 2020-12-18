#include<iostream>
using namespace std;
const int N = 100;
int x[10][10];
bool mr[10][10]; //m[r][v] => value v appear on row r
bool mc[10][10]; //m[c][v] => value v appear on row c
bool mrc[4][4][10]; // mrc[i][j][v] => value v appear son sub square (i,j)
int n;
int T;
bool appear[N];
int cnt;
bool found = false;
bool check(int v, int r, int c) {
    return !mr[r][v] && !mc[c][v] && ! mrc[(r-1)/3 +1][(c-1)/3 +1][v];
    // return T + v == M;

}
void solution() {
    found = true;
    // cout << "solution " << cnt << " : ";
    for(int i = 1; i<= 9 ; i++) {
        for(int j = 1; j<= 9; j++)
        cout << x[i][j] << " ";
        cout << endl;
        
    }
    cout << "----------------" << endl;
}


void TRY(int r, int c) {
    for (int v = 1; v<= 9; v++) {
        if (check(v,r,c)) {
            x[r][c] = v;
            mr[r][v] = true;
            mc[c][v] = true;
            mrc[(r-1)/3 +1][(c-1)/3 +1][v] = true;
            if(r == 9 && c == 9) solution();
            else {
                if(c==9) TRY(r+1,1);
                else TRY(r,c+1);
            }
            mr[r][v] = false;
            mc[c][v] = false;
            mrc[(r-1)/3 +1][(c-1)/3 +1][v] = false;
        }
        // if(!appear[v]) {
        //     x[k] = v;
        //     appear[v] = true;
        //     if(k == n) solution();
        //     else {
        //         TRY(k+1);
        //     }
        //     appear[v] = false;
        // }
    } 
}

int main() {
    
    TRY(1,1);

}