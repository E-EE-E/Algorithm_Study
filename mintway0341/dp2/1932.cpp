#include <bits/stdc++.h>
using namespace std;
int n, ans, a[510][510], sum[510][510];

int fn(int x)
{

}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    sum[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum[i][j] = max(sum[i - 1][j], sum[i - 1][j - 1]) + a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans < sum[n - 1][i]) ans = sum[n - 1][i];
    }
    printf("%d", ans);

    return 0;
}
