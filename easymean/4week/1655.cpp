/* 균형잡힌 트리 만들기

전제 조건
1) left는 max heap
2) right는 min heap
3) 0 <= left.size() - right.size() <= 1
4) left 탑에 있는게 무조건 리턴되도록 한다.

알고리즘
1) 첫 입력은 무조건 left에 푸쉬
2) 
if input < left.top then push left
else if right is not empty && input > right.top then push right
else 사이즈를 비교한다.
  if left.size() - right.size() > 1 then push right
  else push left

3) 균형을 맞춰준다.
if left.size() - right.size() > 1, then left -> right
else if right.size() > left.size, then right -> left

*/

#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int> left;
priority_queue<int> right;

int main(void)
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if (left.empty())
    {
      left.push(tmp);
    }
    else
    {
      if (tmp < left.top())
      {
        left.push(tmp);
        if (left.size() - right.size() > 1)
        {
          right.push(-left.top());
          left.pop();
        }
      }
      else if (!right.empty() && tmp > -right.top())
      {
        right.push(-tmp);
        if (right.size() > left.size())
        {
          left.push(-right.top());
          right.pop();
        }
      }
      else
      {
        if (left.size() > right.size())
        {
          right.push(-tmp);
        }
        else
        {
          left.push(tmp);
        }
      }
    }
    printf("%d\n", left.top());
  }
  return 0;
}