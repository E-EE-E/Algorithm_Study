/*
underflow 발생 위험 때문에 long long을 해줘야 한다.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const long long INF = 60000000 + 1;
int n, m;
vector<pair<int, long long>> adj[501];
long long dist[501];
int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    long long c;
    scanf("%d%d%lld", &a, &b, &c);
    adj[a].push_back(make_pair(b, c));
  }

  for (int i = 2; i <= n; i++)
  {
    dist[i] = INF;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dist[j] == INF)
        continue;
      for (auto p : adj[j])
      {
        long long tmp = min(dist[p.first], dist[j] + p.second);
        if (i < n)
        {
          dist[p.first] = tmp;
        }
        else
        {
          if (dist[p.first] != tmp)
          {
            printf("-1\n");
            return 0;
          }
        }
      }
    }
  }

  for (int i = 2; i <= n; i++)
  {
    if (dist[i] == INF)
    {
      printf("-1\n");
    }
    else
    {
      printf("%lld\n", dist[i]);
    }
  }
  return 0;
}