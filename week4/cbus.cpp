#include <iostream>
using namespace std;
const int MAX = 100;
typedef unsigned long long ull;
ull c[2 * MAX][2 * MAX];
bool visited[2 * MAX];
int n, k;
int c_min = 10000000;
int temp_c;
int x[2 * MAX];
ull min_cost = 1000000;
ull cost;
int available;
void input()
{
    cin >> n >> k;
    available = k;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> temp_c; //get map
            c[i][j] = temp_c;
            if (temp_c < c_min && temp_c != 0)
            c_min = temp_c;
        }
    }
    // cout << c_min;
}
bool check(int v)
{
    if (cost + c[v][0] > min_cost)
        return false;
    if (v <= n && !visited[v])
    {
        if (available)
        {
            available -= 1;
            return true;
        }
    }
    if (v > n && !visited[v])
    {
        // for (int i = 1; i <= 2 * n; i++)
        // {
        //     if (x[i] + n == v)
        //     {
            if (visited[v-n])
            {
                available += 1;
                return true;
            }
        //     }
        // }
    }
    return false;
}
void solution(int k)
{
    ull total_cost = cost + c[x[k]][0];
    if (total_cost < min_cost)
        min_cost = total_cost;
}

void TRY(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v))
        {
            x[k] = v;
            visited[v] = true;
            cost += c[x[k - 1]][x[k]];
            if (k == 2 * n)
                solution(k);
            else
            {
                if(cost + (2*n -k +1)*c_min < min_cost)
                TRY(k + 1);
            }

            cost -= c[x[k - 1]][x[k]];
            visited[v] = false;
            x[k] = 0;
            if (v <= n)
            {
                available += 1;
            }
            else
            {
                available -= 1;
            }
        }
    }
}
void solve()
{
    cost = 0;
    x[0] = 0;
    for (int i = 0; i <= 2 * n + 1; i++)
        visited[i] = false;
    TRY(1);
    cout << min_cost << endl;
}
int main()
{
    input();
    solve();
}