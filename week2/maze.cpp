#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<string>

using namespace std;
const int MAX = 1000;
int a[MAX][MAX];
int N, M, start_row, start_col;
map<string, pair<int,int> > direction;

map<pair<int, int>, int> d;
bool visited[MAX][MAX]; // true if node is visited
pair <int, int> startState;
pair <int, int> finalState;
queue<pair<int,int> > Q;
void input() {
    cin >> N >>M >> start_row >> start_col;
    for(int i = 1; i<=N; i++)
    for(int j = 1 ; j<= M; j++) {
        cin >> a[i][j];
    }

    direction["UP"] = pair<int, int>(0,-1);
    direction["DOWN"] = pair<int, int>(0,1);
    direction["RIGHT"] = pair<int, int>(1,0);
    direction["LEFT"] = pair<int, int>(-1,0);
}

bool check(int r, int c) {
    return (!visited[r][c] &&a[r][c] == 0);
}

void solve() {
    //print input

    for(int i = 1; i<=N; i++)
    for(int j = 1 ; j<= M; j++) {
        visited[i][j] = false;
    }
    startState = pair<int, int>(start_row, start_col);
    Q.push(startState);
    visited[start_row][start_col] = true;
    d[startState] = 0;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    bool found = false;
    while(!Q.empty()) {
        pair<int, int> s = Q.front();
        // for(int m = 0; m < Q.size(); m++)
        // printf("%lu...\n",Q.size());
        Q.pop();

        for(int k = 0; k< 4; k++) {
            int nr = s.first + dr[k];
            int nc = s.second + dc[k];
            
            pair<int, int> ns = pair<int, int>(nr, nc);
            
            if(nr < 1 || nr > N || nc <1 || nc >M) {
                finalState = ns;
                found = true;
            }
            if (check(nr, nc)) {
                Q.push(ns);
                visited[nr][nc] = true;
                d[ns] = d[s] + 1;
            }
        }
        if (found) {
         cout << d[finalState];
        break;
    }
    }
    // printf("result: %d.\n",d[finalState]);
    // cout << d[finalState];
    
}


int main() {
    input();
    solve();

}


