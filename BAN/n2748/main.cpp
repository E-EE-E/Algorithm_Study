//피보나치 풀이 3 - 반복문 사용
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    
    int n;
    cin>>n;
    long long a[91] = {0,1,};
    for(int i = 2; i <=n; ++i) {
        a[i] = a[i-1] + a[i-2];
    }
    cout<< a[n] <<'\n';
    return 0;
}
