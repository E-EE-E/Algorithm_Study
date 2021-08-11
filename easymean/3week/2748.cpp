/*브론즈 피보나치 수열 dp*/
#include <stdio.h>

using namespace std;
const int MAX = 91;
long long dp[MAX];
int main(void)
{
  int n;
  scanf("%d", &n);

  dp[0] = 0, dp[1] = 1, dp[2] = 1;

  for (int i = 3; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  printf("%lld", dp[n]);
  return 0;
}