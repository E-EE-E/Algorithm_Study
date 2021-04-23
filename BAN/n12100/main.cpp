//1. 5번의 이동을 위해 방향 상하좌우(4가지) 중 하나를 골라 얻을 수 있는 모든 방법 구하기
// L 2. 시뮬레이션 하기 (각 이동마다 1번씩 합치기)
//   L 3. 각 이동마다 while문 한칸씩이동하기 무한반복 - 더이상 이동없을 때까지
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
const int max_move = 5;
vector<vector<pair<int, bool>>> board;
vector<int> dir;
bool moving(int d, vector<vector<pair<int, bool>>> &a) {
    bool ismoving = false;
    if(d == 0) {
        for(int j = 1; j < n; ++j) {
            for(int i = 0; i < n; ++i) {//왼쪽부터 행 먼저 쭉 읽고 옆 열로 이동
                if(a[i][j].first == 0) continue;
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(a[nx][ny].first == 0) {
                    swap(a[nx][ny], a[i][j]);
                    ismoving = true;
                } else if(a[nx][ny].first == a[i][j].first) {
                    if(a[nx][ny].second == false && a[i][j].second == false) {
                        a[nx][ny].first += a[i][j].first;
                        a[i][j].first = 0;
                        a[nx][ny].second = true;
                        ismoving = true;
                    }
                }
            }
        }
    } else if(d == 1) {
        for(int j = n-2; j >= 0; --j) {//for(int j = n-2; j >= 1; --j) 같은 실수 주의하자
            for(int i = 0; i < n; ++i) {
                if(a[i][j].first == 0) continue;
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(a[nx][ny].first == 0) {
                    swap(a[nx][ny], a[i][j]);
                    ismoving = true;
                } else if(a[nx][ny].first == a[i][j].first) {
                    if(a[nx][ny].second == false && a[i][j].second == false) {
                        a[nx][ny].first += a[i][j].first;
                        a[i][j].first = 0;
                        a[nx][ny].second = true;
                        ismoving = true;
                    }
                }
            }
        }

    } else if(d == 2) {
        for(int i = n-2; i >= 0; --i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j].first == 0) continue;
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(a[nx][ny].first == 0) {
                    swap(a[nx][ny], a[i][j]);
                    ismoving = true;
                } else if(a[nx][ny].first == a[i][j].first) {
                    if(a[nx][ny].second == false && a[i][j].second == false) {
                        a[nx][ny].first += a[i][j].first;
                        a[i][j].first = 0;
                        a[nx][ny].second = true;
                        ismoving = true;
                    }
                }
            }
            
        }
    } else if(d == 3) {
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j].first == 0) continue;
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(a[nx][ny].first == 0) {
                    swap(a[nx][ny], a[i][j]);
                    ismoving = true;
                } else if(a[nx][ny].first == a[i][j].first) {
                    if(a[nx][ny].second == false && a[i][j].second == false) {
                        a[nx][ny].first += a[i][j].first;
                        a[i][j].first = 0;
                        a[nx][ny].second = true;
                        ismoving = true;
                    }
                }
            }
        }
    }
    return ismoving;
}
int solution(vector<vector<pair<int, bool>>> a) {
    for(int k = 0; k < dir.size(); ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                a[i][j].second = false;
            }
        }
        int d = dir[k];
        bool ok = true;
        while(true) {
            ok = moving(d, a);
            if(!ok) break;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j].first == 0) continue;
            int temp = a[i][j].first;
            if(ans < temp)
                ans = temp;
        }
    }
    return ans;
}
int go(int index, int pdir) {
    if(index == max_move) {
        return solution(board);
    }

    int ans = -1;
    for(int i = 0; i < 4; ++i) { //4가지 모든 방향 선택가능(같은 방향 연속이동도 값을 변화시키므로 의미있음)
        dir.push_back(i);
        int temp = go(index+1, i);
        if(ans < temp) ans = temp;
        dir.pop_back();
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        board.clear();
        cin>> n;
        for(int i = 0; i < n; ++i) {
            vector<pair<int, bool> > temp;
            for(int j =0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back({x, false});
            }
            board.push_back(temp);
        }
        cout<<'#'<<t<<' ';
        cout<<go(0, -1)<<'\n';
    }
    return 0;
}
