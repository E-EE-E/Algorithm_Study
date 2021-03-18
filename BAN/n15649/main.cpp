#include <iostream>
// bool 배열로 중복방지
// 재귀 이용한 수열 생성

using namespace std;

bool c[10]; int a[10];
void go (int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout<<a[i];
            if(i != m-1) cout<<' ';
        }
        cout<<'\n';
        return;
    }
    for (int i = 1; i<=n; ++i) {
        if(c[i] == true) continue;
        c[i] = true;
        a[index] = i;
        go(index+1, n, m);
        c[i] = false;
    }
}
int main(int argc, const char * argv[]) {
    
    int n, m;
    cin >> n >> m;
    
    go(0, n, m);
        
    return 0;
}
