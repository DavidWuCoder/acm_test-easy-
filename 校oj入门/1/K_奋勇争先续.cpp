#include <bits/stdc++.h>
using ll = long long;

class acmer
{
public:
    std::string name;
    int score;
    int time;
    bool operator<(acmer& n)
    {
        if (score == n.score)
        {
            return time < n.time;
        }
        else
        {
            return score > n.score;
        }
    }
};

bool cmp(acmer x, acmer y)
{
    if (x.score== y.score)
    {
        return x.time < y.time;
    };
    return x.score > y.score;
}

void solve(int& T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<acmer> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].name >> a[i].score >> a[i].time;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        std::cout << a[i].name << " " << a[i].score << " " << a[i].time << '\n';
    }
    std::cout << '\n';
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
