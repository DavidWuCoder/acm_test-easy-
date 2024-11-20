#include <bits/stdc++.h>
using ll = long long;

struct node
{
    int x, y, s;
};

void solve(int &T)
{
    int n, m;
    while(std::cin >> n >> m){
        std::vector<std::vector<char>> g(n, std::vector<char>(m));
        std::vector<std::vector<int>> vis(n, std::vector<int>(m));
        std::queue<node> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> g[i][j];
                if (g[i][j] == 'r')
                {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        std::array<int, 4> dx = {0, 0, 1, -1};
        std::array<int, 4> dy = {1, -1, 0, 0};
        int ans = -1;
        while (!q.empty())
        {
            auto [x, y, c] = q.front();
            q.pop();
            if (g[x][y] == 'a')
            {
                ans = c;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }
                if (vis[nx][ny] == 1)
                {
                    continue;
                }
                if (g[nx][ny] == '#')
                    continue;
                if (g[nx][ny] == 'x')
                {
                    q.push({nx, ny, c + 2});
                }
                q.push({nx, ny, c + 1});
                vis[nx][ny] = 1;
            }
        }
        if (ans != -1)
            std::cout << ans << '\n';
        else
        {
            std::cout << "Poor ANGEL has to stay in the prison all his life." << '\n';
        }
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