#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n;
    std::cin >> n;
    std::vector<int> f(n + 1);
    f[1] = 1;
    if (n == 1)
    {
        std::cout << f[1] << '\n';
        return;
    }
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    std::cout << f[n] << '\n';
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