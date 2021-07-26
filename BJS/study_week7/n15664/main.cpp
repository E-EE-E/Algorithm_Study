#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> ans;
bool check[10];
void go(int index, int start, vector<int> &a) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int prev = 0;
    for(int i = start + 1; i < n; ++i) { // 비내림차순
        if(prev == a[i]) continue; //중복케이스 제거
        prev = a[i];
        ans.push_back(a[i]);
        go(index + 1, i, a);
        ans.pop_back();
    }
}
int main() {
    cin>>n>>m;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    go(0, -1, a);
    return 0;
}
