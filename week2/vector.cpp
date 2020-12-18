#include<iostream>
#include<list>
#include<vector>

using namespace std;
int main() {
    vector<int> V(3,100); // init 3 elem 100
    for(int v = 0 ; v <= 10; v ++) {
        V.push_back(v);

    }

    printf("\n%lu\n", V.size());
    cout << "vector: ";
    for(int i = 0; i< V.size(); i++)  {
        cout << V[i] << " ";
    }
 }