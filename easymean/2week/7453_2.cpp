#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 4000;
int a[MAX];
int b[MAX];
int c[MAX];
int d[MAX];

int main(void)
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  }

  vector<int> s1;
  vector<int> s2;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      s1.push_back(a[i] + b[j]);
      s2.push_back(c[i] + d[j]);
    }
  }

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  int l1 = s1.size(), l2 = s2.size();
  long long cnt = 0;
  int p1 = 0, p2 = l2 - 1;
  while (p2 >= 0 && p1 < l1)
  {
    int sum = s1[p1] + s2[p2];
    if (sum < 0)
    {
      p1++;
    }
    else if (sum > 0)
    {
      p2--;
    }
    else
    {
      int cnt1 = 1, cnt2 = 1;
      while (++p1 < l1 && s1[p1] == s1[p1 - 1])
      {
        cnt1++;
      }

      while (--p2 >= 0 && s2[p2] == s2[p2 + 1])
      {
        cnt2++;
      }
      cnt += (long long)cnt1 * cnt2;
    }
  }

  printf("%lld", cnt);
  return 0;
}