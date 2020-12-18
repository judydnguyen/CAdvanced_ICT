#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<queue>

using namespace std;
int main() {
    queue<int> Q;
    for(int i = 0; i< 5; i++) {
        Q.push(i);
    }

    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        cout << v << endl;
    }
}