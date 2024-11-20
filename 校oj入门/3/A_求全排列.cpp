#include <iostream>
#include <vector>
#include <functional>
using ll = long long;

void solve(int &T)
{
    int n;
    while (std::cin >> n)
    {
        std::vector<int> a(n + 1);
        std::vector<int> vis(n + 1);

        std::function<void(int, int)> dfs = [&](int x, int pre)
        {
            if (x == n + 1)
            {
                for (int j = 1; j <= n; j++)
                {
                    std::cout << a[j] << ' ';
                }
                std::cout << '\n';
                return;
            }
            for (int i = 1; i <= n; i++)
            {
                if (!vis[i])
                {
                    a[x] = i;
                    vis[i] = 1;
                    dfs(x + 1, i);
                    vis[i] = 0;
                }
            }
        };

        dfs(1, 0);
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