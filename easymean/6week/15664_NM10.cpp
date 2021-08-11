#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 10000 + 1;
int n, m;
vector<int> v;
int answer[8];
void dfs(int idx, int cnt)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << answer[i] << " ";
    }
    cout << "\n";
    return;
  }
  bool visit[MAX] = {
      0,
  };
  for (int i = idx; i < n; i++)
  {
    int next = v[i];
    if (visit[next])
      continue;
    visit[next] = 1;
    answer[cnt] = next;
    dfs(i + 1, cnt + 1);
  }
}
int main(void)
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());
  dfs(0, 0);
  return 0;
}