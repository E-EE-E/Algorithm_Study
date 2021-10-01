//dp[n][(0,1,2)] = dp[n-1][(0,1,2)] + cost(0,1,2)
//이전 layer에서 최소값에 비용을 더해가면 최소비용이다
#include <iostream>
#include <vector>
using namespace std;

int dp[1002][3]; //i==0->>dp[0][color] = 0
int main() {
    int n, r, g, b;
    cin>>n;
    for(int i = 1; i <= n; ++i) { //1~N
        cin>>r>>g>>b;
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + b;
    }
    int ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
    cout<<ans<<'\n';
}

//오답코드
//시간복잡도 = 3^1000  -> dp이용하자
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n;
//int ans = -1;
//int res[1001];
//void go(vector<vector<int>> &a, int index, int sum) {
//    if(index < 0) {
//        if(ans == -1 || sum < ans) {
//            ans = sum;
//        }
//        return;
//    }
//    if(sum > 1000) return;
//
//    for(int i = 0; i < 3; ++i) {
//        if(index>=0&&index<n-1&&res[index+1] == i) continue;
//        res[index] = i;
//        go(a, index-1, sum+a[index][i]);
//        res[index] = -1;
//    }
//}
//int main(int argc, const char * argv[]) {
//    cin>>n;
//    vector<vector<int>> a(n, vector<int>(3, 0));
//    for(int i = 0; i < n; ++i) {
//        res[i] = -1;
//        int r,g,b;
//        cin>>r>>g>>b;
//        a[i][0] = r;
//        a[i][1] = g;
//        a[i][2] = b;
//    }
//
//    go(a, n-1, 0);
//
//    cout<<ans<<'\n';
//
//    return 0;
//}
