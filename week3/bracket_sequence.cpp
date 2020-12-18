#include <iostream>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX_LENGTH 100000
using namespace std;

int main()
{
    map<char, int> brackets;
    brackets['('] = 1;
    brackets[')'] = -1;
    brackets['['] = 2;
    brackets[']'] = -2;
    char arrInput[MAX_LENGTH+22];
    cin >> arrInput;
    long length = strlen(arrInput);
    // cout << length <<"length " << endl;
    long ans = 0;
    stack<long> s;
    for (long i = 0; i < length; i++)
    {
        // cout << brackets[arrInput[i]];
        if (brackets[arrInput[i]] == 1 || brackets[arrInput[i]] == 2)
        {
            s.push(i);
        }
        else if (s.empty())
        {
            s.push(i);
        }
        else if (brackets[arrInput[i]] + brackets[arrInput[s.top()]] == 0)
            s.pop();
        else
            s.push(i);
    }
    // cout << s.top();
    if (s.empty())
    {
        // successfully!
        for (long i = 0; i <= length; i++)
        {
            if (brackets[arrInput[i]] == 2)
                ans++;
            // printf("%ld\n%s\n", ans, arrInput);
            
            
        }
        cout << ans << endl;
        cout << arrInput << endl;
    }
    else
    {
        // cout << s.top();
        // not completely correct => need to get sub correct sequence.
        long start_idx, end_idx;
        long res_start, res_end;
        long ans_temp;
        s.push(length);
        // cout << s.size() << "size of s" << endl;
        // cout << s.top();
        while (s.size() != 1)
        {
            end_idx = s.top() - 1;
            s.pop();
            start_idx = s.top() + 1;
            ans_temp = 0;
            // cout << "st : " << start_idx << " end: " << end_idx <<endl;
            for (long i = start_idx; i <= end_idx; i++)
            {
                if (brackets[arrInput[i]] == 2)
                    ans_temp++;
            }
            // cout << ans_temp << " ??? " << ans;
            if (ans_temp > ans)
            {
                ans = ans_temp;
                res_start = start_idx;
                res_end = end_idx;
            }
        }

        start_idx = 0;
        end_idx = s.top() - 1;
        // cout << start_idx << ", " << end_idx;
        ans_temp = 0;
        for (long i = start_idx; i <= end_idx; i++)
        {
            if (brackets[arrInput[i]] == 2)
                ans_temp++;
        }

        if (ans_temp > ans)
        {
            ans = ans_temp;
            res_start = start_idx;
            res_end = end_idx;
        }

        if(ans) {
            cout << ans << endl;
            for(long i = res_start; i<= res_end; i++) 
                printf("%c", arrInput[i]);
                printf("\n");
            
        }
        else {
            cout << 0;
        }
    }
}