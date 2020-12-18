#include<iostream>
#include<list>
#include<vector>
#include<set>

using namespace std;
int main() {
    set<int> S;
    for(int i = 1; i<=10; i++) {
        S.insert(i);
    }
    for (set<int>::iterator it = S.begin(); it != S.end(); it ++) {
        cout << *it <<endl;
        
    }
    if(S.find(7) != S.end()) 
    cout << "S cointains 7." << endl;
    else 
    cout << "S doesn't contains 7." << endl;
}