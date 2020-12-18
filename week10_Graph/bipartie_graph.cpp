#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100005;
int N, M;
int colorArr[MAX];

vector<int> X[MAX]; //list of adjancent nodes of node X[i]
// bool visited[MAX][MAX];

void INPUT()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int tmp1, tmp2, weight;
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
        // cin >> weight;
        // w[tmp1][tmp2] = weight;
        // w[tmp2][tmp1] = weight;
    }
}

int isBipartite(int src)
{
    // cout << src << endl;
    colorArr[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // cout << u << endl;
        // if(visited[u][u] == true) return 0;

        for (int v = 0; v < X[u].size(); v++)
        {
            int m = X[u][v];
            if (colorArr[m] == -1)
            {
                colorArr[m] = 1 - colorArr[u];
                // printf("color of %d is %d\n", v, colorArr[m]);
                q.push(m);
            }

            else if (colorArr[m] == colorArr[u])
                return 0;
        }
    }
    return 1;
}

int SOLVE()
{
    for (int i = 1; i <= N; i++)
        colorArr[i] = -1;
    for (int i = 1; i <= N; i++)
    {
        if (colorArr[i] == -1)
            if (isBipartite(i) == 0)
                return 0;
    }
    return 1;
}

int main() {
    INPUT();
    printf("%d\n", SOLVE());
}