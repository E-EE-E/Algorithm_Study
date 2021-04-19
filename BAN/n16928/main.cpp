/*
 백준에 있는 예제 testcase 모두 한번에 돌리는 형태로 구현함
 testcase T개만큼 출력
=>    #(testcase) 결과값
=>ex) #1 3
 */
//문제 접근
//노드, 간선 그래프 형태로 나타낼 수 있고
//가중치가 모두 1이므로 BFS로 풀이

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define next _next //c++14 algorithm에 같은이름함수존재
using namespace std;
int solution(vector<int> &dist, const vector<int> &next){
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 1; i <= 6; ++i) {
            if(cur+i > 100) continue;
            int y = next[cur+i];
            if(dist[y] == -1) {
                dist[y] = dist[cur] + 1;
                q.push(y);
            }
        }
    }
    return dist[100];
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        vector<int> dist(101, 0);
        vector<int> next(101, 0);
        for(int i = 1; i <= 100; ++i) {
            dist[i] = -1;
            next[i] = i;
        }
        int n, m;
        cin>>n >>m;
        while(n--) {
            int x, y;
            cin >> x>>y;
            next[x] = y;
        }
        while(m--) {
            int u, v;
            cin>>u>>v;
            next[u] = v;
        }
        cout<<'#'<<t<<' '<<solution(dist, next)<<'\n';
    }
    return 0;
}
