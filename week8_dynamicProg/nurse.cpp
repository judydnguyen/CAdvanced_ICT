#include <iostream>
#define n 1003
using namespace std;
int N;
int F[2][n]; // F[0][x] means the number of ways to plan to the day x is off, 1 measn 0
int k1, k2;
int main()
{
    cin >> N >> k1 >> k2;
    F[0][0] = 1;
    F[1][0] = 1;
    // truong hop khong co ngay lam viec nao
    F[0][1] = 1;
    for (int i = 1; i <= k1 - 1; i++)
    {
        F[1][i] = 0;
        F[0][i + 1] = F[1][i];
    }
    // coi i la ngay cuoi cung cua 1 period, tu 1 -> k1 -1 : chua du 1 period.
    for (int i = k1; i <= N; i++)
    {
        F[0][i] = F[1][i - 1];
        int sum = 0;
        for (int j = max(0, i - k2); j <= i - k1; j++)
        {
            sum += F[0][j];
        }
        F[1][i] = sum;
        // cout << F[1][i] << endl;
        // if(i == N) {
        //     cout << F[0][n]
        // }
    }
    cout << F[0][N] + F[1][N] << endl;
}
