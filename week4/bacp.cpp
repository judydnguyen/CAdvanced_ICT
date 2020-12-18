#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 20;
typedef unsigned long long ull;
int N, M;
// N: number of courses
// M: number of periods
int c[MAX];
int a[MAX][MAX];
int retval = 1e6;
int cur_max_load = 0;
int x[MAX];
int load[MAX];
void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> a[i][j];
        }
}

bool check(int k, int v)
{
    for (int i = 1; i <= N; i++)
    {
        if (a[i][k] == 1)
        {
            
            if (x[i] >= v)
            return false;
            // cout << "nho hon: " << "(" << i << ", " << k << endl;
            // cout << x[i] << "v: " << v << endl;
            // for(int j = 1; j <= k; j++)
            // cout << x[j] << ", ";
            // cout << endl;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (a[k][i] == 1)
        {
            
            if (x[i] <= v && x[i] != 0)
                return false;
            //     cout << "lon hon: " << "(" << i << ", " << k << endl;
            // cout << x[i] << "v: " << v << endl;
            // for(int j = 1; j <= k; j++)
            // cout << x[j] << ", ";
            // cout << endl;
        }
    }


    return true;
}

void solution()
{
    // cout << "solution: " << endl;
    // for (int i = 1; i <= N; i++)
    // cout << x[i] << ", ";
    // cout << endl;
    int max_l = -1e6;
     for (int i = 1; i <= M; i++)
     if(load[i] > max_l)
     max_l = load[i];
    //  cout << load[i] << ", ";
    //  cout << endl;
    // int max_l = *std::max_element(load, load + M);

    if (max_l < retval)
        retval = max_l;
}

void TRY(int k)
{
    for (int v = 1; v <= M; v++)
    {
        if (check(k, v))
        {
            x[k] = v;
            load[v] += c[k];
            if (k == N)
                solution();
            else
            {
                TRY(k + 1);
            }
            x[k] = 0;
            load[v] -= c[k];
        }
    }
}

void solve()
{
    for (int i = 1; i <= M; i++)
        load[i] = 0;
    TRY(1);
    cout << retval << endl;
}

int main()
{
    input();
    solve();
    return 0;
}