/*
dp[r][c][현재 방향][현재 턴 여부]
 */
#include <stdio.h>

using namespace std;
const int MAX = 101;
const int STAY = 0;
const int TURN = 1;
const int DOWN = 0;
const int RIGHT = 1;
const int MOD = 100000;

int w, h;
int dp[MAX][MAX][2][2];
int main(void)
{
  scanf("%d%d", &w, &h);

  for (int i = 2; i <= h; i++)
  {
    dp[i][1][DOWN][STAY] = 1;
  }

  for (int i = 2; i <= w; i++)
  {
    dp[1][i][RIGHT][STAY] = 1;
  }

  for (int i = 2; i <= h; i++)
  {
    for (int j = 2; j <= w; j++)
    {
      dp[i][j][DOWN][STAY] = (dp[i - 1][j][DOWN][STAY] + dp[i - 1][j][DOWN][TURN]) % MOD;
      dp[i][j][RIGHT][STAY] = (dp[i][j - 1][RIGHT][STAY] + dp[i][j - 1][RIGHT][TURN]) % MOD;
      dp[i][j][DOWN][TURN] = dp[i - 1][j][RIGHT][STAY] % MOD;
      dp[i][j][RIGHT][TURN] = dp[i][j - 1][DOWN][STAY] % MOD;
    }
  }
  int answer = 0;
  for (int i = 0; i <= 1; i++)
  {
    for (int j = 0; j <= 1; j++)
    {
      answer += dp[h][w][i][j];
    }
  }
  printf("%d\n", answer % MOD);
  return 0;
}