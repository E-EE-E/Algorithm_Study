#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 11;

struct pp
{
  int r, c;
} tr, tb;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
char mp[MAX][MAX];
int n, m, result = MAX;

queue<pp> q;

bool isWall(int r, int c)
{
  if (mp[r][c] == '#')
  {
    return true;
  }
  return false;
}

bool isOther(int r, int c)
{
  if (!q.empty() && (q.front().r == r && q.front().c == c))
  {
    return true;
  }
  return false;
}

bool isHole(int r, int c)
{
  if (mp[r][c] == 'O')
  {
    return true;
  }
  return false;
}

pp do_roll(pp cp, int d)
{
  int r = cp.r, c = cp.c;
  // printf("%d %d\n", r, c);
  while (1)
  {

    if (isHole(r, c))
    {
      // printf("%d %d\n", r, c);
      return {r, c};
    }

    if (isWall(r, c) || isOther(r, c))
    {
      r -= dr[d], c -= dc[d];
      return {r, c};
    }

    r += dr[d];
    c += dc[d];
  }
}

bool isSame(pp a, pp b)
{
  if (a.r == b.r && a.c == b.c)
  {
    return true;
  }
  return false;
}

void dfs(int cnt, pp cr, pp cb)
{
  if (cnt >= result)
    return;
  pp nr;
  pp nb;

  for (int i = 0; i < 4; i++)
  {
    memcpy(&nr, &cr, sizeof(pp));
    memcpy(&nb, &cb, sizeof(pp));
    if ((i == 0 && nr.r == nb.r && nr.c < nb.c) || (i == 1 && nr.r == nb.r && nb.c < nr.c) ||
        (i == 2 && nr.c == nb.c && nb.r < nr.r) || (i == 3 && nr.c == nb.c && nr.r < nb.r))
    {
      nb = do_roll(nb, i);
      q.push(nb);
      nr = do_roll(nr, i);
    }
    else
    {
      nr = do_roll(nr, i);
      q.push(nr);
      nb = do_roll(nb, i);
      // printf("b is %d %d\n", nb.r, nb.c);
    }
    q.pop();

    // printf("%d th: r is on (%d, %d) and b is on (%d, %d)\n", cnt, nr.r, nr.c, nb.r, nb.c);

    if (isSame(nr, cr) && isSame(nb, cb))
    {
      continue;
    }

    //빨간 구슬만 구멍에 있다면
    if (isHole(nr.r, nr.c) && !isHole(nb.r, nb.c))
    {
      //printf("%d th: only r is in hole\n", cnt);
      result = result > cnt ? cnt : result;
      return;
    }
    else if (isHole(nb.r, nb.c))
    { //파란 구슬이 구멍이라면
      //printf("%d th: blue is in hole!!!!\n", cnt);
      continue;
    }
    // printf("%d th: r is on (%d, %d) and b is on (%d, %d)\n", cnt, nr.r, nr.c, nb.r, nr.c);

    dfs(cnt + 1, nr, nb);
  }
}

int main(void)
{
  scanf("%d%d", &n, &m);

  char tmp[MAX];

  for (int i = 0; i < n; i++)
  {
    scanf("%s", tmp);
    for (int j = 0; j < m; j++)
    {
      mp[i][j] = tmp[j];
      if (mp[i][j] == 'R')
      {
        tr = {i, j};
      }
      else if (mp[i][j] == 'B')
      {
        tb = {i, j};
      }
    }
  }

  dfs(1, tr, tb);

  if (result == MAX)
  {
    printf("-1");
  }
  else
  {
    printf("%d", result);
  }

  return 0;
}