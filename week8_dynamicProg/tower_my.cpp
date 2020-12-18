#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXLENGTH 100
using namespace std;
struct block
{
    int a, b, h;

    block(int a, int b, int h)
    {
        this->a = a;
        this->b = b;
        this->h = h;
    }

    block()
    {
    }
};

vector<block> B;
int map[MAXLENGTH][MAXLENGTH];
int max_h[MAXLENGTH];

int main()
{
    int n, i, ans = 1;
    int a, b, c;
    while (scanf("%d", &n) && n)
    {
        // test case n
        B.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            B.push_back(block(a, b, c));
            B.push_back(block(a, c, b));
            B.push_back(block(b, c, a));
        }

        // check whether mappable between 2 cubic or not.
        for (int i = 0; i < B.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                map[i][j] = 0;
                if (i == j)
                {
                    continue;
                }
                if ((B[i].a > B[j].a && B[i].b > B[j].b) || (B[i].a > B[j].b && B[i].b > B[j].a))
                {
                    map[i][j] = 1;
                }
            }
        }
        memset(max_h, 0, sizeof max_h);
        // check whether mappable between 2 cubic or not.

        int max_s = -1;
        for(int i = 0; i< B.size(); i++) {
            if(max_h[i] == 0) {
                max_h[i] = 
            }
        }
    }
}