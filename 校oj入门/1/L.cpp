#include <bits/stdc++.h>
using ll = long long;

bool cmp(int a, int b){
    return a > b;
}

void solve(int& T)
{
    int n;
    std::cin >> n;
    std::vector<int> f(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> f[i];
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        sort(f.begin() + i, f.end(), cmp);
        for (int j = i + 1; j <= i + f[i] && j < n; j++)
        {
            f[j] -= 1;
            if (f[j] < 0)
            {
                flag = 1;
            }
        }
        f[i] = 0;
        if (flag)
        {
            break;
        }
    }
    if (flag == 0)
    {
        std::cout << "yes" << '\n';
    }
    else
    {
        std::cout << "no\n";
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