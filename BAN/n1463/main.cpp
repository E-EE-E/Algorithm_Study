//Bottom-up
#include <cstdio>
#include <iostream>

using namespace std;
int d[1000001];

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        int n;
        cin>>n;
        d[1] = 0;
        for(int i=2; i <=n; ++i) {
            d[i] = d[i-1] + 1;
            if(i%2 == 0 && d[i] > d[i/2] + 1) {
                d[i] = d[i/2] + 1;
            }
            if(i%3 == 0 && d[i] > d[i/3] + 1) {
                d[i] = d[i/3] + 1;
            }
        }
        cout<<'#'<<t<<' ';
        cout<<d[n]<<'\n';
    }
    return 0;
}
