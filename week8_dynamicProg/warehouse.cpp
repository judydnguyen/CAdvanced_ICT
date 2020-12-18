#include <iostream>
#include <deque>

const int N = 1e3 + 1;
int a[N];
using namespace std;
int n, L1, L2, ans;
int D;
// S(i, t) : max amount of golds picked when the truck stop at i and total picking time = t.
// S(i, t) = max {S(j, t- ti) + ai && i - j <= D};
// ans = MAX {S(i,t)};

int S[N][N];
int T;
int t[N];

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int k = 0; k <= T; k++)
    {
        if (k != t[0])
            S[0][k] = 0;
        else
            S[0][k] = a[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= T; k++)
        {
            if (k != t[i])
                S[i][k] = 0;
            else
                S[i][k] = a[i];

            for (int d = 1; d <= D; d++)
            {
                int j = i - d;
                if (j >= 0 && k >= t[i] && S[j][k - t[i]] > 0)
                {
                    if (S[i][k] < S[j][k - t[i]] + a[i])
                    {
                        S[i][k] = S[j][k - t[i]] + a[i];
                    }
                }
            }
        }
    }
    int rs = 0;
    for(int i = 0; i<= n; i++) {
        for(int k = 0; k<= T; k++) {
            if(S[i][k] > rs) rs = S[i][k];
        }
    }
    cout << rs;
}