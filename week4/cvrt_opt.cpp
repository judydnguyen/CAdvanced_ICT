#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 20;

typedef unsigned long long ull;
const ull mod = 1e9 + 7;
int n, K, Q;
int d[MAX];
ull R = 0;
int cnt[MAX]; // for each truck
ull load[MAX];
int dis[MAX][MAX];
int total_cost[MAX];
// int a[MAX][MAX];
// int retval = 1e6;
// int cur_max_load = 0;
// int x[MAX];
// int load[MAX];
ull min_tt = 1e10;
int ass[MAX][MAX];

ull f;
int x[MAX];
ull min_tc;
bool appear[MAX];
// using tsp to find perm.
void solution_tsp(int k);
void TRY_tsp(int k, int v);
ull tsp(int v) {
    
    for(int i = 0; i<= MAX; i++)
    {
    x[i] = 0;
    appear[i] = false;
    }
    f = 0;
    min_tc = 1e10;
    TRY_tsp(1, v);
    return min_tc;
    
}
void solution_tsp(int k) {
    if(f + dis[x[k]][0] < min_tc)
    min_tc =  f + dis[x[k]][0];
}
void TRY_tsp(int k, int v) {
    for(int i = 1; i<= cnt[v]; i++) {
        if(!appear[i]) {
            appear[i] = true;
            x[k] = ass[v][i];
            f += dis[x[k-1]][ass[v][i]];
            if(k==cnt[v]) solution_tsp(k);
            else {
                TRY_tsp(k+1, v);
            }
            appear[i] = false;
            f -= dis[x[k-1]][ass[v][i]];
        }
    }
}

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
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> dis[i][j];
        }
    }
}

bool check(int k, int v)
{
    if (load[v] + d[k] > Q)
    {
        return false;
    }
    return true;
}

void solution()
{
    // int max_l = *std::max_element(load, load + M);
    // if (max_l < retval)
    //     retval = max_l;
    // for(int i = 0; i<= K; i++) {
    //     cout << cnt[i] << ", ";
    // }
    // cout << "solution: " << endl;
    ull tmp = 0;
    // R += 1;
    for (int i = 1; i <= K; i++)
    {
        // cout << "count: " << cnt[i] << endl;
        // for(int j = 1; j<= cnt[i]; j++) {
        //     cout << ass[i][j] << ", ";
        // }
        // cout << endl;
        if (cnt[i] == 0)
        {
            tmp = 1e10;
            break;
        }
        // tmp += total_cost[i] + dis[cnt[i]][0];
        tmp += tsp(i);
        // cout << "tsp of i: " << i << tsp(i) << endl;
        // cout << "count: " << cnt[i] << endl;
        // for(int j = 1; j<= cnt[i]; j++) {
        //     cout << ass[i][j] << ", ";
        // }
        // cout << endl;
        // else
        // {
        //    tmp *= ull(fact(cnt[i]));
        // }

        // tmp *= ull(fact(cnt[i]));
    }
    if (tmp < min_tt) {
        min_tt = tmp;
    }
}



void TRY(int k)
{
    for (int v = 1; v <= K; v++) // v_th truck.
    {
        if (check(k, v))
        {
            load[v] += d[k];
            cnt[v] += 1;
            ass[v][cnt[v]] = k;
            total_cost[v] += dis[ass[v][cnt[v]-1]][k];
            // cout << "total_cost[v] " << v <<" cnt[v-1] is: " << ass[v][cnt[v]-1]<< "+ " << dis[ass[v][cnt[v]-1]][k] << endl;
            if (k == n)
                solution();
            else
            {
                TRY(k + 1);
            }
            // x[k] = 0;
            ass[v][cnt[v]] = 0;
            load[v] -= d[k];
            cnt[v] -= 1;
            total_cost[v] -= dis[ass[v][cnt[v-1]]][k];
        }
    }
    
}

void solve()
{
    for (int i = 1; i <= K; i++)
        load[i] = 0;
    TRY(1);
    cout << min_tt << endl;
}

int main()
{
    input();
    solve();
    return 0;
}