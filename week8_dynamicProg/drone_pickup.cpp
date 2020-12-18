#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXLENGTH 3003
using namespace std;
// struct point {
//     int gold;
//     int e;
//     point(int a, int b) {
//         this->gold = a;
//         this->e = b;
//     }
//     point() {}
// };
// point x[MAXLENGTH];
int x[MAXLENGTH][3];
int N, K;
int tmp;
int k2 = 0, k1 = 51;
int g[MAXLENGTH][MAXLENGTH]; // max amount of gold can have up to xi and number of drones picked up.
int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> x[i][0]; // gold
        g[i][1] = x[i][0];
        g[i][0] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp; // energy
        x[i][1] = tmp;
        if (tmp > k2)
            k2 = tmp;
        if (tmp < k1)
            k1 = tmp;
    }
    // cout << k1 << ", " << k2 << endl;
    int ans = -1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = max(1, i - k2); j <= i - 1; j++)
        {

            if (i - j <= x[j][1])
            {

                for (int m = 1; m <= K && m <= g[j][0]; m++)
                {
                    // printf("m = %d - %d\n", m, g[i][m]);
                    if (g[j][m] + x[i][0] > g[i][m + 1] && g[j][m] > 0)
                    {
                        // g[i][0] = g[j][0] + 1;
                        if (m == 1 && j != 1)
                        {
                            // g[i][0] += 1;
                            continue;
                        }
                        // printf("m = %d - %d\n", m, g[j][m]);

                        g[i][m + 1] = g[j][m] + x[i][0];

                        g[i][0] = g[j][0] + 1;
                    }
                }
            }
        }
    }

    if (N == 1)
    {
        cout << x[1][0] << endl;
        return 0;
    }

    for (int i = K + 1; i >= 2; i--)
    {
        // cout << g[N][i] << endl;
        if (g[N][i] > ans && g[N][i] > 0 && g[N - 1][i - 1] > 0)
            ans = g[N][i];
    }

    cout << ans << endl;
}