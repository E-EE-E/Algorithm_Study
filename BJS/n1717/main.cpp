/*Union 시 부모의 부모를 업데이트 해야한다 주의*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int p[1000001];

int Find(int a) {
    if(p[a] == a)
        return a;
    else
        return p[a] = Find(p[a]);
}
bool UnionFind(int op, int a, int b) {
    int ua = Find(a);
    int ub = Find(b);
    if(ua == ub)
        return 1;
    if(op == 0) {
        if(ua < ub) {
            p[ub] = ua; //p[b] = ua;(X)
        } else {
            p[ua] = ub; //p[a] = ub;(X)
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin>> n>> m;
    for(int i = 0; i <= n; ++i) {
        p[i] = i;
    }
    for(int i = 0; i < m; ++i) {
        int op, a, b;
        cin>>op>>a>>b;
        bool ans = UnionFind(op, a, b);
        if(op == 1)
            cout<< (ans ? "YES":"NO") <<'\n';
    }
    
    return 0;
}
