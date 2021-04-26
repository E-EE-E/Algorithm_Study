//피보나치 풀이 2 - 동적계획법, 메모라이제이션 O(N)
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> a;
long long go(int n) {
    if(n < 2)
        return n;
    
    if(a[n] != -1)
        return a[n];
    
    a[n] = go(n-1) + go(n-2);
    
    return a[n];
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    
    int n;
    cin>>n;
    for(int i = 0; i <=n; ++i) {
        a.push_back(-1);
    }
    cout<< go(n) <<'\n';
    return 0;
}
