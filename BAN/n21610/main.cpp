//샘송전자 2021 상반기 오후 1번
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int solution(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &c) {
    int cnt = 0;
    while(cnt < m) { //m번 구름이동
        int d = b[cnt][0];
        int s = b[cnt][1];
        cnt += 1;

        //구름이동
        vector<vector<int>> temp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(c[i][j] == 1) {
                    int nx = i + dx[d]*(s%n);
                    int ny = j + dy[d]*(s%n);
                    if(nx < 0) {
                        int temp = (nx * -1)%n;
                        nx = (n - temp)%n;
                    }
                    if(ny < 0) {
                        int temp = (ny * -1)%n;
                        ny = (n - temp)%n;
                    }
                    nx %= n;
                    ny %= n;
                    if((0<=nx&&nx<n) && (0<=ny&&ny<n)) {
                        temp[nx][ny] = 1;
                    }
                }
            }
        }
        c = temp;
        // 비온 뒤 + 1
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(c[i][j] == 1) {
                    a[i][j] += 1;
                }
            }
        }
        
        temp = a;
        // 비온 곳 기준 대각선칸 물이있는 칸만큼 + a
        for(int i = 0; i < n ; ++i) {
            for(int j = 0; j < n; ++j) {
                if(c[i][j] == 1) {
                    int count = 0;
                    for(int k = 1; k < 8; k += 2) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if((0<=nx&&nx<n) && (0<=ny&&ny<n)) {
                            if(a[nx][ny] > 0)
                                count += 1;
                        }
                    }
                    temp[i][j] += count;
                }
            }
        }
        a = temp;
        // 비가 오지 않은 칸 증발, 구름 생성
        vector<vector<int>> temp2(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(c[i][j] != 1) {
                    if(temp[i][j] >= 2) {
                        a[i][j] -= 2;
                        temp2[i][j] = 1;
                    }
                }
            }
        }
        c = temp2;
    }
    //최종 물 총량
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans += a[i][j];
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;

    cin >> tc;
    for(int t = 1; t <= tc; ++t) {
        cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> b(m);
        for(int i = 0; i <m; ++i) {
            int d, s;
            cin >> d>>s;
            d -= 1;
            b[i].push_back(d);
            b[i].push_back(s);
        }
        vector<vector<int>> c(n, vector<int>(n, 0));
        c[n-1][0] = 1;
        c[n-1][1] = 1;
        c[n-2][0] = 1;
        c[n-2][1] = 1;

        cout<<'#'<<t<<' ';
        cout<<solution(a, b, c);
        cout<<'\n';
    }
    return 0;
}
