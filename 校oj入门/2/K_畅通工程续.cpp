#include <bits/stdc++.h>
using ll = long long;


void solve(int& T)
{
    int n, m;
    while(std::cin >> n >> m){
        std::vector<std::vector<std::pair<int, int>>> g(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            std::cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        int b, e;
        std::cin >> b >> e;
        std::vector<int> dis(n, INT_MAX);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.emplace(b, 0);
        dis[b] = 0;
        while (!pq.empty())
        {
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
        std::cout << (dis[e] == INT_MAX ? -1 : dis[e]) << '\n';
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