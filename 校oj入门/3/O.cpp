#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int n, m;
    std::cin >> n >> m;
    if (n % (m + 1) == 0)
    {
        std::cout << "Rabbit\n";
    }
    else
    {
        std::cout << "Grass\n";
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