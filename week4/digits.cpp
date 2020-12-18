#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 20;
typedef unsigned long long ull;
int ret = 0;
int N;
int c[8];
int M = 7;
bool visited[10];
void input()
{
    cin >> N;
}

bool checksum(){
    // cout << 100*c[1] + 10*c[2] + c[3] - (100*c[7]+62) + 1000*c[4]+100*c[5]+10*c[6]+c[3] << endl;
    if (100*c[1] + 10*c[2] + c[3] - (100*c[7]+62) + 1000*c[4]+100*c[5]+10*c[6]+c[3] == N)
    return true;
    return false;
}
// bool check(int k)
// {
//     for (int i = 1; i <= N; i++)
//     {
//         if (a[i][k] == 1)
//         {
            
//             if (x[i] >= v)
//             return false;
//             // cout << "nho hon: " << "(" << i << ", " << k << endl;
//             // cout << x[i] << "v: " << v << endl;
//             // for(int j = 1; j <= k; j++)
//             // cout << x[j] << ", ";
//             // cout << endl;
//         }
//     }

//     for (int i = 1; i <= N; i++)
//     {
//         if (a[k][i] == 1)
//         {
            
//             if (x[i] <= v && x[i] != 0)
//                 return false;
//             //     cout << "lon hon: " << "(" << i << ", " << k << endl;
//             // cout << x[i] << "v: " << v << endl;
//             // for(int j = 1; j <= k; j++)
//             // cout << x[j] << ", ";
//             // cout << endl;
//         }
//     }


//     return true;
// }

void solution()
{
    // cout << "solution: " << endl;
    // for (int i = 1; i <= N; i++)
    // cout << x[i] << ", ";
    // cout << endl;
    // int max_l = -1e6;
    //  for (int i = 1; i <= M; i++)
    //  if(load[i] > max_l)
    //  max_l = load[i];
    // //  cout << load[i] << ", ";
    // //  cout << endl;
    // // int max_l = *std::max_element(load, load + M);

    // if (max_l < retval)
    //     retval = max_l;
    if(checksum())
    ret += 1;

}

void TRY(int k)
{
    for(int i = 1; i<= 9; i++) {
        if(!visited[i]) {
            c[k] = i;
            visited[i] = true;
            if(k == M) solution();
            else {
                TRY(k+1);
            }
            visited[i] = false;
        }
    }
}

void solve()
{
    // for (int i = 1; i <= M; i++)
    //     load[i] = 0;
    TRY(1);
    cout << ret << endl;
}

int main()
{
    input();
    solve();
    return 0;
}