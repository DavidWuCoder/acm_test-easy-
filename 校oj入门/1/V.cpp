#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    std::vector<ll> f(31);
    f[1] = 1;
    f[2] = 3;
    f[3] = 5;
    for (int i = 4; i <= 30; i++)
    {
        f[i] = f[i - 1] + f[i - 2] * 2;
    }
    int t;
    std::cin >> t;
    while(t--)
    {
        int x;
        std::cin >> x;
        std::cout << f[x] << '\n';
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