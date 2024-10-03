#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    std::vector<ll> f(52);
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    for (int i = 4; i <= 50; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    int n;
    while (std::cin >> n)
    {
        std::cout <<  f[n] << '\n';
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