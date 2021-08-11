/*개똥벌레*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 500000;
int n, h;
int up[MAX + 1];
int down[MAX + 1];

vector<int> total;

int main(void)
{
  scanf("%d%d", &n, &h);

  for (int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if (i & 1)
    {
      up[h - tmp + 1]++; //위
    }
    else
    {
      down[tmp]++; //아래
    }
  }

  for (int i = h; i > 0; i--)
  {
    down[i - 1] += down[i];
  }

  for (int i = 0; i < h; i++)
  {
    up[i + 1] += up[i];
  }
  for (int i = 1; i <= h; i++)
  {
    total.push_back(down[i] + up[i]);
  }

  sort(total.begin(), total.end());
  int answer = total[0], cnt = 1;
  for (int i = 1; i < total.size(); i++)
  {
    if (answer == total[i])
      cnt++;
    else
      break;
  }

  printf("%d %d", answer, cnt);

  return 0;
}