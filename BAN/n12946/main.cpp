//
// ans = 0 : 하나도 색칠할 칸이 없을때
// ans = 1 : 모든 색칠할 칸이 인접하지 않을때
// ans = 2 : 이분그래프일때
// ans = 3 : 이분그래프가 아닐 때 = 인접한 정점이 같은 색으로 칠해졌을 때 (색칠 최대 3)
//
#include <cstdio>
#include <iostream>
#include <cstring> //for memset
#include <vector>

using namespace std;
int n;
vector<char> a[50];
vector<int> dx = {-1,-1,0,0,1,1};
vector<int> dy = {0,1,-1,1,-1,0};
int color[50][50];
int ans;
void dfs(int x, int y, int c) {
    color[x][y] = c;
    ans = max(ans, 1); //색칠하러왔다면 이미 0이 아님
    for(int k = 0; k < 6; ++k){ //육각보드 확인
        int nx = x + dx[k];
        int ny = y + dy[k];
        if((0<= nx&&nx <n)&&(0<=ny&&ny<n)) {//범위 내
            if(a[nx][ny] == 'X') {//칠해야 되는 칸일 때
                if(color[nx][ny] == -1) { //안칠했으면 칠하러감
                    dfs(nx, ny, 1-c); // 1-c 인접한 칸은 다른색으로 칠함
                }
                ans = max(ans, 2); // 인접한 칸이 있다면 이미 1이 아님
                if(color[nx][ny] == c) { // 인접한 칸이 같은색으로 칠해졌다면
                    ans = max(ans, 3); // 이분그래프가 아니므로 답은 3
                }
            }
        }
    }
}
int solution() {
    ans = 0;
    //memset(color, -1, sizeof(color));
    for(int i = 0; i <n; ++i) {
        for(int j = 0; j < n; ++j) {
            color[i][j] = -1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j] == 'X' && color[i][j] == -1) { //색칠해야되는데 안했으면
                dfs(i, j, 0);//색칠하러감 (0으로 색칠)
            }
        }
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        n = 0;
        cin>>n;
        
        for(int i = 0; i < n; ++i) {
            a[i].clear();
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                char m;
                cin >> m;
                a[i].push_back(m);
            }
        }
        
        cout<<'#'<<t<<' ';
        cout<<solution();
        cout<<'\n';
    }
    return 0;
}
