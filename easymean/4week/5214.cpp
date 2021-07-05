/*
환승
더미노드를 추가하는 bfs
*/
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100000;
int n, m, k;
vector<int> adj[MAX + 1001];
int visited[MAX + 1001];
int main(void)
{
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 1; i <= k; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      adj[n + i].push_back(tmp);
      adj[tmp].push_back(n + i);
    }
  }

  int result = -1;
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  while (!q.empty())
  {
    int cn = q.front();

    //printf("cur node: %d level: %d\n", cn, cl);
    if (cn == n)
    {
      result = visited[cn];
      break;
    }
    q.pop();
    for (auto a : adj[cn])
    {
      if (visited[a] == 0)
      {
        if (a > n)
          visited[a] = visited[cn];
        else
          visited[a] = visited[cn] + 1;
        q.push(a);
      }
    }
  }

  printf("%d", result);

  return 0;
}