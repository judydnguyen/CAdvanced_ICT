#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;
int N, M;
// char COLOR[MAX];
bool visited[MAX];
vector<int> X[MAX]; //list of adjancent nodes of node X[i]
int p[MAX];
int cnt = 0;

void setParent(int i)
{
    visited[i] = true;
    for (int j = 0; j < X[i].size(); j++)
    {
        if (!visited[X[i][j]])
        {
            p[X[i][j]] = i;
            // visited[X[i][j]] = true;
            cnt += 1;
        }
    }
    // if (X[i].size() > 0 && cnt < N)
    for (int j = 0; j < X[i].size(); j++)
    {
        if (X[i].size() > 0 && cnt < N && !visited[X[i][j]])
        {
            // cout << X[i][j] << endl;
            setParent(X[i][j]);
        }
    }
}

int main()
{
    cin >> N;
    int tmp1, tmp2;
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
    }
    // main process
    cnt += 1; // count = 1
    visited[1] = true;
    // for (int i = 1; i <= N; i++)
    // {
    //     visited[1] = true;
    //     for (int j = 0; j < X[i].size(); j++)
    //     {
    //         if (!visited[X[i][j]])
    //         {
    //             p[X[i][j]] = i;
    //             visited[X[i][j]] = true;
    //         }
    //     }
    // }
    setParent(1);

    for (int i = 2; i <= N; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}