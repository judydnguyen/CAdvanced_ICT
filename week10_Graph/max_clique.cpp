#include <iostream>
using namespace std;
const int MAX = 13;
const int MAX_E = 100;
int chosen[MAX_E]; // list of edges
bool visited[MAX];
int N, M;
int graph[MAX][MAX];
int res;
int d[MAX_E]; // degree of the vectices

bool is_clique(int b)
{
    for (int i = 1; i < b; i++)
        for (int j = i + 1; j <= b; j++)
            if (graph[chosen[i]][chosen[j]] == 0)
                return false;
    return true;
}

void TRY(int k)
{
    if(k-1 > res)
    res = k-1;
    for (int i = chosen[k - 1] + 1; i <= N; i++)
    {
        if (!visited[i])
        {
            chosen[k] = i;
            if (is_clique(k) && k < N)
                {
                    TRY(k + 1);
                }
        }
        visited[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    int tmp1, tmp2;
    for (int i = 1; i <= M; i++)
    {
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = 1;
        graph[tmp2][tmp1] = 1;
    }
    TRY(1);
    cout << res << endl;
}