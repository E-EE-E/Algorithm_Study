#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 100000 + 1;
bool visited[MAX];

struct s
{
  long long age;
  int num;
};
vector<s> adj[MAX];
vector<int> solve(vector<long long> ages)
{
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

  for (int i = 0; i < ages.size(); i++)
  {
    pq.push(make_pair(ages[i], i + 1));
  }

  while (!pq.empty())
  {
    long long c_age = pq.top().first;
    int c_num = pq.top().second;

    pq.pop();
    if (visited[c_num])
      continue;

    visited[c_num] = 1;
    for (auto a : adj[c_num])
    {
      long long n_age = min(ages[a.num], a.age + c_num);
      //이거 빼먹었다
      ages[a.num] = n_age;
      pq.push(make_pair(n_age, a.num));
    }
  }
}