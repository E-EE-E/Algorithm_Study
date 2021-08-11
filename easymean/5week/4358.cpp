#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;
map<string, int> mp;
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  long long sum = 0;
  while (getline(cin, s))
  {
    mp[s]++;
    sum++;
  }

  for (auto a : mp)
  {
    cout << a.first << " ";
    int cnt = a.second;
    double tmp = (double)1L * cnt * 1000000 / sum;
    double ratio = round(tmp);
    cout.precision(4);
    cout << fixed << ratio / 10000 << "\n";
  }

  return 0;
}