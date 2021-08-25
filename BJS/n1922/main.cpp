#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pii;
vector<int> p;
int Find(int a) {
    if (p[a] == a) return a;
    else return p[a] = Find(p[a]);
}
bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a == b)
        return 0;
    if(a < b)
        p[b] = a;
    else
        p[a] = b;
    return 1;
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin>>n>>m;
    for(int i = 0; i <= n; ++i) {
        p.push_back(i);
    }
    vector<pii> edge(m);
    for(int i = 0; i < m; ++i) {
        cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
    }
    sort(edge.begin(), edge.end());
    //union하면 가중치 더함
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < edge.size(); ++i) {
        if(cnt > n-1) break;
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        if(Union(a, b)) {
            ans += edge[i].first;
            cnt++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
