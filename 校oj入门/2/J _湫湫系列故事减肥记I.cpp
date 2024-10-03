#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n; 
    while (std::cin >> n)
    {
        std::vector<int> v(n), w(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> w[i] >> v[i];
        }
        int m;
        std::cin >> m;
        std::vector<int> f(m + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = v[i]; j <= m; j++)
                f[j] = std::max(f[j], f[j - v[i]] + w[i]);
        }
        std::cout << f[m] << '\n';
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