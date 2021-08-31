#include <iostream>
#include <vector>
using namespace std;

int go(int i, int j, vector<pair<int, int>> &a, vector<vector<int>> &dp) {
    if(i == j) return dp[i][j]=0;
    if(i+1 == j) return dp[i][j] = a[i].first*a[i].second*a[j].second;

    if(dp[i][j] != -1) return dp[i][j];

    for(int k = i; k < j; ++k) {
        int temp = go(i, k, a, dp) + go(k+1, j, a, dp) + a[i].first*a[k].second*a[j].second;
        if(dp[i][j] > temp || dp[i][j] == -1)
            dp[i][j] = temp;
    }
    
    return dp[i][j];
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<pair<int, int>> a(n, make_pair(0, 0));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i = 0; i < n; ++i) {
        cin>>a[i].first>>a[i].second;
    }
    cout<<go(0, n-1, a, dp)<<'\n';
    return 0;
}
