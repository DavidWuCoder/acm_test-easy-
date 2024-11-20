#include <bits/stdc++.h>
using ll = long long;

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

void solve(int& T)
{
    int a, b, c;
    while (std::cin >> a >> b >> c && (a && b && c))
    {
        a /= gcd(b, c);
        if (a & 1)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << a - 1 << '\n';
        }
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