#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n = 0;
    while (std::cin >> n)
    {
        if (n == 0)
        {
            std::cout << "no" << '\n';
            continue;
        }
        if (n == 1)
        {
            std::cout << "no" << '\n';
            continue;
        }
        int a = 7, b = 11, c = 0;
        a %= 3;
        b %= 3;
        for (int i = 0; i < n - 1; i++)
        {
            c = (a + b) % 3;
            a = b;
            b = c;
        }
        std::cout << (b == 0 ? "yes" : "no") << '\n';
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