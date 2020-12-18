#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 20;
typedef unsigned long long ull;
int length;
string prev_seq;
int flag = 1;
void input() {
    cin >> length;
    cin >> prev_seq;
}

void solve() {
    for(int i = length-1 ; i>=0; i--) {
        if(prev_seq[i] == '0'){
            prev_seq[i] = '1';
            flag = 1;
            break;
        }
        else {
            if(i == 0)
            {
                flag = 0;
                break;
            }
            prev_seq[i] = '0';
        }
    }
    if (flag == 1)
    {cout << prev_seq;}
    else {
        cout << -1;
    }
}

int main() {
    input();
    solve();
}