#include<iostream>
#include<algorithm>
#include<cmath>

#define MAXLENGTH 1000006
using namespace std;
int n;
int a[MAXLENGTH];
int t[MAXLENGTH*4];
int m;
int j, k;
int ret = 0;
int min_v(int x, int y) {
    return (x<y?x:y);
}
int max_v(int x, int y) {
    return (x>y?x:y);
}

int getMid(int s, int e) {
    return (s+ (e-s)/2);
}

int cal_min(int k, int l, int r, int L, int R) {
    // int mid = getMid(f,l);
    // if(f==l) {
    //     return a[f];
    // }
    // else if(l-f == 1) {
    //     return min_v(a[f], a[l]);
    // }
    // else {
    //     return min_v(cal_min(f, mid), cal_min(mid, f));
    // }

    // -- METHOD 2 --
    // printf("%d %d %d %d\n", l, r, L, R);
    if(r < L || l > R) return 1e7;
    if(L<= l && r <=R) {
        return t[k];
    }
    int mid = (r+l)/2;
    // printf("%d\n", mid);
    return min_v(cal_min(k*2, l, mid, L, R), cal_min(k*2+1, mid+1, r, L, R));


}

void build(int k, int l, int r) {
    if(l==r) {
        t[k] = a[l];
        return;
    }
    int mid = (l+r) / 2;
    build(2*k, l, mid);
    build(2*k+1, mid+1, r);
    // printf("%d - %d\n", t[2*k], t[2*k+1]);
    t[k] = min_v(t[2*k], t[2*k+1]);
}
int main() {
    cin >> n;
    // int old_l, old_r;
    for(int i = 1; i<= n; i++) {
        cin >> a[i];
    }
    build(1,1,n);
    // cout << t[10] << endl;
    cin >> m;
    while(m > 0) {
        cin >> j >> k;
        // old_l = j, old_r=k;
        // cout << cal_min(j,k) << endl;
        ret += cal_min(1,1, n, j+1,k+1);
        m--;
        // break;
    }
    cout << ret << endl;
}