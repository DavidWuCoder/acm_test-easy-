#include <bits/stdc++.h>
using ll = long long;

struct node{
    int x;
    int s;
};

void solve(int& T)
{
    int n;
    while (std::cin >> n && n)
    {
        int ans = -1;
        int a, b;
        std::cin >> a >> b;
        std::vector<int> dir(n + 1), vis(n + 1);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> dir[i];
        }
        std::queue<node> q;
        q.push({a, 0});
        vis[a] = 1;
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            if (t.x == b)
            {
                ans = t.s;
                break;
            }
            int nx = t.x + dir[t.x];
            if (nx >= 1 && nx <= n && vis[nx] == 0)
            {
                vis[nx] = 1;
                q.push({nx, t.s + 1});
            }
            nx = t.x - dir[t.x];
            if (nx >= 1 && nx <= n && vis[nx] == 0)
            {
                vis[nx] = 1;
                q.push({nx, t.s + 1});
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