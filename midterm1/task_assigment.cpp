#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 40;

typedef unsigned long long ull;
const ull mod = 1e9 + 7;
// int n, K, Q;
int n, m, K;
int d[MAX];
ull R = 0;
int cnt[MAX]; 
ull load[MAX];
int cost[MAX][MAX];

ull min_tt = 1e10;
int ass[MAX][MAX];
ull c;
ull f;
int x[MAX];
ull min_tc;
ull min_c = min_tt;
bool appear[MAX];
// using tsp to find perm.
// void solution_tsp(int k);
// void TRY_tsp(int k, int v);
// ull tsp(int v) {
    
//     for(int i = 0; i<= MAX; i++)
//     {
//     x[i] = 0;
//     appear[i] = false;
//     }
//     f = 0;
//     min_tc = 1e10;
//     TRY_tsp(1, v);
//     return min_tc;
    
// }
// void solution_tsp(int k) {
//     if(f + dis[x[k]][0] < min_tc)
//     min_tc =  f + dis[x[k]][0];
// }
// void TRY_tsp(int k, int v) {
//     for(int i = 1; i<= cnt[v]; i++) {
//         if(!appear[i]) {
//             appear[i] = true;
//             x[k] = ass[v][i];
//             f += dis[x[k-1]][ass[v][i]];
//             if(k==cnt[v]) solution_tsp(k);
//             else {
//                 TRY_tsp(k+1, v);
//             }
//             appear[i] = false;
//             f -= dis[x[k-1]][ass[v][i]];
//         }
//     }
// }

ull fact(int n)
{
    ull l = n;
    if ((l == 0) || (l == 1))
        return 1;
    else
        return l * fact(l - 1);
}
void input()
{
    cin >> n >> m >> K;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> d[i];
    // }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ull tmp;
            cin >> tmp;
            cost[i][j] = tmp;
            if(tmp < min_c) {
                min_c = tmp;
            }
        }
    }
}

bool check(int t, int v)
{
    if(c + cost[v][t] >= min_tt)
    return false;
    if (load[v] < K)
    {
        return true;
    }
    return false;
}

void solution()
{
    if(c < min_tt) {
        min_tt = c;
    }
}



void TRY(int k)
{
    for (int v = 1; v <= m; v++) // v_th staff.
    {
        if (load[v] < K)
        {
            load[v] += 1;
            // cnt[v] += 1;
            // ass[v][load[v]] = k;
            c += cost[v][k];
            // cout << "total_cost[v] " << v <<" cnt[v-1] is: " << ass[v][cnt[v]-1]<< "+ " << dis[ass[v][cnt[v]-1]][k] << endl;
            if (k == n) // all tasks assigned.
                solution();
            else
            {
                if(c +  min_c* (n-k) < min_tt)
                TRY(k + 1);
            }
            // x[k] = 0;
            // ass[v][cnt[v]] = 0;
            load[v] -= 1;
            // cnt[v] -= 1;
            c -= cost[v][k];
            // total_cost[v] -= cost[v][k];
        }
    }
    
}

void solve()
{
    c = 0;
    // for (int i = 1; i <= m; i++)
    //     load[i] = 0;
    TRY(1);
    cout << min_tt << endl;
}

int main()
{
    input();
    solve();
    return 0;
}