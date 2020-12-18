#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_LENGTH 100005
typedef unsigned long long ull;

int N,C;
int pos[MAX_LENGTH];
int retval;
// ull l, r;
int answer;
// ull m;
void Merge(ull *a, int left, int m, int right)
{
    int *temp = new int[right-left+1];
    int k = 0, i = left, j = m + 1;
 
    while(i <= m && j <= right)
    {
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
 
    while(i <= m) temp[k++] = a[i++];
 
    while(j <= right) temp[k++] = a[j++];
 
    for(int i = 0; i < k; i++)
        a[i + left] = temp[i];
 
    delete[] temp;
}
 
void MergeSort(ull *a, int left, int right)
{
    int m;
    if(left < right)
    {
        m = (left + right) / 2;
        MergeSort(a, left, m);
        MergeSort(a, m + 1, left);
        Merge(a, left, m, right);
    }
}

void input() {
    cin >> N >> C;
    for(int i = 0; i< N; i++) {
        cin >> pos[i];
    }
    sort(pos, pos + N);
}
bool checkValid(int ans, int arr[]) {
    int cows = 1, cur = arr[0];
    for(int i = 1; i< N; i++) {
        if(pos[i] - cur >= ans) {
            cur = arr[i];
            cows ++;
            if(cows == C)
            return true;
        }
    }
    return false;
}

bool isValid() {
    // start from the first barn.
    // int cur = 0, cnt = 1, delta = 0, i = 1;
    // while(i<N) {
    //     delta = pos[i] - pos[cur];
    //     if(delta >= answer) {
    //         cur = i;
    //         cnt += 1;
    //     }
    //     i ++;
    //     if(cnt == C) return true;
    // }
    //  // all cows is arranged.
    // return false;
    int cows = 1, cur = pos[0];
    for(int i = 1; i< N; i++) {
        if(pos[i] - cur >= answer) {
            cur = pos[i];
            cows ++;
            if(cows == C)
            return true;
        }
    }
    return false;
}
void bs(int arr[]) {
    int l = 0, r = pos[N-1], m = -1;

    while(r > l) {
        // cout << l << ", " << r << endl;
        answer = (l + r) / 2;
        // cout << "ans: " << answer << endl;
        if(checkValid(answer, arr)) 
        {
            // cout << "ans: " << answer << endl;
            // cout << " m: " << m << endl;
            if(answer > m) {
                // cout << "ok..." << endl;
                m = answer;
            }
            l = answer +1;
        }    
        else r = answer;
        // cout << " m: " << m << endl;
    }
    //  answer = r;
    //  if(!isValid()) answer = l;
     cout << m << endl;
}
void solve() {
    // answer = 0;
    // input();
    // MergeSort(pos, 1, N);
    // sort(pos, pos + N);

    // Binary search
    // l = 0;
    // r = pos[N-1];
    // m = -1;
    // cout << l << ", " << r << endl;
    int l = 0, r = pos[N-1], m = -1;

    while(r > l) {
        // cout << l << ", " << r << endl;
        answer = (l + r) / 2;
        if(isValid()) 
        {
            if(answer > m) {
                m = answer;
            }
            l = answer +1;
        }
        else r = answer;
    }
    //  answer = r;
    //  if(!isValid()) answer = l;
     cout << m << endl;
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--)
    {
        // scanf("%d %d",&N,&C);
        cin >> N >> C;
        // int pos[N];
        for (int i=0; i<N; i++)
            scanf("%d",&pos[i]);
        sort(pos,pos+N);
        //cout<<" dfsa \n";
        bs(pos);
        // printf("%d\n",k);
    }
    return 0;
}