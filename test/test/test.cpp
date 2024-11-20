//#include <iostream>
//#include <algorithm>
//#include <functional>
//#include <vector>
//#include <numeric>
//#include <queue>
//using ll = long long;
////
////struct edge
////{
////    int u, v, w;
////    bool operator<(edge& ne)
////    {
////        return w < ne.w;
////    }
////};
////
////void solve(int& T)
////{
////    int n, m;
////    while (std::cin >> n >> m && n)
////    {
////        std::vector<edge> edges;
////        for (int i = 0; i < m; i++)
////        {
////            int u, v, w;
////            std::cin >> u >> v >> w;
////            edges.push_back({ u, v, w });
////        }
////        std::sort(edges.begin(), edges.end());
////        std::vector<int> fa(n + 1);
////        std::iota(fa.begin(), fa.end(), 0);
////        std::function<int(int)> root = [&](int x)
////            {
////                return fa[x] = (fa[x] == x ? x : root(fa[x]));
////            };
////        int ans = 0;
////        int cnt = 0;
////        for (auto& e : edges)
////        {
////            if (root(e.u) == root(e.v))
////            {
////                continue;
////            }
////            ans += e.w;
////            cnt++;
////            fa[root(e.u)] = root(e.v);
////        }
////        if (cnt == n - 1)
////        {
////            std::cout << ans << '\n';
////        }
////        else
////        {
////            std::cout << '?' << '\n';
////        }
////    }
////}
////
////int main()
////{
////    std::ios::sync_with_stdio(false);
////    std::cin.tie(nullptr);
////    std::cout.tie(nullptr);
////    int T = 1;
////    // std::cin >> T;
////    for (int i = 1; i <= T; i++)
////        solve(T);
////    return 0;
////}
//
////#include <bits/stdc++.h>
//using ll = long long;
//
//void solve()
//{
//    int T, S, D;
//    while (std::cin >> T >> S >> D)
//    {
//        std::vector<std::vector<std::pair<int, int>>> g(1005);
//        for (int i = 0; i < T; i++)
//        {
//            int u, v, w;
//            std::cin >> u >> v >> w;
//            g[u].emplace_back(v, w);
//            g[v].emplace_back(u, w);
//        }
//        std::vector<int> bs(S);
//        std::vector<int> es(D);
//        for (int& i : bs)
//        {
//            std::cin >> i;
//        }
//        for (int& i : es)
//        {
//            std::cin >> i;
//        }
//        int ans = INT_MAX;
//        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
//        std::vector<int> dis(1005, INT_MAX);
//        for (int& b : bs)
//        {
//            dis[b] = 0;
//            pq.emplace(b, 0);
//        }
//        while (!pq.empty())
//        {
//            auto [x, dx] = pq.top();
//            pq.pop();
//            if (dx > dis[x])
//            {
//                continue;
//            }
//            for (auto [y, dy] : g[x])
//            {
//                int new_dis = dx + dy;
//                if (new_dis < dis[y])
//                {
//                    dis[y] = new_dis;
//                    pq.emplace(y, new_dis);
//                }
//            }
//        }
//        for (int& e : es)
//        {
//            ans = std::min(dis[e], ans);
//        }
//        std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
//    }
//}
//
//int main()
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//    int T = 1;
//    // std::cin >> T;
//    for (int i = 1; i <= T; i++)
//        solve();
//    return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//
//#include <stdio.h>
//#include <queue>
//#include <stdlib.h>
//#include <string.h>
//
//int mar[5][5][5];
//int vis[5][5][5];
//int a, b, c, t;
//
//struct node
//{
//    int x, y, z, _val;
//    node(int a, int b, int c, int z) : x(a), y(b), z(c), _val(z)
//    {
//
//    }
//};
//
//int dx[] = { 0, 1, 0, -1, 0, 0 };
//int dy[] = { 0, 0, 1, 0, -1, 0 };
//int dz[] = { 1, 0, 0, 0, 0, -1 };
//
//void bfs()
//{
//    memset(vis, 0, sizeof(vis));
//    std::queue<node> q;
//    q.emplace(1, 1, 1, 0);
//    vis[1][1][1] = 1;
//    while (!q.empty())
//    {
//        auto [x, y, z, val] = q.front();
//        if (x == a && y == b && z == c)
//        {
//            if (val <= t)
//            {
//                printf("%d\n", val);
//            }
//            else
//            {
//                printf("-1");
//            }
//            return;
//        }
//        for (int k = 0; k < 6; k++)
//        {
//            int nx = x + dx[k],
//                ny = y + dy[k],
//                nz = z + dz[k];
//
//            if (nx < 1 || nx > a || ny < 1 || ny > b || nz < 1 || nz > c)
//            {
//                continue;
//            }
//            if (vis[nx][ny][nz])
//            {
//                continue;
//            }
//            vis[nx][ny][nz] = 1;
//            q.emplace(nx, ny, nz, val + 1);
//        }
//        q.pop();
//
//    }
//}
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    while (T--)
//    {
//        scanf("%d %d %d %d", &a, &b, &c, &t);
//        for (int i = 1; i <= a; i++)
//        {
//            for (int j = 1; j <= b; j++)
//            {
//                for (int k = 1; k <= c; k++)
//                {
//                    scanf("%d", &mar[i][j][k]);
//                }
//            }
//        }
//        bfs();
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <functional>
//using ll = long long;
//
//void solve(int& T)
//{
//    int n;
//    while (std::cin >> n)
//    {
//        std::vector<int> a(n + 1);
//        std::vector<int> vis(n + 1);
//
//        std::function<void(int, int)> dfs = [&](int x, int pre) 
//        {
//            if (x == n + 1)
//            {
//                for (int j = 1; j <= n; j++)
//                {
//                    std::cout << a[j] << ' ';
//                }
//                std::cout << '\n';
//                return;
//            }
//            for (int i = 1; i <= n; i++)
//            {
//                if (!vis[i])
//                {
//                    a[x] = i;
//                    vis[i] = 1;
//                    dfs(x + 1, i);
//                    vis[i] = 0;
//                }
//            }
//        };
//
//        dfs(1, 0);
//    }
//}
//
//int main()
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//    int T = 1;
//    // std::cin >> T;
//    for (int i = 1; i <= T; i++)
//        solve(T);
//    return 0;
//}

//#include <array>
//#include <array>
//void solve(int& T)
//{
//    int n, m, t;
//    while ((std::cin >> n >> m >> t) && (n != 0 || m != 0 || t != 0))
//    {
//        int sx, sy, ex, ey;
//        std::vector<std::vector<char>> a(n, std::vector<char>(m)), vis(n, std::vector<char>(m));
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                std::cin >> a[i][j];
//                if (a[i][j] == 'S')
//                {
//                    sx = i;
//                    sy = j;
//                }
//                else if (a[i][j] == 'D')
//                {
//                    ex = i;
//                    ey = j;
//                }
//            }
//        }
//        std::array<int, 4> dx = { 1, -1, 0, 0 };
//        std::array<int, 4> dy = { 0, 0, 1, -1 };
//        vis[sx][sy] = 1;
//        int cnt = 0;
//        bool flag = 0;
//        std::function<void(int, int)> dfs = [&](int x, int y)
//            {
//                if (flag)
//                {
//                    return;
//                }
//                if (x == ex && y == ey)
//                {
//                    if (cnt == t)
//                        flag = true;
//                }
//                for (int i = 0; i < 4; i++)
//                {
//                    int nx = x + dx[i];
//                    int ny = y + dy[i];
//                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//                    {
//                        continue;
//                    }
//                    if (a[nx][ny] == 'X')
//                        continue;
//                    if (vis[nx][ny])
//                    {
//                        continue;
//                    }
//                    vis[nx][ny] = 1;
//                    cnt += 1;
//                    dfs(nx, ny);
//                    cnt -= 1;
//                    vis[nx][ny] = 0;
//                }
//            };
//        dfs(sx, sy);
//        std::cout << (flag == 0 ? "NO\n" : "YES\n");
//    }
//}
//
//int main()
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//    int T = 1;
//    // std::cin >> T;
//    for (int i = 1; i <= T; i++)
//        solve(T);
//    return 0;
//}
//
//#include <array>
//using ll = long long;
//
//void solve(int& T)
//{
//    int n, m;
//    while (std::cin >> n >> m && (n != 0 || m != 0)) {
//        std::vector<std::vector<char>> g(n, std::vector<char>(m));
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                std::cin >> g[i][j];
//            }
//        }
//        std::array<int, 8> dx = { 0, 1, 1, 1, 0, -1, -1, -1 };
//        std::array<int, 8> dy = { 1, 1, 0, -1, -1, -1, 0, 1 };
//        std::function<void(int, int)> dfs = [&](int x, int y)
//            {
//                g[x][y] = '*';
//                for (int i = 0; i < 8; i++)
//                {
//                    int nx = x + dx[i];
//                    int ny = y + dy[i];
//                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
//                    {
//                        continue;
//                    }
//                    if (g[nx][ny] = '@')
//                    {
//                        dfs(nx, ny);
//                    }
//                }
//                return;
//            };
//        int ans = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (g[i][j] == '@')
//                {
//                    ans++;
//                    dfs(i, j);
//                }
//            }
//        }
//        std::cout << ans << '\n';
//    }
//}
//
//int main()
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//    int T = 1;
//    // std::cin >> T;
//    for (int i = 1; i <= T; i++)
//        solve(T);
//    return 0;
//}

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> g;
        g.push_back({ 1 });
        if (numRows == 1)
        {
            return g;
        }
        for (int i = 1; i < numRows; i++)
        {
            g.push_back(vector<int>(i + 1));
            g[i][0] = 1;
            g[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                g[i][j] = g[i - 1][j] + g[i - 1][j - 1];
            }
        }
        return g;
    }
};

int main()
{
    Solution s1;
    s1.generate(5);
}