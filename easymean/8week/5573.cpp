/*
dp[r][c] = r,c를 방문하는 횟수
*/
#include <stdio.h>

using namespace std;
const int MAX = 1000 + 1;
int h, w, n;
int arr[MAX][MAX];
int dp[MAX][MAX];
int main(void)
{
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  //첫번째 칸은 무조건 n-1번 방문
  dp[1][1] = n - 1;

  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      int tmp = dp[i][j];
      dp[i + 1][j] += tmp / 2;
      dp[i][j + 1] += tmp / 2;
      //짝수번 방문이면 우, 하 방향 모두 반씩
      //홀수번 방문이면 input이 영향줌
      if (tmp & 1)
      {
        if (arr[i][j])
        {
          dp[i][j + 1]++;
        }
        else
        {
          dp[i + 1][j]++;
        }
      }
    }
  }

  //n번째 방문 경로 탐색
  int r = 1, c = 1;
  while (r <= h && c <= w)
  {
    //방향 전환
    if (dp[r][c] & 1)
    {
      if (arr[r][c])
      {
        r++;
      }
      else
      {
        c++;
      }
    }
    else
    {
      if (arr[r][c])
      {
        c++;
      }
      else
      {
        r++;
      }
    }
  }

  printf("%d %d", r, c);
  return 0;
}