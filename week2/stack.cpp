#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<stack>

using namespace std;
int main() {
    stack<int> S;
    for(int i = 0; i<5; i++) {
        S.push(i);
    }
    while(!S.empty()) {
        int v = S.top();
        S.pop();
        cout << v << endl;
    }
}