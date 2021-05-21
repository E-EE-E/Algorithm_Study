#include <cstdio>
#include <iostream>

using namespace std;
int d[1000001];
int go(int n) {
    if(n == 1) {
        return 0;
    }
    if(d[n] > 0) {
        return d[n];
    }
    d[n] = go(n-1) + 1;
    if(n%2 == 0) {
        int temp = go(n/2) + 1;
        if(d[n] > temp) {
            d[n] = temp;
        }
    }
    if(n%3 == 0) {
        int temp = go(n/3) + 1;
        if(d[n] > temp) {
            d[n] = temp;
        }
    }
    return d[n];
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i) {
        int n;
        cin>>n;
        cout<<'#'<<i<<' ';
        cout<<go(n)<<'\n';
    }
    return 0;
}
