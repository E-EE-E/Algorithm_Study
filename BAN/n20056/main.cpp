//음수 좌표인 경우 맵 밖으로 나가지 않도록 처리하는 것.
//1. 이동
//- 맵에서 이동 -> r.c에 있던 vector<ball>은 모두 지우고 nx, ny로 push_back
//--- 이동 할 때마다 새로운 temp 맵에 볼 추가해서 deep copy해줌
//- ball 이동 -> ball list에 있는 r,c도 nx, ny로 업데이트
//2. 합치고 나누기
//- 합치고 나눈다 = 나누는 과정에서 나온 m,s,d의 ball이 4개가 생긴다
//-- = 기존 ball은 지우고 4개 추가하면됨
//-- 지울 때 맵에서 볼vector도 지우지만 ball list에서도 지워져야함 = bool iserase이용

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct ball {
    int r, c, m, s, d;
    int idx;
    bool iserased;
};
int n, m, k;
vector<ball> balls; //m개
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int sum_m(vector<ball> a) {
    int sum = 0;
    for(int i = 0; i < a.size(); ++i) {
        sum += a[i].m;
    }
    return sum / 5;
}
int sum_s(vector<ball> a) {
    int sum = 0;
    for(int i = 0; i < a.size(); ++i) {
        sum+= a[i].s;
    }
    return sum/a.size();
}
bool sum_d(vector<ball> a) {
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i].d % 2 == 0)
            cnt += 1;
    }
    if(cnt == a.size()) {
        return true;
    }
    cnt = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i].d % 2 != 0)
            cnt += 1;
    }
    if(cnt == a.size()) {
        return true;
    }
    return false;
}
bool clearball(vector<ball> &a) {
    for(int i = 0; i < a.size(); ++i) {
        balls[a[i].idx].iserased = true; //직접 vector에서 빼고 넣기 복잡해서 불변수로 판단
    }
    return true;
}
int solution(vector<ball> map[50][50]) {
    for(int i = 0; i < k; ++i) {
        //move
        vector<ball> temp[50][50];
        for(int j = 0; j < balls.size(); ++j) {
            ball &curball = balls[j]; //이동한 곳으로 r,c 업데이트 해줘야 하므로 레퍼런스 선언!!주의
            if(curball.iserased == true) continue;
            int d = curball.d;
            int nx = (curball.r + dx[d]*curball.s)%n;
            if(nx < 0) {
                int t = nx*-1; //음수인 경우 맵안으로 들어오도록
                nx = n - (t%n);
            }
            int ny = (curball.c + dy[d]*curball.s)%n;
            if(ny < 0) {
                int t = ny*-1;
                ny = n - (t%n);
            }
            curball.r = nx; curball.c = ny; //위치 이동
            temp[nx][ny].push_back(curball);//이동한 위치로
        }
        map = temp;
        
        for(int i1 = 0; i1 < n; ++i1) {
            for(int j = 0; j < n; ++j) {
                if(map[i1][j].size() >= 2) {
                    int m, s, d;
                    m = sum_m(map[i1][j]);
                    if(m == 0) {
                        clearball(map[i1][j]); //ball list에서도 지우고
                        map[i1][j].clear();    //맵에서도 지우고
                        continue;
                    }
                    s = sum_s(map[i1][j]);
                    d = sum_d(map[i1][j]) ? 0 : 1;
                    clearball(map[i1][j]);  //다 지우고 4개 새로 넣는다
                    map[i1][j].clear();
                    int index = (int)balls.size();
                    for(int j1 = 0; j1 < 4; ++j1, ++index) {
                        ball curball = {i1, j, m, s, d +j1*2, index, false};
                        balls.push_back(curball); //ball list에도 넣고
                        map[i1][j].push_back(curball); //맵에도 넣고
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < balls.size(); ++i) {
        if(!balls[i].iserased) //존재하는 ball 중에서만 질량합
            ans += balls[i].m;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t =  1; t <= tc; ++t) {
        vector<ball> map[50][50];
        balls.clear();
        cin>>n>>m>>k;
        int index = 0;
        for(int i = 0; i < m; ++i) {
            int r, c, m, s, d;
            cin>> r>>c>>m>>s>>d;
            r-=1; c-=1;
            ball b = {r, c, m, s, d,index, false};
            map[r][c].push_back(b);
            balls.push_back(b);
            index += 1;
        }
        cout<<'#'<<t<<' ';
        cout<<solution(map);
        cout<<'\n';
    }
    return 0;
}
