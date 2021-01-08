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
int k;
int s[102];
// int src, des;
vector<pair<int,int> > E[MAX]; // Adjacency list

int dijkstra(int src, int des) {
    
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
    return D[des];
}

int main() {
    int ret = -INF;
    int t1, t2;
    cin >> N >> m;
    int tmp1, tmp2, w;
    for(int i = 1; i<= m ; i++) {
        cin >> tmp1 >> tmp2 >> w;
        E[tmp1].push_back(make_pair(w, tmp2));
        E[tmp2].push_back(make_pair(w, tmp1));
    }
    
    cin >> k;
    for(int i = 1; i<= k; i++) {
        cin >> s[i];
    }
    // cin >> t1 >> t2;
    for(int i = 1; i<= N; i++ ) D[i] = INF;
    // dijkstra(2,5);
    // for(int i = 1; i<k; i++)
    // for(int j = i+1; j<=k; j++)
    // {
    //     for(int m = 1; m<= k; m++ ) D[m] = INF;
    //     int cur_p = dijkstra(s[i], s[j]);
    //     if(cur_p > ret) ret = cur_p;
    // }
    // cout << ret << endl;
    cout << dijkstra(1,3) << endl;

    // cout << D[5] << endl;
}