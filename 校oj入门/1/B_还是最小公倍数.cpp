#include <iostream>
#include <bits/stdc++.h>

// 计算最大公约数 (GCD)
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算最小公倍数 (LCM)
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b; // 注意先除后乘以避免溢出
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int num1, num2;
    int T;
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
        int ans = 1;
        for (int &x : a)
        {
            ans = lcm(ans, x);
        }

        std::cout << ans << '\n';
    }

    return 0;
}