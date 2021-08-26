#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[1010][1010], b[1010][1010];

bool fn(int x, int y, int l)
{
    int sum = b[x + l - 1][y + l - 1] - b[x + l - 1][y - 1] - b[x - 1][y + l - 1] + b[x - 1][y - 1];
    if (sum == l * l) return true;
    else return false;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &a[i][j]);
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
        }
    }

    //Parametric Search
    int left = 1, right = min(n, m);
    while (left <= right)
    {
        int mid = (left + right) / 2;
        bool chk = false;
        for (int i = 1; i <= n - mid + 1; i++)
        {
            for (int j = 1; j <= m - mid + 1; j++)
            {
                if (fn(i, j, mid)) chk = true;
            }
        }
        if (chk)
        {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    printf("%d", ans * ans);
    return 0;
}
