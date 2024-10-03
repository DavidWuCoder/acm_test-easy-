#include <bits/stdc++.h>
using ll = long long;

struct edge{
    int u, v, w;
    bool operator<(edge& ne) {
        return w < ne.w;
    };
};


void solve(int& T)
{
    int n;
    while (std::cin >> n && n)
    {
        int cnt = 0;
        std::vector<edge> edges;
        std::vector<int> fa(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        std::function<int(int)> root = [&](int x)
        {
            return fa[x] = (fa[x] == x ? x : root(fa[x]));
        };
        for (int i = 0; i < n * (n - 1) / 2; i++)
        {
            int u, v, w, flag;
            std::cin >> u >> v >> w >> flag;
            if (flag == 0)
            {
                edges.push_back({u, v, w});
            }
            else
            {
                fa[root(u)] = root(v);
                cnt++;
            }
        }
        std::sort(edges.begin(), edges.end());
        int ans = 0;
        for (auto& [u, v, w] : edges)
        {
            if (root(u) != root(v))
            {
                ans += w;
                cnt++;
                fa[root(u)] = root(v);
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