//visit은 idx의 방문을 표시 -> 깊이 탐색에서 같은 idx는 방문하지 않는다.
//check는 숫자의 방문을 표시 -> 같은 깊이에서 같은 숫자는 방문하지 않는다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000 + 1;
int n, m;
vector<int> v;
int answer[8];
bool visit[8];

void dfs(int cnt)
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
  bool check[MAX] = {
      0,
  };
  for (int i = 0; i < v.size(); i++)
  {
    int next = v[i];
    if (visit[i] || check[next])
    {
      continue;
    }
    visit[i] = check[next] = 1;
    answer[cnt] = next;
    dfs(cnt + 1);
    visit[i] = 0;
  }
}
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());

  dfs(0);
  return 0;
}