#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const LL INF = 987654321;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, LL>>> graph(n);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        graph[a-1].push_back(make_pair(b-1, c));
    }
    vector<LL> dist(n, INF);
    dist[0] = 0;
    bool cycle = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {//from
            if(dist[j] == INF) continue;
            for(int k = 0; k < graph[j].size(); ++k) {//to
                int adj = graph[j][k].first;
                LL adjCost = graph[j][k].second;
                if(dist[adj] > dist[j] + adjCost) {
                    dist[adj] = dist[j] + adjCost;
                    if(i == n-1) cycle = true;
                }
            }
        }
    }
    if(cycle) cout<<-1<<'\n';
    else {
        for(int i = 1; i < n; ++i) {
            cout<<(dist[i] != INF ? dist[i] : -1)<<'\n';
        }
    }
    return 0;
}
