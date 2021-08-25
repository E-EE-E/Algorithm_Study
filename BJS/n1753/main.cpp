#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321; // why?????
int v, e, s;
vector<vector<pair<int, int>>> graph(MAX);
vector<int> dijkstra() {
    vector<int> dist(v+1, INF);
    dist[s] = 0;
    
    priority_queue<pair<int, int>> pq; //cost vertex
    pq.push(make_pair(0, s)); // 초기비용, 시작점
    
    while(!pq.empty()) {
        int cost = -pq.top().first; // min
        int cur = pq.top().second; pq.pop();
        
        if(dist[cur] < cost) continue; // 최소dist
        
        for(int i = 0; i < graph[cur].size(); ++i) { //check all neighbors
            int nx = graph[cur][i].first;
            int nxDist = cost + graph[cur][i].second;
            if(dist[nx] > nxDist) {
                dist[nx] = nxDist; //작은값으로 업데이트
                pq.push(make_pair(-nxDist, nx));
            }
        }
    }
    
    return dist;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>v>>e>>s;

    for(int i = 0; i < e; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
    }
    
    vector<int> res = dijkstra();
    
    for(int i = 1; i <= v; ++i) {
        if(res[i] == INF)
            cout<<"INF"<<'\n';
        else
            cout<<res[i]<<'\n';
    }
    return 0;
}
