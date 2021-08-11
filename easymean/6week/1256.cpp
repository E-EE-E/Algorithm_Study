/*
next permutation 다돌리면 터짐
조합을 사용한다. -> 파스칼 삼각형 사용
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1000000000 + 1;

int n, m, k, tmp;
vector<char> v;

int pascal[201][201];

int solve(int total, int num)
{
  int &ret = pascal[total][num];
  if (ret > 0)
    return ret;

  if (total == num || num == 0)
  {
    ret = 1;
  }
  else if (num == 1 || total - 1 == num)
  {
    ret = total;
  }
  else
  {
    ret = min(solve(total - 1, num) + solve(total - 1, num - 1), MAX);
  }
  return ret;
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;

  pascal[0][0] = pascal[1][0] = pascal[1][1] = 1;
  int cnt_a = n, cnt_z = m;
  if (solve(cnt_a + cnt_z, cnt_a) < k)
  {
    cout << -1;
    return 0;
  }

  while (cnt_a + cnt_z > 0)
  {
    if (cnt_a == 0)
    {
      v.push_back('z');
      cnt_z--;
    }
    else if (cnt_z == 0)
    {
      v.push_back('a');
      cnt_a--;
    }
    else
    {
      tmp = solve(cnt_a + cnt_z - 1, cnt_a - 1);
      if (tmp >= k)
      {
        v.push_back('a');
        cnt_a--;
      }
      else
      {
        v.push_back('z');
        k -= tmp;
        cnt_z--;
      }
    }
  }

  for (auto a : v)
    cout << a;

  return 0;
}