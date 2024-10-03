#include <bits/stdc++.h>
using ll = long long;

void solve(int& T)
{
    int v1, v2;
    std::cin >> v1 >> v2;
    int m = v2 - v1;
    int n;
    std::cin >> n;
    std::vector<int> f(m + 1, INT_MAX);
    f[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        std::cin >> w >> v;
        for (int j = v; j <= m; j++)
        {
            if (f[j - v] != INT_MAX){
                f[j] = std::min(f[j], f[j - v] + w);
            }
        }
    }
    if (f[m] != INT_MAX){
        std::cout << "The minimum amount of money in the piggy-bank is " << f[m] << '.'<< '\n';
    }
    else
    {
        std::cout << "This is impossible.\n";
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