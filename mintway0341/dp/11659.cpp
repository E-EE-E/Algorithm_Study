#include <bits/stdc++.h>
int n, m, a[100010], b[100010];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", b[y] - b[x - 1]);
    }

    return 0;
}
