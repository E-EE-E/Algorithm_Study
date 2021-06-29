#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 1000000;
int arr[MAX];
int main(void)
{
  int n, m;
  scanf("%d%d", &n, &m);
  int left = 0, right = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    right = max(right, arr[i]);
  }
  int result = 0;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
      total += max(0, arr[i] - mid);
    }

    if (total >= m)
    {
      left = mid + 1;
      result = mid;
    }
    else
    {
      right = mid - 1;
    }
  }

  printf("%d", result);

  return 0;
}