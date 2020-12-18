#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#define pii pair<int, int>
#define MAX_LENGTH 200000

using namespace std;
long valueArr[MAX_LENGTH + 1];
long threshold;
long N;

long findMax(long low, long high)
{
    if(low == high) 
    {
        return valueArr[low];
    }
    long mid = (low + high)/2;
    return max(findMax(low,mid), findMax(mid+1, high));
}
int main()
{
    long maxTotal = -1;
    cin >> N >> threshold;
    long i = 1;
    while(i <= N) {
        cin >> valueArr[i];
        i++;
    }
    // calculate output
    long prev_L, prev_R;
    long maxL ;
    long maxR ;
    long deltaL;
    long deltaR;
    // prev_L = valueArr[1];
    // prev_R = -1e9;
    // situation i = 2;
    maxL = valueArr[1];
    maxR = findMax(3, N);
    deltaL = maxL - valueArr[2];
    deltaR = maxR - valueArr[2];
    if(deltaL > threshold && deltaR > threshold)
    {
        maxTotal = deltaL + deltaR;
    }
    for(int i = 3; i < N ; i++) {
        
        maxL = maxL > valueArr[i-1] ? maxL : valueArr[i-1];
        if(valueArr[i] == maxR)
        {
            maxR = findMax(i+1, N);
        }
       
        // prev_R = maxR;
        deltaL = maxL - valueArr[i];
        deltaR = maxR - valueArr[i];
        if(deltaL >= threshold && deltaR >= threshold)
        {
            if(deltaL + deltaR > maxTotal) {
                maxTotal = deltaL + deltaR;
            }
        }
    }
    cout << maxTotal << endl;
}