#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1001;
unsigned long long n, k;
vector<pair<int,int> > a, b;

unsigned long long solve(vector<pair<int,int> > a) {
    sort(a.begin(), a.end()); // sort by increasing order of position (a[i].first)
    int p, m, x, r, remain, num;
    unsigned long long d = 0;
    for(int i = a.size() -1 ; i >=0 ; i --)
    {
        m = a[i].second;
        x = a[i].first;
        if(m == 0)
        {
            continue;
        }
        p = m / k;
        r = m % k;
        d += 2ll * p * x;
        a[i].second = r; // remaining packages
        if (a[i].second > 0) {
            d += 2ll * x; // need the ship the remains for customer.
            remain = k; // init number of packages on hand of shipper.
            for(int j = i; j>=0; j--) {
                num = min(remain, a[j].second);
                a[j].second -= num;
                remain -= num;
                if(remain == 0)
                {
                    break;
                }
            }

        }
    }
    return d;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i<n ; i++) {
        int x, m;
        cin >> x >> m;
        if (x >= 0) {
            a.push_back(pair<int,int>(x,m));

        }
        else {
            b.push_back(pair<int,int>(-x,m));
        }
    }
    cout << solve(a) + solve(b);

}

