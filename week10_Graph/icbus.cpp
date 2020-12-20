#include <iostream>
#include <iterator>
#include <vector>
#include <cstring>
#define pii pair<int, int>
#define vi vector<pii>

using namespace std;

const int NMAX = 5005;
vector<pii> g[NMAX]; // directed graph
vector<int> X[NMAX]; // adjacency list of graph
int weight[NMAX][NMAX];
bool flag[NMAX];
int N, M;
int city[NMAX][3];
int c_cost, c_dis, c_city;
int cost[NMAX];
int p[NMAX];
bool visited[NMAX];
int cnt = 0;
void dfs(int v, int k)
{
    if (k > 0)
    {
        int duplicate;
        for (int i = 0; i < X[v].size(); i++)
        {
            if (weight[c_city][X[v][i]] == 0)
                weight[c_city][X[v][i]] = c_cost;
            else if (weight[c_city][X[v][i]] > c_cost)
                weight[c_city][X[v][i]] = c_cost;
            // if(c_city == X[v][i]) weight
            dfs(X[v][i], k - 1);
        }
    }
}

void dijkstra()
{
    visited[1] = true;
    cnt += 1 ;
    for (int i = 1; i <= N; i++)
    {
        if(weight[1][i] > 0)
        cost[i] = weight[1][i];
        else 
        cost[i] = 1e9;
        p[i] = 1;
        // cout << cost[i] << endl;
    }
 
    while(cnt <= N) {
        int min_n = -1, min_w = cost[1]+1;
        for(int i = 2; i<= N; i++) {
            // cout << min_w << endl;
            if(cost[i] < min_w && !visited[i]) {min_n = i;
            min_w = cost[i];
            }
            
        }
        // cout << min_n << endl;
        visited[min_n] = true;
        cnt +=1;
        for(int i = 1; i<= N; i++) {
            int tmp_w = weight[min_n][i] > 0 ? weight[min_n][i] : 1e9;
            // if(i == N) {
            //     cout << tmp_w << endl;
            // }
            if(!visited[i] && cost[i] > cost[min_n] + tmp_w)
            {
                cost[i] = cost[min_n] + tmp_w;
                p[i] = min_n;
            }
        }
    }
}

// int solve() {
//     for(int i = 1; i<= N ;i++) {
//         cost[i] = 1e9;
//     }
//     cost[1] = 0;
//     memset(visited, false, sizeof(visited));
//     for(int i = 1; i<= N ; i++) {
//         int minId = -1;
//         int minVal = 1e9;
//         for(int v = 1; v<= N; v++) {
//             if(!visited[v]) {
//                 if (cost[v] < minVal)
//                 {
//                     minVal = cost[v];
//                     minId = v;
//                 }
//             }
//         }
//         visited[minId] = true;
//         if(minId == N)
//         {
//             cout << cost[minId];
//             return 0;
//         }
//         // update cost
//         // for(int v = 1; v <= N ; v++) {
//         //     if(!visited[v] && weight[minId][v] <= )
//         // }

//     }
// }

int main()
{
    cin >> N >> M;
    int c, d;
    for (int i = 1; i <= N; i++)
    {
        cin >> c >> d;
        city[i][0] = c; // cost
        city[i][1] = d; // max distance
    }
    int tmp1, tmp2;
    for (int i = 1; i <= M; i++)
    {
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
    }

    // build directed graph
    for (int i = 1; i <= N; i++)
    {
        c_cost = city[i][0];
        c_dis = city[i][1];
        c_city = i;
        dfs(i, c_dis);
    }
    for(int i = 1; i<= N; i++) {
        weight[i][i] = 0;
    }
    // for(int i = 1; i<= N; i++)
    // {for(int j = 1; j<= N; j++)
    // cout << weight[i][j] << " ";
    // cout << endl;
    // }
    dijkstra();
    cout << cost[N] << endl;
    // cout << p[N] << endl;
}































































































































