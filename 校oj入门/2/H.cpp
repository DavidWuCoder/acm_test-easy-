#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int> v, w;
    for (int i = 0; i < n; i++)
    {
        int c = 1, p, h, k;
        std::cin >> p >> h >> k;
        while (k > c)
        {
            k -= c;
            w.push_back(c * h);
            v.push_back(c * p);
            c *= 2;
        }
        w.push_back(k * h);
        v.push_back(k * p);
    }
    n = w.size();
    std::vector<int> f(m + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = std::max(f[j - v[i]] + w[i], f[j]);
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