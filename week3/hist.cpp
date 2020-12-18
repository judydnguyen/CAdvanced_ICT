#include <iostream>
#include <stack>
#include <string>
#include <map>
#define N 1000000
using namespace std;

long long R[N];
long long L[N];

// using stack to get index of left and right.
// stack<int> S;
//  for  i= 0 -> n-1; {
//      while S is not empty and h[S.top] > h[i] {
//          r[s(top)] = i, S.pop

//      }
//      S.push(i)
//  }

//  for  i= n -1 -> 0; {
//      while S is not empty and h[S.top] > h[i] {
//          l[s(top)] = i, S.pop

//      }
//      S.push(i)
//  }

// for i = 0 -> n-1
// long long A = h[i] * (R[i]-L(i) - 1);
// ans = A > ans ? A: ans;

unsigned long long maxArea(int heightArr[], int arrLength)
{
    long long ans = 0;
    stack<int> S;
    for (int i = 1; i <= arrLength+1; i++)
    {
        while (!S.empty() && heightArr[S.top()] > heightArr[i])
        {
            
                R[S.top()] = i;
                S.pop();
            
        }
        // printf("\nHere: %d", i);
        S.push(i);
    }

    for (int i = arrLength; i >=0; i--)
    {
        while (!S.empty() && heightArr[S.top()] > heightArr[i])
        {
            
                L[S.top()] = i;
                S.pop();
        }
        S.push(i);
    }

    for (int i = 1; i <= arrLength; i++)
    {
        // printf("\n...%d-%d", L[i], R[i]);
        long long A = heightArr[i] * (R[i] - L[i] - 1);
        ans = A > ans ? A : ans;
    }

    return ans;
}

unsigned long long maxRectArea(unsigned long long heightArr[], int arrLength)
{
    long long ans = 0;
    for (int i = 0; i < arrLength; i++)
    {
        unsigned long long min_h = heightArr[i];
        for (int j = i; j < arrLength; j++)
        {
            min_h = min(min_h, heightArr[j]);
            long long A = (j - i + 1) * min_h;
            ans = A > ans ? A : ans;
        }
    }
    return ans;
}

int main()
{
    int arrLength;
    cin >> arrLength;
    while (arrLength != 0)
    {
        // 0cout << arrLength;
        int heightArr[arrLength + 1];
        for (int i = 1; i <= arrLength; i++)
        {
            cin >> heightArr[i];
        }
        cout << maxArea(heightArr, arrLength) << endl;
        cin >> arrLength ;
    }
}