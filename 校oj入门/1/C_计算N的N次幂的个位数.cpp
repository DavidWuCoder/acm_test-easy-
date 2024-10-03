#include <bits/stdc++.h>
using ll = long long;

#define int long long

int ksm(int base, int exponent)
{
    int result = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            result = (result * base) % 10;
        }
        base = (base * base) % 10;
        exponent >>= 1;
    }
    return result;
}

void solve(int& T)
{
    int x;
    std::cin >> x;
    std::cout << ksm(x, x) << '\n';
}

signed main()
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