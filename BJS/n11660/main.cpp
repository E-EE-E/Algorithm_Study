#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

int main(int argc, const char * argv[]) {
    int n, m;

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    vector<vector<LL>> dp(n+1, vector<LL>(n+1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
        }
    }
    cout<<'\n';
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    int x1, y1, x2, y2;
    while(m--) {
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]<<'\n';
    }
    return 0;
}
