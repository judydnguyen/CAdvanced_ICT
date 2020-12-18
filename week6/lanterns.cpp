#include <iostream>
#include <algorithm>
#include <cmath>
#define lli int
using namespace std;
const double pi = acos(-1);
const int appr = 1e-9;
// int n, i, f;
// lli n, l;
double min_sz, max_sz, mid;
// int cnt, cas;
int flag = 0;
// lli area[1005];

typedef struct lant
{
    lli x;
    lli y;
    // int ind;
} lantern;

int max_t(int x, int y)  
{  
    return (x > y)? x : y;  
} 

int area[1005];
int compare(const void *a, const void *b)
{
    lantern *p1 = (lantern *)a;
    lantern *p2 = (lantern *)b;
    return p1->x - p2->x;
}
int main()
{
    int n, l;
    cin >> n >> l;
    // cout << n << endl;
    for (int j = 0; j < n; j++)
    {
        cin >> area[j];
    }

    sort(&area[0], &area[0] + (int)n, less<int>());
    // sort(area, area+n);
    // qsort(area, n, sizeof(lantern), compare);
    // for (int j = 0; j < n; j++)
    // {
    //     cout << area[j] << " ";
    // }
    // int max_dis = 0;
    // for(int i = 0; i<n-1; i++) {
    //     if(int tmp = area[i+1] - area[i] > max_dis) {
    //         max_dis = tmp;
    //     }
    // }
    // max_dis = max_t(max_dis, area[0]-0);
    // max_dis = max_t(max_dis, l-area[(int)n-1]);
    // int ret = max_dis/2;


    // std::sort(std::begin(area), std::end(area + n), std::greater<double>{});
    // while(cas --) {
    //     cin >> n >> f;
    //     f+=1;
    //     for(int i = 0; i< n; i++) {
    //         int tmp;
    //         cin >> tmp;
    //         tmp *= tmp;
    //         area[i] = tmp;
    //     }
    min_sz = (double)0.0;
    max_sz = -(area[0] - area[(int)n-1]);
    // // cout << max_sz << endl;
    while (abs(max_sz - min_sz) >= 1)
    {
        // cout << abs(max_sz - min_sz) << endl;
        // if(max_sz - min_sz < 1e-7) 
        // {

        // break;
        // }
        mid = (double)(min_sz + max_sz) / 2;
        // cnt = 0;
        // cout << "mid: " << mid << endl;
        // cout << max_sz << ", " << min_sz << endl;
        for (int i = 0; i < n - 1; i++)
        {
            // cnt += (int)floor(area[i]/mid);
            if (area[i] + mid < area[i + 1] - mid)
            {
                flag = 0;
                break;
            }
            if (i == n - 2)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            max_sz = (int)mid;
        }
        else
        {
            min_sz = (int)mid;
        }
    }

    // // min_sz *= pi;
    printf("%.9f\n", mid);
}