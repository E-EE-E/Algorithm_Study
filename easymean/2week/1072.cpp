#include <stdio.h>

using namespace std;
long long x, y;
int result;

int getWinRate(long long d, long long n)
{
  return n * 100 / d;
}

int main(void)
{

  scanf("%lld%lld", &x, &y);
  int z = getWinRate(x, y);

  if (z >= 99)
    return !printf("-1\n");

  int start = 1, end = 1000000000;
  while (start <= end)
  {
    int mid = (start + end) / 2;
    int newZ = getWinRate(x + mid, y + mid);
    if (newZ == z)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
      result = mid;
    }
  }

  printf("%d", result);
  return 0;
}