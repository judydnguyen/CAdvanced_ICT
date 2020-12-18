#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXLENGTH 1000006
using namespace std;

int n, L1, L2;
int ans;
int x[MAXLENGTH];
int S[MAXLENGTH];
int sub_seq[MAXLENGTH];
int main()
{
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << x[i];
    // }

    // finished input
    S[1] = x[1];
    ans = S[1];
    int last = -1;
    for (int i = 2; i <= n; i++)
    {
        S[i] = x[i];
        // last = i;
        for (int j = i-1; j >= 1; j--)
        {
            int tmp = i - j;
            // cout << tmp << endl;
            if (tmp < L1)
            continue;
            if (tmp > L2)
            break;
            if (tmp >= L1 && tmp <= L2 && S[i] < S[j] + x[i])
            {
                // cout << tmp << endl;
                // printf("%d, %d is %d\n", i, j, tmp);
               
                // S[i] -= S[last];
                // last = j;
                S[i] = S[j] + x[i];
                // break;
            }
        }
        // printf("S%d = %d \n",i, S[i]);
        // for(int j = 1; j <= i-1; j++) {
        //     if(x[j] > 0) {
        //         // if(S[i] < S[j]+1) {
        //             S[i] += x[j];

        //         }
        //     }

        ans = max(ans, S[i]);
    }


    cout << ans << endl;
}