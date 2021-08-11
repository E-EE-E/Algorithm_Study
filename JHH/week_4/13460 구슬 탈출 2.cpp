#include<iostream>
#include<tuple>
#include <queue>
#include <climits>
using namespace std;

int N, M,min_val;
char **board;
bool ****visit;

//rx,ry,bx,by, cnt
queue<tuple<int, int,int,int,int>> ball_qu; 

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int BFS() {
	int rx, ry, bx, by, cnt;

	while (!ball_qu.empty())
	{
		

		tie(rx, ry, bx, by, cnt) = ball_qu.front();
		ball_qu.pop();

		if (cnt == 11) { //11 이상 일 경우 제외
			continue;
		}
		for (int i = 0; i < 4; i++) {
			
			bool red_frist = false;
			bool check_continue = false;
			//같은 줄에 있을 때 순서 고려해서. 다른 줄에 있다면 상관 X
			if ((i == 0 && rx < bx) || (i == 1 && rx>bx) || (i == 2 && ry<by) || (i == 3 && ry>by))
				red_frist = true;

			int nx_r = rx + dx[i], ny_r = ry + dy[i];
			int nx_b = bx + dx[i], ny_b = by + dy[i];

			if (red_frist) { //빨간 공 먼저 이동할 경우

				//빨간공 이동, 이동할때 파란공이 같이 빠지면 안됨...
				while (board[nx_r][ny_r] != '#') {
					if (board[nx_r][ny_r] == 'O') {
						check_continue = true;
					}
					nx_r = nx_r + dx[i]; ny_r = ny_r + dy[i];
				}

				nx_r = nx_r - dx[i]; ny_r = ny_r - dy[i];
				
				bool blue_out = false; 

				//파란공 이동
				while (board[nx_b][ny_b] != '#') {
					
					if (board[nx_b][ny_b] == 'O') { // 파란공이 나가는 경우
						blue_out = true; check_continue = true; break;
					}
					if (nx_b == nx_r && ny_b == ny_r) { //빨간 공이 이미 있는 경우, 더 갈 수 없음.
						break;
					}
					nx_b = nx_b + dx[i]; ny_b = ny_b + dy[i];
				}
				nx_b = nx_b - dx[i]; ny_b = ny_b - dy[i];

				if (check_continue) { //푸시하면 안되는 경우 = 빨간공이나 파란공이 나간경우
					if (blue_out == false) { //빨간 공만 나간 경우 최솟값 갱신
						if (cnt < min_val) {
							min_val = cnt;
						}
					}
					continue;
				}
				
			}
			else { //파란공 먼저 이동하는 경우
				
				//파란공 이동				
				while (board[nx_b][ny_b] != '#') {
					if (board[nx_b][ny_b] == 'O') {
						check_continue = true;
						break;
					}

					nx_b = nx_b + dx[i]; ny_b = ny_b + dy[i];
				}
				if (check_continue) {
					continue;
				}
				nx_b = nx_b - dx[i]; ny_b = ny_b - dy[i];
				

				//빨간공 이동
				while (board[nx_r][ny_r] != '#') {
					if (nx_b == nx_r && ny_b == ny_r) { //파란 공이 이미 이동해 있는 경우
						break;
					}

					if (board[nx_r][ny_r] == 'O') {
						if (cnt < min_val) {
							min_val = cnt;
							check_continue = true;
							break;
						}
					}
					nx_r = nx_r + dx[i]; ny_r = ny_r + dy[i];
				}

				if (check_continue) {
					continue;
				}
				nx_r = nx_r - dx[i]; ny_r = ny_r - dy[i];
				
			}
			if (visit[nx_r][ny_r][nx_b][ny_b] == true) //visit 기록 있으면 푸시안함
				continue;
			ball_qu.push(make_tuple(nx_r, ny_r, nx_b, ny_b, cnt + 1));
			visit[nx_r][ny_r][nx_b][ny_b] = true;
		}
	}
	return 0;
}
int main() {
	cin >> N >> M;
	board = new char*[N];

	//빨강공 + 파란공 위치가 중복으로 나타날 수 없음. -> 동시에 두 위치 나타내기 위해 4차원 배열 선언  ^^;;
	visit = new bool***[N];
	
	for (int i = 0; i < N; i++) {
		board[i] = new char[M];
		visit[i] = new bool**[M];
		for (int j = 0; j < M; j++) {
			visit[i][j] = new bool*[N];
			for (int k = 0; k < N; k++) {
				visit[i][j][k] = new bool[M];
			}
		}
	}
	
	//입력 받기 
	int rx, ry, bx, by;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				rx = i; ry = j;
			}

			if (board[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}

	//첫 위치 큐에 푸시 
	visit[rx][ry][bx][by] = true;
	ball_qu.push(make_tuple(rx, ry, bx, by, 1));
	min_val = INT_MAX;
	BFS(); //BFS 시작

	if (min_val == INT_MAX) {
		cout << "-1";
	}
	else {
		cout << min_val;
	}
	

	//동적할당 해제
	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				delete[] visit[i][j][k];
			}
			delete[] visit[i][j];			
		}
		delete[] board[i];
		delete[] visit[i];
	}

	delete[] board;
	delete[] visit;
	

	return 0;
}