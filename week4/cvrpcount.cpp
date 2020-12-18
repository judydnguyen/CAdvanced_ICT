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
// int a[MAX][MAX];
// int retval = 1e6;
// int cur_max_load = 0;
// int x[MAX];
// int load[MAX];
int ass[MAX][MAX];
ull fact(int n) {
    ull l = n;
   if ((l==0)||(l==1))
   return 1;
   else
   return l*fact(l-1);
}
void input()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    
}

bool check(int k, int v)
{
    if(load[v] + d[k] > Q) {
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
    ull tmp = 1;
    // R += 1;
    for(int i = 1; i<= K; i++) {
        // cout << "count: " << cnt[i] << endl;
        // for(int j = 1; j<= cnt[i]; j++) {
        //     cout << ass[i][j] << ", ";
        // }
        // cout << endl;
        if(cnt[i] == 0)
        {
            tmp = 0;
            break;

        }
        // cout << "count: " << cnt[i] << endl;
        // for(int j = 1; j<= cnt[i]; j++) {
        //     cout << ass[i][j] << ", ";
        // }
        // cout << endl;
        // else
        // {
        //    tmp *= ull(fact(cnt[i])); 
        // }   
        tmp *= ull(fact(cnt[i]));     
    }
    R+= tmp;
    
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
            if (k == n)
                solution();
            else
            {
                TRY(k + 1);
            }
            // x[k] = 0;
            load[v] -= d[k];
            cnt[v] -= 1;
        }
    }
}

void solve()
{
    for (int i = 1; i <= K; i++)
        load[i] = 0;
    TRY(1);
    cout << (R/fact(K)) % mod << endl;
}

int main()
{
    input();
    solve();
    return 0;
}