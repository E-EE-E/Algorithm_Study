#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
bool cmp(const tuple<int, int, int> &u, const tuple<int, int, int> &v) {
    return get<0>(u) < get<0>(v);
}
bool cmp2(const tuple<int, int, int> &u, const tuple<int, int, int> &v) {
    return get<1>(u) < get<1>(v);
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin>>n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    cin>>m;
    vector<tuple<int, int, int>> b(m, make_tuple(0, 0, 0));
    for(int i = 0; i < m; ++i) {
        cin>> get<0>(b[i]);
        get<1>(b[i]) = i+1;
        get<2>(b[i]) = 0;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);

    int i, j;
    i = j = 0;
    while(i<n && j<m) {
        if(a[i] == get<0>(b[j])) {
            get<2>(b[j]) = 1;
            j = j+1;
        } else if(a[i] < get<0>(b[j])) {
            i += 1;
        } else if(a[i] > get<0>(b[j])) {
            j += 1;
        }
    }
    sort(b.begin(), b.end(), cmp2);
    for(int i = 0; i < m; ++i) {
        cout<<get<2>(b[i])<<'\n';
    }

    return 0;
}
