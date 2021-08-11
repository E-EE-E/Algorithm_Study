#include <stdio.h>
#include <math.h>
/*
모든 무게 경우의 수를 찾기
a >=b일 경우 a b a+b a-b모두 가능하다.
*/

using namespace std;
const int MAX = 40000 + 1;
int n, m;
bool dp[31][MAX];
int main(void)
{
  scanf("%d", &n);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    int cur;
    scanf("%d", &cur);
    for (int j = 0; j < MAX; j++)
    {
      /*
      현재 무게가 cur일때 무게 j를 만들 수 있다
     = cur포함 x. 이전 단계에서 j이 존재한다.
     = cur포함 o. 이전 단계에서 j-cur이 존재한다.
     = cur포함 o. 이전 단계에서 j+cur이 존재한다.
      */
      dp[i][j] = dp[i - 1][j] || dp[i - 1][abs(j - cur)];
      if (j + cur < MAX)
        dp[i][j] = dp[i][j] || dp[i - 1][j + cur];
    }
  }

  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if (dp[n][tmp])
      printf("Y ");
    else
      printf("N ");
  }

  return 0;
}