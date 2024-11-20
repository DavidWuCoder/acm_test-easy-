#include <bits/stdc++.h>
using ll = long long;

void solve(int &T)
{
    int n, m, t;
    while ((std::cin >> n >> m >> t) && (n != 0 || m != 0 || t != 0))
    {
        int sx, sy, ex, ey;
        std::vector<std::vector<char>> a(n, std::vector<char>(m)), vis(n, std::vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                else if (a[i][j] == 'D')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        std::array<int, 4> dx = {1, -1, 0, 0};
        std::array<int, 4> dy = {0, 0, 1, -1};
        vis[sx][sy] = 1;
        int cnt = 0;
        bool flag = 0;

        // 奇偶性剪枝
        if ((sx + sy) % 2 && (ex + ey) % 2)
        {
            if (t % 2)
            {
                std::cout << "NO" << '\n';
                continue;
            }
        }
        if ((sx + sy) % 2 == 0 && (ex + ey) % 2 == 0)
        {
            if (t % 2)
            {
                std::cout << "NO" << '\n';
                continue;
            }
        }
        if ((sx + sy) % 2 == 0 && (ex + ey) % 2)
        {
            if (!(t % 2))
            {
                std::cout << "NO" << '\n';
                continue;
            }
        }
        if ((sx + sy) % 2 && (ex + ey) % 2 == 0)
        {
            if (!(t % 2))
            {
                std::cout << "NO" << '\n';
                continue;
            }
        }

        // if (n * m - wall_numbers <= t)
        // {
        //     std::std::cout << "NO" << '\n';
        //     continue;
        // }

        std::function<void(int, int)> dfs = [&](int x, int y)
        {
            if (flag)
            {
                return;
            }
            if (x == ex && y == ey)
            {
                if (cnt == t)
                    flag = true;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }
                if (a[nx][ny] == 'X')
                    continue;
                if (vis[nx][ny])
                {
                    continue;
                }
                vis[nx][ny] = 1;
                cnt += 1;
                dfs(nx, ny);
                cnt -= 1;
                vis[nx][ny] = 0;
            }
        };
        dfs(sx, sy);
        std::cout << (flag == 0 ? "NO\n" : "YES\n");
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