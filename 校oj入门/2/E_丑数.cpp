#include <bits/stdc++.h>
using ll = long long;

void solve(int &T)
{
    std::vector<ll> f(5843);
    int a = 0, b = 0, c = 0, d = 0;
    f[0] = 1;
    for (int i = 1; i < f.size(); i++)
    {
        f[i] = std::min(std::min(2 * f[a], 3 * f[b]), std::min(5 * f[c], 7 * f[d]));
        if (f[i] == 2 * f[a])
        {
            a++;
        }
        if (f[i] == 3 * f[b])
        {
            b++;
        }
        if (f[i] == 5 * f[c])
        {
            c++;
        }
        if (f[i] == 7 * f[d])
        {
            d++;
        }
    }
    int n;
    while (std::cin >> n && n)
    {
        std::cout << f[n - 1] << '\n';
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