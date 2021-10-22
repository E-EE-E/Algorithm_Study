//가장큰 제곱수를 찾아빼는 방법 ->failed
//=>반례 : 12 -> 3^2 + 1+1+1 = 4 (x) / 2^2+2^2+2^2 = 3 (o)
/*
#include <iostream>
#include <vector>
using namespace std;

int s[400+1];
int main(int argc, const char * argv[]) {
    for(int i = 1; i*i <= 100000; ++i) {
        s[i] = i*i;
    }
    int n;
    cin>>n;
    int ans = 0;
    while(n>0) {
        int t = 0;
        for(int i = 1; i*i <= 100000; ++i) {
            if(s[i] <= n) {
                t = s[i];
            }
            else
                break;
        }
        n -= t;
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
*/
//dp 이용
//dp[i] : i의 최소제곱수항
#include <iostream>
#include <vector>
using namespace std;

int dp[100001];
int main() {
    int n; cin>>n;
    for(int i = 1; i <= n; ++i) {
        dp[i] = i;
        for(int j = 1; j*j <= i; ++j) {
            dp[i] = min(dp[i], dp[i-j*j] + 1); //+1의 의미 : dp[j*j] = 1이므로
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
