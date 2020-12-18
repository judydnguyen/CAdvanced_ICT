#include<iostream>
using namespace std;
#define MAX_LENGTH 10000000
 
 
int max(int a, int b) {
	return a > b ? a : b;
}
 
int max(int a, int b, int c) {
	return max(max(a,b), c);
}
 
void maxSum(int arr[], int l, int h) {
	int max_Sum = arr[l];
	int s = max_Sum;
	for (int i = 1; i<h; i++) {
		if ( s >0 ) {
			s += arr[i];
		}
		else
		s = arr[i];
		max_Sum = s > max_Sum? s: max_Sum;
	}
	cout << max_Sum;
}
 
int main() {
	int n; //number of elements in array
	
	cin >> n >> m;
	int arr[MAX_LENGTH];
	for(int i=0; i<n; i++){
//  cout<<"Insert element "<<i<<": ";
    cin>>arr[i];
  }
    maxSum(arr, 0, n);
	
 
}