#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int INF = (1<<31)-1;

int n, m, r;
vector<int> go(int s, vector<vector<pii>> &g) {
    vector<int> dist(n, INF);
    dist[s] = 0;
    
    priority_queue<pii> pq;
    pq.push(pii(0, s));
    
    while(!pq.empty()) {
        int cost = -pq.top().first; //min
        int cur = pq.top().second; pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(int i = 0; i < g[cur].size(); ++i) {
            int nx = g[cur][i].second;
            int nxDist = cost + g[cur][i].first;
            if(dist[nx] > nxDist) {
                dist[nx] = nxDist;
                pq.push(pii(-nxDist, nx));
            }
        }
    }
    
    return dist;
}
int main(int argc, const char * argv[]) {
    cin>>n>>m>>r;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    vector<vector<pii>> g(n);
    for(int i = 0; i < r; ++i) {
        int a, b, l;
        cin>>a>>b>>l;
        g[a-1].push_back(pii(l, b-1));
        g[b-1].push_back(pii(l, a-1));
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int temp = 0;
        vector<int> res = go(i, g);
        for(int j = 0; j < n; ++j) {
            if(res[j] <= m) {
                temp += a[j];
            }
        }
        if(ans < temp) {
            ans = temp;
        }
    }
    cout<<ans<<'\n';
    
    return 0;
}
