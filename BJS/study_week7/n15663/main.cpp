#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[10], ans[10];
bool check[10];
void go(int index) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int prev = 0;
    for(int i = 0; i < n; ++i) {
        if(check[i]) continue; //중복선택 제거
        if(prev == a[i]) continue; //중복케이스 제거
        prev = a[i];
        check[i] = true;
        ans[index] = a[i];
        go(index + 1);
        check[i] = false;
    }
}
int main() {
    cin>>n>>m;
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a, a+n);
    go(0);
    return 0;
}
