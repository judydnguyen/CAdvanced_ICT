#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#define pii pair<int, int>
#define MAX_LENGTH 100000
using namespace std;
long numTest;
long numRange;
long rangeArr[MAX_LENGTH + 1];
long total = 0;
long totalRange()
{
    stack<long> s;
    long length = numRange;
    long i = 1;
    while (i <= length)
    {
        if (s.empty())
        {
            s.push(rangeArr[i]);
            // cout << s.top();
        }
        else
        {
            long tmp = rangeArr[i];
            if (s.top() != tmp)
            {
                s.push(tmp);
            }
        }
        i++;
    }
    return s.size();
}

long totalRange_optimal(long idx, long newval, long oldval)
{
    long ret = total;
    if(idx >= 2) {
        long left = rangeArr[idx - 1];
        if(oldval == left) {
            if (newval != oldval)
                ret += 1;

        }
        else {
            if(newval == left)
                ret -= 1;
        }
    }
    if(idx < numRange) {
        long right = rangeArr[idx + 1];
        if(oldval == right) {
            if (newval != oldval)
                ret += 1;

        }
        else {
            if(newval == right)
                ret -= 1;
        }
    }
    return ret;
}

int main()
{
    cin >> numRange;
    for (long i = 1; i <= numRange; i++)
    {
        cin >> rangeArr[i];
    }
    total = totalRange();

    cin >> numTest;
    while (numTest > 0)
    {
        long idx, newval;
        cin >> idx >> newval;
        long oldval = rangeArr[idx];
        rangeArr[idx] = newval;
        total = totalRange_optimal(idx, newval, oldval);
        cout << total << endl;
        
        numTest -= 1;
    }
}