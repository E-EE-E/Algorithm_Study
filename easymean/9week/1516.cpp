#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 500;
int dist[MAX + 1], indegree[MAX + 1], n, result[MAX + 1];
vector<int> adj[MAX + 1];
queue<int> q;
int main(void)
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &dist[i]);
    while (1)
    {
      int bef;
      scanf("%d", &bef);
      if (bef == -1)
        break;
      indegree[i]++;
      adj[bef].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
    result[i] = dist[i];
  }

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int next : adj[x])
    {
      indegree[next]--;
      result[next] = max(result[next], result[x] + dist[next]);
      if (indegree[next] == 0)
      {
        q.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    printf("%d\n", result[i]);
  }
  return 0;
}