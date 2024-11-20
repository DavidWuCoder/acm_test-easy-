#include <bits/stdc++.h>
using ll = long long;

struct tclass
{
    int beg, end;
    bool operator<(tclass& x)
    {
        return end < x.end;
    }
};

void solve(int& T)
{
    int n;
    while(std::cin >> n && n != 0)
    {
        std::vector<tclass> s(n);
        for (int i = 0; i < n; i++){
            std::cin >> s[i].beg >> s[i].end;
        }
        std::sort(s.begin(), s.end());
        int sg = s[0].end;
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i].beg >= sg)
            {
                ans += 1;
                sg = s[i].end;
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