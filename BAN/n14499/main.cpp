#include <iostream>
// 1. 주사위 굴리기
// 2. 바닥면 이동
// 3. 바닥면에 따른 명령수행

using namespace std;
int a[20][20];
// 좌측 상단이 0,0이므로
// 동서북남(서->동 / 북->남 = 좌->우 / 상->하 로 인덱스 증가)
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int dice[7]; //주사위 면에 저장되는 수
int main(int argc, const char * argv[]) {
    int n, m, x, y, k;
    cin>>n>>m>>x>>y>>k;
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }
    while(k--) {
        int l;
        cin>>l;
        l -= 1; // 1,2,3,4동서북남 -> 0,1,2,3인덱스로 사용
        int nx, ny;
        nx = x+dx[l];
        ny = y+dy[l];
        if(nx <0 || nx>=n ||ny<0||ny>=m) {
            continue; // 지도 범위를 벗어나면 명령 무시
        }
        if(l == 0) {//rignt
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        } else if(l ==1) {//left
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        } else if(l == 2) {//up
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        } else if(l == 3) {//down
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }
        x = nx; y = ny;
        if(a[x][y] == 0) {
            a[x][y] = dice[6];
        } else {
            dice[6] = a[x][y];
            a[x][y] = 0;
        }
        cout<< dice[1]<<'\n';
    }
    
    
    return 0;
}
