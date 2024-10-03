#include <bits/stdc++.h>
using ll = long long;

void solve(int &T)
{
    int n;
    while (std::cin >> n){
        std::vector<int> a(n);
        
        for (int &x : a)
        {
            std::cin >> x;
        }
        std::vector<int> f = {a[0]};
        for (int i = 1; i < n; i++)
        {
            if (f.back() <= a[i])
            {
                f.push_back(a[i]);
            }
            else
            {
                *upper_bound(f.begin(), f.end(), a[i]) = a[i];
            }
        }
        std::cout << f.size() << '\n';
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