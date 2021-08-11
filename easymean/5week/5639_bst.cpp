//binary search tree
#include <stdio.h>

using namespace std;
int arr[10000];

void recursivePrint(int left, int right)
{
  if (left > right)
  {
    return;
  }

  int root = arr[left];
  int mid = right;
  while (arr[mid] > root)
    mid--;
  recursivePrint(left + 1, mid);
  recursivePrint(mid + 1, right);
  printf("%d\n", root);
}
int main(void)
{
  freopen("input.txt", "r", stdin);
  int i = 0;
  int tmp;
  while (scanf("%d", &tmp) != -1)
  {
    arr[i++] = tmp;
  }
  recursivePrint(0, i - 1);
  return 0;
}