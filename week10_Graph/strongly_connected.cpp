#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1e6+5;

int N, M;
char COLOR[MAX];
vector<int> A[MAX]; //list of adjancent nodes of node X[i]
int f[MAX]; // finish time of u. 
int ICC[MAX]; 
int NCC; //number of connected components
vector<int> A1[MAX];
int x[MAX]; //record the nodes.
int len_x;
int t;
void INPUT()
{
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        A[tmp1].push_back(tmp2);
        // X[tmp2].push_back(tmp1);
    }
}

void buildResidualGraph() {
    for(int v = 1; v<= N; v++ ) {
        for(int i = 0; i< A[v].size(); i++){
            int u = A[v][i]; // (u,v) is an arc of G => (u,v) is an arc of G'
            A1[u].push_back(v);
    }
}
}

void init() {
    for(int v = 1; v<= N; v++) 
    COLOR[v] = 'w';
}

void DFS1(int u)
{
    t++;
    COLOR[u] = 'g';
    ICC[u] = NCC;
    for(int i = 0; i < A[u].size(); i++)
    {
        int v = A[u][i];

        if(COLOR[v] == 'w')
            DFS1(v);
    }

    t++;
    f[u] = t;
    x[len_x] = u;
    len_x ++;
        
}
void DFS1() {
    init();
    len_x = 0;
    for(int v = 1; v<= N; v++) {
        if (COLOR[v] == 'w')
        DFS1(v);
    }
}

void DFS2(int u)
{
    COLOR[u] = 'g';
    ICC[u] = NCC;
    for(int i = 0; i< A1[u].size(); i++ ) {
        int v = A1[u][i];
        if(COLOR[v] == 'w') DFS2(v);
    }
}

void DFS2() {
    init();
    NCC = 0;

    for(int i = len_x-1; i>= 0; i--) {
        int v = x[i];
        if(COLOR[v] == 'w') {
            NCC++;
            DFS2(v);
        }
    } 
}


void SOLVE()
{
    DFS1();
    buildResidualGraph();
    DFS2();
    // for(int k = 1; k<= NCC; k++) {
    //     cout << "SCC["<< k<<"]: ";
    //     for(int v = 1; v<= N; v++) if(ICC[v] == k) cout << v << " ";
    //     cout << endl;
    // }
    // DFS();
    cout << NCC;
}



int main()
{
    INPUT();
    SOLVE();
}
