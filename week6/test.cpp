#include <iostream>
using namespace std;
 
const int MAX = 100005;
 
int Answer;             // Lưu kết quả
int N;                  // Lưu số lượng ngăn trong chuồng
int C;                  // Lưu số lượng con bò
int X[MAX];             // Lưu toạ độ các ngăn
int Left, Right;
 
void Merge(int *a, int left, int m, int right)
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
 
void MergeSort(int *a, int left, int right)
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
 
bool IsValid()
{
    // Ta sẽ xếp thử các con bò vào các ngăn, bắt đầu từ ngăn đầu tiên
    int pos = 0, cnt = 1, delta = 0, i = 1;
 
    while(i < N)
    {
        // Khoảng cách giữa ngăn thứ 'i' và ngăn 'pos'
        delta = X[i] - X[pos];
 
        // Vì Answer ở đây là khoảng cách ngắn nhất giữa các chuồng
        // Nên buộc delta phải lớn hơn Answer thì ta mới xếp được
        if(delta >= Answer)
        {
            pos = i;
            cnt++;
        }
        
        i++;
 
        // Nếu xếp được hết C con bò thì thoả mãn,
        // ngược lại là không thể xếp C con bò vào N ngăn mà khoảng cách ngắn nhất 
        // giữa hai chuồng là Answer
        if(cnt == C) return true;
    }
    
    return false;
}
 
int main()
{
    ios::sync_with_stdio(false);
    
    // Comment dòng này trước khi submit
    freopen("input.txt","r",stdin);
 
    int T;
    cin >> T;
 
    for(int tc = 0; tc < T; tc++)
    {
        // Input
        Answer = 0;
 
        cin >> N >> C;
        for(int i = 0; i < N; i++)
            cin >> X[i];
 
        // Implementing code below
        MergeSort(X, 0, N-1);
 
        // Binary search
        Left  = 1;
        Right = X[N-1] - X[0];
 
        while (Left < Right - 1)
        {
            // Answer chính là khoảng cách ngắn nhất đang xét
            // giữa các ngăn
            Answer = (Left + Right) / 2;
 
            if (IsValid()) Left = Answer;
            else Right = Answer - 1;
        }
 
        // Kiểm tra xem là tại Left hoặc Right thoả mãn thì lấy
        Answer = Right;
        if(!IsValid()) Answer = Left;
 
        // ouput
        cout << Answer << endl;
    }
 
    return 0;
}