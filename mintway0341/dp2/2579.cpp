#include <bits/stdc++.h>
using namespace std;
int n, a[310], b[310][5];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    b[0][1] = a[0];
    b[0][2] = 0;
    b[1][1] = a[1];
    b[1][2] = a[0] + a[1];
    for (int i = 2; i < n; i++)
    {
        b[i][1] = max(b[i - 2][1], b[i - 2][2]) + a[i];
        b[i][2] = b[i - 1][1] + a[i];
    }
    printf("%d", max(b[n - 1][1], b[n - 1][2]));
    return 0;
}
