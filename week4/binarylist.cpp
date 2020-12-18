#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 20;
typedef unsigned long long ull;
int length;
int k, thres;
string prev_seq;
int cnt = 0;
int flag = 1;
int sum = 0;
void input() {
    cin >> length >> k >> thres;
    // cin >> prev_seq;
    for(int i = 0; i< length; i++) {
        prev_seq[i] = '0';
    }
}

int solve() {
    sum = 0;
    for(int i = length-1 ; i>=0; i--) {
        
        if(prev_seq[i] == '0'){
            prev_seq[i] = '1';
            // sum += prev_seq[i];
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
            // sum += prev_seq[i];
        }
    }
    if (flag == 1)
    return 1;
    else {
        return -1;
    }
}

bool check_valid() {
    int j = 0;
    while(prev_seq[j] != '0') {
        j+=1;
    }
    sum = 0;
    while(j < length) {
        if(prev_seq[j] == '0')
        sum += 1;
    }
}

int main() {
    input();
while(1) {
    if(solve() == 1) {
        sum = 0;
        for(int i = 0; i < length; i++) {
            if(prev_seq[i] == '0')
            sum += 1;
        }
        if(cnt == k) {
        cout << prev_seq;
        }
    }
    else {
        cout << -1;
        break;
    }
}