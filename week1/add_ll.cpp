#include<iostream>
using namespace std;
int main() {
    unsigned long long a,b,a1,a0,b1,b0, c1, c0;

    cin >>a >>b;
    a0 = a%10;
    a1 = a/10;
     b0 = b%10;
    b1 = b/10;
    c0 = (a0+b0) %10;
    c1 = (a0+b0) /10; //remains
    c1 = a1 +b1+c1;
    if(c1>0) cout << c1;
    cout << c0;
}