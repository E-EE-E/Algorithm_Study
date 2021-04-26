/*
 풀이 1
 중복연산 과정 없애기
 i = a, j = b 이면 sum = A[a] + A[a+1] + ... + A[b]
 i = a, j = b+1 이면 sum = A[a] + A[a+1] + ... + A[b] + A[b+1]
 파란 부분이 중복되는 부분이므로 A[b+1]만 이어서 더해주면 됨

 시간 초과 안남! - 성공 (시간 : 40ms)
 시간복잡도 : O(N^2)
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> &a, int n, int m) {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = i; j < n; ++j) {
            sum += a[j];
            if(sum == m) ans += 1;
        }
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) {
        int n, m;
        cin>>n>>m;
        vector<int> a;
        for(int i = 0; i < n; ++i) {
            int x;
            cin>>x;
            a.push_back(x);
        }
        cout<<'#'<<t<<' ';
        cout<<solution(a,n, m);
        cout<<'\n';
    }
    return 0;
}
