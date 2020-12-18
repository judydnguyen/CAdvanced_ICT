#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;

char open[] = {'[','{','('};
char close[] = {']','}',')'};
map<char, char> mappingParenthese;

int findInArr(char arr[], char key, int leng) {
    for (int i = 0; i< leng; i ++) {
        if(key == arr[i]) {
            return 1;
        }
    }

return 0;
}

int checkParenthese(string inputStr) {
    for(int i = 0; i<3; i++)
    {
        mappingParenthese.insert(pair<char, char>(close[i], open[i]));
    }
    stack<char> parentheseStack;
    int length = inputStr.length();
    int i = 0;
    char temp = 0;
    while (i < length) {
        temp = inputStr[i];
        // printf("\ncurrent temp: %c.", temp);
        if(findInArr(open, temp, 3))
        {
            parentheseStack.push(temp);
            
                // printf("begin: %c\t", parentheseStack.top());
            
        }
        if(findInArr(close, temp, 3))
        {
            // printf("end: %c\t", parentheseStack.top());
            if (parentheseStack.empty())
            {
                return 0;
            }
            else
            {
                if(mappingParenthese[temp] != parentheseStack.top())
                {
                    return 0;
                }
                parentheseStack.pop();
            }
        }
        i += 1;
    }
    if (parentheseStack.empty()) {
        return 1;
    }
    return 0;
}

int main()
{
    string currentString = "\0";
    int lineNum;
    cin >> lineNum;
    for(int  i = 0; i< lineNum; i++)
    {
        cin >> currentString;
        printf("%d\n",checkParenthese(currentString));
    }

    return 0;
}