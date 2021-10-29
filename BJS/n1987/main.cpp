//배열인자 복사 주의하자 - 되도록이면 참조형으로 가자. vector<bool> &check
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int r, c, ans;
void go(int x, int y, int cnt, vector<vector<char>> &a, vector<bool> &check) {
    ans = max(ans, cnt);
    //if(cnt == r*c) return;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        int value = a[nx][ny];
        if (check[value - 'A'] == true)
            continue;
        check[value - 'A'] = true;
        go(nx, ny, cnt + 1, a, check);
        check[value - 'A'] = false;
    }
}
int main(int argc, const char * argv[]) {
    cin>>r>>c;
    vector<vector<char>> a(r, vector<char>(c, ' '));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin>>a[i][j];
        }
    }
    vector<bool> check(26, false);
    check[a[0][0]-'A'] = true;
    go(0, 0, 1, a, check);
    cout<<ans<<'\n';
    return 0;
}
