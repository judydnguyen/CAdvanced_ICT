#include<iostream>
#define     N   2*int(1e6)+7
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define     fd(i,a,b)   for(int i=a;i>=b;--i)
#include<deque>

using       namespace std;

int n, res, t[N];

struct point{
    int s, t;
}a[N];

int Q[N]; // ind 0 is length of queue.
bool cmp(point &a, point &b){
    if ((a.t <  b.t) || (a.t == b.t && a.s < b.s)) return true;
    return false;
}

void readf()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].s >> a[i].t;
}

void findd(int x, int value)
{
    if (x <= 0) return;
    res = max(res, value + t[x]);
    x -= x&(-x);
    findd(x, value);
}

void update(int x, int value)
{
    if (x > N) return ;
    t[x] = max(t[x], value);
    x += x&(-x);
    update(x, value);
}

void        solve()
{
    res= 0;
    memset(t,0,sizeof(t));
    sort(a, a+n, cmp); // increasing sort
    // for(int i = 0; i < n; i++)
    // {
    //     findd(a[i].s, a[i].t-a[i].s);
    //     update(a[i].t, a[i].t-a[i].s);
    // }
    int tmp;
    Q[1] = 1; Q[0] = 1;
    for(int i = 1; i< n; i++) {
        int j = i-1;
        while(Q[0] != 0 && j >= 0) {
            int top_q = a[Q[Q[0]]].s - a[Q[Q[0]]].t;
            // if(a[i].t > a[Q[Q]])
            int m = Q[0];
            for(m ; m >= 0; m --) {
                if(a[Q[m]].s < a[i].t)
                    tmp = a[i].s - a[i].t + a[Q[m]].s - a[Q[m]].t;
            }
            if((a[i].s = a[i].s) > top_q) {
                Q[0] ++;
                Q[Q[0]] = i;
            }
           
        }
        res = max(res, tmp);
    }


    cout<<res;
}

main()
{
   // freopen("check.txt","r",stdin);
    readf();
    solve();
}
