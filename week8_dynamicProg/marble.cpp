#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXLENGTH 606
using namespace std;

int W, H;
int waste[MAXLENGTH][MAXLENGTH];
int main()
{
    cin >> W >> H;
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            waste[i][j] = i * j;
        }
    }
    int cnt;
    cin >> cnt;
    while (cnt)
    {
        int x, y;
        cin >> x >> y;
        waste[x][y] = 0;
        cnt --;
    }
    int min_horizontal = 360000;
    int min_vertical = 360000;
    int res = 360000;
    for (int x = 1; x <= W; x++)
    {
        for (int y = 1; y <= H; y++)
        {
            min_horizontal = x*y;
            min_vertical = x*y;
            for (int i = 1; i <= x; i++)
            {
                min_horizontal = min(min_horizontal, waste[x - i][y] + waste[i][y]);
            }
            for (int j = 1; j <= y; j++)
            {
                // min_horizontal = min(min_horizontal, waste[W-i][] + waste[i][H]);
                min_vertical = min(min_vertical, waste[x][y - j] + waste[x][j]);
            }
            res = min(waste[x][y],min(min_horizontal, min_vertical));
            waste[x][y] = res;
        }
        // min_horizontal = min(min_horizontal, waste[W-i][] + waste[i][H]);
    }

    cout << waste[W][H] << endl;

}