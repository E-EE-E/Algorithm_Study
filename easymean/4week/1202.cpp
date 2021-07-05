#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;
struct s
{
  int w, v;
};

bool cmp(const s &t1, const s &t2)
{
  if (t1.w == t2.w)
  {
    return t1.v > t2.v;
  }
  return t1.w < t2.w;
}
vector<s> js;
vector<int> bag;
int main(void)
{
  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; i++)
  {
    int w, v;
    scanf("%d%d", &w, &v);
    js.push_back({w, v});
  }
  for (int i = 0; i < k; i++)
  {
    int a;
    scanf("%d", &a);
    bag.push_back(a);
  }
  sort(js.begin(), js.end(), cmp);
  sort(bag.begin(), bag.end());

  priority_queue<int> pq;
  int idx = 0;
  long long result = 0;
  for (int i = 0; i < k; i++)
  {
    int limit = bag[i];
    while (idx < n && js[idx].w <= limit)
    {
      pq.push(js[idx++].v);
    }

    if (!pq.empty())
    {
      result += pq.top();
      pq.pop();
    }
  }

  printf("%lld", result);
  return 0;
}