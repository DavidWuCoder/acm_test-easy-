#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int T, S, D;
    while (std::cin >> T >> S >> D)
    {
        std::vector<std::vector<std::pair<int, int>>> g(1005);
        for (int i = 0; i < T; i++)
        {
            int u, v, w;
            std::cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        std::vector<int> bs(S);
        std::vector<int> es(D);
        for (int &i : bs)
        {
            std::cin >> i;
        }
        for (int &i : es)
        {
            std::cin >> i;
        }
        int ans = INT_MAX;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        std::vector<int> dis(1005, INT_MAX);
        for (int &b : bs)
        {
            dis[b] = 0;
            pq.emplace(b, 0);
        }
        while (!pq.empty())
        {
            // 注意这里要用值
            auto [x, dx] = pq.top();
            pq.pop();
            if (dx > dis[x])
            {
                continue;
            }
            for (auto [y, dy] : g[x])
            {
                int new_dis = dx + dy;
                if (new_dis < dis[y])
                {
                    dis[y] = new_dis;
                    pq.emplace(y, new_dis);
                }
            }
        }
        for (int &e : es)
        {
            ans = std::min(dis[e], ans);
        }
        std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
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
        solve();
    return 0;
}