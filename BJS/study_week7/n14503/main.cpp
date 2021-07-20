#include <iostream>
#include <vector>
using namespace std;

int n, m, r, c, d, ans;
int dx[] = {-1,0,1,0};//북,동,남,서(x), 북,서,남,동(왼쪽회전기준)
int dy[] = {0,-1,0,1};
int a[51][51];
bool check[51][51];
void go(int x, int y, int dir) {
    if(check[x][y]) return;
    ans++;
    check[x][y] = true;
    
    int prv = dir;
    for(int i = 0; i < 4; ++i) {
        int ndir = (prv + i)%4;
        int nx = x+dx[ndir];
        int ny = y+dy[ndir];
        if(nx<0 || n < nx || ny < 0 || m < ny) continue;
        if(a[nx][ny] == 1) continue;
        go(nx, ny, ndir);
        //prv = ndir;
    }
}
int main() {
    cin>>n>>m>>r>>c>>d;
    r-= 1, c-= 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }
    if(d == 3) d = 1;
    else if(d == 1) d = 3;
    go(r, c, d);
    cout<<ans<<'\n';
    return 0;
}
