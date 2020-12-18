#include <iostream>
#include <stack>
#include <string>
#include <map>
#define pii pair<int,int>
using namespace std;
int noRow = 0, noCol = 0;
map<pii, int> map1;
map<pii, int> map2;
map<pii, int> submap1;
map<pii, int> submap2;

int maxObject() {
    // moving the first map
    int max_ret = 0;
    for(int i = -(noRow); i<= noRow; i++) {
        for(int j = -(noCol); j <= noCol; j++)
         {
             int retval = 0;
             int x0 = 0, y0= 0, x1=noRow, y1=noCol;
             if(i < 0) { // row down
                x0 = -(i);
             }
             if (i>0) // row up
             {
                 x1 = noRow - i;
             }
             if(j < 0) // col left {
                 {
                 y1 = noCol + j;
             }
             if (j > 0) // col right
             {
                 y0 = j;
             }

             for(int m = x0; m < x1; m++)
             {
                 for(int n = y0; n < y1; n++)
                 {
                    //  if(map2[pii(m,n)] == 0)
                    // //  submap2[pii(m,n)] = 9999;
                    //  else {
                    //     submap2[pii(m,n)] = 1;
                    //  }
                     if(map2[pii(m,n)] == 1 && map1[pii(m+i, n-j)] == 1)
                        retval += 1;

                 }
             }
             if(retval > max_ret) 
             max_ret = retval;


         }
    }
    return max_ret;
}
int main() {
    int numtest;
    cin >> numtest;
    for(int i = 0; i< numtest; i++) {
        cin >> noRow >> noCol;
        for(int j = 0; j< noRow; j++)
        for(int k = 0; k<noCol; k++) {
            cin >> map1[pii(j, k)];
        }
        for(int j = 0; j< noRow; j++)
        for(int k = 0; k<noCol; k++) {
            cin >> map2[pii(j, k)];
        }
    }
    cout << maxObject();
}