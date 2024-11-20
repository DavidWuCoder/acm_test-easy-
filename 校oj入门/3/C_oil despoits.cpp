#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n, m;
    while(std::cin >> n >> m && (n != 0 || m != 0)){
        std::vector<std::vector<char>> g(n, std::vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> g[i][j];
            }
        }
        std::array<int, 8> dx = {0, 1, 1, 1, 0, -1, -1, -1};
        std::array<int, 8> dy = {1, 1, 0, -1, -1, -1, 0, 1};
        std::function<void(int, int)> dfs = [&](int x, int y)
        {
            g[x][y] = '*';
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                {
                    continue;
                }
                if (g[nx][ny] == '@')
                {
                    dfs(nx, ny);
                }
            }
            return;
        };
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == '@')
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        std::cout << ans << '\n';
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