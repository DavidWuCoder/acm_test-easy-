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
    // 加快读入速度
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);


    int num1, num2;
    int T;
    std::cin >> T;
    // 循环 T 个样例
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

#include <iostream>
using namespace std;
int main()
{
    int N;
    int a[30];
    int b[10];
    for (int i = 0; i < 30; i++)
    {
        a[i] = 1;
    }
    for (int i = 0; i < 10; i++)
        b[i] = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int data;
            cin >> data;
            a[j] = data;
        }
        int end = a[0];
        for (int j = 1; j < num; j++)
        {
            int b, c, e, f;
            b = e = end;
            c = f = a[j];
            while (b != c)
            {
                if (b > c)
                    b -= c;
                else
                    c -= b;
            }
            end = e / c * f;
        }
        b[i] = end;
    }
    for (int i = 0; i < N; i++)
        cout << b[i] << endl;
    return 0;
}