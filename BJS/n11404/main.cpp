#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int n, m;
int main(int argc, const char * argv[]) {
    cin>>n>>m;
    vector<vector<LL>> adj(n, vector<LL>(n, -1));
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        if(adj[a-1][b-1] == -1 || adj[a-1][b-1] > c)
            adj[a-1][b-1] = c;
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(adj[i][k] != -1 && adj[k][j] != -1) {
                    if(adj[i][j] == -1 || adj[i][j] > adj[i][k] + adj[k][j])
                        adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j || adj[i][j] == -1)
                cout<<0<<' ';
            else
                cout<<adj[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
