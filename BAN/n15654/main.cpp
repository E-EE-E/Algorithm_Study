#include <iostream>
#include <algorithm>
// 인덱스 수열이 곧 주어진 수의 수열

using namespace std;
bool c[10]; int a[10];
int num[10];
void go(int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout<<num[a[i]]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 0; i<n; ++i)
    {
        if(c[i]) continue;;
        c[i] = true;
        a[index] = i;
        go(index+1, n, m);
        c[i] = false;
    }
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; ++i) {
        cin>>num[i];
    }
    sort(num, num+n);
    go(0, n, m);
    return 0;
}
