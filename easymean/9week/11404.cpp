#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 100;
const long long INF = 10000000000;
long long arr[MAX + 1][MAX + 1];
int n, m;
int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      arr[i][j] = INF;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int a, b;
    long long c;
    scanf("%d%d%lld", &a, &b, &c);
    arr[a][b] = min(arr[a][b], c);
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {
        if (j == k)
          continue;
        arr[j][k] = min(arr[j][i] + arr[i][k], arr[j][k]);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] == INF)
      {
        printf("0 ");
      }
      else
      {
        printf("%lld ", arr[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}