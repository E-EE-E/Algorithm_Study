#include <stdio.h>
#include <vector>

using namespace std;
int n;
vector<char> v[27];

void preorder(char cur)
{
  if (cur == '.')
    return;

  printf("%c", cur);

  preorder(v[cur - 'A'][0]);
  preorder(v[cur - 'A'][1]);
}

void inorder(char cur)
{
  if (cur == '.')
    return;

  inorder(v[cur - 'A'][0]);
  printf("%c", cur);
  inorder(v[cur - 'A'][1]);
}

void postorder(char cur)
{
  if (cur == '.')
    return;

  postorder(v[cur - 'A'][0]);
  postorder(v[cur - 'A'][1]);
  printf("%c", cur);
}

int main(void)
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    char c, l, r;
    scanf(" %c %c %c", &c, &l, &r);
    v[c - 'A'].push_back(l);
    v[c - 'A'].push_back(r);
  }
  char root = 'A';
  preorder(root);
  printf("\n");

  inorder(root);
  printf("\n");

  postorder(root);
  printf("\n");
  return 0;
}