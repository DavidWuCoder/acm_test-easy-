#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> f(m + 1);
    std::vector<int> v(n), w(n);
    for (auto& x : w)
    {
        std::cin >> x;
    }
    for (auto& x : v)
    {
        std::cin >> x;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);
        }
    }
    std::cout << f[m] << '\n';
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