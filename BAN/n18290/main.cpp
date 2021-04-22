#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int n, m, k;
int ans = -2147483647;
bool check[10][10];
int a[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void go(int index, int sum, int px, int py) {
    if(index == k) {
        if(ans < sum)
            ans = sum;
        return;
    }
    
    for(int i = px; i < n; ++i) {
        for(int j = (i == px)?py:0; j < m; ++j) {
            if(check[i][j]) continue;
            bool ok = true;
            for(int x = 0; x < 4; ++x) {
                int nx = i + dx[x];
                int ny = j + dy[x];
                if((0<= nx&&nx < n)&&(0<= ny&&ny < m)) {
                    if(check[nx][ny]) {
                        ok = false;
                    }
                }
            }
            if(!ok) continue;
            check[i][j] = true;
            //sum += a[i][j];
            go(index + 1, sum + a[i][j], i, j);
            //sum -= a[i][j];
            check[i][j] = false;
        }
    }
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        cin>> n >> m >> k;
        ans = -2147483647;
        memset(a, 0, sizeof(a)); //0으로 배열초기화
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin>> a[i][j];
                check[i][j] = false; // check배열 초기화
            }
        }
        
        cout<<'#'<<t<<' ';
        go(0, 0, 0, 0);
        cout<<ans;
        cout<<'\n';
    }
    return 0;
}
