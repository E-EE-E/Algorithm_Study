#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int> q;
int n;
int main(void)
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if (tmp == 0)
    {
      if (!q.empty())
      {
        printf("%d\n", -q.top());
        q.pop();
      }
      else
      {
        printf("0\n");
      }
    }
    else
    {
      q.push(-tmp);
    }
  }
  return 0;
}