#include<iostream>
#include<deque>
#include<vector>
#include<queue>

#define pii pair<int, int>
using namespace std;

const int INF = 2147483647;
const int MAX = 100005;
int D[MAX], N; // Keeps minimum distance to each node
int n, m;
int src, des;
vector<pair<int,int> > E[MAX]; // Adjacency list

void dijkstra() {
    
    D[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0, src));
    while(!q.empty()) {
        pii p = q.top();
        q.pop();
        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;
        for(int i = 0; i< E[u].size(); i++)
        {
            pii pr = E[u][i];
            int v = pr.second;
            int next_dist = dist + pr.first;
            // cout << next_dist << endl;
            // cout << v << endl;
            // cout << D[v] << endl;

            if(next_dist < D[v])
            {
                D[v] = next_dist;
                
                q.push(make_pair(next_dist, v));
            }
            
        }
    }
}

int main() {
    cin >> N >> m;
    int tmp1, tmp2, w;
    for(int i = 1; i<= m ; i++) {
        cin >> tmp1 >> tmp2 >> w;
        E[tmp1].push_back(make_pair(w, tmp2));
    }
    
    cin >> src >> des;
    for(int i = 1; i<= N; i++ ) D[i] = INF;
    dijkstra();

    cout << D[des] << endl;
}