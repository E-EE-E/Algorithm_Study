/*
 1. 궁수 배치
  L 2. 게임진행 while(1)
    //적 수 카운트 if 적 == 0  break;
    2-1. 궁수 공격
    //모든 궁수 동시 공격 - 이전 궁수가 죽인 적이 다음 궁수가 죽일 수 있는 적에 영향을 미치면 안됨!!!!
    2-2. 적 이동
 */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, m, d;
vector<vector<int>> a;
int simulation(vector<vector<int>> b, int l1, int l2, int l3) {
    vector<int> pos(3);
    pos = {l1, l2, l3};
    
    int score = 0;
    
    while(true) {
        int cnt = 0;
        for(int i = 0; i <n; ++i) {
            for(int j = 0; j < m; ++j) {
                cnt += b[i][j]; //적수 카운트
            }
        }
        if(cnt == 0) break; //적이 없으면 종료
        vector<pair<int,int> > deleted(3, make_pair(-1, -1));
        for(int k = 0; k < 3; ++k) {
            int dx, dy, min_dist;
            dx = dy = min_dist = -1;
            for(int j = 0; j < m; ++j) { // 열 먼저!!
                for(int i = 0; i < n; ++i) {
                    if(b[i][j] == 0) continue;
                    int dist = abs(n-i) + abs(pos[k]-j);
                    if(dist > d) continue;
                    if(dist < min_dist || min_dist == -1) { //dist가 같은 값은 이후 선택되지 않는다. 열이 오른쪽으로 가기때문에
                        dx = i; dy = j;
                        min_dist = dist;
                    }
                }
            }
            deleted[k] = make_pair(dx, dy);
//            if((0<= dx&&dx<n) && (0<=dy&&dy<m)) {
//
//                b[dx][dy] = 0;
//                ++score; //각 궁수별로 공격이 끝날 때 마다 적을 죽임처리하면 동시공격이 아닌 순차공격이 됨!!!!!!(주의사항)
//            }
        }
        // 동시에 공격할 수 있기 때문에, 궁수들이 죽이는 적이 겹칠 수 있다.
        // 그러므로 각 궁수가 죽일 수 있는 적을 찾은 뒤, 적이 중복되지 않도록 score에 카운트한다.
        // ex)적 1- 궁수1이 죽임, 궁수 2가 죽임
        // => score = 1
        for(int i = 0; i < 3; ++i) {
            int x = deleted[i].first;
            if(x == -1) continue;
            int y = deleted[i].second;
            if(b[x][y] != 0) { //이미 죽인 적 또 죽이지 않도록, 카운트!
                score += 1;
            }
            b[x][y] = 0;
        }
        for(int i = n-1; i >= 0; --i) {
            for(int j = 0; j < m; ++j) {
                if(b[i][j] == 1) {
                    b[i][j] = 0;
                    if(i+1 != n) {
                        b[i+1][j] = 1;
                    }
                }
            }
        }
    }
    
    return score;
}
int go() {
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = i+1; j < m; ++j) {
            for(int k = j+1; k < m; ++k) {
                int ret = simulation(a, i, j, k);
                if(ans < ret) ans = ret;
            }
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        cin>>n>>m>>d;
        a.clear();
        
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
        cout<<'#'<<t<<' ';
        cout<<go();
        cout<<'\n';
    }
    return 0;
}
