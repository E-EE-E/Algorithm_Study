#include <iostream>
// 풀이 1 - 순서
// 위치(index)에 start~n 중 하나 선택
// 오름차순이므로 선택한 수(i) 다음 위치(index+1)에는 i+1~n

using namespace std;

int a[10];
void go(int index, int start, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout<<a[i];
            if(i != m-1) cout<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = start; i <= n; ++i) {
        a[index] = i;
        go(index+1, i+1, n, m);
    }
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin >>n>>m;
    go(0, 1, n, m);
    
    return 0;
}
