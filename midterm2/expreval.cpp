#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#define ull unsigned long long
using namespace std;
const ull max_length = 200003;
ull prio[4];
stack<ull> ops;
stack<ull> num;
stack<ull> ret;
ull w;
ull N;
ull cal(ull a, ull b, ull op)
{
    switch(op) {
        case 0:
        // break;
        return a - b;
        case 1:
        // break;
        return (ull)(a) + b;
        case 2:
        // break;
        return (ull)(a) * b;
    }
    return 0;
}

int main() {
    // 0: -, 1:+, 2: *
    prio[0] = 1;

    prio[1]= 1;
    prio[2] = 2;
    ull cur_op;
    ull next_op;
    ull num1, num2;
    cin >> N;
    if(N == 1) {
        ull m;
        cin >> m;
        cout << m << endl;
        return 0;
    }
    else {
    ull tmp;
    for(ull i = 1; i<=N; i++) {
        cin >> tmp;
        num.push(tmp); // push number
    }
    for(ull i = 1; i<=N-1; i++) {
        cin >> tmp;
        ops.push(tmp); // ops

    }
    }


    // while(!num.empty()) {
        cur_op = ops.top();
        ops.pop();
        next_op = ops.top();
        ops.pop();
        num2 = num.top();
        num.pop();
        num1 = num.top();
        num.pop();
        while(!num.empty()) {
            if(next_op == -1)
            break;
            // cout << cur_op << ", " << next_op << endl;
            // printf("w: %d n1: %d n2: %d op: %d next: %d\n", w ,num1, num2, cur_op, next_op);
        if(prio[next_op] < prio[cur_op] || next_op == cur_op) {
            // ull tmp_ret = cal(num1, num2, cur_op);
            // num.push(tmp_ret);
            // cout << "here2..." << endl;
            num2 = cal(num1, num2, cur_op);
            num1 = num.top();
            num.pop();
            cur_op = next_op;
            if(ops.empty()) {
                next_op = -1;
            }
            else {
            next_op = ops.top();
            ops.pop();
            }
        }
        else {
            // ret.push(num2);
            // cout << "here1.." << endl;
            w = num.top();
            num.pop();
            num1 = cal(w, num1, next_op);
            if(ops.empty()) {
                next_op = -1;
            }
            else {
            next_op = ops.top();
            ops.pop();
            }
           
            // num2 = num1;
            // num2 = num1;
            // num1 = num.top();
            // num.pop();
            // ret.push(cal(num1, num2, next_op));
            // next_op = ops.top();
            // ops.pop();
            // prullf("w: %d n1: %d n2: %d op: %d next: %d\n", w ,num1, num2, cur_op, next_op);

        }
        // prullf("w: %d n1: %d n2: %d op: %d next: %d\n", w ,num1, num2, cur_op, next_op);
        // printf("w: %lld n1: %lld n2: %lld op: %lld next: %lld\n", w ,num1, num2, cur_op, next_op);
    }
    
    cout << cal(num1, num2, cur_op) << endl;
    // cout << num1-num2 << endl;
}