
/*파스칼 삼각형 사용하면 터짐*/
#include <iostream>
#include <vector>

using namespace std;
int n, m, k;
vector<int> cnt;
int main(void)
{
  cin >> m;
  int total = 0;
  for (int i = 1; i <= m; i++)
  {
    int tmp;
    cin >> tmp;
    cnt.push_back(tmp);
    total += tmp;
  }

  cin >> k;

  double res = 0;
  for (int a : cnt)
  {
    if (a < k)
      continue;

    double tmp = 1.0;
    for (int i = 0; i < k; i++)
    {
      tmp *= (double)(a - i) / (total - i);
    }
    res += tmp;
  }
  cout << fixed;
  cout.precision(11);
  cout << res;
  return 0;
}