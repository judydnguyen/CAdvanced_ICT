#include<iostream>
using namespace std;

typedef unsigned long long ull;
ull const MAX_LENGTH = (1e6 +1);
ull const P = 1e9 + 7;

ull addmod(ull a, ull b) {
    a = a % P;
	b = b % P;
	ull c = P - a;
	if (c>b) return (a + b);
	else return (b - c);
}

ull arrmod(ull arr[],int l, int h) {
    // printf("l = %d, h= %d.\n", l, h);
    if(l==h) {
        
        return arr[l] % P;
    }
    if(l<h)
    {
        int m = (l + h)/2;
    // printf("%d: \n", m);
    return addmod(arrmod(arr,l,m),arrmod(arr,m+1,h));
    }
    return 0;
    // ull retval = 0;
    // for(int i=l; i< h; i++)
    // {
    //     retval = addmod(retval, arr[i]);
    // }
    // return retval;
}
int main() {
    long long n;
    cin >> n;
    ull arr[MAX_LENGTH];
    for (int i = 0; i< n; i++)
    cin >> arr[i];
    cout << arrmod(arr,0, n);
}