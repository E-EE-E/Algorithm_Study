#include <iostream>
// 풀이 1 - 순서
// 비내림차순(중복+오름차순)

using namespace std;
bool c[10]; int a[10];
void go(int index, int start, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout<<a[i]<<' ';
        }
        cout<<'\n';
        return ;
    }
    for(int i = start; i <= n; ++i) {
        a[index] = i;
        go(index+1, i, n, m);   //중복가능하므로 i~n(o), i+1~n(x)
    }
}
int main(int argc, const char * argv[]) {
    
    int n, m;
    cin>>n>>m;
    
    go(0, 1, n, m);
    
    return 0;
}
