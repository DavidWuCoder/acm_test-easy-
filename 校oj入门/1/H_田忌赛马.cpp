#include <bits/stdc++.h>
using ll = long long;

void solve(int &T)
{
    int n;
    while (std::cin >> n && (n != 0))
    {
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int &i : a)
        {
            std::cin >> i;
        }
        for (int &i : b)
        {
            std::cin >> i;
        }
        sort(a.begin(), a.end(), std::greater<int>());
        sort(b.begin(), b.end(), std::greater<int>());
        int l1 = 0, r1 = n - 1;
        int l2 = 0, r2 = n - 1;
        int ans = 0;
        int t = n;
        while (t--)
        {
            if (a[l1] > b[l2])
            {
                ans += 200;
                l1++;
                l2++;
            }
            else if(a[l1] < b[l2])
            {
                ans -= 200;
                r1--;
                l2++;
            }
            else 
            {
                if (a[r1] > b[r2])
                {
                    ans += 200;
                    r1--;
                    r2--;
                }
                else
                {
                    ans -= 200;
                    r1--;
                    l2++;
                }
            }
        }
        std::cout << ans << '\n';
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