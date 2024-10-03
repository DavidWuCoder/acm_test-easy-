#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cin >> a[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            f[i][j] = std::max(f[i + 1][j + 1], f[i + 1][j]) + a[i][j];
        }
    }
    std::cout << f[0][0] << '\n';
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