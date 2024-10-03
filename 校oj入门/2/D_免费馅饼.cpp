#include <stdio.h>
#include <algorithm>
#include <string.h>

int dp[100050][20];

signed main()
{
    int n, x, t;
    int sup = 0;
    while (~scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &x, &t);
            dp[t][x]++;
            sup = std::max(sup, t);
        }
        for (int i = sup - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 10; j++)
            {
                dp[i][j] = std::max(dp[i + 1][j], std::max(dp[i + 1][j + 1], dp[i + 1][j - 1])) + dp[i][j];
            }
        }
        printf("%d\n", dp[0][5]);
    }
    return 0;
}