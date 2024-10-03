#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n;
    std::cin >> n;
    std::vector<int> w = {150, 200, 350};
    std::vector<int> f(n + 1, INT_MIN);
    f[0] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = w[i]; j <= n; j++)
        {
            if (f[j - w[i]] != INT_MIN)
            {
                f[j] = std::max(f[j], f[j - w[i]] + 1);
            }
        }
    }
    for (int j = n; j >= 0; j--)
    {
        if (f[j] != INT_MIN)
        {
            std::cout << (n - j) << '\n';
            return;
        }
    }
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