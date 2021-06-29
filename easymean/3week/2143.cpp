#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int t, n1, n2, tmp;
vector<int> a;
vector<int> b;
int main(void)
{
  scanf("%d", &t);
  scanf("%d", &n1);

  //누적합 구하기
  int prev = 0;
  for (int i = 0; i < n1; i++)
  {
    scanf("%d", &tmp);
    a.push_back(prev + tmp);
    prev = a[i];
  }

  scanf("%d", &n2);
  prev = 0;
  for (int i = 0; i < n2; i++)
  {
    scanf("%d", &tmp);
    b.push_back(prev + tmp);
    prev = b[i];
  }

  for (int i = 1; i < n1; i++)
  {
    for (int j = 0; j < i; j++)
    {
      a.push_back(a[i] - a[j]);
    }
  }

  for (int i = 1; i < n2; i++)
  {
    for (int j = 0; j < i; j++)
    {
      b.push_back(b[i] - b[j]);
    }
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int len1 = a.size(), len2 = b.size();
  int l = 0, r = len2 - 1;
  long long cnt = 0;
  while (l < len1 && r > -1)
  {
    int sum = a[l] + b[r];
    if (sum < t)
    {
      l++;
    }
    else if (sum > t)
    {
      r--;
    }
    else
    {
      int cnt1 = 1, cnt2 = 1;
      while (++l < len1 && a[l] == a[l - 1])
      {
        cnt1++;
      }
      while (--r > -1 && b[r] == b[r + 1])
      {
        cnt2++;
      }
      cnt += 1L * cnt1 * cnt2;
    }
  }

  printf("%lld", cnt);
  return 0;
}