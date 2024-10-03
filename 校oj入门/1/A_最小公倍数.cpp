#include <iostream>

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
    int num1, num2;

    while(std::cin >> num1 >> num2)
    {
        std::cout << lcm(num1, num2) << std::endl;
    }

    return 0;
}