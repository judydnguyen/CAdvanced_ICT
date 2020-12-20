#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;
int N, M, K;
int u[MAX]; // start node
int v[MAX]; // end node
int c[MAX]; // cost corresponding
int ET[MAX];
int nET;

// disjoint set 

int r[MAX]; // rank of set v
int p[MAX]; // parent of v
int cnt[MAX]; // number of node in a tree
int total_w[MAX];
long long rs;

void link(int x, int y, int w) {
    if(r[x] > r[y]) 
    {
        p[y] = x;
        total_w[x] += total_w[y];
        total_w[x] += w;
        cnt[x] += cnt[y];
    }
    else {
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] + 1;
        total_w[y] += total_w[x];
        total_w[y] += w;
        cnt[y] += cnt[x];
    }
}

void makeSet(int x) {
    p[x] = x;
    r[x] = 0;
    cnt[x] = 1;
}
int findSet(int x) {
    if( x != p[x])
    p[x] = findSet(p[x]);
    return p[x];
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b; b= tmp;

}

void swapEdge(int i, int j) {
    swap(c[i], c[j]);
    swap(v[i], v[j]);
    swap(u[i], u[j]);
}

int partition(int L, int R) {
    int pivot = c[R];
    // swapEdge(index, R);
    int storeIndex = L;
    for(int i = L; i <= R -1; i++) {
        if(c[i] < pivot) {
            swapEdge(storeIndex, i);
            storeIndex++;
        }
    }
    swapEdge(storeIndex, R);
    return storeIndex;
}

bool compareEdge(int i, int j) {
    return c[i] < c[j];
}

void quick_sort(int L, int R)
{
    if (L < R)
    {
        int pi = partition(L, R);

        quick_sort(L, pi - 1);
        quick_sort(pi+1, R);
    }
}

void INPUT() {
    int tmp1, tmp2, weight;
    
    cin >> N >> M >> K;
    for(int i = 1; i<= M; i++) {
        cin >> tmp1 >> tmp2 >> weight;
        u[i] = tmp1;
        v[i] = tmp2;
        c[i] = weight;
    }
}

void SOLVE() {
    for(int x = 1; x<= N; x++) makeSet(x);
    quick_sort(1, M);
    rs = 0;
    int flag = 0;
    int count = 0;
    nET = 0;
    for(int i = 1; i <= M; i++) {
        int ru = findSet(u[i]);
        int rv = findSet(v[i]);
        if(ru != rv) {
            link(ru, rv, c[i]);
            nET ++;
            ET[nET] = i;
            rs += c[i];
            count ++;
            if(nET == K) {
             flag = 1;
             break;
            }
            if(count == N - 1) break;
        }
    }
    if(flag == 1)
    cout << rs << endl;
    else 
    cout << -1 << endl;
}

int main() {
    INPUT();
    SOLVE();
}