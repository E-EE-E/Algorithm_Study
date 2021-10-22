dist[a][b] a->b
max(dist[a][b] + dist[b][a])
//다익스트라 -> 가중치 양수, 최단거리
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

const int INF = (1<<31)-1;
const int MAX = 10000 + 1;

int main(int argc, const char * argv[]) {
    int n, m, x;
    cin>>n>>m>>x;
    vector<vector<pii>> to(MAX);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        to[a].push_back(pii(b, c));//a->b, 단방향
    }
        
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i = 1; i < n+1; ++i) {
        dist[i][i] = 0;
        priority_queue<pii> pq;
        pq.push(pii(i, 0));
        
        while(!pq.empty()) {
            int w = -pq.top().second;
            int e = pq.top().first; pq.pop();
            
            if(dist[i][e] < w) continue;
            
            for(auto it = to[e].begin(); it != to[e].end(); ++it) {
                int nx = (*it).first;
                int nxw = w + (*it).second;
                if(dist[i][nx] > nxw) {
                    dist[i][nx] = nxw;
                    pq.push(pii(nx, -nxw));
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i < n+1; ++i) {
        ans = max(ans, dist[i][x] + dist[x][i]);
    }
    cout<<ans<<'\n';
    
    return 0;
}
