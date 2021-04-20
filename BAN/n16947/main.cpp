#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> a(3000, vector<int>(3000));
//순환선 찾기 (DFS)
int dfs(int x, int px, vector<int> &check) {
    if(check[x]==1) return x; //사이클 찾음
    check[x] = 1; //방문
    for(int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if(y != px) {
            int res = dfs(y, x, check);
            if(res == -2) return -2; //사이클 찾았지만, x는 사이클 밖
            if(res >= 0) {
                check[x] = 2; //x는 사이클에 포함
                if(x == res) return -2; //사이클 시작점 = 끝. 다음부터 사이클에 포함안됨
                else
                    return res; //사이클의 시작점 반환 = 사이클 중
            }
        }
    }
    return -1; //사이클 못찾음
}
void solution(int n) {
    vector<int> check(n, 0);
    dfs(0, -1, check);
    
    //순환선과의 최단거리 찾기 (BFS)
    queue<int> q;
    vector<int> dist(n);
    for(int i = 0; i < n; ++i) {
        if(check[i] == 2) { //사이클
            dist[i] = 0;
            q.push(i);
        } else{
            dist[i] = -1;
        }
    }
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i];
            if(dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        cout<<dist[i]<<' ';
    }
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        int n;
        cin>> n;
        for(int i = 0; i < n; ++i) {
            a[i].clear();
        }
        for(int i = 0; i < n; ++i) {
            int x, y;
            cin>>x>>y;
            x-=1; y-=1;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cout<<'#'<<t<<' ';
        solution(n);
        cout<<'\n';
    }
    return 0;
}
