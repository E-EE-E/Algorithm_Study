#include <bits/stdc++.h>
int m, lena, lenb, dp[4010][4010];
char a[4010], b[4010];

int main()
{
    scanf("%s", a);
    scanf("%s", b);
    lena = strlen(a);
    lenb = strlen(b);
    for (int i = 0; i < lena; i++)
    {
        if (a[i] == b[0]) dp[i][0] = 1;
        else dp[i][0] = -1;
    }
    for (int i = 0; i < lenb; i++)
    {
        if (a[0] == b[i]) dp[0][i] = 1;
        else dp[0][i] = -1;
    }
    for (int i = 1; i < lena; i++)
    {
        for (int j = 1; j < lenb; j++)
        {
            if (a[i] != b[j]) dp[i][j] = -1;
            else if (dp[i - 1][j - 1] != -1) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = 1;

            if (dp[i][j] > m) m = dp[i][j];
        }
    }
    printf("%d", m);

    return 0;
}

