#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int a, b;
    std::vector<int> fa(100000 + 1);
    std::iota(fa.begin(), fa.end(), 0);
    std::vector<int> vis(100000 + 1);
    std::function<int(int)> root = [&](int x)
    {
        return fa[x] = (fa[x] == x ? x : root(fa[x]));
    };
    bool flag = 0;
    while (std::cin >> a >> b)
    {
        if (a == -1 && b == -1)
        {
            break;
        }
        if (a == 0 && b == 0)
        {
            int cnt = 0;
            for (int i = 1; i <= 100000; ++i)
            {
                if (vis[i] == 1 && fa[i] == i)
                    cnt++; // 计数有几个集合
            }

            std::cout << (flag || cnt > 1 ? "No" : "Yes") << '\n';

            std::iota(fa.begin(), fa.end(), 0);
            std::vector<int>(100001, 0).swap(vis);
            flag = false;
            continue;
        }

        if (root(a) != root(b))
        {
            vis[a] = 1;
            vis[b] = 1;
            fa[root(a)] = root(b); // 注意等于号不要写成双等于
        }
        else
        {
            vis[a] = 1;
            vis[b] = 1;
            flag = true;
        }
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