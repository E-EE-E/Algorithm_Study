// 풀이방법 - 투포인터
// sum == s일 때, left를 옮기면 sum < s이므로, right + 1 해야 함
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc; cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        int n, s;
        cin>>n>>s;
        vector<int> a(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        int min = 0;
        
        int left, right;
        left = right = 0;
        int sum = a[0];
        while(left <= right && right < n) {
            if(sum > s) {
                if(min == 0 || min > (right - left+1)) {
                    min = (right - left)+1;
                }
                sum -= a[left];
                left += 1;
            } else {
                if(sum == s) {
                    if(min == 0 || min > (right - left)) {
                        min = (right - left)+1;
                    }
                }
                right += 1;
                if(right < n)
                    sum += a[right];
            }
        }
        
        cout<<'#'<<t<<' ';
        cout<<min<<'\n';
    }
    return 0;
}
