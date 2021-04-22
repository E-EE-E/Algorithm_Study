#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int num[11];
int op[4];
int ops[10];
long long ans_max;
long long ans_min;
long long calc(int n) {
    long long ans = num[0];
    for(int i = 1; i < n; ++i) {
        if(ops[i-1] == 0) {
            ans += num[i];
        } else if(ops[i-1] == 1) {
            ans -= num[i];
        } else if(ops[i-1] == 2) {
            ans *= num[i];
        } else {
            ans /= num[i];
        }
    }
    return ans;
}
void go(int index, int n) {
    if(index == n-1) {
        long long temp =calc(n);
        if(ans_max < temp) ans_max = temp;
        if(ans_min > temp) ans_min = temp;
        return;
    }
    
    for(int i = 0; i < 4; ++i) {
        if(op[i] == 0) continue;
        op[i] -=1;
        ops[index] = i;
        go(index +1, n);
        op[i] += 1;
    }
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        int n;
        cin>>n;
        ans_min = 34359738367;
        ans_max = -34359738367;
        memset(num, 0, sizeof(num));
        memset(op, 0, sizeof(op));
        memset(ops, 0, sizeof(ops));
        for(int i=0; i< n; ++i) {
            cin>> num[i];
        }
        for(int i=0; i < 4; ++i) {
            cin>> op[i];
        }
        
        cout<<'#'<<t<<'\n';
        go(0, n);
        cout<<ans_max<<'\n';
        cout<<ans_min<<'\n';
        cout<<'\n';
    }
    return 0;
}
