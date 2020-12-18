#include <iostream> 
#include <algorithm>
using namespace std; 
typedef unsigned long long ull;
ull n, k, m;
int T;

ull addmod(ull a, ull b) {
    a = a % m;
	b = b % m;
	ull c = m - a;
	if (c>b) return (a + b);
	else return (b - c);
}

ull mulmod(ull a, ull b) // calculate a*b mod P
{
    if ( b == 1)
    return a % m;
    if (a == 1)
    return b % m;
    ull retval = 0;
    
    if (a < b) {
        ull tmp = a;
        a = b;
        b = tmp;
    }
        while(b> 0){
        if (b % 2 == 1)
        {
            retval = addmod(retval,a);
        }
        b /= 2;
        a = addmod(a,a);
        }
    
    return retval;
    
}
ull expmod(ull a, ull b) {
    ull retval = 1; // initialize result
    a = a % m;
    if ( a == 0) return 0;
    while (b > 0) {
        if ( b & 1)
            retval = mulmod(retval, a);
        b = b >> 1; // b/2
        a = mulmod(a,a);

    }
    return retval;

}
ull mod_inverse(ull n) {
    // for(ull i = 1; i< m; i++) {
    //     if(mulmod(n,i) == 1) {
    //         return i;
    //     }
    // }
    ull ret = expmod(n, m-2);
    return ret;
    return -1;
}

ull fact_mod(ull start_n, ull end_n) {
    // cout << "m = " << m << endl;
    ull ret = 1;
    ull i = start_n;
    // cout << mulmod(42,1) << endl;
    while(i >= end_n) {
        ret = mulmod(ret, i);
        // cout << "ret = " << ret <<endl;
        i-=1;
    }
    return ret;
}

ull NcR(ull num, ull r) 
{ 
  
    // p holds the value of n*(n-1)*(n-2)..., 
    // k holds the value of r*(r-1)... 
    // cout << num << ", " << r << endl;
    if(r>num)
    return 0;
    ull p = 1, k = 1; 
  
    // C(n, r) == C(n, n-r), 
    // choosing the smaller value 
    if (num - r < r) 
        r = num - r; 
  
    if (r != 0) { 
        ull fact_n = fact_mod(num,num-r+1);
        // cout << "f_n: " << num <<" - "<<num-r+1 << fact_n <<endl;
        ull fact_k = fact_mod(r,1);
        ull fact_k_inv = mod_inverse(fact_k);
        return mulmod(fact_n, fact_k_inv);
        
  
        // k should be simplified to 1 
        // as C(n, r) is a natural number 
        // (denominator should be 1 ) . 
    } 
  
    else
        p = 1; 
  
    // if our approach is correct p = ans and k =1 
    return p;
} 

void solve() {
    ull p = NcR(n,k);
    cout << p << endl;;
}
// Function to find the nCr 
void input() {
    cin >> T;
    for(int i = 1; i<= T; i++) {
        cin >> n >> k >> m;
        solve();
    }
    
}


// Driver code 
int main() 
{ 
    // int n = 50, r = 25; 
  
    // printNcR(n, r); 
  
    // return 0; 
    input();
} 