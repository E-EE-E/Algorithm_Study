//시간은 상대적으로 느리지만
//방문배열을 참조형 인자로 넘겨주면 성공, 복사하면 시간초과남 (vector<bool> &check, vector<bool> check)
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//typedef pair<int, int> pii;
//int dx[] = {0,0,-1,1};
//int dy[] = {-1,1,0,0};
//int r, c;
//int go(int x, int y, int cnt, vector<vector<char>> &a, vector<bool> &check, vector<vector<bool>> &ch) {
//    if(ch[x][y] == true) return cnt;
//    ch[x][y] = true;
//
//    int ans = -1;
//    bool ok = false;
//    for(int i = 0; i < 4; ++i) {
//        int nx =x+dx[i];
//        int ny =y+dy[i];
//        if(nx <0 || ny < 0|| nx >= r || ny >= c) continue;
//        int value = a[nx][ny];
//        if(check[value-'A'] == true) continue;
//        check[value - 'A'] = true;
//        ok = true;
//        int temp = go(nx, ny, cnt+1, a, check, ch);
//        check[value - 'A'] = false;
//        ch[nx][ny] = false;
//        if(ans == -1 || temp > ans) {
//            ans = temp;
//        }
//    }
//    if(!ok ) return cnt;
//    return ans;
//}
//int main(int argc, const char * argv[]) {
//    cin>>r>>c;
//    vector<vector<char>> a(r, vector<char>(c, ' '));
//    for(int i = 0; i < r; ++i) {
//        for(int j = 0; j < c; ++j) {
//            cin>>a[i][j];
//        }
//    }
//    vector<bool> check(26, false);
//    vector<vector<bool>> ch(r, vector<bool>(c, false));
//    check[a[0][0]-'A'] = true;
//    int res = go(0, 0, 1, a, check, ch);
//    cout<<res<<'\n';
//    return 0;
//}
//
//
