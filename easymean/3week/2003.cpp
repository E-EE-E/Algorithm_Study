/*1 투포인터 */

#include <stdio.h>

using namespace std;
const int MAX = 10000 + 1;

int n, m;
int arr[MAX];
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  int result = 0;
  int l = 0, r = 0;
  int sum = arr[l];
  while (r < n)
  {
    if (sum > m)
    {
      sum -= arr[l++];
    }
    else if (sum < m)
    {
      sum += arr[++r];
    }
    else
    {
      result++;
      sum -= arr[l++];
    }
  }
  printf("%d", result);
  return 0;
}