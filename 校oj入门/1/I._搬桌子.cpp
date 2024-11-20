#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n;
    std::cin >> n;
    std::vector<int> p(201);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        if (a > b)
        {
            std::swap(a, b);
        }
        for (int i = a; i <= b; i++)
        {
            p[i]++;
        }
    }
    std::cout << 10 * (*max_element(p.begin(), p.end())) << '\n';;
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