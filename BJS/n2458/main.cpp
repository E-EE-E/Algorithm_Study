#include <iostream>
#include <vector>
using namespace std;

int n, m;
void floyd_warshall(vector<vector<bool>> &adj) {
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(adj[i][k] && adj[k][j])
                    adj[i][j] = true;
            }
        }
    }
}
int main() {
    cin>>n>>m;
    vector<vector<bool>> adj(n+1, vector<bool>(n+1, false));
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin>>a>>b;
        adj[a][b] = true;
    }
    floyd_warshall(adj);
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(int j = 1; j <= n; ++j) {
            if(adj[i][j] || adj[j][i]) cnt++;
        }
        ans += (cnt == n-1);
    }
    cout<<ans<<'\n';
    
    return 0;
}
