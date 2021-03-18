#include <iostream>
// 풀이 2 - 선택
// 오름차순으로 i를 키우며 선택할지 안할지로 수열만듬

using namespace std;

int a[10];
void go(int i, int selected, int n, int m) {
    if(selected == m) {
        for(int i = 0; i < m; ++i) {
            cout<<a[i];
            if(i != m-1) cout<<' ';
        }
        cout<<'\n';
        return;
    }
    if(i>n) return;
    a[selected] = i;
    go(i+1, selected+1, n, m);
    a[selected] = 0;
    go(i+1, selected, n, m);
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin >>n>>m;
    go(1, 0, n, m);
    
    return 0;
}
