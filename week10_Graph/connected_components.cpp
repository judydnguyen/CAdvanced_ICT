#include<iostream>
#include<vector>

using namespace std;

const int MAX = 31;

int N, M;
char COLOR[MAX];
vector<int> X[MAX]; //list of adjancent nodes of node X[i]
vector<int> A[1];
int ICC[MAX]; 
int NCC; //number of connected components

void INPUT()
{
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
    }
}

void DFS(int u)
{
    COLOR[u] = 'O';
    ICC[u] = NCC;
    for(int i = 0; i < X[u].size(); i++)
    {
        int v = X[u][i];
        if(COLOR[v] == 'W')
            DFS(v);
    }
        
}

void DFS()
{
    for(int v = 1; v <= N; v++)
    {
        COLOR[v] = 'W';
    }
    NCC = 0;
    for(int v = 1; v <= N; v++)
    {
        if(COLOR[v] == 'W')
        {
            NCC++;
            DFS(v);
        }
    }
}


void SOLVE()
{
    DFS();
    cout << NCC;
}



int main()
{
    INPUT();
    SOLVE();
}
