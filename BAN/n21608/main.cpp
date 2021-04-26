//샘송전자 2021 상반기 오전 1번
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool compare(const tuple<int, int, int, int> &u, tuple<int, int, int, int> &v) {
    if(get<0>(u) == get<0>(v)) {
        if(get<1>(u) == get<1>(v)) {
            if(get<2>(u) == get<2>(v))
                return get<3>(u) < get<3>(v);
            return get<2>(u) < get<2>(v);
        }
        return get<1>(u) > get<1>(v);
    }
    
    return get<0>(u) > get<0>(v);
}
tuple<int, int, int, int> findempty(vector<vector<int>> &a, vector<int> &p) {
    int n = (int)a.size();
    vector<tuple<int, int, int, int>> ans;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j] < 0) {
                int cnt = 0;
                int emptycnt = 0;
                for(int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if((0<= nx&&nx < n) && (0<= ny&&ny <n)) {
                        if(a[nx][ny] < 0) {
                            emptycnt += 1;
                            continue;
                        }
                        for(int l = 1; l <= 4; ++l) {
                            if(a[nx][ny] == p[l])
                                cnt++;
                        }
                    }
                }
                ans.push_back(make_tuple(cnt, emptycnt, i, j));
            }
        }
    }
    if(ans.empty())
        return make_tuple(-1, -1, -1, -1);

    sort(ans.begin(), ans.end(), compare);
    
    return ans[0];
}
vector<int> findperson(int idx, vector<vector<int>> &a) {
    int n = (int)a.size();
    vector<int> ans(1);
    for(int i = 0; i < n; ++i) {
        if(idx == a[i][0]) {
            ans = a[i];
            break;
        }
    }
    return ans;
}
int solution(vector<vector<int>> &a, int n) {
    int ans = 0;
    vector<vector<int>> map(n, vector<int>(n, -1));
    //자리배치
    for(int i = 0; i < a.size(); ++i) {
        vector<int> p = a[i];
        int cnt, emptycnt, x, y;
        tie(cnt, emptycnt, x, y) = findempty(map, p);
        if(cnt == -1) break;
        map[x][y] = p[0];
    }
    
    //만족도
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int temp = map[i][j];
            int cnt = 0;
            for(int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if((0<= nx&&nx < n) && (0<= ny&&ny <n)) {
                    for(int l = 1; l <= 4; ++l) {
                        vector<int> person = findperson(temp, a);
                        if(map[nx][ny] ==  person[l]) {
                            cnt += 1;
                        }
                    }
                }
            }
            if(cnt != 0) {
                ans += pow(10, cnt-1);
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
        int n;
        cin>> n;
        vector<vector<int>> a;
        for(int i = 0; i < n*n; ++i) {
            vector<int> temp;
            for(int j = 0; j < 5; ++j) {
                int x;
                cin>>x;
                x-=1;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
        cout<<'#'<<t<<' ';
        cout<<solution(a, n)<<'\n';
    }
    
    return 0;
}
