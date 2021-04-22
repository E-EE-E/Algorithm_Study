//두번째 풀이
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int ans;
void go(int sum, int n) {
    if(sum > n) return;
    if(sum == n) {
        ans += 1;
        return;
    }
    
    for(int i = 1; i <= 3; ++i) {
        go(sum +i, n);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 0; t < tc; ++t) {
        ans = 0;
        int n;
        cin>> n;
        go(0, n);
        cout<< ans;
        cout<<'\n';
    }
    return 0;
}
//첫번째 풀이
//#include <iostream>
//// 재귀이용
//// sum으로 재귀종료조건
//
//using namespace std;
//
//int ans = 0;
//void go(int n, int sum) {
//    for(int i = 1; i <=3; ++i) {
//        if(n==sum+i) {
//            ++ans;
//            return;
//        } else if(n > sum+i) {
//            go(n, sum+i);
//        }
//    }
//}
//
//int main(int argc, const char * argv[]) {
//
//    int t;
//    cin>>t;
//
//    while(t--) {
//        int n;
//        cin>>n;
//
//        go(n, 0);
//
//        cout<<ans<<'\n';
//        ans = 0;
//    }
//
//    return 0;
//}
