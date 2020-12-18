#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int x[1005];

int main() {
    int n, len;
    scanf("%d %d", &n, &len);
    for(int i = 0; i< n; i++) {
        scanf("%d", &x[i]);
    }
    sort(x, x+n);
    double ret = max(x[0], len - x[n-1]);
    for(int i = 0; i< n-1; i++) {
        double cur = (double)(x[i+1] - x[i])/2;
        if(cur > ret) {
            ret = cur;
        }
    }
    printf("%.9lf\n", ret);
}