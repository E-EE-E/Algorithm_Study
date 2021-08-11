#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int MAX = 501;
int n, m;
vector<int> adj[MAX];
int in[MAX], out[MAX];
bool visited[MAX];
int dfs(int cur)
{
  int result = 0;
  visited[cur] = 1;
  for (int a : adj[cur])
  {
    if (visited[a])
      continue;
    in[a]++;
    result += dfs(a) + 1;
  }
  return result;
}
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d%d", &from, &to);
    adj[from].push_back(to);
  }

  for (int i = 1; i <= n; i++)
  {
    memset(visited, 0, sizeof(visited));
    out[i] = dfs(i);
  }
  int answer = 0;
  for (int i = 1; i <= n; i++)
  {
    if (in[i] + out[i] == n - 1)
    {
      answer++;
    }
  }
  printf("%d", answer);
  return 0;
}