#include <iostream>

using namespace std;

int main() {
	int W, H;

	cin >> W >> H;

	int dp[100][100][4];

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 4; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	for (int w = 0; w < W; w++) {
		dp[0][w][0] = 0;
		dp[0][w][1] = 0;
		dp[0][w][2] = 1;
		dp[0][w][3] = 0;
	}

	for (int h = 1; h < H; h++) {
		dp[h][0][0] = 1;
		dp[h][0][1] = 0;
		dp[h][0][2] = 0;
		dp[h][0][3] = 0;
	}
	dp[0][0][0] = 1;



	/*
		w, h 위치에

		0: 북 -> 북 으로 들어온 경우
		1: 동 -> 북 으로 들어온 경우
		2: 동 -> 동 으로 들어온 경우
		3: 북 ->동 으로 들어온 경우

	*/

	for (int h = 1; h < H; h++) {
		for (int w = 1; w < W; w++) {
			//남->북 으로 들어오는 경우의 수
			dp[h][w][0] = (dp[h - 1][w][0] + dp[h - 1][w][1]) % 100000;
			dp[h][w][1] = dp[h - 1][w][2];


			//동쪽에서 들어오는 경우의 수
			dp[h][w][2] = (dp[h][w - 1][2] + dp[h][w - 1][3] ) % 100000;
			dp[h][w][3] = dp[h][w - 1][0];
		}
	}

	long long sum = (dp[H - 1][W - 1][0] + dp[H - 1][W - 1][1] +dp[H - 1][W - 1][2] + dp[H - 1][W - 1][3]) % 100000;
	cout << sum << endl;
}