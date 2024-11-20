#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    std::vector<ll> f(41);
    f[1] = 3;
    f[2] = 8;
    f[3] = 22;
    for (int i = 4; i <= 40; i++)
    {
        f[i] = 2 * f[i - 1] + 2 * f[i - 2];
    }
    int n;
    while(std::cin >> n)
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