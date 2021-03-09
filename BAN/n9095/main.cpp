#include <iostream>
// 재귀이용
// sum으로 재귀종료조건

using namespace std;

int ans = 0;
void go(int n, int sum) {
    for(int i = 1; i <=3; ++i) {
        if(n==sum+i) {
            ++ans;
            return;
        } else if(n > sum+i) {
            go(n, sum+i);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        go(n, 0);
 
        cout<<ans<<'\n';
        ans = 0;
    }
    
    return 0;
}
