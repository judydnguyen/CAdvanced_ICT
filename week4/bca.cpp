#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 35;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int N, M;
// N: number of teachers
// M: number of courses
bool assigned[MAX];
int total_conflict;
int f[MAX][MAX];
int conf[MAX][MAX];
int ass[MAX][MAX];
int tt_fa[MAX];
int c[MAX];
int a[MAX][MAX];
int retval = 1e6;
int cur_max_load = 0;
int x[MAX];
int load[MAX];
int possible = 0;
// pii conf[100000];
void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int num_fa;
        cin >> num_fa;
        tt_fa[i] = num_fa;
        for (int j = 1; j <= num_fa; j++)
        {
            cin >> f[i][j];
        }
    }
    cin >> total_conflict;
    for (int i = 1; i <= total_conflict; i++)
    {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        // cout << idx1 << idx2 << endl;
        conf[idx1][idx2] = 1;
    }
}

bool isConflict(int x, int y)
{
    if (conf[x][y] == 1 || conf[y][x] == 1)
        return true;
    return false;
}

bool check(int k, int v)
{
    // k : course.
    // v : teacher.
    int flag = 0;
    for (int i = 1; i <= tt_fa[v]; i++)
    {
        if (f[v][i] == k)
            flag = 1;
    }

    for (int i = 1; i <= load[v]; i++)
    {
        if (isConflict(ass[v][i], k))
            flag = 0;
        break;
    }

    if (flag)
        return true;
    return false;
}

void solution()
{
    // cout << "solution: " << endl;
    // for (int i = 1; i <= N; i++)
    // cout << x[i] << ", ";
    // cout << endl;
    possible = 1;
    int max_l = -1e6;
    for (int i = 1; i <= N; i++)
        if (load[i] > max_l)
            max_l = load[i];
    //  cout << load[i] << ", ";
    //  cout << endl;
    // int max_l = *std::max_element(load, load + M);

    if (max_l < retval)
        retval = max_l;
}

void TRY(int k)
{
    for (int v = 1; v <= N; v++)
    {
        if (check(k, v))
        {
            x[k] = v;
            load[v] += 1;
            ass[v][load[v]] = k;
            if (k == M)
                solution();
            else
            {
                if (retval == 1e6)
                {
                    TRY(k + 1);
                }
                else
                {
                    if (load[v] < retval)
                    {
                        TRY(k + 1);
                    }
                }
            }
            x[k] = 0;
            ass[v][load[v]] = 0;
            load[v] -= 1;
        }
    }
}

void solve()
{
    for (int i = 1; i <= M; i++)
        load[i] = 0;
    TRY(1);
    if (possible == 1)
    {
        cout << retval << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    input();
    solve();
    return 0;
}