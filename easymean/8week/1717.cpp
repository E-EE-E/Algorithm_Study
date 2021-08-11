#include <stdio.h>

using namespace std;
const int MAX = 1000000 + 1;
int parent[MAX];
int n, m;

int find(int a)
{
  if (a == parent[a])
    return a;
  return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
  a = find(a);
  b = find(b);
  if (a != b)
  {
    parent[b] = a;
  }
}

int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }
  for (int i = 0; i < m; i++)
  {
    int cmd, a, b;
    scanf("%d%d%d", &cmd, &a, &b);
    if (cmd == 0)
    {
      merge(a, b);
    }
    else
    {
      if (find(a) == find(b))
      {
        printf("YES\n");
      }
      else
      {
        printf("NO\n");
      }
    }
  }
  return 0;
}