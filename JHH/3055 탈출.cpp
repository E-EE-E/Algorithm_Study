#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>

using namespace std;

char **grid;
bool **visit;
int R, C;
queue<pair<int, int>> qu;
queue<pair<int, int>> doChi_qu;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool waterSpread() {
	int x, y;
	int newX, newY;
	int thisTime = qu.size();
	while (thisTime--)
	{
			
		tie(x, y) = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			
			newX = x + dx[i];
			newY = y + dy[i];

			if (newX < 0 || newX >= R || newY < 0 || newY >= C || 
				grid[newX][newY]=='X'|| grid[newX][newY] == '*' || grid[newX][newY] == 'D')
				continue;
			
			grid[newX][newY] = '*';
			qu.push(make_pair(newX, newY)); // 갈 수 있으면 푸시
		}
	}

	/*
	cout << endl << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << grid[i][j] <<" ";
		}
		cout << endl;
	}
	cout << endl<<endl;
	*/
	return true;
}

/*
	0 : 탈출불가
	1 : 이동 성공
	2 : 비버굴에 도착
*/
int dochi_Moving() {
	int x, y;
	int newX, newY;
	int thisTime = doChi_qu.size(); //이번 시간에만 이동,,,!
	while (thisTime--)
	{
		tie(x, y) = doChi_qu.front();
		doChi_qu.pop();
		
		for (int i = 0; i < 4; i++) {
			
			newX = x + dx[i];
			newY = y + dy[i];

			if (newX < 0 || newX >= R || newY < 0 || newY >= C || visit[newX][newY] == true ||
				grid[newX][newY] == 'X' || grid[newX][newY] == '*')
				continue;

			if (grid[newX][newY] == 'D')
				return 2;
			
			doChi_qu.push(make_pair(newX, newY)); // 갈 수 있으면 푸시
			visit[newX][newY] = true;
		}
	}

	if (doChi_qu.empty()) { //새롭게 갈 수 있는 길 없음 
		return 0;
	}

	return 1;

	return true;
}


int moving_min() {
	int result = 1;
	int min = 0;
	while (result == 1) {
		min += 1;
		waterSpread(); //물은 먼저 퍼져나감
		result = dochi_Moving(); //고슴도치 이동 BFS
		if (result == 2) { //비버굴에 도착한 경우
			return min;
		}
	}

	return -1;
}


int main() {
	cin >> R >> C;

	grid = new char*[R];
	visit = new bool*[R];

	for (int i = 0; i < R; i++) {
		grid[i] = new char[C];
		visit[i] = new bool[C];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == '*') {
				qu.push(make_pair(i, j));
			}
			if (grid[i][j] == 'S') {
				doChi_qu.push(make_pair(i, j));
			}
		}
	}
	int ans = moving_min();

	if (ans == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << ans;
	}


	for (int i = 0; i < R; i++) {
		delete grid[i];
		delete visit[i];
	}
	delete grid, visit;
}