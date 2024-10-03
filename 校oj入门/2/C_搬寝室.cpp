#include <bits/stdc++.h>
using ll = long long;

void solve(int &T)
{
    int n, k;
    while (std::cin >> n >> k)
    {
        std::vector<int> a(n);
        for (auto &x : a)
        {
            std::cin >> x;
        }
        sort(a.begin(), a.end());
        std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= n; i++)
            f[i][0] = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * 2 <= i; j++)
            {
                f[i][j] = std::min(f[i - 1][j], f[i - 2][j - 1] + (a[i - 1] - a[i - 2]) * (a[i - 1] - a[i - 2]));
            }
        }
        std::cout << f[n][k] << '\n';
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