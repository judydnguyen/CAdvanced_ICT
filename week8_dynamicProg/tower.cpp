#include <stdio.h>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;

struct cubic
{
	int a, b, h;

	cubic(int a, int b, int h)
	{
		this->a = a;
		this->b = b;
		this->h = h;
	}

	cubic() {}
};

vector <cubic> v;
int map[100][100];
int best[100];

void init()
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			map[i][j] = 0;
			if (i == j)
			{
				continue;
			}
			if ((v[i].a > v[j].a && v[i].b > v[j].b) || (v[i].a > v[j].b && v[i].b > v[j].a))
			{
				map[i][j] = 1;
			}
		}
	}
	memset(best, 0, sizeof best);
    // check whether mappable between 2 cubic or not. 
}

int dfs(int p)
{
	int h = v[p].h;
	int ret = h;

	for (int i = 0; i < v.size(); i++)
	{
		if (map[p][i])
		{
			int tmp = h;
			if (best[i] == 0)
			{
				tmp += dfs(i);
			}
			else
			{
				tmp += best[i];
			}
			ret = tmp > ret ? tmp : ret;
		}
	}
	return best[p] = ret;
}

int main()
{
	int n, i, cas = 1;
	int a, b, c;

	while (scanf("%d", &n) && (n != 0))
	{
		v.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			v.push_back(cubic(a, b, c));
			v.push_back(cubic(a, c, b));
			v.push_back(cubic(b, c, a));
		}
		init();
		int max = -1;
		for (i = 0; i < v.size(); i++)
		{
			if (best[i] == 0)
			{
				// best[i] = dfs(i);
                for(int j = 0; j< v.size(); j++) {
                    if(map[i][j]) {
                        
                    }
                }
			}
			max = max > best[i] ? max : best[i];
		}
		printf("Case %d: maximum height = %d\n", cas++, max);
	}
	return 0;
}