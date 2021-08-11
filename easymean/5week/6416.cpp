/*
트리인지 확인하기
1. 루트 노드가 존재(indegree 없음)
2. 루트노드를 제외한 나머지는 무조건 indegree가 하나 이상
3. 루트에서 다른 노드로 가는 경로가 유일 
*/
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>

using namespace std;
const int MAX = 100000 + 1;

int u, v, r, ind[MAX], visited[MAX];
bool flag = true;
set<int> ns;
vector<int> adj[MAX];

void check()
{
  int cnt = 0;
  for (auto a : ns)
  {
    if (ind[a] == 0)
    {
      if (r > -1)
      {
        //루트 노드가 2개 이상이라면
        // printf("two root\n");
        flag = false;
        return;
      }
      r = a;
    }
    else if (ind[a] >= 2)
    {
      //printf("dup path\n");
      flag = false;
      return;
    }
  }
  if (r == -1 && ns.size() > 0) //루트 노드가 없다면
  {
    // printf("no root node\n");
    flag = false;
    return;
  }

  return;
}

void check2()
{
  if (!flag)
    return;

  queue<int> q;
  q.push(r);
  visited[r] = 1;
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();

    for (int nn : adj[cur])
    {
      ind[nn]--;
      if (ind[nn] == 0)
      {
        q.push(nn);
        visited[nn] = 1;
      }
    }
  }

  for (auto a : ns)
  {
    if (visited[a] == 0)
    {
      // printf("cannot arrive\n");
      flag = false;
      return;
    }
  }
  return;
}

void print(int t)
{
  printf("Case %d is ", t);
  if (flag)
  {
    printf("a tree.\n");
  }
  else
  {
    printf("not a tree.\n");
  }
}

int main(void)
{
  int t = 1;
  while (1)
  {
    scanf("%d%d", &u, &v);
    if (u < 0 && v < 0)
      break;
    else if (u == 0 && v == 0)
    {
      r = -1;
      flag = true;
      check();
      check2();
      print(t);
      /*트리 초기화*/
      t++;
      for (auto a : ns)
      {
        adj[a].clear();
        visited[a] = 0;
        ind[a] = 0;
      }
      ns.clear();
    }
    else
    {
      ns.insert(u);
      ns.insert(v);
      ind[v]++;
      adj[u].push_back(v);
    }
  }
  return 0;
}