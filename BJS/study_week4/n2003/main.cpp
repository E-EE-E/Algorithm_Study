#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc; cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        int n, m;
        cin>>n>>m;
        vector<int> a(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        
        int left, right;
        left = right = 0;
        int sum = a[0];
        int ans = 0;
        while(left <= right && right < n) {
            if(sum <= m) {
                if(sum == m) ans += 1;
                sum += a[++right];
            } else {
                sum -= a[left++];
                if(left > right && left < n) {//right==left일때 sum > m이면
                    right = left;             //a[right]는 m보다 큰 값이니 패스~
                    sum = a[right];
                }
            }
        }
        cout<<'#'<<t<<' ';
        cout<<ans<<'\n';
    }
    return 0;
}
