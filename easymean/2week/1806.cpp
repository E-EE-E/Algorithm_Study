#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 100000;
int arr[MAX];
int main(void)
{
  int n;
  long long s;
  scanf("%d%lld", &n, &s);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int l = 0, r = 0;
  long long sum = arr[0];
  int result = MAX + 1;
  while (r < n)
  {
    if (sum < s)
    {
      sum += arr[++r];
    }
    else
    {
      result = min(result, r - l + 1);
      sum -= arr[l++];
    }
  }

  if (result == MAX + 1)
  {
    result = 0;
  }
  printf("%d", result);
  return 0;
}