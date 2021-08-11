#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
const int MAX = 1000 + 1;
int n, m, result;

struct s
{
  int n, c;
};
bool visit[MAX];
vector<s> adj[MAX];
void dfs(int cur, int goal, int cost)
{
  if (visit[cur])
    return;
  visit[cur] = 1;
  if (cur == goal)
  {
    result = cost;
    return;
  }

  for (auto a : adj[cur])
  {
    dfs(a.n, goal, cost + a.c);
  }
  visit[cur] = 0;
}
int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n - 1; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    memset(visit, 0, sizeof(visit));
    scanf("%d%d", &a, &b);
    dfs(a, b, 0);
    printf("%d\n", result);
  }
  return 0;
}