/*
 풀이  2 - 투포인터 (two pointer) 사용

 가장 효율적 - 성공 (시간 : 4ms)
 시간복잡도 : O(N)
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> &a, int n, int m) {
    int left, right;
    left = right = 0;
    int ans = 0;
    int sum = a[0]; // 주의 (두 점이 같은 곳을 가리킴)
    while(left <= right && right <n) {
        if(sum < m) {
            right += 1;
            sum += a[right];
        } else if(sum == m) {
            ans += 1;
            right += 1;
            sum += a[right];
        } else if(sum > m) {
            sum -= a[left];
            left += 1;
            if(left > right && left < n) {
                right = left;
                sum = a[left];
            }
        }
    }
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        int n, m;
        cin>>n>>m;
        vector<int> a;
        for(int i = 0; i < n; ++i) {
            int x; cin>>x;
            a.push_back(x);
        }
        cout<<'#'<<t<<' ';
        cout<<solution(a, n, m)<<'\n';
    }
    return 0;
}
