#include<iostream>
using namespace std;

void abbreviation(string input_str) {
    int i;
    if( (i = input_str.length()) <= 10) {
        cout << input_str;
    }
    else {
        cout << input_str[0];
        cout << i-2;
        cout << input_str[i-1];
    }
}

int main()
{
    // string arr[10];
    int n;
    string tmp;
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> tmp;
        abbreviation(tmp);
        cout << '\n';
    }

    

}