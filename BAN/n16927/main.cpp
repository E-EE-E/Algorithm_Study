#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a[300];
int n, m, r;
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n>>m>>r;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int c = 0;
            cin>> c;
            a[i].push_back(c);
        }
    }
    
    vector<vector<int>> groups;
    for(int k=0; k < min(n, m)/2; ++k) {
        vector<int> group;
        for(int j = k; j < m-1-k; ++j) {
            group.push_back(a[k][j]);
        }
        for(int i = k; i < n-1-k; ++i) {
            group.push_back(a[i][m-1-k]);
        }
        for(int j = m-1-k; j >= 1+k; --j) {
            group.push_back(a[n-1-k][j]);
        }
        for(int i = n-1-k; i >= 1+k; --i) {
            group.push_back(a[i][k]);
        }
        groups.push_back(group);
    }

    for(int k=0; k < min(n, m)/2; ++k) {
        vector<int> &group = groups[k];
        int len = (int)group.size();
        int idx = r % len;
        for(int j = k; j < m-1-k; ++j, idx = (idx+1)%len) {
            a[k][j] = group[idx];
        }
        for(int i = k; i < n-1-k; ++i, idx = (idx+1)%len) {
            a[i][m-1-k] = group[idx];
        }
        for(int j = m-1-k; j >= 1+k; --j, idx = (idx+1)%len) {
            a[n-1-k][j] = group[idx];
        }
        for(int i = n-1-k; i >= 1+k; --i, idx = (idx+1)%len) {
            a[i][k] = group[idx];
        }
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}
