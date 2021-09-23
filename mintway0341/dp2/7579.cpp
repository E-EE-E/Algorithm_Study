#include <bits/stdc++.h>
using namespace std;
int n, m, ans, b[110], c[110], dp[10010][110];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i <= 100 * n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i < c[j]) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = max(dp[i][j - 1], dp[i - c[j]][j - 1] + b[j]);
        }
    }
    for (int i = 0; i <= 100 * n; i++)
    {
        if (dp[i][n] >= m)
        {
            ans = i;
            break;
        }
    }
    printf("%d", ans);

    return 0;
}


