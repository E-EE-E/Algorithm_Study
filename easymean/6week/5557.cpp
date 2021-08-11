/*
dp[i][j] = i번째에서 합이 j가 되는 경우의 수

dp[i-1][j] + arr[i]<=20 이라면 dp[i][j+arr[i]] += dp[i-1][j]이다.

어차피 이전 배열만 보기 때문에 모두 저장할 필요 없다.
배열 두개만 사용하자. 
*/
#include <iostream>
#include <vector>

using namespace std;

int n, goal;
vector<int> v;
long long dp1[21];
long long dp2[21];
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  goal = v[n - 1];
  dp1[v[0]] = 1;

  for (int i = 1; i <= n - 2; i++)
  {
    for (int j = 0; j <= 20; j++)
    {
      if (j + v[i] <= 20)
      {
        dp2[j + v[i]] += dp1[j];
      }
      if (j - v[i] >= 0)
      {
        dp2[j - v[i]] += dp1[j];
      }
    }

    for (int j = 0; j <= 20; j++)
    {
      dp1[j] = dp2[j];
      dp2[j] = 0;
    }
  }
  cout << dp1[goal] << "\n";
  return 0;
}