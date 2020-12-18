#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5 + 10;
int N, M;
vector<int> X[MAX]; // adjacency list of graph
bool visited[MAX];
vector<int> tin, low;
vector<pair<int, int> > br;
int timer;
int num_cp;
int num_b;
bool cp[MAX];
void isArticulationPoint(int v)
{
    if (!cp[v])
    {
        cp[v] = true;
        num_cp += 1;
    }
}

void isBridge(int v, int u)
{
     br.push_back(pair<int, int>(v, u));
}
int min(int a, int b)
{
    return a < b ? a : b;
}
void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = ++timer;
    int children = 0;
    for (int j = 0; j < X[v].size(); j++)
    {
        if (X[v][j] == p)
            continue; // not articulation point
        if (visited[X[v][j]])
        {
            low[v] = min(low[v], tin[X[v][j]]);
        }
        else
        {
            children ++;
            dfs(X[v][j], v);
            low[v] = min(low[v], low[X[v][j]]);
            if (low[X[v][j]] > tin[v]) isBridge(v, X[v][j]);
            if (low[X[v][j]] >= tin[v] && p != -1)
            // num_cp += 1;
            {
                isArticulationPoint(v);
                // if (low[X[v][j]] > tin[v])
                // {
                //     isBridge(X[v][j], v);
                    
                // }
            }
        }
    }
    if (p == -1 && children > 1)
    {
        isArticulationPoint(v);
        
    }
    // num_cp += 1;
}

int main()
{
    timer = 0;
    cin >> N >> M;
    int tmp1, tmp2;
    for (int i = 1; i <= M; i++)
    {
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
    }
    tin.assign(MAX, -1);
    low.assign(MAX, -1);
    // main process
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
            dfs(i, -1);
    }
    cout << num_cp << " ";
    cout << br.size() << endl;
}