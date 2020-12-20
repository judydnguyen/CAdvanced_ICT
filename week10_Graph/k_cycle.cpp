#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
const int MAX = 31;

int N, M, K;
int n;
char COLOR[MAX];
vector<int> X[MAX]; //list of adjancent nodes of node X[i]
int ed[MAX][MAX];
bool visited[MAX];
int res = 0;
int p[MAX];
int cur_v;
void dfs(int i, int num) {
    // visited[i] = true;
    // n += 1;

    if(COLOR[i] == 'O') {

    }

    // cout << num << ": " ;
    //  cout << i << ", " << cur_v << endl;
    if (num == K)
    {
        // xvisited[i] = false;
        if(ed[i][cur_v] == 1)
        {
        //    cout << i << "- " << cur_v << endl;
            res += 1;
        }
        // if (ed[i][])
        COLOR[i] = 'W';

    }
    else if(num < K)
    for (int j = 0; j < X[i].size(); j++)
    {
        if (COLOR[X[i][j]] == 'W')
        {
            COLOR[X[i][j]] = 'O';
            dfs(X[i][j], num+1);
        }
        // visited[X[i][j]] = false;
    }
    COLOR[i] = 'W';
}

int main() {
    cin >> N >> M >> K;
    int tmp1, tmp2;
    for (int i = 1; i <= M; i++)
    {
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
        ed[tmp1][tmp2] = 1;
        ed[tmp2][tmp1] = 1;
    }
    n = 0;
    memset(COLOR, 'W', sizeof(COLOR));
    for (int i = 1; i <= N; i++)
    {
        cur_v = i;
        memset(COLOR, 'W', sizeof(COLOR));
        COLOR[i] = 'B';
        dfs(i, 1);
    }
    int ans = res / K / 2;
    cout << ans << endl;
}