#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, m;
vector<vector<char>> board;
vector<int> dir;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int simulation(vector<vector<char>> a) {
    int ans = -1;//11;
    for(int k = 0; k < dir.size(); ++k) {
        int d = dir[k];
        int rx, ry, bx, by;
        int hx, hy;
        rx = ry = bx = by = hx = hy = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] =='R') {rx = i; ry = j;}
                else if(a[i][j] == 'B') {bx = i; by = j;}
                else if(a[i][j] == '0') {hx = i; hy = j;}
            }
        }
        bool rhole = false;
        bool bhole = false;
        bool not_change = false;
        int prx = rx; int pry = ry; int pbx = bx; int pby = by;
        while(!not_change) {
            int temprx = prx + dx[d];
            int tempry = pry + dy[d];
            if((0<= temprx&& temprx<n) &&(0<= tempry&&tempry<m)) {
                rx = prx + dx[d];
                ry = pry + dy[d];
                if(a[rx][ry] == '#') {
                    rx = prx; ry = pry;
                }
                else if(a[rx][ry] == 'O') {
                    rhole = true;
                    a[prx][pry] = '.';
                }
                else if(a[rx][ry] == 'B') {
                    rx = prx; ry = pry;
                }
                else {
                    a[rx][ry] = a[prx][pry];
                    a[prx][pry] = '.';
                }
            }
            
            int tempbx = pbx + dx[d];
            int tempby = pby + dy[d];
            
            if((0<= tempbx&& tempbx<n) &&(0<= tempby&&tempby<m)) {
                bx = pbx + dx[d];
                by = pby + dy[d];
                
                if(a[bx][by] == '#') {
                    bx = pbx; by = pby;
                }
                else if(a[bx][by] == 'O') {
                    bhole = true;
                    a[pbx][pby] = '.';
                }
                else if(a[bx][by] == 'R') {
                    bx = pbx; by = pby;
                }
                else {
                    a[bx][by] = a[pbx][pby];
                    a[pbx][pby] = '.';
                }
                
            }
            if(pbx == bx && pby == by && prx == rx && pry == ry) {
                not_change = true;
            }
            prx = rx; pry = ry; //마지막에..?
            pbx = bx; pby = by; //마지막에..?
        }
        if(bhole == true) {
            break;
        } else {
            if(rhole == true) {
                ans = k+1;
                break;
            }
        }
    }
    return ans;
}
int solution(int index, int pdir) {
    if(index == 10) {
        int ret = simulation(board);
        return ret;
    }
    int ans = -1;//11;
    for(int i = 0; i < 4; ++i) {
        if(i == pdir) continue;
        else if(i == 0 && pdir == 1) continue;
        else if(i == 1 && pdir == 0) continue;
        else if(i == 2 && pdir == 3) continue;
        else if(i == 3 && pdir == 2) continue;
        dir.push_back(i);
        int temp = solution(index +1, i);
        dir.pop_back();
        if(temp == -1) continue;
        if(ans == -1 ||temp < ans)
            ans = temp;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int t = 1; t<= tc; ++t) {
        board.clear();
        dir.clear();
        cin>>n>>m;
        for(int i = 0; i < n; ++i) {
            vector<char> temp;
            for(int j = 0; j < m; ++j) {
                char a;
                cin>> a;
                temp.push_back(a);
            }
            board.push_back(temp);
        }
        cout<<'#'<<t<<' ';
        int ans = solution(0, -1);
        //if(ans == 11)
        //    ans = -1;
        cout<<ans;
        cout<<'\n';
    }
    return 0;
}
