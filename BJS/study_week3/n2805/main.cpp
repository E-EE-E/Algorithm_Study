// 풀이방법 - 이분탐색
// first <= last 를 만족하기 위해
// first = mid + 1, last = mid -1 (O)
// 주의 (first = mid, last = mid (X))
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc; cin>>tc;
    for(int t = 1; t<= tc; ++t) {
        int n, m;
        cin>>n>>m;
        vector<int> tree(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>tree[i];
        }
        long long max = -1;
        long long first = 0;
        long long last = *max_element(tree.begin(), tree.end());
        while(first <= last) {
            long long sum = 0;
            long long mid = (last + first)/2;
            for(int i = 0; i < n; ++i) {
                if(tree[i] >= mid) {
                    sum += tree[i] - mid;
                }
            }
            if(sum >= m) {
                if(max == -1 || max < mid) {
                    max = mid;
                }
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        cout<<'#'<<t<<' ';
        cout<<max<<'\n';
    }
    return 0;
}
