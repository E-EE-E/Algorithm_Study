#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long go(int n, vector<long long> &memo) {
    if(memo[n] != -1)
        return memo[n];
    
    if(n < 2) {
        memo[n] = n;
    } else {
        memo[n] = go(n-1, memo) + go(n-2, memo);
    }
    
    return memo[n];
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc; cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        int n; cin>>n;
        vector<long long> a(n+1, -1);
        cout<<'#'<<t<<' ';
        cout<<go(n, a)<<'\n';
    }
    return 0;
}
