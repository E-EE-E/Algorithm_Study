#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct Pers{
    Pers(){};
    Pers(int _x, int _y, int _nx, int _ny){x = _x; y = _y; nx = _nx; ny = _ny;}
    int x, y;
    int nx, ny;
};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
tuple<int, int, int, int> bfs(int x, int y, vector<vector<int>> &a, vector<Pers> &p) {
    int n = (int)a.size();
    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(n, -1));
    vector<tuple<int, int, int, int>> ans;
    
    q.push(make_pair(x, y));
    d[x][y] = 0;
    while(!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        if(a[x][y] > 0) {
            ans.push_back(make_tuple(d[x][y], x, y, a[x][y]));
        }
        for(int i = 0; i< 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if((0<= nx&&nx < n)&&(0 <= ny&&ny < n) && d[nx][ny] == -1
               && a[nx][ny] != -1) {
                bool move = false; bool person = false;
                if(a[nx][ny] > 0) {
                    move = true; person = true;
                } else if(a[nx][ny] == 0) {
                    move = true;
                }
                if(move) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                    if(person) {
                        ans.push_back(make_tuple(d[nx][ny], nx, ny, a[nx][ny]));
                    }
                }
            }
        }
    }
    if(ans.empty())
        return make_tuple(-1, -1, -1, -1);
    sort(ans.begin(), ans.end());
    return ans[0];
}
tuple<int, int, int> bfs_arrive(int x, int y, vector<vector<int>> &a, Pers &p) {
    int n = (int)a.size();
    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(n, -1));
    vector<tuple<int, int, int>> ans;
    
    q.push(make_pair(x, y));
    d[x][y] = 0;
    while(!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for(int i = 0; i< 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if((0<= nx&&nx < n)&&(0 <= ny&&ny < n) && d[nx][ny] == -1
               && a[nx][ny] != -1) {
                d[nx][ny] = d[x][y] + 1;
                q.push(make_pair(nx, ny));
                if(nx == p.nx && ny == p.ny) {
                    ans.push_back(make_tuple(d[nx][ny], nx, ny));
                }
            }
        }
    }
    if(ans.empty())
        return make_tuple(-1, -1, -1);
    sort(ans.begin(), ans.end());
    return ans[0];
}
int solution(int x, int y, int f, vector<vector<int>> &a, vector<Pers> &p, int m) {
    int ans = f;
    int cnt = 0;
    while(1) {
        int nx, ny, dist, idx;
        tie(dist, nx, ny, idx) = bfs(x, y, a, p);
        if(dist == -1) break;
        ans -= dist;
        if(ans < 0) break;
        a[nx][ny] = 0;
        tie(x, y) = make_pair(nx, ny);
        
        tie(dist, nx, ny) = bfs_arrive(x, y, a, p[idx]);
        if(dist == -1) break;
        ans -= dist;
        if(ans < 0) break;
        cnt += 1;
        ans += dist*2;
        tie(x, y) = make_pair(nx, ny);
    }
    
    if(cnt != m)
        return -1;
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t<= tc; ++t) {
        int n, m, f;
        cin>>n >>m>> f;
        vector<vector<int>> a(n, vector<int>(n, 0));
        //vector<vector<int>> a_arrive(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int x;
                cin>>x;
                if(x== 1) {
                    x = -1;
                }
                a[i][j] = x; //a_arrive[i][j] = x;
            }
        }
        int x, y;
        cin>>x>>y;
        x-=1;y-=1;
        vector<Pers> p(m+1);
        for(int i = 1; i <= m; ++i) {
            int cx, cy, nx, ny;
            cin>>cx>>cy>>nx>>ny;
            cx -= 1; cy -=1; nx -=1; ny-=1;
            a[cx][cy] = i;
            //a_arrive[nx][ny] = i;
            p[i] = Pers(cx, cy, nx, ny);
        }
        cout<<'#'<<t<<' ';
        cout<<solution(x, y, f, a, p, m);
        cout<<'\n';
    }
    return 0;
}
