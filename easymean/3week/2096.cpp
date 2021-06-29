/*
dp 사용

*/

#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 100000 + 1;
int n;
int dp[3];
int dp2[3];
int main(void)
{
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (i == 0)
    {
      dp[0] = dp2[0] = a;
      dp[1] = dp2[1] = b;
      dp[2] = dp2[2] = c;
    }
    else
    {
      int tmp1 = max(dp[0], dp[1]);
      int tmp2 = max(dp[1], dp[2]);
      dp[1] = max(tmp1, tmp2) + b;
      dp[0] = tmp1 + a;
      dp[2] = tmp2 + c;
      tmp1 = min(dp2[0], dp2[1]);
      tmp2 = min(dp2[1], dp2[2]);
      dp2[1] = min(tmp1, tmp2) + b;
      dp2[0] = tmp1 + a;
      dp2[2] = tmp2 + c;
    }
  }

  int res = max(dp[1], max(dp[0], dp[2]));
  int res2 = min(dp2[1], min(dp2[0], dp2[2]));
  printf("%d %d", res, res2);
  return 0;
}