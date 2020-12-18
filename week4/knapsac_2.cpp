#include <iostream>
using namespace std;
const int MAX = 100;
typedef unsigned long long ull;
int n;
ull b;
ull a[MAX], c[MAX];
ull max_val;
ull tmp_val;
ull tmp_sum;
void input()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
}
void TRY(int k)
{
    for (int i = k; i <= n; i++)
    {
        if (tmp_sum + a[i] <= b)
        {
            tmp_sum += a[i];
            tmp_val += c[i];
            max_val = max_val < tmp_val ? tmp_val : max_val;
            TRY(i + 1);
            tmp_sum -= a[i];
            tmp_val -= c[i];
        }
    }
}
void solve()
{
    max_val = 0;
    tmp_val = 0;
    tmp_sum = 0;
    TRY(1);
    cout << max_val << endl;
}
int main(int argc, char const *argv[])
{
    input();
    solve();
    return 0;
}