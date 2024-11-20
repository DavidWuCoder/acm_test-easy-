#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    
    int n, e;
    std::cin >> n >> e;
    std::vector<std::vector<int>> G(n + 1, std::vector<int>(n + 1));
    int sum = 0;
    std::vector<int> reverse_boy(n + 1), match(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        G[a][b] = 1;
    }

    std::function<bool(int)> dfs = [&](int x)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!reverse_boy[i] && G[x][i])
            {
                reverse_boy[i] = 1;
                if (!match[i] || dfs(match[i]))
                {
                    match[i] = x;
                    return true;
                }
            }
        }
        return false;
    };

    for (int i = 1; i <= n; i++)
    {
        std::vector<int>(n + 1).swap(reverse_boy);
        if (dfs(i))
            sum++;
    }
    std::cout << n - sum << '\n';
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}