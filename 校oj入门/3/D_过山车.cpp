#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n, m, k;
    while (std::cin >> k >>  n >> m && (k != 0))
    {
        std::vector<std::vector<int>> line(n + 1, std::vector<int>(m + 1));
        for (int i = 0; i < k; i++)
        {
            int a, b;
            std::cin >> a >> b;
            line[a][b] = 1;
        }
        std::vector<int> used(m, 0);
        std::vector<int> girl(m, 0);
        std::function<bool(int)> find = [&](int x) {
            int i, j;
            for (j = 1; j <= m; j++)
            { 
                if (line[x][j] == true && used[j] == false)
                {
                    used[j] = 1;
                    if (girl[j] == 0 || find(girl[j]))
                    {
                        girl[j] = x;
                        return true;
                    }
                }
            }
            return false;
        };
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            std::vector<int>(m).swap(used);
            if (find(i))
                ans++;
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