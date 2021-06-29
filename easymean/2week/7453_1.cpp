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
      s1.push_back(-(a[i] + b[j]));
      s2.push_back(c[i] + d[j]);
    }
  }

  sort(s2.begin(), s2.end());

  long long result = 0;

  for (int i = 0; i < s1.size(); i++)
  {
    int goal = s1[i];
    int ub = upper_bound(s2.begin(), s2.end(), goal) - s2.begin();
    int lb = lower_bound(s2.begin(), s2.end(), goal) - s2.begin();
    result += ub - lb;
  }
  printf("%lld", result);
  return 0;
}