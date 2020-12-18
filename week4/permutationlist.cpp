#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 10000000
using namespace std;
typedef unsigned long long ull;
int n,m;
stack<int> s1, s2;
int perm[MAX];
bool addSubStack = true;
int pivot;
int min_larger = MAX;
int next_ind = -1;
int trace = 1;
void input()
{
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int tmp;
        cin >> tmp;
        perm[i] = tmp;
        // s2.push(tmp);
        // if(s1.empty() || s1.top() < tmp) {

        //     s1.push(tmp);
        //     if(min_larger > tmp) {
        //         min_larger = tmp;
        //     }

        // }
        // else {
        //     pivot = i; // index of pivot, elem need to be replaced.
        //     break;
        // }

        i += 1;
    }

    // int cont_idx = i - 1;
    // while(cont_idx >= 1) {
    //     cin >> perm[cont_idx];
    //     cont_idx -=1;
    // }
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i=1; i <= size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void solve()
{
    int j = n;
    min_larger = MAX;
    while (j >= 1)
    {
        int temp;
        temp = perm[j];
        if (s1.empty() || s1.top() < temp)
        {
            s1.push(temp);
            // if (min_larger > temp)
            // {
            //     min_larger = temp;
            //     next_ind = j;
            // }
        }
        else {
            break;
        }
        j -= 1;

        // exchange the position of the pivot and next candidate.
       


    }
    //  cout << perm[j] << endl;
        // cout << perm[next_ind] << endl;
        if(j != 0) {
        int t = perm[j];
        perm[j] = perm[next_ind];
        perm[next_ind] = t;
        // quickSort(perm, j+1, n);
        int temp;
        int r = j + 1; 
        int s = n;
        while (r < s){//4. Lật ngược đoạn từ aj+1 đến an. 
   temp = perm[r]; 
   perm[r] = perm[s];
   perm[s] = temp;
   r++;
   s--;
  }
        printArray(perm, n);
        }
        else {
            cout << -1;
        }
}
void gen() {
    cin >> n >> m;
    for(int i = 1; i<= n ; i++) {
        perm[i] = i;
    }
}
int nextPermutation() {
    stack<int> s3;
    int j = n;
    while (j >= 1)
    {
        if(perm[j] > perm[j-1])
        break;
        // int temp;
        // temp = perm[j];
        // if (q1.empty() ||  < temp)
        // {
        //     s1.push(temp);
        //     if (min_larger > temp)
        //     {
        //         min_larger = temp;
        //         next_ind = j;
        //     }
        // }
        // else {
        //     break;
        // }
        j -= 1;

        // exchange the position of the pivot and next candidate.
       


    }
    // cout << j;
    j -= 1;
    //  cout << perm[j] << endl;
        // cout << perm[next_ind] << endl;
        if(j != 0) {
            int k = n; 
            while(perm[j] > perm[k]) k -= 1;
            next_ind = k;
            // cout << endl << next_ind <<endl;
        int t = perm[j];
        perm[j] = perm[next_ind];
        perm[next_ind] = t;
        // quickSort(perm, j+1, n);
        int temp;
        int r = j + 1; 
        int s = n;
        while (r < s){//4. Lật ngược đoạn từ aj+1 đến an. 
   temp = perm[r]; 
   perm[r] = perm[s];
   perm[s] = temp;
   r++;
   s--;
  }
        // printArray(perm, n);
        return 1;
        }
        else {
           return -1;
        }
}

int main() {
    gen();
    // quickSort(perm, 5, n);
    while(1) {
        trace += 1;
        if(nextPermutation() == 1) {
            if(trace == m) {
            printArray(perm, n);
            break;
            }
        }
        else {
            cout << -1;
            break;
        }
        
    }
    // printArray(perm, n);
    // solve();
}