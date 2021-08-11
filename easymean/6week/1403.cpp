#include <stdio.h>
#include <string.h>

using namespace std;
const int MAX = 50;
int n, m;
int r, c, d;
int nr, nc, nd, i;
int arr[MAX + 2][MAX + 2];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main(void)
{
  scanf("%d%d", &n, &m);
  scanf("%d%d%d", &r, &c, &d);
  memset(arr, 1, sizeof(arr));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
  bool flag;
  int cnt = 0;
  while (1)
  {
    if (arr[r][c] == 0)
    {
      arr[r][c] = -1; //청소
      cnt++;
    }

    flag = false;
    for (nd = d - 1, i = 0; i < 4; nd--, i++)
    {
      if (nd < 0)
      {
        nd += 4;
      }
      nr = r + dr[nd];
      nc = c + dc[nd];
      if (arr[nr][nc] == 0)
      {
        d = nd;
        r = nr;
        c = nc;
        flag = true;
        break;
      }
    }
    int br, bc;
    if (!flag)
    {
      br = r - dr[d];
      bc = c - dc[d];

      if (arr[br][bc] == 1)
      {
        break;
      }

      r = br;
      c = bc;
    }
  }

  printf("%d\n", cnt);
  return 0;
}