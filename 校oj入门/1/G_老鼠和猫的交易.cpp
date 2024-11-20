#include <bits/stdc++.h>
using ll = long long;

struct node{
    int x, y;
    double c;
    bool operator<(node& e2)
    {
        return c > e2.c;
    }
};

void solve(int& T)
{
    int m, n;
    while (std::cin >> m >> n && !(n == -1 && m == -1))
    {
        std::vector<node> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i].x >> a[i].y;
            a[i].c = (double)a[i].x / a[i].y;
        }
        sort(a.begin(), a.end());
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (m > a[i].y)
            {
                m -= a[i].y;
                ans += a[i].x;
            }
            else
            {
                ans += m * (double)a[i].x / a[i].y;
                break;
            }
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(3)<< ans << '\n';
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