// 방향은 언제나 서, 남, 동, 북 순서로 회전한다는 것
// 서, 남, 동, 북에 대한 10군데의 흩날리는 모래의 방향을 이차배열로 정의하는 부분이 까다로웠음
// 한 번에 한 칸 이동하고 dist만큼 이동이 끝나면 방향을 변경해준다
// dist마다 두 개의 방향으로 이동이 필요하다
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, ans;
//4방향
int dx[] = {0,1,0,-1}; //서 남 동 북
int dy[] = {-1,0,1,0}; //서 남 동 북
//double p[9] = {0.05, 0.10, 0.10, 0.02, 0.02, 0.07, 0.07, 0.01, 0.01}; // 몇%/100
int p[9] = {5, 10, 10, 2, 2, 7, 7, 1, 1};// 비율 몇%
int m_dx[4][10] = {
    {0, -1, 1, -2, 2, -1, 1, -1, 1, 0},//서
    {2, 1, 1, 0, 0, 0, 0, -1, -1, 1},//남
    {0, -1, 1, -2, 2, -1, 1, -1, 1, 0},//동
    {-2, -1, -1, 0, 0, 0, 0, 1, 1, -1}};//북
int m_dy[4][10] = {
    {-2, -1, -1, 0, 0, 0, 0, 1, 1, -1},//서
    {0, -1, 1, -2, 2, -1, 1, -1, 1, 0},//남
    {2, 1, 1, 0, 0, 0, 0, -1, -1, 1},//동
    {0, -1, 1, -2, 2, -1, 1, -1, 1, 0}};//북
void solution(vector<vector<int>> &board) {
    int x = n/2; //배열의 중간지점 좌표
    int y = n/2;
    int a; //토네이도가 이동한 y지점 모래
    int d = 0; // 방향정보(0: 서, 1: 남, 2: 동, 3: 북)
    int dist = 1; //dist만큼 d방향으로 이동
    int cnt = 0; // 두 번 이동 확인용 (한 방향당 2번)
    while(1) {
        cnt += 1;
        for(int m = 0; m < dist; ++m) {  //한 칸씩 이동
            int nx = x + dx[d]; //d 방향으로 이동
            int ny = y + dy[d];
            x = nx; y = ny;
            a = board[nx][ny]; //이동지점(y) 모래
            for(int k = 0; k < 9; ++k) { // 비율적힌 칸에 모래 이동
                int m_nx = nx + m_dx[d][k];
                int m_ny = ny + m_dy[d][k];
                int sand = board[nx][ny]*(p[k]/100.0); //흩날린 모래 //y지점에 있던 모래의 p퍼센트 //a에서 비율을 계산하면 안됨. a는 모래가 흩날리는 중간값이므로
                a -= sand;
                if((0<= m_nx && m_nx < n)&& (0<=m_ny&& m_ny< n)) {
                    board[m_nx][m_ny] += sand;
                } else {
                    ans += sand;
                }
            }
            //a알파 칸에 남은 모래 이동
            int m_nx = nx + m_dx[d][9];
            int m_ny = ny + m_dy[d][9];
            if((0<= m_nx && m_nx < n)&& (0<= m_ny&& m_ny< n)) {
                board[m_nx][m_ny] += a;
            } else {
                ans += a;
            }
            board[nx][ny] = 0; //모두 흩날려서 남은 모래 없음
            if(nx == 0 && ny == 0) {
                return;
            }
        }
        if(cnt == 2) {
            ++dist;
            cnt = 0;
        }
        d = (d + 1) % 4; //서남동북 순 방향 변경
    }
    
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        cin>>n;
        ans = 0;
        vector<vector<int>> a;
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j < n; ++j) {
                int x;
                cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
        cout<<'#'<<t<<' ';
        solution(a); // 모래이동
        cout<<ans<<'\n'; //결과 출력
    }
    return 0;
}
