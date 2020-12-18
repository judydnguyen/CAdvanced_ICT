#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long int ull;
using namespace std;
int N;
ull M;
// int h[10000005];
// ull ret;
int main()
{
    // int min_h, max_h, mid;
    int *arr;
    int max_v = -1;
    cin >> N >> M;
    arr = (int*) malloc (N * sizeof(int));
    int i = 0;
    // cout << max_h << endl;
    for (i = 0; i < N; i++)
    {
        // cout << max_h << endl;
        // scanf("%lld" , &h[i]);
        cin >> arr[i];
        if (arr[i] > max_v)
            max_v = arr[i];
    }
    
    ull min_h = 0;
    ull max_h = max_v;
    ull sum = 0, mid;
    ull ret = 0;
    while (min_h <= max_h)
    {
        // cout << "(" << min_h << "," << max_h << ")"  << endl;
        sum = 0;
        mid = (min_h + max_h) / 2;
        for (i = 0; i < N; i++)
        {
            ull tmp = arr[i] - mid;
            sum += (tmp > 0 ? tmp : 0);
        }
        // cout << sum << endl;
        // cout << mid << endl;
        if (sum > M)
        {
            min_h = mid + 1;
            if (mid > ret)
                ret = mid;
        }
        else if (sum == M)
        {
            ret = mid;
            break;
        }
        else
        {
            max_h = mid-1;
        }
    }
    // cout << sum << endl;
    cout << ret << endl;
}