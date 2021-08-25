#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 3000000 + 1;
const int MAX = 20000 + 1;
int v, e, s;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> adj[MAX];
int dist[MAX];
bool chk[MAX];
int main(void)
{
  scanf("%d%d%d", &v, &e, &s);

  for (int i = 1; i <= v; i++)
  {
    dist[i] = INF;
  }
  dist[s] = 0;
  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({c, b});
  }
  pq.push({0, s});
  while (!pq.empty())
  {
    int x = pq.top().second;
    pq.pop();

    if (chk[x])
      continue;
    chk[x] = 1;
    for (auto a : adj[x])
    {
      int next = a.second, cost = a.first;
      dist[next] = min(dist[next], dist[x] + cost);
      pq.push({-dist[next], next});
    }
  }

  for (int i = 1; i <= v; i++)
  {
    if (dist[i] == INF)
    {
      printf("INF\n");
    }
    else
    {
      printf("%d\n", dist[i]);
    }
  }
  return 0;
}