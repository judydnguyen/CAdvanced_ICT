#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#define MAX 10000
using namespace std;
typedef unsigned long long ull;
ull cnt = 1;
ull k;
int n, m;
int comb[MAX];
int prev_comb[MAX];
void input()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        prev_comb[i] = i;
    }
    // for(int i = 1; i<= m; i++) {
    //     cin >> prev_comb[i];
    // }
}

int solve()
{
    int j = m;
    while (prev_comb[j] == n - m + j && j > 0)
        j -= 1;
    if (j >= 1)
    {
        prev_comb[j] += 1;
        for (int k = j + 1; k <= m; k++)
        {
            prev_comb[k] = prev_comb[j] + k - j;
        }
        return 1;

        // for(int i = 1; i<= m; i++) {
        //     cout << prev_comb[i] << " ";

        // }
        // cout << endl;
    }
    else
    {
        // cout << -1 << endl;
        return -1;
    }
}

int main()
{
    input();
    if (cnt == k)
    {
        for (int i = 1; i <= m; i++)
                {
                    cout << prev_comb[i] << " ";
                }
                cout << endl;
        return 0;
    }
    while (1)
    {
        cnt += 1;
        if (solve() == 1)
        {
            if (cnt == k)
            {
                for (int i = 1; i <= m; i++)
                {
                    cout << prev_comb[i] << " ";
                }
                cout << endl;
                return 0;
            }
        }
        else
        {
            cout << -1 << endl;
            break;
        }
    }
    // solve();
}