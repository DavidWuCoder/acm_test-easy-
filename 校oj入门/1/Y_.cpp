#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n = 50;
    std::vector<ll> f(n + 1);
    f[1] = 3;
    f[2] = 6;
    f[3] = 6;
    for (int i = 4; i <= 50; i++)
    {
        f[i] = f[i - 1] + 2 * f[i - 2];
    }
    while (std::cin >> n)
    {
        std::cout << f[n] << '\n';
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