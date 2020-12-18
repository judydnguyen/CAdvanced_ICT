//
//  main.cpp
//  Training2_LOCATE
//

//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <cstring>
#define pii pair<int,int>
using namespace std;

typedef struct  {
    int x,y;
} coordinate;
int dd[2003][2003];
coordinate before[10003], after[10003];
int main() {
    // coordinate before[10003], after[10003];
    
    // clearmap < pair<int,int>, int > dd;
    // map < int, pii> before, after;
    int t,l,c,cb,ca;
    cin >> t;
    // cout << t;
    
    while (t--) {
        int ans=0;
        cb = 0; ca = 0;
        std::cin >> l >> c;
        
        for (int i=0; i<l; i++) {
            for (int j=0; j<c; j++) {
                int k;
                std::cin >> k;
                if (k==1) {
                    before[cb].x = i;
                    before[cb].y = j;
                    cb++;
                }
            }
        }
 
        // auto start = chrono::steady_clock::now();
        for (int i=0; i<l; i++) {
            for (int j=0; j<c; j++) {
                int k;
                std::cin >> k;
                if (k==1) {
                    after[ca].x = i;
                    after[ca].y = j;
                    ca++;
                }
            }
        }
        //  auto start2 = chrono::steady_clock::now();
        // for(int i = 0; i< 2003; i++)
        // {
        //     for(int j = 0; j< 2003; j++) {
        //         dd[pair<int,int>(i,j)] = 0;
        //     }
        // }
        // auto end2 = chrono::steady_clock::now();
        // auto diff2 = end2 - start2;
        // cout << chrono::duration <double, milli> (diff2).count() << " ms" << endl;
        memset(dd, 0, sizeof(dd));
        for (int i=0; i<cb; i++) {
            for (int j=0; j<ca; j++) {
                int ttx = before[i].x - after[j].x + 1000;
                int tty = before[i].y - after[j].y + 1000;
                dd[ttx][tty] += 1;
                // dd[pair<int,int>(ttx,tty)] += 1;
                ans = ans < dd[ttx][tty] ? dd[ttx][tty] : ans;
                // ans = ans < dd[pair<int,int>(ttx,tty)] ? dd[pair<int,int>(ttx,tty)] : ans;
            }
        }
        //        auto end = chrono::steady_clock::now();
        // auto diff = end - start;
        // cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
        std::cout << ans << "\n";
        // memset(dd, 0, sizeof(dd));
    }
    return 0;
    
}
