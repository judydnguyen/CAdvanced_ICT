#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

// compare 2 area. 1 is equal, 0 is not.
map<pair<int, int>, int> map1;
map<pair<int, int>, int> map2;
map<pair<int, int>, int> submap1;
map<pair<int, int>, int> submap2;
int noRow = 0, noCol = 0;
pair<int, int> compare2Area(int noRow, int noCol)
{
    int numObject = 0;
    for (int row = 0; row < noRow; row++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < noCol; j++)
        {
            if (map1[pair<int, int>(row, j)] == 1)
                numObject += 1;
            sum1 += map1[pair<int, int>(row, j)];
            sum2 += map2[pair<int, int>(row, j)];
        }
        if (sum1 != sum2)
        {
            return pair<int, int>(0, 0);
        }
    }
    for (int col = 0; col < noRow; col++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < noRow; j++)
        {
            sum1 += map1[pair<int, int>(j, col)];
            sum2 += map2[pair<int, int>(j, col)];
        }
        if (sum1 != sum2)
        {
            return pair<int, int>(0, 0);
        }
    }

    return pair<int, int>(1, numObject);
}

int maxObject(int startX, int startY, int numRow, int numCol) {
    int totalObject = 0;
   for(int i = startX; i < numRow; i++)
   {
       for(int j = startY; j < numCol; j++)
       {
           // calculate by sum of row.
           totalObject += map1[pair<int,int>(i,j)];
           int maxX_map2 = noRow - numRow + 1;
           int maxY_map2 = noCol - numCol + 1;
           submap1[pair<int,int>(i-startX, j - startY)] = map1[pair<int,int>(i,j)];
           for(int m = 0; m < maxX_map2; m++)
           {
               for(int n = 0; n < maxY_map2; m++)
               {
                   submap2[pair<int,int>()];
               }
           }

       }
   }
}

void input()
{
    int noTest;
    cin >> noTest;
    for (int i = 0; i < noTest; i++)
    {

        cin >> noRow >> noCol;
        for (int j = 0; j < noRow; j++)
        {
            for (int k = 0; k < noCol; k++)
            {
                cin >> map1[pair<int, int>(j, k)];
            }
        }
        for (int j = 0; j < noRow; j++)
        {
            for (int k = 0; k < noCol; k++)
            {
                cin >> map2[pair<int, int>(j, k)];
            }
        }

        // solve here.
    }
}
void solve()
{
    int startX, startY;
    int endX, endY;
    int maxRow, maxCol;
    for (int i = 0; i < noRow; i++)
    {
        for (int j = 0; j < noCol; j++)
        {
            startX = i;
            startY = j;
            maxRow = noRow - i;
            maxCol = noCol - j;
            for (int m = 1 ;m <= maxRow; m++)
            {
                for (int n = 1; n <= maxCol; n++)
                {
                    endX = m;
                    endY = n;
                }
            }
        }
    }
}
int main()
{
    input();
    // for (int i = 0; i<3; i++) {
    //     for (int j = 0; j<4; j++) {
    //         cout << map1[pair<int, int>(i,j)] << ' ';
    //         // cout << map2[pair<int, int>(i,j)];
    //         // cout << map1[pair<int, int>(i,j)];
    //     }
    //     cout << '\n';
    // }
    // for (int i = 0; i<3; i++) {
    //     for (int j = 0; j<4; j++) {
    //         cout << map2[pair<int, int>(i,j)] << ' ';
    //         // cout << map2[pair<int, int>(i,j)];
    //         // cout << map1[pair<int, int>(i,j)];
    //     }
    //     cout << '\n';
    // }
    // cout << compare2Area(map1, map2, 3, 4);
}

1
10 8
0 1 1 0 0 0 0 0
0 1 1 1 0 0 0 0
0 0 0 0 0 1 0 0
0 1 1 1 1 0 0 0
0 0 1 1 1 0 0 0
0 0 0 1 1 0 0 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

1
10 8
0 1 1 0 0 0 0 0
0 1 1 1 0 0 0 0
0 0 0 0 0 1 0 0
0 1 1 1 1 0 0 0
0 0 1 1 1 0 0 0
0 0 0 1 1 0 0 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1
1 1 0 1 1 1 1 0
1 1 0 0 1 1 1 0
1 0 0 0 0 1 1 0
0 0 0 1 0 0 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 0 0