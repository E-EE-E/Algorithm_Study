#include <iostream>
#include <vector>
using namespace std;
typedef long long  LL;

int n, a[101];
LL d[101][21];
int main() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>> a[i];
    }
    d[1][a[1]] = 1;
    for(int i = 2; i < n; ++i) {
        for(int j = 0; j <= 20; ++j) {
            if(d[i-1][j] == 0) continue; //이전까지 j를 만든 경우만
            //if(j-a[i] < 0 || j+a[i] > 20) continue; // 만들 수가 0~20 범위 벗어나지않게
            if(j+a[i]<=20)
                d[i][j+a[i]] += d[i-1][j];
            if(j-a[i] >= 0)
                d[i][j-a[i]] += d[i-1][j];
        }
    }
    cout<<d[n-1][a[n]]<<'\n';
    return 0;
}
