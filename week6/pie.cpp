#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const double pi = acos(-1);
const double appr = 1e-7;
int n, i, f;
double min_sz, max_sz, mid;
int cnt, cas;
double area[10001];

int main() {
    cin >> cas;
    while(cas --) {
        cin >> n >> f;
        f+=1;
        for(int i = 0; i< n; i++) {
            int tmp;
            cin >> tmp;
            tmp *= tmp;
            area[i] = tmp;
        }
        min_sz = 0.0;
        max_sz = 100000000.0;
        while(min_sz + appr < max_sz) {
            mid = (min_sz + max_sz) / 2;
            cnt = 0;
            for(int i = 0; i< n ; i++) {
                cnt += (int)floor(area[i]/mid);
            }
            if(cnt < f) {
                max_sz = mid;
            }
            else {
                min_sz = mid;
            }
        }

        min_sz *= pi;
        printf("%.6lf\n",min_sz);

    }
}