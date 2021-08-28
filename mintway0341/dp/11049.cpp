//재귀 풀이
#include <bits/stdc++.h>
typedef long long ll;
ll n, r[510], c[510], dp[510][510];

ll fn(ll x, ll y)
{
    if (dp[x][y]) return dp[x][y];
    if (x >= y) return dp[x][y] = 0;
    if (x + 1 == y) return dp[x][y] = r[x] * c[x] * c[y];

    ll mi = (ll)1e18;
    for (ll i = x; i < y; i++)
    {
        ll tmp = fn(x, i) + fn(i + 1, y) + r[x] * c[i] * c[y];
        if (tmp < mi) mi = tmp;
    }

    return dp[x][y] = mi;
}

int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &r[i], &c[i]);
    }
    printf("%lld", fn(1, n));

    return 0;
}


//for문 풀이
//#include <bits/stdc++.h>
//typedef long long ll;
//ll n, r[510], c[510], dp[510][510];
//
//int main()
//{
//    scanf("%lld", &n);
//    for (ll i = 1; i <= n; i++)
//    {
//        scanf("%lld %lld", &r[i], &c[i]);
//    }
//    for (ll i = 0; i < n; i++)
//    {
//        for (ll j = 1; i + j <= n; j++)
//        {
//            ll x = j, y = i + j;
//            if (x >= y) dp[x][y] = 0;
//            else if (x + 1 == y) dp[x][y] = r[x] * c[x] * c[y];
//            else
//            {
//                ll mi = (ll)1e18;
//                for (ll k = x; k < y; k++)
//                {
//                    ll tmp = dp[x][k] + dp[k + 1][y] + r[x] * c[k] * c[y];
//                    if (tmp < mi) mi = tmp;
//                }
//                dp[x][y] = mi;
//            }
//        }
//    }
//    printf("%lld", dp[1][n]);
//
//    return 0;
//}
