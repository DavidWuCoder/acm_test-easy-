#include <bits/stdc++.h>
using ll = long long;

ll ksm(int base, int exponent)
{
    ll result = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            result = (result * base) % 1000;
        }
        base = (base * base) % 1000;
        exponent >>= 1;
    }
    return result;
}

void solve(int &T)
{
    int a, b;
    while (std::cin >> a >> b && !(a == 0 && b == 0))
    {
        std::cout << ksm(a, b) << '\n';
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