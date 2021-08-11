#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
const int MAX = 1000000 + 1;

string str;
int k, result;
bool visited[MAX];

int toInt(string tmp)
{
  int cur = 0, idx = 0;
  int len = tmp.size();
  while (idx < len)
  {
    cur *= 10;
    cur += (tmp[idx++] - '0');
  }

  return cur;
}

void bfs(string tmp)
{
  queue<string> q;
  q.push(tmp);
  int len = tmp.size();

  int level = 0;
  while (!q.empty())
  {
    if (level > k)
    {
      break;
    }
    memset(visited, 0, sizeof(visited));

    int qs = q.size();
    while (qs--)
    {
      string cs = q.front();

      q.pop();
      for (int i = 0; i < len - 1; i++)
      {
        for (int j = i + 1; j < len; j++)
        {
          string ns = cs;
          swap(ns[i], ns[j]);
          int nn = toInt(ns);

          if (ns[0] == '0' || visited[nn])
            continue;

          if (level == k - 1)
          {
            result = max(result, nn);
          }
          q.push(ns);
          visited[nn] = 1;
        }
      }
    }
    level++;
  }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> str >> k;

  bfs(str);

  if (result == 0)
  {
    cout << -1;
  }
  else
  {
    cout << result;
  }

  return 0;
}