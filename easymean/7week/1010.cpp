#include <stdio.h>
#include <algorithm>
using namespace std;
int t;
int l, r;
long long pascal[31][31];
long long solve(int total, int num)
{
  long long &ret = pascal[total][num];
  if (ret > 0)
    return ret;

  if (total == num || num == 0)
  {
    ret = 1;
  }
  else if (num == 1 || total - 1 == num)
  {
    ret = total;
  }
  else
  {
    ret = solve(total - 1, num) + solve(total - 1, num - 1);
  }
  return ret;
}

int main(void)
{
  scanf("%d", &t);
  pascal[1][0] = pascal[1][1] = 1;
  while (t--)
  {
    scanf("%d%d", &l, &r);
    printf("%lld\n", solve(r, l));
  }
  return 0;
}