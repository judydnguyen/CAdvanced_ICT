#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#define MAX_SIZE 100006
 
using namespace std;
float ret_min = __FLT_MAX__;
int N;
int indx1, indx2;
typedef struct Point {
    float x;
    float y;
    int ind;
} point;
point p[MAX_SIZE];
 
int compareX(const void*a, const void*b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->x - p2->x);
}
 
int compareY(const void*a, const void*b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->y - p2->y);
}
 
float dis(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
 
float minDisArr(Point P[], int n) // n is size 
{
    float min_d = __FLT_MAX__;
    for(int i = 0; i< n; i++) {
        for(int j = i+1; j<n ; j++ ) {
            if(dis(P[i], P[j]) <= ret_min) {
                ret_min = dis(P[i], P[j]);
                indx1 = P[i].ind;
                indx2 = P[j].ind;
                // cout << indx1 << " " << indx2 << endl;
            }
        }
    }
    // cout << "min_Disarr" << min_d << endl;
    return ret_min;
}
 
float min(float x, float y)  
{  
    return (x < y)? x : y;  
} 
 
float minDisMiddle(Point strip[], int size_arr, float d) {
    float min_d = d;
    qsort(strip, size_arr, sizeof(point), compareY);
    for(int i = 0; i< size_arr; i++) {
        for(int j = i+1; j< size_arr && (strip[j].y - strip[i].y) <= ret_min; j++)
        if(dis(strip[j], strip[i]) <= ret_min) {
            ret_min = dis(strip[j], strip[i]);
            indx1 = strip[i].ind;
            indx2 = strip[j].ind;
            // cout << indx1 << " " << indx2 << endl;
        }
    }
    // cout << "min_Dis_Middle" << min_d << endl;
    return ret_min;
}
 
float solve(Point P[], int n) {
    // cout << d 
    // cout << n;
    if(n<= 3)
        return minDisArr(P, n);
    int mid = n/2;
    // cout << "mid_c: " << mid <<endl;
    // for(int i = 0; i<n ; i++) {
    //     cout << "s: " << P[i].ind <<endl;
    // }
    Point midPoint = P[mid];
    // cout << "mid: " << midPoint.x << ", " << midPoint.y << endl;
    float ml = solve(P,mid);
    float mr = solve(P+mid, n-mid);
 
    ret_min = min(ml, mr);
    // cout << d << endl;
    Point strip[n];
    int j = 0;
    for(int i = 0; i< n; i++) {
        if (abs(P[i].x - midPoint.x) <= ret_min)
            strip[j] = P[i], j++;
    }
    return min(ret_min, minDisMiddle(strip, j, ret_min));
}
 
int main() {
    cin >> N;
    for(int i = 0; i< N; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].ind = i;
    }
    qsort(p, N, sizeof(point), compareX);
    float ret = solve(p,N);
    if (indx1 > indx2) {
        int tmp = indx1;
        indx1 = indx2;
        indx2 = tmp;
    }
    printf("%d %d %.6f", indx1, indx2, ret);
    // cout << indx1 << " " << indx2 << " " << ret << endl;
 
}