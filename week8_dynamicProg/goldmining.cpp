#include<iostream>
#include<deque>
const int N = 1e6 + 1;
int a[N], S[N];
int n, L1, L2, ans;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> L1 >> L2;
    ans = 0;
    for(int i = 1; i<= n; i++) cin >> a[i];
    deque<int> Q;
    for(int i = 1; i<= n; i++) {

        while(!Q.empty() && Q.front() < i - L2) Q.pop_front();
        if(i-L1 >= 1) {
            while(!Q.empty() && S[Q.back()] < S[i-L1]) Q.pop_back();
            Q.push_back(i-L1);
        }
        // optimal
        S[i] = (Q.empty() ? 0: S[Q.front()]) + a[i];



        // S[i] = a[i];
        // for(int j = i-L2; i<= i-L1; j++) {
        //     S[i] = S[j] + a[i];
        ans = max(ans, S[i]);
        }
    cout << ans;

}
