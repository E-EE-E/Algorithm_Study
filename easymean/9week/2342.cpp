/*
dance dance revolution
*/
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
const int MAX = 400000 + 1;
int dp1[5][5], dp2[5][5];
int arr[MAX];

int cal(int from, int to)
{
  if (from == to)
  {
    return 1;
  }
  else if (from == 0)
  {
    return 2;
  }
  else if (abs(from - to) == 2)
  {
    return 4;
  }
  else
  {
    return 3;
  }
}
int main(void)
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      dp1[i][j] = MAX;
    }
  }
  dp1[0][0] = 0;
  int prev = 0, cur, answer = MAX;
  while (1)
  {
    scanf("%d", &cur);
    if (cur == 0)
    {
      for (int i = 0; i < 5; i++)
      {
        answer = min(answer, min(dp1[prev][i], dp1[i][prev]));
      }
      printf("%d", answer);
      break;
    }
    for (int i = 0; i < 5; i++)
    {
      dp2[cur][i] = MAX;
      dp2[i][cur] = MAX;
      //printf("%d %d\n", cur, i);
      for (int j = 0; j < 5; j++)
      {
        dp2[cur][i] = min(dp2[cur][i], dp1[j][i] + cal(j, cur));
        dp2[i][cur] = min(dp2[i][cur], dp1[i][j] + cal(j, cur));
        // printf("%d: %d %d\n", j, dp2[cur][i], dp2[i][cur]);
      }
    }

    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        dp1[i][j] = MAX;
      }
    }

    for (int i = 0; i < 5; i++)
    {
      dp1[cur][i] = dp2[cur][i];
      dp1[i][cur] = dp2[i][cur];
      //printf("%d, %d: %d %d\n", cur, i, dp1[i][cur], dp1[cur][i]);
    }
    prev = cur;
  }

  return 0;
}