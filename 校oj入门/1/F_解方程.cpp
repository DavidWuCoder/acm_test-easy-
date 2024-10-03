#include <bits/stdc++.h>
using ll = long long;

double func(double x)
{
    double ans = 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
    return ans;
}

void solve(int& T)
{
    double a = 0, b = 100;
    double t;
    std::cin >> t;
    int l = func(a) - t;
    double r = func(b) - t;
    if ( t >= l && t <= r )
    {
        std::cout << "No solution!" << '\n';
        return;
    }
    double ans;
    while ((b - a) > 1e-5)
    {
        double mid = (a + b) / 2;
        double m = func(mid) - t;
        if (l * m > 0)
        {
            a = mid;
        }
        else
        {
            b = mid;
            ans = mid;
        }
    }
    std::cout << std::fixed << std::setprecision(4);
    std::cout << ans << '\n';
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