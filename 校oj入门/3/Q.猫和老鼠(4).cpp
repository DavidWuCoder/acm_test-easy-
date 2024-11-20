#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n, k;
    while(std::cin >> n >> k && (n != -1 && k != -1)){
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1)), g(n, std::vector<int> (n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> g[i][j];
            }
        }

        std::function<int(int, int)> dfs = [&](int x, int y)
        {
            if (dp[x][y])
                return dp[x][y];
            dp[x][y] = g[x][y];
            for (int i = 1; i <= k; i++)
            {
                if (x + i <= n - 1 && g[x + i][y] > g[x][y])
                {
                    dp[x][y] = std::max(dp[x][y], g[x][y] + dfs(x + i, y));
                }
                if (x - i >= 0 && g[x - i][y] > g[x][y])
                {
                    dp[x][y] = std::max(dp[x][y], g[x][y] + dfs(x - i, y));
                }
                if (y + i <= n - 1 && g[x][y + i] > g[x][y])
                {
                    dp[x][y] = std::max(dp[x][y], g[x][y] + dfs(x, y + i));
                }
                if (y - i >= 0 && g[x][y - i] > g[x][y])
                {
                    dp[x][y] = std::max(dp[x][y], g[x][y] + dfs(x, y - i));
                }
            }
            return dp[x][y];
        };
        dfs(0, 0);
        std::cout << dp[0][0] << '\n';
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}