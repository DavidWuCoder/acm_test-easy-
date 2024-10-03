#include <bits/stdc++.h>
using ll = long long;

struct edge{
    int u, v, w;
    bool operator<(edge& ne)
    {
        return w < ne.w;
    }
};

void solve(int& T)
{
    int n;
    while (std::cin >> n && n)
    {
        std::vector<edge> edges;
        for (int i = 0; i < n * (n - 1) / 2; i++)
        {
            int u, v, w;
            std::cin >> u >>  v >>  w;
            edges.push_back({u, v, w});
        }
        std::sort(edges.begin(), edges.end());
        std::vector<int> fa(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        std::function<int(int)> root = [&](int x)
        {
            return fa[x] = (fa[x] == x ? x : root(fa[x]));
        };
        int ans = 0;
        for (auto& e : edges)
        {
            if (root(e.u) == root(e.v))
            {
                continue;
            }
            ans += e.w;
            fa[root(e.u)] = root(e.v);
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