#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 32000 + 2;
int to[MAX];
vector<int> adj[MAX];
int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin>>a>>b;
        to[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(to[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < adj[cur].size(); ++i) {
            int j = adj[cur][i];
            --to[j];
            if(to[j] == 0)
                q.push(j);
        }
        cout<<cur<<' ';
    }
    return 0;
}
