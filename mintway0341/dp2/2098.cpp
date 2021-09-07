#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, w[30][30], dp[(1 << 16) + 10][20];
ll ans = (ll)1e18;

int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            scanf("%lld", &w[i][j]);
        }
    }
    for (ll i = 0; i < (1 << n); i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if ((i & 1) == 0 || (i & (1 << j)) == 0) dp[i][j] = (ll)1e18;
            else
            {
                ll mi = (ll)1e18;
                for (ll k = 0; k < n; k++)
                {
                    if ((i & (1 << k)) && (j != k) && w[k][j])
                    {
                        mi = min(mi, dp[i - (1 << j)][k] + w[k][j]);
                    }
                }
                if (mi != (ll)1e18) dp[i][j] = mi;
                else if (i == 1) dp[i][j] = 0;
                else dp[i][j] = (ll)1e18;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        ll tmp = dp[(1 << n) - 1][i];
        if (tmp != -1 && w[i][0] != 0)
        {
            ans = min(ans, tmp + w[i][0]);
        }
    }
    printf("%lld", ans);

    return 0;
}
