// 풀이방법 - 수학적 수식으로 z+1을 만드는 최소횟수 a 찾기
// y+a 와 동시에 x+a 가 됨 주의
// a 계산식 중 x*z처리시 int범위 초과 주의
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc; cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        long long x, y;
        cin>>x>>y;
        long long ans = 0;
        int z = (int)(100*y/x);
        if(z >= 99)
            ans = -1;
        else {
            long long a = (z*x + x -100*y);
            long long b = (99.0-z);
            ans = (a%b == 0)? a / b : a/b +1;
        }
        cout<<'#'<<t<<' ';
        cout<<ans<<'\n';
    }
    return 0;
}
