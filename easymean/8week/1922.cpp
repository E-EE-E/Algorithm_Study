/*최소 스패닝 트리 만들기*/
#include <stdio.h>
#include <algorithm>

using namespace std;
const int NODE = 1001;
const int MAX = 100000;
int n, m;

struct edge
{
  int u, v, c;
  bool operator<(const edge &cp) const
  {
    return c < cp.c;
  };
};
edge adj[MAX];
int parent[NODE];

int find(int x)
{
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u != v)
  {
    parent[v] = u;
  }
}
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &adj[i].u, &adj[i].v, &adj[i].c);
  }
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  sort(adj, adj + m);
  int answer = 0;
  for (int i = 0; i < m; i++)
  {
    int u = adj[i].u, v = adj[i].v, c = adj[i].c;
    if (find(u) != find(v))
    {
      answer += c;
      merge(u, v);
    }
  }
  printf("%d", answer);
  return 0;
}