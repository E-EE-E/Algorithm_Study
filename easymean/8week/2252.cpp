#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 32000 + 1;
int n, m;
int indegree[MAX];
vector<int> adj[MAX], result;
queue<int> q;
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    indegree[b]++;
  }

  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int front = q.front();
    result.push_back(front);
    q.pop();

    for (auto a : adj[front])
    {
      indegree[a]--;
      if (indegree[a] == 0)
      {
        q.push(a);
      }
    }
  }

  for (int i = 0; i < result.size(); i++)
  {
    printf("%d ", result[i]);
  }
  return 0;
}