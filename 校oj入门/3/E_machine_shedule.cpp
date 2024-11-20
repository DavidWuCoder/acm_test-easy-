#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n, m, k;
    while(std::cin >> n >> m >> k && (n != 0))
    {
        std::vector<std::vector<int>> G(n, std::vector<int>(m));
        for (int i = 0; i < k; i++)
        {
            int t, a, b;
            std::cin >> t >> a >> b;
            if (a && b)
            G[a][b] = 1;
        }
        std::vector<int> vis(m);
        std::vector<int> match(m);
        std::function<bool(int x)> dfs = [&](int x)
        {
            for (int i = 0; i < m; i++)
            {
                if (!vis[i] && G[x][i])
                {
                    vis[i] = 1;
                    if (!match[i] || dfs(match[i]))
                    {
                        match[i] = x;
                        return true;
                    }
                }
            }
            return false;
        };

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            std::vector<int>(m).swap(vis);
            if (dfs(i))
                sum++;
            
        }
        std::cout << sum << '\n';
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