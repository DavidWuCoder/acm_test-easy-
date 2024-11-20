#include <bits/stdc++.h>
using ll = long long;

bool cmp(int a, int b)
{
    return a > b;
}

void solve(int& T)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        sort(a.begin() + i, a.end(), cmp);
        
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