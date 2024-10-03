#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n, m;
    while (std::cin >> n >> m && n)
    {
        std::vector<int> fa(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        std::function<int(int)> root = [&](int x)
        {
            return fa[x] = (fa[x] == x ? x : root(fa[x]));
        };
        for (int i = 0; i < m; i++)
        {
            int a, b;
            std::cin >> a >> b;
            fa[root(a)] = root(b);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (fa[i] == i)
            {
                cnt++;
            }
        }
        std::cout << cnt - 1 << '\n';
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