#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
int N,M;
int **grid;
int cnt;
int curX, curY, curDirection;

void clean(int x,int y) {
	cnt++;
	grid[x][y] = 2;
}

bool isFullAllDirection(int x, int y) {
	return grid[x - 1][y] != 0 && grid[x][y - 1] != 0 && grid[x][y + 1] != 0 && grid[x + 1][y] != 0;
}

bool moveLeft(int d,int x, int y) {
	int nx, ny;
	int newD;
	
	if (curDirection == 0) {
		nx = curX;
		ny = curY - 1;
		newD = 3;
	}
	else if (curDirection == 1) {
		nx = curX - 1;
		ny = curY;
		newD = 0;
	}
	else if (curDirection == 2) {
		nx = curX;
		ny = curY + 1;
		newD = 1;
	}
	else if (curDirection == 3) {
		nx = curX+1;
		ny = curY;
		newD = 2;
	}

	if (grid[nx][ny] == 0) //왼쪽방향에 비어있으면
	{
		clean(nx, ny);
		curX = nx;
		curY = ny;
		curDirection = newD;
		return true;
	}
	else {
		return false;
	}

}

void turnLeft(int d, int x, int y) {
	int nx, ny;
	int newD;

	if (d == 0) {
		newD = 3;
	}
	else if (d == 1) {
		newD = 0;
	}
	else if (d == 2) {
		newD = 1;
	}
	else if (d == 3) {
		newD = 2;
	}

	curDirection = newD;
	

}

bool moveBack() {

	int nx=curX, ny=curY;
	if (curDirection == 0) {
		nx = curX+1;
		ny = curY;
	}
	else if (curDirection == 1) {
		nx = curX ;
		ny = curY-1;
	}
	else if (curDirection == 2) {
		nx = curX - 1;
		ny = curY;
	}
	else if (curDirection == 3) {
		nx = curX ;
		ny = curY+1;
	}

	if (grid[nx][ny] == 1) { //뒤가 벽일때
		return false;
	}
	else { //뒤로 갈 수 있을 때
		curX = nx;
		curY = ny;
		return true;
	}
}



int main() {
	
	cin >> N >> M;

	grid = new int*[N];
	for (int i = 0; i < N; i++) {
		grid[i] = new int[M];
	}
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}


	cnt = 0;
	curX = r, curY = c;
	curDirection = d;
	clean(curX, curY);

	while (1) {
		if (!moveLeft(curDirection,curX,curY)) //왼쪽 실패하면
		{
			if (!isFullAllDirection(curX,curY)) //네 방향 다 못가는게 아니면
			{
				turnLeft(curDirection, curX, curY);
			}
			else {
				if (!moveBack()) { //뒤로도 못가면
					break;
				}
			}
		}
		
	}

	cout << cnt;
	
	for (int i = 0; i < N; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}